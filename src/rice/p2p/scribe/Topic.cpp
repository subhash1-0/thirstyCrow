// Generated from /pastry-2.1/src/rice/p2p/scribe/Topic.java
#include <rice/p2p/scribe/Topic.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/p2p/commonapi/Endpoint.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/commonapi/IdFactory.hpp>
#include <rice/p2p/commonapi/rawserialization/InputBuffer.hpp>
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

rice::p2p::scribe::Topic::Topic(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::scribe::Topic::Topic(::rice::p2p::commonapi::Id* id) 
    : Topic(*static_cast< ::default_init_tag* >(0))
{
    ctor(id);
}

rice::p2p::scribe::Topic::Topic(::rice::p2p::commonapi::IdFactory* factory, ::java::lang::String* name) 
    : Topic(*static_cast< ::default_init_tag* >(0))
{
    ctor(factory,name);
}

rice::p2p::scribe::Topic::Topic(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint)  /* throws(IOException) */
    : Topic(*static_cast< ::default_init_tag* >(0))
{
    ctor(buf,endpoint);
}

void rice::p2p::scribe::Topic::ctor(::rice::p2p::commonapi::Id* id)
{
    super::ctor();
    this->id = id;
}

void rice::p2p::scribe::Topic::ctor(::rice::p2p::commonapi::IdFactory* factory, ::java::lang::String* name)
{
    super::ctor();
    this->id = getId(factory, name);
}

rice::p2p::commonapi::Id* rice::p2p::scribe::Topic::getId()
{
    return id;
}

rice::p2p::commonapi::Id* rice::p2p::scribe::Topic::getId(::rice::p2p::commonapi::IdFactory* factory, ::java::lang::String* name)
{
    clinit();
    return npc(factory)->buildId(name);
}

bool rice::p2p::scribe::Topic::equals(::java::lang::Object* o)
{
    if(dynamic_cast< Topic* >(o) != nullptr) {
        return npc(npc((java_cast< Topic* >(o)))->id)->equals(id);
    }
    return false;
}

int32_t rice::p2p::scribe::Topic::hashCode()
{
    return npc(id)->hashCode();
}

java::lang::String* rice::p2p::scribe::Topic::toString()
{
    return ::java::lang::StringBuilder().append(u"[TOPIC "_j)->append(static_cast< ::java::lang::Object* >(id))
        ->append(u"]"_j)->toString();
}

void rice::p2p::scribe::Topic::ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint) /* throws(IOException) */
{
    super::ctor();
    id = npc(endpoint)->readId(buf, npc(buf)->readShort());
}

void rice::p2p::scribe::Topic::serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */
{
    npc(buf)->writeShort(npc(id)->getType());
    npc(id)->serialize(buf);
}

int32_t rice::p2p::scribe::Topic::compareTo(Topic* that)
{
    return npc(this->id)->compareTo(npc(that)->id);
}

int32_t rice::p2p::scribe::Topic::compareTo(::java::lang::Object* arg0)
{ 
    return compareTo(dynamic_cast< Topic* >(arg0));
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::scribe::Topic::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.scribe.Topic", 21);
    return c;
}

java::lang::Class* rice::p2p::scribe::Topic::getClass0()
{
    return class_();
}

