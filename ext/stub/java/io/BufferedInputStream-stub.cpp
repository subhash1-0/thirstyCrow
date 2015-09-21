// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/io/BufferedInputStream.hpp>

extern void unimplemented_(const char16_t* name);
java::io::BufferedInputStream::BufferedInputStream(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::io::BufferedInputStream::BufferedInputStream(InputStream* arg0)
    : BufferedInputStream(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0);
}

java::io::BufferedInputStream::BufferedInputStream(InputStream* arg0, int32_t arg1)
    : BufferedInputStream(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0, arg1);
}

int32_t& java::io::BufferedInputStream::DEFAULT_BUFFER_SIZE()
{
    clinit();
    return DEFAULT_BUFFER_SIZE_;
}
int32_t java::io::BufferedInputStream::DEFAULT_BUFFER_SIZE_;
int32_t& java::io::BufferedInputStream::MAX_BUFFER_SIZE()
{
    clinit();
    return MAX_BUFFER_SIZE_;
}
int32_t java::io::BufferedInputStream::MAX_BUFFER_SIZE_;
java::util::concurrent::atomic::AtomicReferenceFieldUpdater*& java::io::BufferedInputStream::bufUpdater()
{
    clinit();
    return bufUpdater_;
}
java::util::concurrent::atomic::AtomicReferenceFieldUpdater* java::io::BufferedInputStream::bufUpdater_;

void ::java::io::BufferedInputStream::ctor(InputStream* arg0)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::io::BufferedInputStream::ctor(InputStream* arg0)");
}

void ::java::io::BufferedInputStream::ctor(InputStream* arg0, int32_t arg1)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::io::BufferedInputStream::ctor(InputStream* arg0, int32_t arg1)");
}

int32_t java::io::BufferedInputStream::available()
{ /* stub */
    unimplemented_(u"int32_t java::io::BufferedInputStream::available()");
    return 0;
}

void java::io::BufferedInputStream::close()
{ /* stub */
    unimplemented_(u"void java::io::BufferedInputStream::close()");
}

/* private: void java::io::BufferedInputStream::fill() */
/* private: int8_tArray* java::io::BufferedInputStream::getBufIfOpen() */
/* private: java::io::InputStream* java::io::BufferedInputStream::getInIfOpen() */
void java::io::BufferedInputStream::mark(int32_t arg0)
{ /* stub */
    unimplemented_(u"void java::io::BufferedInputStream::mark(int32_t arg0)");
}

bool java::io::BufferedInputStream::markSupported()
{ /* stub */
    unimplemented_(u"bool java::io::BufferedInputStream::markSupported()");
    return 0;
}

int32_t java::io::BufferedInputStream::read()
{ /* stub */
    unimplemented_(u"int32_t java::io::BufferedInputStream::read()");
    return 0;
}

int32_t java::io::BufferedInputStream::read(::int8_tArray* arg0, int32_t arg1, int32_t arg2)
{ /* stub */
    unimplemented_(u"int32_t java::io::BufferedInputStream::read(::int8_tArray* arg0, int32_t arg1, int32_t arg2)");
    return 0;
}

/* private: int32_t java::io::BufferedInputStream::read1(::int8_tArray* arg0, int32_t arg1, int32_t arg2) */
void java::io::BufferedInputStream::reset()
{ /* stub */
    unimplemented_(u"void java::io::BufferedInputStream::reset()");
}

int64_t java::io::BufferedInputStream::skip(int64_t arg0)
{ /* stub */
    unimplemented_(u"int64_t java::io::BufferedInputStream::skip(int64_t arg0)");
    return 0;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::io::BufferedInputStream::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.io.BufferedInputStream", 27);
    return c;
}

int32_t java::io::BufferedInputStream::read(::int8_tArray* arg0)
{
    return super::read(arg0);
}

java::lang::Class* java::io::BufferedInputStream::getClass0()
{
    return class_();
}

