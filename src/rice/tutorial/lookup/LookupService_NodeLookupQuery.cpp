// Generated from /pastry-2.1/src/rice/tutorial/lookup/LookupService.java
#include <rice/tutorial/lookup/LookupService_NodeLookupQuery.hpp>

#include <rice/p2p/commonapi/NodeHandle.hpp>

rice::tutorial::lookup::LookupService_NodeLookupQuery::LookupService_NodeLookupQuery(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::tutorial::lookup::LookupService_NodeLookupQuery::LookupService_NodeLookupQuery(::rice::p2p::commonapi::NodeHandle* localHandle, int32_t num, int32_t seqno) 
    : LookupService_NodeLookupQuery(*static_cast< ::default_init_tag* >(0))
{
    ctor(localHandle,num,seqno);
}

constexpr int64_t rice::tutorial::lookup::LookupService_NodeLookupQuery::serialVersionUID;

void rice::tutorial::lookup::LookupService_NodeLookupQuery::ctor(::rice::p2p::commonapi::NodeHandle* localHandle, int32_t num, int32_t seqno)
{
    super::ctor();
    this->numNodes = num;
    this->seqno = seqno;
    this->source = localHandle;
}

int32_t rice::tutorial::lookup::LookupService_NodeLookupQuery::getPriority()
{
    return 0;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::tutorial::lookup::LookupService_NodeLookupQuery::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.tutorial.lookup.LookupService.NodeLookupQuery", 50);
    return c;
}

java::lang::Class* rice::tutorial::lookup::LookupService_NodeLookupQuery::getClass0()
{
    return class_();
}

