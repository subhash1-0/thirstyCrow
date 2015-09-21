// Generated from /pastry-2.1/src/rice/pastry/peerreview/PeerReviewCallbackImpl.java
#include <rice/pastry/peerreview/PeerReviewCallbackImpl.hpp>

#include <java/lang/Class.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/nio/ByteBuffer.hpp>
#include <java/util/ArrayList.hpp>
#include <java/util/Collection.hpp>
#include <java/util/Iterator.hpp>
#include <java/util/Map.hpp>
#include <org/mpisws/p2p/transport/MessageCallback.hpp>
#include <org/mpisws/p2p/transport/MessageRequestHandle.hpp>
#include <org/mpisws/p2p/transport/P2PSocket.hpp>
#include <org/mpisws/p2p/transport/SocketCallback.hpp>
#include <org/mpisws/p2p/transport/SocketRequestHandle.hpp>
#include <org/mpisws/p2p/transport/TransportLayer.hpp>
#include <org/mpisws/p2p/transport/TransportLayerCallback.hpp>
#include <org/mpisws/p2p/transport/peerreview/WitnessListener.hpp>
#include <org/mpisws/p2p/transport/peerreview/replay/Verifier.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/LogManager.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/pastry/Id.hpp>
#include <rice/pastry/NodeHandle.hpp>
#include <rice/pastry/NodeHandleFactory.hpp>
#include <rice/pastry/PastryNode.hpp>
#include <rice/pastry/leafset/LeafSet.hpp>
#include <rice/pastry/peerreview/CallbackFactory.hpp>
#include <rice/pastry/peerreview/FetchLeafsetApp.hpp>
#include <rice/pastry/peerreview/PeerReviewCallbackImpl_getWitnesses_1.hpp>
#include <rice/pastry/socket/TransportLayerNodeHandle.hpp>

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

rice::pastry::peerreview::PeerReviewCallbackImpl::PeerReviewCallbackImpl(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::peerreview::PeerReviewCallbackImpl::PeerReviewCallbackImpl(::rice::pastry::PastryNode* pn, ::org::mpisws::p2p::transport::TransportLayer* tl, CallbackFactory* nodeFactory) 
    : PeerReviewCallbackImpl(*static_cast< ::default_init_tag* >(0))
{
    ctor(pn,tl,nodeFactory);
}

rice::pastry::peerreview::PeerReviewCallbackImpl::PeerReviewCallbackImpl(::org::mpisws::p2p::transport::TransportLayer* tl) 
    : PeerReviewCallbackImpl(*static_cast< ::default_init_tag* >(0))
{
    ctor(tl);
}

void rice::pastry::peerreview::PeerReviewCallbackImpl::ctor(::rice::pastry::PastryNode* pn, ::org::mpisws::p2p::transport::TransportLayer* tl, CallbackFactory* nodeFactory)
{
    ctor(tl);
    this->pn = pn;
    this->nodeFactory = nodeFactory;
    this->logger = npc(npc(npc(pn)->getEnvironment())->getLogManager())->getLogger(getClass(), nullptr);
    this->fetchLeafSetApp = new FetchLeafsetApp(pn, int32_t(4));
    npc(fetchLeafSetApp)->register_();
}

void rice::pastry::peerreview::PeerReviewCallbackImpl::ctor(::org::mpisws::p2p::transport::TransportLayer* tl)
{
    super::ctor();
    this->tl = tl;
}

org::mpisws::p2p::transport::peerreview::PeerReviewCallback* rice::pastry::peerreview::PeerReviewCallbackImpl::getReplayInstance(::org::mpisws::p2p::transport::peerreview::replay::Verifier* v)
{
    return new PeerReviewCallbackImpl(v);
}

void rice::pastry::peerreview::PeerReviewCallbackImpl::storeCheckpoint(::rice::p2p::commonapi::rawserialization::OutputBuffer* buffer) /* throws(IOException) */
{
    npc(npc(pn)->getId())->serialize(buffer);
    npc(npc(pn)->getLocalHandle())->serialize(buffer);
}

bool rice::pastry::peerreview::PeerReviewCallbackImpl::loadCheckpoint(::rice::p2p::commonapi::rawserialization::InputBuffer* buffer) /* throws(IOException) */
{
    auto environment = npc((java_cast< ::org::mpisws::p2p::transport::peerreview::replay::Verifier* >(tl)))->getEnvironment();
    auto nodeId = ::rice::pastry::Id::build(buffer);
    pn = new ::rice::pastry::PastryNode(nodeId, environment);
    auto nodeHandleFactory = npc(nodeFactory)->getNodeHandleFactory(pn);
    auto handle = java_cast< ::rice::pastry::NodeHandle* >(npc(nodeHandleFactory)->readNodeHandle(buffer));
    npc(npc(nodeFactory)->localHandleTable)->put(pn, handle);
    npc(nodeFactory)->nodeHandleHelper(pn);
    return true;
}

java::util::Collection* rice::pastry::peerreview::PeerReviewCallbackImpl::getMyWitnessedNodes()
{
    auto foo = npc(npc(pn)->getLeafSet())->getUniqueSet();
    auto ret = new ::java::util::ArrayList(npc(foo)->size());
    for (auto _i = npc(foo)->iterator(); _i->hasNext(); ) {
        ::rice::pastry::NodeHandle* h = java_cast< ::rice::pastry::NodeHandle* >(_i->next());
        {
            npc(ret)->add(static_cast< ::java::lang::Object* >(java_cast< ::rice::pastry::socket::TransportLayerNodeHandle* >(h)));
        }
    }
    npc(logger)->log(::java::lang::StringBuilder().append(u"myWitnessedNodes: "_j)->append(static_cast< ::java::lang::Object* >(ret))->toString());
    return ret;
}

void rice::pastry::peerreview::PeerReviewCallbackImpl::init_()
{
}

void rice::pastry::peerreview::PeerReviewCallbackImpl::destroy()
{
}

void rice::pastry::peerreview::PeerReviewCallbackImpl::notifyCertificateAvailable(::rice::pastry::Id* id)
{
}

void rice::pastry::peerreview::PeerReviewCallbackImpl::notifyCertificateAvailable(::java::lang::Object* id)
{ 
    notifyCertificateAvailable(dynamic_cast< ::rice::pastry::Id* >(id));
}

void rice::pastry::peerreview::PeerReviewCallbackImpl::incomingSocket(::org::mpisws::p2p::transport::P2PSocket* s) /* throws(IOException) */
{
    npc(callback)->incomingSocket(s);
}

void rice::pastry::peerreview::PeerReviewCallbackImpl::messageReceived(::rice::pastry::socket::TransportLayerNodeHandle* i, ::java::nio::ByteBuffer* m, ::java::util::Map* options) /* throws(IOException) */
{
    npc(callback)->messageReceived(i, m, options);
}

void rice::pastry::peerreview::PeerReviewCallbackImpl::messageReceived(::java::lang::Object* i, ::java::lang::Object* m, ::java::util::Map* options)
{ 
    messageReceived(dynamic_cast< ::rice::pastry::socket::TransportLayerNodeHandle* >(i), dynamic_cast< ::java::nio::ByteBuffer* >(m), options);
}

void rice::pastry::peerreview::PeerReviewCallbackImpl::notifyStatusChange(::rice::pastry::Id* id, int32_t newStatus)
{
}

void rice::pastry::peerreview::PeerReviewCallbackImpl::notifyStatusChange(::java::lang::Object* id, int32_t newStatus)
{ 
    notifyStatusChange(dynamic_cast< ::rice::pastry::Id* >(id), newStatus);
}

void rice::pastry::peerreview::PeerReviewCallbackImpl::acceptMessages(bool b)
{
}

void rice::pastry::peerreview::PeerReviewCallbackImpl::acceptSockets(bool b)
{
}

void rice::pastry::peerreview::PeerReviewCallbackImpl::getWitnesses(::rice::pastry::Id* subject, ::org::mpisws::p2p::transport::peerreview::WitnessListener* callback)
{
    npc(fetchLeafSetApp)->getNeighbors(subject, new PeerReviewCallbackImpl_getWitnesses_1(this, subject, callback));
}

void rice::pastry::peerreview::PeerReviewCallbackImpl::getWitnesses(::java::lang::Object* subject, ::org::mpisws::p2p::transport::peerreview::WitnessListener* callback)
{ 
    getWitnesses(dynamic_cast< ::rice::pastry::Id* >(subject), dynamic_cast< ::org::mpisws::p2p::transport::peerreview::WitnessListener* >(callback));
}

rice::pastry::socket::TransportLayerNodeHandle* rice::pastry::peerreview::PeerReviewCallbackImpl::getLocalIdentifier()
{
    return java_cast< ::rice::pastry::socket::TransportLayerNodeHandle* >(npc(tl)->getLocalIdentifier());
}

org::mpisws::p2p::transport::SocketRequestHandle* rice::pastry::peerreview::PeerReviewCallbackImpl::openSocket(::rice::pastry::socket::TransportLayerNodeHandle* i, ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe, ::java::util::Map* options)
{
    return npc(tl)->openSocket(i, deliverSocketToMe, options);
}

org::mpisws::p2p::transport::SocketRequestHandle* rice::pastry::peerreview::PeerReviewCallbackImpl::openSocket(::java::lang::Object* i, ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe, ::java::util::Map* options)
{ 
    return openSocket(dynamic_cast< ::rice::pastry::socket::TransportLayerNodeHandle* >(i), dynamic_cast< ::org::mpisws::p2p::transport::SocketCallback* >(deliverSocketToMe), options);
}

void rice::pastry::peerreview::PeerReviewCallbackImpl::setCallback(::org::mpisws::p2p::transport::TransportLayerCallback* callback)
{
    this->callback = callback;
}

void rice::pastry::peerreview::PeerReviewCallbackImpl::setErrorHandler(::org::mpisws::p2p::transport::ErrorHandler* handler)
{
}

org::mpisws::p2p::transport::MessageRequestHandle* rice::pastry::peerreview::PeerReviewCallbackImpl::sendMessage(::rice::pastry::socket::TransportLayerNodeHandle* i, ::java::nio::ByteBuffer* m, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options)
{
    return npc(tl)->sendMessage(i, m, deliverAckToMe, options);
}

org::mpisws::p2p::transport::MessageRequestHandle* rice::pastry::peerreview::PeerReviewCallbackImpl::sendMessage(::java::lang::Object* i, ::java::lang::Object* m, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options)
{ 
    return sendMessage(dynamic_cast< ::rice::pastry::socket::TransportLayerNodeHandle* >(i), dynamic_cast< ::java::nio::ByteBuffer* >(m), dynamic_cast< ::org::mpisws::p2p::transport::MessageCallback* >(deliverAckToMe), options);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::peerreview::PeerReviewCallbackImpl::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.peerreview.PeerReviewCallbackImpl", 45);
    return c;
}

java::lang::Class* rice::pastry::peerreview::PeerReviewCallbackImpl::getClass0()
{
    return class_();
}

