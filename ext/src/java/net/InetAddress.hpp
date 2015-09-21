// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/net/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <sun/misc/fwd-pastry-2.1.hpp>
#include <sun/net/spi/nameservice/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <java/io/Serializable.hpp>

template<typename ComponentType, typename... Bases> struct SubArray;
namespace java
{
    namespace lang
    {
typedef ::SubArray< ::java::lang::Comparable, ObjectArray > ComparableArray;
    } // lang

    namespace io
    {
typedef ::SubArray< ::java::io::ObjectStreamField, ::java::lang::ObjectArray, ::java::lang::ComparableArray > ObjectStreamFieldArray;
typedef ::SubArray< ::java::io::Serializable, ::java::lang::ObjectArray > SerializableArray;
    } // io

    namespace net
    {
typedef ::SubArray< ::java::net::InetAddress, ::java::lang::ObjectArray, ::java::io::SerializableArray > InetAddressArray;
    } // net
} // java

struct default_init_tag;

class java::net::InetAddress
    : public virtual ::java::lang::Object
    , public virtual ::java::io::Serializable
{

public:
    typedef ::java::lang::Object super;

private:
    static bool $assertionsDisabled_;
    static int64_t FIELDS_OFFSET_;

public: /* package */
    static constexpr int32_t IPv4 { int32_t(1) };
    static constexpr int32_t IPv6 { int32_t(2) };

private:
    static ::sun::misc::Unsafe* UNSAFE_;
    static InetAddress_Cache* addressCache_;
    static bool addressCacheInit_;
    static ::java::lang::Object* cacheLock_;
    static int64_t cacheTime_;
    static InetAddress* cachedLocalHost_;
    ::java::lang::String* canonicalHostName {  };

public: /* package */
    InetAddress_InetAddressHolder* holder_ {  };

private:
    static InetAddressImpl* impl_;
    static ::java::util::HashMap* lookupTable_;
    static constexpr int64_t maxCacheTime { int64_t(5000LL) };
    static ::java::util::List* nameServices_;
    static InetAddress_Cache* negativeCache_;
    static bool preferIPv6Address_;
    static ::java::io::ObjectStreamFieldArray* serialPersistentFields_;
    static constexpr int64_t serialVersionUID { int64_t(3286316764910316507LL) };
    static InetAddressArray* unknown_array_;

protected:
    void ctor();

public: /* package */
    static InetAddress* anyLocalAddress();
    /*static void cacheAddresses(::java::lang::String* arg0, InetAddressArray* arg1, bool arg2); (private) */
    /*static void cacheInitIfNeeded(); (private) */
    /*static InetAddressArray* checkLookupTable(::java::lang::String* arg0); (private) */
    /*static int32_t checkNumericZone(::java::lang::String* arg0); (private) */
    /*static ::sun::net::spi::nameservice::NameService* createNSProvider(::java::lang::String* arg0); (private) */

public:
    bool equals(::java::lang::Object* arg0) override;
    virtual ::int8_tArray* getAddress();
    /*static InetAddressArray* getAddressesFromNameService(::java::lang::String* arg0, InetAddress* arg1); (private) */
    static InetAddressArray* getAllByName(::java::lang::String* arg0);
    /*static InetAddressArray* getAllByName(::java::lang::String* arg0, InetAddress* arg1); (private) */
    /*static InetAddressArray* getAllByName0(::java::lang::String* arg0); (private) */

public: /* package */
    static InetAddressArray* getAllByName0(::java::lang::String* arg0, bool arg1);
    /*static InetAddressArray* getAllByName0(::java::lang::String* arg0, InetAddress* arg1, bool arg2); (private) */

public:
    static InetAddress* getByAddress(::int8_tArray* arg0);
    static InetAddress* getByAddress(::java::lang::String* arg0, ::int8_tArray* arg1);
    static InetAddress* getByName(::java::lang::String* arg0);
    /*static InetAddress* getByName(::java::lang::String* arg0, InetAddress* arg1); (private) */
    /*static InetAddressArray* getCachedAddresses(::java::lang::String* arg0); (private) */
    virtual ::java::lang::String* getCanonicalHostName();
    virtual ::java::lang::String* getHostAddress();
    /*static ::java::lang::String* getHostFromNameService(InetAddress* arg0, bool arg1); (private) */
    virtual ::java::lang::String* getHostName();

public: /* package */
    virtual ::java::lang::String* getHostName(bool arg0);

public:
    static InetAddress* getLocalHost();
    static InetAddress* getLoopbackAddress();
    int32_t hashCode() override;

public: /* package */
    virtual InetAddress_InetAddressHolder* holder();
    /*static void init_(); (private) */

public:
    virtual bool isAnyLocalAddress();
    virtual bool isLinkLocalAddress();
    virtual bool isLoopbackAddress();
    virtual bool isMCGlobal();
    virtual bool isMCLinkLocal();
    virtual bool isMCNodeLocal();
    virtual bool isMCOrgLocal();
    virtual bool isMCSiteLocal();
    virtual bool isMulticastAddress();
    virtual bool isReachable(int32_t arg0);
    virtual bool isReachable(NetworkInterface* arg0, int32_t arg1, int32_t arg2);
    virtual bool isSiteLocalAddress();

public: /* package */
    static InetAddressImpl* loadImpl(::java::lang::String* arg0);
    /*void readObject(::java::io::ObjectInputStream* arg0); (private) */
    /*void readObjectNoData(::java::io::ObjectInputStream* arg0); (private) */
    /*::java::lang::Object* readResolve(); (private) */

public:
    ::java::lang::String* toString() override;
    /*static void updateLookupTable(::java::lang::String* arg0); (private) */
    /*void writeObject(::java::io::ObjectOutputStream* arg0); (private) */

    // Generated

public: /* package */
    InetAddress();
protected:
    InetAddress(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

public: /* package */
    static bool& $assertionsDisabled();

private:
    static int64_t& FIELDS_OFFSET();
    static ::sun::misc::Unsafe*& UNSAFE();
    static InetAddress_Cache*& addressCache();
    static bool& addressCacheInit();
    static ::java::lang::Object*& cacheLock();
    static int64_t& cacheTime();
    static InetAddress*& cachedLocalHost();

public: /* package */
    static InetAddressImpl*& impl();

private:
    static ::java::util::HashMap*& lookupTable();
    static ::java::util::List*& nameServices();
    static InetAddress_Cache*& negativeCache();

public: /* package */
    static bool& preferIPv6Address();

private:
    static ::java::io::ObjectStreamFieldArray*& serialPersistentFields();

public: /* package */
    static InetAddressArray*& unknown_array();

private:
    virtual ::java::lang::Class* getClass0();
};
