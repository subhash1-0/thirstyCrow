// Generated from /pastry-2.1/src/rice/p2p/multiring/MultiringApplication.java
#include <rice/p2p/multiring/MultiringApplication.hpp>

#include <java/lang/Class.hpp>
#include <java/lang/IllegalArgumentException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/p2p/commonapi/Application.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/multiring/MultiringNodeHandle.hpp>
#include <rice/p2p/multiring/MultiringRouteMessage.hpp>
#include <rice/p2p/multiring/RingId.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::multiring::MultiringApplication::MultiringApplication(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::multiring::MultiringApplication::MultiringApplication(::rice::p2p::commonapi::Id* ringId, ::rice::p2p::commonapi::Application* application) 
    : MultiringApplication(*static_cast< ::default_init_tag* >(0))
{
    ctor(ringId,application);
}

void rice::p2p::multiring::MultiringApplication::ctor(::rice::p2p::commonapi::Id* ringId, ::rice::p2p::commonapi::Application* application)
{
    super::ctor();
    this->application = application;
    this->ringId = ringId;
    if((dynamic_cast< RingId* >(ringId) != nullptr) || (dynamic_cast< MultiringApplication* >(application) != nullptr))
        throw new ::java::lang::IllegalArgumentException(::java::lang::StringBuilder().append(u"Illegal creation of MRApplication: "_j)->append(static_cast< ::java::lang::Object* >(npc(ringId)->getClass()))
            ->append(u", "_j)
            ->append(static_cast< ::java::lang::Object* >(npc(application)->getClass()))->toString());

}

bool rice::p2p::multiring::MultiringApplication::forward(::rice::p2p::commonapi::RouteMessage* message)
{
    return npc(application)->forward(new MultiringRouteMessage(ringId, message));
}

void rice::p2p::multiring::MultiringApplication::deliver(::rice::p2p::commonapi::Id* id, ::rice::p2p::commonapi::Message* message)
{
    if(id != nullptr) {
        npc(application)->deliver(RingId::build(ringId, id), message);
    } else {
        npc(application)->deliver(nullptr, message);
    }
}

void rice::p2p::multiring::MultiringApplication::update(::rice::p2p::commonapi::NodeHandle* handle, bool joined)
{
    npc(application)->update(new MultiringNodeHandle(ringId, handle), joined);
}

java::lang::String* rice::p2p::multiring::MultiringApplication::toString()
{
    return ::java::lang::StringBuilder().append(u"MultiringApplication<"_j)->append(static_cast< ::java::lang::Object* >(application))
        ->append(u">:"_j)
        ->append(static_cast< ::java::lang::Object* >(ringId))->toString();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::multiring::MultiringApplication::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.multiring.MultiringApplication", 39);
    return c;
}

java::lang::Class* rice::p2p::multiring::MultiringApplication::getClass0()
{
    return class_();
}

