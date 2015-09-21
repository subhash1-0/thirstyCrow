// Generated from /pastry-2.1/src/rice/tutorial/scribe/MyScribeClient.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <rice/tutorial/scribe/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/p2p/commonapi/Message.hpp>

struct default_init_tag;

class rice::tutorial::scribe::MyScribeClient_PublishContent
    : public virtual ::java::lang::Object
    , public virtual ::rice::p2p::commonapi::Message
{

public:
    typedef ::java::lang::Object super;
    int32_t getPriority() override;

    // Generated
    MyScribeClient_PublishContent(MyScribeClient *MyScribeClient_this);
protected:
    MyScribeClient_PublishContent(MyScribeClient *MyScribeClient_this, const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    MyScribeClient *MyScribeClient_this;

private:
    virtual ::java::lang::Class* getClass0();
    friend class MyScribeClient;
};
