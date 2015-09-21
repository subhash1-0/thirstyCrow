// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/lang/reflect/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct default_init_tag;

class java::lang::reflect::Array_ final
    : public ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;

    /*void ctor(); (private) */
    static ::java::lang::Object* get(::java::lang::Object* arg0, int32_t arg1);
    static bool getBoolean(::java::lang::Object* arg0, int32_t arg1);
    static int8_t getByte(::java::lang::Object* arg0, int32_t arg1);
    static char16_t getChar(::java::lang::Object* arg0, int32_t arg1);
    static double getDouble(::java::lang::Object* arg0, int32_t arg1);
    static float getFloat(::java::lang::Object* arg0, int32_t arg1);
    static int32_t getInt(::java::lang::Object* arg0, int32_t arg1);
    static int32_t getLength(::java::lang::Object* arg0);
    static int64_t getLong(::java::lang::Object* arg0, int32_t arg1);
    static int16_t getShort(::java::lang::Object* arg0, int32_t arg1);
    /*static ::java::lang::Object* multiNewArray_(::java::lang::Class* arg0, ::int32_tArray* arg1); (private) */
    /*static ::java::lang::Object* newArray_(::java::lang::Class* arg0, int32_t arg1); (private) */
    static ::java::lang::Object* newInstance(::java::lang::Class* arg0, int32_t arg1);
    static ::java::lang::Object* newInstance(::java::lang::Class* arg0, ::int32_tArray* arg1);
    static void set(::java::lang::Object* arg0, int32_t arg1, ::java::lang::Object* arg2);
    static void setBoolean(::java::lang::Object* arg0, int32_t arg1, bool arg2);
    static void setByte(::java::lang::Object* arg0, int32_t arg1, int8_t arg2);
    static void setChar(::java::lang::Object* arg0, int32_t arg1, char16_t arg2);
    static void setDouble(::java::lang::Object* arg0, int32_t arg1, double arg2);
    static void setFloat(::java::lang::Object* arg0, int32_t arg1, float arg2);
    static void setInt(::java::lang::Object* arg0, int32_t arg1, int32_t arg2);
    static void setLong(::java::lang::Object* arg0, int32_t arg1, int64_t arg2);
    static void setShort(::java::lang::Object* arg0, int32_t arg1, int16_t arg2);

    // Generated
    Array_();
protected:
    Array_(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
