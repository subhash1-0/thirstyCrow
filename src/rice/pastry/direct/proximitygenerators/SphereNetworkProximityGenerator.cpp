// Generated from /pastry-2.1/src/rice/pastry/direct/proximitygenerators/SphereNetworkProximityGenerator.java
#include <rice/pastry/direct/proximitygenerators/SphereNetworkProximityGenerator.hpp>

#include <java/io/PrintStream.hpp>
#include <java/lang/Math.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/System.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/params/Parameters.hpp>
#include <rice/environment/random/RandomSource.hpp>
#include <rice/pastry/direct/NodeRecord.hpp>
#include <rice/pastry/direct/proximitygenerators/SphereNetworkProximityGenerator_SphereNodeRecord.hpp>

template<typename ComponentType, typename... Bases> struct SubArray;
namespace java
{
    namespace io
    {
typedef ::SubArray< ::java::io::Serializable, ::java::lang::ObjectArray > SerializableArray;
    } // io

    namespace lang
    {
typedef ::SubArray< ::java::lang::CharSequence, ObjectArray > CharSequenceArray;
typedef ::SubArray< ::java::lang::Comparable, ObjectArray > ComparableArray;
typedef ::SubArray< ::java::lang::String, ObjectArray, ::java::io::SerializableArray, ComparableArray, CharSequenceArray > StringArray;
    } // lang
} // java

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::pastry::direct::proximitygenerators::SphereNetworkProximityGenerator::SphereNetworkProximityGenerator(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::direct::proximitygenerators::SphereNetworkProximityGenerator::SphereNetworkProximityGenerator(int32_t maxDiameter) 
    : SphereNetworkProximityGenerator(*static_cast< ::default_init_tag* >(0))
{
    ctor(maxDiameter);
}

void rice::pastry::direct::proximitygenerators::SphereNetworkProximityGenerator::ctor(int32_t maxDiameter)
{
    super::ctor();
    this->maxDiameter = maxDiameter;
}

rice::pastry::direct::NodeRecord* rice::pastry::direct::proximitygenerators::SphereNetworkProximityGenerator::generateNodeRecord()
{
    return new SphereNetworkProximityGenerator_SphereNodeRecord(this);
}

void rice::pastry::direct::proximitygenerators::SphereNetworkProximityGenerator::test()
{
    npc(::java::lang::System::out())->println((new SphereNetworkProximityGenerator_SphereNodeRecord(this, int32_t(0), int32_t(0)))->proximity(static_cast< ::rice::pastry::direct::NodeRecord* >(new SphereNetworkProximityGenerator_SphereNodeRecord(this, int32_t(0), ::java::lang::Math::PI))));
    npc(::java::lang::System::out())->println((new SphereNetworkProximityGenerator_SphereNodeRecord(this, -int32_t(1), int32_t(0)))->proximity(static_cast< ::rice::pastry::direct::NodeRecord* >(new SphereNetworkProximityGenerator_SphereNodeRecord(this, int32_t(1), ::java::lang::Math::PI))));
    for (auto i = int32_t(0); i < 100; i++) {
        npc(::java::lang::System::out())->println((new SphereNetworkProximityGenerator_SphereNodeRecord(this))->proximity(static_cast< ::rice::pastry::direct::NodeRecord* >(new SphereNetworkProximityGenerator_SphereNodeRecord(this))));
    }
}

void rice::pastry::direct::proximitygenerators::SphereNetworkProximityGenerator::main(::java::lang::StringArray* argz)
{
    clinit();
    npc(::java::lang::System::out())->println(u"hello world"_j);
    (new SphereNetworkProximityGenerator(npc(npc(::rice::environment::Environment::directEnvironment())->getParameters())->getInt(u"pastry_direct_max_diameter"_j)))->test();
}

void rice::pastry::direct::proximitygenerators::SphereNetworkProximityGenerator::setRandom(::rice::environment::random::RandomSource* random)
{
    this->random = random;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::direct::proximitygenerators::SphereNetworkProximityGenerator::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.direct.proximitygenerators.SphereNetworkProximityGenerator", 70);
    return c;
}

java::lang::Class* rice::pastry::direct::proximitygenerators::SphereNetworkProximityGenerator::getClass0()
{
    return class_();
}

