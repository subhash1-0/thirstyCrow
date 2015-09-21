// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/security/AccessController.hpp>

template<typename ComponentType, typename... Bases> struct SubArray;
namespace java
{
    namespace io
    {
typedef ::SubArray< ::java::io::Serializable, ::java::lang::ObjectArray > SerializableArray;
    } // io

    namespace security
    {
typedef ::SubArray< ::java::security::Guard, ::java::lang::ObjectArray > GuardArray;
typedef ::SubArray< ::java::security::Permission, ::java::lang::ObjectArray, GuardArray, ::java::io::SerializableArray > PermissionArray;
    } // security
} // java

extern void unimplemented_(const char16_t* name);
java::security::AccessController::AccessController(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}


/* private: void ::java::security::AccessController::ctor() */
void java::security::AccessController::checkPermission(Permission* arg0)
{ /* stub */
    clinit();
    unimplemented_(u"void java::security::AccessController::checkPermission(Permission* arg0)");
}

/* private: java::security::AccessControlContext* java::security::AccessController::createWrapper(DomainCombiner* arg0, ::java::lang::Class* arg1, AccessControlContext* arg2, AccessControlContext* arg3, PermissionArray* arg4) */
java::lang::Object* java::security::AccessController::doPrivileged(PrivilegedAction* arg0, AccessControlContext* arg1, PermissionArray* arg2)
{ /* stub */
    clinit();
    unimplemented_(u"java::lang::Object* java::security::AccessController::doPrivileged(PrivilegedAction* arg0, AccessControlContext* arg1, PermissionArray* arg2)");
    return 0;
}

java::lang::Object* java::security::AccessController::doPrivileged(PrivilegedExceptionAction* arg0, AccessControlContext* arg1, PermissionArray* arg2)
{ /* stub */
    clinit();
    unimplemented_(u"java::lang::Object* java::security::AccessController::doPrivileged(PrivilegedExceptionAction* arg0, AccessControlContext* arg1, PermissionArray* arg2)");
    return 0;
}

java::lang::Object* java::security::AccessController::doPrivilegedWithCombiner(PrivilegedAction* arg0)
{ /* stub */
    clinit();
    unimplemented_(u"java::lang::Object* java::security::AccessController::doPrivilegedWithCombiner(PrivilegedAction* arg0)");
    return 0;
}

java::lang::Object* java::security::AccessController::doPrivilegedWithCombiner(PrivilegedExceptionAction* arg0)
{ /* stub */
    clinit();
    unimplemented_(u"java::lang::Object* java::security::AccessController::doPrivilegedWithCombiner(PrivilegedExceptionAction* arg0)");
    return 0;
}

java::lang::Object* java::security::AccessController::doPrivilegedWithCombiner(PrivilegedAction* arg0, AccessControlContext* arg1, PermissionArray* arg2)
{ /* stub */
    clinit();
    unimplemented_(u"java::lang::Object* java::security::AccessController::doPrivilegedWithCombiner(PrivilegedAction* arg0, AccessControlContext* arg1, PermissionArray* arg2)");
    return 0;
}

java::lang::Object* java::security::AccessController::doPrivilegedWithCombiner(PrivilegedExceptionAction* arg0, AccessControlContext* arg1, PermissionArray* arg2)
{ /* stub */
    clinit();
    unimplemented_(u"java::lang::Object* java::security::AccessController::doPrivilegedWithCombiner(PrivilegedExceptionAction* arg0, AccessControlContext* arg1, PermissionArray* arg2)");
    return 0;
}

/* private: java::security::ProtectionDomain* java::security::AccessController::getCallerPD(::java::lang::Class* arg0) */
java::security::AccessControlContext* java::security::AccessController::getContext()
{ /* stub */
    clinit();
    unimplemented_(u"java::security::AccessControlContext* java::security::AccessController::getContext()");
    return 0;
}

/* private: java::security::AccessControlContext* java::security::AccessController::preserveCombiner(DomainCombiner* arg0, ::java::lang::Class* arg1) */
extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::security::AccessController::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.security.AccessController", 30);
    return c;
}

java::lang::Class* java::security::AccessController::getClass0()
{
    return class_();
}

