// Generated from /pastry-2.1/src/rice/p2p/scribe/maintenance/ScribeMaintenancePolicy.java

#pragma once

#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/scribe/maintenance/fwd-pastry-2.1.hpp>
#include <rice/p2p/scribe/rawserialization/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/p2p/scribe/maintenance/ScribeMaintenancePolicy.hpp>

struct default_init_tag;

class rice::p2p::scribe::maintenance::ScribeMaintenancePolicy_DefaultScribeMaintenancePolicy
    : public virtual ::java::lang::Object
    , public virtual ScribeMaintenancePolicy
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    ::rice::environment::logging::Logger* logger {  };
protected:
    void ctor(::rice::environment::Environment* environment);

public:
    void doMaintenance(MaintainableScribe* scribe) override;
    void noLongerRoot(MaintainableScribe* scribe, ::java::util::List* topics) override;
    void nodeFaulty(MaintainableScribe* scribe, ::rice::p2p::commonapi::NodeHandle* handle, ::java::util::List* nodeWasParent, ::java::util::List* nodeWasChild) override;
    void subscribeFailed(MaintainableScribe* scribe, ::java::util::List* failedTopics) override;
    ::rice::p2p::scribe::rawserialization::RawScribeContent* implicitSubscribe(::java::util::List* topics) override;

    // Generated
    ScribeMaintenancePolicy_DefaultScribeMaintenancePolicy(::rice::environment::Environment* environment);
protected:
    ScribeMaintenancePolicy_DefaultScribeMaintenancePolicy(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
    friend class ScribeMaintenancePolicy;
};
