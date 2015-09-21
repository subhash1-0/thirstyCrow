// Generated from /pastry-2.1/src/rice/p2p/splitstream/StripeId.java
#include <rice/p2p/splitstream/StripeId.hpp>

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

rice::p2p::splitstream::StripeId::StripeId(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::splitstream::StripeId::StripeId(::rice::p2p::commonapi::Id* id) 
    : StripeId(*static_cast< ::default_init_tag* >(0))
{
    ctor(id);
}

void rice::p2p::splitstream::StripeId::ctor(::rice::p2p::commonapi::Id* id)
{
    super::ctor();
    this->id = id;
}

rice::p2p::commonapi::Id* rice::p2p::splitstream::StripeId::getId()
{
    return id;
}

java::lang::String* rice::p2p::splitstream::StripeId::toString()
{
    return ::java::lang::StringBuilder().append(u"[StripeId "_j)->append(static_cast< ::java::lang::Object* >(id))
        ->append(u"]"_j)->toString();
}

int32_t rice::p2p::splitstream::StripeId::hashCode()
{
    return npc(id)->hashCode();
}

bool rice::p2p::splitstream::StripeId::equals(::java::lang::Object* o)
{
    if(!(dynamic_cast< StripeId* >(o) != nullptr)) {
        return false;
    }
    return npc(npc((java_cast< StripeId* >(o)))->id)->equals(id);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::splitstream::StripeId::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.splitstream.StripeId", 29);
    return c;
}

java::lang::Class* rice::p2p::splitstream::StripeId::getClass0()
{
    return class_();
}

