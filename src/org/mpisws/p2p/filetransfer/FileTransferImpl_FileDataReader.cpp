// Generated from /pastry-2.1/src/org/mpisws/p2p/filetransfer/FileTransferImpl.java
#include <org/mpisws/p2p/filetransfer/FileTransferImpl_FileDataReader.hpp>

#include <java/io/File.hpp>
#include <java/io/IOException.hpp>
#include <java/io/RandomAccessFile.hpp>
#include <java/lang/IllegalStateException.hpp>
#include <java/lang/Integer.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/RuntimeException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/nio/ByteBuffer.hpp>
#include <java/util/Map.hpp>
#include <org/mpisws/p2p/filetransfer/FileTransferCallback.hpp>
#include <org/mpisws/p2p/filetransfer/FileTransferImpl_FileDataReader_completeChunk_2.hpp>
#include <org/mpisws/p2p/filetransfer/FileTransferImpl_FileDataReader_completeChunk_1.hpp>
#include <org/mpisws/p2p/filetransfer/FileTransferImpl_FileDataReader_cancelled_4.hpp>
#include <org/mpisws/p2p/filetransfer/FileTransferImpl_FileDataReader_cancelled_3.hpp>
#include <org/mpisws/p2p/filetransfer/FileTransferImpl_MsgTypeReader.hpp>
#include <org/mpisws/p2p/filetransfer/FileTransferImpl.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/environment/processing/Processor.hpp>
#include <rice/environment/processing/WorkRequest.hpp>
#include <rice/p2p/commonapi/appsocket/AppSocket.hpp>
#include <Array.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::filetransfer::FileTransferImpl_FileDataReader::FileTransferImpl_FileDataReader(FileTransferImpl *FileTransferImpl_this, const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
    , FileTransferImpl_this(FileTransferImpl_this)
{
    clinit();
}

org::mpisws::p2p::filetransfer::FileTransferImpl_FileDataReader::FileTransferImpl_FileDataReader(FileTransferImpl *FileTransferImpl_this, int32_t uid, ::int8_tArray* metadata, ::java::io::File* f, int64_t offset, int64_t length)  /* throws(IOException) */
    : FileTransferImpl_FileDataReader(FileTransferImpl_this, *static_cast< ::default_init_tag* >(0))
{
    ctor(uid,metadata,f,offset,length);
}

void org::mpisws::p2p::filetransfer::FileTransferImpl_FileDataReader::init()
{
    requestedCancel = false;
    cancelled_ = false;
    exception = nullptr;
}

void org::mpisws::p2p::filetransfer::FileTransferImpl_FileDataReader::ctor(int32_t uid, ::int8_tArray* metadata, ::java::io::File* f, int64_t offset, int64_t length) /* throws(IOException) */
{
    super::ctor();
    init();
    this->uid = uid;
    this->f = f;
    this->ptr = offset;
    this->offset = offset;
    this->length = length;
    file = new ::java::io::RandomAccessFile(f, u"rw"_j);
    this->metadata = metadata;
    npc(file)->seek(offset);
    bytes = new ::int8_tArray(FileTransferImpl_this->CHUNK_SIZE);
    curReader = ::java::nio::ByteBuffer::wrap(bytes);
}

java::lang::String* org::mpisws::p2p::filetransfer::FileTransferImpl_FileDataReader::toString()
{
    return ::java::lang::StringBuilder().append(u"Incoming file<"_j)->append(uid)
        ->append(u"> "_j)
        ->append(npc(metadata)->length)
        ->append(u" off:"_j)
        ->append(offset)
        ->append(u" length:"_j)
        ->append(length)
        ->append(u" "_j)
        ->append(static_cast< ::java::lang::Object* >(f))->toString();
}

bool org::mpisws::p2p::filetransfer::FileTransferImpl_FileDataReader::read(::rice::p2p::commonapi::appsocket::AppSocket* socket, int32_t numToRead) /* throws(IOException) */
{
    if(npc(curReader)->position() != 0)
        throw new ::java::lang::IllegalStateException(::java::lang::StringBuilder().append(u"curReader has "_j)->append(npc(curReader)->remaining())
            ->append(u" bytes remaining. "_j)
            ->append(numToRead)->toString());

    npc(curReader)->limit(numToRead);
    FileTransferImpl_this->reader = this;
    return read(socket);
}

bool org::mpisws::p2p::filetransfer::FileTransferImpl_FileDataReader::read(::rice::p2p::commonapi::appsocket::AppSocket* socket) /* throws(IOException) */
{
    auto ret = npc(socket)->read(curReader);
    if(ret < 0) {
        FileTransferImpl_this->socketClosed();
        return false;
    }
    if(npc(curReader)->hasRemaining()) {
        return false;
    }
    completeChunk();
    return true;
}

void org::mpisws::p2p::filetransfer::FileTransferImpl_FileDataReader::completeChunk()
{
    npc(curReader)->flip();
    auto const writeMe = new ::int8_tArray(npc(curReader)->remaining());
    npc(curReader)->get(writeMe);
    npc(curReader)->clear();
    FileTransferImpl_this->incrementFileChunksInMemory();
    ::rice::environment::processing::WorkRequest* wr = new FileTransferImpl_FileDataReader_completeChunk_2(this, writeMe, new FileTransferImpl_FileDataReader_completeChunk_1(this), npc(FileTransferImpl_this->environment)->getSelectorManager());
    npc(FileTransferImpl_this->processor)->processBlockingIO(wr);
    FileTransferImpl_this->reader = FileTransferImpl_this->msgTypeReader;
}

void org::mpisws::p2p::filetransfer::FileTransferImpl_FileDataReader::complete()
{
    npc(FileTransferImpl_this->incomingData)->remove(::java::lang::Integer::valueOf(uid));
    try {
        npc(file)->close();
    } catch (::java::io::IOException* ioe) {
        if(npc(FileTransferImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(FileTransferImpl_this->logger)->logException(::java::lang::StringBuilder().append(u"Error closing file "_j)->append(static_cast< ::java::lang::Object* >(file))->toString(), ioe);

    }
    npc(FileTransferImpl_this->callback)->fileReceived(getFile(), getMetadata());
}

int8_tArray* org::mpisws::p2p::filetransfer::FileTransferImpl_FileDataReader::getBytes()
{
    return bytes;
}

int8_t org::mpisws::p2p::filetransfer::FileTransferImpl_FileDataReader::getPriority()
{
    throw new ::java::lang::RuntimeException(u"Unknown priority.  Don't call this on the receiving side."_j);
}

int64_t org::mpisws::p2p::filetransfer::FileTransferImpl_FileDataReader::getSize()
{
    return npc(bytes)->length;
}

int32_t org::mpisws::p2p::filetransfer::FileTransferImpl_FileDataReader::getUID()
{
    return uid;
}

bool org::mpisws::p2p::filetransfer::FileTransferImpl_FileDataReader::cancel()
{
    if(requestedCancel)
        return false;

    requestedCancel = true;
    return FileTransferImpl_this->requestCancel(uid);
}

java::io::File* org::mpisws::p2p::filetransfer::FileTransferImpl_FileDataReader::getFile()
{
    return f;
}

int64_t org::mpisws::p2p::filetransfer::FileTransferImpl_FileDataReader::getLength()
{
    return length;
}

java::nio::ByteBuffer* org::mpisws::p2p::filetransfer::FileTransferImpl_FileDataReader::getMetadata()
{
    return ::java::nio::ByteBuffer::wrap(metadata);
}

int64_t org::mpisws::p2p::filetransfer::FileTransferImpl_FileDataReader::getOffset()
{
    return offset;
}

void org::mpisws::p2p::filetransfer::FileTransferImpl_FileDataReader::cancelled(FileTransferImpl_DataReader* reader)
{
    cancelled_ = true;
    ::rice::environment::processing::WorkRequest* wr = new FileTransferImpl_FileDataReader_cancelled_4(this, new FileTransferImpl_FileDataReader_cancelled_3(this, reader), npc(FileTransferImpl_this->environment)->getSelectorManager());
    npc(FileTransferImpl_this->processor)->processBlockingIO(wr);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::filetransfer::FileTransferImpl_FileDataReader::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.filetransfer.FileTransferImpl.FileDataReader", 59);
    return c;
}

java::lang::Class* org::mpisws::p2p::filetransfer::FileTransferImpl_FileDataReader::getClass0()
{
    return class_();
}

