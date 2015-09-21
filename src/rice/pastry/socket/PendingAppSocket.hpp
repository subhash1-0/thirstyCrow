// Generated from /pastry-2.1/src/rice/pastry/socket/PendingAppSocket.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/appsocket/fwd-pastry-2.1.hpp>
#include <rice/pastry/socket/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct default_init_tag;

class rice::pastry::socket::PendingAppSocket
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    int32_t appAddress {  };
    ::rice::p2p::commonapi::appsocket::AppSocketReceiver* receiver {  };
protected:
    void ctor(int32_t appAddress, ::rice::p2p::commonapi::appsocket::AppSocketReceiver* receiver);

    // Generated

public:
    PendingAppSocket(int32_t appAddress, ::rice::p2p::commonapi::appsocket::AppSocketReceiver* receiver);
protected:
    PendingAppSocket(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
