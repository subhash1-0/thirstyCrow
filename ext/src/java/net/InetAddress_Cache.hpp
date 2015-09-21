// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/net/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

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

struct default_init_tag;

class java::net::InetAddress_Cache final
    : public ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;

private:
    ::java::util::LinkedHashMap* cache {  };
    InetAddress_Cache_Type* type {  };

protected:
    void ctor(InetAddress_Cache_Type* arg0);

public:
    InetAddress_CacheEntry* get(::java::lang::String* arg0);
    /*int32_t getPolicy(); (private) */
    InetAddress_Cache* put(::java::lang::String* arg0, InetAddressArray* arg1);

    // Generated
    InetAddress_Cache(InetAddress_Cache_Type* arg0);
protected:
    InetAddress_Cache(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
