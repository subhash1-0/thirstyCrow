// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/priority/PriorityTransportLayerImpl.java
#include <org/mpisws/p2p/transport/priority/PriorityTransportLayerImpl_EntityManager_MessageWrapper.hpp>

#include <java/io/IOException.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/System.hpp>
#include <java/lang/ref/WeakReference.hpp>
#include <java/nio/ByteBuffer.hpp>
#include <java/util/Map.hpp>
#include <org/mpisws/p2p/transport/MessageCallback.hpp>
#include <org/mpisws/p2p/transport/P2PSocket.hpp>
#include <org/mpisws/p2p/transport/priority/MessageInfoImpl.hpp>
#include <org/mpisws/p2p/transport/priority/PriorityTransportLayerImpl_EntityManager.hpp>
#include <org/mpisws/p2p/transport/priority/PriorityTransportLayerImpl.hpp>
#include <org/mpisws/p2p/transport/priority/QueueOverflowException.hpp>
#include <rice/environment/logging/Logger.hpp>
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
org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_EntityManager_MessageWrapper::PriorityTransportLayerImpl_EntityManager_MessageWrapper(PriorityTransportLayerImpl_EntityManager *PriorityTransportLayerImpl_EntityManager_this, const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
    , PriorityTransportLayerImpl_EntityManager_this(PriorityTransportLayerImpl_EntityManager_this)
{
    clinit();
}

org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_EntityManager_MessageWrapper::PriorityTransportLayerImpl_EntityManager_MessageWrapper(PriorityTransportLayerImpl_EntityManager *PriorityTransportLayerImpl_EntityManager_this, ::java::lang::Object* temp, ::java::nio::ByteBuffer* message, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options, int32_t priority, int32_t seq) 
    : PriorityTransportLayerImpl_EntityManager_MessageWrapper(PriorityTransportLayerImpl_EntityManager_this, *static_cast< ::default_init_tag* >(0))
{
    ctor(temp,message,deliverAckToMe,options,priority,seq);
}

void org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_EntityManager_MessageWrapper::init()
{
    cancelled = false;
    completed = false;
}

void org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_EntityManager_MessageWrapper::ctor(::java::lang::Object* temp, ::java::nio::ByteBuffer* message, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options, int32_t priority, int32_t seq)
{
    super::ctor();
    init();
    this->originalSize = npc(message)->remaining();
    this->myIdentifier = temp;
    this->originalMessage = message;
    auto size = npc(message)->remaining();
    this->message = ::java::nio::ByteBuffer::allocate(npc(message)->remaining() + int32_t(4));
    npc(this->message)->put(static_cast< int8_t >(((static_cast<int32_t>(static_cast<uint32_t>(size) >> int32_t(24))) & int32_t(255))));
    npc(this->message)->put(static_cast< int8_t >(((static_cast<int32_t>(static_cast<uint32_t>(size) >> int32_t(16))) & int32_t(255))));
    npc(this->message)->put(static_cast< int8_t >(((static_cast<int32_t>(static_cast<uint32_t>(size) >> int32_t(8))) & int32_t(255))));
    npc(this->message)->put(static_cast< int8_t >(((static_cast<int32_t>(static_cast<uint32_t>(size) >> int32_t(0))) & int32_t(255))));
    npc(this->message)->put(message);
    npc(this->message)->clear();
    this->deliverAckToMe = deliverAckToMe;
    this->options = options;
    this->priority = priority;
    this->seq = seq;
}

org::mpisws::p2p::transport::priority::MessageInfo* org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_EntityManager_MessageWrapper::getMessageInfo()
{
    return new MessageInfoImpl(originalMessage, options, priority);
}

void org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_EntityManager_MessageWrapper::complete()
{
    completed = true;
    if(deliverAckToMe != nullptr)
        npc(deliverAckToMe)->ack(this);

    PriorityTransportLayerImpl_EntityManager_this->PriorityTransportLayerImpl_this->notifyListenersWrote(originalSize, java_cast< ::java::lang::Object* >(myIdentifier), options);
}

bool org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_EntityManager_MessageWrapper::receiveSelectResult(::org::mpisws::p2p::transport::P2PSocket* socket) /* throws(IOException) */
{
    if(npc(PriorityTransportLayerImpl_EntityManager_this->PriorityTransportLayerImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINEST)
        npc(PriorityTransportLayerImpl_EntityManager_this->PriorityTransportLayerImpl_this->logger)->log(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(this))->append(u".receiveSelectResult("_j)
            ->append(static_cast< ::java::lang::Object* >(socket))
            ->append(u")"_j)->toString());

    try {
        if(this->socket != nullptr && static_cast< ::java::lang::Object* >(this->socket) != static_cast< ::java::lang::Object* >(socket)) {
            if(npc(PriorityTransportLayerImpl_EntityManager_this->PriorityTransportLayerImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
                npc(PriorityTransportLayerImpl_EntityManager_this->PriorityTransportLayerImpl_this->logger)->log(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(this))->append(u" Socket changed!!! can:"_j)
                    ->append(cancelled)
                    ->append(u" comp:"_j)
                    ->append(completed)
                    ->append(u" socket:"_j)
                    ->append(static_cast< ::java::lang::Object* >(socket))
                    ->append(u" writingSocket:"_j)
                    ->append(static_cast< ::java::lang::Object* >(PriorityTransportLayerImpl_EntityManager_this->writingSocket))
                    ->append(u" this.socket:"_j)
                    ->append(static_cast< ::java::lang::Object* >(this->socket))->toString());

            npc(socket)->shutdownOutput();
            return false;
        }
        this->socket = socket;
        if(cancelled && npc(message)->position() == 0) {
            if(npc(PriorityTransportLayerImpl_EntityManager_this->PriorityTransportLayerImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINEST)
                npc(PriorityTransportLayerImpl_EntityManager_this->PriorityTransportLayerImpl_this->logger)->log(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(this))->append(u".rsr("_j)
                    ->append(static_cast< ::java::lang::Object* >(socket))
                    ->append(u") cancelled"_j)->toString());

            return true;
        } else {
            int64_t bytesWritten;
            if((bytesWritten = npc(socket)->write(message)) == -int32_t(1)) {
                if(npc(PriorityTransportLayerImpl_EntityManager_this->PriorityTransportLayerImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINEST)
                    npc(PriorityTransportLayerImpl_EntityManager_this->PriorityTransportLayerImpl_this->logger)->log(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(this))->append(u".rsr("_j)
                        ->append(static_cast< ::java::lang::Object* >(socket))
                        ->append(u") socket was closed"_j)->toString());

                PriorityTransportLayerImpl_EntityManager_this->clearAndEnqueue(this);
                return false;
            }
            if(npc(PriorityTransportLayerImpl_EntityManager_this->PriorityTransportLayerImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINER)
                npc(PriorityTransportLayerImpl_EntityManager_this->PriorityTransportLayerImpl_this->logger)->log(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(this))->append(u" wrote "_j)
                    ->append(bytesWritten)
                    ->append(u" bytes of "_j)
                    ->append(npc(message)->capacity())
                    ->append(u" remaining:"_j)
                    ->append(npc(message)->remaining())->toString());

            if(npc(message)->hasRemaining()) {
                if(npc(PriorityTransportLayerImpl_EntityManager_this->PriorityTransportLayerImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINEST)
                    npc(PriorityTransportLayerImpl_EntityManager_this->PriorityTransportLayerImpl_this->logger)->log(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(this))->append(u".rsr("_j)
                        ->append(static_cast< ::java::lang::Object* >(socket))
                        ->append(u") has remaining"_j)->toString());

                return false;
            }
        }
        return PriorityTransportLayerImpl_EntityManager_this->complete(this);
    } catch (::java::io::IOException* ioe) {
        if(npc(PriorityTransportLayerImpl_EntityManager_this->PriorityTransportLayerImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINEST)
            npc(PriorityTransportLayerImpl_EntityManager_this->PriorityTransportLayerImpl_this->logger)->logException(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(this))->append(u".rsr("_j)
                ->append(static_cast< ::java::lang::Object* >(socket))
                ->append(u")"_j)->toString(), ioe);

        throw ioe;
    }
}

void org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_EntityManager_MessageWrapper::drop()
{
    if(deliverAckToMe != nullptr)
        npc(deliverAckToMe)->sendFailed(this, new QueueOverflowException(java_cast< ::java::lang::Object* >(npc(PriorityTransportLayerImpl_EntityManager_this->identifier)->get()), originalMessage));

    PriorityTransportLayerImpl_EntityManager_this->PriorityTransportLayerImpl_this->notifyListenersDropped(originalSize, java_cast< ::java::lang::Object* >(myIdentifier), options);
}

int32_t org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_EntityManager_MessageWrapper::compareTo(PriorityTransportLayerImpl_EntityManager_MessageWrapper* that)
{
    if(this->priority == npc(that)->priority) {
        return this->seq - npc(that)->seq;
    }
    return this->priority - npc(that)->priority;
}

int32_t org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_EntityManager_MessageWrapper::compareTo(::java::lang::Object* o)
{ 
    return compareTo(dynamic_cast< PriorityTransportLayerImpl_EntityManager_MessageWrapper* >(o));
}

java::lang::Object* org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_EntityManager_MessageWrapper::getIdentifier()
{
    return java_cast< ::java::lang::Object* >(myIdentifier);
}

java::nio::ByteBuffer* org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_EntityManager_MessageWrapper::getMessage()
{
    return originalMessage;
}

java::util::Map* org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_EntityManager_MessageWrapper::getOptions()
{
    return options;
}

void org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_EntityManager_MessageWrapper::reset()
{
    npc(message)->clear();
    socket = nullptr;
}

bool org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_EntityManager_MessageWrapper::cancel()
{
    cancelled = true;
    {
        synchronized synchronized_0(PriorityTransportLayerImpl_EntityManager_this->queue);
        {
            if(this->equals(PriorityTransportLayerImpl_EntityManager_this->messageThatIsBeingWritten)) {
                if(npc(message)->position() == 0) {
                    PriorityTransportLayerImpl_EntityManager_this->messageThatIsBeingWritten = nullptr;
                    return true;
                } else {
                    return false;
                }
            }
            return npc(PriorityTransportLayerImpl_EntityManager_this->queue)->remove(static_cast< ::java::lang::Object* >(this));
        }
    }
}

java::lang::String* org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_EntityManager_MessageWrapper::toString()
{
    return ::java::lang::StringBuilder().append(u"MessagWrapper{"_j)->append(static_cast< ::java::lang::Object* >(message))
        ->append(u"}@"_j)
        ->append(::java::lang::System::identityHashCode(this))
        ->append(u"->"_j)
        ->append(static_cast< ::java::lang::Object* >(java_cast< ::java::lang::Object* >(npc(PriorityTransportLayerImpl_EntityManager_this->identifier)->get())))
        ->append(u" pri:"_j)
        ->append(priority)
        ->append(u" seq:"_j)
        ->append(seq)
        ->append(u" s:"_j)
        ->append(static_cast< ::java::lang::Object* >(this->socket))->toString();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_EntityManager_MessageWrapper::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.priority.PriorityTransportLayerImpl.EntityManager.MessageWrapper", 89);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_EntityManager_MessageWrapper::getClass0()
{
    return class_();
}

