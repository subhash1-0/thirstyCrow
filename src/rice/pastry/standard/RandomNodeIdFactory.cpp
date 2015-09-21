// Generated from /pastry-2.1/src/rice/pastry/standard/RandomNodeIdFactory.java
#include <rice/pastry/standard/RandomNodeIdFactory.hpp>

#include <java/lang/Class.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/RuntimeException.hpp>
#include <java/lang/String.hpp>
#include <java/security/MessageDigest.hpp>
#include <java/security/NoSuchAlgorithmException.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/LogManager.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/environment/random/RandomSource.hpp>
#include <rice/pastry/Id.hpp>
#include <Array.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::pastry::standard::RandomNodeIdFactory::RandomNodeIdFactory(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::standard::RandomNodeIdFactory::RandomNodeIdFactory(::rice::environment::Environment* env) 
    : RandomNodeIdFactory(*static_cast< ::default_init_tag* >(0))
{
    ctor(env);
}

void rice::pastry::standard::RandomNodeIdFactory::ctor(::rice::environment::Environment* env)
{
    super::ctor();
    this->environment = env;
    next = npc(npc(env)->getRandomSource())->nextLong();
    this->logger = npc(npc(env)->getLogManager())->getLogger(getClass(), nullptr);
}

rice::pastry::Id* rice::pastry::standard::RandomNodeIdFactory::generateNodeId()
{
    auto raw = new ::int8_tArray(int32_t(8));
    auto tmp = ++next;
    for (auto i = int32_t(0); i < 8; i++) {
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
    npc(md)->update(raw);
    auto digest = npc(md)->digest();
    auto nodeId = ::rice::pastry::Id::build(digest);
    return nodeId;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::standard::RandomNodeIdFactory::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.standard.RandomNodeIdFactory", 40);
    return c;
}

java::lang::Class* rice::pastry::standard::RandomNodeIdFactory::getClass0()
{
    return class_();
}

