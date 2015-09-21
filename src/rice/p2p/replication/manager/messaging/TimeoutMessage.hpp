// Generated from /pastry-2.1/src/rice/p2p/replication/manager/messaging/TimeoutMessage.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/replication/manager/messaging/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/p2p/commonapi/Message.hpp>

struct default_init_tag;

class rice::p2p::replication::manager::messaging::TimeoutMessage
    : public virtual ::java::lang::Object
    , public virtual ::rice::p2p::commonapi::Message
{

public:
    typedef ::java::lang::Object super;

public: /* protected */
    ::rice::p2p::commonapi::Id* id {  };
protected:
    void ctor(::rice::p2p::commonapi::Id* id);

public:
    int32_t getPriority() override;
    virtual ::rice::p2p::commonapi::Id* getId();

    // Generated
    TimeoutMessage(::rice::p2p::commonapi::Id* id);
protected:
    TimeoutMessage(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
