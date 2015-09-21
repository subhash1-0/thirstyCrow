// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/lang/ClassLoader.hpp>

template<typename ComponentType, typename... Bases> struct SubArray;
namespace java
{
    namespace io
    {
typedef ::SubArray< ::java::io::Serializable, ::java::lang::ObjectArray > SerializableArray;
    } // io

    namespace lang
    {
typedef ::SubArray< ::java::lang::CharSequence, ObjectArray > CharSequenceArray;
typedef ::SubArray< ::java::lang::Comparable, ObjectArray > ComparableArray;

        namespace reflect
        {
typedef ::SubArray< ::java::lang::reflect::AnnotatedElement, ::java::lang::ObjectArray > AnnotatedElementArray;
        } // reflect
typedef ::SubArray< ::java::lang::Package, ObjectArray, ::java::lang::reflect::AnnotatedElementArray > PackageArray;
typedef ::SubArray< ::java::lang::String, ObjectArray, ::java::io::SerializableArray, ComparableArray, CharSequenceArray > StringArray;
    } // lang

    namespace security
    {
        namespace cert
        {
typedef ::SubArray< ::java::security::cert::Certificate, ::java::lang::ObjectArray, ::java::io::SerializableArray > CertificateArray;
        } // cert
    } // security
} // java

extern void unimplemented_(const char16_t* name);
java::lang::ClassLoader::ClassLoader(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::lang::ClassLoader::ClassLoader()
    : ClassLoader(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

java::lang::ClassLoader::ClassLoader(ClassLoader* arg0)
    : ClassLoader(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0);
}

java::util::Vector*& java::lang::ClassLoader::loadedLibraryNames()
{
    clinit();
    return loadedLibraryNames_;
}
java::util::Vector* java::lang::ClassLoader::loadedLibraryNames_;
java::util::Stack*& java::lang::ClassLoader::nativeLibraryContext()
{
    clinit();
    return nativeLibraryContext_;
}
java::util::Stack* java::lang::ClassLoader::nativeLibraryContext_;
java::security::cert::CertificateArray*& java::lang::ClassLoader::nocerts()
{
    clinit();
    return nocerts_;
}
java::security::cert::CertificateArray* java::lang::ClassLoader::nocerts_;
java::lang::ClassLoader*& java::lang::ClassLoader::scl()
{
    clinit();
    return scl_;
}
java::lang::ClassLoader* java::lang::ClassLoader::scl_;
bool& java::lang::ClassLoader::sclSet()
{
    clinit();
    return sclSet_;
}
bool java::lang::ClassLoader::sclSet_;
java::lang::StringArray*& java::lang::ClassLoader::sys_paths()
{
    clinit();
    return sys_paths_;
}
java::lang::StringArray* java::lang::ClassLoader::sys_paths_;
java::util::Vector*& java::lang::ClassLoader::systemNativeLibraries()
{
    clinit();
    return systemNativeLibraries_;
}
java::util::Vector* java::lang::ClassLoader::systemNativeLibraries_;
java::lang::StringArray*& java::lang::ClassLoader::usr_paths()
{
    clinit();
    return usr_paths_;
}
java::lang::StringArray* java::lang::ClassLoader::usr_paths_;

void ::java::lang::ClassLoader::ctor()
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::lang::ClassLoader::ctor()");
}

void ::java::lang::ClassLoader::ctor(ClassLoader* arg0)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::lang::ClassLoader::ctor(ClassLoader* arg0)");
}

/* private: void ::java::lang::ClassLoader::ctor(Void* arg0, ClassLoader* arg1) */
void java::lang::ClassLoader::addClass(Class* arg0)
{ /* stub */
    unimplemented_(u"void java::lang::ClassLoader::addClass(Class* arg0)");
}

/* private: void java::lang::ClassLoader::checkCerts(String* arg0, ::java::security::CodeSource* arg1) */
void java::lang::ClassLoader::checkClassLoaderPermission(ClassLoader* arg0, Class* arg1)
{ /* stub */
    clinit();
    unimplemented_(u"void java::lang::ClassLoader::checkClassLoaderPermission(ClassLoader* arg0, Class* arg1)");
}

/* private: java::lang::Void* java::lang::ClassLoader::checkCreateClassLoader() */
/* private: bool java::lang::ClassLoader::checkName(String* arg0) */
/* private: void java::lang::ClassLoader::checkPackageAccess(Class* arg0, ::java::security::ProtectionDomain* arg1) */
void java::lang::ClassLoader::clearAssertionStatus()
{ /* stub */
    unimplemented_(u"void java::lang::ClassLoader::clearAssertionStatus()");
}

/* private: bool java::lang::ClassLoader::compareCerts(::java::security::cert::CertificateArray* arg0, ::java::security::cert::CertificateArray* arg1) */
java::lang::Class* java::lang::ClassLoader::defineClass(::int8_tArray* arg0, int32_t arg1, int32_t arg2)
{ /* stub */
    unimplemented_(u"java::lang::Class* java::lang::ClassLoader::defineClass(::int8_tArray* arg0, int32_t arg1, int32_t arg2)");
    return 0;
}

java::lang::Class* java::lang::ClassLoader::defineClass(String* arg0, ::java::nio::ByteBuffer* arg1, ::java::security::ProtectionDomain* arg2)
{ /* stub */
    unimplemented_(u"java::lang::Class* java::lang::ClassLoader::defineClass(String* arg0, ::java::nio::ByteBuffer* arg1, ::java::security::ProtectionDomain* arg2)");
    return 0;
}

java::lang::Class* java::lang::ClassLoader::defineClass(String* arg0, ::int8_tArray* arg1, int32_t arg2, int32_t arg3)
{ /* stub */
    unimplemented_(u"java::lang::Class* java::lang::ClassLoader::defineClass(String* arg0, ::int8_tArray* arg1, int32_t arg2, int32_t arg3)");
    return 0;
}

java::lang::Class* java::lang::ClassLoader::defineClass(String* arg0, ::int8_tArray* arg1, int32_t arg2, int32_t arg3, ::java::security::ProtectionDomain* arg4)
{ /* stub */
    unimplemented_(u"java::lang::Class* java::lang::ClassLoader::defineClass(String* arg0, ::int8_tArray* arg1, int32_t arg2, int32_t arg3, ::java::security::ProtectionDomain* arg4)");
    return 0;
}

/* private: java::lang::String* java::lang::ClassLoader::defineClassSourceLocation(::java::security::ProtectionDomain* arg0) */
java::lang::Package* java::lang::ClassLoader::definePackage(String* arg0, String* arg1, String* arg2, String* arg3, String* arg4, String* arg5, String* arg6, ::java::net::URL* arg7)
{ /* stub */
    unimplemented_(u"java::lang::Package* java::lang::ClassLoader::definePackage(String* arg0, String* arg1, String* arg2, String* arg3, String* arg4, String* arg5, String* arg6, ::java::net::URL* arg7)");
    return 0;
}

bool java::lang::ClassLoader::desiredAssertionStatus(String* arg0)
{ /* stub */
    unimplemented_(u"bool java::lang::ClassLoader::desiredAssertionStatus(String* arg0)");
    return 0;
}

/* private: java::lang::Class* java::lang::ClassLoader::findBootstrapClassOrNull(String* arg0) */
java::lang::Class* java::lang::ClassLoader::findClass(String* arg0)
{ /* stub */
    unimplemented_(u"java::lang::Class* java::lang::ClassLoader::findClass(String* arg0)");
    return 0;
}

java::lang::String* java::lang::ClassLoader::findLibrary(String* arg0)
{ /* stub */
    unimplemented_(u"java::lang::String* java::lang::ClassLoader::findLibrary(String* arg0)");
    return 0;
}

java::lang::Class* java::lang::ClassLoader::findLoadedClass(String* arg0)
{ /* stub */
    unimplemented_(u"java::lang::Class* java::lang::ClassLoader::findLoadedClass(String* arg0)");
    return 0;
}

int64_t java::lang::ClassLoader::findNative(ClassLoader* arg0, String* arg1)
{ /* stub */
    clinit();
    unimplemented_(u"int64_t java::lang::ClassLoader::findNative(ClassLoader* arg0, String* arg1)");
    return 0;
}

java::net::URL* java::lang::ClassLoader::findResource(String* arg0)
{ /* stub */
    unimplemented_(u"java::net::URL* java::lang::ClassLoader::findResource(String* arg0)");
    return 0;
}

java::util::Enumeration* java::lang::ClassLoader::findResources(String* arg0)
{ /* stub */
    unimplemented_(u"java::util::Enumeration* java::lang::ClassLoader::findResources(String* arg0)");
    return 0;
}

java::lang::Class* java::lang::ClassLoader::findSystemClass(String* arg0)
{ /* stub */
    unimplemented_(u"java::lang::Class* java::lang::ClassLoader::findSystemClass(String* arg0)");
    return 0;
}

sun::misc::URLClassPath* java::lang::ClassLoader::getBootstrapClassPath()
{ /* stub */
    clinit();
    unimplemented_(u"sun::misc::URLClassPath* java::lang::ClassLoader::getBootstrapClassPath()");
    return 0;
}

/* private: java::net::URL* java::lang::ClassLoader::getBootstrapResource(String* arg0) */
/* private: java::util::Enumeration* java::lang::ClassLoader::getBootstrapResources(String* arg0) */
java::lang::ClassLoader* java::lang::ClassLoader::getClassLoader(Class* arg0)
{ /* stub */
    clinit();
    unimplemented_(u"java::lang::ClassLoader* java::lang::ClassLoader::getClassLoader(Class* arg0)");
    return 0;
}

java::lang::Object* java::lang::ClassLoader::getClassLoadingLock(String* arg0)
{ /* stub */
    unimplemented_(u"java::lang::Object* java::lang::ClassLoader::getClassLoadingLock(String* arg0)");
    return 0;
}

java::lang::Package* java::lang::ClassLoader::getPackage(String* arg0)
{ /* stub */
    unimplemented_(u"java::lang::Package* java::lang::ClassLoader::getPackage(String* arg0)");
    return 0;
}

java::lang::PackageArray* java::lang::ClassLoader::getPackages()
{ /* stub */
}

java::lang::ClassLoader* java::lang::ClassLoader::getParent()
{ /* stub */
return parent ; /* getter */
}

java::net::URL* java::lang::ClassLoader::getResource(String* arg0)
{ /* stub */
    unimplemented_(u"java::net::URL* java::lang::ClassLoader::getResource(String* arg0)");
    return 0;
}

java::io::InputStream* java::lang::ClassLoader::getResourceAsStream(String* arg0)
{ /* stub */
    unimplemented_(u"java::io::InputStream* java::lang::ClassLoader::getResourceAsStream(String* arg0)");
    return 0;
}

java::util::Enumeration* java::lang::ClassLoader::getResources(String* arg0)
{ /* stub */
    unimplemented_(u"java::util::Enumeration* java::lang::ClassLoader::getResources(String* arg0)");
    return 0;
}

java::lang::ClassLoader* java::lang::ClassLoader::getSystemClassLoader()
{ /* stub */
    clinit();
    unimplemented_(u"java::lang::ClassLoader* java::lang::ClassLoader::getSystemClassLoader()");
    return 0;
}

java::net::URL* java::lang::ClassLoader::getSystemResource(String* arg0)
{ /* stub */
    clinit();
    unimplemented_(u"java::net::URL* java::lang::ClassLoader::getSystemResource(String* arg0)");
    return 0;
}

java::io::InputStream* java::lang::ClassLoader::getSystemResourceAsStream(String* arg0)
{ /* stub */
    clinit();
    unimplemented_(u"java::io::InputStream* java::lang::ClassLoader::getSystemResourceAsStream(String* arg0)");
    return 0;
}

java::util::Enumeration* java::lang::ClassLoader::getSystemResources(String* arg0)
{ /* stub */
    clinit();
    unimplemented_(u"java::util::Enumeration* java::lang::ClassLoader::getSystemResources(String* arg0)");
    return 0;
}

/* private: void java::lang::ClassLoader::initSystemClassLoader() */
/* private: void java::lang::ClassLoader::initializeJavaAssertionMaps() */
/* private: java::lang::StringArray* java::lang::ClassLoader::initializePath(String* arg0) */
bool java::lang::ClassLoader::isAncestor(ClassLoader* arg0)
{ /* stub */
    unimplemented_(u"bool java::lang::ClassLoader::isAncestor(ClassLoader* arg0)");
    return 0;
}

java::lang::Class* java::lang::ClassLoader::loadClass(String* arg0)
{ /* stub */
    unimplemented_(u"java::lang::Class* java::lang::ClassLoader::loadClass(String* arg0)");
    return 0;
}

java::lang::Class* java::lang::ClassLoader::loadClass(String* arg0, bool arg1)
{ /* stub */
    unimplemented_(u"java::lang::Class* java::lang::ClassLoader::loadClass(String* arg0, bool arg1)");
    return 0;
}

/* private: java::lang::Class* java::lang::ClassLoader::loadClassInternal(String* arg0) */
void java::lang::ClassLoader::loadLibrary(Class* arg0, String* arg1, bool arg2)
{ /* stub */
    clinit();
    unimplemented_(u"void java::lang::ClassLoader::loadLibrary(Class* arg0, String* arg1, bool arg2)");
}

/* private: bool java::lang::ClassLoader::loadLibrary0(Class* arg0, ::java::io::File* arg1) */
/* private: bool java::lang::ClassLoader::needsClassLoaderPermissionCheck(ClassLoader* arg0, ClassLoader* arg1) */
/* private: void java::lang::ClassLoader::postDefineClass(Class* arg0, ::java::security::ProtectionDomain* arg1) */
/* private: java::security::ProtectionDomain* java::lang::ClassLoader::preDefineClass(String* arg0, ::java::security::ProtectionDomain* arg1) */
bool java::lang::ClassLoader::registerAsParallelCapable()
{ /* stub */
    clinit();
    unimplemented_(u"bool java::lang::ClassLoader::registerAsParallelCapable()");
    return 0;
}

void java::lang::ClassLoader::resolveClass(Class* arg0)
{ /* stub */
    unimplemented_(u"void java::lang::ClassLoader::resolveClass(Class* arg0)");
}

void java::lang::ClassLoader::setClassAssertionStatus(String* arg0, bool arg1)
{ /* stub */
}

void java::lang::ClassLoader::setDefaultAssertionStatus(bool arg0)
{ /* stub */
    this->defaultAssertionStatus = arg0; /* setter */
}

void java::lang::ClassLoader::setPackageAssertionStatus(String* arg0, bool arg1)
{ /* stub */
}

void java::lang::ClassLoader::setSigners(Class* arg0, ObjectArray* arg1)
{ /* stub */
    unimplemented_(u"void java::lang::ClassLoader::setSigners(Class* arg0, ObjectArray* arg1)");
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::lang::ClassLoader::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.lang.ClassLoader", 21);
    return c;
}

java::lang::Class* java::lang::ClassLoader::getClass0()
{
    return class_();
}

