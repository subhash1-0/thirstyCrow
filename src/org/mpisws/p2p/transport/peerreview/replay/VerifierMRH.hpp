// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/replay/VerifierMRH.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/nio/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/replay/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/util/MessageRequestHandleImpl.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::peerreview::replay::VerifierMRH
    : public ::org::mpisws::p2p::transport::util::MessageRequestHandleImpl
{

public:
    typedef ::org::mpisws::p2p::transport::util::MessageRequestHandleImpl super;
    ::org::mpisws::p2p::transport::MessageCallback* callback {  };
protected:
    void ctor(::java::lang::Object* i, ::java::nio::ByteBuffer* m, ::org::mpisws::p2p::transport::MessageCallback* callback, ::java::util::Map* options);

public:
    virtual void ack();

    // Generated
    VerifierMRH(::java::lang::Object* i, ::java::nio::ByteBuffer* m, ::org::mpisws::p2p::transport::MessageCallback* callback, ::java::util::Map* options);
protected:
    VerifierMRH(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
