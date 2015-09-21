// Generated from /pastry-2.1/src/org/mpisws/p2p/testing/transportlayer/replay/Replayer.java

#pragma once

#include <org/mpisws/p2p/testing/transportlayer/replay/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/pastry/NodeIdFactory.hpp>

struct default_init_tag;

class org::mpisws::p2p::testing::transportlayer::replay::Replayer_Replayer_1
    : public virtual ::java::lang::Object
    , public virtual ::rice::pastry::NodeIdFactory
{

public:
    typedef ::java::lang::Object super;
    ::rice::pastry::Id* generateNodeId() override;

    // Generated
    Replayer_Replayer_1(Replayer *Replayer_this, ::rice::pastry::Id* id);
    static ::java::lang::Class *class_();
    Replayer *Replayer_this;
    ::rice::pastry::Id* id;

private:
    virtual ::java::lang::Class* getClass0();
    friend class Replayer;
    friend class Replayer_Replayer_2;
};
