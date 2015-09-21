// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/security/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct default_init_tag;

class java::security::Provider_ServiceKey
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;

private:
    ::java::lang::String* algorithm {  };
    ::java::lang::String* originalAlgorithm {  };
    ::java::lang::String* type {  };

    /*void ctor(::java::lang::String* arg0, ::java::lang::String* arg1, bool arg2); (private) */

public:
    bool equals(::java::lang::Object* arg0) override;
    int32_t hashCode() override;

public: /* package */
    virtual bool matches(::java::lang::String* arg0, ::java::lang::String* arg1);

    // Generated

public:
    Provider_ServiceKey();
protected:
    Provider_ServiceKey(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
