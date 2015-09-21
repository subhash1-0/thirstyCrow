// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/io/FileInputStream.hpp>

extern void unimplemented_(const char16_t* name);
java::io::FileInputStream::FileInputStream(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::io::FileInputStream::FileInputStream(::java::lang::String* arg0)
    : FileInputStream(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0);
}

java::io::FileInputStream::FileInputStream(File* arg0)
    : FileInputStream(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0);
}

java::io::FileInputStream::FileInputStream(FileDescriptor* arg0)
    : FileInputStream(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0);
}


void ::java::io::FileInputStream::ctor(::java::lang::String* arg0)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::io::FileInputStream::ctor(::java::lang::String* arg0)");
}

void ::java::io::FileInputStream::ctor(File* arg0)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::io::FileInputStream::ctor(File* arg0)");
}

void ::java::io::FileInputStream::ctor(FileDescriptor* arg0)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::io::FileInputStream::ctor(FileDescriptor* arg0)");
}

void java::io::FileInputStream::close()
{ /* stub */
    unimplemented_(u"void java::io::FileInputStream::close()");
}

void java::io::FileInputStream::finalize()
{ /* stub */
    unimplemented_(u"void java::io::FileInputStream::finalize()");
}

java::nio::channels::FileChannel* java::io::FileInputStream::getChannel()
{ /* stub */
return channel ; /* getter */
}

java::io::FileDescriptor* java::io::FileInputStream::getFD()
{ /* stub */
    unimplemented_(u"java::io::FileDescriptor* java::io::FileInputStream::getFD()");
    return 0;
}

/* private: void java::io::FileInputStream::open(::java::lang::String* arg0) */
int32_t java::io::FileInputStream::read()
{ /* stub */
    unimplemented_(u"int32_t java::io::FileInputStream::read()");
    return 0;
}

int32_t java::io::FileInputStream::read(::int8_tArray* arg0)
{ /* stub */
    unimplemented_(u"int32_t java::io::FileInputStream::read(::int8_tArray* arg0)");
    return 0;
}

int32_t java::io::FileInputStream::read(::int8_tArray* arg0, int32_t arg1, int32_t arg2)
{ /* stub */
    unimplemented_(u"int32_t java::io::FileInputStream::read(::int8_tArray* arg0, int32_t arg1, int32_t arg2)");
    return 0;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::io::FileInputStream::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.io.FileInputStream", 23);
    return c;
}

java::lang::Class* java::io::FileInputStream::getClass0()
{
    return class_();
}

