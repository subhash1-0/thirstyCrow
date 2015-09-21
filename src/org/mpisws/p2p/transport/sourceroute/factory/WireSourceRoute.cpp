// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/sourceroute/factory/WireSourceRoute.java
#include <org/mpisws/p2p/transport/sourceroute/factory/WireSourceRoute.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/net/InetAddress.hpp>
#include <java/net/InetSocketAddress.hpp>
#include <java/util/Iterator.hpp>
#include <java/util/List.hpp>
#include <rice/p2p/commonapi/rawserialization/OutputBuffer.hpp>

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

org::mpisws::p2p::transport::sourceroute::factory::WireSourceRoute::WireSourceRoute(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::transport::sourceroute::factory::WireSourceRoute::WireSourceRoute(::java::net::InetSocketAddress* local, ::java::net::InetSocketAddress* remote) 
    : WireSourceRoute(*static_cast< ::default_init_tag* >(0))
{
    ctor(local,remote);
}

org::mpisws::p2p::transport::sourceroute::factory::WireSourceRoute::WireSourceRoute(::java::util::List* path) 
    : WireSourceRoute(*static_cast< ::default_init_tag* >(0))
{
    ctor(path);
}

org::mpisws::p2p::transport::sourceroute::factory::WireSourceRoute::WireSourceRoute(::java::net::InetSocketAddress* address) 
    : WireSourceRoute(*static_cast< ::default_init_tag* >(0))
{
    ctor(address);
}

void org::mpisws::p2p::transport::sourceroute::factory::WireSourceRoute::ctor(::java::net::InetSocketAddress* local, ::java::net::InetSocketAddress* remote)
{
    super::ctor(local, remote);
}

void org::mpisws::p2p::transport::sourceroute::factory::WireSourceRoute::ctor(::java::util::List* path)
{
    super::ctor(static_cast< ::java::util::List* >(path));
}

void org::mpisws::p2p::transport::sourceroute::factory::WireSourceRoute::ctor(::java::net::InetSocketAddress* address)
{
    super::ctor(static_cast< ::java::lang::Object* >(address));
}

void org::mpisws::p2p::transport::sourceroute::factory::WireSourceRoute::serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */
{
    npc(buf)->writeByte(static_cast< int8_t >(npc(path)->size()));
    for (auto _i = npc(path)->iterator(); _i->hasNext(); ) {
        ::java::net::InetSocketAddress* i = java_cast< ::java::net::InetSocketAddress* >(_i->next());
        {
            npc(buf)->write(npc(npc(i)->getAddress())->getAddress(), 0, 4);
            npc(buf)->writeShort(static_cast< int16_t >(npc(i)->getPort()));
        }
    }
}

int32_t org::mpisws::p2p::transport::sourceroute::factory::WireSourceRoute::getSerializedLength()
{
    auto ret = int32_t(5);
    ret += npc(path)->size() * int32_t(6);
    return ret;
}

java::util::List* org::mpisws::p2p::transport::sourceroute::factory::WireSourceRoute::getPath()
{
    return path;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::sourceroute::factory::WireSourceRoute::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.sourceroute.factory.WireSourceRoute", 60);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::sourceroute::factory::WireSourceRoute::getClass0()
{
    return class_();
}

