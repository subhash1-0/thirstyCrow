// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/io/ObjectOutputStream_PutField.hpp>

struct default_init_tag;

class java::io::ObjectOutputStream_PutFieldImpl
    : public ObjectOutputStream_PutField
{

public:
    typedef ObjectOutputStream_PutField super;

private:
    ObjectStreamClass* desc {  };
    ::java::lang::ObjectArray* objVals {  };
    ::int8_tArray* primVals {  };

public: /* package */
    ObjectOutputStream* this$0 {  };

protected:
    void ctor(ObjectStreamClass* arg0);
    /*int32_t getFieldOffset(::java::lang::String* arg0, ::java::lang::Class* arg1); (private) */

public:
    void put(::java::lang::String* arg0, bool arg1) override;
    void put(::java::lang::String* arg0, int8_t arg1) override;
    void put(::java::lang::String* arg0, char16_t arg1) override;
    void put(::java::lang::String* arg0, int16_t arg1) override;
    void put(::java::lang::String* arg0, int32_t arg1) override;
    void put(::java::lang::String* arg0, float arg1) override;
    void put(::java::lang::String* arg0, int64_t arg1) override;
    void put(::java::lang::String* arg0, double arg1) override;
    void put(::java::lang::String* arg0, ::java::lang::Object* arg1) override;
    void write(ObjectOutput* arg0) override;

public: /* package */
    virtual void writeFields();

    // Generated
    ObjectOutputStream_PutFieldImpl(ObjectOutputStream *ObjectOutputStream_this, ObjectStreamClass* arg0);
protected:
    ObjectOutputStream_PutFieldImpl(ObjectOutputStream *ObjectOutputStream_this, const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    ObjectOutputStream *ObjectOutputStream_this;

private:
    virtual ::java::lang::Class* getClass0();
};
