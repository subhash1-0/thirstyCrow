// Generated from /pastry-2.1/src/rice/tutorial/lookup/LookupService.java
#include <rice/tutorial/lookup/LookupService_sendMessageWithRetries_2.hpp>

#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <rice/Continuation.hpp>
#include <rice/p2p/commonapi/NodeHandleSet.hpp>
#include <rice/tutorial/lookup/LookupService_NodeLookupTimeoutException.hpp>
#include <rice/tutorial/lookup/LookupService.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::tutorial::lookup::LookupService_sendMessageWithRetries_2::LookupService_sendMessageWithRetries_2(LookupService *LookupService_this, int32_t seq, ::rice::p2p::commonapi::Id* id, int32_t num, ::rice::Continuation* cont)
    : super(*static_cast< ::default_init_tag* >(0))
    , LookupService_this(LookupService_this)
    , seq(seq)
    , id(id)
    , num(num)
    , cont(cont)
{
    clinit();
    init();
    ctor();
}

void rice::tutorial::lookup::LookupService_sendMessageWithRetries_2::init()
{
    t = LookupService_this->firstTimeout;
    cum = int32_t(0);
}

void rice::tutorial::lookup::LookupService_sendMessageWithRetries_2::receiveException(::java::lang::Exception* exception)
{
    if(dynamic_cast< LookupService_NodeLookupTimeoutException* >(exception) != nullptr) {
        cum += t;
        if(cum < LookupService_this->timeout) {
            t *= 2;
            if(cum + t < LookupService_this->timeout) {
                LookupService_this->sendMessage(seq, id, num, this, t);
            } else {
                LookupService_this->sendMessage(seq, id, num, this, LookupService_this->timeout - cum);
            }
        } else {
            npc(cont)->receiveException(exception);
        }
    } else {
        npc(cont)->receiveException(exception);
    }
}

void rice::tutorial::lookup::LookupService_sendMessageWithRetries_2::receiveResult(::rice::p2p::commonapi::NodeHandleSet* result)
{
    npc(cont)->receiveResult(result);
}

void rice::tutorial::lookup::LookupService_sendMessageWithRetries_2::receiveResult(::java::lang::Object* result)
{ 
    receiveResult(dynamic_cast< ::rice::p2p::commonapi::NodeHandleSet* >(result));
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::tutorial::lookup::LookupService_sendMessageWithRetries_2::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::tutorial::lookup::LookupService_sendMessageWithRetries_2::getClass0()
{
    return class_();
}

