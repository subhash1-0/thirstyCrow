// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/io/FileOutputStream.hpp>

extern void unimplemented_(const char16_t* name);
java::io::FileOutputStream::FileOutputStream(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::io::FileOutputStream::FileOutputStream(::java::lang::String* arg0)
    : FileOutputStream(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0);
}

java::io::FileOutputStream::FileOutputStream(File* arg0)
    : FileOutputStream(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0);
}

java::io::FileOutputStream::FileOutputStream(FileDescriptor* arg0)
    : FileOutputStream(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0);
}

java::io::FileOutputStream::FileOutputStream(::java::lang::String* arg0, bool arg1)
    : FileOutputStream(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0, arg1);
}

java::io::FileOutputStream::FileOutputStream(File* arg0, bool arg1)
    : FileOutputStream(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0, arg1);
}


void ::java::io::FileOutputStream::ctor(::java::lang::String* arg0)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::io::FileOutputStream::ctor(::java::lang::String* arg0)");
}

void ::java::io::FileOutputStream::ctor(File* arg0)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::io::FileOutputStream::ctor(File* arg0)");
}

void ::java::io::FileOutputStream::ctor(FileDescriptor* arg0)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::io::FileOutputStream::ctor(FileDescriptor* arg0)");
}

void ::java::io::FileOutputStream::ctor(::java::lang::String* arg0, bool arg1)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::io::FileOutputStream::ctor(::java::lang::String* arg0, bool arg1)");
}

void ::java::io::FileOutputStream::ctor(File* arg0, bool arg1)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::io::FileOutputStream::ctor(File* arg0, bool arg1)");
}

void java::io::FileOutputStream::close()
{ /* stub */
    unimplemented_(u"void java::io::FileOutputStream::close()");
}

void java::io::FileOutputStream::finalize()
{ /* stub */
    unimplemented_(u"void java::io::FileOutputStream::finalize()");
}

java::nio::channels::FileChannel* java::io::FileOutputStream::getChannel()
{ /* stub */
return channel ; /* getter */
}

java::io::FileDescriptor* java::io::FileOutputStream::getFD()
{ /* stub */
    unimplemented_(u"java::io::FileDescriptor* java::io::FileOutputStream::getFD()");
    return 0;
}

/* private: void java::io::FileOutputStream::open(::java::lang::String* arg0, bool arg1) */
void java::io::FileOutputStream::write(int32_t arg0)
{ /* stub */
    unimplemented_(u"void java::io::FileOutputStream::write(int32_t arg0)");
}

void java::io::FileOutputStream::write(::int8_tArray* arg0)
{ /* stub */
    unimplemented_(u"void java::io::FileOutputStream::write(::int8_tArray* arg0)");
}

void java::io::FileOutputStream::write(::int8_tArray* arg0, int32_t arg1, int32_t arg2)
{ /* stub */
    unimplemented_(u"void java::io::FileOutputStream::write(::int8_tArray* arg0, int32_t arg1, int32_t arg2)");
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::io::FileOutputStream::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.io.FileOutputStream", 24);
    return c;
}

java::lang::Class* java::io::FileOutputStream::getClass0()
{
    return class_();
}

