#pragma once

#ifndef eLibraryHeaderIOFileStream
#define eLibraryHeaderIOFileStream

#if eLibraryFeature(IO)

#include <IO/IOUtility.hpp>
#include <IO/Stream.hpp>

namespace eLibrary::IO {
    /**
     * The FileInputStream class provides support for reading files
     */
    class FileInputStream final : public InputStream {
    private:
        FileDescriptor StreamDescriptor;

        static int getOpenOption(FileOption OptionCurrent) noexcept {
            return (int) OptionCurrent;
        }

        template<typename ...Os>
        static int getOpenOption(FileOption OptionCurrent, Os ...OptionList) noexcept {
            return (int) OptionCurrent | getOpenOption(OptionList...);
        }
    public:
        constexpr FileInputStream() noexcept = default;

        void doClose() override {
            StreamDescriptor.doClose();
        }

        template<typename ...Os>
        void doOpen(const String &StreamPath, Os ...StreamOptionList) {
            if (isAvailable()) throw IOException(u"FileInputStream::doOpen<Os...>(const String&, Os...) isAvailable"_S);
            int StreamOption = O_RDONLY;
            if constexpr (sizeof...(StreamOptionList) > 0) StreamOption |= getOpenOption(StreamOptionList...);
            StreamDescriptor.doAssign(::open(StreamPath.toU8String().c_str(), StreamOption, 0777));
            if (!isAvailable()) throw IOException(u"FileInputStream::doOpen<Os...>(const String&, Os...) isAvailable"_S);
        }

        int doRead() override {
            if (!isAvailable()) throw IOException(u"FileInputStream::doRead() isAvailable"_S);
            char StreamBuffer;
            ::read((int) StreamDescriptor, &StreamBuffer, 1);
            return StreamBuffer;
        }

        void doRead(ByteBuffer &FileBuffer) override {
            if (!isAvailable()) throw IOException(u"FileInputStream::doRead(ByteBuffer&) isAvailable"_S);
            FileBuffer.setBufferPosition(FileBuffer.getBufferPosition() + ::read((int) StreamDescriptor, FileBuffer.BufferContainer.getElementContainer() + FileBuffer.getBufferPosition(), FileBuffer.getRemaining()));
        }

        void doSeek(long FileOffset, int FileOrigin) const {
            if (!isAvailable()) throw IOException(u"FileInputStream::doSeek(long, int) isAvailable"_S);
            ::lseek((int) StreamDescriptor, FileOffset, FileOrigin);
        }

        auto getFilePosition() const {
            if (!isAvailable()) throw IOException(u"FileInputStream::getFilePosition() isAvailable"_S);
            return ::lseek((int) StreamDescriptor, 0, SEEK_CUR);
        }

        bool isAvailable() const noexcept override {
            return StreamDescriptor.isAvailable();
        }
    };

    /**
     * The FileOutputStream class provides support for writing files
     */
    class FileOutputStream final : public OutputStream {
    private:
        FileDescriptor StreamDescriptor;

        static int getOpenOption(FileOption OptionCurrent) noexcept {
            return (int) OptionCurrent;
        }

        template<typename ...Os>
        static int getOpenOption(FileOption OptionCurrent, Os ...OptionList) noexcept {
            return (int) OptionCurrent | getOpenOption(OptionList...);
        }
    public:
        constexpr FileOutputStream() noexcept = default;

        void doClose() override {
            StreamDescriptor.doClose();
        }

        void doFlush() override {
            if (!isAvailable()) throw IOException(u"FileOutputStream::doFlush() isAvailable"_S);
        }

        template<typename ...Os>
        void doOpen(const String &StreamPath, Os ...StreamOptionList) {
            if (isAvailable()) throw IOException(u"FileOutputStream::doOpen<Os...>(const String&, Os...) isAvailable"_S);
            int StreamOption = O_WRONLY;
            if constexpr (sizeof...(StreamOptionList) > 0) StreamOption |= getOpenOption(StreamOptionList...);
            StreamDescriptor.doAssign(::open(StreamPath.toU8String().c_str(), StreamOption, 0777));
            if (!isAvailable()) throw IOException(u"FileOutputStream::doOpen<Os...>(const String&, Os...) isAvailable"_S);
        }

        void doSeek(long FileOffset, int FileOrigin) {
            if (!isAvailable()) throw IOException(u"FileOutputStream::doSeek(long, int) isAvailable"_S);
            ::lseek((int) StreamDescriptor, FileOffset, FileOrigin);
        }

        void doWrite(uint8_t FileCharacter) override {
            if (!isAvailable()) throw IOException(u"FileOutputStream::doWrite(uint8_t) isAvailable"_S);
            ::write((int) StreamDescriptor, &FileCharacter, 1);
        }

        void doWrite(const ByteBuffer &FileBuffer) override {
            if (!isAvailable()) throw IOException(u"FileOutputStream::doWrite(const ByteBuffer&) isAvailable"_S);
            ::write((int) StreamDescriptor, FileBuffer.BufferContainer.getElementContainer() + FileBuffer.getBufferPosition(), FileBuffer.getRemaining());
            FileBuffer.setBufferPosition(FileBuffer.getBufferLimit());
        }

        auto getFilePosition() const {
            if (!isAvailable()) throw IOException(u"FileOutputStream::getFilePosition() isAvailable"_S);
            return ::lseek((int) StreamDescriptor, 0, SEEK_CUR);
        }

        bool isAvailable() const noexcept override {
            return StreamDescriptor.isAvailable();
        }
    };
}
#endif

#endif
