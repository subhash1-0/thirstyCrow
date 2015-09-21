// Generated from /pastry-2.1/src/rice/p2p/replication/manager/messaging/ReminderMessage.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <rice/p2p/replication/manager/messaging/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/p2p/commonapi/Message.hpp>

struct default_init_tag;

class rice::p2p::replication::manager::messaging::ReminderMessage
    : public virtual ::java::lang::Object
    , public virtual ::rice::p2p::commonapi::Message
{

public:
    typedef ::java::lang::Object super;
protected:
    void ctor();

public:
    int32_t getPriority() override;

    // Generated
    ReminderMessage();
protected:
    ReminderMessage(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
