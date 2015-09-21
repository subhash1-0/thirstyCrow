// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/networkinfo/NetworkInfoTransportLayer.java
#include <org/mpisws/p2p/transport/networkinfo/NetworkInfoTransportLayer_getExternalNodes_3.hpp>

#include <java/io/IOException.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <org/mpisws/p2p/transport/P2PSocket.hpp>
#include <org/mpisws/p2p/transport/networkinfo/NetworkInfoIOException.hpp>
#include <org/mpisws/p2p/transport/networkinfo/NetworkInfoTransportLayer_getExternalNodes_3_receiveResult_3_1.hpp>
#include <org/mpisws/p2p/transport/networkinfo/NetworkInfoTransportLayer.hpp>
#include <org/mpisws/p2p/transport/util/SocketInputBuffer.hpp>
#include <rice/Continuation.hpp>

template<typename T, typename U>
static T java_cast(U* u)
{
    if(!u) return static_cast<T>(nullptr);
    auto t = dynamic_cast<T>(u);
    if(!t) throw new ::java::lang::ClassCastException();
    return t;
}

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::transport::networkinfo::NetworkInfoTransportLayer_getExternalNodes_3::NetworkInfoTransportLayer_getExternalNodes_3(NetworkInfoTransportLayer *NetworkInfoTransportLayer_this, ::rice::Continuation* c)
    : super(*static_cast< ::default_init_tag* >(0))
    , NetworkInfoTransportLayer_this(NetworkInfoTransportLayer_this)
    , c(c)
{
    clinit();
    ctor();
}

void org::mpisws::p2p::transport::networkinfo::NetworkInfoTransportLayer_getExternalNodes_3::receiveResult(::org::mpisws::p2p::transport::SocketRequestHandle* cancellable, ::org::mpisws::p2p::transport::P2PSocket* sock)
{
    auto const sib = new ::org::mpisws::p2p::transport::util::SocketInputBuffer(sock);
    try {
        (new NetworkInfoTransportLayer_getExternalNodes_3_receiveResult_3_1(this, sib, c))->receiveSelectResult(sock, true, false);
    } catch (::java::io::IOException* ioe) {
        npc(c)->receiveException(ioe);
    }
}

void org::mpisws::p2p::transport::networkinfo::NetworkInfoTransportLayer_getExternalNodes_3::receiveException(::org::mpisws::p2p::transport::SocketRequestHandle* s, ::java::lang::Exception* ex)
{
    if(dynamic_cast< ::java::io::IOException* >(ex) != nullptr)
        npc(c)->receiveException(java_cast< ::java::io::IOException* >(ex));

    npc(c)->receiveException(new NetworkInfoIOException(ex));
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::networkinfo::NetworkInfoTransportLayer_getExternalNodes_3::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::networkinfo::NetworkInfoTransportLayer_getExternalNodes_3::getClass0()
{
    return class_();
}

