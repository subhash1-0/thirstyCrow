// Generated from /pastry-2.1/src/org/mpisws/p2p/testing/filetransfer/EncryptedFileTest.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/filetransfer/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/testing/filetransfer/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/filetransfer/SimpleFileTransferListener.hpp>

struct default_init_tag;

class org::mpisws::p2p::testing::filetransfer::EncryptedFileTest_main_4_receiveResult_4_2
    : public ::org::mpisws::p2p::filetransfer::SimpleFileTransferListener
{

public:
    typedef ::org::mpisws::p2p::filetransfer::SimpleFileTransferListener super;
    void fileTransferred(::org::mpisws::p2p::filetransfer::FileReceipt* receipt, int64_t bytesTransferred, int64_t total, bool incoming) override;

    // Generated
    EncryptedFileTest_main_4_receiveResult_4_2(EncryptedFileTest_main_4 *EncryptedFileTest_main_4_this, ::java::lang::String* prefix);
    static ::java::lang::Class *class_();
    EncryptedFileTest_main_4 *EncryptedFileTest_main_4_this;

private:
    virtual ::java::lang::Class* getClass0();
    friend class EncryptedFileTest;
    friend class EncryptedFileTest_main_1;
    friend class EncryptedFileTest_main_2;
    friend class EncryptedFileTest_main_2_incomingSocket_2_1;
    friend class EncryptedFileTest_main_2_incomingSocket_2_2;
    friend class EncryptedFileTest_main_3;
    friend class EncryptedFileTest_main_4;
    friend class EncryptedFileTest_main_4_receiveResult_4_1;
    friend class EncryptedFileTest_main_4_receiveResult_4_3;
};
