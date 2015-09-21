// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/multiaddress/SimpleAddressStrategy.java
#include <org/mpisws/p2p/transport/multiaddress/SimpleAddressStrategy.hpp>

#include <java/io/Serializable.hpp>
#include <java/lang/ArrayIndexOutOfBoundsException.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/net/InetAddress.hpp>
#include <java/net/InetSocketAddress.hpp>
#include <java/net/SocketAddress.hpp>
#include <org/mpisws/p2p/transport/multiaddress/MultiInetSocketAddress.hpp>
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

org::mpisws::p2p::transport::multiaddress::SimpleAddressStrategy::SimpleAddressStrategy(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::transport::multiaddress::SimpleAddressStrategy::SimpleAddressStrategy()
    : SimpleAddressStrategy(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

java::net::InetSocketAddress* org::mpisws::p2p::transport::multiaddress::SimpleAddressStrategy::getAddress(MultiInetSocketAddress* local, MultiInetSocketAddress* remote)
{
    try {
        for (auto ctr = int32_t(0); ctr < npc(npc(remote)->address)->length; ctr++) {
            if(!npc(npc((*npc(local)->address)[ctr])->getAddress())->equals(static_cast< ::java::lang::Object* >(npc((*npc(remote)->address)[ctr])->getAddress()))) {
                return (*npc(remote)->address)[ctr];
            }
        }
    } catch (::java::lang::ArrayIndexOutOfBoundsException* aioobe) {
        return npc(remote)->getInnermostAddress();
    }
    return (*npc(remote)->address)[npc(npc(remote)->address)->length - int32_t(1)];
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::multiaddress::SimpleAddressStrategy::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.multiaddress.SimpleAddressStrategy", 59);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::multiaddress::SimpleAddressStrategy::getClass0()
{
    return class_();
}

