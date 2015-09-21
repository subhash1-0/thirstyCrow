// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/util/zip/GZIPInputStream.hpp>

extern void unimplemented_(const char16_t* name);
java::util::zip::GZIPInputStream::GZIPInputStream(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::util::zip::GZIPInputStream::GZIPInputStream(::java::io::InputStream* arg0)
    : GZIPInputStream(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0);
}

java::util::zip::GZIPInputStream::GZIPInputStream(::java::io::InputStream* arg0, int32_t arg1)
    : GZIPInputStream(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0, arg1);
}

constexpr int32_t java::util::zip::GZIPInputStream::FCOMMENT;
constexpr int32_t java::util::zip::GZIPInputStream::FEXTRA;
constexpr int32_t java::util::zip::GZIPInputStream::FHCRC;
constexpr int32_t java::util::zip::GZIPInputStream::FNAME;
constexpr int32_t java::util::zip::GZIPInputStream::FTEXT;
constexpr int32_t java::util::zip::GZIPInputStream::GZIP_MAGIC;

void ::java::util::zip::GZIPInputStream::ctor(::java::io::InputStream* arg0)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::util::zip::GZIPInputStream::ctor(::java::io::InputStream* arg0)");
}

void ::java::util::zip::GZIPInputStream::ctor(::java::io::InputStream* arg0, int32_t arg1)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::util::zip::GZIPInputStream::ctor(::java::io::InputStream* arg0, int32_t arg1)");
}

void java::util::zip::GZIPInputStream::close()
{ /* stub */
    unimplemented_(u"void java::util::zip::GZIPInputStream::close()");
}

/* private: void java::util::zip::GZIPInputStream::ensureOpen() */
int32_t java::util::zip::GZIPInputStream::read(::int8_tArray* arg0, int32_t arg1, int32_t arg2)
{ /* stub */
    unimplemented_(u"int32_t java::util::zip::GZIPInputStream::read(::int8_tArray* arg0, int32_t arg1, int32_t arg2)");
    return 0;
}

/* private: int32_t java::util::zip::GZIPInputStream::readHeader(::java::io::InputStream* arg0) */
/* private: bool java::util::zip::GZIPInputStream::readTrailer() */
/* private: int32_t java::util::zip::GZIPInputStream::readUByte(::java::io::InputStream* arg0) */
/* private: int64_t java::util::zip::GZIPInputStream::readUInt(::java::io::InputStream* arg0) */
/* private: int32_t java::util::zip::GZIPInputStream::readUShort(::java::io::InputStream* arg0) */
/* private: void java::util::zip::GZIPInputStream::skipBytes(::java::io::InputStream* arg0, int32_t arg1) */
extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::util::zip::GZIPInputStream::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.util.zip.GZIPInputStream", 29);
    return c;
}

int32_t java::util::zip::GZIPInputStream::read()
{
    return super::read();
}

int32_t java::util::zip::GZIPInputStream::read(::int8_tArray* arg0)
{
    return super::read(arg0);
}

java::lang::Class* java::util::zip::GZIPInputStream::getClass0()
{
    return class_();
}

