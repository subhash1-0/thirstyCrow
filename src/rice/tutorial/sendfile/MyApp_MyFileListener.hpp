// Generated from /pastry-2.1/src/rice/tutorial/sendfile/MyApp.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/filetransfer/fwd-pastry-2.1.hpp>
#include <rice/tutorial/sendfile/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/filetransfer/FileTransferListener.hpp>

struct default_init_tag;

class rice::tutorial::sendfile::MyApp_MyFileListener
    : public virtual ::java::lang::Object
    , public virtual ::org::mpisws::p2p::filetransfer::FileTransferListener
{

public:
    typedef ::java::lang::Object super;
    void fileTransferred(::org::mpisws::p2p::filetransfer::FileReceipt* receipt, int64_t bytesTransferred, int64_t total, bool incoming) override;
    void msgTransferred(::org::mpisws::p2p::filetransfer::BBReceipt* receipt, int32_t bytesTransferred, int32_t total, bool incoming) override;
    void transferCancelled(::org::mpisws::p2p::filetransfer::Receipt* receipt, bool incoming) override;
    void transferFailed(::org::mpisws::p2p::filetransfer::Receipt* receipt, bool incoming) override;

    // Generated
    MyApp_MyFileListener(MyApp *MyApp_this);
protected:
    MyApp_MyFileListener(MyApp *MyApp_this, const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    MyApp *MyApp_this;

private:
    virtual ::java::lang::Class* getClass0();
    friend class MyApp;
    friend class MyApp_MyApp_1;
    friend class MyApp_MyApp_1_receiveSocket_1_1;
    friend class MyApp_sendMyMsgDirect_2;
    friend class MyApp_sendMyMsgDirect_2_receiveSocket_2_1;
};
