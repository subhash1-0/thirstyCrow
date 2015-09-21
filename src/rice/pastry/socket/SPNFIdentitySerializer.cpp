// Generated from /pastry-2.1/src/rice/pastry/socket/SPNFIdentitySerializer.java
#include <rice/pastry/socket/SPNFIdentitySerializer.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/util/HashMap.hpp>
#include <java/util/Map.hpp>
#include <org/mpisws/p2p/transport/identity/SerializerListener.hpp>
#include <org/mpisws/p2p/transport/multiaddress/MultiInetSocketAddress.hpp>
#include <org/mpisws/p2p/transport/sourceroute/SourceRoute.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/commonapi/rawserialization/InputBuffer.hpp>
#include <rice/p2p/commonapi/rawserialization/OutputBuffer.hpp>
#include <rice/pastry/Id.hpp>
#include <rice/pastry/NodeHandleFactoryListener.hpp>
#include <rice/pastry/PastryNode.hpp>
#include <rice/pastry/socket/SPNFIdentitySerializer_addSerializerListener_1.hpp>
#include <rice/pastry/socket/SocketNodeHandle.hpp>
#include <rice/pastry/socket/SocketNodeHandleFactory.hpp>
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

rice::pastry::socket::SPNFIdentitySerializer::SPNFIdentitySerializer(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::socket::SPNFIdentitySerializer::SPNFIdentitySerializer(::rice::pastry::PastryNode* pn, SocketNodeHandleFactory* factory) 
    : SPNFIdentitySerializer(*static_cast< ::default_init_tag* >(0))
{
    ctor(pn,factory);
}

void rice::pastry::socket::SPNFIdentitySerializer::init()
{
    listeners = new ::java::util::HashMap();
}

void rice::pastry::socket::SPNFIdentitySerializer::ctor(::rice::pastry::PastryNode* pn, SocketNodeHandleFactory* factory)
{
    super::ctor();
    init();
    this->pn = pn;
    this->factory = factory;
}

void rice::pastry::socket::SPNFIdentitySerializer::serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf, TransportLayerNodeHandle* i) /* throws(IOException) */
{
    auto epoch = npc(i)->getEpoch();
    auto nid = java_cast< ::rice::pastry::Id* >(npc(i)->getId());
    npc(buf)->writeLong(epoch);
    npc(nid)->serialize(buf);
}

void rice::pastry::socket::SPNFIdentitySerializer::serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf, ::java::lang::Object* i)
{ 
    serialize(buf, dynamic_cast< TransportLayerNodeHandle* >(i));
}

rice::pastry::socket::TransportLayerNodeHandle* rice::pastry::socket::SPNFIdentitySerializer::deserialize(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::org::mpisws::p2p::transport::sourceroute::SourceRoute* i) /* throws(IOException) */
{
    auto epoch = npc(buf)->readLong();
    auto nid = ::rice::pastry::Id::build(buf);
    auto ret = buildSNH(buf, java_cast< ::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* >(npc(i)->getLastHop()), epoch, nid);
    return java_cast< TransportLayerNodeHandle* >(npc(factory)->coalesce(ret));
}

java::lang::Object* rice::pastry::socket::SPNFIdentitySerializer::deserialize(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::java::lang::Object* l)
{ 
    return deserialize(buf, dynamic_cast< ::org::mpisws::p2p::transport::sourceroute::SourceRoute* >(l));
}

rice::pastry::socket::SocketNodeHandle* rice::pastry::socket::SPNFIdentitySerializer::buildSNH(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* i, int64_t epoch, ::rice::pastry::Id* nid) /* throws(IOException) */
{
    return new SocketNodeHandle(i, epoch, nid, pn);
}

org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* rice::pastry::socket::SPNFIdentitySerializer::translateDown(TransportLayerNodeHandle* i)
{
    return java_cast< ::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* >(npc(i)->getAddress());
}

java::lang::Object* rice::pastry::socket::SPNFIdentitySerializer::translateDown(::java::lang::Object* i)
{ 
    return translateDown(dynamic_cast< TransportLayerNodeHandle* >(i));
}

org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* rice::pastry::socket::SPNFIdentitySerializer::translateUp(::org::mpisws::p2p::transport::sourceroute::SourceRoute* i)
{
    return java_cast< ::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* >(npc(i)->getLastHop());
}

java::lang::Object* rice::pastry::socket::SPNFIdentitySerializer::translateUp(::java::lang::Object* i)
{ 
    return translateUp(dynamic_cast< ::org::mpisws::p2p::transport::sourceroute::SourceRoute* >(i));
}

void rice::pastry::socket::SPNFIdentitySerializer::addSerializerListener(::org::mpisws::p2p::transport::identity::SerializerListener* listener)
{
    ::rice::pastry::NodeHandleFactoryListener* foo = new SPNFIdentitySerializer_addSerializerListener_1(this, listener);
    npc(listeners)->put(listener, foo);
    npc(factory)->addNodeHandleFactoryListener(foo);
}

void rice::pastry::socket::SPNFIdentitySerializer::removeSerializerListener(::org::mpisws::p2p::transport::identity::SerializerListener* listener)
{
    npc(factory)->removeNodeHandleFactoryListener(java_cast< ::rice::pastry::NodeHandleFactoryListener* >(npc(listeners)->get(listener)));
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::socket::SPNFIdentitySerializer::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.socket.SPNFIdentitySerializer", 41);
    return c;
}

java::lang::Class* rice::pastry::socket::SPNFIdentitySerializer::getClass0()
{
    return class_();
}

