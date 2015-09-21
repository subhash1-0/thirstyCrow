// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct default_init_tag;

class java::io::ObjectOutputStream_PutField
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;

protected:
    void ctor();

public:
    virtual void put(::java::lang::String* arg0, bool arg1) = 0;
    virtual void put(::java::lang::String* arg0, int8_t arg1) = 0;
    virtual void put(::java::lang::String* arg0, char16_t arg1) = 0;
    virtual void put(::java::lang::String* arg0, int16_t arg1) = 0;
    virtual void put(::java::lang::String* arg0, int32_t arg1) = 0;
    virtual void put(::java::lang::String* arg0, int64_t arg1) = 0;
    virtual void put(::java::lang::String* arg0, float arg1) = 0;
    virtual void put(::java::lang::String* arg0, double arg1) = 0;
    virtual void put(::java::lang::String* arg0, ::java::lang::Object* arg1) = 0;
    virtual void write(ObjectOutput* arg0) = 0;

    // Generated
    ObjectOutputStream_PutField();
protected:
    ObjectOutputStream_PutField(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
