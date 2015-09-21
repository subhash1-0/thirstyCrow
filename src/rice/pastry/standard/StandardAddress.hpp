// Generated from /pastry-2.1/src/rice/pastry/standard/StandardAddress.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/pastry/standard/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

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

class rice::pastry::standard::StandardAddress
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;

private:
    static constexpr int64_t serialVersionUID { int64_t(1564239935633411277LL) };

public:
    static int32_t getAddress(::java::lang::Class* c, ::java::lang::String* instance, ::rice::environment::Environment* env);
    static int16_t getAddress(::java::lang::Class* c, ::rice::environment::Environment* env);

private:
    static int32_t shift(int32_t n, int32_t s);
    static int32_t unshift(int32_t n, int32_t s);

public:
    static void main(::java::lang::StringArray* args);

    // Generated
    StandardAddress();
protected:
    StandardAddress(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
