// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/lang/Boolean.hpp>

extern void unimplemented_(const char16_t* name);
java::lang::Boolean::Boolean(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::lang::Boolean::Boolean(bool arg0)
    : Boolean(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0);
}

java::lang::Boolean::Boolean(String* arg0)
    : Boolean(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0);
}

java::lang::Boolean*& java::lang::Boolean::FALSE()
{
    clinit();
    return FALSE_;
}
java::lang::Boolean* java::lang::Boolean::FALSE_;
java::lang::Boolean*& java::lang::Boolean::TRUE()
{
    clinit();
    return TRUE_;
}
java::lang::Boolean* java::lang::Boolean::TRUE_;
java::lang::Class*& java::lang::Boolean::TYPE()
{
    clinit();
    return TYPE_;
}
java::lang::Class* java::lang::Boolean::TYPE_;
constexpr int64_t java::lang::Boolean::serialVersionUID;

void ::java::lang::Boolean::ctor(bool arg0)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::lang::Boolean::ctor(bool arg0)");
}

void ::java::lang::Boolean::ctor(String* arg0)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::lang::Boolean::ctor(String* arg0)");
}

bool java::lang::Boolean::booleanValue()
{ /* stub */
    unimplemented_(u"bool java::lang::Boolean::booleanValue()");
    return 0;
}

int32_t java::lang::Boolean::compare(bool arg0, bool arg1)
{ /* stub */
    clinit();
    unimplemented_(u"int32_t java::lang::Boolean::compare(bool arg0, bool arg1)");
    return 0;
}

int32_t java::lang::Boolean::compareTo(Boolean* arg0)
{ /* stub */
    unimplemented_(u"int32_t java::lang::Boolean::compareTo(Boolean* arg0)");
    return 0;
}

int32_t java::lang::Boolean::compareTo(Object* arg0)
{ 
    return compareTo(dynamic_cast< Boolean* >(arg0));
}

bool java::lang::Boolean::equals(Object* arg0)
{ /* stub */
    unimplemented_(u"bool java::lang::Boolean::equals(Object* arg0)");
    return 0;
}

bool java::lang::Boolean::getBoolean(String* arg0)
{ /* stub */
    clinit();
    unimplemented_(u"bool java::lang::Boolean::getBoolean(String* arg0)");
    return 0;
}

int32_t java::lang::Boolean::hashCode()
{ /* stub */
    unimplemented_(u"int32_t java::lang::Boolean::hashCode()");
    return 0;
}

int32_t java::lang::Boolean::hashCode(bool arg0)
{ /* stub */
    clinit();
    unimplemented_(u"int32_t java::lang::Boolean::hashCode(bool arg0)");
    return 0;
}

bool java::lang::Boolean::logicalAnd(bool arg0, bool arg1)
{ /* stub */
    clinit();
    unimplemented_(u"bool java::lang::Boolean::logicalAnd(bool arg0, bool arg1)");
    return 0;
}

bool java::lang::Boolean::logicalOr(bool arg0, bool arg1)
{ /* stub */
    clinit();
    unimplemented_(u"bool java::lang::Boolean::logicalOr(bool arg0, bool arg1)");
    return 0;
}

bool java::lang::Boolean::logicalXor(bool arg0, bool arg1)
{ /* stub */
    clinit();
    unimplemented_(u"bool java::lang::Boolean::logicalXor(bool arg0, bool arg1)");
    return 0;
}

bool java::lang::Boolean::parseBoolean(String* arg0)
{ /* stub */
    clinit();
    unimplemented_(u"bool java::lang::Boolean::parseBoolean(String* arg0)");
    return 0;
}

java::lang::String* java::lang::Boolean::toString()
{ /* stub */
    unimplemented_(u"java::lang::String* java::lang::Boolean::toString()");
    return 0;
}

java::lang::String* java::lang::Boolean::toString(bool arg0)
{ /* stub */
    clinit();
    unimplemented_(u"java::lang::String* java::lang::Boolean::toString(bool arg0)");
    return 0;
}

java::lang::Boolean* java::lang::Boolean::valueOf(bool arg0)
{ /* stub */
    clinit();
    unimplemented_(u"java::lang::Boolean* java::lang::Boolean::valueOf(bool arg0)");
    return 0;
}

java::lang::Boolean* java::lang::Boolean::valueOf(String* arg0)
{ /* stub */
    clinit();
    unimplemented_(u"java::lang::Boolean* java::lang::Boolean::valueOf(String* arg0)");
    return 0;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::lang::Boolean::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.lang.Boolean", 17);
    return c;
}

java::lang::Class* java::lang::Boolean::getClass0()
{
    return class_();
}

