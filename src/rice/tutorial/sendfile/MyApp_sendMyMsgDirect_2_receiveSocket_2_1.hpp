// Generated from /pastry-2.1/src/rice/tutorial/sendfile/MyApp.java

#pragma once

#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/filetransfer/fwd-pastry-2.1.hpp>
#include <rice/tutorial/sendfile/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/Continuation.hpp>

struct default_init_tag;

class rice::tutorial::sendfile::MyApp_sendMyMsgDirect_2_receiveSocket_2_1
    : public virtual ::java::lang::Object
    , public virtual ::rice::Continuation
{

public:
    typedef ::java::lang::Object super;
    void receiveException(::java::lang::Exception* exception) override;
    virtual void receiveResult(::org::mpisws::p2p::filetransfer::FileReceipt* result);

    // Generated
    MyApp_sendMyMsgDirect_2_receiveSocket_2_1(MyApp_sendMyMsgDirect_2 *MyApp_sendMyMsgDirect_2_this, ::java::io::File* f);
    static ::java::lang::Class *class_();
    virtual void receiveResult(::java::lang::Object* result) override;
    MyApp_sendMyMsgDirect_2 *MyApp_sendMyMsgDirect_2_this;
    ::java::io::File* f;

private:
    virtual ::java::lang::Class* getClass0();
    friend class MyApp;
    friend class MyApp_MyApp_1;
    friend class MyApp_MyApp_1_receiveSocket_1_1;
    friend class MyApp_MyFileListener;
    friend class MyApp_sendMyMsgDirect_2;
};
