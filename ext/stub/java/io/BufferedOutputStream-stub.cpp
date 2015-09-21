// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/io/BufferedOutputStream.hpp>

extern void unimplemented_(const char16_t* name);
java::io::BufferedOutputStream::BufferedOutputStream(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::io::BufferedOutputStream::BufferedOutputStream(OutputStream* arg0)
    : BufferedOutputStream(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0);
}

java::io::BufferedOutputStream::BufferedOutputStream(OutputStream* arg0, int32_t arg1)
    : BufferedOutputStream(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0, arg1);
}


void ::java::io::BufferedOutputStream::ctor(OutputStream* arg0)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::io::BufferedOutputStream::ctor(OutputStream* arg0)");
}

void ::java::io::BufferedOutputStream::ctor(OutputStream* arg0, int32_t arg1)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::io::BufferedOutputStream::ctor(OutputStream* arg0, int32_t arg1)");
}

void java::io::BufferedOutputStream::flush()
{ /* stub */
    unimplemented_(u"void java::io::BufferedOutputStream::flush()");
}

/* private: void java::io::BufferedOutputStream::flushBuffer() */
void java::io::BufferedOutputStream::write(int32_t arg0)
{ /* stub */
    unimplemented_(u"void java::io::BufferedOutputStream::write(int32_t arg0)");
}

void java::io::BufferedOutputStream::write(::int8_tArray* arg0, int32_t arg1, int32_t arg2)
{ /* stub */
    unimplemented_(u"void java::io::BufferedOutputStream::write(::int8_tArray* arg0, int32_t arg1, int32_t arg2)");
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::io::BufferedOutputStream::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.io.BufferedOutputStream", 28);
    return c;
}

void java::io::BufferedOutputStream::write(::int8_tArray* b)
{
    super::write(b);
}

java::lang::Class* java::io::BufferedOutputStream::getClass0()
{
    return class_();
}

