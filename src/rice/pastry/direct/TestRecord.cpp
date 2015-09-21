// Generated from /pastry-2.1/src/rice/pastry/direct/TestRecord.java
#include <rice/pastry/direct/TestRecord.hpp>

rice::pastry::direct::TestRecord::TestRecord(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::direct::TestRecord::TestRecord(int32_t n, int32_t k) 
    : TestRecord(*static_cast< ::default_init_tag* >(0))
{
    ctor(n,k);
}

void rice::pastry::direct::TestRecord::ctor(int32_t n, int32_t k)
{
    super::ctor();
    nNodes = n;
    nTests = k;
}

int32_t rice::pastry::direct::TestRecord::getNodeNumber()
{
    return nNodes;
}

int32_t rice::pastry::direct::TestRecord::getTestNumber()
{
    return nTests;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::direct::TestRecord::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.direct.TestRecord", 29);
    return c;
}

java::lang::Class* rice::pastry::direct::TestRecord::getClass0()
{
    return class_();
}

