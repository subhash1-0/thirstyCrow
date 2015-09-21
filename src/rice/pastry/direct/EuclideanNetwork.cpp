// Generated from /pastry-2.1/src/rice/pastry/direct/EuclideanNetwork.java
#include <rice/pastry/direct/EuclideanNetwork.hpp>

#include <java/lang/NullPointerException.hpp>
#include <java/lang/String.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/params/Parameters.hpp>
#include <rice/pastry/direct/proximitygenerators/EuclideanProximityGenerator.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::pastry::direct::EuclideanNetwork::EuclideanNetwork(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::direct::EuclideanNetwork::EuclideanNetwork(::rice::environment::Environment* env) 
    : EuclideanNetwork(*static_cast< ::default_init_tag* >(0))
{
    ctor(env);
}

void rice::pastry::direct::EuclideanNetwork::ctor(::rice::environment::Environment* env)
{
    super::ctor(env, new ::rice::pastry::direct::proximitygenerators::EuclideanProximityGenerator(npc(npc(env)->getParameters())->getInt(u"pastry_direct_max_diameter"_j)));
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::direct::EuclideanNetwork::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.direct.EuclideanNetwork", 35);
    return c;
}

java::lang::Class* rice::pastry::direct::EuclideanNetwork::getClass0()
{
    return class_();
}

