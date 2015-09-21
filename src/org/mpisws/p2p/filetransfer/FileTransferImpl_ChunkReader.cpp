// Generated from /pastry-2.1/src/org/mpisws/p2p/filetransfer/FileTransferImpl.java
#include <org/mpisws/p2p/filetransfer/FileTransferImpl_ChunkReader.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/IllegalStateException.hpp>
#include <java/lang/Integer.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/nio/ByteBuffer.hpp>
#include <java/util/Map.hpp>
#include <org/mpisws/p2p/filetransfer/FileTransferImpl_DataReader.hpp>
#include <org/mpisws/p2p/filetransfer/FileTransferImpl.hpp>
#include <rice/p2p/commonapi/appsocket/AppSocket.hpp>
#include <rice/p2p/util/MathUtils.hpp>
#include <Array.hpp>

template<typename T, typename U>
static T java_cast(U* u)
{
    if(!u) return static_cast<T>(nullptr);
    auto t = dynamic_cast<T>(u);
    if(!t) throw new ::java::lang::ClassCastException();
    return t;
}

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::filetransfer::FileTransferImpl_ChunkReader::FileTransferImpl_ChunkReader(FileTransferImpl *FileTransferImpl_this, const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
    , FileTransferImpl_this(FileTransferImpl_this)
{
    clinit();
}

org::mpisws::p2p::filetransfer::FileTransferImpl_ChunkReader::FileTransferImpl_ChunkReader(FileTransferImpl *FileTransferImpl_this)
    : FileTransferImpl_ChunkReader(FileTransferImpl_this, *static_cast< ::default_init_tag* >(0))
{
    ctor();
}

void org::mpisws::p2p::filetransfer::FileTransferImpl_ChunkReader::ctor()
{
    super::ctor();
    init();
}

void org::mpisws::p2p::filetransfer::FileTransferImpl_ChunkReader::init()
{
    bytes = new ::int8_tArray(int32_t(4));
    buf = ::java::nio::ByteBuffer::wrap(bytes);
}

void org::mpisws::p2p::filetransfer::FileTransferImpl_ChunkReader::setUID(int32_t uid)
{
    this->uid = uid;
}

bool org::mpisws::p2p::filetransfer::FileTransferImpl_ChunkReader::read(::rice::p2p::commonapi::appsocket::AppSocket* socket) /* throws(IOException) */
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
    auto dataReader = java_cast< FileTransferImpl_DataReader* >(npc(FileTransferImpl_this->incomingData)->get(::java::lang::Integer::valueOf(uid)));
    if(dataReader == nullptr)
        throw new ::java::lang::IllegalStateException(::java::lang::StringBuilder().append(u"No record of uid "_j)->append(uid)->toString());

    return npc(dataReader)->read(socket, size);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::filetransfer::FileTransferImpl_ChunkReader::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.filetransfer.FileTransferImpl.ChunkReader", 56);
    return c;
}

java::lang::Class* org::mpisws::p2p::filetransfer::FileTransferImpl_ChunkReader::getClass0()
{
    return class_();
}

