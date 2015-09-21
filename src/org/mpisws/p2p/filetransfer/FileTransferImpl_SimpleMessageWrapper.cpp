// Generated from /pastry-2.1/src/org/mpisws/p2p/filetransfer/FileTransferImpl.java
#include <org/mpisws/p2p/filetransfer/FileTransferImpl_SimpleMessageWrapper.hpp>

#include <java/lang/Integer.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/nio/ByteBuffer.hpp>
#include <org/mpisws/p2p/filetransfer/FileTransferImpl_MessageWrapper.hpp>
#include <org/mpisws/p2p/filetransfer/FileTransferImpl.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/p2p/commonapi/appsocket/AppSocket.hpp>
#include <rice/p2p/util/MathUtils.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::filetransfer::FileTransferImpl_SimpleMessageWrapper::FileTransferImpl_SimpleMessageWrapper(FileTransferImpl *FileTransferImpl_this, const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
    , FileTransferImpl_this(FileTransferImpl_this)
{
    clinit();
}

org::mpisws::p2p::filetransfer::FileTransferImpl_SimpleMessageWrapper::FileTransferImpl_SimpleMessageWrapper(FileTransferImpl *FileTransferImpl_this, int8_t msgType, int32_t uid) 
    : FileTransferImpl_SimpleMessageWrapper(FileTransferImpl_this, *static_cast< ::default_init_tag* >(0))
{
    ctor(msgType,uid);
}

void org::mpisws::p2p::filetransfer::FileTransferImpl_SimpleMessageWrapper::ctor(int8_t msgType, int32_t uid)
{
    super::ctor();
    this->uid = uid;
    this->msgType = msgType;
    msg = ::java::nio::ByteBuffer::allocate(5);
    npc(msg)->put(msgType);
    npc(msg)->put(::rice::p2p::util::MathUtils::intToByteArray_(uid));
    npc(msg)->clear();
}

java::lang::String* org::mpisws::p2p::filetransfer::FileTransferImpl_SimpleMessageWrapper::toString()
{
    if(msgType == FileTransferImpl::MSG_CANCEL)
        return ::java::lang::StringBuilder().append(u"Cancel msg <"_j)->append(uid)
            ->append(u">"_j)->toString();

    if(msgType == FileTransferImpl::MSG_CANCEL_REQUEST)
        return ::java::lang::StringBuilder().append(u"Cancel request <"_j)->append(uid)
            ->append(u">"_j)->toString();

    return u"Unknown message"_j;
}

void org::mpisws::p2p::filetransfer::FileTransferImpl_SimpleMessageWrapper::complete()
{
}

void org::mpisws::p2p::filetransfer::FileTransferImpl_SimpleMessageWrapper::drop()
{
}

int8_t org::mpisws::p2p::filetransfer::FileTransferImpl_SimpleMessageWrapper::getPriority()
{
    return FileTransferImpl::CANCEL_PRIORITY;
}

int64_t org::mpisws::p2p::filetransfer::FileTransferImpl_SimpleMessageWrapper::getSeq()
{
    return ::java::lang::Integer::MIN_VALUE;
}

int32_t org::mpisws::p2p::filetransfer::FileTransferImpl_SimpleMessageWrapper::getUid()
{
    return uid;
}

int32_t org::mpisws::p2p::filetransfer::FileTransferImpl_SimpleMessageWrapper::compareTo(FileTransferImpl_MessageWrapper* that)
{
    if(this->getPriority() == npc(that)->getPriority()) {
        if(this->uid == npc(that)->getUid()) {
            return static_cast< int32_t >((this->getSeq() - npc(that)->getSeq()));
        }
        return this->uid - npc(that)->getUid();
    }
    return this->getPriority() - npc(that)->getPriority();
}

int32_t org::mpisws::p2p::filetransfer::FileTransferImpl_SimpleMessageWrapper::compareTo(::java::lang::Object* arg0)
{ 
    return compareTo(dynamic_cast< FileTransferImpl_MessageWrapper* >(arg0));
}

bool org::mpisws::p2p::filetransfer::FileTransferImpl_SimpleMessageWrapper::receiveSelectResult(::rice::p2p::commonapi::appsocket::AppSocket* socket) /* throws(IOException) */
{
    if(npc(FileTransferImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINEST)
        npc(FileTransferImpl_this->logger)->log(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(this))->append(u".receiveSelectResult("_j)
            ->append(static_cast< ::java::lang::Object* >(socket))
            ->append(u")"_j)->toString());

    int64_t bytesWritten;
    if((bytesWritten = npc(socket)->write(msg)) == -int32_t(1)) {
        FileTransferImpl_this->socketClosed();
        return false;
    }
    if(npc(msg)->hasRemaining()) {
        if(npc(FileTransferImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINEST)
            npc(FileTransferImpl_this->logger)->log(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(this))->append(u".rsr("_j)
                ->append(static_cast< ::java::lang::Object* >(socket))
                ->append(u") has remaining"_j)->toString());

        return false;
    }
    return FileTransferImpl_this->complete(this);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::filetransfer::FileTransferImpl_SimpleMessageWrapper::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.filetransfer.FileTransferImpl.SimpleMessageWrapper", 65);
    return c;
}

java::lang::Class* org::mpisws::p2p::filetransfer::FileTransferImpl_SimpleMessageWrapper::getClass0()
{
    return class_();
}

