// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/lang/Number.hpp>
#include <java/lang/Comparable.hpp>

struct default_init_tag;

class java::lang::Short final
    : public Number
    , public Comparable
{

public:
    typedef Number super;
    static constexpr int32_t BYTES { int32_t(2) };
    static constexpr int16_t MAX_VALUE { int16_t(32767) };
    static constexpr int16_t MIN_VALUE { int16_t(-32768) };
    static constexpr int32_t SIZE { int32_t(16) };

private:
    static Class* TYPE_;
    static constexpr int64_t serialVersionUID { int64_t(7515723908773894738LL) };
    int16_t value {  };

protected:
    void ctor(int16_t arg0);
    void ctor(String* arg0);

public:
    int8_t byteValue() override;
    static int32_t compare(int16_t arg0, int16_t arg1);
    int32_t compareTo(Short* arg0);
    static Short* decode(String* arg0);
    double doubleValue() override;
    bool equals(Object* arg0) override;
    float floatValue() override;
    int32_t hashCode() override;
    static int32_t hashCode(int16_t arg0);
    int32_t intValue() override;
    int64_t longValue() override;
    static int16_t parseShort(String* arg0);
    static int16_t parseShort(String* arg0, int32_t arg1);
    static int16_t reverseBytes(int16_t arg0);
    int16_t shortValue() override;
    String* toString() override;
    static String* toString(int16_t arg0);
    static int32_t toUnsignedInt(int16_t arg0);
    static int64_t toUnsignedLong(int16_t arg0);
    static Short* valueOf(String* arg0);
    static Short* valueOf(int16_t arg0);
    static Short* valueOf(String* arg0, int32_t arg1);

    // Generated
    Short(int16_t arg0);
    Short(String* arg0);
protected:
    Short(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    virtual int32_t compareTo(Object* arg0) override;
    static Class*& TYPE();

private:
    virtual ::java::lang::Class* getClass0();
};
