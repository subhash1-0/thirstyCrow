// Generated from /pastry-2.1/src/rice/pastry/join/JoinAddress.java
#include <rice/pastry/join/JoinAddress.hpp>

rice::pastry::join::JoinAddress::JoinAddress(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::join::JoinAddress::JoinAddress()
    : JoinAddress(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

constexpr int32_t rice::pastry::join::JoinAddress::myCode;

int32_t rice::pastry::join::JoinAddress::getCode()
{
    clinit();
    return myCode;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::join::JoinAddress::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.join.JoinAddress", 28);
    return c;
}

java::lang::Class* rice::pastry::join::JoinAddress::getClass0()
{
    return class_();
}

