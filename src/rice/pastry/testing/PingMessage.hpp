// Generated from /pastry-2.1/src/rice/pastry/testing/PingClient.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/pastry/testing/fwd-pastry-2.1.hpp>
#include <rice/pastry/messaging/Message.hpp>

struct default_init_tag;

class rice::pastry::testing::PingMessage
    : public ::rice::pastry::messaging::Message
{

public:
    typedef ::rice::pastry::messaging::Message super;

private:
    ::rice::pastry::Id* source {  };
    ::rice::pastry::Id* target {  };
protected:
    void ctor(int32_t pingAddress, ::rice::pastry::Id* src, ::rice::pastry::Id* tgt);

public:
    ::java::lang::String* toString() override;

    // Generated
    PingMessage(int32_t pingAddress, ::rice::pastry::Id* src, ::rice::pastry::Id* tgt);
protected:
    PingMessage(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
    friend class PingClient;
    friend class PingClient_PingAddress;
};
