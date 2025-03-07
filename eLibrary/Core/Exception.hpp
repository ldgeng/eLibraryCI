#pragma once

#ifndef eLibraryHeaderCoreException
#define eLibraryHeaderCoreException

#include <Core/String.hpp>
#include <exception>

namespace eLibrary::Core {
    /**
     * Support for handling exceptions
     */
    class Exception : public Object, public ::std::exception {
    private:
        mutable ::std::string ExceptionDetail;
        String ExceptionMessage;
    public:
        explicit Exception(const String &ExceptionMessageSource) noexcept : ExceptionMessage(ExceptionMessageSource) {}

        String toString() const noexcept override {
            if (ExceptionDetail.empty()) ExceptionDetail = ExceptionMessage.toU8String();
            return {ExceptionDetail};
        }

        const char *what() const noexcept override {
            toString();
            return ExceptionDetail.data();
        }
    };

    class ArithmeticException final : public Exception {
    public:
        using Exception::Exception;
    };

    class ConcurrentException : public Exception {
    public:
        using Exception::Exception;
    };

    class IndexException final : public Exception {
    public:
        using Exception::Exception;
    };

    class InterruptedException final : public ConcurrentException {
    public:
        using ConcurrentException::ConcurrentException;
    };

    class TypeException final : public Exception {
    public:
        using Exception::Exception;
    };
}

#endif
