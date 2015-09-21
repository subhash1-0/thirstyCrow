// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <sun/reflect/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <java/security/PrivilegedAction.hpp>
#include <sun/reflect/ReflectionFactory.hpp>

struct default_init_tag;

class sun::reflect::ReflectionFactory_GetReflectionFactoryAction final
    : public virtual ::java::lang::Object
    , public ::java::security::PrivilegedAction
{

public:
    typedef ::java::lang::Object super;

protected:
    void ctor();

public:
    ReflectionFactory* run() override;

    // Generated
    ReflectionFactory_GetReflectionFactoryAction();
protected:
    ReflectionFactory_GetReflectionFactoryAction(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
