// Generated from /pastry-2.1/src/rice/pastry/direct/proximitygenerators/EuclideanProximityGenerator.java
#include <rice/pastry/direct/proximitygenerators/EuclideanProximityGenerator.hpp>

#include <java/lang/Math.hpp>
#include <rice/environment/random/RandomSource.hpp>
#include <rice/pastry/direct/proximitygenerators/EuclideanProximityGenerator_EuclideanNodeRecord.hpp>

rice::pastry::direct::proximitygenerators::EuclideanProximityGenerator::EuclideanProximityGenerator(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::direct::proximitygenerators::EuclideanProximityGenerator::EuclideanProximityGenerator(int32_t maxDiameter) 
    : EuclideanProximityGenerator(*static_cast< ::default_init_tag* >(0))
{
    ctor(maxDiameter);
}

void rice::pastry::direct::proximitygenerators::EuclideanProximityGenerator::ctor(int32_t maxDiameter)
{
    super::ctor();
    side = static_cast< int32_t >((maxDiameter / ::java::lang::Math::sqrt(2.0)));
}

rice::pastry::direct::NodeRecord* rice::pastry::direct::proximitygenerators::EuclideanProximityGenerator::generateNodeRecord()
{
    return new EuclideanProximityGenerator_EuclideanNodeRecord(this);
}

void rice::pastry::direct::proximitygenerators::EuclideanProximityGenerator::setRandom(::rice::environment::random::RandomSource* random)
{
    this->random = random;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::direct::proximitygenerators::EuclideanProximityGenerator::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.direct.proximitygenerators.EuclideanProximityGenerator", 66);
    return c;
}

java::lang::Class* rice::pastry::direct::proximitygenerators::EuclideanProximityGenerator::getClass0()
{
    return class_();
}

