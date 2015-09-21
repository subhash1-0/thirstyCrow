// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <atomic>
#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/security/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct default_init_tag;

class java::security::Provider_EngineDescription
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;

private:
    std::atomic< ::java::lang::Class* > constructorParameterClass {  };

public: /* package */
    ::java::lang::String* constructorParameterClassName {  };
    ::java::lang::String* name {  };
    bool supportsParameter {  };

protected:
    void ctor(::java::lang::String* arg0, bool arg1, ::java::lang::String* arg2);

public: /* package */
    virtual ::java::lang::Class* getConstructorParameterClass();

    // Generated
    Provider_EngineDescription(::java::lang::String* arg0, bool arg1, ::java::lang::String* arg2);
protected:
    Provider_EngineDescription(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
