// Generated from /pastry-2.1/src/rice/pastry/socket/nat/rendezvous/LeafSetRendezvousStrategy.java
#include <rice/pastry/socket/nat/rendezvous/LeafSetRendezvousStrategy.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/util/ArrayList.hpp>
#include <java/util/Iterator.hpp>
#include <rice/environment/random/RandomSource.hpp>
#include <rice/pastry/NodeHandle.hpp>
#include <rice/pastry/PastryNode.hpp>
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

rice::pastry::socket::nat::rendezvous::LeafSetRendezvousStrategy::LeafSetRendezvousStrategy(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::socket::nat::rendezvous::LeafSetRendezvousStrategy::LeafSetRendezvousStrategy(::rice::pastry::PastryNode* pn, ::rice::environment::random::RandomSource* r) 
    : LeafSetRendezvousStrategy(*static_cast< ::default_init_tag* >(0))
{
    ctor(pn,r);
}

void rice::pastry::socket::nat::rendezvous::LeafSetRendezvousStrategy::ctor(::rice::pastry::PastryNode* pn, ::rice::environment::random::RandomSource* r)
{
    super::ctor();
    this->pn = pn;
    this->random = r;
}

rice::pastry::socket::nat::rendezvous::RendezvousSocketNodeHandle* rice::pastry::socket::nat::rendezvous::LeafSetRendezvousStrategy::getRendezvousPoint(RendezvousSocketNodeHandle* dest, ::java::util::Map* options)
{
    auto choiceSet = new ::java::util::ArrayList();
    for (auto _i = npc(npc(pn)->getLeafSet())->iterator(); _i->hasNext(); ) {
        ::rice::pastry::NodeHandle* nh = java_cast< ::rice::pastry::NodeHandle* >(_i->next());
        {
            auto rnh = java_cast< RendezvousSocketNodeHandle* >(nh);
            if(npc(rnh)->canContactDirect()) {
                npc(choiceSet)->add(static_cast< ::java::lang::Object* >(rnh));
            }
        }
    }
    if(npc(choiceSet)->size() == 0) {
        return nullptr;
    }
    return java_cast< RendezvousSocketNodeHandle* >(npc(choiceSet)->get(npc(random)->nextInt(npc(choiceSet)->size())));
}

java::lang::Object* rice::pastry::socket::nat::rendezvous::LeafSetRendezvousStrategy::getRendezvousPoint(::java::lang::Object* dest, ::java::util::Map* options)
{ 
    return getRendezvousPoint(dynamic_cast< RendezvousSocketNodeHandle* >(dest), options);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::socket::nat::rendezvous::LeafSetRendezvousStrategy::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.socket.nat.rendezvous.LeafSetRendezvousStrategy", 59);
    return c;
}

java::lang::Class* rice::pastry::socket::nat::rendezvous::LeafSetRendezvousStrategy::getClass0()
{
    return class_();
}

