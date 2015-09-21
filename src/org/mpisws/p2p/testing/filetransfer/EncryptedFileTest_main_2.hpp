// Generated from /pastry-2.1/src/org/mpisws/p2p/testing/filetransfer/EncryptedFileTest.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/net/fwd-pastry-2.1.hpp>
#include <java/nio/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/testing/filetransfer/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/TransportLayerCallback.hpp>

struct default_init_tag;

class org::mpisws::p2p::testing::filetransfer::EncryptedFileTest_main_2
    : public virtual ::java::lang::Object
    , public virtual ::org::mpisws::p2p::transport::TransportLayerCallback
{

public:
    typedef ::java::lang::Object super;
    virtual void messageReceived(::java::net::InetSocketAddress* i, ::java::nio::ByteBuffer* m, ::java::util::Map* options) /* throws(IOException) */;
    void incomingSocket(::org::mpisws::p2p::transport::P2PSocket* s) /* throws(IOException) */ override;

    // Generated
    EncryptedFileTest_main_2(::rice::environment::logging::Logger* logger, ::rice::environment::Environment* env);
    static ::java::lang::Class *class_();
    virtual void messageReceived(::java::lang::Object* i, ::java::lang::Object* m, ::java::util::Map* options) override;
    ::rice::environment::logging::Logger* logger;
    ::rice::environment::Environment* env;

private:
    virtual ::java::lang::Class* getClass0();
    friend class EncryptedFileTest;
    friend class EncryptedFileTest_main_1;
    friend class EncryptedFileTest_main_2_incomingSocket_2_1;
    friend class EncryptedFileTest_main_2_incomingSocket_2_2;
    friend class EncryptedFileTest_main_3;
    friend class EncryptedFileTest_main_4;
    friend class EncryptedFileTest_main_4_receiveResult_4_1;
    friend class EncryptedFileTest_main_4_receiveResult_4_2;
    friend class EncryptedFileTest_main_4_receiveResult_4_3;
};
