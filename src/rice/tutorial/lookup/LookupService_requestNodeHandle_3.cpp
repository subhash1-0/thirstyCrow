// Generated from /pastry-2.1/src/rice/tutorial/lookup/LookupService.java
#include <rice/tutorial/lookup/LookupService_requestNodeHandle_3.hpp>

#include <rice/tutorial/lookup/LookupService_requestNodeHandle_3_run_3_1.hpp>
#include <rice/tutorial/lookup/LookupService.hpp>

rice::tutorial::lookup::LookupService_requestNodeHandle_3::LookupService_requestNodeHandle_3(LookupService *LookupService_this, ::rice::p2p::commonapi::Id* id, ::rice::Continuation* cont)
    : super(*static_cast< ::default_init_tag* >(0))
    , LookupService_this(LookupService_this)
    , id(id)
    , cont(cont)
{
    clinit();
    ctor();
}

void rice::tutorial::lookup::LookupService_requestNodeHandle_3::run()
{
    LookupService_this->sendMessageWithRetries(id, 1, new LookupService_requestNodeHandle_3_run_3_1(this, cont));
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::tutorial::lookup::LookupService_requestNodeHandle_3::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::tutorial::lookup::LookupService_requestNodeHandle_3::getClass0()
{
    return class_();
}

