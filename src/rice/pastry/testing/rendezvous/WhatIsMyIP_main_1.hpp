// Generated from /pastry-2.1/src/rice/pastry/testing/rendezvous/WhatIsMyIP.java

#pragma once

#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/net/fwd-pastry-2.1.hpp>
#include <rice/pastry/testing/rendezvous/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/Continuation.hpp>

struct default_init_tag;

class rice::pastry::testing::rendezvous::WhatIsMyIP_main_1
    : public virtual ::java::lang::Object
    , public virtual ::rice::Continuation
{

public:
    typedef ::java::lang::Object super;
    virtual void receiveResult(::java::net::InetAddress* result);
    virtual void receiveException(::java::io::IOException* exception);

    // Generated
    WhatIsMyIP_main_1();
    static ::java::lang::Class *class_();
    virtual void receiveException(::java::lang::Exception* exception) override;
    virtual void receiveResult(::java::lang::Object* result) override;

private:
    virtual ::java::lang::Class* getClass0();
    friend class WhatIsMyIP;
};
