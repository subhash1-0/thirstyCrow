// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/lang/reflect/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/Comparable.hpp>

struct default_init_tag;

class java::io::ObjectStreamField
    : public virtual ::java::lang::Object
    , public virtual ::java::lang::Comparable
{

public:
    typedef ::java::lang::Object super;

private:
    ::java::lang::reflect::Field* field {  };
    ::java::lang::String* name {  };
    int32_t offset {  };
    ::java::lang::String* signature {  };
    ::java::lang::Class* type {  };
    bool unshared {  };

protected:
    void ctor(::java::lang::String* arg0, ::java::lang::Class* arg1);
    void ctor(::java::lang::String* arg0, ::java::lang::Class* arg1, bool arg2);
    void ctor(::java::lang::String* arg0, ::java::lang::String* arg1, bool arg2);
    void ctor(::java::lang::reflect::Field* arg0, bool arg1, bool arg2);

public:
    int32_t compareTo(::java::lang::Object* arg0) override;
    /*static ::java::lang::String* getClassSignature(::java::lang::Class* arg0); (private) */

public: /* package */
    virtual ::java::lang::reflect::Field* getField();

public:
    virtual ::java::lang::String* getName();
    virtual int32_t getOffset();

public: /* package */
    virtual ::java::lang::String* getSignature();

public:
    virtual ::java::lang::Class* getType();
    virtual char16_t getTypeCode();
    virtual ::java::lang::String* getTypeString();
    virtual bool isPrimitive();
    virtual bool isUnshared();

public: /* protected */
    virtual void setOffset(int32_t arg0);

public:
    ::java::lang::String* toString() override;

    // Generated
    ObjectStreamField(::java::lang::String* arg0, ::java::lang::Class* arg1);
    ObjectStreamField(::java::lang::String* arg0, ::java::lang::Class* arg1, bool arg2);

public: /* package */
    ObjectStreamField(::java::lang::String* arg0, ::java::lang::String* arg1, bool arg2);
    ObjectStreamField(::java::lang::reflect::Field* arg0, bool arg1, bool arg2);
protected:
    ObjectStreamField(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
