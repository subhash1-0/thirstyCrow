// Generated from /pastry-2.1/src/rice/p2p/util/rawserialization/JavaSerializationException.java
#include <rice/p2p/util/rawserialization/JavaSerializationException.hpp>

#include <java/lang/Exception.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>

rice::p2p::util::rawserialization::JavaSerializationException::JavaSerializationException(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::util::rawserialization::JavaSerializationException::JavaSerializationException(::java::lang::Object* o, ::java::lang::Exception* e) 
    : JavaSerializationException(*static_cast< ::default_init_tag* >(0))
{
    ctor(o,e);
}

void rice::p2p::util::rawserialization::JavaSerializationException::ctor(::java::lang::Object* o, ::java::lang::Exception* e)
{
    super::ctor(::java::lang::StringBuilder().append(u"Error serializing "_j)->append(static_cast< ::java::lang::Object* >(o))->toString());
    initCause(e);
    this->cantSerialize = o;
}

java::lang::Object* rice::p2p::util::rawserialization::JavaSerializationException::getUnserializable()
{
    return cantSerialize;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::util::rawserialization::JavaSerializationException::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.util.rawserialization.JavaSerializationException", 57);
    return c;
}

java::lang::Class* rice::p2p::util::rawserialization::JavaSerializationException::getClass0()
{
    return class_();
}

