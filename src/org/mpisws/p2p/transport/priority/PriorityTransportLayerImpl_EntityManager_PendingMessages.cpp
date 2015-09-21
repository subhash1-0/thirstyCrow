// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/priority/PriorityTransportLayerImpl.java
#include <org/mpisws/p2p/transport/priority/PriorityTransportLayerImpl_EntityManager_PendingMessages.hpp>

#include <java/io/IOException.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/nio/ByteBuffer.hpp>
#include <java/util/Iterator.hpp>
#include <java/util/LinkedList.hpp>
#include <java/util/Map.hpp>
#include <org/mpisws/p2p/transport/ClosedChannelException.hpp>
#include <org/mpisws/p2p/transport/P2PSocket.hpp>
#include <org/mpisws/p2p/transport/TransportLayer.hpp>
#include <org/mpisws/p2p/transport/priority/PriorityTransportLayerImpl_EntityManager_PendingMessages_PendingMessage.hpp>
#include <org/mpisws/p2p/transport/priority/PriorityTransportLayerImpl_EntityManager.hpp>
#include <org/mpisws/p2p/transport/priority/PriorityTransportLayerImpl.hpp>
#include <rice/environment/logging/Logger.hpp>

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

org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_EntityManager_PendingMessages::PriorityTransportLayerImpl_EntityManager_PendingMessages(PriorityTransportLayerImpl_EntityManager *PriorityTransportLayerImpl_EntityManager_this, const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
    , PriorityTransportLayerImpl_EntityManager_this(PriorityTransportLayerImpl_EntityManager_this)
{
    clinit();
}

org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_EntityManager_PendingMessages::PriorityTransportLayerImpl_EntityManager_PendingMessages(PriorityTransportLayerImpl_EntityManager *PriorityTransportLayerImpl_EntityManager_this, ::java::lang::Object* i) 
    : PriorityTransportLayerImpl_EntityManager_PendingMessages(PriorityTransportLayerImpl_EntityManager_this, *static_cast< ::default_init_tag* >(0))
{
    ctor(i);
}

void org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_EntityManager_PendingMessages::init()
{
    msgs = new ::java::util::LinkedList();
}

void org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_EntityManager_PendingMessages::ctor(::java::lang::Object* i)
{
    super::ctor();
    init();
    this->i = i;
    header = ::java::nio::ByteBuffer::wrap(PriorityTransportLayerImpl::BIG_MSG_SOCKET());
}

void org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_EntityManager_PendingMessages::start(::java::util::Map* options)
{
    if(npc(PriorityTransportLayerImpl_EntityManager_this->PriorityTransportLayerImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINER)
        npc(PriorityTransportLayerImpl_EntityManager_this->PriorityTransportLayerImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Opening BIG message socket to:"_j)->append(static_cast< ::java::lang::Object* >(java_cast< ::java::lang::Object* >(i)))->toString());

    npc(PriorityTransportLayerImpl_EntityManager_this->PriorityTransportLayerImpl_this->tl)->openSocket(java_cast< ::java::lang::Object* >(i), this, options);
}

org::mpisws::p2p::transport::MessageRequestHandle* org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_EntityManager_PendingMessages::addMessage(::java::nio::ByteBuffer* m, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options)
{
    if(npc(PriorityTransportLayerImpl_EntityManager_this->PriorityTransportLayerImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(PriorityTransportLayerImpl_EntityManager_this->PriorityTransportLayerImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Sending BIG message of size:"_j)->append(npc(m)->remaining())
            ->append(u" to:"_j)
            ->append(static_cast< ::java::lang::Object* >(java_cast< ::java::lang::Object* >(i)))->toString());

    auto ret = new PriorityTransportLayerImpl_EntityManager_PendingMessages_PendingMessage(this, m, deliverAckToMe, options);
    npc(msgs)->addLast(static_cast< ::java::lang::Object* >(ret));
    return ret;
}

void org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_EntityManager_PendingMessages::receiveException(::org::mpisws::p2p::transport::SocketRequestHandle* s, ::java::lang::Exception* ex)
{
    receiveException(ex);
}

void org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_EntityManager_PendingMessages::receiveException(::org::mpisws::p2p::transport::P2PSocket* socket, ::java::lang::Exception* ioe)
{
    receiveException(ioe);
}

void org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_EntityManager_PendingMessages::receiveException(::java::lang::Exception* ex)
{
    npc(PriorityTransportLayerImpl_EntityManager_this->pendingBigMessages)->remove(this);
    for (auto _i = npc(msgs)->iterator(); _i->hasNext(); ) {
        PriorityTransportLayerImpl_EntityManager_PendingMessages_PendingMessage* foo = java_cast< PriorityTransportLayerImpl_EntityManager_PendingMessages_PendingMessage* >(_i->next());
        {
            npc(foo)->sendFailed(ex);
        }
    }
    if(socket != nullptr) {
        auto temp = socket;
        socket = nullptr;
        npc(temp)->close();
    }
}

void org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_EntityManager_PendingMessages::receiveSelectResult(::org::mpisws::p2p::transport::P2PSocket* socket, bool canRead, bool canWrite) /* throws(IOException) */
{
    if(npc(header)->hasRemaining()) {
        if(npc(socket)->write(header) < 0) {
            if(npc(PriorityTransportLayerImpl_EntityManager_this->PriorityTransportLayerImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
                npc(PriorityTransportLayerImpl_EntityManager_this->PriorityTransportLayerImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Error writing BIG message header to:"_j)->append(static_cast< ::java::lang::Object* >(socket))->toString());

            receiveException(new ::org::mpisws::p2p::transport::ClosedChannelException(u"Socket closed before writing BIG header."_j));
            return;
        }
        if(npc(header)->hasRemaining()) {
            npc(socket)->register_(false, true, this);
            return;
        } else {
            if(npc(PriorityTransportLayerImpl_EntityManager_this->PriorityTransportLayerImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINER)
                npc(PriorityTransportLayerImpl_EntityManager_this->PriorityTransportLayerImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Wrote BIG message header to:"_j)->append(static_cast< ::java::lang::Object* >(socket))->toString());

        }
    }
    try {
        sendNextMessage();
    } catch (::java::io::IOException* ioe) {
        receiveException(ioe);
    }
}

void org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_EntityManager_PendingMessages::receiveResult(::org::mpisws::p2p::transport::SocketRequestHandle* cancellable, ::org::mpisws::p2p::transport::P2PSocket* sock)
{
    socket = sock;
    try {
        if(npc(PriorityTransportLayerImpl_EntityManager_this->PriorityTransportLayerImpl_this->logger)->level <= ::rice::environment::logging::Logger::INFO)
            npc(PriorityTransportLayerImpl_EntityManager_this->PriorityTransportLayerImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Opened BIG message socket to:"_j)->append(static_cast< ::java::lang::Object* >(java_cast< ::java::lang::Object* >(i)))->toString());

        receiveSelectResult(sock, false, true);
    } catch (::java::io::IOException* ioe) {
        receiveException(ioe);
    }
}

void org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_EntityManager_PendingMessages::sendNextMessage() /* throws(IOException) */
{
    if(npc(msgs)->isEmpty()) {
        npc(socket)->close();
        npc(PriorityTransportLayerImpl_EntityManager_this->pendingBigMessages)->remove(java_cast< ::java::lang::Object* >(i));
        return;
    }
    npc(java_cast< PriorityTransportLayerImpl_EntityManager_PendingMessages_PendingMessage* >(npc(msgs)->getFirst()))->send();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_EntityManager_PendingMessages::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.priority.PriorityTransportLayerImpl.EntityManager.PendingMessages", 90);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_EntityManager_PendingMessages::getClass0()
{
    return class_();
}

