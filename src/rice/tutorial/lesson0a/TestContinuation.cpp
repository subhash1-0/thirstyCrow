// Generated from /pastry-2.1/src/rice/tutorial/lesson0a/TestContinuation.java
#include <rice/tutorial/lesson0a/TestContinuation.hpp>

#include <java/lang/NullPointerException.hpp>
#include <rice/p2p/past/Past.hpp>
#include <rice/tutorial/lesson0a/MyContinuation.hpp>

template<typename ComponentType, typename... Bases> struct SubArray;
namespace java
{
    namespace io
    {
typedef ::SubArray< ::java::io::Serializable, ::java::lang::ObjectArray > SerializableArray;
    } // io

    namespace lang
    {
typedef ::SubArray< ::java::lang::CharSequence, ObjectArray > CharSequenceArray;
typedef ::SubArray< ::java::lang::Comparable, ObjectArray > ComparableArray;
typedef ::SubArray< ::java::lang::String, ObjectArray, ::java::io::SerializableArray, ComparableArray, CharSequenceArray > StringArray;
    } // lang
} // java

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::tutorial::lesson0a::TestContinuation::TestContinuation(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::tutorial::lesson0a::TestContinuation::TestContinuation()
    : TestContinuation(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

void rice::tutorial::lesson0a::TestContinuation::main(::java::lang::StringArray* args)
{
    clinit();
    ::rice::p2p::past::Past* past = nullptr;
    ::rice::p2p::commonapi::Id* id = nullptr;
    ::rice::Continuation* command = new MyContinuation();
    npc(past)->lookup(id, command);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::tutorial::lesson0a::TestContinuation::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.tutorial.lesson0a.TestContinuation", 39);
    return c;
}

java::lang::Class* rice::tutorial::lesson0a::TestContinuation::getClass0()
{
    return class_();
}

