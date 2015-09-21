// Generated from /pastry-2.1/src/org/mpisws/p2p/testing/transportlayer/SSLTest.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/nio/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/testing/transportlayer/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/P2PSocketReceiver.hpp>

struct default_init_tag;

class org::mpisws::p2p::testing::transportlayer::SSLTest_main_1_incomingSocket_1_1
    : public virtual ::java::lang::Object
    , public virtual ::org::mpisws::p2p::transport::P2PSocketReceiver
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    ::java::nio::ByteBuffer* readMe {  };

public:
    void receiveSelectResult(::org::mpisws::p2p::transport::P2PSocket* socket, bool canRead, bool canWrite) /* throws(IOException) */ override;
    void receiveException(::org::mpisws::p2p::transport::P2PSocket* socket, ::java::lang::Exception* ioe) override;

    // Generated
    SSLTest_main_1_incomingSocket_1_1(SSLTest_main_1 *SSLTest_main_1_this);
    static ::java::lang::Class *class_();

private:
    void init();
    SSLTest_main_1 *SSLTest_main_1_this;
    virtual ::java::lang::Class* getClass0();
    friend class SSLTest;
    friend class SSLTest_main_1;
    friend class SSLTest_main_2;
    friend class SSLTest_main_2_receiveResult_2_1;
};
