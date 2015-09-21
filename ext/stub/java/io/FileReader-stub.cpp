// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/io/FileReader.hpp>

extern void unimplemented_(const char16_t* name);
java::io::FileReader::FileReader(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::io::FileReader::FileReader(::java::lang::String* arg0)
    : FileReader(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0);
}

java::io::FileReader::FileReader(File* arg0)
    : FileReader(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0);
}

java::io::FileReader::FileReader(FileDescriptor* arg0)
    : FileReader(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0);
}


void ::java::io::FileReader::ctor(::java::lang::String* arg0)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::io::FileReader::ctor(::java::lang::String* arg0)");
}

void ::java::io::FileReader::ctor(File* arg0)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::io::FileReader::ctor(File* arg0)");
}

void ::java::io::FileReader::ctor(FileDescriptor* arg0)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::io::FileReader::ctor(FileDescriptor* arg0)");
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::io::FileReader::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.io.FileReader", 18);
    return c;
}

java::lang::Class* java::io::FileReader::getClass0()
{
    return class_();
}

