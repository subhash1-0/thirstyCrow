// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/io/File_TempDirectory.hpp>

extern void unimplemented_(const char16_t* name);
java::io::File_TempDirectory::File_TempDirectory(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::security::SecureRandom*& java::io::File_TempDirectory::random()
{
    clinit();
    return random_;
}
java::security::SecureRandom* java::io::File_TempDirectory::random_;
java::io::File*& java::io::File_TempDirectory::tmpdir()
{
    clinit();
    return tmpdir_;
}
java::io::File* java::io::File_TempDirectory::tmpdir_;

/* private: void ::java::io::File_TempDirectory::ctor() */
java::io::File* java::io::File_TempDirectory::generateFile(::java::lang::String* arg0, ::java::lang::String* arg1, File* arg2)
{ /* stub */
    clinit();
    unimplemented_(u"java::io::File* java::io::File_TempDirectory::generateFile(::java::lang::String* arg0, ::java::lang::String* arg1, File* arg2)");
    return 0;
}

java::io::File* java::io::File_TempDirectory::location()
{ /* stub */
    clinit();
    unimplemented_(u"java::io::File* java::io::File_TempDirectory::location()");
    return 0;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::io::File_TempDirectory::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.io.File.TempDirectory", 26);
    return c;
}

java::lang::Class* java::io::File_TempDirectory::getClass0()
{
    return class_();
}

