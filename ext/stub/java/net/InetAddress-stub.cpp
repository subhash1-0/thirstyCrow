// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/net/InetAddress.hpp>

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
java::net::InetAddress::InetAddress(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::net::InetAddress::InetAddress()
    : InetAddress(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

bool& java::net::InetAddress::$assertionsDisabled()
{
    clinit();
    return $assertionsDisabled_;
}
bool java::net::InetAddress::$assertionsDisabled_;
int64_t& java::net::InetAddress::FIELDS_OFFSET()
{
    clinit();
    return FIELDS_OFFSET_;
}
int64_t java::net::InetAddress::FIELDS_OFFSET_;
constexpr int32_t java::net::InetAddress::IPv4;
constexpr int32_t java::net::InetAddress::IPv6;
sun::misc::Unsafe*& java::net::InetAddress::UNSAFE()
{
    clinit();
    return UNSAFE_;
}
sun::misc::Unsafe* java::net::InetAddress::UNSAFE_;
java::net::InetAddress_Cache*& java::net::InetAddress::addressCache()
{
    clinit();
    return addressCache_;
}
java::net::InetAddress_Cache* java::net::InetAddress::addressCache_;
bool& java::net::InetAddress::addressCacheInit()
{
    clinit();
    return addressCacheInit_;
}
bool java::net::InetAddress::addressCacheInit_;
java::lang::Object*& java::net::InetAddress::cacheLock()
{
    clinit();
    return cacheLock_;
}
java::lang::Object* java::net::InetAddress::cacheLock_;
int64_t& java::net::InetAddress::cacheTime()
{
    clinit();
    return cacheTime_;
}
int64_t java::net::InetAddress::cacheTime_;
java::net::InetAddress*& java::net::InetAddress::cachedLocalHost()
{
    clinit();
    return cachedLocalHost_;
}
java::net::InetAddress* java::net::InetAddress::cachedLocalHost_;
java::net::InetAddressImpl*& java::net::InetAddress::impl()
{
    clinit();
    return impl_;
}
java::net::InetAddressImpl* java::net::InetAddress::impl_;
java::util::HashMap*& java::net::InetAddress::lookupTable()
{
    clinit();
    return lookupTable_;
}
java::util::HashMap* java::net::InetAddress::lookupTable_;
constexpr int64_t java::net::InetAddress::maxCacheTime;
java::util::List*& java::net::InetAddress::nameServices()
{
    clinit();
    return nameServices_;
}
java::util::List* java::net::InetAddress::nameServices_;
java::net::InetAddress_Cache*& java::net::InetAddress::negativeCache()
{
    clinit();
    return negativeCache_;
}
java::net::InetAddress_Cache* java::net::InetAddress::negativeCache_;
bool& java::net::InetAddress::preferIPv6Address()
{
    clinit();
    return preferIPv6Address_;
}
bool java::net::InetAddress::preferIPv6Address_;
java::io::ObjectStreamFieldArray*& java::net::InetAddress::serialPersistentFields()
{
    clinit();
    return serialPersistentFields_;
}
java::io::ObjectStreamFieldArray* java::net::InetAddress::serialPersistentFields_;
constexpr int64_t java::net::InetAddress::serialVersionUID;
java::net::InetAddressArray*& java::net::InetAddress::unknown_array()
{
    clinit();
    return unknown_array_;
}
java::net::InetAddressArray* java::net::InetAddress::unknown_array_;

void ::java::net::InetAddress::ctor()
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::net::InetAddress::ctor()");
}

java::net::InetAddress* java::net::InetAddress::anyLocalAddress()
{ /* stub */
    clinit();
    unimplemented_(u"java::net::InetAddress* java::net::InetAddress::anyLocalAddress()");
    return 0;
}

/* private: void java::net::InetAddress::cacheAddresses(::java::lang::String* arg0, InetAddressArray* arg1, bool arg2) */
/* private: void java::net::InetAddress::cacheInitIfNeeded() */
/* private: java::net::InetAddressArray* java::net::InetAddress::checkLookupTable(::java::lang::String* arg0) */
/* private: int32_t java::net::InetAddress::checkNumericZone(::java::lang::String* arg0) */
/* private: sun::net::spi::nameservice::NameService* java::net::InetAddress::createNSProvider(::java::lang::String* arg0) */
bool java::net::InetAddress::equals(::java::lang::Object* arg0)
{ /* stub */
    unimplemented_(u"bool java::net::InetAddress::equals(::java::lang::Object* arg0)");
    return 0;
}

int8_tArray* java::net::InetAddress::getAddress()
{ /* stub */
    unimplemented_(u"int8_tArray* java::net::InetAddress::getAddress()");
    return 0;
}

/* private: java::net::InetAddressArray* java::net::InetAddress::getAddressesFromNameService(::java::lang::String* arg0, InetAddress* arg1) */
java::net::InetAddressArray* java::net::InetAddress::getAllByName(::java::lang::String* arg0)
{ /* stub */
    clinit();
    unimplemented_(u"java::net::InetAddressArray* java::net::InetAddress::getAllByName(::java::lang::String* arg0)");
    return 0;
}

/* private: java::net::InetAddressArray* java::net::InetAddress::getAllByName(::java::lang::String* arg0, InetAddress* arg1) */
/* private: java::net::InetAddressArray* java::net::InetAddress::getAllByName0(::java::lang::String* arg0) */
java::net::InetAddressArray* java::net::InetAddress::getAllByName0(::java::lang::String* arg0, bool arg1)
{ /* stub */
    clinit();
    unimplemented_(u"java::net::InetAddressArray* java::net::InetAddress::getAllByName0(::java::lang::String* arg0, bool arg1)");
    return 0;
}

/* private: java::net::InetAddressArray* java::net::InetAddress::getAllByName0(::java::lang::String* arg0, InetAddress* arg1, bool arg2) */
java::net::InetAddress* java::net::InetAddress::getByAddress(::int8_tArray* arg0)
{ /* stub */
    clinit();
    unimplemented_(u"java::net::InetAddress* java::net::InetAddress::getByAddress(::int8_tArray* arg0)");
    return 0;
}

java::net::InetAddress* java::net::InetAddress::getByAddress(::java::lang::String* arg0, ::int8_tArray* arg1)
{ /* stub */
    clinit();
    unimplemented_(u"java::net::InetAddress* java::net::InetAddress::getByAddress(::java::lang::String* arg0, ::int8_tArray* arg1)");
    return 0;
}

java::net::InetAddress* java::net::InetAddress::getByName(::java::lang::String* arg0)
{ /* stub */
    clinit();
    unimplemented_(u"java::net::InetAddress* java::net::InetAddress::getByName(::java::lang::String* arg0)");
    return 0;
}

/* private: java::net::InetAddress* java::net::InetAddress::getByName(::java::lang::String* arg0, InetAddress* arg1) */
/* private: java::net::InetAddressArray* java::net::InetAddress::getCachedAddresses(::java::lang::String* arg0) */
java::lang::String* java::net::InetAddress::getCanonicalHostName()
{ /* stub */
return canonicalHostName ; /* getter */
}

java::lang::String* java::net::InetAddress::getHostAddress()
{ /* stub */
    unimplemented_(u"java::lang::String* java::net::InetAddress::getHostAddress()");
    return 0;
}

/* private: java::lang::String* java::net::InetAddress::getHostFromNameService(InetAddress* arg0, bool arg1) */
java::lang::String* java::net::InetAddress::getHostName()
{ /* stub */
    unimplemented_(u"java::lang::String* java::net::InetAddress::getHostName()");
    return 0;
}

java::lang::String* java::net::InetAddress::getHostName(bool arg0)
{ /* stub */
    unimplemented_(u"java::lang::String* java::net::InetAddress::getHostName(bool arg0)");
    return 0;
}

java::net::InetAddress* java::net::InetAddress::getLocalHost()
{ /* stub */
    clinit();
    unimplemented_(u"java::net::InetAddress* java::net::InetAddress::getLocalHost()");
    return 0;
}

java::net::InetAddress* java::net::InetAddress::getLoopbackAddress()
{ /* stub */
    clinit();
    unimplemented_(u"java::net::InetAddress* java::net::InetAddress::getLoopbackAddress()");
    return 0;
}

int32_t java::net::InetAddress::hashCode()
{ /* stub */
    unimplemented_(u"int32_t java::net::InetAddress::hashCode()");
    return 0;
}

java::net::InetAddress_InetAddressHolder* java::net::InetAddress::holder()
{ /* stub */
    unimplemented_(u"java::net::InetAddress_InetAddressHolder* java::net::InetAddress::holder()");
    return 0;
}

bool java::net::InetAddress::isAnyLocalAddress()
{ /* stub */
    unimplemented_(u"bool java::net::InetAddress::isAnyLocalAddress()");
    return 0;
}

bool java::net::InetAddress::isLinkLocalAddress()
{ /* stub */
    unimplemented_(u"bool java::net::InetAddress::isLinkLocalAddress()");
    return 0;
}

bool java::net::InetAddress::isLoopbackAddress()
{ /* stub */
    unimplemented_(u"bool java::net::InetAddress::isLoopbackAddress()");
    return 0;
}

bool java::net::InetAddress::isMCGlobal()
{ /* stub */
    unimplemented_(u"bool java::net::InetAddress::isMCGlobal()");
    return 0;
}

bool java::net::InetAddress::isMCLinkLocal()
{ /* stub */
    unimplemented_(u"bool java::net::InetAddress::isMCLinkLocal()");
    return 0;
}

bool java::net::InetAddress::isMCNodeLocal()
{ /* stub */
    unimplemented_(u"bool java::net::InetAddress::isMCNodeLocal()");
    return 0;
}

bool java::net::InetAddress::isMCOrgLocal()
{ /* stub */
    unimplemented_(u"bool java::net::InetAddress::isMCOrgLocal()");
    return 0;
}

bool java::net::InetAddress::isMCSiteLocal()
{ /* stub */
    unimplemented_(u"bool java::net::InetAddress::isMCSiteLocal()");
    return 0;
}

bool java::net::InetAddress::isMulticastAddress()
{ /* stub */
    unimplemented_(u"bool java::net::InetAddress::isMulticastAddress()");
    return 0;
}

bool java::net::InetAddress::isReachable(int32_t arg0)
{ /* stub */
    unimplemented_(u"bool java::net::InetAddress::isReachable(int32_t arg0)");
    return 0;
}

bool java::net::InetAddress::isReachable(NetworkInterface* arg0, int32_t arg1, int32_t arg2)
{ /* stub */
    unimplemented_(u"bool java::net::InetAddress::isReachable(NetworkInterface* arg0, int32_t arg1, int32_t arg2)");
    return 0;
}

bool java::net::InetAddress::isSiteLocalAddress()
{ /* stub */
    unimplemented_(u"bool java::net::InetAddress::isSiteLocalAddress()");
    return 0;
}

java::net::InetAddressImpl* java::net::InetAddress::loadImpl(::java::lang::String* arg0)
{ /* stub */
    clinit();
    unimplemented_(u"java::net::InetAddressImpl* java::net::InetAddress::loadImpl(::java::lang::String* arg0)");
    return 0;
}

/* private: void java::net::InetAddress::readObject(::java::io::ObjectInputStream* arg0) */
/* private: void java::net::InetAddress::readObjectNoData(::java::io::ObjectInputStream* arg0) */
/* private: java::lang::Object* java::net::InetAddress::readResolve() */
java::lang::String* java::net::InetAddress::toString()
{ /* stub */
    unimplemented_(u"java::lang::String* java::net::InetAddress::toString()");
    return 0;
}

/* private: void java::net::InetAddress::updateLookupTable(::java::lang::String* arg0) */
/* private: void java::net::InetAddress::writeObject(::java::io::ObjectOutputStream* arg0) */
extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::net::InetAddress::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.net.InetAddress", 20);
    return c;
}

java::lang::Class* java::net::InetAddress::getClass0()
{
    return class_();
}

