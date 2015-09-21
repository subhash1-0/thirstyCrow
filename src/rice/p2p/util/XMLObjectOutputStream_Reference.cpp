// Generated from /pastry-2.1/src/rice/p2p/util/XMLObjectOutputStream.java
#include <rice/p2p/util/XMLObjectOutputStream_Reference.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <rice/p2p/util/XMLObjectOutputStream.hpp>

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

rice::p2p::util::XMLObjectOutputStream_Reference::XMLObjectOutputStream_Reference(XMLObjectOutputStream *XMLObjectOutputStream_this, const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
    , XMLObjectOutputStream_this(XMLObjectOutputStream_this)
{
    clinit();
}

rice::p2p::util::XMLObjectOutputStream_Reference::XMLObjectOutputStream_Reference(XMLObjectOutputStream *XMLObjectOutputStream_this, ::java::lang::Object* object) 
    : XMLObjectOutputStream_Reference(XMLObjectOutputStream_this, *static_cast< ::default_init_tag* >(0))
{
    ctor(object);
}

void rice::p2p::util::XMLObjectOutputStream_Reference::ctor(::java::lang::Object* object)
{
    super::ctor();
    this->object = object;
}

int32_t rice::p2p::util::XMLObjectOutputStream_Reference::hashCode()
{
    return XMLObjectOutputStream_this->hash(object);
}

bool rice::p2p::util::XMLObjectOutputStream_Reference::equals(::java::lang::Object* o)
{
    return (npc((java_cast< XMLObjectOutputStream_Reference* >(o)))->object == object);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::util::XMLObjectOutputStream_Reference::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.util.XMLObjectOutputStream.Reference", 45);
    return c;
}

java::lang::Class* rice::p2p::util::XMLObjectOutputStream_Reference::getClass0()
{
    return class_();
}

