// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/text/AttributedCharacterIterator_Attribute.hpp>

extern void unimplemented_(const char16_t* name);
java::text::AttributedCharacterIterator_Attribute::AttributedCharacterIterator_Attribute(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::text::AttributedCharacterIterator_Attribute::AttributedCharacterIterator_Attribute(::java::lang::String* arg0)
    : AttributedCharacterIterator_Attribute(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0);
}

java::text::AttributedCharacterIterator_Attribute*& java::text::AttributedCharacterIterator_Attribute::INPUT_METHOD_SEGMENT()
{
    clinit();
    return INPUT_METHOD_SEGMENT_;
}
java::text::AttributedCharacterIterator_Attribute* java::text::AttributedCharacterIterator_Attribute::INPUT_METHOD_SEGMENT_;
java::text::AttributedCharacterIterator_Attribute*& java::text::AttributedCharacterIterator_Attribute::LANGUAGE()
{
    clinit();
    return LANGUAGE_;
}
java::text::AttributedCharacterIterator_Attribute* java::text::AttributedCharacterIterator_Attribute::LANGUAGE_;
java::text::AttributedCharacterIterator_Attribute*& java::text::AttributedCharacterIterator_Attribute::READING()
{
    clinit();
    return READING_;
}
java::text::AttributedCharacterIterator_Attribute* java::text::AttributedCharacterIterator_Attribute::READING_;
java::util::Map*& java::text::AttributedCharacterIterator_Attribute::instanceMap()
{
    clinit();
    return instanceMap_;
}
java::util::Map* java::text::AttributedCharacterIterator_Attribute::instanceMap_;
constexpr int64_t java::text::AttributedCharacterIterator_Attribute::serialVersionUID;

void ::java::text::AttributedCharacterIterator_Attribute::ctor(::java::lang::String* arg0)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::text::AttributedCharacterIterator_Attribute::ctor(::java::lang::String* arg0)");
}

bool java::text::AttributedCharacterIterator_Attribute::equals(::java::lang::Object* arg0)
{ /* stub */
    unimplemented_(u"bool java::text::AttributedCharacterIterator_Attribute::equals(::java::lang::Object* arg0)");
    return 0;
}

java::lang::String* java::text::AttributedCharacterIterator_Attribute::getName()
{ /* stub */
return name ; /* getter */
}

int32_t java::text::AttributedCharacterIterator_Attribute::hashCode()
{ /* stub */
    unimplemented_(u"int32_t java::text::AttributedCharacterIterator_Attribute::hashCode()");
    return 0;
}

java::lang::Object* java::text::AttributedCharacterIterator_Attribute::readResolve()
{ /* stub */
    unimplemented_(u"java::lang::Object* java::text::AttributedCharacterIterator_Attribute::readResolve()");
    return 0;
}

java::lang::String* java::text::AttributedCharacterIterator_Attribute::toString()
{ /* stub */
    unimplemented_(u"java::lang::String* java::text::AttributedCharacterIterator_Attribute::toString()");
    return 0;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::text::AttributedCharacterIterator_Attribute::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.text.AttributedCharacterIterator.Attribute", 47);
    return c;
}

java::lang::Class* java::text::AttributedCharacterIterator_Attribute::getClass0()
{
    return class_();
}

