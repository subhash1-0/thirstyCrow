// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/security/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct default_init_tag;

class java::security::Provider_UString
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    ::java::lang::String* lowerString {  };
    ::java::lang::String* string {  };

protected:
    void ctor(::java::lang::String* arg0);

public:
    bool equals(::java::lang::Object* arg0) override;
    int32_t hashCode() override;
    ::java::lang::String* toString() override;

    // Generated

public: /* package */
    Provider_UString(::java::lang::String* arg0);
protected:
    Provider_UString(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
