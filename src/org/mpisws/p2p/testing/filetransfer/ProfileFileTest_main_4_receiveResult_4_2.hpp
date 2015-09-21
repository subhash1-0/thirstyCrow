// Generated from /pastry-2.1/src/org/mpisws/p2p/testing/filetransfer/ProfileFileTest.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/filetransfer/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/testing/filetransfer/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/Continuation.hpp>

struct default_init_tag;

class org::mpisws::p2p::testing::filetransfer::ProfileFileTest_main_4_receiveResult_4_2
    : public virtual ::java::lang::Object
    , public virtual ::rice::Continuation
{

public:
    typedef ::java::lang::Object super;
    virtual void receiveResult(::org::mpisws::p2p::filetransfer::FileReceipt* result);
    void receiveException(::java::lang::Exception* exception) override;

    // Generated
    ProfileFileTest_main_4_receiveResult_4_2(ProfileFileTest_main_4 *ProfileFileTest_main_4_this);
    static ::java::lang::Class *class_();
    virtual void receiveResult(::java::lang::Object* result) override;
    ProfileFileTest_main_4 *ProfileFileTest_main_4_this;

private:
    virtual ::java::lang::Class* getClass0();
    friend class ProfileFileTest;
    friend class ProfileFileTest_main_1;
    friend class ProfileFileTest_main_2;
    friend class ProfileFileTest_main_2_incomingSocket_2_1;
    friend class ProfileFileTest_main_2_incomingSocket_2_2;
    friend class ProfileFileTest_main_3;
    friend class ProfileFileTest_main_4;
    friend class ProfileFileTest_main_4_receiveResult_4_1;
};
