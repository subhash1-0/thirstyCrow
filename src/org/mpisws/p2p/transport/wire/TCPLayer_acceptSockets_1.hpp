// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/wire/TCPLayer.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/wire/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/Runnable.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::wire::TCPLayer_acceptSockets_1
    : public virtual ::java::lang::Object
    , public virtual ::java::lang::Runnable
{

public:
    typedef ::java::lang::Object super;
    void run() override;

    // Generated
    TCPLayer_acceptSockets_1(TCPLayer *TCPLayer_this, bool b);
    static ::java::lang::Class *class_();
    TCPLayer *TCPLayer_this;
    bool b;

private:
    virtual ::java::lang::Class* getClass0();
    friend class TCPLayer;
};
