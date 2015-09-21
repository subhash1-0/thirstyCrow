// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/lang/reflect/fwd-pastry-2.1.hpp>
#include <java/net/fwd-pastry-2.1.hpp>
#include <java/nio/fwd-pastry-2.1.hpp>
#include <java/security/fwd-pastry-2.1.hpp>
#include <java/security/cert/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <java/util/concurrent/fwd-pastry-2.1.hpp>
#include <sun/misc/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

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

struct default_init_tag;

class java::lang::ClassLoader
    : public virtual Object
{

public:
    typedef Object super;

public: /* package */
    Object* assertionLock {  };
    ::java::util::Map* classAssertionStatus {  };

private:
    ::java::util::Vector* classes {  };
    bool defaultAssertionStatus {  };
    ::java::security::ProtectionDomain* defaultDomain {  };
    ::java::util::Set* domains {  };
    static ::java::util::Vector* loadedLibraryNames_;
    ::java::util::Vector* nativeLibraries {  };
    static ::java::util::Stack* nativeLibraryContext_;
    static ::java::security::cert::CertificateArray* nocerts_;
    ::java::util::Map* package2certs {  };
    ::java::util::Map* packageAssertionStatus {  };
    ::java::util::HashMap* packages {  };
    ::java::util::concurrent::ConcurrentHashMap* parallelLockMap {  };
    ClassLoader* parent {  };
    static ClassLoader* scl_;
    static bool sclSet_;
    static StringArray* sys_paths_;
    static ::java::util::Vector* systemNativeLibraries_;
    static StringArray* usr_paths_;

protected:
    void ctor();
    void ctor(ClassLoader* arg0);
    /*void ctor(Void* arg0, ClassLoader* arg1); (private) */

public: /* package */
    virtual void addClass(Class* arg0);
    /*void checkCerts(String* arg0, ::java::security::CodeSource* arg1); (private) */
    static void checkClassLoaderPermission(ClassLoader* arg0, Class* arg1);
    /*static Void* checkCreateClassLoader(); (private) */
    /*bool checkName(String* arg0); (private) */
    /*void checkPackageAccess(Class* arg0, ::java::security::ProtectionDomain* arg1); (private) */

public:
    virtual void clearAssertionStatus();
    /*bool compareCerts(::java::security::cert::CertificateArray* arg0, ::java::security::cert::CertificateArray* arg1); (private) */

public: /* protected */
    Class* defineClass(::int8_tArray* arg0, int32_t arg1, int32_t arg2);
    Class* defineClass(String* arg0, ::java::nio::ByteBuffer* arg1, ::java::security::ProtectionDomain* arg2);
    Class* defineClass(String* arg0, ::int8_tArray* arg1, int32_t arg2, int32_t arg3);
    Class* defineClass(String* arg0, ::int8_tArray* arg1, int32_t arg2, int32_t arg3, ::java::security::ProtectionDomain* arg4);
    /*Class* defineClass0(String* arg0, ::int8_tArray* arg1, int32_t arg2, int32_t arg3, ::java::security::ProtectionDomain* arg4); (private) */
    /*Class* defineClass1(String* arg0, ::int8_tArray* arg1, int32_t arg2, int32_t arg3, ::java::security::ProtectionDomain* arg4, String* arg5); (private) */
    /*Class* defineClass2(String* arg0, ::java::nio::ByteBuffer* arg1, int32_t arg2, int32_t arg3, ::java::security::ProtectionDomain* arg4, String* arg5); (private) */
    /*String* defineClassSourceLocation(::java::security::ProtectionDomain* arg0); (private) */
    virtual Package* definePackage(String* arg0, String* arg1, String* arg2, String* arg3, String* arg4, String* arg5, String* arg6, ::java::net::URL* arg7);

public: /* package */
    virtual bool desiredAssertionStatus(String* arg0);
    /*Class* findBootstrapClass(String* arg0); (private) */
    /*Class* findBootstrapClassOrNull(String* arg0); (private) */

public: /* protected */
    virtual Class* findClass(String* arg0);
    virtual String* findLibrary(String* arg0);
    Class* findLoadedClass(String* arg0);
    /*Class* findLoadedClass0(String* arg0); (private) */

public: /* package */
    static int64_t findNative(ClassLoader* arg0, String* arg1);

public: /* protected */
    virtual ::java::net::URL* findResource(String* arg0);
    virtual ::java::util::Enumeration* findResources(String* arg0);
    Class* findSystemClass(String* arg0);

public: /* package */
    static ::sun::misc::URLClassPath* getBootstrapClassPath();
    /*static ::java::net::URL* getBootstrapResource(String* arg0); (private) */
    /*static ::java::util::Enumeration* getBootstrapResources(String* arg0); (private) */
    static ClassLoader* getClassLoader(Class* arg0);

public: /* protected */
    virtual Object* getClassLoadingLock(String* arg0);
    virtual Package* getPackage(String* arg0);
    virtual PackageArray* getPackages();

public:
    ClassLoader* getParent();
    virtual ::java::net::URL* getResource(String* arg0);
    virtual ::java::io::InputStream* getResourceAsStream(String* arg0);
    virtual ::java::util::Enumeration* getResources(String* arg0);
    static ClassLoader* getSystemClassLoader();
    static ::java::net::URL* getSystemResource(String* arg0);
    static ::java::io::InputStream* getSystemResourceAsStream(String* arg0);
    static ::java::util::Enumeration* getSystemResources(String* arg0);
    /*static void initSystemClassLoader(); (private) */
    /*void initializeJavaAssertionMaps(); (private) */
    /*static StringArray* initializePath(String* arg0); (private) */

public: /* package */
    virtual bool isAncestor(ClassLoader* arg0);

public:
    virtual Class* loadClass(String* arg0);

public: /* protected */
    virtual Class* loadClass(String* arg0, bool arg1);
    /*Class* loadClassInternal(String* arg0); (private) */

public: /* package */
    static void loadLibrary(Class* arg0, String* arg1, bool arg2);
    /*static bool loadLibrary0(Class* arg0, ::java::io::File* arg1); (private) */
    /*static bool needsClassLoaderPermissionCheck(ClassLoader* arg0, ClassLoader* arg1); (private) */
    /*void postDefineClass(Class* arg0, ::java::security::ProtectionDomain* arg1); (private) */
    /*::java::security::ProtectionDomain* preDefineClass(String* arg0, ::java::security::ProtectionDomain* arg1); (private) */

public: /* protected */
    static bool registerAsParallelCapable();
    /*static void registerNatives(); (private) */
    void resolveClass(Class* arg0);
    /*void resolveClass0(Class* arg0); (private) */
    /*static AssertionStatusDirectives* retrieveDirectives(); (private) */

public:
    virtual void setClassAssertionStatus(String* arg0, bool arg1);
    virtual void setDefaultAssertionStatus(bool arg0);
    virtual void setPackageAssertionStatus(String* arg0, bool arg1);

public: /* protected */
    void setSigners(Class* arg0, ObjectArray* arg1);

    // Generated
    ClassLoader();
    ClassLoader(ClassLoader* arg0);
protected:
    ClassLoader(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    static ::java::util::Vector*& loadedLibraryNames();
    static ::java::util::Stack*& nativeLibraryContext();
    static ::java::security::cert::CertificateArray*& nocerts();
    static ClassLoader*& scl();
    static bool& sclSet();
    static StringArray*& sys_paths();
    static ::java::util::Vector*& systemNativeLibraries();
    static StringArray*& usr_paths();
    virtual ::java::lang::Class* getClass0();
};
