// Generated from /pastry-2.1/src/org/mpisws/p2p/filetransfer/FileTransferImpl.java
#include <org/mpisws/p2p/filetransfer/FileTransferImpl_MessageWrapperImpl.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/nio/ByteBuffer.hpp>
#include <java/util/LinkedList.hpp>
#include <java/util/List.hpp>
#include <org/mpisws/p2p/filetransfer/FileTransferImpl_MessageWrapper.hpp>
#include <org/mpisws/p2p/filetransfer/FileTransferImpl_ReceiptImpl.hpp>
#include <org/mpisws/p2p/filetransfer/FileTransferImpl.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/p2p/commonapi/appsocket/AppSocket.hpp>
#include <rice/p2p/util/SortedLinkedList.hpp>

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

extern void lock(::java::lang::Object *);
extern void unlock(::java::lang::Object *);

namespace
{
    struct synchronized
    {
        synchronized(::java::lang::Object *o) : o(o) { ::lock(o); }
        ~synchronized() { ::unlock(o); }
    private:
        synchronized(const synchronized&); synchronized& operator=(const synchronized&);
        ::java::lang::Object *o;
    };
}
org::mpisws::p2p::filetransfer::FileTransferImpl_MessageWrapperImpl::FileTransferImpl_MessageWrapperImpl(FileTransferImpl *FileTransferImpl_this, const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
    , FileTransferImpl_this(FileTransferImpl_this)
{
    clinit();
}

org::mpisws::p2p::filetransfer::FileTransferImpl_MessageWrapperImpl::FileTransferImpl_MessageWrapperImpl(FileTransferImpl *FileTransferImpl_this, FileTransferImpl_ReceiptImpl* receipt, int64_t seq, ::java::util::List* message) 
    : FileTransferImpl_MessageWrapperImpl(FileTransferImpl_this, *static_cast< ::default_init_tag* >(0))
{
    ctor(receipt,seq,message);
}

void org::mpisws::p2p::filetransfer::FileTransferImpl_MessageWrapperImpl::init()
{
    started = false;
}

void org::mpisws::p2p::filetransfer::FileTransferImpl_MessageWrapperImpl::ctor(FileTransferImpl_ReceiptImpl* receipt, int64_t seq, ::java::util::List* message)
{
    super::ctor();
    init();
    this->receipt = receipt;
    this->seq = seq;
    this->message = message;
}

java::lang::String* org::mpisws::p2p::filetransfer::FileTransferImpl_MessageWrapperImpl::toString()
{
    return ::java::lang::StringBuilder().append(u"Part "_j)->append(seq)
        ->append(u" of "_j)
        ->append(static_cast< ::java::lang::Object* >(receipt))->toString();
}

void org::mpisws::p2p::filetransfer::FileTransferImpl_MessageWrapperImpl::drop()
{
    npc(receipt)->failed();
}

bool org::mpisws::p2p::filetransfer::FileTransferImpl_MessageWrapperImpl::cancel()
{
    if(this->equals(FileTransferImpl_this->messageThatIsBeingWritten)) {
        if(!started) {
            return true;
        } else {
            return false;
        }
    }
    {
        synchronized synchronized_0(FileTransferImpl_this->queue);
        {
            return npc(FileTransferImpl_this->queue)->remove(static_cast< ::java::lang::Object* >(this));
        }
    }
}

void org::mpisws::p2p::filetransfer::FileTransferImpl_MessageWrapperImpl::clear(::java::util::LinkedList* message, int64_t seq)
{
    started = false;
    this->message = message;
    this->seq = seq;
}

int32_t org::mpisws::p2p::filetransfer::FileTransferImpl_MessageWrapperImpl::compareTo(FileTransferImpl_MessageWrapper* that)
{
    if(npc(this->receipt)->priority == npc(that)->getPriority()) {
        if(npc(this->receipt)->uid == npc(that)->getUid()) {
            return static_cast< int32_t >((this->seq - npc(that)->getSeq()));
        }
        return npc(this->receipt)->uid - npc(that)->getUid();
    }
    return npc(this->receipt)->priority - npc(that)->getPriority();
}

int32_t org::mpisws::p2p::filetransfer::FileTransferImpl_MessageWrapperImpl::compareTo(::java::lang::Object* arg0)
{ 
    return compareTo(dynamic_cast< FileTransferImpl_MessageWrapper* >(arg0));
}

bool org::mpisws::p2p::filetransfer::FileTransferImpl_MessageWrapperImpl::receiveSelectResult(::rice::p2p::commonapi::appsocket::AppSocket* socket) /* throws(IOException) */
{
    if(npc(FileTransferImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINEST)
        npc(FileTransferImpl_this->logger)->log(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(this))->append(u".receiveSelectResult("_j)
            ->append(static_cast< ::java::lang::Object* >(socket))
            ->append(u")"_j)->toString());

    if(npc(receipt)->isCancelled() && !started) {
        if(npc(FileTransferImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINEST)
            npc(FileTransferImpl_this->logger)->log(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(this))->append(u".rsr("_j)
                ->append(static_cast< ::java::lang::Object* >(socket))
                ->append(u") cancelled"_j)->toString());

        FileTransferImpl_this->messageThatIsBeingWritten = nullptr;
        return true;
    } else {
        started = true;
        int64_t bytesWritten;
        if((bytesWritten = npc(socket)->write(java_cast< ::java::nio::ByteBuffer* >(npc(message)->get(0)))) == -int32_t(1)) {
            FileTransferImpl_this->socketClosed();
            return false;
        }
        if(npc(java_cast< ::java::nio::ByteBuffer* >(npc(message)->get(0)))->hasRemaining()) {
            if(npc(FileTransferImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINEST)
                npc(FileTransferImpl_this->logger)->log(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(this))->append(u".rsr("_j)
                    ->append(static_cast< ::java::lang::Object* >(socket))
                    ->append(u") has remaining"_j)->toString());

            return false;
        } else {
            npc(message)->remove(int32_t(0));
            if(!npc(message)->isEmpty())
                return receiveSelectResult(socket);

        }
    }
    return FileTransferImpl_this->complete(this);
}

void org::mpisws::p2p::filetransfer::FileTransferImpl_MessageWrapperImpl::complete()
{
    npc(receipt)->complete(this);
}

int8_t org::mpisws::p2p::filetransfer::FileTransferImpl_MessageWrapperImpl::getPriority()
{
    return npc(receipt)->getPriority();
}

int64_t org::mpisws::p2p::filetransfer::FileTransferImpl_MessageWrapperImpl::getSeq()
{
    return seq;
}

int32_t org::mpisws::p2p::filetransfer::FileTransferImpl_MessageWrapperImpl::getUid()
{
    return npc(receipt)->getUID();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::filetransfer::FileTransferImpl_MessageWrapperImpl::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.filetransfer.FileTransferImpl.MessageWrapperImpl", 63);
    return c;
}

java::lang::Class* org::mpisws::p2p::filetransfer::FileTransferImpl_MessageWrapperImpl::getClass0()
{
    return class_();
}

