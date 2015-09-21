// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/io/InputStream.hpp>

extern void unimplemented_(const char16_t* name);
java::io::InputStream::InputStream(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::io::InputStream::InputStream()
    : InputStream(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

constexpr int32_t java::io::InputStream::MAX_SKIP_BUFFER_SIZE;

void ::java::io::InputStream::ctor()
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::io::InputStream::ctor()");
}

int32_t java::io::InputStream::available()
{ /* stub */
    unimplemented_(u"int32_t java::io::InputStream::available()");
    return 0;
}

void java::io::InputStream::close()
{ /* stub */
    unimplemented_(u"void java::io::InputStream::close()");
}

void java::io::InputStream::mark(int32_t arg0)
{ /* stub */
    unimplemented_(u"void java::io::InputStream::mark(int32_t arg0)");
}

bool java::io::InputStream::markSupported()
{ /* stub */
    unimplemented_(u"bool java::io::InputStream::markSupported()");
    return 0;
}

int32_t java::io::InputStream::read(::int8_tArray* arg0)
{ /* stub */
    unimplemented_(u"int32_t java::io::InputStream::read(::int8_tArray* arg0)");
    return 0;
}

int32_t java::io::InputStream::read(::int8_tArray* arg0, int32_t arg1, int32_t arg2)
{ /* stub */
    unimplemented_(u"int32_t java::io::InputStream::read(::int8_tArray* arg0, int32_t arg1, int32_t arg2)");
    return 0;
}

void java::io::InputStream::reset()
{ /* stub */
    unimplemented_(u"void java::io::InputStream::reset()");
}

int64_t java::io::InputStream::skip(int64_t arg0)
{ /* stub */
    unimplemented_(u"int64_t java::io::InputStream::skip(int64_t arg0)");
    return 0;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::io::InputStream::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.io.InputStream", 19);
    return c;
}

java::lang::Class* java::io::InputStream::getClass0()
{
    return class_();
}

