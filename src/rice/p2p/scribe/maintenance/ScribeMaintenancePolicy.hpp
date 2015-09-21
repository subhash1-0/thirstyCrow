// Generated from /pastry-2.1/src/rice/p2p/scribe/maintenance/ScribeMaintenancePolicy.java

#pragma once

#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/scribe/maintenance/fwd-pastry-2.1.hpp>
#include <rice/p2p/scribe/rawserialization/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct rice::p2p::scribe::maintenance::ScribeMaintenancePolicy
    : public virtual ::java::lang::Object
{
    virtual void doMaintenance(MaintainableScribe* scribe) = 0;
    virtual void noLongerRoot(MaintainableScribe* scribe, ::java::util::List* topics) = 0;
    virtual void nodeFaulty(MaintainableScribe* scribe, ::rice::p2p::commonapi::NodeHandle* node, ::java::util::List* nodeWasParent, ::java::util::List* nodeWasChild) = 0;
    virtual void subscribeFailed(MaintainableScribe* scribe, ::java::util::List* failedTopics) = 0;
    virtual ::rice::p2p::scribe::rawserialization::RawScribeContent* implicitSubscribe(::java::util::List* topics) = 0;

    // Generated
    static ::java::lang::Class *class_();
};
