// Generated from /pastry-2.1/src/rice/tutorial/timer/MyApp.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <rice/tutorial/timer/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/p2p/commonapi/Message.hpp>

struct default_init_tag;

class rice::tutorial::timer::MyApp_MessageToSelf
    : public virtual ::java::lang::Object
    , public virtual ::rice::p2p::commonapi::Message
{

public:
    typedef ::java::lang::Object super;
    int32_t getPriority() override;

    // Generated
    MyApp_MessageToSelf(MyApp *MyApp_this);
protected:
    MyApp_MessageToSelf(MyApp *MyApp_this, const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    MyApp *MyApp_this;

private:
    virtual ::java::lang::Class* getClass0();
    friend class MyApp;
};
