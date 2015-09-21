// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/table/UnknownValueException.java
#include <org/mpisws/p2p/transport/table/UnknownValueException.hpp>

#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>

org::mpisws::p2p::transport::table::UnknownValueException::UnknownValueException(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::transport::table::UnknownValueException::UnknownValueException(::java::lang::Object* source, ::java::lang::Object* key) 
    : UnknownValueException(*static_cast< ::default_init_tag* >(0))
{
    ctor(source,key);
}

void org::mpisws::p2p::transport::table::UnknownValueException::ctor(::java::lang::Object* source, ::java::lang::Object* key)
{
    super::ctor(::java::lang::StringBuilder().append(u"The node "_j)->append(static_cast< ::java::lang::Object* >(source))
        ->append(u" did not have a value for the key "_j)
        ->append(static_cast< ::java::lang::Object* >(key))
        ->append(u"."_j)->toString());
    this->source = source;
    this->key = key;
}

java::lang::Object* org::mpisws::p2p::transport::table::UnknownValueException::getSource()
{
    return source;
}

java::lang::Object* org::mpisws::p2p::transport::table::UnknownValueException::getKey()
{
    return key;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::table::UnknownValueException::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.table.UnknownValueException", 52);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::table::UnknownValueException::getClass0()
{
    return class_();
}

