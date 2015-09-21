// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/lang/Number.hpp>
#include <java/lang/Comparable.hpp>

struct default_init_tag;

class java::lang::Double final
    : public Number
    , public Comparable
{

public:
    typedef Number super;
    static constexpr int32_t BYTES { int32_t(8) };
    static constexpr int32_t MAX_EXPONENT { int32_t(1023) };
    static constexpr double MAX_VALUE { 1.7976931348623157E308 };
    static constexpr int32_t MIN_EXPONENT { int32_t(-1022) };
    static constexpr double MIN_NORMAL { 2.2250738585072014E-308 };
    static constexpr double MIN_VALUE { 4.9E-324 };
    static constexpr double NEGATIVE_INFINITY { (-std::numeric_limits<double>::infinity()) };
    static constexpr double NaN { std::numeric_limits<double>::quiet_NaN() };
    static constexpr double POSITIVE_INFINITY { std::numeric_limits<double>::infinity() };
    static constexpr int32_t SIZE { int32_t(64) };

private:
    static Class* TYPE_;
    static constexpr int64_t serialVersionUID { int64_t(-9172774392245257468LL) };
    double value {  };

protected:
    void ctor(double arg0);
    void ctor(String* arg0);

public:
    int8_t byteValue() override;
    static int32_t compare(double arg0, double arg1);
    int32_t compareTo(Double* arg0);
    static int64_t doubleToLongBits(double arg0);
    static int64_t doubleToRawLongBits(double arg0);
    double doubleValue() override;
    bool equals(Object* arg0) override;
    float floatValue() override;
    int32_t hashCode() override;
    static int32_t hashCode(double arg0);
    int32_t intValue() override;
    static bool isFinite(double arg0);
    bool isInfinite();
    static bool isInfinite(double arg0);
    bool isNaN();
    static bool isNaN(double arg0);
    static double longBitsToDouble(int64_t arg0);
    int64_t longValue() override;
    static double max(double arg0, double arg1);
    static double min(double arg0, double arg1);
    static double parseDouble(String* arg0);
    int16_t shortValue() override;
    static double sum(double arg0, double arg1);
    static String* toHexString(double arg0);
    String* toString() override;
    static String* toString(double arg0);
    static Double* valueOf(String* arg0);
    static Double* valueOf(double arg0);

    // Generated
    Double(double arg0);
    Double(String* arg0);
protected:
    Double(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    virtual int32_t compareTo(Object* arg0) override;
    static Class*& TYPE();

private:
    virtual ::java::lang::Class* getClass0();
};
