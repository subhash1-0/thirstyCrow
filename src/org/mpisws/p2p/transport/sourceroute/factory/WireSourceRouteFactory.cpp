// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/sourceroute/factory/WireSourceRouteFactory.java
#include <org/mpisws/p2p/transport/sourceroute/factory/WireSourceRouteFactory.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/net/InetAddress.hpp>
#include <java/net/InetSocketAddress.hpp>
#include <java/util/ArrayList.hpp>
#include <java/util/Collection.hpp>
#include <java/util/Collections.hpp>
#include <java/util/List.hpp>
#include <org/mpisws/p2p/transport/sourceroute/SourceRoute.hpp>
#include <org/mpisws/p2p/transport/sourceroute/factory/WireSourceRoute.hpp>
#include <rice/p2p/commonapi/rawserialization/InputBuffer.hpp>
#include <Array.hpp>

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

org::mpisws::p2p::transport::sourceroute::factory::WireSourceRouteFactory::WireSourceRouteFactory(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::transport::sourceroute::factory::WireSourceRouteFactory::WireSourceRouteFactory()
    : WireSourceRouteFactory(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

org::mpisws::p2p::transport::sourceroute::SourceRoute* org::mpisws::p2p::transport::sourceroute::factory::WireSourceRouteFactory::build(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::java::net::InetSocketAddress* localAddr, ::java::net::InetSocketAddress* lastHop) /* throws(IOException) */
{
    auto numInPath = npc(buf)->readByte();
    auto path = new ::java::util::ArrayList(static_cast< int32_t >(numInPath));
    for (auto i = int32_t(0); i < numInPath; i++) {
        auto addrBytes = new ::int8_tArray(int32_t(4));
        npc(buf)->read(addrBytes);
        auto addr = ::java::net::InetAddress::getByAddress(addrBytes);
        auto port = npc(buf)->readShort();
        npc(path)->add(static_cast< ::java::lang::Object* >(new ::java::net::InetSocketAddress(addr, int32_t(65535) & port)));
    }
    return new WireSourceRoute(static_cast< ::java::util::List* >(path));
}

org::mpisws::p2p::transport::sourceroute::SourceRoute* org::mpisws::p2p::transport::sourceroute::factory::WireSourceRouteFactory::build(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::java::lang::Object* local, ::java::lang::Object* lastHop)
{ 
    return build(buf, dynamic_cast< ::java::net::InetSocketAddress* >(local), dynamic_cast< ::java::net::InetSocketAddress* >(lastHop));
}

org::mpisws::p2p::transport::sourceroute::SourceRoute* org::mpisws::p2p::transport::sourceroute::factory::WireSourceRouteFactory::getSourceRoute(::java::util::List* route)
{
    return new WireSourceRoute(route);
}

org::mpisws::p2p::transport::sourceroute::SourceRoute* org::mpisws::p2p::transport::sourceroute::factory::WireSourceRouteFactory::reverse(::org::mpisws::p2p::transport::sourceroute::SourceRoute* route)
{
    auto temp = java_cast< WireSourceRoute* >(route);
    auto result = new ::java::util::ArrayList(static_cast< ::java::util::Collection* >(npc(temp)->getPath()));
    ::java::util::Collections::reverse(result);
    return new WireSourceRoute(static_cast< ::java::util::List* >(result));
}

org::mpisws::p2p::transport::sourceroute::SourceRoute* org::mpisws::p2p::transport::sourceroute::factory::WireSourceRouteFactory::getSourceRoute(::java::net::InetSocketAddress* local, ::java::net::InetSocketAddress* dest)
{
    return new WireSourceRoute(local, dest);
}

org::mpisws::p2p::transport::sourceroute::SourceRoute* org::mpisws::p2p::transport::sourceroute::factory::WireSourceRouteFactory::getSourceRoute(::java::lang::Object* local, ::java::lang::Object* dest)
{ 
    return getSourceRoute(dynamic_cast< ::java::net::InetSocketAddress* >(local), dynamic_cast< ::java::net::InetSocketAddress* >(dest));
}

org::mpisws::p2p::transport::sourceroute::SourceRoute* org::mpisws::p2p::transport::sourceroute::factory::WireSourceRouteFactory::getSourceRoute(::java::net::InetSocketAddress* local)
{
    return new WireSourceRoute(local);
}

org::mpisws::p2p::transport::sourceroute::SourceRoute* org::mpisws::p2p::transport::sourceroute::factory::WireSourceRouteFactory::getSourceRoute(::java::lang::Object* local)
{ 
    return getSourceRoute(dynamic_cast< ::java::net::InetSocketAddress* >(local));
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::sourceroute::factory::WireSourceRouteFactory::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.sourceroute.factory.WireSourceRouteFactory", 67);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::sourceroute::factory::WireSourceRouteFactory::getClass0()
{
    return class_();
}

