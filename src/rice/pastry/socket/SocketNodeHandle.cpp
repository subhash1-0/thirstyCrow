// Generated from /pastry-2.1/src/rice/pastry/socket/SocketNodeHandle.java
#include <rice/pastry/socket/SocketNodeHandle.hpp>

#include <java/lang/Class.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Integer.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/net/InetSocketAddress.hpp>
#include <java/util/HashMap.hpp>
#include <java/util/Map.hpp>
#include <org/mpisws/p2p/transport/liveness/LivenessProvider.hpp>
#include <org/mpisws/p2p/transport/multiaddress/MultiInetSocketAddress.hpp>
#include <org/mpisws/p2p/transport/priority/PriorityTransportLayer.hpp>
#include <org/mpisws/p2p/transport/proximity/ProximityProvider.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/LogManager.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/p2p/commonapi/rawserialization/InputBuffer.hpp>
#include <rice/p2p/commonapi/rawserialization/OutputBuffer.hpp>
#include <rice/pastry/Id.hpp>
#include <rice/pastry/NodeHandle.hpp>
#include <rice/pastry/PastryNode.hpp>
#include <rice/pastry/messaging/Message.hpp>

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

rice::pastry::socket::SocketNodeHandle::SocketNodeHandle(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::socket::SocketNodeHandle::SocketNodeHandle(::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* eisa, int64_t epoch, ::rice::pastry::Id* id, ::rice::pastry::PastryNode* node) 
    : SocketNodeHandle(*static_cast< ::default_init_tag* >(0))
{
    ctor(eisa,epoch,id,node);
}

void rice::pastry::socket::SocketNodeHandle::ctor(::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* eisa, int64_t epoch, ::rice::pastry::Id* id, ::rice::pastry::PastryNode* node)
{
    super::ctor(id);
    this->eaddress = eisa;
    this->epoch = epoch;
    setLocalNode(node);
}

int64_t rice::pastry::socket::SocketNodeHandle::getEpoch()
{
    return epoch;
}

void rice::pastry::socket::SocketNodeHandle::setLocalNode(::rice::pastry::PastryNode* pn)
{
    localnode = pn;
    this->logger = npc(npc(npc(localnode)->getEnvironment())->getLogManager())->getLogger(getClass(), nullptr);
}

org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* rice::pastry::socket::SocketNodeHandle::getIdentifier()
{
    return eaddress;
}

int32_t rice::pastry::socket::SocketNodeHandle::getLiveness()
{
    if(isLocal()) {
        return LIVENESS_ALIVE;
    } else {
        return npc(npc((java_cast< ::rice::pastry::PastryNode* >(localnode)))->getLivenessProvider())->getLiveness(this, nullptr);
    }
}

org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* rice::pastry::socket::SocketNodeHandle::getAddress()
{
    return eaddress;
}

java::net::InetSocketAddress* rice::pastry::socket::SocketNodeHandle::getInetSocketAddress()
{
    return npc(eaddress)->getAddress(0);
}

bool rice::pastry::socket::SocketNodeHandle::checkLiveness()
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(this))->append(u".checkLiveness()"_j)->toString());

    npc(npc((java_cast< ::rice::pastry::PastryNode* >(localnode)))->getLivenessProvider())->checkLiveness(this, nullptr);
    return isAlive();
}

bool rice::pastry::socket::SocketNodeHandle::isLocal()
{
    assertLocalNode();
    return npc(npc(getLocalNode())->getLocalHandle())->equals(static_cast< ::java::lang::Object* >(this));
}

void rice::pastry::socket::SocketNodeHandle::receiveMessage(::rice::pastry::messaging::Message* msg)
{
    assertLocalNode();
    ::java::util::Map* options = new ::java::util::HashMap(int32_t(1));
    npc(options)->put(::org::mpisws::p2p::transport::priority::PriorityTransportLayer::OPTION_PRIORITY(), ::java::lang::Integer::valueOf(npc(msg)->getPriority()));
    npc(getLocalNode())->send(this, msg, nullptr, options);
}

java::lang::String* rice::pastry::socket::SocketNodeHandle::toString()
{
    return ::java::lang::StringBuilder().append(u"[SNH: "_j)->append(static_cast< ::java::lang::Object* >(nodeId))
        ->append(u"/"_j)
        ->append(static_cast< ::java::lang::Object* >(eaddress))
        ->append(u"]"_j)->toString();
}

java::lang::String* rice::pastry::socket::SocketNodeHandle::toStringFull()
{
    return ::java::lang::StringBuilder().append(u"[SNH: "_j)->append(static_cast< ::java::lang::Object* >(nodeId))
        ->append(u"/"_j)
        ->append(static_cast< ::java::lang::Object* >(eaddress))
        ->append(u" "_j)
        ->append(epoch)
        ->append(u"]"_j)->toString();
}

bool rice::pastry::socket::SocketNodeHandle::equals(::java::lang::Object* obj)
{
    if(!(dynamic_cast< SocketNodeHandle* >(obj) != nullptr))
        return false;

    auto other = java_cast< SocketNodeHandle* >(obj);
    auto ret = (epoch == npc(other)->epoch && npc(npc(other)->getNodeId())->equals(getNodeId()) && npc(npc(other)->eaddress)->equals(static_cast< ::java::lang::Object* >(eaddress)));
    return ret;
}

int32_t rice::pastry::socket::SocketNodeHandle::hashCode()
{
    auto hash = (static_cast< int32_t >(epoch)) ^ npc(getNodeId())->hashCode() ^ npc(eaddress)->hashCode();
    return hash;
}

int32_t rice::pastry::socket::SocketNodeHandle::proximity()
{
    return npc(npc((java_cast< ::rice::pastry::PastryNode* >(localnode)))->getProxProvider())->proximity(this, nullptr);
}

bool rice::pastry::socket::SocketNodeHandle::ping()
{
    if(npc(npc(localnode)->getLocalHandle())->equals(static_cast< ::java::lang::Object* >(this)))
        return false;

    npc(npc((java_cast< ::rice::pastry::PastryNode* >(localnode)))->getLivenessProvider())->checkLiveness(this, nullptr);
    return isAlive();
}

void rice::pastry::socket::SocketNodeHandle::update(::java::util::Observable* o, ::java::lang::Object* obj)
{
}

rice::pastry::socket::SocketNodeHandle* rice::pastry::socket::SocketNodeHandle::build(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::pastry::PastryNode* local) /* throws(IOException) */
{
    clinit();
    auto eaddr = ::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress::build(buf);
    auto epoch = npc(buf)->readLong();
    auto nid = ::rice::pastry::Id::build(buf);
    return new SocketNodeHandle(eaddr, epoch, nid, local);
}

void rice::pastry::socket::SocketNodeHandle::serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */
{
    npc(eaddress)->serialize(buf);
    npc(buf)->writeLong(epoch);
    npc(nodeId)->serialize(buf);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::socket::SocketNodeHandle::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.socket.SocketNodeHandle", 35);
    return c;
}

void rice::pastry::socket::SocketNodeHandle::update(::java::lang::Object* update)
{
    super::update(update);
}

java::lang::Class* rice::pastry::socket::SocketNodeHandle::getClass0()
{
    return class_();
}

