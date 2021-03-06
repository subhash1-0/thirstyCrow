// Generated from /pastry-2.1/src/rice/pastry/socket/nat/rendezvous/NeverResponseStrategy.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/nio/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/pastry/socket/nat/rendezvous/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/rendezvous/ResponseStrategy.hpp>

struct default_init_tag;

class rice::pastry::socket::nat::rendezvous::NeverResponseStrategy
    : public virtual ::java::lang::Object
    , public virtual ::org::mpisws::p2p::transport::rendezvous::ResponseStrategy
{

public:
    typedef ::java::lang::Object super;
    void messageReceived(::java::lang::Object* i, ::java::nio::ByteBuffer* msg, ::java::util::Map* options) override;
    void messageSent(::java::lang::Object* i, ::java::nio::ByteBuffer* msg, ::java::util::Map* options) override;
    bool sendDirect(::java::lang::Object* i, ::java::nio::ByteBuffer* msg, ::java::util::Map* options) override;

    // Generated
    NeverResponseStrategy();
protected:
    NeverResponseStrategy(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
