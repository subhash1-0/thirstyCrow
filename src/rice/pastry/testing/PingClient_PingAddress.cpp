// Generated from /pastry-2.1/src/rice/pastry/testing/PingClient.java
#include <rice/pastry/testing/PingClient_PingAddress.hpp>

rice::pastry::testing::PingClient_PingAddress::PingClient_PingAddress(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::testing::PingClient_PingAddress::PingClient_PingAddress()
    : PingClient_PingAddress(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

int32_t& rice::pastry::testing::PingClient_PingAddress::myCode()
{
    clinit();
    return myCode_;
}
int32_t rice::pastry::testing::PingClient_PingAddress::myCode_;

int32_t rice::pastry::testing::PingClient_PingAddress::getCode()
{
    clinit();
    return myCode_;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::testing::PingClient_PingAddress::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.testing.PingClient.PingAddress", 42);
    return c;
}

void rice::pastry::testing::PingClient_PingAddress::clinit()
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

java::lang::Class* rice::pastry::testing::PingClient_PingAddress::getClass0()
{
    return class_();
}

