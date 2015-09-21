// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/networkinfo/NetworkInfoTransportLayer.java
#include <org/mpisws/p2p/transport/networkinfo/NetworkInfoTransportLayer_getMyInetAddress_1_receiveResult_1_1.hpp>

#include <java/io/IOException.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/net/InetSocketAddress.hpp>
#include <java/util/Map.hpp>
#include <org/mpisws/p2p/transport/P2PSocket.hpp>
#include <org/mpisws/p2p/transport/networkinfo/NetworkInfoIOException.hpp>
#include <org/mpisws/p2p/transport/networkinfo/NetworkInfoTransportLayer_getMyInetAddress_1.hpp>
#include <org/mpisws/p2p/transport/networkinfo/NetworkInfoTransportLayer.hpp>
#include <org/mpisws/p2p/transport/simpleidentity/InetSocketAddressSerializer.hpp>
#include <org/mpisws/p2p/transport/util/InsufficientBytesException.hpp>
#include <org/mpisws/p2p/transport/util/SocketInputBuffer.hpp>
#include <rice/Continuation.hpp>
#include <rice/p2p/commonapi/rawserialization/InputBuffer.hpp>

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

org::mpisws::p2p::transport::networkinfo::NetworkInfoTransportLayer_getMyInetAddress_1_receiveResult_1_1::NetworkInfoTransportLayer_getMyInetAddress_1_receiveResult_1_1(NetworkInfoTransportLayer_getMyInetAddress_1 *NetworkInfoTransportLayer_getMyInetAddress_1_this, ::org::mpisws::p2p::transport::util::SocketInputBuffer* sib, ::rice::Continuation* c)
    : super(*static_cast< ::default_init_tag* >(0))
    , NetworkInfoTransportLayer_getMyInetAddress_1_this(NetworkInfoTransportLayer_getMyInetAddress_1_this)
    , sib(sib)
    , c(c)
{
    clinit();
    ctor();
}

void org::mpisws::p2p::transport::networkinfo::NetworkInfoTransportLayer_getMyInetAddress_1_receiveResult_1_1::receiveSelectResult(::org::mpisws::p2p::transport::P2PSocket* socket, bool canRead, bool canWrite) /* throws(IOException) */
{
    try {
        auto addr = npc(NetworkInfoTransportLayer_getMyInetAddress_1_this->NetworkInfoTransportLayer_this->addrSerializer)->deserialize(static_cast< ::rice::p2p::commonapi::rawserialization::InputBuffer* >(sib), static_cast< ::java::net::InetSocketAddress* >(nullptr), static_cast< ::java::util::Map* >(nullptr));
        npc(c)->receiveResult(addr);
    } catch (::org::mpisws::p2p::transport::util::InsufficientBytesException* ibe) {
        npc(socket)->register_(true, false, this);
    } catch (::java::io::IOException* e) {
        npc(c)->receiveException(e);
    }
}

void org::mpisws::p2p::transport::networkinfo::NetworkInfoTransportLayer_getMyInetAddress_1_receiveResult_1_1::receiveException(::org::mpisws::p2p::transport::P2PSocket* socket, ::java::lang::Exception* ioe)
{
    if(dynamic_cast< ::java::io::IOException* >(ioe) != nullptr)
        npc(c)->receiveException(java_cast< ::java::io::IOException* >(ioe));

    npc(c)->receiveException(new NetworkInfoIOException(ioe));
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::networkinfo::NetworkInfoTransportLayer_getMyInetAddress_1_receiveResult_1_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::networkinfo::NetworkInfoTransportLayer_getMyInetAddress_1_receiveResult_1_1::getClass0()
{
    return class_();
}

