// Generated from /pastry-2.1/src/org/mpisws/p2p/filetransfer/FileTransferImpl.java
#include <org/mpisws/p2p/filetransfer/FileTransferImpl_MsgTypeReader.hpp>

#include <java/lang/NullPointerException.hpp>
#include <java/nio/ByteBuffer.hpp>
#include <org/mpisws/p2p/filetransfer/FileTransferImpl_BBHeaderReader.hpp>
#include <org/mpisws/p2p/filetransfer/FileTransferImpl_ChunkReader.hpp>
#include <org/mpisws/p2p/filetransfer/FileTransferImpl_FileHeaderReader.hpp>
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

org::mpisws::p2p::filetransfer::FileTransferImpl_MsgTypeReader::FileTransferImpl_MsgTypeReader(FileTransferImpl *FileTransferImpl_this, const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
    , FileTransferImpl_this(FileTransferImpl_this)
{
    clinit();
}

org::mpisws::p2p::filetransfer::FileTransferImpl_MsgTypeReader::FileTransferImpl_MsgTypeReader(FileTransferImpl *FileTransferImpl_this)
    : FileTransferImpl_MsgTypeReader(FileTransferImpl_this, *static_cast< ::default_init_tag* >(0))
{
    ctor();
}

void org::mpisws::p2p::filetransfer::FileTransferImpl_MsgTypeReader::ctor()
{
    super::ctor();
    init();
}

void org::mpisws::p2p::filetransfer::FileTransferImpl_MsgTypeReader::init()
{
    bytes = new ::int8_tArray(int32_t(5));
    buf = ::java::nio::ByteBuffer::wrap(bytes);
}

bool org::mpisws::p2p::filetransfer::FileTransferImpl_MsgTypeReader::read(::rice::p2p::commonapi::appsocket::AppSocket* socket) /* throws(IOException) */
{
    auto bytesRead = npc(socket)->read(buf);
    if(bytesRead < 0) {
        FileTransferImpl_this->socketClosed();
        return false;
    }
    if(npc(buf)->hasRemaining())
        return false;

    npc(buf)->clear();
    auto msgType = (*bytes)[int32_t(0)];
    auto uid = ::rice::p2p::util::MathUtils::byteArrayToInt(bytes, 1);
    npc(buf)->clear();
    switch (msgType) {
    case FileTransferImpl::MSG_BB_HEADER:
        npc(FileTransferImpl_this->bbHeaderReader)->setUID(uid);
        FileTransferImpl_this->reader = FileTransferImpl_this->bbHeaderReader;
        break;
    case FileTransferImpl::MSG_FILE_HEADER:
        npc(FileTransferImpl_this->fileHeaderReader)->setUID(uid);
        FileTransferImpl_this->reader = FileTransferImpl_this->fileHeaderReader;
        break;
    case FileTransferImpl::MSG_CHUNK:
        npc(FileTransferImpl_this->chunkReader)->setUID(uid);
        FileTransferImpl_this->reader = FileTransferImpl_this->chunkReader;
        break;
    case FileTransferImpl::MSG_CANCEL:
        FileTransferImpl_this->senderCancelled(uid);
        break;
    case FileTransferImpl::MSG_CANCEL_REQUEST:
        FileTransferImpl_this->receiverCancelled(uid);
        break;
    }

    return true;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::filetransfer::FileTransferImpl_MsgTypeReader::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.filetransfer.FileTransferImpl.MsgTypeReader", 58);
    return c;
}

java::lang::Class* org::mpisws::p2p::filetransfer::FileTransferImpl_MsgTypeReader::getClass0()
{
    return class_();
}

