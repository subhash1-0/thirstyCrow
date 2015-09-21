// Generated from /pastry-2.1/src/rice/tutorial/sendfile/MyApp.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/appsocket/fwd-pastry-2.1.hpp>
#include <rice/tutorial/sendfile/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/p2p/commonapi/appsocket/AppSocketReceiver.hpp>

struct default_init_tag;

class rice::tutorial::sendfile::MyApp_MyApp_1
    : public virtual ::java::lang::Object
    , public virtual ::rice::p2p::commonapi::appsocket::AppSocketReceiver
{

public:
    typedef ::java::lang::Object super;
    void receiveSocket(::rice::p2p::commonapi::appsocket::AppSocket* socket) override;
    void receiveSelectResult(::rice::p2p::commonapi::appsocket::AppSocket* socket, bool canRead, bool canWrite) override;
    void receiveException(::rice::p2p::commonapi::appsocket::AppSocket* socket, ::java::lang::Exception* e) override;

    // Generated
    MyApp_MyApp_1(MyApp *MyApp_this);
    static ::java::lang::Class *class_();
    MyApp *MyApp_this;

private:
    virtual ::java::lang::Class* getClass0();
    friend class MyApp;
    friend class MyApp_MyApp_1_receiveSocket_1_1;
    friend class MyApp_MyFileListener;
    friend class MyApp_sendMyMsgDirect_2;
    friend class MyApp_sendMyMsgDirect_2_receiveSocket_2_1;
};
