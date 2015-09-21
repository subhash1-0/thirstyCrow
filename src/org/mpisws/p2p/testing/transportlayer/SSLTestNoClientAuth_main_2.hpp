// Generated from /pastry-2.1/src/org/mpisws/p2p/testing/transportlayer/SSLTestNoClientAuth.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/testing/transportlayer/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/SocketCallback.hpp>

struct default_init_tag;

class org::mpisws::p2p::testing::transportlayer::SSLTestNoClientAuth_main_2
    : public virtual ::java::lang::Object
    , public virtual ::org::mpisws::p2p::transport::SocketCallback
{

public:
    typedef ::java::lang::Object super;
    void receiveResult(::org::mpisws::p2p::transport::SocketRequestHandle* cancellable, ::org::mpisws::p2p::transport::P2PSocket* sock) override;
    void receiveException(::org::mpisws::p2p::transport::SocketRequestHandle* s, ::java::lang::Exception* ex) override;

    // Generated
    SSLTestNoClientAuth_main_2();
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
    friend class SSLTestNoClientAuth;
    friend class SSLTestNoClientAuth_main_1;
    friend class SSLTestNoClientAuth_main_1_incomingSocket_1_1;
    friend class SSLTestNoClientAuth_main_2_receiveResult_2_1;
};
