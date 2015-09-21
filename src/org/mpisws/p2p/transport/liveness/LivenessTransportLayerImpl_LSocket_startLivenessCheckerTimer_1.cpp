// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/liveness/LivenessTransportLayerImpl.java
#include <org/mpisws/p2p/transport/liveness/LivenessTransportLayerImpl_LSocket_startLivenessCheckerTimer_1.hpp>

#include <java/lang/NullPointerException.hpp>
#include <org/mpisws/p2p/transport/liveness/LivenessTransportLayerImpl_EntityManager.hpp>
#include <org/mpisws/p2p/transport/liveness/LivenessTransportLayerImpl_LSocket.hpp>
#include <rice/selector/TimerTask.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

extern void lock(::java::lang::Object *);
extern void unlock(::java::lang::Object *);

namespace
{
    struct synchronized
    {
        synchronized(::java::lang::Object *o) : o(o) { ::lock(o); }
        ~synchronized() { ::unlock(o); }
    private:
        synchronized(const synchronized&); synchronized& operator=(const synchronized&);
        ::java::lang::Object *o;
    };
}
org::mpisws::p2p::transport::liveness::LivenessTransportLayerImpl_LSocket_startLivenessCheckerTimer_1::LivenessTransportLayerImpl_LSocket_startLivenessCheckerTimer_1(LivenessTransportLayerImpl_LSocket *LivenessTransportLayerImpl_LSocket_this)
    : super(*static_cast< ::default_init_tag* >(0))
    , LivenessTransportLayerImpl_LSocket_this(LivenessTransportLayerImpl_LSocket_this)
{
    clinit();
    ctor();
}

void org::mpisws::p2p::transport::liveness::LivenessTransportLayerImpl_LSocket_startLivenessCheckerTimer_1::run()
{
    {
        synchronized synchronized_0(LivenessTransportLayerImpl_LSocket_this);
        {
            if(LivenessTransportLayerImpl_LSocket_this->livenessCheckerTimer == static_cast< ::rice::selector::TimerTask* >(this))
                LivenessTransportLayerImpl_LSocket_this->livenessCheckerTimer = nullptr;

        }
    }
    npc(LivenessTransportLayerImpl_LSocket_this->manager)->checkLiveness(LivenessTransportLayerImpl_LSocket_this->options);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::liveness::LivenessTransportLayerImpl_LSocket_startLivenessCheckerTimer_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::liveness::LivenessTransportLayerImpl_LSocket_startLivenessCheckerTimer_1::getClass0()
{
    return class_();
}

