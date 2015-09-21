// Generated from /pastry-2.1/src/rice/pastry/socket/nat/rendezvous/RendezvousSocketPastryNodeFactory.java
#include <rice/pastry/socket/nat/rendezvous/RendezvousSocketPastryNodeFactory_getBootstrapper_3.hpp>

#include <java/lang/Boolean.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/util/ArrayList.hpp>
#include <java/util/Iterator.hpp>
#include <java/util/Observable.hpp>
#include <org/mpisws/p2p/transport/rendezvous/PilotManager.hpp>
#include <rice/pastry/socket/nat/rendezvous/RendezvousSocketNodeHandle.hpp>
#include <rice/pastry/socket/nat/rendezvous/RendezvousSocketPastryNodeFactory.hpp>
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

extern void lock(::java::lang::Object *);
extern void unlock(::java::lang::Object *);

namespace
{
    struct synchronized
    {
        synchronized(::java::lang::Object *o) : o(o) { ::lock(o); }
        ~synchronized() { ::unlock(o); }
    private:
        synchronized(const synchronized&); synchronized& operator=(const synchronized&);
        ::java::lang::Object *o;
    };
}
rice::pastry::socket::nat::rendezvous::RendezvousSocketPastryNodeFactory_getBootstrapper_3::RendezvousSocketPastryNodeFactory_getBootstrapper_3(RendezvousSocketPastryNodeFactory *RendezvousSocketPastryNodeFactory_this, ::java::util::ArrayList* closeMeWhenReady, ::boolArray* booted, ::org::mpisws::p2p::transport::rendezvous::PilotManager* manager)
    : super(*static_cast< ::default_init_tag* >(0))
    , RendezvousSocketPastryNodeFactory_this(RendezvousSocketPastryNodeFactory_this)
    , closeMeWhenReady(closeMeWhenReady)
    , booted(booted)
    , manager(manager)
{
    clinit();
    ctor();
}

void rice::pastry::socket::nat::rendezvous::RendezvousSocketPastryNodeFactory_getBootstrapper_3::update(::java::util::Observable* o, ::java::lang::Object* arg)
{
    if(dynamic_cast< ::java::lang::Boolean* >(arg) != nullptr) {
        if(npc((java_cast< ::java::lang::Boolean* >(arg)))->booleanValue()) {
            ::java::util::List* temp;
            {
                synchronized synchronized_0(closeMeWhenReady);
                {
                    (*booted)[int32_t(0)] = true;
                }
            }
            for (auto _i = npc(closeMeWhenReady)->iterator(); _i->hasNext(); ) {
                RendezvousSocketNodeHandle* nh = java_cast< RendezvousSocketNodeHandle* >(_i->next());
                {
                    npc(manager)->closePilot(nh);
                }
            }
            npc(closeMeWhenReady)->clear();
            npc(o)->deleteObserver(this);
        }
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::socket::nat::rendezvous::RendezvousSocketPastryNodeFactory_getBootstrapper_3::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::pastry::socket::nat::rendezvous::RendezvousSocketPastryNodeFactory_getBootstrapper_3::getClass0()
{
    return class_();
}

