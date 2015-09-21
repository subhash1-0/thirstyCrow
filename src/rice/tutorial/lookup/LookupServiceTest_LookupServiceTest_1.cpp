// Generated from /pastry-2.1/src/rice/tutorial/lookup/LookupServiceTest.java
#include <rice/tutorial/lookup/LookupServiceTest_LookupServiceTest_1.hpp>

#include <java/io/PrintStream.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/System.hpp>
#include <rice/p2p/commonapi/NodeHandleSet.hpp>
#include <rice/pastry/Id.hpp>
#include <rice/tutorial/lookup/LookupService_NodeLookupTimeoutException.hpp>
#include <rice/tutorial/lookup/LookupServiceTest.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::tutorial::lookup::LookupServiceTest_LookupServiceTest_1::LookupServiceTest_LookupServiceTest_1(LookupServiceTest *LookupServiceTest_this, ::rice::pastry::Id* id)
    : super(*static_cast< ::default_init_tag* >(0))
    , LookupServiceTest_this(LookupServiceTest_this)
    , id(id)
{
    clinit();
    ctor();
}

void rice::tutorial::lookup::LookupServiceTest_LookupServiceTest_1::receiveException(::java::lang::Exception* exception)
{
    if(dynamic_cast< LookupService_NodeLookupTimeoutException* >(exception) != nullptr) {
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"Request for "_j)->append(static_cast< ::java::lang::Object* >(id))
            ->append(u" timed out"_j)->toString());
    } else {
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"Exception requesting "_j)->append(static_cast< ::java::lang::Object* >(id))
            ->append(u": "_j)
            ->append(npc(exception)->getMessage())->toString());
        npc(exception)->printStackTrace();
    }
}

void rice::tutorial::lookup::LookupServiceTest_LookupServiceTest_1::receiveResult(::rice::p2p::commonapi::NodeHandleSet* result)
{
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"ReplicaSet for "_j)->append(static_cast< ::java::lang::Object* >(id))
        ->append(u": "_j)
        ->append(static_cast< ::java::lang::Object* >(result))->toString());
}

void rice::tutorial::lookup::LookupServiceTest_LookupServiceTest_1::receiveResult(::java::lang::Object* result)
{ 
    receiveResult(dynamic_cast< ::rice::p2p::commonapi::NodeHandleSet* >(result));
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::tutorial::lookup::LookupServiceTest_LookupServiceTest_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::tutorial::lookup::LookupServiceTest_LookupServiceTest_1::getClass0()
{
    return class_();
}

