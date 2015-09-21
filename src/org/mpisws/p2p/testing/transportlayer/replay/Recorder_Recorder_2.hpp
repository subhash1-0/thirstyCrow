// Generated from /pastry-2.1/src/org/mpisws/p2p/testing/transportlayer/replay/Recorder.java

#pragma once

#include <java/net/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/testing/transportlayer/replay/fwd-pastry-2.1.hpp>
#include <rice/pastry/socket/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/Runnable.hpp>

struct default_init_tag;

class org::mpisws::p2p::testing::transportlayer::replay::Recorder_Recorder_2
    : public virtual ::java::lang::Object
    , public virtual ::java::lang::Runnable
{

public:
    typedef ::java::lang::Object super;
    void run() override;

    // Generated
    Recorder_Recorder_2(Recorder *Recorder_this, ::rice::pastry::socket::SocketPastryNodeFactory* factory, ::java::util::ArrayList* nodeContainer, ::java::net::InetSocketAddress* bootaddress);
    static ::java::lang::Class *class_();
    Recorder *Recorder_this;
    ::rice::pastry::socket::SocketPastryNodeFactory* factory;
    ::java::util::ArrayList* nodeContainer;
    ::java::net::InetSocketAddress* bootaddress;

private:
    virtual ::java::lang::Class* getClass0();
    friend class Recorder;
    friend class Recorder_Recorder_1;
    friend class Recorder_Recorder_1_getBootstrapper_1_1;
    friend class Recorder_AppInvokation;
    friend class Recorder_SubscribeInvokation;
    friend class Recorder_PublishInvokation;
};
