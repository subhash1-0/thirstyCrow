// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/io/ByteArrayInputStream.hpp>

extern void unimplemented_(const char16_t* name);
java::io::ByteArrayInputStream::ByteArrayInputStream(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::io::ByteArrayInputStream::ByteArrayInputStream(::int8_tArray* arg0)
    : ByteArrayInputStream(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0);
}

java::io::ByteArrayInputStream::ByteArrayInputStream(::int8_tArray* arg0, int32_t arg1, int32_t arg2)
    : ByteArrayInputStream(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0, arg1, arg2);
}


void ::java::io::ByteArrayInputStream::ctor(::int8_tArray* arg0)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::io::ByteArrayInputStream::ctor(::int8_tArray* arg0)");
}

void ::java::io::ByteArrayInputStream::ctor(::int8_tArray* arg0, int32_t arg1, int32_t arg2)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::io::ByteArrayInputStream::ctor(::int8_tArray* arg0, int32_t arg1, int32_t arg2)");
}

int32_t java::io::ByteArrayInputStream::available()
{ /* stub */
    unimplemented_(u"int32_t java::io::ByteArrayInputStream::available()");
    return 0;
}

void java::io::ByteArrayInputStream::close()
{ /* stub */
    unimplemented_(u"void java::io::ByteArrayInputStream::close()");
}

void java::io::ByteArrayInputStream::mark(int32_t arg0)
{ /* stub */
    unimplemented_(u"void java::io::ByteArrayInputStream::mark(int32_t arg0)");
}

bool java::io::ByteArrayInputStream::markSupported()
{ /* stub */
    unimplemented_(u"bool java::io::ByteArrayInputStream::markSupported()");
    return 0;
}

int32_t java::io::ByteArrayInputStream::read()
{ /* stub */
    unimplemented_(u"int32_t java::io::ByteArrayInputStream::read()");
    return 0;
}

int32_t java::io::ByteArrayInputStream::read(::int8_tArray* arg0, int32_t arg1, int32_t arg2)
{ /* stub */
    unimplemented_(u"int32_t java::io::ByteArrayInputStream::read(::int8_tArray* arg0, int32_t arg1, int32_t arg2)");
    return 0;
}

void java::io::ByteArrayInputStream::reset()
{ /* stub */
    unimplemented_(u"void java::io::ByteArrayInputStream::reset()");
}

int64_t java::io::ByteArrayInputStream::skip(int64_t arg0)
{ /* stub */
    unimplemented_(u"int64_t java::io::ByteArrayInputStream::skip(int64_t arg0)");
    return 0;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::io::ByteArrayInputStream::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.io.ByteArrayInputStream", 28);
    return c;
}

int32_t java::io::ByteArrayInputStream::read(::int8_tArray* arg0)
{
    return super::read(arg0);
}

java::lang::Class* java::io::ByteArrayInputStream::getClass0()
{
    return class_();
}

