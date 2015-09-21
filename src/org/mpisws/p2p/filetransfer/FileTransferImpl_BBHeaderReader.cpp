// Generated from /pastry-2.1/src/org/mpisws/p2p/filetransfer/FileTransferImpl.java
#include <org/mpisws/p2p/filetransfer/FileTransferImpl_BBHeaderReader.hpp>

#include <java/lang/NullPointerException.hpp>
#include <java/nio/ByteBuffer.hpp>
#include <org/mpisws/p2p/filetransfer/FileTransferImpl_MsgTypeReader.hpp>
#include <org/mpisws/p2p/filetransfer/FileTransferImpl.hpp>
#include <rice/p2p/commonapi/appsocket/AppSocket.hpp>
#include <rice/p2p/util/MathUtils.hpp>
#include <Array.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::filetransfer::FileTransferImpl_BBHeaderReader::FileTransferImpl_BBHeaderReader(FileTransferImpl *FileTransferImpl_this, const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
    , FileTransferImpl_this(FileTransferImpl_this)
{
    clinit();
}

org::mpisws::p2p::filetransfer::FileTransferImpl_BBHeaderReader::FileTransferImpl_BBHeaderReader(FileTransferImpl *FileTransferImpl_this)
    : FileTransferImpl_BBHeaderReader(FileTransferImpl_this, *static_cast< ::default_init_tag* >(0))
{
    ctor();
}

void org::mpisws::p2p::filetransfer::FileTransferImpl_BBHeaderReader::ctor()
{
    super::ctor();
    init();
}

void org::mpisws::p2p::filetransfer::FileTransferImpl_BBHeaderReader::init()
{
    bytes = new ::int8_tArray(int32_t(4));
    buf = ::java::nio::ByteBuffer::wrap(bytes);
}

void org::mpisws::p2p::filetransfer::FileTransferImpl_BBHeaderReader::setUID(int32_t uid)
{
    this->uid = uid;
}

bool org::mpisws::p2p::filetransfer::FileTransferImpl_BBHeaderReader::read(::rice::p2p::commonapi::appsocket::AppSocket* socket) /* throws(IOException) */
{
    auto bytesRead = npc(socket)->read(buf);
    if(bytesRead < 0) {
        FileTransferImpl_this->socketClosed();
        return false;
    }
    if(npc(buf)->hasRemaining())
        return false;

    npc(buf)->clear();
    auto size = ::rice::p2p::util::MathUtils::byteArrayToInt(bytes);
    npc(buf)->clear();
    FileTransferImpl_this->addIncomingMessage(uid, size);
    FileTransferImpl_this->reader = FileTransferImpl_this->msgTypeReader;
    return true;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::filetransfer::FileTransferImpl_BBHeaderReader::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.filetransfer.FileTransferImpl.BBHeaderReader", 59);
    return c;
}

java::lang::Class* org::mpisws::p2p::filetransfer::FileTransferImpl_BBHeaderReader::getClass0()
{
    return class_();
}

