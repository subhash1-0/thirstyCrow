// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/io/BufferedWriter.hpp>

extern void unimplemented_(const char16_t* name);
java::io::BufferedWriter::BufferedWriter(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::io::BufferedWriter::BufferedWriter(Writer* arg0)
    : BufferedWriter(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0);
}

java::io::BufferedWriter::BufferedWriter(Writer* arg0, int32_t arg1)
    : BufferedWriter(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0, arg1);
}

int32_t& java::io::BufferedWriter::defaultCharBufferSize()
{
    clinit();
    return defaultCharBufferSize_;
}
int32_t java::io::BufferedWriter::defaultCharBufferSize_;

void ::java::io::BufferedWriter::ctor(Writer* arg0)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::io::BufferedWriter::ctor(Writer* arg0)");
}

void ::java::io::BufferedWriter::ctor(Writer* arg0, int32_t arg1)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::io::BufferedWriter::ctor(Writer* arg0, int32_t arg1)");
}

void java::io::BufferedWriter::close()
{ /* stub */
    unimplemented_(u"void java::io::BufferedWriter::close()");
}

/* private: void java::io::BufferedWriter::ensureOpen() */
void java::io::BufferedWriter::flush()
{ /* stub */
    unimplemented_(u"void java::io::BufferedWriter::flush()");
}

void java::io::BufferedWriter::flushBuffer()
{ /* stub */
    unimplemented_(u"void java::io::BufferedWriter::flushBuffer()");
}

/* private: int32_t java::io::BufferedWriter::min(int32_t arg0, int32_t arg1) */
void java::io::BufferedWriter::newLine()
{ /* stub */
    unimplemented_(u"void java::io::BufferedWriter::newLine()");
}

void java::io::BufferedWriter::write(int32_t arg0)
{ /* stub */
    unimplemented_(u"void java::io::BufferedWriter::write(int32_t arg0)");
}

void java::io::BufferedWriter::write(::char16_tArray* arg0, int32_t arg1, int32_t arg2)
{ /* stub */
    unimplemented_(u"void java::io::BufferedWriter::write(::char16_tArray* arg0, int32_t arg1, int32_t arg2)");
}

void java::io::BufferedWriter::write(::java::lang::String* arg0, int32_t arg1, int32_t arg2)
{ /* stub */
    unimplemented_(u"void java::io::BufferedWriter::write(::java::lang::String* arg0, int32_t arg1, int32_t arg2)");
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::io::BufferedWriter::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.io.BufferedWriter", 22);
    return c;
}

void java::io::BufferedWriter::write(::char16_tArray* arg0)
{
    super::write(arg0);
}

void java::io::BufferedWriter::write(::java::lang::String* arg0)
{
    super::write(arg0);
}

java::lang::Class* java::io::BufferedWriter::getClass0()
{
    return class_();
}

