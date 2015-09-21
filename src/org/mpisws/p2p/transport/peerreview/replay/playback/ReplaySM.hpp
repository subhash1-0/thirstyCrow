// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/replay/playback/ReplaySM.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/replay/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/replay/playback/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/fwd-pastry-2.1.hpp>
#include <rice/environment/time/simulated/fwd-pastry-2.1.hpp>
#include <rice/selector/fwd-pastry-2.1.hpp>
#include <rice/selector/SelectorManager.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::peerreview::replay::playback::ReplaySM
    : public ::rice::selector::SelectorManager
{

public:
    typedef ::rice::selector::SelectorManager super;

public: /* package */
    ::org::mpisws::p2p::transport::peerreview::replay::Verifier* verifier {  };
    ::rice::environment::time::simulated::DirectTimeSource* simTime {  };
protected:
    void ctor(::java::lang::String* instance, ::rice::environment::time::simulated::DirectTimeSource* timeSource, ::rice::environment::logging::LogManager* log);

public:
    virtual void setVerifier(::org::mpisws::p2p::transport::peerreview::replay::Verifier* v);
    void setEnvironment(::rice::environment::Environment* env) override;

public: /* protected */
    void addTask(::rice::selector::TimerTask* task) override;

public:
    virtual bool makeProgress();

public: /* protected */
    virtual bool isSuccess();
    void doInvocations() override;

    // Generated

public:
    ReplaySM(::java::lang::String* instance, ::rice::environment::time::simulated::DirectTimeSource* timeSource, ::rice::environment::logging::LogManager* log);
protected:
    ReplaySM(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
