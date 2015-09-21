// Generated from /pastry-2.1/src/rice/pastry/messaging/PRawMessage.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/pastry/messaging/fwd-pastry-2.1.hpp>
#include <rice/pastry/messaging/Message.hpp>
#include <rice/p2p/commonapi/rawserialization/RawMessage.hpp>

struct default_init_tag;

class rice::pastry::messaging::PRawMessage
    : public Message
    , public virtual ::rice::p2p::commonapi::rawserialization::RawMessage
{

public:
    typedef Message super;
protected:
    void ctor(int32_t address);
    void ctor(int32_t address, ::java::util::Date* timestamp);

    // Generated

public:
    PRawMessage(int32_t address);
    PRawMessage(int32_t address, ::java::util::Date* timestamp);
protected:
    PRawMessage(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    virtual int32_t getPriority();

private:
    virtual ::java::lang::Class* getClass0();
};
