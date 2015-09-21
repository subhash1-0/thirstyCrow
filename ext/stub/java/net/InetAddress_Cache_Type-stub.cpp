// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/net/InetAddress_Cache_Type.hpp>

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

extern void unimplemented_(const char16_t* name);
java::net::InetAddress_Cache_Type::InetAddress_Cache_Type(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::net::InetAddress_Cache_TypeArray*& java::net::InetAddress_Cache_Type::$VALUES()
{
    clinit();
    return $VALUES_;
}
java::net::InetAddress_Cache_TypeArray* java::net::InetAddress_Cache_Type::$VALUES_;
java::net::InetAddress_Cache_Type* java::net::InetAddress_Cache_Type::Negative;
java::net::InetAddress_Cache_Type* java::net::InetAddress_Cache_Type::Positive;

/* private: void ::java::net::InetAddress_Cache_Type::ctor(::java::lang::String* name, int ordinal) */
java::net::InetAddress_Cache_Type* java::net::InetAddress_Cache_Type::valueOf(::java::lang::String* arg0)
{ /* stub */
    clinit();
    unimplemented_(u"java::net::InetAddress_Cache_Type* java::net::InetAddress_Cache_Type::valueOf(::java::lang::String* arg0)");
    return 0;
}

java::net::InetAddress_Cache_TypeArray* java::net::InetAddress_Cache_Type::values()
{ /* stub */
    clinit();
    unimplemented_(u"java::net::InetAddress_Cache_TypeArray* java::net::InetAddress_Cache_Type::values()");
    return 0;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::net::InetAddress_Cache_Type::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.net.InetAddress.Cache.Type", 31);
    return c;
}

java::lang::Enum* java::net::InetAddress_Cache_Type::valueOf(::java::lang::Class* arg0, ::java::lang::String* arg1)
{
    return super::valueOf(arg0, arg1);
}

java::lang::Class* java::net::InetAddress_Cache_Type::getClass0()
{
    return class_();
}

