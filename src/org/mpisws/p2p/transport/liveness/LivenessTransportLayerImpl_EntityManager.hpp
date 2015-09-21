// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/liveness/LivenessTransportLayerImpl.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/lang/ref/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/liveness/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::liveness::LivenessTransportLayerImpl_EntityManager
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    int32_t RTO {  };
    double RTT {  };
    double standardD {  };

public: /* protected */
    ::java::lang::ref::WeakReference* identifier {  };
    int32_t liveness {  };
    int64_t updated {  };

private:
    LivenessTransportLayerImpl_DeadChecker* pendingDeadchecker {  };

public: /* protected */
    ::java::util::Set* sockets {  };
protected:
    void ctor(::java::lang::Object* identifier);

public:
    virtual LivenessTransportLayerImpl_DeadChecker* getPending();
    virtual void setPending(LivenessTransportLayerImpl_DeadChecker* d);
    virtual void removeSocket(LivenessTransportLayerImpl_LSocket* socket);
    virtual int32_t rto();

public: /* protected */
    virtual void markAlive(::java::util::Map* options);
    virtual void markSuspected(::java::util::Map* options);
    virtual void markDead(::java::util::Map* options);
    virtual void markDeadForever(::java::util::Map* options);
    virtual void markDeadHelper(int32_t liveness, ::java::util::Map* options, bool notify);

private:
    void updateRTO(int64_t m);

public: /* protected */
    virtual bool checkLiveness(::java::util::Map* options);

public:
    ::java::lang::String* toString() override;
    virtual void destroy();

    // Generated
    LivenessTransportLayerImpl_EntityManager(LivenessTransportLayerImpl *LivenessTransportLayerImpl_this, ::java::lang::Object* identifier);
protected:
    LivenessTransportLayerImpl_EntityManager(LivenessTransportLayerImpl *LivenessTransportLayerImpl_this, const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    void init();
    LivenessTransportLayerImpl *LivenessTransportLayerImpl_this;
    virtual ::java::lang::Class* getClass0();
    friend class LivenessTransportLayerImpl;
    friend class LivenessTransportLayerImpl_openSocket_1;
    friend class LivenessTransportLayerImpl_sendMessage_2;
    friend class LivenessTransportLayerImpl_ping_3;
    friend class LivenessTransportLayerImpl_pong_4;
    friend class LivenessTransportLayerImpl_DeadChecker;
    friend class LivenessTransportLayerImpl_EntityManager_checkLiveness_1;
    friend class LivenessTransportLayerImpl_LSocket;
    friend class LivenessTransportLayerImpl_LSocket_startLivenessCheckerTimer_1;
};
