// Generated from /pastry-2.1/src/org/mpisws/p2p/testing/transportlayer/replay/Recorder.java

#pragma once

#include <org/mpisws/p2p/testing/transportlayer/replay/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/testing/transportlayer/replay/Recorder_AppInvokation.hpp>

struct default_init_tag;

class org::mpisws::p2p::testing::transportlayer::replay::Recorder_SubscribeInvokation
    : public Recorder_AppInvokation
{

public:
    typedef Recorder_AppInvokation super;
protected:
    void ctor(MyScribeClient* app);

public:
    void doIt() /* throws(IOException) */ override;

    // Generated
    Recorder_SubscribeInvokation(Recorder *Recorder_this, MyScribeClient* app);
protected:
    Recorder_SubscribeInvokation(Recorder *Recorder_this, const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
    friend class Recorder;
    friend class Recorder_Recorder_1;
    friend class Recorder_Recorder_1_getBootstrapper_1_1;
    friend class Recorder_Recorder_2;
    friend class Recorder_AppInvokation;
    friend class Recorder_PublishInvokation;
};
