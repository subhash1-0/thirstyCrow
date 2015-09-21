// Generated from /pastry-2.1/src/rice/pastry/testing/RegrTestApp.java
#include <rice/pastry/testing/RegrTestApp_RTAddress.hpp>

rice::pastry::testing::RegrTestApp_RTAddress::RegrTestApp_RTAddress(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::testing::RegrTestApp_RTAddress::RegrTestApp_RTAddress()
    : RegrTestApp_RTAddress(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

int32_t& rice::pastry::testing::RegrTestApp_RTAddress::myCode()
{
    clinit();
    return myCode_;
}
int32_t rice::pastry::testing::RegrTestApp_RTAddress::myCode_;

int32_t rice::pastry::testing::RegrTestApp_RTAddress::getCode()
{
    clinit();
    return myCode_;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::testing::RegrTestApp_RTAddress::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.testing.RegrTestApp.RTAddress", 41);
    return c;
}

void rice::pastry::testing::RegrTestApp_RTAddress::clinit()
{
    super::clinit();
    static bool in_cl_init = false;
struct clinit_ {
    clinit_() {
        in_cl_init = true;
        myCode_ = int32_t(-1843800321);
    }
};

    if(!in_cl_init) {
        static clinit_ clinit_instance;
    }
}

java::lang::Class* rice::pastry::testing::RegrTestApp_RTAddress::getClass0()
{
    return class_();
}

