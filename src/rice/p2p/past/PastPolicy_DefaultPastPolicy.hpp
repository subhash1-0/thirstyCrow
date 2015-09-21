// Generated from /pastry-2.1/src/rice/p2p/past/PastPolicy.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <rice/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/past/fwd-pastry-2.1.hpp>
#include <rice/persistence/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/p2p/past/PastPolicy.hpp>

struct default_init_tag;

class rice::p2p::past::PastPolicy_DefaultPastPolicy
    : public virtual ::java::lang::Object
    , public virtual PastPolicy
{

public:
    typedef ::java::lang::Object super;
    void fetch(::rice::p2p::commonapi::Id* id, ::rice::p2p::commonapi::NodeHandle* hint, ::rice::persistence::Cache* backup, Past* past, ::rice::Continuation* command) override;
    bool allowInsert(PastContent* content) override;

    // Generated
    PastPolicy_DefaultPastPolicy();
protected:
    PastPolicy_DefaultPastPolicy(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
    friend class PastPolicy;
    friend class PastPolicy_DefaultPastPolicy_fetch_1;
    friend class PastPolicy_DefaultPastPolicy_fetch_1_receiveResult_1_1;
};
