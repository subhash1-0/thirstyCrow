// Generated from /pastry-2.1/src/org/mpisws/p2p/testing/transportlayer/replay/Recorder.java

#pragma once

#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/testing/transportlayer/replay/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/pastry/boot/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/pastry/boot/Bootstrapper.hpp>

struct default_init_tag;

class org::mpisws::p2p::testing::transportlayer::replay::Recorder_Recorder_1_getBootstrapper_1_1
    : public virtual ::java::lang::Object
    , public virtual ::rice::pastry::boot::Bootstrapper
{

public:
    typedef ::java::lang::Object super;
    void boot(::java::util::Collection* bootaddresses) override;

    // Generated
    Recorder_Recorder_1_getBootstrapper_1_1(Recorder_Recorder_1 *Recorder_Recorder_1_this, ::rice::pastry::PastryNode* pn, ::rice::pastry::boot::Bootstrapper* internal);
    static ::java::lang::Class *class_();
    Recorder_Recorder_1 *Recorder_Recorder_1_this;
    ::rice::pastry::PastryNode* pn;
    ::rice::pastry::boot::Bootstrapper* internal;

private:
    virtual ::java::lang::Class* getClass0();
    friend class Recorder;
    friend class Recorder_Recorder_1;
    friend class Recorder_Recorder_2;
    friend class Recorder_AppInvokation;
    friend class Recorder_SubscribeInvokation;
    friend class Recorder_PublishInvokation;
};
