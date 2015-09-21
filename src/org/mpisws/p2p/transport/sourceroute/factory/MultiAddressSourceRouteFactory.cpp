// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/sourceroute/factory/MultiAddressSourceRouteFactory.java
#include <org/mpisws/p2p/transport/sourceroute/factory/MultiAddressSourceRouteFactory.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/util/ArrayList.hpp>
#include <java/util/Collection.hpp>
#include <java/util/Collections.hpp>
#include <java/util/List.hpp>
#include <org/mpisws/p2p/transport/multiaddress/MultiInetSocketAddress.hpp>
#include <org/mpisws/p2p/transport/sourceroute/SourceRoute.hpp>
#include <org/mpisws/p2p/transport/sourceroute/factory/MultiAddressSourceRoute.hpp>
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

org::mpisws::p2p::transport::sourceroute::factory::MultiAddressSourceRouteFactory::MultiAddressSourceRouteFactory(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::transport::sourceroute::factory::MultiAddressSourceRouteFactory::MultiAddressSourceRouteFactory()
    : MultiAddressSourceRouteFactory(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

org::mpisws::p2p::transport::sourceroute::SourceRoute* org::mpisws::p2p::transport::sourceroute::factory::MultiAddressSourceRouteFactory::build(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* local, ::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* lastHop) /* throws(IOException) */
{
    auto numInPath = npc(buf)->readByte();
    if(numInPath == 2) {
        return new MultiAddressSourceRoute(lastHop, local);
    }
    auto path = new ::java::util::ArrayList(static_cast< int32_t >(numInPath));
    for (auto i = int32_t(0); i < numInPath; i++) {
        npc(path)->add(static_cast< ::java::lang::Object* >(::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress::build(buf)));
    }
    return new MultiAddressSourceRoute(static_cast< ::java::util::List* >(path));
}

org::mpisws::p2p::transport::sourceroute::SourceRoute* org::mpisws::p2p::transport::sourceroute::factory::MultiAddressSourceRouteFactory::build(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::java::lang::Object* local, ::java::lang::Object* lastHop)
{ 
    return build(buf, dynamic_cast< ::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* >(local), dynamic_cast< ::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* >(lastHop));
}

org::mpisws::p2p::transport::sourceroute::SourceRoute* org::mpisws::p2p::transport::sourceroute::factory::MultiAddressSourceRouteFactory::getSourceRoute(::java::util::List* route)
{
    return new MultiAddressSourceRoute(route);
}

org::mpisws::p2p::transport::sourceroute::SourceRoute* org::mpisws::p2p::transport::sourceroute::factory::MultiAddressSourceRouteFactory::reverse(::org::mpisws::p2p::transport::sourceroute::SourceRoute* route)
{
    auto temp = java_cast< MultiAddressSourceRoute* >(route);
    auto result = new ::java::util::ArrayList(static_cast< ::java::util::Collection* >(npc(temp)->getPath()));
    ::java::util::Collections::reverse(result);
    return new MultiAddressSourceRoute(static_cast< ::java::util::List* >(result));
}

org::mpisws::p2p::transport::sourceroute::SourceRoute* org::mpisws::p2p::transport::sourceroute::factory::MultiAddressSourceRouteFactory::getSourceRoute(::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* local, ::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* dest)
{
    return new MultiAddressSourceRoute(local, dest);
}

org::mpisws::p2p::transport::sourceroute::SourceRoute* org::mpisws::p2p::transport::sourceroute::factory::MultiAddressSourceRouteFactory::getSourceRoute(::java::lang::Object* local, ::java::lang::Object* dest)
{ 
    return getSourceRoute(dynamic_cast< ::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* >(local), dynamic_cast< ::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* >(dest));
}

org::mpisws::p2p::transport::sourceroute::SourceRoute* org::mpisws::p2p::transport::sourceroute::factory::MultiAddressSourceRouteFactory::getSourceRoute(::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* local)
{
    return new MultiAddressSourceRoute(local);
}

org::mpisws::p2p::transport::sourceroute::SourceRoute* org::mpisws::p2p::transport::sourceroute::factory::MultiAddressSourceRouteFactory::getSourceRoute(::java::lang::Object* local)
{ 
    return getSourceRoute(dynamic_cast< ::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* >(local));
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::sourceroute::factory::MultiAddressSourceRouteFactory::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.sourceroute.factory.MultiAddressSourceRouteFactory", 75);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::sourceroute::factory::MultiAddressSourceRouteFactory::getClass0()
{
    return class_();
}

