// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/io/ObjectInputStream_GetField.hpp>

struct default_init_tag;

class java::io::ObjectInputStream_GetFieldImpl
    : public ObjectInputStream_GetField
{

public:
    typedef ObjectInputStream_GetField super;

private:
    ObjectStreamClass* desc {  };
    ::int32_tArray* objHandles {  };
    ::java::lang::ObjectArray* objVals {  };
    ::int8_tArray* primVals {  };

public: /* package */
    ObjectInputStream* this$0 {  };

protected:
    void ctor(ObjectStreamClass* arg0);

public:
    bool defaulted(::java::lang::String* arg0) override;
    bool get(::java::lang::String* arg0, bool arg1) override;
    int8_t get(::java::lang::String* arg0, int8_t arg1) override;
    char16_t get(::java::lang::String* arg0, char16_t arg1) override;
    int16_t get(::java::lang::String* arg0, int16_t arg1) override;
    int32_t get(::java::lang::String* arg0, int32_t arg1) override;
    float get(::java::lang::String* arg0, float arg1) override;
    int64_t get(::java::lang::String* arg0, int64_t arg1) override;
    double get(::java::lang::String* arg0, double arg1) override;
    ::java::lang::Object* get(::java::lang::String* arg0, ::java::lang::Object* arg1) override;
    /*int32_t getFieldOffset(::java::lang::String* arg0, ::java::lang::Class* arg1); (private) */
    ObjectStreamClass* getObjectStreamClass() override;

public: /* package */
    virtual void readFields();

    // Generated
    ObjectInputStream_GetFieldImpl(ObjectInputStream *ObjectInputStream_this, ObjectStreamClass* arg0);
protected:
    ObjectInputStream_GetFieldImpl(ObjectInputStream *ObjectInputStream_this, const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    ObjectInputStream *ObjectInputStream_this;

private:
    virtual ::java::lang::Class* getClass0();
};
