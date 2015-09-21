// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/replay/record/RecordSM.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/replay/record/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/fwd-pastry-2.1.hpp>
#include <rice/environment/random/fwd-pastry-2.1.hpp>
#include <rice/environment/time/fwd-pastry-2.1.hpp>
#include <rice/environment/time/simulated/fwd-pastry-2.1.hpp>
#include <rice/selector/fwd-pastry-2.1.hpp>
#include <rice/selector/SelectorManager.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::peerreview::replay::record::RecordSM
    : public ::rice::selector::SelectorManager
{

public:
    typedef ::rice::selector::SelectorManager super;

public: /* package */
    ::rice::environment::time::simulated::DirectTimeSource* simTime {  };
    ::rice::environment::time::TimeSource* realTime {  };
protected:
    void ctor(::java::lang::String* instance, ::rice::environment::time::TimeSource* realTime, ::rice::environment::time::simulated::DirectTimeSource* simTime, ::rice::environment::logging::LogManager* log, ::rice::environment::random::RandomSource* rs);

public: /* protected */
    void addTask(::rice::selector::TimerTask* task) override;
    void executeDueTasks() override;
    void doInvocations() override;

    // Generated

public:
    RecordSM(::java::lang::String* instance, ::rice::environment::time::TimeSource* realTime, ::rice::environment::time::simulated::DirectTimeSource* simTime, ::rice::environment::logging::LogManager* log, ::rice::environment::random::RandomSource* rs);
protected:
    RecordSM(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
