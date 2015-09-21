// Generated from /pastry-2.1/src/rice/pastry/socket/nat/rendezvous/LeafSetPilotFinder.java
#include <rice/pastry/socket/nat/rendezvous/LeafSetPilotFinder.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/IllegalArgumentException.hpp>
#include <java/lang/Math.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/util/ArrayList.hpp>
#include <java/util/Collection.hpp>
#include <java/util/HashSet.hpp>
#include <java/util/Iterator.hpp>
#include <rice/environment/Environment.hpp>
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

rice::pastry::socket::nat::rendezvous::LeafSetPilotFinder::LeafSetPilotFinder(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::socket::nat::rendezvous::LeafSetPilotFinder::LeafSetPilotFinder(::rice::pastry::PastryNode* pn) 
    : LeafSetPilotFinder(*static_cast< ::default_init_tag* >(0))
{
    ctor(pn);
}

void rice::pastry::socket::nat::rendezvous::LeafSetPilotFinder::ctor(::rice::pastry::PastryNode* pn)
{
    super::ctor();
    this->leafSet = npc(pn)->getLeafSet();
    this->random = npc(npc(pn)->getEnvironment())->getRandomSource();
}

rice::pastry::socket::nat::rendezvous::RendezvousSocketNodeHandle* rice::pastry::socket::nat::rendezvous::LeafSetPilotFinder::findPilot(RendezvousSocketNodeHandle* dest)
{
    if(npc(dest)->canContactDirect())
        throw new ::java::lang::IllegalArgumentException(::java::lang::StringBuilder().append(u"Dest "_j)->append(static_cast< ::java::lang::Object* >(dest))
            ->append(u" is not firewalled."_j)->toString());

    if(npc(leafSet)->contains(dest)) {
        auto possibleIntermediates = new ::java::util::HashSet();
        if(npc(leafSet)->overlaps()) {
            for (auto _i = npc(leafSet)->iterator(); _i->hasNext(); ) {
                ::rice::pastry::NodeHandle* foo = java_cast< ::rice::pastry::NodeHandle* >(_i->next());
                {
                    auto nh = java_cast< RendezvousSocketNodeHandle* >(foo);
                    if(npc(nh)->canContactDirect())
                        npc(possibleIntermediates)->add(static_cast< ::java::lang::Object* >(nh));

                }
            }
        } else {
            auto index = npc(leafSet)->getIndex(dest);
            auto maxDist = npc(leafSet)->maxSize() / int32_t(2);
            for (auto i = -npc(leafSet)->ccwSize(); i <= npc(leafSet)->cwSize(); i++) {
                if(i != 0) {
                    if(::java::lang::Math::abs(index - i) <= maxDist) {
                        auto nh = java_cast< RendezvousSocketNodeHandle* >(npc(leafSet)->get(i));
                        if(npc(nh)->canContactDirect())
                            npc(possibleIntermediates)->add(static_cast< ::java::lang::Object* >(nh));

                    }
                }
            }
        }
        auto list = new ::java::util::ArrayList(static_cast< ::java::util::Collection* >(possibleIntermediates));
        if(npc(list)->isEmpty())
            return nullptr;

        return java_cast< RendezvousSocketNodeHandle* >(npc(list)->get(npc(random)->nextInt(npc(list)->size())));
    } else {
        return nullptr;
    }
}

java::lang::Object* rice::pastry::socket::nat::rendezvous::LeafSetPilotFinder::findPilot(::java::lang::Object* i)
{ 
    return findPilot(dynamic_cast< RendezvousSocketNodeHandle* >(i));
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::socket::nat::rendezvous::LeafSetPilotFinder::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.socket.nat.rendezvous.LeafSetPilotFinder", 52);
    return c;
}

java::lang::Class* rice::pastry::socket::nat::rendezvous::LeafSetPilotFinder::getClass0()
{
    return class_();
}

