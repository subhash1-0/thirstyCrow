// Generated from /pastry-2.1/src/rice/pastry/testing/PingTestRecord.java
#include <rice/pastry/testing/PingTestRecord.hpp>

#include <java/lang/Math.hpp>
#include <Array.hpp>

rice::pastry::testing::PingTestRecord::PingTestRecord(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::testing::PingTestRecord::PingTestRecord(int32_t n, int32_t k, int32_t baseBitLength) 
    : PingTestRecord(*static_cast< ::default_init_tag* >(0))
{
    ctor(n,k,baseBitLength);
}

void rice::pastry::testing::PingTestRecord::init()
{
    fDistance = int32_t(0);
}

void rice::pastry::testing::PingTestRecord::ctor(int32_t n, int32_t k, int32_t baseBitLength)
{
    super::ctor(n, k);
    init();
    nIndex = static_cast< int32_t >(::java::lang::Math::ceil(::java::lang::Math::log(n) / ::java::lang::Math::log(::java::lang::Math::pow(2, baseBitLength))));
    nIndex *= 3;
    nHops = new ::int32_tArray(nIndex * int32_t(2));
    fProb = new ::doubleArray(nIndex * int32_t(2));
}

void rice::pastry::testing::PingTestRecord::doneTest()
{
    int32_t i;
    int64_t sum = int32_t(0);
    for (i = 0; i < nIndex; i++) {
        sum += (*nHops)[i] * i;
    }
    fHops = (static_cast< double >(sum)) / nTests;
    fDistance = fDistance / nTests;
    for (i = 0; i < nIndex; i++) {
        (*fProb)[i] = i * (*nHops)[i] / (static_cast< double >(sum));
    }
}

void rice::pastry::testing::PingTestRecord::addHops(int32_t index)
{
    (*nHops)[index]++;
}

void rice::pastry::testing::PingTestRecord::addDistance(double rDistance)
{
    fDistance += rDistance;
}

double rice::pastry::testing::PingTestRecord::getAveHops()
{
    return fHops;
}

double rice::pastry::testing::PingTestRecord::getAveDistance()
{
    return fDistance;
}

doubleArray* rice::pastry::testing::PingTestRecord::getProbability()
{
    return fProb;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::testing::PingTestRecord::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.testing.PingTestRecord", 34);
    return c;
}

java::lang::Class* rice::pastry::testing::PingTestRecord::getClass0()
{
    return class_();
}

