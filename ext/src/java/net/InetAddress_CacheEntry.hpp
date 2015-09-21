// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/net/fwd-pastry-2.1.hpp>
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

class java::net::InetAddress_CacheEntry final
    : public ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    InetAddressArray* addresses {  };
    int64_t expiration {  };

protected:
    void ctor(InetAddressArray* arg0, int64_t arg1);

    // Generated

public: /* package */
    InetAddress_CacheEntry(InetAddressArray* arg0, int64_t arg1);
protected:
    InetAddress_CacheEntry(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
