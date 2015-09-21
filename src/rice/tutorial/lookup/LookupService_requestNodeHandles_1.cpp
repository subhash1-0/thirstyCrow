// Generated from /pastry-2.1/src/rice/tutorial/lookup/LookupService.java
#include <rice/tutorial/lookup/LookupService_requestNodeHandles_1.hpp>

#include <rice/tutorial/lookup/LookupService.hpp>

rice::tutorial::lookup::LookupService_requestNodeHandles_1::LookupService_requestNodeHandles_1(LookupService *LookupService_this, ::rice::p2p::commonapi::Id* id, int32_t num, ::rice::Continuation* cont)
    : super(*static_cast< ::default_init_tag* >(0))
    , LookupService_this(LookupService_this)
    , id(id)
    , num(num)
    , cont(cont)
{
    clinit();
    ctor();
}

void rice::tutorial::lookup::LookupService_requestNodeHandles_1::run()
{
    LookupService_this->sendMessageWithRetries(id, num, cont);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::tutorial::lookup::LookupService_requestNodeHandles_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::tutorial::lookup::LookupService_requestNodeHandles_1::getClass0()
{
    return class_();
}

