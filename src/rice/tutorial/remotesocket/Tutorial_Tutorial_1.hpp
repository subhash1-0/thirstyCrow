// Generated from /pastry-2.1/src/rice/tutorial/remotesocket/Tutorial.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/appsocket/fwd-pastry-2.1.hpp>
#include <rice/tutorial/remotesocket/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/Continuation.hpp>

struct default_init_tag;

class rice::tutorial::remotesocket::Tutorial_Tutorial_1
    : public virtual ::java::lang::Object
    , public virtual ::rice::Continuation
{

public:
    typedef ::java::lang::Object super;
    virtual void receiveResult(::rice::p2p::commonapi::appsocket::AppSocket* result);
    void receiveException(::java::lang::Exception* exception) override;

    // Generated
    Tutorial_Tutorial_1(Tutorial *Tutorial_this);
    static ::java::lang::Class *class_();
    virtual void receiveResult(::java::lang::Object* result) override;
    Tutorial *Tutorial_this;

private:
    virtual ::java::lang::Class* getClass0();
    friend class Tutorial;
    friend class Tutorial_Tutorial_1_receiveResult_1_1;
};
