// Generated from /pastry-2.1/src/rice/tutorial/remotesocket/Tutorial.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/nio/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/appsocket/fwd-pastry-2.1.hpp>
#include <rice/tutorial/remotesocket/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/p2p/commonapi/appsocket/AppSocketReceiver.hpp>

struct default_init_tag;

class rice::tutorial::remotesocket::Tutorial_Tutorial_1_receiveResult_1_1
    : public virtual ::java::lang::Object
    , public virtual ::rice::p2p::commonapi::appsocket::AppSocketReceiver
{

public:
    typedef ::java::lang::Object super;
    void receiveSelectResult(::rice::p2p::commonapi::appsocket::AppSocket* socket, bool canRead, bool canWrite) override;
    void receiveException(::rice::p2p::commonapi::appsocket::AppSocket* socket, ::java::lang::Exception* e) override;
    void receiveSocket(::rice::p2p::commonapi::appsocket::AppSocket* socket) override;

    // Generated
    Tutorial_Tutorial_1_receiveResult_1_1(Tutorial_Tutorial_1 *Tutorial_Tutorial_1_this, ::java::nio::ByteBuffer* out);
    static ::java::lang::Class *class_();
    Tutorial_Tutorial_1 *Tutorial_Tutorial_1_this;
    ::java::nio::ByteBuffer* out;

private:
    virtual ::java::lang::Class* getClass0();
    friend class Tutorial;
    friend class Tutorial_Tutorial_1;
};
