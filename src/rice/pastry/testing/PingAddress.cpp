// Generated from /pastry-2.1/src/rice/pastry/testing/PingAddress.java
#include <rice/pastry/testing/PingAddress.hpp>

rice::pastry::testing::PingAddress::PingAddress(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::testing::PingAddress::PingAddress()
    : PingAddress(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

int32_t& rice::pastry::testing::PingAddress::myCode()
{
    clinit();
    return myCode_;
}
int32_t rice::pastry::testing::PingAddress::myCode_;

int32_t rice::pastry::testing::PingAddress::getCode()
{
    clinit();
    return myCode_;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::testing::PingAddress::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.testing.PingAddress", 31);
    return c;
}

void rice::pastry::testing::PingAddress::clinit()
{
    super::clinit();
    static bool in_cl_init = false;
struct clinit_ {
    clinit_() {
        in_cl_init = true;
        myCode_ = int32_t(-1843799809);
    }
};

    if(!in_cl_init) {
        static clinit_ clinit_instance;
    }
}

java::lang::Class* rice::pastry::testing::PingAddress::getClass0()
{
    return class_();
}

