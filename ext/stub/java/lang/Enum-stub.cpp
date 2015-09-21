// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/lang/Enum.hpp>

extern void unimplemented_(const char16_t* name);
java::lang::Enum::Enum(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::lang::Enum::Enum(String* arg0, int32_t arg1)
    : Enum(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0, arg1);
}


void ::java::lang::Enum::ctor(String* arg0, int32_t arg1)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::lang::Enum::ctor(String* arg0, int32_t arg1)");
}

java::lang::Object* java::lang::Enum::clone()
{ /* stub */
    unimplemented_(u"java::lang::Object* java::lang::Enum::clone()");
    return 0;
}

int32_t java::lang::Enum::compareTo(Enum* arg0)
{ /* stub */
    unimplemented_(u"int32_t java::lang::Enum::compareTo(Enum* arg0)");
    return 0;
}

int32_t java::lang::Enum::compareTo(Object* arg0)
{ 
    return compareTo(dynamic_cast< Enum* >(arg0));
}

bool java::lang::Enum::equals(Object* arg0)
{ /* stub */
    unimplemented_(u"bool java::lang::Enum::equals(Object* arg0)");
    return 0;
}

void java::lang::Enum::finalize()
{ /* stub */
    unimplemented_(u"void java::lang::Enum::finalize()");
}

java::lang::Class* java::lang::Enum::getDeclaringClass()
{ /* stub */
    unimplemented_(u"java::lang::Class* java::lang::Enum::getDeclaringClass()");
    return 0;
}

int32_t java::lang::Enum::hashCode()
{ /* stub */
    unimplemented_(u"int32_t java::lang::Enum::hashCode()");
    return 0;
}

java::lang::String* java::lang::Enum::name()
{ /* stub */
    unimplemented_(u"java::lang::String* java::lang::Enum::name()");
    return 0;
}

int32_t java::lang::Enum::ordinal()
{ /* stub */
    unimplemented_(u"int32_t java::lang::Enum::ordinal()");
    return 0;
}

/* private: void java::lang::Enum::readObject(::java::io::ObjectInputStream* arg0) */
/* private: void java::lang::Enum::readObjectNoData() */
java::lang::String* java::lang::Enum::toString()
{ /* stub */
    unimplemented_(u"java::lang::String* java::lang::Enum::toString()");
    return 0;
}

java::lang::Enum* java::lang::Enum::valueOf(Class* arg0, String* arg1)
{ /* stub */
    clinit();
    unimplemented_(u"java::lang::Enum* java::lang::Enum::valueOf(Class* arg0, String* arg1)");
    return 0;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::lang::Enum::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.lang.Enum", 14);
    return c;
}

java::lang::Class* java::lang::Enum::getClass0()
{
    return class_();
}

