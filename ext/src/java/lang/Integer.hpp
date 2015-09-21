// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/lang/Number.hpp>
#include <java/lang/Comparable.hpp>

struct default_init_tag;

class java::lang::Integer final
    : public Number
    , public Comparable
{

public:
    typedef Number super;
    static constexpr int32_t BYTES { int32_t(4) };

private:
    static ::char16_tArray* DigitOnes_;
    static ::char16_tArray* DigitTens_;

public:
    static constexpr int32_t MAX_VALUE { int32_t(2147483647) };
    static constexpr int32_t MIN_VALUE { int32_t(-0x7fffffff-1) };
    static constexpr int32_t SIZE { int32_t(32) };

private:
    static Class* TYPE_;
    static ::char16_tArray* digits_;
    static constexpr int64_t serialVersionUID { int64_t(1360826667806852920LL) };
    static ::int32_tArray* sizeTable_;
    int32_t value {  };

protected:
    void ctor(int32_t arg0);
    void ctor(String* arg0);

public:
    static int32_t bitCount(int32_t arg0);
    int8_t byteValue() override;
    static int32_t compare(int32_t arg0, int32_t arg1);
    int32_t compareTo(Integer* arg0);
    static int32_t compareUnsigned(int32_t arg0, int32_t arg1);
    static Integer* decode(String* arg0);
    static int32_t divideUnsigned(int32_t arg0, int32_t arg1);
    double doubleValue() override;
    bool equals(Object* arg0) override;
    float floatValue() override;

public: /* package */
    static int32_t formatUnsignedInt(int32_t arg0, int32_t arg1, ::char16_tArray* arg2, int32_t arg3, int32_t arg4);
    static void getChars(int32_t arg0, int32_t arg1, ::char16_tArray* arg2);

public:
    static Integer* getInteger(String* arg0);
    static Integer* getInteger(String* arg0, int32_t arg1);
    static Integer* getInteger(String* arg0, Integer* arg1);
    int32_t hashCode() override;
    static int32_t hashCode(int32_t arg0);
    static int32_t highestOneBit(int32_t arg0);
    int32_t intValue() override;
    int64_t longValue() override;
    static int32_t lowestOneBit(int32_t arg0);
    static int32_t max(int32_t arg0, int32_t arg1);
    static int32_t min(int32_t arg0, int32_t arg1);
    static int32_t numberOfLeadingZeros(int32_t arg0);
    static int32_t numberOfTrailingZeros(int32_t arg0);
    static int32_t parseInt(String* arg0);
    static int32_t parseInt(String* arg0, int32_t arg1);
    static int32_t parseUnsignedInt(String* arg0);
    static int32_t parseUnsignedInt(String* arg0, int32_t arg1);
    static int32_t remainderUnsigned(int32_t arg0, int32_t arg1);
    static int32_t reverse(int32_t arg0);
    static int32_t reverseBytes(int32_t arg0);
    static int32_t rotateLeft(int32_t arg0, int32_t arg1);
    static int32_t rotateRight(int32_t arg0, int32_t arg1);
    int16_t shortValue() override;
    static int32_t signum(int32_t arg0);

public: /* package */
    static int32_t stringSize(int32_t arg0);

public:
    static int32_t sum(int32_t arg0, int32_t arg1);
    static String* toBinaryString(int32_t arg0);
    static String* toHexString(int32_t arg0);
    static String* toOctalString(int32_t arg0);
    String* toString() override;
    static String* toString(int32_t arg0);
    static String* toString(int32_t arg0, int32_t arg1);
    static int64_t toUnsignedLong(int32_t arg0);
    static String* toUnsignedString(int32_t arg0);
    static String* toUnsignedString(int32_t arg0, int32_t arg1);
    /*static String* toUnsignedString0(int32_t arg0, int32_t arg1); (private) */
    static Integer* valueOf(String* arg0);
    static Integer* valueOf(int32_t arg0);
    static Integer* valueOf(String* arg0, int32_t arg1);

    // Generated
    Integer(int32_t arg0);
    Integer(String* arg0);
protected:
    Integer(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    virtual int32_t compareTo(Object* o) override;

public: /* package */
    static ::char16_tArray*& DigitOnes();
    static ::char16_tArray*& DigitTens();

public:
    static Class*& TYPE();

public: /* package */
    static ::char16_tArray*& digits();
    static ::int32_tArray*& sizeTable();

private:
    virtual ::java::lang::Class* getClass0();
};
