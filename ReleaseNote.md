# Release Notes

This document describes the changes to eLibrary present in each release.

> eLibrary V0.20.1
- Core::MemoryAllocator doAllocate / doDeallocate(...)
- operator "" _I(...)
> eLibrary V0.20.0
- Core::Array(Memory Allocation)
- Core::ArrayList(Memory Allocation) Constructor(const Array<E>&)(Remove)
- Core::AtomicInteger(Remove)
- Core::AtomicReference(Remove)
- Core::AtomicStorage / doAddFetch / doAndFetch / doCompareExchange / doExchange / doFetchAdd / doFetchAnd / doFetchOr / doFetchSub / doFetchXor / doLoad / doOrFetch / doSubFetch / doXorFetch / getValue / setValue(New)
- Core::Collections doCopyConstruct / doMoveConstruct(New)
- Core::ConcurrentException(New)
- Core::ConcurrentOperation / doAddFetch / doAndFetch / doCastAddress / doCastObject / doCompareExchange / doExchange / doFetchAdd / doFetchAnd / doFetchOr / doFetchSub / doFetchXor / doLoad / doOrFetch / doSubFetch / doXorFetch(New)
- Core::ConcurrentQueue(`Mutex` Implementation)
- Core::ConcurrentUtility(Remove)
- Core::Functions doInvoke / doInvokeTuple(New)
- Core::Hashable(Remove)
- Core::Integer doBitShiftLeft(Remove) getAbsolute / getOpposite(...)
- Core::MemoryAllocator doAllocate / doConstruct / doDeallocate / doDestroy(constexpr)
- Core::MemoryOrder(New)
- Core::Mutex / doLock / doUnlock / isLocked / tryLock(New)
- Core::MutexLocker(New)
- Core::MutexLockerUnique / doAssign / doLock / doUnlock / tryLock(New)
- Core::Object getClassName(Remove)
- Core::PointerWeak / doAssign / doLock / doReset / doSwap / getReferenceCount / getValue / hasValue / isExpired(New)
- Core::RedBlackTree(Memory Allocation) doOrder(...)
- Core::RuntimeException(Remove)
- Core::String toU16String(`Array` Implementation)
- Core::StringBuffer toString(`Array` Implementation)
- Core::Thread doInterrupt / isInterrupted(...) doJoin / isFinished(`Atomic` Implementation)
- Core::ThreadState / isFinished / isInterrupted / setFinished / setInterrupted(New)
- Multimedia::AudioSegment toMediaBuffer(...)
- Network::SocketInputStream(...)
- Network::SocketOutputStream(...)
- operator"" _I / _S(New)
> eLibrary V2023.19.0
- Core::Array(Memory Allocation) doAssign(Memory Leak) doCompare / doConcat / getElementContainer(New)
- Core::ArrayList(Memory Allocation) doAllocate(Remove) doCompare(New)
- Core::Collections doCompare / getDistance(New)
- Core::ConcurrentQueue isEmpty / doDequeue / doEnqueue(New)
- Core::ContainerSet doCompare(New)
- Core::DoubleLinkedList(Memory Allocation) doCompare(New)
- Core::Functions / PlaceHolder<int> / doBind(New)
- Core::HeapMemoryResource(New)
- Core::Integer doMultiplication(Memory Leak) getGreatestCommonFactor(...)
- Core::MathematicsContext Constructor()(Remove) Constructor(const Integer&)(New)
- Core::MemoryAllocator(...)
- Core::MemoryResource / doAcquire / doRelease(New)
- Core::NonConstructable(New)
- Core::NonCopyAssignable(New)
- Core::NonCopyConstructable(New)
- Core::NonMovable(New)
- Core::NonMoveAssignable(New)
- Core::NonMoveConstructable(New)
- Core::PointerShared / doAssign / doReset / doSwap / getReferenceCount / getValue / hasValue / valueOf(New)
- Core::PointerUnique / doAssign / doReset / getValue / hasValue / valueOf
- Core::RedBlackTree(Memory Allocation) doClear(New)
- Core::ReentrantThread(Remove)
- Core::ReentrantFunctionThread(Remove)
- Core::Reference / getValue(New)
- Core::SingleLinkedList(Memory Allocation) doCompare(New)
- Core::String(Memory Allocation)
- Core::ThreadExecutor / doShutdown / doSubmit / isShutdown(New)
- Core::TypeBase(Remove)
- Core::TypeClass(Remove)
- Core::TypeEnumeration(Remove)
- Core::TypeManager(Remove)
- Core::TypePropertyBase(Remove)
- Core::TypePropertyClass(Remove)
- Core::TypePropertyEnumeration(Remove)
- Core::Extension::GeoIP MaxMindDatabase / doLookup(Experimental / New)
- IO::ByteBuffer(`Array` Implementation) doAssign(Remove)
- Multimedia::AudioSegment(`Array` Implementation) doConcat(New) setChannelCount(Segmentation Fault) setSampleRate(...)
- Multimedia::MediaChannelLayout doCompare(New)
- Multimedia::MediaSWRContext doConvert(const uint8_t**, int, uint8_t**, int)(doConvert(const uint8_t**, uint8_t**, int))
> eLibrary V2023.18.0
- Core::ArraySet(...)
- Core::Collections(Arrays)
- Core::Fraction toInteger(New)
- Core::Function doAssign / doCall(New)
- Core::Mathematics(...)
- Core::NonCopyable(New)
- Core::ObjectDerived(Remove)
- Core::String valueOf<T>(Remove)
- Core::TypeManager doQueryType / doRegisterType(New) doQueryClass / doRegisterBase / doRegisterClass / doRegisterEnumeration(Remove)
> eLibrary V2023.17.0
- Core::Array Constructor<II>(II, II)(New) Constructor<ElementSourceSize(size_t)>(std::array<E, ElementSourceSize>)(Remove)
- Core::Fraction Constructor(`Integer::getGreatestCommonFactor` Implementation)
- Core::Integer doBitShiftLeft(New) getGreatestCommonFactor(Mathematics::getGreatestCommonFactor)
- Core::NumberBuiltin(IntegerBuiltin)
- Core::Objects doCompare<T(Integral)>(Remove)
- Core::SizeEqual(New)
- Multimedia::MediaBuffer Constructor(const MediaChannelLayout&, const IO::ByteBuffer&, ALsizei)(Constructor(ALenum, const IO::ByteBuffer&, ALsizei))
- Multimedia::MediaCaptureDevice / doCapture / doClose / doStart / doStop(New)
- Multimedia::MediaContext ~MediaContext(`MediaContext::doDestroy` Implementation) doDestroy(...) MediaDistanceModel / setDistanceModel / setDopplerFactor / setSoundVelocity(New)
- Multimedia::MediaDevice ~MediaDevice(`MediaDevice::doClose` Implementation)
- Multimedia::MediaSource setSourceDistanceMaximum / setSourceDistanceReference / setSourceGainMaximum / setSourceGainMinimum / setSourceRolloffFactor(New) setSourceGain(setAudioGain) setSourcePitch(setAudioPitch) setSourceVelocity(setAudioVelocity)
> eLibrary V2023.16.0
- Core::ConcurrentUtility doCompareAndExchange<T>(New) doCompareAndExchange16 / doCompareAndExchange32 / doCompareAndExchange64(doCompareAndExchange)
- Core::TypeBase / getTypeName / isClass / isEnumeration(New)
- Core::TypeClass doRegisterProperty / getClassParent / getClassProperty(New)
- Core::TypeEnumeration doRegisterProperty / getEnumerationProperty(New)
- Core::TypeManager doQueryClass / doRegisterClass / doRegisterEnumeration / getInstance(New)
- Core::TypePropertyBase / getValueType(New)
- Core::TypePropertyClass(New)
- Core::TypePropertyEnumeration(New)
- Core::Object getClassName(New)
- Core::Optional(...)
- Core::Variant(New)
- IO::FileDescriptor ~FileDescriptor(...)
> eLibrary V2023.15.4
- IO::FileOption OptionText(Remove)
- IO::FileOutputStream getFilePosition(...)
> eLibrary V2023.15.3
- IO::File isExists(...)
- IO::FileInputStream getFileLength(Remove) getFilePosition(...)
- Network::NetworkAddress toAddressIn4 / toAddressIn6(...)
- Network::NetworkSocketAddress toAddressIn4 / toAddressIn6(...)
- Network::StreamSocket doAccept(...)
> eLibrary V2023.15.2
- Core::Thread(...)
- IO::File(...)
- IO::FileDescriptor(...)
- IO::FileInputStream(...)
- IO::FileOutputStream(...)
> eLibrary V2023.15.1
- Core::Class(Remove)
- Core::Exception getClassName(New)
> eLibrary V2023.15
- Core::Array doAssign(New)
- Core::ArrayList Constructor<II>(II, II)(New) Constructor(const ::std::vector<E>&) / toSTLVector(Remove)
- Core::Arrays doTraverse(New)
- Core::ContainerQueue(SingleLinkedQueue)
- Core::ContainerStack(SingleLinkedStack)
- Core::DoubleLinkedList addElement(...) Constructor<II>(II, II)(New) toSTLList(Remove)
- Core::IntegerBuiltin / doCast / doCompare / getValue(New)
- Core::MemoryAllocator deleteArray<T> / deleteObject<T>(New)
- Core::Numbers doCast(Remove)
- Core::SingleLinkedList addElement(...) Constructor<II>(II, II)(New) toSTLForwardList(Remove)
- IO::File doRemove / getAccessTime / getFileSize / getModificationTime / isDirectory / isExists / isFile(New)
- IO::FileDescriptor doAssign(FileDescriptor&&)(New)
- Multimedia::AudioSegment toMediaBuffer(Memory Leak Fixup)
- Multimedia::OpenAL::MediaBuffer Constructor(ALenum, const IO::ByteBuffer&, ALsizei)(Constructor(ALenum, const void*, ALsizei, ALsizei))
- Network::DatagramSocket setUDPNoChecksum(New)
- Network::NetworkAddress toAddressIn(Remove) toAddressIn4 / toAddressIn6(New)
- Network::NetworkSocketAddress toAddressIn(Remove) toAddressIn4 / toAddressIn6(New)
- Network::NetworkSocketDescriptor doAssign(NetworkSocketDescriptor&&)(New)
- Network::NetworkSSLContext(Remove)
- Network::NetworkSSLDescriptor(Remove)
- Network::NetworkSSLInitializer(Remove)
- Network::NetworkSSLMethod(Remove)
- Network::SocketInputStream doRead(...)
- Network::SocketOutputStream doWrite(...)
- Network::StreamSocketServer setTCPNoDelay(New)
> eLibrary V2023.14
- Core::ArrayIterator(...)
- Core::ArrayList Constructor(const ::std::vector<E>&)(New)
- Core::DoubleLinkedIterator(...)
- Core::DoubleLinkedList Constructor<Es...>(Es...)(New)
- Core::DoubleLinkedSet begin / end(New)
- Core::Objects doCompare<T(Arithmetic)>(T, T)(New) doMatchExecute / doMatchValue / makeEntry(Remove)
- Core::SingleLinkedIterator(...)
- Core::SingleLinkedList begin / Constructor<Es...>(Es...) / end(New)
- Core::SingleLinkedSet end(...)
- Multimedia::MediaCodec toString(...)
> eLibrary V2023.13
- Core::Any Constructor<Ts...>(std::inplace_t, T, Ts&&...)(New)
- Core::Objects doMatchValue / doMove(...) makeEntry(New)
- Core::Optional Constructor<Ts...>(std::inplace_t, T, Ts&&...)(New)
- Core::SegmentTree(Remove)
- IO::ByteBuffer doCompact(`Arrays::doCopyBackward` Implementation)
- Multimedia::AudioSegment doAssign(const AudioSegment&)(...) doAssign(AudioSegment&&)(New)
- Network::DatagramSocket doReceive(ByteBuffer&)(doReceive(char*, int)) doSend(ByteBuffer&)(doSend(char*, int))
- Network::NetworkSocketAddress toAddressIn(New)
- Network::SocketOutputStream doWrite(...)
> eLibrary V2023.12
- Core::ArrayList doAssign(ArrayList<E>&&)(New)
- Core::ArraySet doAssign(ArraySet<E>&&)(New)
- Core::Arrays doCheckG / doCheckGE / doCheckL / doCheckLE / doFill(New)
- Core::Character isDigit(isNumber) toNumber / valueOf(New)
- Core::Collection(Remove)
- Core::ConcurrentUtility doCompareAndExchange(volatile int8_t*, int8_t, int8_t)(...)
- Core::DoubleLinkedList doAssign(DoubleLinkedList<E>&&)(New)
- Core::DoubleLinkedSet Constructor(const DoubleLinkedList&) / doAssign(DoubleLinkedSet<E>&&)(New)
- Core::FunctionThread(New)
- Core::Integer isZero(New) toString(uint8_t)(toString(unsigned short))
- Core::List(Remove)
- Core::Mathematics doCosecant / doCosine / doCotangent / doEvolution / doExponent / doHyperbolicCosine / doHyperbolicSine / doHyperbolicTangent / doInverseHyperbolicTangent / doLogarithmE / doPower / doSecant / doSine / doTangent(Remove)
- Core::Map(Remove)
- Core::Numbers / doCast / doCompare(New)
- Core::Objects doMove(...)
- Core::Optional / doAssign / doReset / getValue / hasValue(New)
- Core::Queue(Remove)
- Core::ReentrantFunctionThread(New)
- Core::ReentrantThread(New)
- Core::SegmentTree(->Deprecated)
- Core::Set(Remove)
- Core::SingleLinkedList doAssign(SingleLinkedList<E>&&)(New)
- Core::SingleLinkedQueue doAssign(SingleLinkedQueue<E>&&) / getElementSize(New)
- Core::SingleLinkedSet Constructor(const SingleLinkedList&) / doAssign(SingleLinkedSet<E>&&)(New)
- Core::SingleLinkedStack / addElement / doAssign / doClear / getElement / getElementSize / isEmpty / removeElement(New)
- Core::Stack(Remove)
- Core::String Constructor(std::string) / Constructor(const ::std::u32string&) / Constructor(const ::std::wstring&) / toWString(...) toU8String / toU32String(...)
- IO::ArchiveInputStream doRead(ByteBuffer&)(New) doRead(uint8_t*, uint32_t, uint32_t)(Remove)
- IO::ByteBuffer doAssign / getBufferContainer(New) getValue / setValue(...)
- IO::FileOption OptionCreate(New) OptionTruncate(OptionTrucate)
- IO::FileInputStream doRead(ByteBuffer&)(New) doRead(uint8_t*, uint32_t, uint32_t)(Remove)
- IO::FileOutputStream doWrite(const ByteBuffer&)(New) doWrite(uint8_t*, uint32_t, uint32_t)(Remove)
- IO::InputStream doRead(ByteBuffer&) doRead(uint8_t*, uint32_t, uint32_t)(Remove)
- IO::OutputStream doWrite(const ByteBuffer&)(New) doWrite(uint8_t*, uint32_t, uint32_t)(Remove)
- Multimedia::MediaCodec doAssign(New)
- Multimedia::MediaCodecContext doAssign(New)
- Multimedia::MediaFormatContext doAssign(New)
- Multimedia::MediaFrame doAssign(New)
- Multimedia::MediaPacket doAssign(New)
- Multimedia::MediaSWRContext doAllocate()(Remove) doAssign(New)
- Network::NetworkSocketDescriptor Constructor(SocketHandleType)(Remove)
- Network::SocketInputStream doWrite(ByteBuffer&)(New) doRead(uint8_t*, uint32_t, uint32_t)(Remove)
- Network::SocketOutputStream doWrite(const ByteBuffer&)(New) doWrite(uint8_t*, uint32_t, uint32_t)(Remove)
> eLibrary V2023.11
- Core::Array Constructor<Es...>(Es...) / begin / doAllocate / end / setElement(New) Constructor(intmax_t)(Remove)
- Core::ArrayList addElement / doReverse / removeIndex(Arrays::doMove Implementation) Constructor(Array<E>)(New) Constructor<size_t>(std::array) / toSTLArray(Remove)
- Core::ArraySet addElement / removeElement(Arrays::doMove Implementation)
- Core::Arrays / doCopy / doCopyBackward / doCopyReverse / doMove / doMoveBackward / doMoveReverse(New)
- Core::Collection / isEmpty(New)
- Core::DoubleLinkedIterator(New)
- Core::DoubleLinkedList toArrayList(Remove)
- Core::IndexException(New)
- Core::List(New)
- Core::Map / isContainsKey / isContainsValue(New)
- Core::Mathematics doCeil2(getNearestPower2Upper) doFloor2(getNearestPower2Lower)
- Core::NtModule(Remove)
- Core::NtProcess doCreate(Remove)
- Core::Objects doCall / doForward / doMatchExecute / doMatchValue / doMove / doSwap(New)
- Core::Queue(New)
- Core::Set(New)
- Core::SingleLinkedIterator(New)
- Core::SingleLinkedList begin / end(New)
- Core::SingleLinkedQueue / addBack / addFront / doAssign / doClear / getBack / getFront / isEmpty / removeBack / removeFront / toString(New)
- Core::SingleLinkedSet begin / end(New)
- Core::Stack(New)
- Core::TypeException(New)
- Core::WindowsException(New)
- IO::Buffer doDiscardMark / doMark / doReset / getBufferMark(Remove)
- IO::ByteBuffer doCompact / doCompare(New)
- IO::FileDescriptor doOpen(Remove)
- IO::FileInputStream Constructor(const String&)(Remove) doOpen<Os...>(const String&, Os...)(doOpen(const String&)) doSeek(long, int)(doSeek(off64_t, int))
- IO::FileOption(New)
- IO::FileOutputStream Constructor(const String&, bool=false)(Remove) doFlush(...) doOpen<Os...>(const String&, Os...)(doOpen(const String&, bool)) doSeek(long, int)(doSeek(off64_t, int)) doTruncate(Remove)
- IO::Library / doOpen / getSymbol(New)
- IO::OutputStream doWrite(uint8_t)(doWrite(int))
- Network::NetworkAddress Constructor(Array<uint8_t>)(New) Constructor(std::array<uint8_t, 4>) / Constructor(std::array<uint8_t, 16>) / Constructor(std::initializer_list<uint8_t>)(Remove) isLoopbackAddress(...)
- Network::NetworkSSLDescriptor doRead(void*, int)(doRead(void*, uint8_t)) doWrite(void*, int)(doWrite(void*, uint8_t))
> eLibrary V2023.10
- Core::Any / doAssign / doReset / getValue / getValueType / hasValue(New)
- Core::Arithmetic(New)
- Core::Array doAssign / getElement / getElementSize / isEmpty(New)
- Core::ArrayIterator(New)
- Core::ArrayList(Memory Allocation) begin / doReverse / end(New)
- Core::ArraySet(Memory Allocation) begin / doAssign / end(New) removeElement(doCompare Implementation)
- Core::AtomicNumber andAndGet / getAndAnd / getAndOr / getAndXor / orAndGet / xorAndGet(New)
- Core::ConcurrentReference / compareAndSet / getAndSet / getValue(New)
- Core::Character / doAssign / doCompare / isAlpha / isLowerCase / isNull / isNumber / isUpperCase / toLowerCase / toUpperCase(New)
- Core::ConcurrentUtility getAndAndNumber / getAndOrNumber / getAndXorNumber(New)
- Core::DoubleLinkedList(Memory Allocation) doAssign / doClear(New)
- Core::DoubleLinkedSet(Memory Allocation) doAssign / doClear(New)
- Core::Integer doFactorial(const Integer&)(doFactorial() Optimization(NumberStep=1))
- Core::InterruptedException(New)
- Core::Mathematics doCosine / doSine(NumberSource > 1)
- Core::MemoryAllocator / newArray / newObject(New)
- Core::NtSecurityBuffer / getBufferSize(New)
- Core::ObjectDerived(New)
- Core::Objects / doCompare / getAddress / getMaximum / getMinimum(New)
- Core::RedBlackTree doAssign / doOrder(New)
- Core::RuntimeException(New)
- Core::SegmentTree / doBuild / doQuery / doUpdate / setElement(New)
- Core::SingleLinkedList(Memory Allocation) doAssign / doClear(New) toArrayList / toDoubleLinkedList(Remove)
- Core::SingleLinkedSet(Memory Allocation) doAssign / doClear(New)
- Core::String(...)
- Core::StringStream(...)
- Core::Thread / doExecute / doInterrupt / doJoin / doStart / doYield / isFinished / isInterrupted(New)
- Core::TreeMap getElementSize / isContains / isEmpty / removeMapping / setMapping(New)
- Core::TreeSet addElement / doDifference / doIntersection / doUnion / getElementSize / isContains / isEmpty / removeElement(New)
- IO::ArchiveDescriptor / doAssign / doClose / doSupportFilter / doSupportFormat / isAvailable(New)
- IO::ArchiveEntry / doAllocate / doAssign / doClear / doClose / getPathname / isAvailable(New)
- IO::ArchiveInputStream / doClose / doOpen / doRead / doReadNextHeader / isAvailable / isEncrypted(New)
- IO::ByteBuffer doAllocate / getValue / setValue(New)
- IO::FileDescriptor / doAssign / doClose / doOpen / isAvailable(New)
- IO::FileInputStream doOpen(New)
- IO::FileOutputStream doOpen(New)
- IO::InputStream doRead(doRead)
- IO::OutputStream isAvailable(New)
- Multimedia::AudioSegment(IO::AudioSegment Remake) doExport / doOpen(Experimental->Stable) doExportWAV / doOpenWAV / getBitSample / getChannelCount / setBitSample / setChannelCount(Remove) getChannelLayout / setChannelLayout(New) toMediaBuffer(toAudioBuffer)
- Multimedia::FFMpegInitializer(Remove)
- Multimedia::MediaBuffer(AudioBuffer) getBufferIndex / setBufferData(Remove)
- Multimedia::MediaChannelLayout(New)
- Multimedia::MediaCodec getCodecObject(Remove)
- Multimedia::MediaCodecContext(IO::MediaCodecContext) doOpen / doSendFrame / doSendPacket / setParameter(New) getContextObject(Remove)
- Multimedia::MediaContext / doDestroy / setContextCurrent / setContextCurrentNull(New)
- Multimedia::MediaDevice / doClose(New)
- Multimedia::MediaFormatContext doWriteFrame / doWriteHeader / doWriteTrailer(New) getContextObject / setIOContext(Remove)
- Multimedia::MediaFrame getFrameObject(Remove)
- Multimedia::MediaIOContext(Remove)
- Multimedia::MediaPacket getPacketObject(Remove)
- Multimedia::MediaSource(AudioSource) setAudioVelocity / setSourceDirection / setSourceRelative(New) setSourceBuffer(setAudioBuffer) setSourceLoop(setAudioLoop)
- Multimedia::MediaSWRContext(IO::MediaSWRContext) / doAllocate / doConvert / doInitialize(New)
- Multimedia::OpenALInitializer(Remove)
- Network::DatagramSocket isAvailable(isClosed) setBroadcast(Remove) setSocketOption(New)
- Network::NetworkSocketDescriptor / doAssign / doClose / isAvailable(New)
- Network::NetworkSocketOption(New)
- Network::NetworkSSLContext(New)
- Network::NetworkSSLDescriptor / doConnect / doRead / doShutdown / doWrite / setFileDescriptor(New)
- Network::NetworkSSLInitializer / doDestroy / doInitialize(New)
- Network::NetworkSSLMethod / getMethodTLS / getMethodTLSClient / getMethodTLSServer(New)
- Network::StreamSocket doDeposit / getInputStream / getOutputStream / getSocketHandle / setAddressReuse / setKeepAlive / setReceiveTimeout / setSendTimeout(Remove) isAvailable(isClosed) setSocketOption(New)
- Network::StreamSocketServer isAvailable / setSocketOption(New) isClosed / setAddressReuse(Remove)
- ::std::formatter<ObjectT(ObjectDerived), CharacterT> / format<ContextT>(const ObjectT&, ContextT&)(New)
> eLibrary V2023.09
- Core::ArrayList addElement / doAssign / doConcat / doReverse / removeIndex(std::copy Implementation) indexOf / isContains(Comparison)
- Core::ArraySet addElement / removeElement(std::copy Implementation) getElementSize / isEmpty / toArrayList(New) isContains(Comparison)
- Core::DoubleLinkedList addElement / removeIndex(Segmentation Fault) / indexOf(Comparison & Modifier) getElementSize / isContains / isEmpty(New) removeElement(...)
- Core::DoubleLinkedSet / addElement / doDifference / doIntersection / doUnion / getElementSize / isContains / isEmpty / removeElement / toDoubleLinkedSet(New)
- Core::Integer doDivision / doModulo / doSubtraction(Signature) doPower(0⁰)
- Core::Object isEqual(Remove)
- Core::RedBlackTree NodeColorEnumeration(...)
- Core::SingleLinkedList indexOf(Comparison & Modifier) getElementSize / isContains / isEmpty(New)
- Core::SingleLinkedSet / addElement / doDifference / doIntersection / doUnion / getElementSize / isContains / isEmpty / removeElement / toSingleLinkedList(New)
- Core::String Constructor / ~Constructor / doAssign(...)
- Core::StringStream(...)
- IO::AudioBuffer getBufferIndex / setBufferData(New)
- IO::AudioSegment / doAssign / doOpenWAV / doSplitChannel / doSynchronize / getBitSample / getChannelCount / getSampleRate / setBitSample / setChannelCount / setSampleRate / toAudioBuffer(New) doExport / doExportWAV / doOpen(Experimental / New)
- IO::AudioSource / doPause / doPlay / doRewind / doStop / setAudioBuffer / setAudioGain / setAudioLoop / setAudioPitch(New)
- IO::FileInputStream Constructor / doSeek / getFileLength / getFilePosition(...)
- IO::FileOutputStream Constructor / doSeek / doTruncate / getFilePosition(...)
- IO::MediaCodec / doFindDecoder / doFindEncoder / getCodecObject(New)
- IO::MediaCodecContext / doAllocate / getChannelCount / getContextObject / getSampleRate(New)
- IO::MediaFormatContext / doFindBestStream / doFindStreamInformation / doOpen / getContextObject / setIOContext / setOutputFormat(New)
- IO::MediaFrame / doAllocate / getFrameObject(New)
- IO::MediaIOContext / doOpen / getContextObject(New)
- IO::MediaPacket / doAllocate / getPacketObject(New)
> eLibrary V2023.08
- Core::ArrayList doClear(...)
- Core::ArraySet / addElement / doClear / doDifference / doIntersection / doUnion / removeElement(New)
- Core::Fraction doPower(New) getValue(...)
- Core::Integer doPower(NumberExponentSource < 0) getValue(...)
- Core::NtFile doRead / doWrite(New)
- Core::NtProcess doCreate / doResume / doSuspend(New)
- Network::NetworkException(New)
- Network::Socket doReceive / doSend(Remove) getInputStream / getOutputStream(Experimental / New)
- Network::SocketInputStream / doRead / getInstance / isAvailable(Experimental / New)
- Network::SocketOutputStream / doClose / doWrite / getInstance / isAvailable(Experimental / New)
