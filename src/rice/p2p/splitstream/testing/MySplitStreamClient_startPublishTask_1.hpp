// Generated from /pastry-2.1/src/rice/p2p/splitstream/testing/MySplitStreamClient.java

#pragma once

#include <rice/p2p/splitstream/testing/fwd-pastry-2.1.hpp>
#include <rice/selector/TimerTask.hpp>

struct default_init_tag;

class rice::p2p::splitstream::testing::MySplitStreamClient_startPublishTask_1
    : public ::rice::selector::TimerTask
{

public:
    typedef ::rice::selector::TimerTask super;
    void run() override;

    // Generated
    MySplitStreamClient_startPublishTask_1(MySplitStreamClient *MySplitStreamClient_this);
    static ::java::lang::Class *class_();
    MySplitStreamClient *MySplitStreamClient_this;

private:
    virtual ::java::lang::Class* getClass0();
    friend class MySplitStreamClient;
};
