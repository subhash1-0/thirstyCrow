// Generated from /pastry-2.1/src/rice/tutorial/ssl/DistTutorial.java
#include <rice/tutorial/ssl/DistTutorial_DistTutorial_1.hpp>

#include <java/io/IOException.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/RuntimeException.hpp>
#include <java/lang/Throwable.hpp>
#include <org/mpisws/p2p/transport/TransportLayer.hpp>
#include <org/mpisws/p2p/transport/ssl/SSLTransportLayerImpl.hpp>
#include <rice/pastry/PastryNode.hpp>
#include <rice/tutorial/ssl/DistTutorial_DistTutorial_1_getBindStrategy_1_1.hpp>
#include <rice/tutorial/ssl/DistTutorial.hpp>

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

rice::tutorial::ssl::DistTutorial_DistTutorial_1::DistTutorial_DistTutorial_1(DistTutorial *DistTutorial_this, ::java::security::KeyStore* store, ::rice::pastry::NodeIdFactory* nf, int32_t startPort, ::rice::environment::Environment* env)
    : super(*static_cast< ::default_init_tag* >(0))
    , DistTutorial_this(DistTutorial_this)
    , store(store)
{
    clinit();
    ctor(nf, startPort, env);
}

rice::tutorial::ssl::DistTutorial_DistTutorial_1::DistTutorial_DistTutorial_1(DistTutorial *DistTutorial_this, ::java::security::KeyStore* store, ::rice::pastry::NodeIdFactory* nf, ::java::net::InetAddress* bindAddress, int32_t startPort, ::rice::environment::Environment* env)
    : super(*static_cast< ::default_init_tag* >(0))
    , DistTutorial_this(DistTutorial_this)
    , store(store)
{
    clinit();
    ctor(nf, bindAddress, startPort, env);
}

org::mpisws::p2p::transport::TransportLayer* rice::tutorial::ssl::DistTutorial_DistTutorial_1::getSourceRouteTransportLayer(::org::mpisws::p2p::transport::TransportLayer* etl, ::rice::pastry::PastryNode* pn, ::org::mpisws::p2p::transport::sourceroute::factory::MultiAddressSourceRouteFactory* esrFactory)
{
    auto sourceRoutingTransportLayer = java_cast< ::org::mpisws::p2p::transport::TransportLayer* >(super::getSourceRouteTransportLayer(etl, pn, esrFactory));
    try {
        return new ::org::mpisws::p2p::transport::ssl::SSLTransportLayerImpl(sourceRoutingTransportLayer, store, store, npc(pn)->getEnvironment());
    } catch (::java::io::IOException* ioe) {
        throw new ::java::lang::RuntimeException(static_cast< ::java::lang::Throwable* >(ioe));
    }
}

org::mpisws::p2p::transport::identity::BindStrategy* rice::tutorial::ssl::DistTutorial_DistTutorial_1::getBindStrategy()
{
    return new DistTutorial_DistTutorial_1_getBindStrategy_1_1(this);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::tutorial::ssl::DistTutorial_DistTutorial_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::tutorial::ssl::DistTutorial_DistTutorial_1::getClass0()
{
    return class_();
}

