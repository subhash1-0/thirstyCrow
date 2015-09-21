// Generated from /pastry-2.1/src/rice/p2p/scribe/ScribeImpl.java
#include <rice/p2p/scribe/ScribeImpl_ScribeClientConverter.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/ref/WeakReference.hpp>
#include <java/util/Collection.hpp>
#include <java/util/Iterator.hpp>
#include <rice/p2p/scribe/ScribeClient.hpp>
#include <rice/p2p/scribe/Topic.hpp>

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

rice::p2p::scribe::ScribeImpl_ScribeClientConverter::ScribeImpl_ScribeClientConverter(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::scribe::ScribeImpl_ScribeClientConverter::ScribeImpl_ScribeClientConverter(ScribeClient* client) 
    : ScribeImpl_ScribeClientConverter(*static_cast< ::default_init_tag* >(0))
{
    ctor(client);
}

void rice::p2p::scribe::ScribeImpl_ScribeClientConverter::ctor(ScribeClient* client)
{
    super::ctor();
    this->client = new ::java::lang::ref::WeakReference(client);
}

void rice::p2p::scribe::ScribeImpl_ScribeClientConverter::subscribeFailed(::java::util::Collection* topics)
{
    auto theClient = java_cast< ScribeClient* >(npc(client)->get());
    if(theClient == nullptr)
        return;

    for (auto _i = npc(topics)->iterator(); _i->hasNext(); ) {
        Topic* topic = java_cast< Topic* >(_i->next());
        {
            npc(theClient)->subscribeFailed(topic);
        }
    }
}

void rice::p2p::scribe::ScribeImpl_ScribeClientConverter::subscribeSuccess(::java::util::Collection* topics)
{
}

bool rice::p2p::scribe::ScribeImpl_ScribeClientConverter::anycast(Topic* topic, ScribeContent* content)
{
    auto theClient = java_cast< ScribeClient* >(npc(client)->get());
    if(theClient == nullptr)
        return false;

    return npc(theClient)->anycast(topic, content);
}

void rice::p2p::scribe::ScribeImpl_ScribeClientConverter::childAdded(Topic* topic, ::rice::p2p::commonapi::NodeHandle* child)
{
    auto theClient = java_cast< ScribeClient* >(npc(client)->get());
    if(theClient == nullptr)
        return;

    npc(theClient)->childAdded(topic, child);
}

void rice::p2p::scribe::ScribeImpl_ScribeClientConverter::childRemoved(Topic* topic, ::rice::p2p::commonapi::NodeHandle* child)
{
    auto theClient = java_cast< ScribeClient* >(npc(client)->get());
    if(theClient == nullptr)
        return;

    npc(theClient)->childRemoved(topic, child);
}

void rice::p2p::scribe::ScribeImpl_ScribeClientConverter::deliver(Topic* topic, ScribeContent* content)
{
    auto theClient = java_cast< ScribeClient* >(npc(client)->get());
    if(theClient == nullptr)
        return;

    npc(theClient)->deliver(topic, content);
}

void rice::p2p::scribe::ScribeImpl_ScribeClientConverter::subscribeFailed(Topic* topic)
{
    auto theClient = java_cast< ScribeClient* >(npc(client)->get());
    if(theClient == nullptr)
        return;

    npc(theClient)->subscribeFailed(topic);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::scribe::ScribeImpl_ScribeClientConverter::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.scribe.ScribeImpl.ScribeClientConverter", 48);
    return c;
}

java::lang::Class* rice::p2p::scribe::ScribeImpl_ScribeClientConverter::getClass0()
{
    return class_();
}

