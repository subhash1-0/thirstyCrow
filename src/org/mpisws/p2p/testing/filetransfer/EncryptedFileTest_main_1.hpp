// Generated from /pastry-2.1/src/org/mpisws/p2p/testing/filetransfer/EncryptedFileTest.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/net/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/testing/filetransfer/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/liveness/LivenessListener.hpp>

struct default_init_tag;

class org::mpisws::p2p::testing::filetransfer::EncryptedFileTest_main_1
    : public virtual ::java::lang::Object
    , public virtual ::org::mpisws::p2p::transport::liveness::LivenessListener
{

public:
    typedef ::java::lang::Object super;
    virtual void livenessChanged(::java::net::InetSocketAddress* i, int32_t val, ::java::util::Map* options);

    // Generated
    EncryptedFileTest_main_1(::rice::environment::logging::Logger* logger);
    static ::java::lang::Class *class_();
    virtual void livenessChanged(::java::lang::Object* i, int32_t val, ::java::util::Map* options) override;
    ::rice::environment::logging::Logger* logger;

private:
    virtual ::java::lang::Class* getClass0();
    friend class EncryptedFileTest;
    friend class EncryptedFileTest_main_2;
    friend class EncryptedFileTest_main_2_incomingSocket_2_1;
    friend class EncryptedFileTest_main_2_incomingSocket_2_2;
    friend class EncryptedFileTest_main_3;
    friend class EncryptedFileTest_main_4;
    friend class EncryptedFileTest_main_4_receiveResult_4_1;
    friend class EncryptedFileTest_main_4_receiveResult_4_2;
    friend class EncryptedFileTest_main_4_receiveResult_4_3;
};
