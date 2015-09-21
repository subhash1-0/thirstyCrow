// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/io/FilterInputStream.hpp>

extern void unimplemented_(const char16_t* name);
java::io::FilterInputStream::FilterInputStream(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::io::FilterInputStream::FilterInputStream(InputStream* arg0)
    : FilterInputStream(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0);
}


void ::java::io::FilterInputStream::ctor(InputStream* arg0)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::io::FilterInputStream::ctor(InputStream* arg0)");
}

int32_t java::io::FilterInputStream::available()
{ /* stub */
    unimplemented_(u"int32_t java::io::FilterInputStream::available()");
    return 0;
}

void java::io::FilterInputStream::close()
{ /* stub */
    unimplemented_(u"void java::io::FilterInputStream::close()");
}

void java::io::FilterInputStream::mark(int32_t arg0)
{ /* stub */
    unimplemented_(u"void java::io::FilterInputStream::mark(int32_t arg0)");
}

bool java::io::FilterInputStream::markSupported()
{ /* stub */
    unimplemented_(u"bool java::io::FilterInputStream::markSupported()");
    return 0;
}

int32_t java::io::FilterInputStream::read()
{ /* stub */
    unimplemented_(u"int32_t java::io::FilterInputStream::read()");
    return 0;
}

int32_t java::io::FilterInputStream::read(::int8_tArray* arg0)
{ /* stub */
    unimplemented_(u"int32_t java::io::FilterInputStream::read(::int8_tArray* arg0)");
    return 0;
}

int32_t java::io::FilterInputStream::read(::int8_tArray* arg0, int32_t arg1, int32_t arg2)
{ /* stub */
    unimplemented_(u"int32_t java::io::FilterInputStream::read(::int8_tArray* arg0, int32_t arg1, int32_t arg2)");
    return 0;
}

void java::io::FilterInputStream::reset()
{ /* stub */
    unimplemented_(u"void java::io::FilterInputStream::reset()");
}

int64_t java::io::FilterInputStream::skip(int64_t arg0)
{ /* stub */
    unimplemented_(u"int64_t java::io::FilterInputStream::skip(int64_t arg0)");
    return 0;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::io::FilterInputStream::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.io.FilterInputStream", 25);
    return c;
}

java::lang::Class* java::io::FilterInputStream::getClass0()
{
    return class_();
}

