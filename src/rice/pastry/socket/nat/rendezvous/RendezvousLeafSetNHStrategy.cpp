// Generated from /pastry-2.1/src/rice/pastry/socket/nat/rendezvous/RendezvousLeafSetNHStrategy.java
#include <rice/pastry/socket/nat/rendezvous/RendezvousLeafSetNHStrategy.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/util/Collection.hpp>
#include <java/util/HashSet.hpp>
#include <org/mpisws/p2p/transport/multiaddress/MultiInetSocketAddress.hpp>
#include <rice/pastry/NodeHandle.hpp>
#include <rice/pastry/leafset/LeafSet.hpp>
#include <rice/pastry/socket/nat/rendezvous/RendezvousSocketNodeHandle.hpp>

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

rice::pastry::socket::nat::rendezvous::RendezvousLeafSetNHStrategy::RendezvousLeafSetNHStrategy(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::socket::nat::rendezvous::RendezvousLeafSetNHStrategy::RendezvousLeafSetNHStrategy(::rice::pastry::leafset::LeafSet* leafSet) 
    : RendezvousLeafSetNHStrategy(*static_cast< ::default_init_tag* >(0))
{
    ctor(leafSet);
}

void rice::pastry::socket::nat::rendezvous::RendezvousLeafSetNHStrategy::ctor(::rice::pastry::leafset::LeafSet* leafSet)
{
    super::ctor();
    this->ls = leafSet;
}

java::util::Collection* rice::pastry::socket::nat::rendezvous::RendezvousLeafSetNHStrategy::getNextHops(::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* destination)
{
    if(ls == nullptr)
        return nullptr;

    auto ret = walkLeafSet(destination, 8);
    return ret;
}

java::util::Collection* rice::pastry::socket::nat::rendezvous::RendezvousLeafSetNHStrategy::getNextHops(::java::lang::Object* destination)
{ 
    return getNextHops(dynamic_cast< ::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* >(destination));
}

java::util::Collection* rice::pastry::socket::nat::rendezvous::RendezvousLeafSetNHStrategy::walkLeafSet(::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* destination, int32_t numRequested)
{
    ::java::util::Collection* result = new ::java::util::HashSet();
    auto leafset = ls;
    for (auto i = int32_t(1); i < npc(leafset)->maxSize() / int32_t(2); i++) {
        auto snh = java_cast< RendezvousSocketNodeHandle* >(npc(leafset)->get(-i));
        if(snh != nullptr && !npc(npc(snh)->eaddress)->equals(static_cast< ::java::lang::Object* >(destination)) && npc(snh)->canContactDirect()) {
            npc(result)->add(npc(snh)->eaddress);
            if(npc(result)->size() >= numRequested)
                return result;

        }
        snh = java_cast< RendezvousSocketNodeHandle* >(npc(leafset)->get(i));
        if(snh != nullptr && !npc(npc(snh)->eaddress)->equals(static_cast< ::java::lang::Object* >(destination)) && npc(snh)->canContactDirect()) {
            npc(result)->add(npc(snh)->eaddress);
            if(npc(result)->size() >= numRequested)
                return result;

        }
    }
    return result;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::socket::nat::rendezvous::RendezvousLeafSetNHStrategy::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.socket.nat.rendezvous.RendezvousLeafSetNHStrategy", 61);
    return c;
}

java::lang::Class* rice::pastry::socket::nat::rendezvous::RendezvousLeafSetNHStrategy::getClass0()
{
    return class_();
}

