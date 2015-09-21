// Generated from /pastry-2.1/src/rice/pastry/standard/ConsistentJoinProtocol.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/pastry/standard/fwd-pastry-2.1.hpp>
#include <rice/selector/TimerTask.hpp>

struct default_init_tag;

class rice::pastry::standard::ConsistentJoinProtocol_ConsistentJoinProtocol_1
    : public ::rice::selector::TimerTask
{

public:
    typedef ::rice::selector::TimerTask super;
    void run() override;
    ::java::lang::String* toString() override;

    // Generated
    ConsistentJoinProtocol_ConsistentJoinProtocol_1(ConsistentJoinProtocol *ConsistentJoinProtocol_this);
    static ::java::lang::Class *class_();
    ConsistentJoinProtocol *ConsistentJoinProtocol_this;

private:
    virtual ::java::lang::Class* getClass0();
    friend class ConsistentJoinProtocol;
    friend class ConsistentJoinProtocol_FailedTime;
    friend class ConsistentJoinProtocol_CJPDeserializer;
    friend class ConsistentJoinProtocol_RequestFromEveryoneMsg;
};
