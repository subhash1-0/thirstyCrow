// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/net/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct default_init_tag;

class java::net::InetSocketAddress_InetSocketAddressHolder
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;

private:
    InetAddress* addr {  };
    ::java::lang::String* hostname {  };
    int32_t port {  };

    /*void ctor(::java::lang::String* arg0, InetAddress* arg1, int32_t arg2); (private) */

public:
    bool equals(::java::lang::Object* arg0) override;
    /*InetAddress* getAddress(); (private) */
    /*::java::lang::String* getHostName(); (private) */
    /*::java::lang::String* getHostString(); (private) */
    /*int32_t getPort(); (private) */
    int32_t hashCode() override;
    /*bool isUnresolved(); (private) */
    ::java::lang::String* toString() override;

    // Generated
    InetSocketAddress_InetSocketAddressHolder();
protected:
    InetSocketAddress_InetSocketAddressHolder(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
