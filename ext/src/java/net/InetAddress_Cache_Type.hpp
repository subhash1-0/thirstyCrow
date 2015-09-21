// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/net/fwd-pastry-2.1.hpp>
#include <java/lang/Enum.hpp>

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
typedef ::SubArray< ::java::lang::Enum, ObjectArray, ComparableArray, ::java::io::SerializableArray > EnumArray;
    } // lang

    namespace net
    {
typedef ::SubArray< ::java::net::InetAddress_Cache_Type, ::java::lang::EnumArray > InetAddress_Cache_TypeArray;
    } // net
} // java

struct default_init_tag;

class java::net::InetAddress_Cache_Type final
    : public ::java::lang::Enum
{

public:
    typedef ::java::lang::Enum super;

private:
    static InetAddress_Cache_TypeArray* $VALUES_;

public:
    static InetAddress_Cache_Type* Negative;
    static InetAddress_Cache_Type* Positive;

    /*void ctor(::java::lang::String* name, int ordinal); (private) */
    static InetAddress_Cache_Type* valueOf(::java::lang::String* arg0);
    static InetAddress_Cache_TypeArray* values();

    // Generated
    InetAddress_Cache_Type(::java::lang::String* name, int ordinal);
protected:
    InetAddress_Cache_Type(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    static ::java::lang::Enum* valueOf(::java::lang::Class* arg0, ::java::lang::String* arg1);

private:
    static InetAddress_Cache_TypeArray*& $VALUES();
    virtual ::java::lang::Class* getClass0();
};
