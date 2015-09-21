// Generated from /pastry-2.1/src/rice/pastry/testing/HelloMsg.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/pastry/testing/fwd-pastry-2.1.hpp>
#include <rice/pastry/messaging/Message.hpp>

struct default_init_tag;

class rice::pastry::testing::HelloMsg
    : public ::rice::pastry::messaging::Message
{

public:
    typedef ::rice::pastry::messaging::Message super;
    ::rice::p2p::commonapi::Id* target {  };

private:
    int32_t msgid {  };

public:
    bool messageDirect {  };

private:
    ::rice::pastry::NodeHandle* src {  };
protected:
    void ctor(int32_t addr, ::rice::pastry::NodeHandle* src, ::rice::p2p::commonapi::Id* tgt, int32_t mid);

public:
    ::java::lang::String* toString() override;
    virtual ::java::lang::String* getInfo();
    virtual int32_t getId();

    // Generated
    HelloMsg(int32_t addr, ::rice::pastry::NodeHandle* src, ::rice::p2p::commonapi::Id* tgt, int32_t mid);
protected:
    HelloMsg(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    void init();
    virtual ::java::lang::Class* getClass0();
};
