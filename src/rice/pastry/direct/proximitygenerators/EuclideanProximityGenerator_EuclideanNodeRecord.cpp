// Generated from /pastry-2.1/src/rice/pastry/direct/proximitygenerators/EuclideanProximityGenerator.java
#include <rice/pastry/direct/proximitygenerators/EuclideanProximityGenerator_EuclideanNodeRecord.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/Math.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/environment/random/RandomSource.hpp>
#include <rice/pastry/direct/NodeRecord.hpp>
#include <rice/pastry/direct/proximitygenerators/EuclideanProximityGenerator.hpp>

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

rice::pastry::direct::proximitygenerators::EuclideanProximityGenerator_EuclideanNodeRecord::EuclideanProximityGenerator_EuclideanNodeRecord(EuclideanProximityGenerator *EuclideanProximityGenerator_this, const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
    , EuclideanProximityGenerator_this(EuclideanProximityGenerator_this)
{
    clinit();
}

rice::pastry::direct::proximitygenerators::EuclideanProximityGenerator_EuclideanNodeRecord::EuclideanProximityGenerator_EuclideanNodeRecord(EuclideanProximityGenerator *EuclideanProximityGenerator_this) 
    : EuclideanProximityGenerator_EuclideanNodeRecord(EuclideanProximityGenerator_this, *static_cast< ::default_init_tag* >(0))
{
    ctor();
}

void rice::pastry::direct::proximitygenerators::EuclideanProximityGenerator_EuclideanNodeRecord::ctor()
{
    super::ctor();
    x = npc(EuclideanProximityGenerator_this->random)->nextInt() % EuclideanProximityGenerator_this->side;
    y = npc(EuclideanProximityGenerator_this->random)->nextInt() % EuclideanProximityGenerator_this->side;
    alive = true;
}

float rice::pastry::direct::proximitygenerators::EuclideanProximityGenerator_EuclideanNodeRecord::proximity(::rice::pastry::direct::NodeRecord* that)
{
    return ::java::lang::Math::round((networkDelay(that) * 2.0));
}

float rice::pastry::direct::proximitygenerators::EuclideanProximityGenerator_EuclideanNodeRecord::networkDelay(::rice::pastry::direct::NodeRecord* that)
{
    auto nr = java_cast< EuclideanProximityGenerator_EuclideanNodeRecord* >(that);
    auto dx = x - npc(nr)->x;
    auto dy = y - npc(nr)->y;
    auto ret = static_cast< float >(::java::lang::Math::sqrt(dx * dx + dy * dy));
    if((ret < 2.0) && !this->equals(that))
        return static_cast< float >(2.0);

    return ret;
}

java::lang::String* rice::pastry::direct::proximitygenerators::EuclideanProximityGenerator_EuclideanNodeRecord::toString()
{
    return ::java::lang::StringBuilder().append(u"ENR("_j)->append(x)
        ->append(u","_j)
        ->append(y)
        ->append(u")"_j)->toString();
}

void rice::pastry::direct::proximitygenerators::EuclideanProximityGenerator_EuclideanNodeRecord::markDead()
{
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::direct::proximitygenerators::EuclideanProximityGenerator_EuclideanNodeRecord::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.direct.proximitygenerators.EuclideanProximityGenerator.EuclideanNodeRecord", 86);
    return c;
}

java::lang::Class* rice::pastry::direct::proximitygenerators::EuclideanProximityGenerator_EuclideanNodeRecord::getClass0()
{
    return class_();
}

