// Generated from /pastry-2.1/src/rice/tutorial/past/PastTutorial.java
#include <rice/tutorial/past/PastTutorial_PastTutorial_1.hpp>

#include <java/io/PrintStream.hpp>
#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/Boolean.hpp>
#include <java/lang/Comparable.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/System.hpp>
#include <rice/p2p/past/PastContent.hpp>
#include <rice/tutorial/past/PastTutorial.hpp>
#include <SubArray.hpp>
#include <ObjectArray.hpp>

template<typename ComponentType, typename... Bases> struct SubArray;
namespace java
{
    namespace io
    {
typedef ::SubArray< ::java::io::Serializable, ::java::lang::ObjectArray > SerializableArray;
    } // io

    namespace lang
    {
typedef ::SubArray< ::java::lang::Comparable, ObjectArray > ComparableArray;
typedef ::SubArray< ::java::lang::Boolean, ObjectArray, ::java::io::SerializableArray, ComparableArray > BooleanArray;
    } // lang
} // java

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::tutorial::past::PastTutorial_PastTutorial_1::PastTutorial_PastTutorial_1(PastTutorial *PastTutorial_this, ::rice::p2p::past::PastContent* myContent)
    : super(*static_cast< ::default_init_tag* >(0))
    , PastTutorial_this(PastTutorial_this)
    , myContent(myContent)
{
    clinit();
    ctor();
}

void rice::tutorial::past::PastTutorial_PastTutorial_1::receiveResult(::java::lang::BooleanArray* results)
{
    auto numSuccessfulStores = int32_t(0);
    for (auto ctr = int32_t(0); ctr < npc(results)->length; ctr++) {
        if(npc((*results)[ctr])->booleanValue())
            numSuccessfulStores++;

    }
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(myContent))->append(u" successfully stored at "_j)
        ->append(numSuccessfulStores)
        ->append(u" locations."_j)->toString());
}

void rice::tutorial::past::PastTutorial_PastTutorial_1::receiveResult(::java::lang::Object* result)
{ 
    receiveResult(dynamic_cast< ::java::lang::BooleanArray* >(result));
}

void rice::tutorial::past::PastTutorial_PastTutorial_1::receiveException(::java::lang::Exception* result)
{
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"Error storing "_j)->append(static_cast< ::java::lang::Object* >(myContent))->toString());
    npc(result)->printStackTrace();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::tutorial::past::PastTutorial_PastTutorial_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::tutorial::past::PastTutorial_PastTutorial_1::getClass0()
{
    return class_();
}

