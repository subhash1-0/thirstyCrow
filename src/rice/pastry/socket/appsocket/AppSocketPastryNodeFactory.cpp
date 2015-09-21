// Generated from /pastry-2.1/src/rice/pastry/socket/appsocket/AppSocketPastryNodeFactory.java
#include <rice/pastry/socket/appsocket/AppSocketPastryNodeFactory.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/String.hpp>
#include <java/util/HashMap.hpp>
#include <org/mpisws/p2p/transport/TransportLayer.hpp>
#include <org/mpisws/p2p/transport/wire/WireTransportLayerImpl.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/pastry/Id.hpp>
#include <rice/pastry/NodeHandle.hpp>
#include <rice/pastry/NodeHandleFactory.hpp>
#include <rice/pastry/PastryNode.hpp>
#include <rice/pastry/socket/SocketNodeHandleFactory.hpp>
#include <rice/pastry/socket/SocketPastryNodeFactory_TransLiveness.hpp>
#include <rice/pastry/socket/appsocket/AppSocketPastryNodeFactory_getLivenessTransportLayer_2.hpp>
#include <rice/pastry/socket/appsocket/AppSocketPastryNodeFactory_getSocketFactory_1.hpp>
#include <rice/pastry/socket/appsocket/AppSocketPastryNodeFactory_BogusTLPastryNode.hpp>
#include <rice/pastry/socket/appsocket/SocketFactory.hpp>
#include <rice/pastry/transport/NodeHandleAdapter.hpp>
#include <rice/pastry/transport/TLDeserializer.hpp>

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

rice::pastry::socket::appsocket::AppSocketPastryNodeFactory::AppSocketPastryNodeFactory(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::socket::appsocket::AppSocketPastryNodeFactory::AppSocketPastryNodeFactory(::rice::pastry::NodeIdFactory* nf, int32_t startPort, ::rice::environment::Environment* env)  /* throws(IOException) */
    : AppSocketPastryNodeFactory(*static_cast< ::default_init_tag* >(0))
{
    ctor(nf,startPort,env);
}

rice::pastry::socket::appsocket::AppSocketPastryNodeFactory::AppSocketPastryNodeFactory(::rice::pastry::NodeIdFactory* nf, ::java::net::InetAddress* bindAddress, int32_t startPort, ::rice::environment::Environment* env)  /* throws(IOException) */
    : AppSocketPastryNodeFactory(*static_cast< ::default_init_tag* >(0))
{
    ctor(nf,bindAddress,startPort,env);
}

void rice::pastry::socket::appsocket::AppSocketPastryNodeFactory::init()
{
    socketTable = new ::java::util::HashMap();
}

void rice::pastry::socket::appsocket::AppSocketPastryNodeFactory::ctor(::rice::pastry::NodeIdFactory* nf, int32_t startPort, ::rice::environment::Environment* env) /* throws(IOException) */
{
    super::ctor(nf, startPort, env);
    init();
}

void rice::pastry::socket::appsocket::AppSocketPastryNodeFactory::ctor(::rice::pastry::NodeIdFactory* nf, ::java::net::InetAddress* bindAddress, int32_t startPort, ::rice::environment::Environment* env) /* throws(IOException) */
{
    super::ctor(nf, bindAddress, startPort, env);
    init();
}

java::lang::String*& rice::pastry::socket::appsocket::AppSocketPastryNodeFactory::STORE_SOCKET()
{
    clinit();
    return STORE_SOCKET_;
}
java::lang::String* rice::pastry::socket::appsocket::AppSocketPastryNodeFactory::STORE_SOCKET_;

java::lang::String*& rice::pastry::socket::appsocket::AppSocketPastryNodeFactory::SOCKET_FACTORY_UID()
{
    clinit();
    return SOCKET_FACTORY_UID_;
}
java::lang::String* rice::pastry::socket::appsocket::AppSocketPastryNodeFactory::SOCKET_FACTORY_UID_;

rice::pastry::socket::appsocket::SocketFactory* rice::pastry::socket::appsocket::AppSocketPastryNodeFactory::getSocketFactory() /* throws(IOException) */
{
    if(sf != nullptr)
        return sf;

    auto nodeId = ::rice::pastry::Id::build();
    auto const pn = new AppSocketPastryNodeFactory_BogusTLPastryNode(this, nodeId, environment);
    auto const handleFactory = java_cast< ::rice::pastry::socket::SocketNodeHandleFactory* >(getNodeHandleFactory(static_cast< ::rice::pastry::PastryNode* >(pn)));
    auto const localhandle = getLocalHandle(static_cast< ::rice::pastry::PastryNode* >(pn), static_cast< ::rice::pastry::NodeHandleFactory* >(handleFactory));
    npc(pn)->setLocalHandle(localhandle);
    auto deserializer = getTLDeserializer(handleFactory, pn);
    auto const nha = getNodeHandleAdapter(static_cast< ::rice::pastry::PastryNode* >(pn), static_cast< ::rice::pastry::NodeHandleFactory* >(handleFactory), deserializer);
    sf = new AppSocketPastryNodeFactory_getSocketFactory_1(this, handleFactory, nha);
    return sf;
}

org::mpisws::p2p::transport::TransportLayer* rice::pastry::socket::appsocket::AppSocketPastryNodeFactory::getWireTransportLayer(::java::net::InetSocketAddress* innermostAddress, ::rice::pastry::PastryNode* pn) /* throws(IOException) */
{
    auto environment = npc(pn)->getEnvironment();
    auto wtl = new ::org::mpisws::p2p::transport::wire::WireTransportLayerImpl(innermostAddress, environment, nullptr, !(dynamic_cast< AppSocketPastryNodeFactory_BogusTLPastryNode* >(pn) != nullptr));
    npc(wtl)->addSocketCountListener(getSocketCountListener(pn));
    if(dynamic_cast< AppSocketPastryNodeFactory_BogusTLPastryNode* >(pn) != nullptr) {
        return npc((java_cast< AppSocketPastryNodeFactory_BogusTLPastryNode* >(pn)))->getWireTransportLayer(wtl);
    }
    return wtl;
}

rice::pastry::socket::SocketPastryNodeFactory_TransLiveness* rice::pastry::socket::appsocket::AppSocketPastryNodeFactory::getLivenessTransportLayer(::org::mpisws::p2p::transport::TransportLayer* tl, ::rice::pastry::PastryNode* pn)
{
    if(dynamic_cast< AppSocketPastryNodeFactory_BogusTLPastryNode* >(pn) != nullptr) {
        return new AppSocketPastryNodeFactory_getLivenessTransportLayer_2(this, tl);
    }
    return java_cast< ::rice::pastry::socket::SocketPastryNodeFactory_TransLiveness* >(super::getLivenessTransportLayer(tl, pn));
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::socket::appsocket::AppSocketPastryNodeFactory::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.socket.appsocket.AppSocketPastryNodeFactory", 55);
    return c;
}

void rice::pastry::socket::appsocket::AppSocketPastryNodeFactory::clinit()
{
struct string_init_ {
    string_init_() {
    STORE_SOCKET_ = u"store_socket"_j;
    SOCKET_FACTORY_UID_ = u"appSocketFactory.uid"_j;
    }
};

    static string_init_ string_init_instance;

    super::clinit();
}

java::lang::Class* rice::pastry::socket::appsocket::AppSocketPastryNodeFactory::getClass0()
{
    return class_();
}

