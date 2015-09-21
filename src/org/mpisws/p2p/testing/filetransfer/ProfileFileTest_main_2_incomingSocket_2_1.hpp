// Generated from /pastry-2.1/src/org/mpisws/p2p/testing/filetransfer/ProfileFileTest.java

#pragma once

#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/nio/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/testing/filetransfer/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/filetransfer/FileTransferCallback.hpp>

struct default_init_tag;

class org::mpisws::p2p::testing::filetransfer::ProfileFileTest_main_2_incomingSocket_2_1
    : public virtual ::java::lang::Object
    , public virtual ::org::mpisws::p2p::filetransfer::FileTransferCallback
{

public:
    typedef ::java::lang::Object super;
    void messageReceived(::java::nio::ByteBuffer* bb) override;
    void fileReceived(::java::io::File* f, ::java::nio::ByteBuffer* metadata) override;
    void receiveException(::java::lang::Exception* ioe) override;

    // Generated
    ProfileFileTest_main_2_incomingSocket_2_1(ProfileFileTest_main_2 *ProfileFileTest_main_2_this, ::rice::environment::logging::Logger* logger);
    static ::java::lang::Class *class_();
    ProfileFileTest_main_2 *ProfileFileTest_main_2_this;
    ::rice::environment::logging::Logger* logger;

private:
    virtual ::java::lang::Class* getClass0();
    friend class ProfileFileTest;
    friend class ProfileFileTest_main_1;
    friend class ProfileFileTest_main_2;
    friend class ProfileFileTest_main_2_incomingSocket_2_2;
    friend class ProfileFileTest_main_3;
    friend class ProfileFileTest_main_4;
    friend class ProfileFileTest_main_4_receiveResult_4_1;
    friend class ProfileFileTest_main_4_receiveResult_4_2;
};
