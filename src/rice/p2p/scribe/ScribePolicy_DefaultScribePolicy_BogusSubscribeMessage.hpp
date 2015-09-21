// Generated from /pastry-2.1/src/rice/p2p/scribe/ScribePolicy.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/scribe/fwd-pastry-2.1.hpp>
#include <rice/p2p/scribe/messaging/SubscribeMessage.hpp>

struct default_init_tag;

class rice::p2p::scribe::ScribePolicy_DefaultScribePolicy_BogusSubscribeMessage
    : public ::rice::p2p::scribe::messaging::SubscribeMessage
{

public:
    typedef ::rice::p2p::scribe::messaging::SubscribeMessage super;

public: /* package */
    ScribeContent* theContent {  };
protected:
    void ctor(::rice::p2p::commonapi::NodeHandle* source, Topic* topic, int32_t i, ScribeContent* content);

public:
    ScribeContent* getContent() override;

    // Generated
    ScribePolicy_DefaultScribePolicy_BogusSubscribeMessage(ScribePolicy_DefaultScribePolicy *ScribePolicy_DefaultScribePolicy_this, ::rice::p2p::commonapi::NodeHandle* source, Topic* topic, int32_t i, ScribeContent* content);
protected:
    ScribePolicy_DefaultScribePolicy_BogusSubscribeMessage(ScribePolicy_DefaultScribePolicy *ScribePolicy_DefaultScribePolicy_this, const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    ScribePolicy_DefaultScribePolicy *ScribePolicy_DefaultScribePolicy_this;

private:
    virtual ::java::lang::Class* getClass0();
    friend class ScribePolicy;
    friend class ScribePolicy_DefaultScribePolicy;
    friend class ScribePolicy_LimitedScribePolicy;
};
