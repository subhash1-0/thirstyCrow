// Generated from /pastry-2.1/src/rice/p2p/util/XMLObjectInputStream.java
#include <rice/p2p/util/XMLObjectInputStream_GetField.hpp>

#include <java/lang/Boolean.hpp>
#include <java/lang/Byte.hpp>
#include <java/lang/Character.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Double.hpp>
#include <java/lang/Float.hpp>
#include <java/lang/Integer.hpp>
#include <java/lang/Long.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/Short.hpp>
#include <java/lang/String.hpp>
#include <java/lang/UnsupportedOperationException.hpp>
#include <java/util/HashMap.hpp>
#include <rice/p2p/util/XMLObjectInputStream.hpp>

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

rice::p2p::util::XMLObjectInputStream_GetField::XMLObjectInputStream_GetField(XMLObjectInputStream *XMLObjectInputStream_this, const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
    , XMLObjectInputStream_this(XMLObjectInputStream_this)
{
    clinit();
}

rice::p2p::util::XMLObjectInputStream_GetField::XMLObjectInputStream_GetField(XMLObjectInputStream *XMLObjectInputStream_this)
    : XMLObjectInputStream_GetField(XMLObjectInputStream_this, *static_cast< ::default_init_tag* >(0))
{
    ctor();
}

void rice::p2p::util::XMLObjectInputStream_GetField::ctor()
{
    super::ctor();
    init();
}

void rice::p2p::util::XMLObjectInputStream_GetField::init()
{
    primitives = new ::java::util::HashMap();
    objects = new ::java::util::HashMap();
}

bool rice::p2p::util::XMLObjectInputStream_GetField::defaulted(::java::lang::String* name)
{
    return (!(npc(primitives)->containsKey(static_cast< ::java::lang::Object* >(name)) || npc(objects)->containsKey(static_cast< ::java::lang::Object* >(name))));
}

bool rice::p2p::util::XMLObjectInputStream_GetField::get(::java::lang::String* name, bool value)
{
    if(java_cast< ::java::lang::Object* >(npc(primitives)->get(static_cast< ::java::lang::Object* >(name))) == nullptr)
        return value;

    return npc((java_cast< ::java::lang::Boolean* >(java_cast< ::java::lang::Object* >(npc(primitives)->get(static_cast< ::java::lang::Object* >(name))))))->booleanValue();
}

int8_t rice::p2p::util::XMLObjectInputStream_GetField::get(::java::lang::String* name, int8_t value)
{
    if(java_cast< ::java::lang::Object* >(npc(primitives)->get(static_cast< ::java::lang::Object* >(name))) == nullptr)
        return value;

    return npc((java_cast< ::java::lang::Byte* >(java_cast< ::java::lang::Object* >(npc(primitives)->get(static_cast< ::java::lang::Object* >(name))))))->byteValue();
}

char16_t rice::p2p::util::XMLObjectInputStream_GetField::get(::java::lang::String* name, char16_t value)
{
    if(java_cast< ::java::lang::Object* >(npc(primitives)->get(static_cast< ::java::lang::Object* >(name))) == nullptr)
        return value;

    return npc((java_cast< ::java::lang::Character* >(java_cast< ::java::lang::Object* >(npc(primitives)->get(static_cast< ::java::lang::Object* >(name))))))->charValue();
}

double rice::p2p::util::XMLObjectInputStream_GetField::get(::java::lang::String* name, double value)
{
    if(java_cast< ::java::lang::Object* >(npc(primitives)->get(static_cast< ::java::lang::Object* >(name))) == nullptr)
        return value;

    return npc((java_cast< ::java::lang::Double* >(java_cast< ::java::lang::Object* >(npc(primitives)->get(static_cast< ::java::lang::Object* >(name))))))->doubleValue();
}

float rice::p2p::util::XMLObjectInputStream_GetField::get(::java::lang::String* name, float value)
{
    if(java_cast< ::java::lang::Object* >(npc(primitives)->get(static_cast< ::java::lang::Object* >(name))) == nullptr)
        return value;

    return npc((java_cast< ::java::lang::Float* >(java_cast< ::java::lang::Object* >(npc(primitives)->get(static_cast< ::java::lang::Object* >(name))))))->floatValue();
}

int32_t rice::p2p::util::XMLObjectInputStream_GetField::get(::java::lang::String* name, int32_t value)
{
    if(java_cast< ::java::lang::Object* >(npc(primitives)->get(static_cast< ::java::lang::Object* >(name))) == nullptr)
        return value;

    return npc((java_cast< ::java::lang::Integer* >(java_cast< ::java::lang::Object* >(npc(primitives)->get(static_cast< ::java::lang::Object* >(name))))))->intValue();
}

int64_t rice::p2p::util::XMLObjectInputStream_GetField::get(::java::lang::String* name, int64_t value)
{
    if(java_cast< ::java::lang::Object* >(npc(primitives)->get(static_cast< ::java::lang::Object* >(name))) == nullptr)
        return value;

    return npc((java_cast< ::java::lang::Long* >(java_cast< ::java::lang::Object* >(npc(primitives)->get(static_cast< ::java::lang::Object* >(name))))))->longValue();
}

int16_t rice::p2p::util::XMLObjectInputStream_GetField::get(::java::lang::String* name, int16_t value)
{
    if(java_cast< ::java::lang::Object* >(npc(primitives)->get(static_cast< ::java::lang::Object* >(name))) == nullptr)
        return value;

    return npc((java_cast< ::java::lang::Short* >(java_cast< ::java::lang::Object* >(npc(primitives)->get(static_cast< ::java::lang::Object* >(name))))))->shortValue();
}

java::lang::Object* rice::p2p::util::XMLObjectInputStream_GetField::get(::java::lang::String* name, ::java::lang::Object* value)
{
    if(java_cast< ::java::lang::Object* >(npc(objects)->get(static_cast< ::java::lang::Object* >(name))) == nullptr)
        return value;

    return java_cast< ::java::lang::Object* >(npc(objects)->get(static_cast< ::java::lang::Object* >(name)));
}

void rice::p2p::util::XMLObjectInputStream_GetField::put(::java::lang::String* name, bool value)
{
    npc(primitives)->put(static_cast< ::java::lang::Object* >(name), static_cast< ::java::lang::Object* >(new ::java::lang::Boolean(value)));
}

void rice::p2p::util::XMLObjectInputStream_GetField::put(::java::lang::String* name, int8_t value)
{
    npc(primitives)->put(static_cast< ::java::lang::Object* >(name), static_cast< ::java::lang::Object* >(new ::java::lang::Byte(value)));
}

void rice::p2p::util::XMLObjectInputStream_GetField::put(::java::lang::String* name, char16_t value)
{
    npc(primitives)->put(static_cast< ::java::lang::Object* >(name), static_cast< ::java::lang::Object* >(new ::java::lang::Character(value)));
}

void rice::p2p::util::XMLObjectInputStream_GetField::put(::java::lang::String* name, double value)
{
    npc(primitives)->put(static_cast< ::java::lang::Object* >(name), static_cast< ::java::lang::Object* >(new ::java::lang::Double(value)));
}

void rice::p2p::util::XMLObjectInputStream_GetField::put(::java::lang::String* name, float value)
{
    npc(primitives)->put(static_cast< ::java::lang::Object* >(name), static_cast< ::java::lang::Object* >(new ::java::lang::Float(value)));
}

void rice::p2p::util::XMLObjectInputStream_GetField::put(::java::lang::String* name, int32_t value)
{
    npc(primitives)->put(static_cast< ::java::lang::Object* >(name), static_cast< ::java::lang::Object* >(new ::java::lang::Integer(value)));
}

void rice::p2p::util::XMLObjectInputStream_GetField::put(::java::lang::String* name, int64_t value)
{
    npc(primitives)->put(static_cast< ::java::lang::Object* >(name), static_cast< ::java::lang::Object* >(new ::java::lang::Long(value)));
}

void rice::p2p::util::XMLObjectInputStream_GetField::put(::java::lang::String* name, int16_t value)
{
    npc(primitives)->put(static_cast< ::java::lang::Object* >(name), static_cast< ::java::lang::Object* >(new ::java::lang::Short(value)));
}

void rice::p2p::util::XMLObjectInputStream_GetField::put(::java::lang::String* name, ::java::lang::Object* value)
{
    npc(objects)->put(static_cast< ::java::lang::Object* >(name), static_cast< ::java::lang::Object* >(value));
}

java::io::ObjectStreamClass* rice::p2p::util::XMLObjectInputStream_GetField::getObjectStreamClass()
{
    throw new ::java::lang::UnsupportedOperationException(u"CANNOT GET THE OBJECT STREAM CLASS!"_j);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::util::XMLObjectInputStream_GetField::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.util.XMLObjectInputStream.GetField", 43);
    return c;
}

java::lang::Class* rice::p2p::util::XMLObjectInputStream_GetField::getClass0()
{
    return class_();
}

