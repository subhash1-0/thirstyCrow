// Generated from /pastry-2.1/src/rice/environment/params/simple/SimpleParameters.java
#include <rice/environment/params/simple/SimpleParameters_MyProperties_keys_1.hpp>

#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/CharSequence.hpp>
#include <java/lang/Comparable.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/String.hpp>
#include <rice/environment/params/simple/SimpleParameters_MyProperties.hpp>
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

rice::environment::params::simple::SimpleParameters_MyProperties_keys_1::SimpleParameters_MyProperties_keys_1(SimpleParameters_MyProperties *SimpleParameters_MyProperties_this, ::java::lang::StringArray* keys)
    : super(*static_cast< ::default_init_tag* >(0))
    , SimpleParameters_MyProperties_this(SimpleParameters_MyProperties_this)
    , keys(keys)
{
    clinit();
    init();
    ctor();
}

void rice::environment::params::simple::SimpleParameters_MyProperties_keys_1::init()
{
    pos = int32_t(0);
}

bool rice::environment::params::simple::SimpleParameters_MyProperties_keys_1::hasMoreElements()
{
    return (pos < npc(keys)->length);
}

java::lang::Object* rice::environment::params::simple::SimpleParameters_MyProperties_keys_1::nextElement()
{
    return (*keys)[pos++];
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::environment::params::simple::SimpleParameters_MyProperties_keys_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::environment::params::simple::SimpleParameters_MyProperties_keys_1::getClass0()
{
    return class_();
}

