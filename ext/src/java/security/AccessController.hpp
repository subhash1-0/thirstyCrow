// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/security/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

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

struct default_init_tag;

class java::security::AccessController final
    : public ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;

    /*void ctor(); (private) */
    static void checkPermission(Permission* arg0);
    /*static AccessControlContext* createWrapper(DomainCombiner* arg0, ::java::lang::Class* arg1, AccessControlContext* arg2, AccessControlContext* arg3, PermissionArray* arg4); (private) */
    static ::java::lang::Object* doPrivileged(PrivilegedAction* arg0);
    static ::java::lang::Object* doPrivileged(PrivilegedExceptionAction* arg0);
    static ::java::lang::Object* doPrivileged(PrivilegedAction* arg0, AccessControlContext* arg1);
    static ::java::lang::Object* doPrivileged(PrivilegedExceptionAction* arg0, AccessControlContext* arg1);
    static ::java::lang::Object* doPrivileged(PrivilegedAction* arg0, AccessControlContext* arg1, PermissionArray* arg2);
    static ::java::lang::Object* doPrivileged(PrivilegedExceptionAction* arg0, AccessControlContext* arg1, PermissionArray* arg2);
    static ::java::lang::Object* doPrivilegedWithCombiner(PrivilegedAction* arg0);
    static ::java::lang::Object* doPrivilegedWithCombiner(PrivilegedExceptionAction* arg0);
    static ::java::lang::Object* doPrivilegedWithCombiner(PrivilegedAction* arg0, AccessControlContext* arg1, PermissionArray* arg2);
    static ::java::lang::Object* doPrivilegedWithCombiner(PrivilegedExceptionAction* arg0, AccessControlContext* arg1, PermissionArray* arg2);
    /*static ProtectionDomain* getCallerPD(::java::lang::Class* arg0); (private) */
    static AccessControlContext* getContext();

public: /* package */
    static AccessControlContext* getInheritedAccessControlContext();
    /*static AccessControlContext* getStackAccessControlContext(); (private) */
    /*static AccessControlContext* preserveCombiner(DomainCombiner* arg0, ::java::lang::Class* arg1); (private) */

    // Generated

public:
    AccessController();
protected:
    AccessController(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
