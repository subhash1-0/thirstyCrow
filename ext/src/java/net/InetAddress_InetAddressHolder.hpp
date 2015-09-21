// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/net/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct default_init_tag;

class java::net::InetAddress_InetAddressHolder
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    int32_t address {  };
    int32_t family {  };
    ::java::lang::String* hostName {  };

private:
    ::java::lang::String* originalHostName {  };

protected:
    void ctor();
    void ctor(::java::lang::String* arg0, int32_t arg1, int32_t arg2);

public: /* package */
    virtual int32_t getAddress();
    virtual int32_t getFamily();
    virtual ::java::lang::String* getHostName();
    virtual ::java::lang::String* getOriginalHostName();
    virtual void init_(::java::lang::String* arg0, int32_t arg1);

    // Generated
    InetAddress_InetAddressHolder();
    InetAddress_InetAddressHolder(::java::lang::String* arg0, int32_t arg1, int32_t arg2);
protected:
    InetAddress_InetAddressHolder(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
