// Generated from /pastry-2.1/src/org/mpisws/p2p/filetransfer/FileTransferImpl.java
#include <org/mpisws/p2p/filetransfer/FileTransferImpl_FileNameReader.hpp>

#include <java/lang/NullPointerException.hpp>
#include <java/nio/ByteBuffer.hpp>
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

org::mpisws::p2p::filetransfer::FileTransferImpl_FileNameReader::FileTransferImpl_FileNameReader(FileTransferImpl *FileTransferImpl_this, const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
    , FileTransferImpl_this(FileTransferImpl_this)
{
    clinit();
}

org::mpisws::p2p::filetransfer::FileTransferImpl_FileNameReader::FileTransferImpl_FileNameReader(FileTransferImpl *FileTransferImpl_this)
    : FileTransferImpl_FileNameReader(FileTransferImpl_this, *static_cast< ::default_init_tag* >(0))
{
    ctor();
}

void org::mpisws::p2p::filetransfer::FileTransferImpl_FileNameReader::ctor()
{
    super::ctor();
    init();
}

void org::mpisws::p2p::filetransfer::FileTransferImpl_FileNameReader::init()
{
    bytes = new ::int8_tArray(int32_t(20));
    buf = ::java::nio::ByteBuffer::wrap(bytes);
}

void org::mpisws::p2p::filetransfer::FileTransferImpl_FileNameReader::initialize(int32_t uid, int64_t offset, int64_t length, int32_t nameSize)
{
    this->uid = uid;
    this->offset = offset;
    this->length = length;
    if(npc(bytes)->length < nameSize) {
        bytes = new ::int8_tArray(nameSize);
        buf = ::java::nio::ByteBuffer::wrap(bytes);
    }
    npc(buf)->clear();
    npc(buf)->limit(nameSize);
}

bool org::mpisws::p2p::filetransfer::FileTransferImpl_FileNameReader::read(::rice::p2p::commonapi::appsocket::AppSocket* socket) /* throws(IOException) */
{
    auto bytesRead = npc(socket)->read(buf);
    if(bytesRead < 0) {
        FileTransferImpl_this->socketClosed();
        return false;
    }
    if(npc(buf)->hasRemaining())
        return false;

    npc(buf)->flip();
    auto returnBytes = new ::int8_tArray(npc(buf)->remaining());
    npc(buf)->get(returnBytes);
    npc(buf)->clear();
    FileTransferImpl_this->addIncomingFile(uid, returnBytes, offset, length);
    FileTransferImpl_this->reader = FileTransferImpl_this->msgTypeReader;
    return true;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::filetransfer::FileTransferImpl_FileNameReader::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.filetransfer.FileTransferImpl.FileNameReader", 59);
    return c;
}

java::lang::Class* org::mpisws::p2p::filetransfer::FileTransferImpl_FileNameReader::getClass0()
{
    return class_();
}

