// Generated from /pastry-2.1/src/rice/p2p/splitstream/ChannelId.java
#include <rice/p2p/splitstream/ChannelId.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/p2p/commonapi/Id.hpp>

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

rice::p2p::splitstream::ChannelId::ChannelId(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::splitstream::ChannelId::ChannelId(::rice::p2p::commonapi::Id* id) 
    : ChannelId(*static_cast< ::default_init_tag* >(0))
{
    ctor(id);
}

rice::p2p::splitstream::ChannelId::ChannelId(::java::lang::String* name) 
    : ChannelId(*static_cast< ::default_init_tag* >(0))
{
    ctor(name);
}

void rice::p2p::splitstream::ChannelId::ctor(::rice::p2p::commonapi::Id* id)
{
    super::ctor();
    this->id = id;
}

void rice::p2p::splitstream::ChannelId::ctor(::java::lang::String* name)
{
    super::ctor();
    this->id = nullptr;
}

rice::p2p::commonapi::Id* rice::p2p::splitstream::ChannelId::getId()
{
    return id;
}

java::lang::String* rice::p2p::splitstream::ChannelId::toString()
{
    return ::java::lang::StringBuilder().append(u"[ChannelId "_j)->append(static_cast< ::java::lang::Object* >(id))
        ->append(u"]"_j)->toString();
}

int32_t rice::p2p::splitstream::ChannelId::hashCode()
{
    return npc(id)->hashCode();
}

bool rice::p2p::splitstream::ChannelId::equals(::java::lang::Object* o)
{
    if(!(dynamic_cast< ChannelId* >(o) != nullptr)) {
        return false;
    }
    return npc(npc((java_cast< ChannelId* >(o)))->id)->equals(id);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::splitstream::ChannelId::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.splitstream.ChannelId", 30);
    return c;
}

java::lang::Class* rice::p2p::splitstream::ChannelId::getClass0()
{
    return class_();
}

