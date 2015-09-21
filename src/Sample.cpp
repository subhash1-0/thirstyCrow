// Generated from /pastry-2.1/license/Sample.java
#include <Sample.hpp>

Sample::Sample(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

Sample::Sample(int32_t s) 
    : Sample(*static_cast< ::default_init_tag* >(0))
{
    ctor(s);
}

void Sample::ctor(int32_t s)
{
    super::ctor();
    something = s;
    nothing = int32_t(2) * s;
}

int32_t Sample::eat(int32_t x)
{
    return nothing * something * x;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* Sample::class_()
{
    static ::java::lang::Class* c = ::class_(u"Sample", 6);
    return c;
}

java::lang::Class* Sample::getClass0()
{
    return class_();
}

