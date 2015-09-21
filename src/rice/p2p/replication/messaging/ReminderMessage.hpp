// Generated from /pastry-2.1/src/rice/p2p/replication/messaging/ReminderMessage.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/p2p/replication/messaging/fwd-pastry-2.1.hpp>
#include <rice/p2p/replication/messaging/ReplicationMessage.hpp>

struct default_init_tag;

class rice::p2p::replication::messaging::ReminderMessage
    : public ReplicationMessage
{

public:
    typedef ReplicationMessage super;
    static constexpr int16_t TYPE { int16_t(1) };
protected:
    void ctor(::rice::p2p::commonapi::NodeHandle* source);

public:
    int16_t getType() override;
    void serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */ override;

    // Generated
    ReminderMessage(::rice::p2p::commonapi::NodeHandle* source);
protected:
    ReminderMessage(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
