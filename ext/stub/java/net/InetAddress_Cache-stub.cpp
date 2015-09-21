// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/net/InetAddress_Cache.hpp>

template<typename ComponentType, typename... Bases> struct SubArray;
namespace java
{
    namespace io
    {
typedef ::SubArray< ::java::io::Serializable, ::java::lang::ObjectArray > SerializableArray;
    } // io

    namespace net
    {
typedef ::SubArray< ::java::net::InetAddress, ::java::lang::ObjectArray, ::java::io::SerializableArray > InetAddressArray;
    } // net
} // java

extern void unimplemented_(const char16_t* name);
java::net::InetAddress_Cache::InetAddress_Cache(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::net::InetAddress_Cache::InetAddress_Cache(InetAddress_Cache_Type* arg0)
    : InetAddress_Cache(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0);
}


void ::java::net::InetAddress_Cache::ctor(InetAddress_Cache_Type* arg0)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::net::InetAddress_Cache::ctor(InetAddress_Cache_Type* arg0)");
}

java::net::InetAddress_CacheEntry* java::net::InetAddress_Cache::get(::java::lang::String* arg0)
{ /* stub */
    unimplemented_(u"java::net::InetAddress_CacheEntry* java::net::InetAddress_Cache::get(::java::lang::String* arg0)");
    return 0;
}

/* private: int32_t java::net::InetAddress_Cache::getPolicy() */
java::net::InetAddress_Cache* java::net::InetAddress_Cache::put(::java::lang::String* arg0, InetAddressArray* arg1)
{ /* stub */
    unimplemented_(u"java::net::InetAddress_Cache* java::net::InetAddress_Cache::put(::java::lang::String* arg0, InetAddressArray* arg1)");
    return 0;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::net::InetAddress_Cache::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.net.InetAddress.Cache", 26);
    return c;
}

java::lang::Class* java::net::InetAddress_Cache::getClass0()
{
    return class_();
}

