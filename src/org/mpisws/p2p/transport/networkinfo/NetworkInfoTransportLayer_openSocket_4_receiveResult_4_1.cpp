// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/networkinfo/NetworkInfoTransportLayer.java
#include <org/mpisws/p2p/transport/networkinfo/NetworkInfoTransportLayer_openSocket_4_receiveResult_4_1.hpp>

#include <java/lang/NullPointerException.hpp>
#include <org/mpisws/p2p/transport/P2PSocket.hpp>
#include <org/mpisws/p2p/transport/networkinfo/NetworkInfoTransportLayer_openSocket_4.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::transport::networkinfo::NetworkInfoTransportLayer_openSocket_4_receiveResult_4_1::NetworkInfoTransportLayer_openSocket_4_receiveResult_4_1(NetworkInfoTransportLayer_openSocket_4 *NetworkInfoTransportLayer_openSocket_4_this, ::org::mpisws::p2p::transport::P2PSocket* result)
    : super(*static_cast< ::default_init_tag* >(0))
    , NetworkInfoTransportLayer_openSocket_4_this(NetworkInfoTransportLayer_openSocket_4_this)
    , result(result)
{
    clinit();
    ctor();
}

bool org::mpisws::p2p::transport::networkinfo::NetworkInfoTransportLayer_openSocket_4_receiveResult_4_1::cancel()
{
    npc(result)->close();
    return true;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::networkinfo::NetworkInfoTransportLayer_openSocket_4_receiveResult_4_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::networkinfo::NetworkInfoTransportLayer_openSocket_4_receiveResult_4_1::getClass0()
{
    return class_();
}

