// Generated from /pastry-2.1/src/rice/p2p/util/XMLObjectOutputStream.java
#include <rice/p2p/util/XMLObjectOutputStream_PutField.hpp>

#include <java/io/ObjectOutput.hpp>
#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/Boolean.hpp>
#include <java/lang/Byte.hpp>
#include <java/lang/CharSequence.hpp>
#include <java/lang/Character.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Comparable.hpp>
#include <java/lang/Double.hpp>
#include <java/lang/Float.hpp>
#include <java/lang/Integer.hpp>
#include <java/lang/Long.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/Short.hpp>
#include <java/lang/String.hpp>
#include <java/util/Hashtable.hpp>
#include <java/util/Set.hpp>
#include <rice/p2p/util/XMLObjectOutputStream.hpp>
#include <SubArray.hpp>
#include <ObjectArray.hpp>

template<typename ComponentType, typename... Bases> struct SubArray;
namespace java
{
    namespace io
    {
typedef ::SubArray< ::java::io::Serializable, ::java::lang::ObjectArray > SerializableArray;
    } // io

    namespace lang
    {
typedef ::SubArray< ::java::lang::CharSequence, ObjectArray > CharSequenceArray;
typedef ::SubArray< ::java::lang::Comparable, ObjectArray > ComparableArray;
typedef ::SubArray< ::java::lang::String, ObjectArray, ::java::io::SerializableArray, ComparableArray, CharSequenceArray > StringArray;
    } // lang
} // java

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

rice::p2p::util::XMLObjectOutputStream_PutField::XMLObjectOutputStream_PutField(XMLObjectOutputStream *XMLObjectOutputStream_this, const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
    , XMLObjectOutputStream_this(XMLObjectOutputStream_this)
{
    clinit();
}

rice::p2p::util::XMLObjectOutputStream_PutField::XMLObjectOutputStream_PutField(XMLObjectOutputStream *XMLObjectOutputStream_this)
    : XMLObjectOutputStream_PutField(XMLObjectOutputStream_this, *static_cast< ::default_init_tag* >(0))
{
    ctor();
}

void rice::p2p::util::XMLObjectOutputStream_PutField::ctor()
{
    super::ctor();
    init();
}

void rice::p2p::util::XMLObjectOutputStream_PutField::init()
{
    primitives = new ::java::util::Hashtable();
    objects = new ::java::util::Hashtable();
}

java::lang::StringArray* rice::p2p::util::XMLObjectOutputStream_PutField::getPrimitives()
{
    return java_cast< ::java::lang::StringArray* >(java_cast< ::java::lang::ObjectArray* >(npc(npc(primitives)->keySet())->toArray_(static_cast< ::java::lang::ObjectArray* >(new ::java::lang::StringArray(int32_t(0))))));
}

java::lang::StringArray* rice::p2p::util::XMLObjectOutputStream_PutField::getObjects()
{
    return java_cast< ::java::lang::StringArray* >(java_cast< ::java::lang::ObjectArray* >(npc(npc(objects)->keySet())->toArray_(static_cast< ::java::lang::ObjectArray* >(new ::java::lang::StringArray(int32_t(0))))));
}

void rice::p2p::util::XMLObjectOutputStream_PutField::put(::java::lang::String* name, bool value)
{
    npc(primitives)->put(static_cast< ::java::lang::Object* >(name), static_cast< ::java::lang::Object* >(new ::java::lang::Boolean(value)));
}

void rice::p2p::util::XMLObjectOutputStream_PutField::put(::java::lang::String* name, int8_t value)
{
    npc(primitives)->put(static_cast< ::java::lang::Object* >(name), static_cast< ::java::lang::Object* >(new ::java::lang::Byte(value)));
}

void rice::p2p::util::XMLObjectOutputStream_PutField::put(::java::lang::String* name, char16_t value)
{
    npc(primitives)->put(static_cast< ::java::lang::Object* >(name), static_cast< ::java::lang::Object* >(new ::java::lang::Character(value)));
}

void rice::p2p::util::XMLObjectOutputStream_PutField::put(::java::lang::String* name, double value)
{
    npc(primitives)->put(static_cast< ::java::lang::Object* >(name), static_cast< ::java::lang::Object* >(new ::java::lang::Double(value)));
}

void rice::p2p::util::XMLObjectOutputStream_PutField::put(::java::lang::String* name, float value)
{
    npc(primitives)->put(static_cast< ::java::lang::Object* >(name), static_cast< ::java::lang::Object* >(new ::java::lang::Float(value)));
}

void rice::p2p::util::XMLObjectOutputStream_PutField::put(::java::lang::String* name, int32_t value)
{
    npc(primitives)->put(static_cast< ::java::lang::Object* >(name), static_cast< ::java::lang::Object* >(new ::java::lang::Integer(value)));
}

void rice::p2p::util::XMLObjectOutputStream_PutField::put(::java::lang::String* name, int64_t value)
{
    npc(primitives)->put(static_cast< ::java::lang::Object* >(name), static_cast< ::java::lang::Object* >(new ::java::lang::Long(value)));
}

void rice::p2p::util::XMLObjectOutputStream_PutField::put(::java::lang::String* name, int16_t value)
{
    npc(primitives)->put(static_cast< ::java::lang::Object* >(name), static_cast< ::java::lang::Object* >(new ::java::lang::Short(value)));
}

void rice::p2p::util::XMLObjectOutputStream_PutField::put(::java::lang::String* name, ::java::lang::Object* value)
{
    npc(objects)->put(static_cast< ::java::lang::Object* >(name), static_cast< ::java::lang::Object* >(value));
}

java::lang::Object* rice::p2p::util::XMLObjectOutputStream_PutField::getPrimitive(::java::lang::String* name)
{
    return java_cast< ::java::lang::Object* >(npc(primitives)->get(static_cast< ::java::lang::Object* >(name)));
}

java::lang::Object* rice::p2p::util::XMLObjectOutputStream_PutField::getObject(::java::lang::String* name)
{
    return java_cast< ::java::lang::Object* >(npc(objects)->get(static_cast< ::java::lang::Object* >(name)));
}

bool rice::p2p::util::XMLObjectOutputStream_PutField::getBoolean(::java::lang::String* name)
{
    return npc((java_cast< ::java::lang::Boolean* >(getPrimitive(name))))->booleanValue();
}

int8_t rice::p2p::util::XMLObjectOutputStream_PutField::getByte(::java::lang::String* name)
{
    return npc((java_cast< ::java::lang::Byte* >(getPrimitive(name))))->byteValue();
}

char16_t rice::p2p::util::XMLObjectOutputStream_PutField::getChar(::java::lang::String* name)
{
    return npc((java_cast< ::java::lang::Character* >(getPrimitive(name))))->charValue();
}

double rice::p2p::util::XMLObjectOutputStream_PutField::getDouble(::java::lang::String* name)
{
    return npc((java_cast< ::java::lang::Double* >(getPrimitive(name))))->doubleValue();
}

float rice::p2p::util::XMLObjectOutputStream_PutField::getFloat(::java::lang::String* name)
{
    return npc((java_cast< ::java::lang::Float* >(getPrimitive(name))))->floatValue();
}

int32_t rice::p2p::util::XMLObjectOutputStream_PutField::getInt(::java::lang::String* name)
{
    return npc((java_cast< ::java::lang::Integer* >(getPrimitive(name))))->intValue();
}

int64_t rice::p2p::util::XMLObjectOutputStream_PutField::getLong(::java::lang::String* name)
{
    return npc((java_cast< ::java::lang::Long* >(getPrimitive(name))))->longValue();
}

int16_t rice::p2p::util::XMLObjectOutputStream_PutField::getShort(::java::lang::String* name)
{
    return npc((java_cast< ::java::lang::Short* >(getPrimitive(name))))->shortValue();
}

void rice::p2p::util::XMLObjectOutputStream_PutField::write(::java::io::ObjectOutput* output) /* throws(IOException) */
{
    auto xoos = java_cast< XMLObjectOutputStream* >(output);
    npc(xoos)->writeFields();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::util::XMLObjectOutputStream_PutField::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.util.XMLObjectOutputStream.PutField", 44);
    return c;
}

java::lang::Class* rice::p2p::util::XMLObjectOutputStream_PutField::getClass0()
{
    return class_();
}

