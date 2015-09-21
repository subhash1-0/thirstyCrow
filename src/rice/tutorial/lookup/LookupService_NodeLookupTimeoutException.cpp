// Generated from /pastry-2.1/src/rice/tutorial/lookup/LookupService.java
#include <rice/tutorial/lookup/LookupService_NodeLookupTimeoutException.hpp>

rice::tutorial::lookup::LookupService_NodeLookupTimeoutException::LookupService_NodeLookupTimeoutException(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::tutorial::lookup::LookupService_NodeLookupTimeoutException::LookupService_NodeLookupTimeoutException()
    : LookupService_NodeLookupTimeoutException(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

constexpr int64_t rice::tutorial::lookup::LookupService_NodeLookupTimeoutException::serialVersionUID;

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::tutorial::lookup::LookupService_NodeLookupTimeoutException::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.tutorial.lookup.LookupService.NodeLookupTimeoutException", 61);
    return c;
}

java::lang::Class* rice::tutorial::lookup::LookupService_NodeLookupTimeoutException::getClass0()
{
    return class_();
}

