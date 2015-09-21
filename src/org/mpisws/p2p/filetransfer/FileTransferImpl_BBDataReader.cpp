// Generated from /pastry-2.1/src/org/mpisws/p2p/filetransfer/FileTransferImpl.java
#include <org/mpisws/p2p/filetransfer/FileTransferImpl_BBDataReader.hpp>

#include <java/lang/IllegalStateException.hpp>
#include <java/lang/Integer.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/RuntimeException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/nio/ByteBuffer.hpp>
#include <java/util/Map.hpp>
#include <org/mpisws/p2p/filetransfer/FileTransferCallback.hpp>
#include <org/mpisws/p2p/filetransfer/FileTransferImpl_MsgTypeReader.hpp>
#include <org/mpisws/p2p/filetransfer/FileTransferImpl.hpp>
#include <rice/p2p/commonapi/appsocket/AppSocket.hpp>
#include <Array.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::filetransfer::FileTransferImpl_BBDataReader::FileTransferImpl_BBDataReader(FileTransferImpl *FileTransferImpl_this, const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
    , FileTransferImpl_this(FileTransferImpl_this)
{
    clinit();
}

org::mpisws::p2p::filetransfer::FileTransferImpl_BBDataReader::FileTransferImpl_BBDataReader(FileTransferImpl *FileTransferImpl_this, int32_t uid, int32_t size) 
    : FileTransferImpl_BBDataReader(FileTransferImpl_this, *static_cast< ::default_init_tag* >(0))
{
    ctor(uid,size);
}

void org::mpisws::p2p::filetransfer::FileTransferImpl_BBDataReader::init()
{
    requestedCancel = false;
}

void org::mpisws::p2p::filetransfer::FileTransferImpl_BBDataReader::ctor(int32_t uid, int32_t size)
{
    super::ctor();
    init();
    this->uid = uid;
    bytes = new ::int8_tArray(size);
    curReader = ::java::nio::ByteBuffer::wrap(bytes);
    npc(curReader)->limit(0);
}

java::lang::String* org::mpisws::p2p::filetransfer::FileTransferImpl_BBDataReader::toString()
{
    return ::java::lang::StringBuilder().append(u"Incoming msg<"_j)->append(uid)
        ->append(u"> of length"_j)
        ->append(npc(bytes)->length)->toString();
}

bool org::mpisws::p2p::filetransfer::FileTransferImpl_BBDataReader::read(::rice::p2p::commonapi::appsocket::AppSocket* socket, int32_t numToRead) /* throws(IOException) */
{
    if(npc(curReader)->hasRemaining())
        throw new ::java::lang::IllegalStateException(::java::lang::StringBuilder().append(u"curReader has "_j)->append(npc(curReader)->remaining())
            ->append(u" bytes remaining. "_j)
            ->append(numToRead)->toString());

    npc(curReader)->limit(npc(curReader)->position() + numToRead);
    FileTransferImpl_this->reader = this;
    return read(socket);
}

bool org::mpisws::p2p::filetransfer::FileTransferImpl_BBDataReader::read(::rice::p2p::commonapi::appsocket::AppSocket* socket) /* throws(IOException) */
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

void org::mpisws::p2p::filetransfer::FileTransferImpl_BBDataReader::completeChunk()
{
    FileTransferImpl_this->notifyListenersReceiveMsgProgress(this, npc(curReader)->position(), npc(bytes)->length);
    if(npc(curReader)->position() == npc(bytes)->length) {
        complete();
    }
    FileTransferImpl_this->reader = FileTransferImpl_this->msgTypeReader;
}

void org::mpisws::p2p::filetransfer::FileTransferImpl_BBDataReader::complete()
{
    npc(FileTransferImpl_this->incomingData)->remove(::java::lang::Integer::valueOf(uid));
    npc(FileTransferImpl_this->callback)->messageReceived(::java::nio::ByteBuffer::wrap(getBytes()));
}

int8_tArray* org::mpisws::p2p::filetransfer::FileTransferImpl_BBDataReader::getBytes()
{
    return bytes;
}

int8_t org::mpisws::p2p::filetransfer::FileTransferImpl_BBDataReader::getPriority()
{
    throw new ::java::lang::RuntimeException(u"Unknown priority.  Don't call this on the receiving side."_j);
}

int64_t org::mpisws::p2p::filetransfer::FileTransferImpl_BBDataReader::getSize()
{
    return npc(bytes)->length;
}

int32_t org::mpisws::p2p::filetransfer::FileTransferImpl_BBDataReader::getUID()
{
    return uid;
}

bool org::mpisws::p2p::filetransfer::FileTransferImpl_BBDataReader::cancel()
{
    if(requestedCancel)
        return false;

    requestedCancel = true;
    return FileTransferImpl_this->requestCancel(uid);
}

void org::mpisws::p2p::filetransfer::FileTransferImpl_BBDataReader::cancelled(FileTransferImpl_DataReader* reader)
{
    FileTransferImpl_this->notifyListenersSenderCancelled(reader);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::filetransfer::FileTransferImpl_BBDataReader::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.filetransfer.FileTransferImpl.BBDataReader", 57);
    return c;
}

java::lang::Class* org::mpisws::p2p::filetransfer::FileTransferImpl_BBDataReader::getClass0()
{
    return class_();
}

