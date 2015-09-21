// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/text/ParseException.hpp>

extern void unimplemented_(const char16_t* name);
java::text::ParseException::ParseException(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::text::ParseException::ParseException(::java::lang::String* arg0, int32_t arg1)
    : ParseException(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0, arg1);
}

constexpr int64_t java::text::ParseException::serialVersionUID;

void ::java::text::ParseException::ctor(::java::lang::String* arg0, int32_t arg1)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::text::ParseException::ctor(::java::lang::String* arg0, int32_t arg1)");
}

int32_t java::text::ParseException::getErrorOffset()
{ /* stub */
return errorOffset ; /* getter */
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::text::ParseException::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.text.ParseException", 24);
    return c;
}

java::lang::Class* java::text::ParseException::getClass0()
{
    return class_();
}

