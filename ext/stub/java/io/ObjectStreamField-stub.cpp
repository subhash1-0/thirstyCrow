// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/io/ObjectStreamField.hpp>

extern void unimplemented_(const char16_t* name);
java::io::ObjectStreamField::ObjectStreamField(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::io::ObjectStreamField::ObjectStreamField(::java::lang::String* arg0, ::java::lang::Class* arg1)
    : ObjectStreamField(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0, arg1);
}

java::io::ObjectStreamField::ObjectStreamField(::java::lang::String* arg0, ::java::lang::Class* arg1, bool arg2)
    : ObjectStreamField(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0, arg1, arg2);
}

java::io::ObjectStreamField::ObjectStreamField(::java::lang::String* arg0, ::java::lang::String* arg1, bool arg2)
    : ObjectStreamField(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0, arg1, arg2);
}

java::io::ObjectStreamField::ObjectStreamField(::java::lang::reflect::Field* arg0, bool arg1, bool arg2)
    : ObjectStreamField(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0, arg1, arg2);
}


void ::java::io::ObjectStreamField::ctor(::java::lang::String* arg0, ::java::lang::Class* arg1)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::io::ObjectStreamField::ctor(::java::lang::String* arg0, ::java::lang::Class* arg1)");
}

void ::java::io::ObjectStreamField::ctor(::java::lang::String* arg0, ::java::lang::Class* arg1, bool arg2)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::io::ObjectStreamField::ctor(::java::lang::String* arg0, ::java::lang::Class* arg1, bool arg2)");
}

void ::java::io::ObjectStreamField::ctor(::java::lang::String* arg0, ::java::lang::String* arg1, bool arg2)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::io::ObjectStreamField::ctor(::java::lang::String* arg0, ::java::lang::String* arg1, bool arg2)");
}

void ::java::io::ObjectStreamField::ctor(::java::lang::reflect::Field* arg0, bool arg1, bool arg2)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::io::ObjectStreamField::ctor(::java::lang::reflect::Field* arg0, bool arg1, bool arg2)");
}

int32_t java::io::ObjectStreamField::compareTo(::java::lang::Object* arg0)
{ /* stub */
    unimplemented_(u"int32_t java::io::ObjectStreamField::compareTo(::java::lang::Object* arg0)");
    return 0;
}

/* private: java::lang::String* java::io::ObjectStreamField::getClassSignature(::java::lang::Class* arg0) */
java::lang::reflect::Field* java::io::ObjectStreamField::getField()
{ /* stub */
return field ; /* getter */
}

java::lang::String* java::io::ObjectStreamField::getName()
{ /* stub */
return name ; /* getter */
}

int32_t java::io::ObjectStreamField::getOffset()
{ /* stub */
return offset ; /* getter */
}

java::lang::String* java::io::ObjectStreamField::getSignature()
{ /* stub */
return signature ; /* getter */
}

java::lang::Class* java::io::ObjectStreamField::getType()
{ /* stub */
return type ; /* getter */
}

char16_t java::io::ObjectStreamField::getTypeCode()
{ /* stub */
    unimplemented_(u"char16_t java::io::ObjectStreamField::getTypeCode()");
    return 0;
}

java::lang::String* java::io::ObjectStreamField::getTypeString()
{ /* stub */
    unimplemented_(u"java::lang::String* java::io::ObjectStreamField::getTypeString()");
    return 0;
}

bool java::io::ObjectStreamField::isPrimitive()
{ /* stub */
    unimplemented_(u"bool java::io::ObjectStreamField::isPrimitive()");
    return 0;
}

bool java::io::ObjectStreamField::isUnshared()
{ /* stub */
    unimplemented_(u"bool java::io::ObjectStreamField::isUnshared()");
    return 0;
}

void java::io::ObjectStreamField::setOffset(int32_t arg0)
{ /* stub */
    this->offset = arg0; /* setter */
}

java::lang::String* java::io::ObjectStreamField::toString()
{ /* stub */
    unimplemented_(u"java::lang::String* java::io::ObjectStreamField::toString()");
    return 0;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::io::ObjectStreamField::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.io.ObjectStreamField", 25);
    return c;
}

java::lang::Class* java::io::ObjectStreamField::getClass0()
{
    return class_();
}

