// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/replay/playback/ReplayLayer.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/replay/playback/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/SocketRequestHandle.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::peerreview::replay::playback::ReplayLayer_openSocket_1
    : public virtual ::java::lang::Object
    , public virtual ::org::mpisws::p2p::transport::SocketRequestHandle
{

public:
    typedef ::java::lang::Object super;
    ::java::lang::Object* getIdentifier() override;
    ::java::util::Map* getOptions() override;
    bool cancel() override;

    // Generated
    ReplayLayer_openSocket_1(ReplayLayer *ReplayLayer_this, ::java::lang::Object* i, ::java::util::Map* options);
    static ::java::lang::Class *class_();
    ReplayLayer *ReplayLayer_this;
    ::java::lang::Object* i;
    ::java::util::Map* options;

private:
    virtual ::java::lang::Class* getClass0();
    friend class ReplayLayer;
};
