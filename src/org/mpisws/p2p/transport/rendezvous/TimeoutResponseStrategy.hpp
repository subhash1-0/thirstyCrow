// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/rendezvous/TimeoutResponseStrategy.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/nio/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/rendezvous/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/environment/time/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/rendezvous/ResponseStrategy.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::rendezvous::TimeoutResponseStrategy
    : public virtual ::java::lang::Object
    , public virtual ResponseStrategy
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    ::java::util::Map* lastTimeReceived {  };
    int32_t timeout {  };
    ::rice::environment::time::TimeSource* time {  };
protected:
    void ctor(int32_t timeout, ::rice::environment::Environment* env);

public:
    void messageReceived(::java::lang::Object* i, ::java::nio::ByteBuffer* msg, ::java::util::Map* options) override;
    void messageSent(::java::lang::Object* i, ::java::nio::ByteBuffer* msg, ::java::util::Map* options) override;
    bool sendDirect(::java::lang::Object* i, ::java::nio::ByteBuffer* msg, ::java::util::Map* options) override;

    // Generated
    TimeoutResponseStrategy(int32_t timeout, ::rice::environment::Environment* env);
protected:
    TimeoutResponseStrategy(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
