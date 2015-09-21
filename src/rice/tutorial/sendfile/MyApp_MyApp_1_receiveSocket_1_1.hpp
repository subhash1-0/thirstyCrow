// Generated from /pastry-2.1/src/rice/tutorial/sendfile/MyApp.java

#pragma once

#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/nio/fwd-pastry-2.1.hpp>
#include <rice/tutorial/sendfile/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/filetransfer/FileTransferCallback.hpp>

struct default_init_tag;

class rice::tutorial::sendfile::MyApp_MyApp_1_receiveSocket_1_1
    : public virtual ::java::lang::Object
    , public virtual ::org::mpisws::p2p::filetransfer::FileTransferCallback
{

public:
    typedef ::java::lang::Object super;
    void messageReceived(::java::nio::ByteBuffer* bb) override;
    void fileReceived(::java::io::File* f, ::java::nio::ByteBuffer* metadata) override;
    void receiveException(::java::lang::Exception* ioe) override;

    // Generated
    MyApp_MyApp_1_receiveSocket_1_1(MyApp_MyApp_1 *MyApp_MyApp_1_this);
    static ::java::lang::Class *class_();
    MyApp_MyApp_1 *MyApp_MyApp_1_this;

private:
    virtual ::java::lang::Class* getClass0();
    friend class MyApp;
    friend class MyApp_MyApp_1;
    friend class MyApp_MyFileListener;
    friend class MyApp_sendMyMsgDirect_2;
    friend class MyApp_sendMyMsgDirect_2_receiveSocket_2_1;
};
