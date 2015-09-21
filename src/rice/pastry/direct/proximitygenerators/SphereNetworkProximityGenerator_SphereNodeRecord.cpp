// Generated from /pastry-2.1/src/rice/pastry/direct/proximitygenerators/SphereNetworkProximityGenerator.java
#include <rice/pastry/direct/proximitygenerators/SphereNetworkProximityGenerator_SphereNodeRecord.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/Math.hpp>
#include <java/lang/NullPointerException.hpp>
#include <rice/environment/random/RandomSource.hpp>
#include <rice/pastry/direct/NodeRecord.hpp>
#include <rice/pastry/direct/proximitygenerators/SphereNetworkProximityGenerator.hpp>

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

rice::pastry::direct::proximitygenerators::SphereNetworkProximityGenerator_SphereNodeRecord::SphereNetworkProximityGenerator_SphereNodeRecord(SphereNetworkProximityGenerator *SphereNetworkProximityGenerator_this, const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
    , SphereNetworkProximityGenerator_this(SphereNetworkProximityGenerator_this)
{
    clinit();
}

rice::pastry::direct::proximitygenerators::SphereNetworkProximityGenerator_SphereNodeRecord::SphereNetworkProximityGenerator_SphereNodeRecord(SphereNetworkProximityGenerator *SphereNetworkProximityGenerator_this) 
    : SphereNetworkProximityGenerator_SphereNodeRecord(SphereNetworkProximityGenerator_this, *static_cast< ::default_init_tag* >(0))
{
    ctor();
}

rice::pastry::direct::proximitygenerators::SphereNetworkProximityGenerator_SphereNodeRecord::SphereNetworkProximityGenerator_SphereNodeRecord(SphereNetworkProximityGenerator *SphereNetworkProximityGenerator_this, double theta, double phi) 
    : SphereNetworkProximityGenerator_SphereNodeRecord(SphereNetworkProximityGenerator_this, *static_cast< ::default_init_tag* >(0))
{
    ctor(theta,phi);
}

void rice::pastry::direct::proximitygenerators::SphereNetworkProximityGenerator_SphereNodeRecord::ctor()
{
    ctor(::java::lang::Math::asin(2.0 * npc(SphereNetworkProximityGenerator_this->random)->nextDouble() - 1.0), 2.0 * ::java::lang::Math::PI * npc(SphereNetworkProximityGenerator_this->random)->nextDouble());
}

void rice::pastry::direct::proximitygenerators::SphereNetworkProximityGenerator_SphereNodeRecord::ctor(double theta, double phi)
{
    super::ctor();
    this->theta = theta;
    this->phi = phi;
    radius = SphereNetworkProximityGenerator_this->maxDiameter / ::java::lang::Math::PI;
}

float rice::pastry::direct::proximitygenerators::SphereNetworkProximityGenerator_SphereNodeRecord::proximity(::rice::pastry::direct::NodeRecord* that)
{
    return static_cast< float >(::java::lang::Math::round(networkDelay(that) * 2.0));
}

float rice::pastry::direct::proximitygenerators::SphereNetworkProximityGenerator_SphereNodeRecord::networkDelay(::rice::pastry::direct::NodeRecord* that)
{
    auto nr = java_cast< SphereNetworkProximityGenerator_SphereNodeRecord* >(that);
    auto ret = (radius * ::java::lang::Math::acos(::java::lang::Math::cos(phi - npc(nr)->phi) * ::java::lang::Math::cos(theta) * ::java::lang::Math::cos(npc(nr)->theta) + ::java::lang::Math::sin(theta) * ::java::lang::Math::sin(npc(nr)->theta)));
    if((ret < 2.0) && !this->equals(that))
        return static_cast< float >(2.0);

    return static_cast< float >(ret);
}

void rice::pastry::direct::proximitygenerators::SphereNetworkProximityGenerator_SphereNodeRecord::markDead()
{
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::direct::proximitygenerators::SphereNetworkProximityGenerator_SphereNodeRecord::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.direct.proximitygenerators.SphereNetworkProximityGenerator.SphereNodeRecord", 87);
    return c;
}

java::lang::Class* rice::pastry::direct::proximitygenerators::SphereNetworkProximityGenerator_SphereNodeRecord::getClass0()
{
    return class_();
}

