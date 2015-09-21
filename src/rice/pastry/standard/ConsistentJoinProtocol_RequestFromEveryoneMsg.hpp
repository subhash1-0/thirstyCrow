// Generated from /pastry-2.1/src/rice/pastry/standard/ConsistentJoinProtocol.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <rice/pastry/standard/fwd-pastry-2.1.hpp>
#include <rice/pastry/messaging/Message.hpp>

struct default_init_tag;

class rice::pastry::standard::ConsistentJoinProtocol_RequestFromEveryoneMsg
    : public ::rice::pastry::messaging::Message
{

public:
    typedef ::rice::pastry::messaging::Message super;
protected:
    void ctor(int32_t address);

    // Generated

public:
    ConsistentJoinProtocol_RequestFromEveryoneMsg(ConsistentJoinProtocol *ConsistentJoinProtocol_this, int32_t address);
protected:
    ConsistentJoinProtocol_RequestFromEveryoneMsg(ConsistentJoinProtocol *ConsistentJoinProtocol_this, const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    ConsistentJoinProtocol *ConsistentJoinProtocol_this;

private:
    virtual ::java::lang::Class* getClass0();
    friend class ConsistentJoinProtocol;
    friend class ConsistentJoinProtocol_FailedTime;
    friend class ConsistentJoinProtocol_CJPDeserializer;
    friend class ConsistentJoinProtocol_ConsistentJoinProtocol_1;
};
