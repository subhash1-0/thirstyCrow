// Generated from /pastry-2.1/src/rice/pastry/socket/nat/rendezvous/RendezvousPNSApplication.java
#include <rice/pastry/socket/nat/rendezvous/RendezvousPNSApplication.hpp>

#include <java/lang/Class.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/IllegalArgumentException.hpp>
#include <java/lang/Integer.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/util/ArrayList.hpp>
#include <java/util/Collection.hpp>
#include <java/util/Iterator.hpp>
#include <java/util/List.hpp>
#include <org/mpisws/p2p/transport/rendezvous/ContactDirectStrategy.hpp>
#include <rice/Continuation.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/LogManager.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/p2p/commonapi/Cancellable.hpp>
#include <rice/pastry/NodeHandle.hpp>
#include <rice/pastry/PastryNode.hpp>
#include <rice/pastry/leafset/LeafSet.hpp>
#include <rice/pastry/socket/nat/rendezvous/NodeIsFirewalledException.hpp>
#include <rice/pastry/socket/nat/rendezvous/RendezvousPNSApplication_getLeafSet_1.hpp>
#include <rice/pastry/socket/nat/rendezvous/RendezvousPNSApplication_getRouteRow_2.hpp>
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

rice::pastry::socket::nat::rendezvous::RendezvousPNSApplication::RendezvousPNSApplication(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::socket::nat::rendezvous::RendezvousPNSApplication::RendezvousPNSApplication(::rice::pastry::PastryNode* pn, ::org::mpisws::p2p::transport::rendezvous::ContactDirectStrategy* contactDirectStrategy) 
    : RendezvousPNSApplication(*static_cast< ::default_init_tag* >(0))
{
    ctor(pn,contactDirectStrategy);
}

void rice::pastry::socket::nat::rendezvous::RendezvousPNSApplication::ctor(::rice::pastry::PastryNode* pn, ::org::mpisws::p2p::transport::rendezvous::ContactDirectStrategy* contactDirectStrategy)
{
    super::ctor(pn, npc(npc(npc(pn)->getEnvironment())->getLogManager())->getLogger(RendezvousPNSApplication::class_(), nullptr));
    this->contactDirectStrategy = contactDirectStrategy;
    if(contactDirectStrategy == nullptr)
        throw new ::java::lang::IllegalArgumentException(u"Need contactDirectStrategy was null"_j);

}

bool rice::pastry::socket::nat::rendezvous::RendezvousPNSApplication::ignore(::rice::pastry::NodeHandle* handle, ::rice::Continuation* c)
{
    if(useHandle(handle))
        return false;

    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(::java::lang::StringBuilder().append(u"PNS not using firewalled node "_j)->append(static_cast< ::java::lang::Object* >(handle))->toString());

    npc(c)->receiveException(new NodeIsFirewalledException(handle));
    return true;
}

bool rice::pastry::socket::nat::rendezvous::RendezvousPNSApplication::useHandle(::rice::pastry::NodeHandle* handle)
{
    auto rsnh = java_cast< RendezvousSocketNodeHandle* >(handle);
    return npc(contactDirectStrategy)->canContactDirect(rsnh);
}

java::util::List* rice::pastry::socket::nat::rendezvous::RendezvousPNSApplication::getNearHandlesHelper(::java::util::List* handles)
{
    auto contactDirect = new ::java::util::ArrayList();
    auto notContactDirect = new ::java::util::ArrayList();
    for (auto _i = npc(handles)->iterator(); _i->hasNext(); ) {
        ::rice::pastry::NodeHandle* foo = java_cast< ::rice::pastry::NodeHandle* >(_i->next());
        {
            auto rsnh = java_cast< RendezvousSocketNodeHandle* >(foo);
            if(npc(rsnh)->canContactDirect()) {
                npc(contactDirect)->add(static_cast< ::java::lang::Object* >(foo));
            } else {
                npc(notContactDirect)->add(static_cast< ::java::lang::Object* >(foo));
            }
        }
    }
    if(npc(contactDirect)->isEmpty())
        return notContactDirect;

    return contactDirect;
}

rice::p2p::commonapi::Cancellable* rice::pastry::socket::nat::rendezvous::RendezvousPNSApplication::getNearHandles(::java::util::Collection* bootHandles, ::rice::Continuation* deliverResultToMe)
{
    auto newBootHandles = new ::java::util::ArrayList();
    if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
        npc(logger)->log(::java::lang::StringBuilder().append(u"Booting off of "_j)->append(npc(bootHandles)->size())
            ->append(u" nodes. "_j)
            ->append(static_cast< ::java::lang::Object* >(bootHandles))->toString());

    for (auto _i = npc(bootHandles)->iterator(); _i->hasNext(); ) {
        ::rice::pastry::NodeHandle* handle = java_cast< ::rice::pastry::NodeHandle* >(_i->next());
        {
            if(useHandle(handle)) {
                npc(newBootHandles)->add(static_cast< ::java::lang::Object* >(handle));
            } else {
                if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                    npc(logger)->log(::java::lang::StringBuilder().append(u"Can't use "_j)->append(static_cast< ::java::lang::Object* >(handle))
                        ->append(u" it is firewalled."_j)->toString());

            }
        }
    }
    return super::getNearHandles(static_cast< ::java::util::Collection* >(newBootHandles), deliverResultToMe);
}

rice::p2p::commonapi::Cancellable* rice::pastry::socket::nat::rendezvous::RendezvousPNSApplication::getLeafSet(::rice::pastry::NodeHandle* input, ::rice::Continuation* c)
{
    if(ignore(input, c))
        return nullptr;

    return super::getLeafSet(input, new RendezvousPNSApplication_getLeafSet_1(this, input, c));
}

rice::p2p::commonapi::Cancellable* rice::pastry::socket::nat::rendezvous::RendezvousPNSApplication::getRouteRow(::rice::pastry::NodeHandle* input, int16_t row, ::rice::Continuation* c)
{
    if(ignore(input, c))
        return nullptr;

    return super::getRouteRow(input, row, new RendezvousPNSApplication_getRouteRow_2(this, input, row, c));
}

rice::p2p::commonapi::Cancellable* rice::pastry::socket::nat::rendezvous::RendezvousPNSApplication::getNearest(::rice::pastry::NodeHandle* seed, ::rice::Continuation* retToMe)
{
    if(ignore(seed, retToMe))
        return nullptr;

    return super::getNearest(seed, retToMe);
}

rice::p2p::commonapi::Cancellable* rice::pastry::socket::nat::rendezvous::RendezvousPNSApplication::getProximity(::rice::pastry::NodeHandle* handle, ::rice::Continuation* c, int32_t timeout)
{
    if(!useHandle(handle)) {
        npc(c)->receiveResult(::java::lang::Integer::valueOf(::java::lang::Integer::MAX_VALUE));
        return nullptr;
    }
    return super::getProximity(handle, c, timeout);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::socket::nat::rendezvous::RendezvousPNSApplication::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.socket.nat.rendezvous.RendezvousPNSApplication", 58);
    return c;
}

rice::pastry::leafset::LeafSet* rice::pastry::socket::nat::rendezvous::RendezvousPNSApplication::getLeafSet()
{
    return super::getLeafSet();
}

java::lang::Class* rice::pastry::socket::nat::rendezvous::RendezvousPNSApplication::getClass0()
{
    return class_();
}

