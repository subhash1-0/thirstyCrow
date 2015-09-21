// Generated from /pastry-2.1/src/rice/pastry/testing/rendezvous/VerifyConnectivity.java
#include <rice/pastry/testing/rendezvous/VerifyConnectivity_main_1_receiveResult_1_1.hpp>

#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/net/InetSocketAddress.hpp>
#include <java/net/SocketAddress.hpp>
#include <java/util/Collections.hpp>
#include <java/util/Set.hpp>
#include <org/mpisws/p2p/transport/multiaddress/MultiInetSocketAddress.hpp>
#include <rice/pastry/socket/SocketPastryNodeFactory.hpp>
#include <rice/pastry/socket/nat/connectivityverifiier/ConnectivityVerifier.hpp>
#include <rice/pastry/testing/rendezvous/VerifyConnectivity_main_1.hpp>
#include <rice/pastry/testing/rendezvous/VerifyConnectivity_main_1_receiveResult_1_1_run_1_1_1.hpp>
#include <SubArray.hpp>
#include <ObjectArray.hpp>

template<typename ComponentType, typename... Bases> struct SubArray;
namespace java
{
    namespace io
    {
typedef ::SubArray< ::java::io::Serializable, ::java::lang::ObjectArray > SerializableArray;
    } // io

    namespace net
    {
typedef ::SubArray< ::java::net::SocketAddress, ::java::lang::ObjectArray, ::java::io::SerializableArray > SocketAddressArray;
typedef ::SubArray< ::java::net::InetSocketAddress, SocketAddressArray > InetSocketAddressArray;
    } // net
} // java

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::pastry::testing::rendezvous::VerifyConnectivity_main_1_receiveResult_1_1::VerifyConnectivity_main_1_receiveResult_1_1(VerifyConnectivity_main_1 *VerifyConnectivity_main_1_this, ::java::net::InetAddress* result, int32_t externalPort, ::rice::pastry::socket::SocketPastryNodeFactory* factory, ::rice::pastry::socket::nat::connectivityverifiier::ConnectivityVerifier* verifier, ::java::net::InetSocketAddress* bootaddress)
    : super(*static_cast< ::default_init_tag* >(0))
    , VerifyConnectivity_main_1_this(VerifyConnectivity_main_1_this)
    , result(result)
    , externalPort(externalPort)
    , factory(factory)
    , verifier(verifier)
    , bootaddress(bootaddress)
{
    clinit();
    ctor();
}

void rice::pastry::testing::rendezvous::VerifyConnectivity_main_1_receiveResult_1_1::run()
{
    auto addrs = new ::java::net::InetSocketAddressArray(int32_t(2));
    addrs->set(int32_t(0), new ::java::net::InetSocketAddress(result, externalPort));
    addrs->set(int32_t(1), npc(factory)->getNextInetSocketAddress());
    auto local = new ::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress(addrs);
    npc(verifier)->verifyConnectivity(local, ::java::util::Collections::singleton(bootaddress), new VerifyConnectivity_main_1_receiveResult_1_1_run_1_1_1(this));
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::testing::rendezvous::VerifyConnectivity_main_1_receiveResult_1_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::pastry::testing::rendezvous::VerifyConnectivity_main_1_receiveResult_1_1::getClass0()
{
    return class_();
}

