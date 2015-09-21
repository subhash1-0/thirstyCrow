// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/net/InetAddress_CacheEntry.hpp>

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
java::net::InetAddress_CacheEntry::InetAddress_CacheEntry(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::net::InetAddress_CacheEntry::InetAddress_CacheEntry(InetAddressArray* arg0, int64_t arg1)
    : InetAddress_CacheEntry(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0, arg1);
}


void ::java::net::InetAddress_CacheEntry::ctor(InetAddressArray* arg0, int64_t arg1)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::net::InetAddress_CacheEntry::ctor(InetAddressArray* arg0, int64_t arg1)");
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::net::InetAddress_CacheEntry::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.net.InetAddress.CacheEntry", 31);
    return c;
}

java::lang::Class* java::net::InetAddress_CacheEntry::getClass0()
{
    return class_();
}

