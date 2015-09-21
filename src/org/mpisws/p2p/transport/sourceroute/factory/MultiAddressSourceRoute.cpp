// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/sourceroute/factory/MultiAddressSourceRoute.java
#include <org/mpisws/p2p/transport/sourceroute/factory/MultiAddressSourceRoute.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/util/Iterator.hpp>
#include <java/util/List.hpp>
#include <org/mpisws/p2p/transport/multiaddress/MultiInetSocketAddress.hpp>
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

org::mpisws::p2p::transport::sourceroute::factory::MultiAddressSourceRoute::MultiAddressSourceRoute(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::transport::sourceroute::factory::MultiAddressSourceRoute::MultiAddressSourceRoute(::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* local, ::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* remote) 
    : MultiAddressSourceRoute(*static_cast< ::default_init_tag* >(0))
{
    ctor(local,remote);
}

org::mpisws::p2p::transport::sourceroute::factory::MultiAddressSourceRoute::MultiAddressSourceRoute(::java::util::List* path) 
    : MultiAddressSourceRoute(*static_cast< ::default_init_tag* >(0))
{
    ctor(path);
}

org::mpisws::p2p::transport::sourceroute::factory::MultiAddressSourceRoute::MultiAddressSourceRoute(::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* address) 
    : MultiAddressSourceRoute(*static_cast< ::default_init_tag* >(0))
{
    ctor(address);
}

void org::mpisws::p2p::transport::sourceroute::factory::MultiAddressSourceRoute::ctor(::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* local, ::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* remote)
{
    super::ctor(local, remote);
}

void org::mpisws::p2p::transport::sourceroute::factory::MultiAddressSourceRoute::ctor(::java::util::List* path)
{
    super::ctor(static_cast< ::java::util::List* >(path));
}

void org::mpisws::p2p::transport::sourceroute::factory::MultiAddressSourceRoute::ctor(::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* address)
{
    super::ctor(static_cast< ::java::lang::Object* >(address));
}

void org::mpisws::p2p::transport::sourceroute::factory::MultiAddressSourceRoute::serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */
{
    npc(buf)->writeByte(static_cast< int8_t >(npc(path)->size()));
    if(npc(path)->size() == 2)
        return;

    for (auto _i = npc(path)->iterator(); _i->hasNext(); ) {
        ::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* i = java_cast< ::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* >(_i->next());
        {
            npc(i)->serialize(buf);
        }
    }
}

int32_t org::mpisws::p2p::transport::sourceroute::factory::MultiAddressSourceRoute::getSerializedLength()
{
    if(npc(path)->size() == 2)
        return 1;

    auto ret = int32_t(1);
    for (auto _i = npc(path)->iterator(); _i->hasNext(); ) {
        ::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* i = java_cast< ::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* >(_i->next());
        {
            ret += npc(i)->getSerializedLength();
        }
    }
    return ret;
}

java::util::List* org::mpisws::p2p::transport::sourceroute::factory::MultiAddressSourceRoute::getPath()
{
    return path;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::sourceroute::factory::MultiAddressSourceRoute::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.sourceroute.factory.MultiAddressSourceRoute", 68);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::sourceroute::factory::MultiAddressSourceRoute::getClass0()
{
    return class_();
}

