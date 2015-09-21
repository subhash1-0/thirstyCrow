// Generated from /pastry-2.1/src/rice/pastry/ScheduledMessage.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/pastry/messaging/fwd-pastry-2.1.hpp>
#include <rice/selector/TimerTask.hpp>

struct default_init_tag;

class rice::pastry::ScheduledMessage
    : public ::rice::selector::TimerTask
{

public:
    typedef ::rice::selector::TimerTask super;

public: /* protected */
    PastryNode* localNode {  };
    ::rice::pastry::messaging::Message* msg {  };
protected:
    void ctor(PastryNode* pn, ::rice::pastry::messaging::Message* msg);

public:
    virtual ::rice::pastry::messaging::Message* getMessage();
    virtual PastryNode* getLocalNode();
    void run() override;
    ::java::lang::String* toString() override;
    bool cancel() override;

    // Generated
    ScheduledMessage(PastryNode* pn, ::rice::pastry::messaging::Message* msg);
protected:
    ScheduledMessage(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
