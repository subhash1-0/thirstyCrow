// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/networkinfo/NetworkInfoTransportLayer.java
#include <org/mpisws/p2p/transport/networkinfo/NetworkInfoTransportLayer_verifyConnectivity_12.hpp>

#include <java/lang/Long.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/util/Map.hpp>
#include <org/mpisws/p2p/transport/networkinfo/NetworkInfoTransportLayer.hpp>

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
org::mpisws::p2p::transport::networkinfo::NetworkInfoTransportLayer_verifyConnectivity_12::NetworkInfoTransportLayer_verifyConnectivity_12(NetworkInfoTransportLayer *NetworkInfoTransportLayer_this, int64_t uid)
    : super(*static_cast< ::default_init_tag* >(0))
    , NetworkInfoTransportLayer_this(NetworkInfoTransportLayer_this)
    , uid(uid)
{
    clinit();
    ctor();
}

bool org::mpisws::p2p::transport::networkinfo::NetworkInfoTransportLayer_verifyConnectivity_12::cancel()
{
    {
        synchronized synchronized_0(NetworkInfoTransportLayer_this->verifyConnectionRequests);
        {
            npc(NetworkInfoTransportLayer_this->verifyConnectionRequests)->remove(::java::lang::Long::valueOf(uid));
        }
    }
    return true;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::networkinfo::NetworkInfoTransportLayer_verifyConnectivity_12::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::networkinfo::NetworkInfoTransportLayer_verifyConnectivity_12::getClass0()
{
    return class_();
}

