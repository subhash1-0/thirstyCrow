// Generated from /pastry-2.1/src/rice/p2p/util/MCAdapter.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <rice/p2p/util/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/MessageCallback.hpp>

struct default_init_tag;

class rice::p2p::util::MCAdapter
    : public virtual ::java::lang::Object
    , public virtual ::org::mpisws::p2p::transport::MessageCallback
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    ::org::mpisws::p2p::transport::MessageCallback* internal {  };

private:
    MRHAdapter* handle {  };
protected:
    void ctor(::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, MRHAdapter* handle);

public:
    void ack(::org::mpisws::p2p::transport::MessageRequestHandle* msg) override;
    void sendFailed(::org::mpisws::p2p::transport::MessageRequestHandle* msg, ::java::lang::Exception* reason) override;

    // Generated
    MCAdapter(::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, MRHAdapter* handle);
protected:
    MCAdapter(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
