// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/lang/Short.hpp>

extern void unimplemented_(const char16_t* name);
java::lang::Short::Short(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::lang::Short::Short(int16_t value)
    : Short(*static_cast< ::default_init_tag* >(0))
{
    ctor(value);
}

java::lang::Short::Short(String* s)
    : Short(*static_cast< ::default_init_tag* >(0))
{
    ctor(s);
}

constexpr int32_t java::lang::Short::BYTES;
constexpr int16_t java::lang::Short::MAX_VALUE;
constexpr int16_t java::lang::Short::MIN_VALUE;
constexpr int32_t java::lang::Short::SIZE;
java::lang::Class*& java::lang::Short::TYPE()
{
    clinit();
    return TYPE_;
}
java::lang::Class* java::lang::Short::TYPE_;
constexpr int64_t java::lang::Short::serialVersionUID;

void ::java::lang::Short::ctor(int16_t value)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::lang::Short::ctor(int16_t value)");
}

void ::java::lang::Short::ctor(String* s)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::lang::Short::ctor(String* s)");
}

int8_t java::lang::Short::byteValue()
{ /* stub */
    unimplemented_(u"int8_t java::lang::Short::byteValue()");
    return 0;
}

int32_t java::lang::Short::compare(int16_t x, int16_t y)
{ /* stub */
    clinit();
    unimplemented_(u"int32_t java::lang::Short::compare(int16_t x, int16_t y)");
    return 0;
}

int32_t java::lang::Short::compareTo(Short* anotherShort)
{ /* stub */
    unimplemented_(u"int32_t java::lang::Short::compareTo(Short* anotherShort)");
    return 0;
}

int32_t java::lang::Short::compareTo(Object* arg0)
{ 
    return compareTo(dynamic_cast< Short* >(arg0));
}

java::lang::Short* java::lang::Short::decode(String* nm)
{ /* stub */
    clinit();
    unimplemented_(u"java::lang::Short* java::lang::Short::decode(String* nm)");
    return 0;
}

double java::lang::Short::doubleValue()
{ /* stub */
    unimplemented_(u"double java::lang::Short::doubleValue()");
    return 0;
}

bool java::lang::Short::equals(Object* obj)
{ /* stub */
    unimplemented_(u"bool java::lang::Short::equals(Object* obj)");
    return 0;
}

float java::lang::Short::floatValue()
{ /* stub */
    unimplemented_(u"float java::lang::Short::floatValue()");
    return 0;
}

int32_t java::lang::Short::hashCode()
{ /* stub */
    unimplemented_(u"int32_t java::lang::Short::hashCode()");
    return 0;
}

int32_t java::lang::Short::hashCode(int16_t value)
{ /* stub */
    clinit();
    unimplemented_(u"int32_t java::lang::Short::hashCode(int16_t value)");
    return 0;
}

int32_t java::lang::Short::intValue()
{ /* stub */
    unimplemented_(u"int32_t java::lang::Short::intValue()");
    return 0;
}

int64_t java::lang::Short::longValue()
{ /* stub */
    unimplemented_(u"int64_t java::lang::Short::longValue()");
    return 0;
}

int16_t java::lang::Short::parseShort(String* s)
{ /* stub */
    clinit();
    unimplemented_(u"int16_t java::lang::Short::parseShort(String* s)");
    return 0;
}

int16_t java::lang::Short::parseShort(String* s, int32_t radix)
{ /* stub */
    clinit();
    unimplemented_(u"int16_t java::lang::Short::parseShort(String* s, int32_t radix)");
    return 0;
}

int16_t java::lang::Short::reverseBytes(int16_t i)
{ /* stub */
    clinit();
    unimplemented_(u"int16_t java::lang::Short::reverseBytes(int16_t i)");
    return 0;
}

int16_t java::lang::Short::shortValue()
{ /* stub */
    unimplemented_(u"int16_t java::lang::Short::shortValue()");
    return 0;
}

java::lang::String* java::lang::Short::toString()
{ /* stub */
    unimplemented_(u"java::lang::String* java::lang::Short::toString()");
    return 0;
}

java::lang::String* java::lang::Short::toString(int16_t s)
{ /* stub */
    clinit();
    unimplemented_(u"java::lang::String* java::lang::Short::toString(int16_t s)");
    return 0;
}

int32_t java::lang::Short::toUnsignedInt(int16_t x)
{ /* stub */
    clinit();
    unimplemented_(u"int32_t java::lang::Short::toUnsignedInt(int16_t x)");
    return 0;
}

int64_t java::lang::Short::toUnsignedLong(int16_t x)
{ /* stub */
    clinit();
    unimplemented_(u"int64_t java::lang::Short::toUnsignedLong(int16_t x)");
    return 0;
}

java::lang::Short* java::lang::Short::valueOf(String* s)
{ /* stub */
    clinit();
    unimplemented_(u"java::lang::Short* java::lang::Short::valueOf(String* s)");
    return 0;
}

java::lang::Short* java::lang::Short::valueOf(int16_t s)
{ /* stub */
    clinit();
    unimplemented_(u"java::lang::Short* java::lang::Short::valueOf(int16_t s)");
    return 0;
}

java::lang::Short* java::lang::Short::valueOf(String* s, int32_t radix)
{ /* stub */
    clinit();
    unimplemented_(u"java::lang::Short* java::lang::Short::valueOf(String* s, int32_t radix)");
    return 0;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::lang::Short::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.lang.Short", 15);
    return c;
}

java::lang::Class* java::lang::Short::getClass0()
{
    return class_();
}

