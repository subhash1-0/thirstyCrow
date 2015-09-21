// Generated from /pastry-2.1/src/rice/pastry/PastryNodeFactory.java
#include <rice/pastry/PastryNodeFactory.hpp>

#include <java/lang/Class.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/String.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/LogManager.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/environment/params/Parameters.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::pastry::PastryNodeFactory::PastryNodeFactory(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::PastryNodeFactory::PastryNodeFactory(::rice::environment::Environment* env) 
    : PastryNodeFactory(*static_cast< ::default_init_tag* >(0))
{
    ctor(env);
}

void rice::pastry::PastryNodeFactory::ctor(::rice::environment::Environment* env)
{
    super::ctor();
    this->environment = env;
    rtMax = static_cast< int8_t >(npc(npc(environment)->getParameters())->getInt(u"pastry_rtMax"_j));
    rtBase = static_cast< int8_t >(npc(npc(environment)->getParameters())->getInt(u"pastry_rtBaseBitLength"_j));
    lSetSize = static_cast< int8_t >(npc(npc(environment)->getParameters())->getInt(u"pastry_lSetSize"_j));
    logger = npc(npc(env)->getLogManager())->getLogger(getClass(), nullptr);
}

rice::environment::Environment* rice::pastry::PastryNodeFactory::getEnvironment()
{
    return environment;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::PastryNodeFactory::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.PastryNodeFactory", 29);
    return c;
}

java::lang::Class* rice::pastry::PastryNodeFactory::getClass0()
{
    return class_();
}

