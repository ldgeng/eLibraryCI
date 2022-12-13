#pragma once

#ifdef eLibraryCore_WindowsNT

#include <Windows.h>
#include <winternl.h>
#include <ntstatus.h>
#include <shlwapi.h>
#include <string>
#include <sstream>

namespace eLibrary {
    typedef NTSTATUS NTAPI (*NtCreateKeyType)(OUT PHANDLE KeyHandle, IN ACCESS_MASK DesiredAccess, IN
                                              POBJECT_ATTRIBUTES ObjectAttributes, ULONG TitleIndex, IN OPTIONAL
                                              PUNICODE_STRING Class, IN ULONG CreateOptions, OUT OPTIONAL
                                              PULONG Disposition);

    typedef NTSTATUS NTAPI (*NtLoadDriverType)(IN PUNICODE_STRING DriverServiceName);

    typedef NTSTATUS NTAPI (*NtSetValueKeyType)(IN HANDLE KeyHandle, IN PUNICODE_STRING ValueName, IN OPTIONAL
                                         ULONG TitleIndex, IN ULONG Type, IN OPTIONAL PVOID Data, IN ULONG DataSize);

    typedef NTSTATUS NTAPI (*NtUnloadDriverType)(IN PUNICODE_STRING DriverServiceName);

    typedef NTSTATUS NTAPI (*RtlAdjustPrivilegeType)(IN ULONG Privilege, IN BOOLEAN Enable, IN BOOLEAN CurrentThread,
                                                     OUT PBOOLEAN Enabled OPTIONAL);

#define SeLoadDriverPrivilege 0xa

    DWORD loadDriverSC(const std::wstring &DriverFilePath) {
        SC_HANDLE ServiceManagerHandle = OpenSCManagerW(nullptr, nullptr, SC_MANAGER_ALL_ACCESS);
        if (!ServiceManagerHandle) return GetLastError();
        SC_HANDLE DriverServiceHandle = CreateServiceW(ServiceManagerHandle, L"eLibraryService", L"eLibraryService", SERVICE_ALL_ACCESS, SERVICE_KERNEL_DRIVER, SERVICE_DEMAND_START, SERVICE_ERROR_IGNORE, DriverFilePath.c_str(), nullptr, nullptr, nullptr, nullptr, nullptr);
        if (!DriverServiceHandle) {
            fprintf(stderr, "CreateServiceW %lu\n", GetLastError());
            CloseServiceHandle(ServiceManagerHandle);
            return GetLastError();
        }

        if (!StartServiceW(DriverServiceHandle, 0, nullptr)) {
            fprintf(stderr, "StartService %lu\n", GetLastError());
        }

        CloseServiceHandle(DriverServiceHandle);
        CloseServiceHandle(ServiceManagerHandle);
        return GetLastError();
    }

    void loadDriver(const std::wstring &DriverFilePath) {
        HMODULE ModuleNtDll = LoadLibraryW(L"ntdll.dll");
        NtCreateKeyType NtCreateKey = (NtCreateKeyType) GetProcAddress(ModuleNtDll, "NtCreateKey");
        NtLoadDriverType NtLoadDriver = (NtLoadDriverType) GetProcAddress(ModuleNtDll, "NtLoadDriver");
        NtSetValueKeyType NtSetValueKey = (NtSetValueKeyType) GetProcAddress(ModuleNtDll, "NtSetValueKey");
        RtlAdjustPrivilegeType RtlAdjustPrivilege = (RtlAdjustPrivilegeType) GetProcAddress(ModuleNtDll,
                                                                                            "RtlAdjustPrivilege");

        NTSTATUS DriverStatus;

        std::basic_stringstream<wchar_t> DriverImagePathStream;
        DriverImagePathStream << L"\\??\\" << DriverFilePath;

        UNICODE_STRING DriverRegistration;
        RtlInitUnicodeString(&DriverRegistration,
                             L"\\Registry\\Machine\\System\\CurrentControlSet\\Services\\eLibraryDriver");

        OBJECT_ATTRIBUTES DriverRegistrationAttribute;
        InitializeObjectAttributes(&DriverRegistrationAttribute, &DriverRegistration, OBJ_CASE_INSENSITIVE, nullptr,
                                   nullptr)

        DWORD DriverErrorControl = SERVICE_ERROR_IGNORE;
        DWORD DriverServiceType = SERVICE_KERNEL_DRIVER;
        DWORD DriverStartType = SERVICE_DEMAND_START;

        UNICODE_STRING DriverErrorControlString, DriverImagePathString, DriverServiceTypeString, DriverStartTypeString;
        RtlInitUnicodeString(&DriverErrorControlString, L"ErrorControl");
        RtlInitUnicodeString(&DriverImagePathString, L"ImagePath");
        RtlInitUnicodeString(&DriverServiceTypeString, L"Type");
        RtlInitUnicodeString(&DriverStartTypeString, L"Start");

        HANDLE DriverRegistrationHandle;
        if (!NT_SUCCESS(
                DriverStatus = NtCreateKey(&DriverRegistrationHandle, KEY_ALL_ACCESS, &DriverRegistrationAttribute, 0, nullptr, 0, nullptr)))
            throw Exception(String(u"loadDriver(const std::wstring&) NtCreateKey"));
        NtSetValueKey(DriverRegistrationHandle, &DriverErrorControlString, 0, REG_DWORD, &DriverErrorControl, sizeof(DWORD));
        NtSetValueKey(DriverRegistrationHandle, &DriverImagePathString, 0, REG_EXPAND_SZ, (void*) DriverImagePathStream.str().c_str(), sizeof(wchar_t) * (DriverImagePathStream.str().size() + 1));
        NtSetValueKey(DriverRegistrationHandle, &DriverStartTypeString, 0, REG_DWORD, &DriverStartType, sizeof(DWORD));
        NtSetValueKey(DriverRegistrationHandle, &DriverServiceTypeString, 0, REG_DWORD, &DriverServiceType, sizeof(DWORD));
        NtClose(DriverRegistrationHandle);

        RtlAdjustPrivilege(SeLoadDriverPrivilege, TRUE, FALSE, nullptr);

        if (!NT_SUCCESS(DriverStatus = NtLoadDriver(&DriverRegistration)))
            throw Exception(String(u"loadDriver(const std::wstring&) NtLoadDriver"));
        FreeLibrary(ModuleNtDll);
    }

    DWORD unloadDriverSC() {
        SC_HANDLE ServiceManagerHandle = OpenSCManagerW(nullptr, nullptr, SC_MANAGER_ALL_ACCESS);
        if (!ServiceManagerHandle)
            return GetLastError();
        SC_HANDLE DriverServiceHandle = OpenServiceW(ServiceManagerHandle, L"eLibraryService", SERVICE_ALL_ACCESS);
        if (!DriverServiceHandle) {
            CloseServiceHandle(ServiceManagerHandle);
            return GetLastError();
        }
        SERVICE_STATUS DriverServiceStatus;
        ControlService(DriverServiceHandle, SERVICE_CONTROL_STOP, &DriverServiceStatus);
        DeleteService(DriverServiceHandle);
        CloseServiceHandle(DriverServiceHandle);
        CloseServiceHandle(ServiceManagerHandle);
        return GetLastError();
    }

    void unloadDriver() {
        NTSTATUS DriverStatus;

        UNICODE_STRING DriverRegistration;
        RtlInitUnicodeString(&DriverRegistration,
                             L"\\Registry\\Machine\\System\\CurrentControlSet\\Services\\eLibraryDriver");

        HMODULE ModuleNtDll = LoadLibraryW(L"ntdll.dll");
        NtUnloadDriverType NtUnloadDriver = (NtUnloadDriverType) GetProcAddress(ModuleNtDll, "NtUnloadDriver");
        RtlAdjustPrivilegeType RtlAdjustPrivilege = (RtlAdjustPrivilegeType) GetProcAddress(ModuleNtDll,
                                                                                            "RtlAdjustPrivilege");

        RtlAdjustPrivilege(SeLoadDriverPrivilege, TRUE, FALSE, nullptr);

        if (!NT_SUCCESS(DriverStatus = NtUnloadDriver(&DriverRegistration)))
            throw Exception(String(u"unloadDriver() NtUnloadDriver"));
        if (!NT_SUCCESS(DriverStatus = SHDeleteKeyW(HKEY_LOCAL_MACHINE,
                                                    L"System\\CurrentControlSet\\Services\\eLibraryDriver")))
            throw Exception(String(u"unloadDriver() SHDeleteKeyW"));
        FreeLibrary(ModuleNtDll);
    }
}

#endif
