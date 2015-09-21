// Generated from /pastry-2.1/src/rice/environment/params/simple/SimpleParameters.java
#include <rice/environment/params/simple/SimpleParameters_MyProperties.hpp>

#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/CharSequence.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Comparable.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/String.hpp>
#include <java/util/Arrays.hpp>
#include <java/util/Set.hpp>
#include <rice/environment/params/simple/SimpleParameters_MyProperties_keys_1.hpp>
#include <rice/environment/params/simple/SimpleParameters.hpp>
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

template<typename T, typename U>
static T java_cast(U* u)
{
    if(!u) return static_cast<T>(nullptr);
    auto t = dynamic_cast<T>(u);
    if(!t) throw new ::java::lang::ClassCastException();
    return t;
}

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::environment::params::simple::SimpleParameters_MyProperties::SimpleParameters_MyProperties(SimpleParameters *SimpleParameters_this, const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
    , SimpleParameters_this(SimpleParameters_this)
{
    clinit();
}

rice::environment::params::simple::SimpleParameters_MyProperties::SimpleParameters_MyProperties(SimpleParameters *SimpleParameters_this)
    : SimpleParameters_MyProperties(SimpleParameters_this, *static_cast< ::default_init_tag* >(0))
{
    ctor();
}

java::util::Enumeration* rice::environment::params::simple::SimpleParameters_MyProperties::keys()
{
    auto const keys = java_cast< ::java::lang::StringArray* >(java_cast< ::java::lang::StringArray* >(npc(keySet())->toArray_(static_cast< ::java::lang::ObjectArray* >(new ::java::lang::StringArray(int32_t(0))))));
    ::java::util::Arrays::sort(static_cast< ::java::lang::ObjectArray* >(keys));
    return new SimpleParameters_MyProperties_keys_1(this, keys);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::environment::params::simple::SimpleParameters_MyProperties::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.environment.params.simple.SimpleParameters.MyProperties", 60);
    return c;
}

java::lang::Class* rice::environment::params::simple::SimpleParameters_MyProperties::getClass0()
{
    return class_();
}

