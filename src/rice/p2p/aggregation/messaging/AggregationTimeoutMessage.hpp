// Generated from /pastry-2.1/src/rice/p2p/aggregation/messaging/AggregationTimeoutMessage.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/p2p/aggregation/messaging/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/aggregation/messaging/AggregationMessage.hpp>

struct default_init_tag;

class rice::p2p::aggregation::messaging::AggregationTimeoutMessage
    : public AggregationMessage
{

public:
    typedef AggregationMessage super;
    static constexpr int16_t TYPE { int16_t(1) };
protected:
    void ctor(int32_t uid, ::rice::p2p::commonapi::NodeHandle* local);

public:
    ::java::lang::String* toString() override;

    // Generated
    AggregationTimeoutMessage(int32_t uid, ::rice::p2p::commonapi::NodeHandle* local);
protected:
    AggregationTimeoutMessage(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
