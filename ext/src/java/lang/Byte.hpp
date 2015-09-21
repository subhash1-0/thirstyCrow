// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/lang/Number.hpp>
#include <java/lang/Comparable.hpp>

struct default_init_tag;

class java::lang::Byte final
    : public Number
    , public Comparable
{

public:
    typedef Number super;
    static constexpr int32_t BYTES { int32_t(1) };
    static constexpr int8_t MAX_VALUE { int8_t(127) };
    static constexpr int8_t MIN_VALUE { int8_t(-128) };
    static constexpr int32_t SIZE { int32_t(8) };

private:
    static Class* TYPE_;
    static constexpr int64_t serialVersionUID { int64_t(-7183698231559129828LL) };
    int8_t value {  };

protected:
    void ctor(int8_t arg0);
    void ctor(String* arg0);

public:
    int8_t byteValue() override;
    static int32_t compare(int8_t arg0, int8_t arg1);
    int32_t compareTo(Byte* arg0);
    static Byte* decode(String* arg0);
    double doubleValue() override;
    bool equals(Object* arg0) override;
    float floatValue() override;
    int32_t hashCode() override;
    static int32_t hashCode(int8_t arg0);
    int32_t intValue() override;
    int64_t longValue() override;
    static int8_t parseByte(String* arg0);
    static int8_t parseByte(String* arg0, int32_t arg1);
    int16_t shortValue() override;
    String* toString() override;
    static String* toString(int8_t arg0);
    static int32_t toUnsignedInt(int8_t arg0);
    static int64_t toUnsignedLong(int8_t arg0);
    static Byte* valueOf(int8_t arg0);
    static Byte* valueOf(String* arg0);
    static Byte* valueOf(String* arg0, int32_t arg1);

    // Generated
    Byte(int8_t arg0);
    Byte(String* arg0);
protected:
    Byte(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    virtual int32_t compareTo(Object* o) override;
    static Class*& TYPE();

private:
    virtual ::java::lang::Class* getClass0();
};
