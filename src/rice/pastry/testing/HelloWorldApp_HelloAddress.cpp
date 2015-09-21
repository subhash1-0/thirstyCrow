// Generated from /pastry-2.1/src/rice/pastry/testing/HelloWorldApp.java
#include <rice/pastry/testing/HelloWorldApp_HelloAddress.hpp>

rice::pastry::testing::HelloWorldApp_HelloAddress::HelloWorldApp_HelloAddress(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::testing::HelloWorldApp_HelloAddress::HelloWorldApp_HelloAddress()
    : HelloWorldApp_HelloAddress(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

int32_t& rice::pastry::testing::HelloWorldApp_HelloAddress::myCode()
{
    clinit();
    return myCode_;
}
int32_t rice::pastry::testing::HelloWorldApp_HelloAddress::myCode_;

int32_t rice::pastry::testing::HelloWorldApp_HelloAddress::getCode()
{
    clinit();
    return myCode_;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::testing::HelloWorldApp_HelloAddress::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.testing.HelloWorldApp.HelloAddress", 46);
    return c;
}

void rice::pastry::testing::HelloWorldApp_HelloAddress::clinit()
{
    super::clinit();
    static bool in_cl_init = false;
struct clinit_ {
    clinit_() {
        in_cl_init = true;
        myCode_ = int32_t(428125133);
    }
};

    if(!in_cl_init) {
        static clinit_ clinit_instance;
    }
}

java::lang::Class* rice::pastry::testing::HelloWorldApp_HelloAddress::getClass0()
{
    return class_();
}

