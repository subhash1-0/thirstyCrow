// Generated from /pastry-2.1/src/rice/tutorial/past/PastTutorial.java
#include <rice/tutorial/past/PastTutorial_PastTutorial_2.hpp>

#include <java/io/PrintStream.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/System.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/past/PastContent.hpp>
#include <rice/tutorial/past/PastTutorial.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::tutorial::past::PastTutorial_PastTutorial_2::PastTutorial_PastTutorial_2(PastTutorial *PastTutorial_this, ::rice::p2p::commonapi::Id* lookupKey)
    : super(*static_cast< ::default_init_tag* >(0))
    , PastTutorial_this(PastTutorial_this)
    , lookupKey(lookupKey)
{
    clinit();
    ctor();
}

void rice::tutorial::past::PastTutorial_PastTutorial_2::receiveResult(::rice::p2p::past::PastContent* result)
{
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"Successfully looked up "_j)->append(static_cast< ::java::lang::Object* >(result))
        ->append(u" for key "_j)
        ->append(static_cast< ::java::lang::Object* >(lookupKey))
        ->append(u"."_j)->toString());
}

void rice::tutorial::past::PastTutorial_PastTutorial_2::receiveResult(::java::lang::Object* result)
{ 
    receiveResult(dynamic_cast< ::rice::p2p::past::PastContent* >(result));
}

void rice::tutorial::past::PastTutorial_PastTutorial_2::receiveException(::java::lang::Exception* result)
{
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"Error looking up "_j)->append(static_cast< ::java::lang::Object* >(lookupKey))->toString());
    npc(result)->printStackTrace();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::tutorial::past::PastTutorial_PastTutorial_2::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::tutorial::past::PastTutorial_PastTutorial_2::getClass0()
{
    return class_();
}

