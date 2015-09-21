// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/liveness/AggressiveLivenessTransportLayerImpl.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/liveness/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/liveness/LivenessTransportLayerImpl_LSocket.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::liveness::AggressiveLivenessTransportLayerImpl_ALSocket
    : public LivenessTransportLayerImpl_LSocket
{

public:
    typedef LivenessTransportLayerImpl_LSocket super;
protected:
    void ctor(LivenessTransportLayerImpl_EntityManager* manager, ::org::mpisws::p2p::transport::P2PSocket* socket, ::java::lang::Object* hardRef);

public:
    void receiveSelectResult(::org::mpisws::p2p::transport::P2PSocket* socket, bool canRead, bool canWrite) /* throws(IOException) */ override;

    // Generated
    AggressiveLivenessTransportLayerImpl_ALSocket(AggressiveLivenessTransportLayerImpl *AggressiveLivenessTransportLayerImpl_this, LivenessTransportLayerImpl_EntityManager* manager, ::org::mpisws::p2p::transport::P2PSocket* socket, ::java::lang::Object* hardRef);
protected:
    AggressiveLivenessTransportLayerImpl_ALSocket(AggressiveLivenessTransportLayerImpl *AggressiveLivenessTransportLayerImpl_this, const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    AggressiveLivenessTransportLayerImpl *AggressiveLivenessTransportLayerImpl_this;

private:
    virtual ::java::lang::Class* getClass0();
    friend class AggressiveLivenessTransportLayerImpl;
};
