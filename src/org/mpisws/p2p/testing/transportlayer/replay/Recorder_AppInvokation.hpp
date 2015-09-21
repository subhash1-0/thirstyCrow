// Generated from /pastry-2.1/src/org/mpisws/p2p/testing/transportlayer/replay/Recorder.java

#pragma once

#include <org/mpisws/p2p/testing/transportlayer/replay/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/Runnable.hpp>

struct default_init_tag;

class org::mpisws::p2p::testing::transportlayer::replay::Recorder_AppInvokation
    : public virtual ::java::lang::Object
    , public virtual ::java::lang::Runnable
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    MyScribeClient* app {  };
protected:
    void ctor(MyScribeClient* app);

public:
    virtual void doIt() /* throws(IOException) */ = 0;
    void run() override;

    // Generated
    Recorder_AppInvokation(Recorder *Recorder_this, MyScribeClient* app);
protected:
    Recorder_AppInvokation(Recorder *Recorder_this, const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    Recorder *Recorder_this;

private:
    virtual ::java::lang::Class* getClass0();
    friend class Recorder;
    friend class Recorder_Recorder_1;
    friend class Recorder_Recorder_1_getBootstrapper_1_1;
    friend class Recorder_Recorder_2;
    friend class Recorder_SubscribeInvokation;
    friend class Recorder_PublishInvokation;
};
