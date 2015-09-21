// Generated from /pastry-2.1/src/rice/tutorial/lookup/LookupService.java
#include <rice/tutorial/lookup/LookupService_NodeLookupResponse.hpp>

#include <rice/p2p/commonapi/NodeHandleSet.hpp>

rice::tutorial::lookup::LookupService_NodeLookupResponse::LookupService_NodeLookupResponse(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::tutorial::lookup::LookupService_NodeLookupResponse::LookupService_NodeLookupResponse(::rice::p2p::commonapi::NodeHandleSet* nodes, int32_t seqno) 
    : LookupService_NodeLookupResponse(*static_cast< ::default_init_tag* >(0))
{
    ctor(nodes,seqno);
}

constexpr int64_t rice::tutorial::lookup::LookupService_NodeLookupResponse::serialVersionUID;

void rice::tutorial::lookup::LookupService_NodeLookupResponse::ctor(::rice::p2p::commonapi::NodeHandleSet* nodes, int32_t seqno)
{
    super::ctor();
    this->nodes = nodes;
    this->seqno = seqno;
}

int32_t rice::tutorial::lookup::LookupService_NodeLookupResponse::getPriority()
{
    return 0;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::tutorial::lookup::LookupService_NodeLookupResponse::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.tutorial.lookup.LookupService.NodeLookupResponse", 53);
    return c;
}

java::lang::Class* rice::tutorial::lookup::LookupService_NodeLookupResponse::getClass0()
{
    return class_();
}

