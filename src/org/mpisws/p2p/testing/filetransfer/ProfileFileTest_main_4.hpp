// Generated from /pastry-2.1/src/org/mpisws/p2p/testing/filetransfer/ProfileFileTest.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/testing/filetransfer/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/SocketCallback.hpp>

struct default_init_tag;

class org::mpisws::p2p::testing::filetransfer::ProfileFileTest_main_4
    : public virtual ::java::lang::Object
    , public virtual ::org::mpisws::p2p::transport::SocketCallback
{

public:
    typedef ::java::lang::Object super;
    void receiveResult(::org::mpisws::p2p::transport::SocketRequestHandle* cancellable, ::org::mpisws::p2p::transport::P2PSocket* s) override;
    void receiveException(::org::mpisws::p2p::transport::SocketRequestHandle* s, ::java::lang::Exception* ex) override;

    // Generated
    ProfileFileTest_main_4(::rice::environment::logging::Logger* logger, ::rice::environment::Environment* env);
    static ::java::lang::Class *class_();
    ::rice::environment::logging::Logger* logger;
    ::rice::environment::Environment* env;

private:
    virtual ::java::lang::Class* getClass0();
    friend class ProfileFileTest;
    friend class ProfileFileTest_main_1;
    friend class ProfileFileTest_main_2;
    friend class ProfileFileTest_main_2_incomingSocket_2_1;
    friend class ProfileFileTest_main_2_incomingSocket_2_2;
    friend class ProfileFileTest_main_3;
    friend class ProfileFileTest_main_4_receiveResult_4_1;
    friend class ProfileFileTest_main_4_receiveResult_4_2;
};
