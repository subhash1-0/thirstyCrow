// Generated from /pastry-2.1/src/rice/environment/params/simple/SimpleParameters.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/environment/params/simple/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <java/util/Enumeration.hpp>

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

struct default_init_tag;

class rice::environment::params::simple::SimpleParameters_MyProperties_keys_1
    : public virtual ::java::lang::Object
    , public virtual ::java::util::Enumeration
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    int32_t pos {  };

public:
    bool hasMoreElements() override;
    ::java::lang::Object* nextElement() override;

    // Generated
    SimpleParameters_MyProperties_keys_1(SimpleParameters_MyProperties *SimpleParameters_MyProperties_this, ::java::lang::StringArray* keys);
    static ::java::lang::Class *class_();

private:
    void init();
    SimpleParameters_MyProperties *SimpleParameters_MyProperties_this;
    ::java::lang::StringArray* keys;
    virtual ::java::lang::Class* getClass0();
    friend class SimpleParameters;
    friend class SimpleParameters_MyProperties;
};
