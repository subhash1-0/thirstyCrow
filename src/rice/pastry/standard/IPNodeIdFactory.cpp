// Generated from /pastry-2.1/src/rice/pastry/standard/IPNodeIdFactory.java
#include <rice/pastry/standard/IPNodeIdFactory.hpp>

#include <java/lang/Class.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/RuntimeException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/net/InetAddress.hpp>
#include <java/security/MessageDigest.hpp>
#include <java/security/NoSuchAlgorithmException.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/LogManager.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/pastry/Id.hpp>
#include <Array.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::pastry::standard::IPNodeIdFactory::IPNodeIdFactory(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::standard::IPNodeIdFactory::IPNodeIdFactory(::java::net::InetAddress* localIP, int32_t port, ::rice::environment::Environment* env) 
    : IPNodeIdFactory(*static_cast< ::default_init_tag* >(0))
{
    ctor(localIP,port,env);
}

int32_t& rice::pastry::standard::IPNodeIdFactory::nextInstance()
{
    clinit();
    return nextInstance_;
}
int32_t rice::pastry::standard::IPNodeIdFactory::nextInstance_;

void rice::pastry::standard::IPNodeIdFactory::ctor(::java::net::InetAddress* localIP, int32_t port, ::rice::environment::Environment* env)
{
    super::ctor();
    this->port = port;
    this->environment = env;
    this->logger = npc(npc(env)->getLogManager())->getLogger(getClass(), nullptr);
    try {
        this->localIP = localIP;
        if(npc(localIP)->isLoopbackAddress())
            throw new ::java::lang::Exception(u"got loopback address: nodeIds will not be unique across computers!"_j);

    } catch (::java::lang::Exception* e) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::SEVERE)
            npc(logger)->log(::java::lang::StringBuilder().append(u"ALERT: IPNodeIdFactory cannot determine local IP address: "_j)->append(static_cast< ::java::lang::Object* >(e))->toString());

    }
}

rice::pastry::Id* rice::pastry::standard::IPNodeIdFactory::generateNodeId()
{
    auto rawIP = npc(localIP)->getAddress();
    auto rawPort = new ::int8_tArray(int32_t(2));
    auto tmp = port;
    for (auto i = int32_t(0); i < 2; i++) {
        (*rawPort)[i] = static_cast< int8_t >((tmp & int32_t(255)));
        tmp >>= 8;
    }
    auto raw = new ::int8_tArray(int32_t(4));
    tmp = ++nextInstance_;
    for (auto i = int32_t(0); i < 4; i++) {
        (*raw)[i] = static_cast< int8_t >((tmp & int32_t(255)));
        tmp >>= 8;
    }
    ::java::security::MessageDigest* md = nullptr;
    try {
        md = ::java::security::MessageDigest::getInstance(u"SHA"_j);
    } catch (::java::security::NoSuchAlgorithmException* e) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::SEVERE)
            npc(logger)->log(u"No SHA support!"_j);

        throw new ::java::lang::RuntimeException(u"No SHA support!"_j, e);
    }
    npc(md)->update(rawIP);
    npc(md)->update(rawPort);
    npc(md)->update(raw);
    auto digest = npc(md)->digest();
    auto nodeId = ::rice::pastry::Id::build(digest);
    return nodeId;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::standard::IPNodeIdFactory::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.standard.IPNodeIdFactory", 36);
    return c;
}

void rice::pastry::standard::IPNodeIdFactory::clinit()
{
    super::clinit();
    static bool in_cl_init = false;
struct clinit_ {
    clinit_() {
        in_cl_init = true;
        nextInstance_ = int32_t(0);
    }
};

    if(!in_cl_init) {
        static clinit_ clinit_instance;
    }
}

java::lang::Class* rice::pastry::standard::IPNodeIdFactory::getClass0()
{
    return class_();
}

