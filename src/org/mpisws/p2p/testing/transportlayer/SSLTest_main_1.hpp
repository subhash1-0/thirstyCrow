// Generated from /pastry-2.1/src/org/mpisws/p2p/testing/transportlayer/SSLTest.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/net/fwd-pastry-2.1.hpp>
#include <java/nio/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/testing/transportlayer/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/TransportLayerCallback.hpp>

struct default_init_tag;

class org::mpisws::p2p::testing::transportlayer::SSLTest_main_1
    : public virtual ::java::lang::Object
    , public virtual ::org::mpisws::p2p::transport::TransportLayerCallback
{

public:
    typedef ::java::lang::Object super;
    void incomingSocket(::org::mpisws::p2p::transport::P2PSocket* s) /* throws(IOException) */ override;
    virtual void messageReceived(::java::net::InetSocketAddress* i, ::java::nio::ByteBuffer* m, ::java::util::Map* options) /* throws(IOException) */;

    // Generated
    SSLTest_main_1();
    static ::java::lang::Class *class_();
    virtual void messageReceived(::java::lang::Object* i, ::java::lang::Object* m, ::java::util::Map* options) override;

private:
    virtual ::java::lang::Class* getClass0();
    friend class SSLTest;
    friend class SSLTest_main_1_incomingSocket_1_1;
    friend class SSLTest_main_2;
    friend class SSLTest_main_2_receiveResult_2_1;
};
