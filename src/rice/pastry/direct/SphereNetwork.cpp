// Generated from /pastry-2.1/src/rice/pastry/direct/SphereNetwork.java
#include <rice/pastry/direct/SphereNetwork.hpp>

#include <java/lang/NullPointerException.hpp>
#include <java/lang/String.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/params/Parameters.hpp>
#include <rice/pastry/direct/proximitygenerators/SphereNetworkProximityGenerator.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::pastry::direct::SphereNetwork::SphereNetwork(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::direct::SphereNetwork::SphereNetwork(::rice::environment::Environment* env) 
    : SphereNetwork(*static_cast< ::default_init_tag* >(0))
{
    ctor(env);
}

void rice::pastry::direct::SphereNetwork::ctor(::rice::environment::Environment* env)
{
    super::ctor(env, new ::rice::pastry::direct::proximitygenerators::SphereNetworkProximityGenerator(npc(npc(env)->getParameters())->getInt(u"pastry_direct_max_diameter"_j)));
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::direct::SphereNetwork::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.direct.SphereNetwork", 32);
    return c;
}

java::lang::Class* rice::pastry::direct::SphereNetwork::getClass0()
{
    return class_();
}

