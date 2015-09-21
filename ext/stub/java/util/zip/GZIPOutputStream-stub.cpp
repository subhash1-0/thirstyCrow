// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/util/zip/GZIPOutputStream.hpp>

extern void unimplemented_(const char16_t* name);
java::util::zip::GZIPOutputStream::GZIPOutputStream(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::util::zip::GZIPOutputStream::GZIPOutputStream(::java::io::OutputStream* arg0)
    : GZIPOutputStream(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0);
}

java::util::zip::GZIPOutputStream::GZIPOutputStream(::java::io::OutputStream* arg0, int32_t arg1)
    : GZIPOutputStream(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0, arg1);
}

java::util::zip::GZIPOutputStream::GZIPOutputStream(::java::io::OutputStream* arg0, bool arg1)
    : GZIPOutputStream(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0, arg1);
}

java::util::zip::GZIPOutputStream::GZIPOutputStream(::java::io::OutputStream* arg0, int32_t arg1, bool arg2)
    : GZIPOutputStream(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0, arg1, arg2);
}

constexpr int32_t java::util::zip::GZIPOutputStream::GZIP_MAGIC;
constexpr int32_t java::util::zip::GZIPOutputStream::TRAILER_SIZE;

void ::java::util::zip::GZIPOutputStream::ctor(::java::io::OutputStream* arg0)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::util::zip::GZIPOutputStream::ctor(::java::io::OutputStream* arg0)");
}

void ::java::util::zip::GZIPOutputStream::ctor(::java::io::OutputStream* arg0, int32_t arg1)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::util::zip::GZIPOutputStream::ctor(::java::io::OutputStream* arg0, int32_t arg1)");
}

void ::java::util::zip::GZIPOutputStream::ctor(::java::io::OutputStream* arg0, bool arg1)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::util::zip::GZIPOutputStream::ctor(::java::io::OutputStream* arg0, bool arg1)");
}

void ::java::util::zip::GZIPOutputStream::ctor(::java::io::OutputStream* arg0, int32_t arg1, bool arg2)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::util::zip::GZIPOutputStream::ctor(::java::io::OutputStream* arg0, int32_t arg1, bool arg2)");
}

void java::util::zip::GZIPOutputStream::finish()
{ /* stub */
    unimplemented_(u"void java::util::zip::GZIPOutputStream::finish()");
}

void java::util::zip::GZIPOutputStream::write(::int8_tArray* arg0, int32_t arg1, int32_t arg2)
{ /* stub */
    unimplemented_(u"void java::util::zip::GZIPOutputStream::write(::int8_tArray* arg0, int32_t arg1, int32_t arg2)");
}

/* private: void java::util::zip::GZIPOutputStream::writeHeader() */
/* private: void java::util::zip::GZIPOutputStream::writeInt(int32_t arg0, ::int8_tArray* arg1, int32_t arg2) */
/* private: void java::util::zip::GZIPOutputStream::writeShort(int32_t arg0, ::int8_tArray* arg1, int32_t arg2) */
/* private: void java::util::zip::GZIPOutputStream::writeTrailer(::int8_tArray* arg0, int32_t arg1) */
extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::util::zip::GZIPOutputStream::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.util.zip.GZIPOutputStream", 30);
    return c;
}

void java::util::zip::GZIPOutputStream::write(int32_t arg0)
{
    super::write(arg0);
}

void java::util::zip::GZIPOutputStream::write(::int8_tArray* arg0)
{
    super::write(arg0);
}

java::lang::Class* java::util::zip::GZIPOutputStream::getClass0()
{
    return class_();
}

