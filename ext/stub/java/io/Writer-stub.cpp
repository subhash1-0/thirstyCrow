// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/io/Writer.hpp>

extern void unimplemented_(const char16_t* name);
java::io::Writer::Writer(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::io::Writer::Writer()
    : Writer(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

java::io::Writer::Writer(::java::lang::Object* arg0)
    : Writer(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0);
}

constexpr int32_t java::io::Writer::WRITE_BUFFER_SIZE;

void ::java::io::Writer::ctor()
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::io::Writer::ctor()");
}

void ::java::io::Writer::ctor(::java::lang::Object* arg0)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::io::Writer::ctor(::java::lang::Object* arg0)");
}

java::io::Writer* java::io::Writer::append(::java::lang::CharSequence* arg0)
{ /* stub */
    unimplemented_(u"java::io::Writer* java::io::Writer::append(::java::lang::CharSequence* arg0)");
    return 0;
}

java::io::Writer* java::io::Writer::append(char16_t arg0)
{ /* stub */
    unimplemented_(u"java::io::Writer* java::io::Writer::append(char16_t arg0)");
    return 0;
}

java::io::Writer* java::io::Writer::append(::java::lang::CharSequence* arg0, int32_t arg1, int32_t arg2)
{ /* stub */
    unimplemented_(u"java::io::Writer* java::io::Writer::append(::java::lang::CharSequence* arg0, int32_t arg1, int32_t arg2)");
    return 0;
}

void java::io::Writer::write(int32_t arg0)
{ /* stub */
    unimplemented_(u"void java::io::Writer::write(int32_t arg0)");
}

void java::io::Writer::write(::char16_tArray* arg0)
{ /* stub */
    unimplemented_(u"void java::io::Writer::write(::char16_tArray* arg0)");
}

void java::io::Writer::write(::java::lang::String* arg0)
{ /* stub */
    unimplemented_(u"void java::io::Writer::write(::java::lang::String* arg0)");
}

void java::io::Writer::write(::java::lang::String* arg0, int32_t arg1, int32_t arg2)
{ /* stub */
    unimplemented_(u"void java::io::Writer::write(::java::lang::String* arg0, int32_t arg1, int32_t arg2)");
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::io::Writer::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.io.Writer", 14);
    return c;
}

java::lang::Class* java::io::Writer::getClass0()
{
    return class_();
}

