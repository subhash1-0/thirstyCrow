// Generated from /pastry-2.1/src/rice/tutorial/lookup/LookupService.java
#include <rice/tutorial/lookup/LookupService_NodeLookupTimeout.hpp>

rice::tutorial::lookup::LookupService_NodeLookupTimeout::LookupService_NodeLookupTimeout(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::tutorial::lookup::LookupService_NodeLookupTimeout::LookupService_NodeLookupTimeout(int32_t seqno) 
    : LookupService_NodeLookupTimeout(*static_cast< ::default_init_tag* >(0))
{
    ctor(seqno);
}

constexpr int64_t rice::tutorial::lookup::LookupService_NodeLookupTimeout::serialVersionUID;

void rice::tutorial::lookup::LookupService_NodeLookupTimeout::ctor(int32_t seqno)
{
    super::ctor();
    this->seqno = seqno;
}

int32_t rice::tutorial::lookup::LookupService_NodeLookupTimeout::getPriority()
{
    return 0;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::tutorial::lookup::LookupService_NodeLookupTimeout::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.tutorial.lookup.LookupService.NodeLookupTimeout", 52);
    return c;
}

java::lang::Class* rice::tutorial::lookup::LookupService_NodeLookupTimeout::getClass0()
{
    return class_();
}

