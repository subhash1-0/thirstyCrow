// Generated from /pastry-2.1/src/org/mpisws/p2p/testing/filetransfer/ProfileFileTest.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/filetransfer/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/testing/filetransfer/fwd-pastry-2.1.hpp>
#include <rice/environment/time/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/filetransfer/FileTransferListener.hpp>

struct default_init_tag;

class org::mpisws::p2p::testing::filetransfer::ProfileFileTest_main_2_incomingSocket_2_2
    : public virtual ::java::lang::Object
    , public virtual ::org::mpisws::p2p::filetransfer::FileTransferListener
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    ::java::util::Map* startTimes {  };

public:
    void fileTransferred(::org::mpisws::p2p::filetransfer::FileReceipt* receipt, int64_t bytesTransferred, int64_t total, bool incoming) override;
    void msgTransferred(::org::mpisws::p2p::filetransfer::BBReceipt* receipt, int32_t bytesTransferred, int32_t total, bool incoming) override;
    void transferCancelled(::org::mpisws::p2p::filetransfer::Receipt* receipt, bool incoming) override;
    void transferFailed(::org::mpisws::p2p::filetransfer::Receipt* receipt, bool incoming) override;

    // Generated
    ProfileFileTest_main_2_incomingSocket_2_2(ProfileFileTest_main_2 *ProfileFileTest_main_2_this, ::rice::environment::time::TimeSource* time);
    static ::java::lang::Class *class_();

private:
    void init();
    ProfileFileTest_main_2 *ProfileFileTest_main_2_this;
    ::rice::environment::time::TimeSource* time;
    virtual ::java::lang::Class* getClass0();
    friend class ProfileFileTest;
    friend class ProfileFileTest_main_1;
    friend class ProfileFileTest_main_2;
    friend class ProfileFileTest_main_2_incomingSocket_2_1;
    friend class ProfileFileTest_main_3;
    friend class ProfileFileTest_main_4;
    friend class ProfileFileTest_main_4_receiveResult_4_1;
    friend class ProfileFileTest_main_4_receiveResult_4_2;
};
