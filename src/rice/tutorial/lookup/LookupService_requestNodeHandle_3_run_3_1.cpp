// Generated from /pastry-2.1/src/rice/tutorial/lookup/LookupService.java
#include <rice/tutorial/lookup/LookupService_requestNodeHandle_3_run_3_1.hpp>

#include <java/lang/Exception.hpp>
#include <java/lang/IndexOutOfBoundsException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/Continuation.hpp>
#include <rice/p2p/commonapi/NodeHandle.hpp>
#include <rice/p2p/commonapi/NodeHandleSet.hpp>
#include <rice/tutorial/lookup/LookupService_requestNodeHandle_3.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::tutorial::lookup::LookupService_requestNodeHandle_3_run_3_1::LookupService_requestNodeHandle_3_run_3_1(LookupService_requestNodeHandle_3 *LookupService_requestNodeHandle_3_this, ::rice::Continuation* cont)
    : super(*static_cast< ::default_init_tag* >(0))
    , LookupService_requestNodeHandle_3_this(LookupService_requestNodeHandle_3_this)
    , cont(cont)
{
    clinit();
    ctor();
}

void rice::tutorial::lookup::LookupService_requestNodeHandle_3_run_3_1::receiveException(::java::lang::Exception* exception)
{
    npc(cont)->receiveException(exception);
}

void rice::tutorial::lookup::LookupService_requestNodeHandle_3_run_3_1::receiveResult(::rice::p2p::commonapi::NodeHandleSet* result)
{
    if(npc(result)->size() != 1) {
        receiveException(static_cast< ::java::lang::Exception* >(new ::java::lang::IndexOutOfBoundsException(::java::lang::StringBuilder().append(u"Expected 1 result, got "_j)->append(npc(result)->size())->toString())));
    } else {
        npc(cont)->receiveResult(npc(result)->getHandle(int32_t(0)));
    }
}

void rice::tutorial::lookup::LookupService_requestNodeHandle_3_run_3_1::receiveResult(::java::lang::Object* result)
{ 
    receiveResult(dynamic_cast< ::rice::p2p::commonapi::NodeHandleSet* >(result));
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::tutorial::lookup::LookupService_requestNodeHandle_3_run_3_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::tutorial::lookup::LookupService_requestNodeHandle_3_run_3_1::getClass0()
{
    return class_();
}

