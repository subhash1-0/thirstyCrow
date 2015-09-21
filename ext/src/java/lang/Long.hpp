// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/math/fwd-pastry-2.1.hpp>
#include <java/lang/Number.hpp>
#include <java/lang/Comparable.hpp>

struct default_init_tag;

class java::lang::Long final
    : public Number
    , public Comparable
{

public:
    typedef Number super;
    static constexpr int32_t BYTES { int32_t(8) };
    static constexpr int64_t MAX_VALUE { int64_t(9223372036854775807LL) };
    static constexpr int64_t MIN_VALUE { int64_t(-0x7fffffffffffffffLL-1) };
    static constexpr int32_t SIZE { int32_t(64) };

private:
    static Class* TYPE_;
    static constexpr int64_t serialVersionUID { int64_t(4290774380558885855LL) };
    int64_t value {  };

protected:
    void ctor(int64_t arg0);
    void ctor(String* arg0);

public:
    static int32_t bitCount(int64_t arg0);
    int8_t byteValue() override;
    static int32_t compare(int64_t arg0, int64_t arg1);
    int32_t compareTo(Long* arg0);
    static int32_t compareUnsigned(int64_t arg0, int64_t arg1);
    static Long* decode(String* arg0);
    static int64_t divideUnsigned(int64_t arg0, int64_t arg1);
    double doubleValue() override;
    bool equals(Object* arg0) override;
    float floatValue() override;

public: /* package */
    static int32_t formatUnsignedLong(int64_t arg0, int32_t arg1, ::char16_tArray* arg2, int32_t arg3, int32_t arg4);
    static void getChars(int64_t arg0, int32_t arg1, ::char16_tArray* arg2);

public:
    static Long* getLong(String* arg0);
    static Long* getLong(String* arg0, int64_t arg1);
    static Long* getLong(String* arg0, Long* arg1);
    int32_t hashCode() override;
    static int32_t hashCode(int64_t arg0);
    static int64_t highestOneBit(int64_t arg0);
    int32_t intValue() override;
    int64_t longValue() override;
    static int64_t lowestOneBit(int64_t arg0);
    static int64_t max(int64_t arg0, int64_t arg1);
    static int64_t min(int64_t arg0, int64_t arg1);
    static int32_t numberOfLeadingZeros(int64_t arg0);
    static int32_t numberOfTrailingZeros(int64_t arg0);
    static int64_t parseLong(String* arg0);
    static int64_t parseLong(String* arg0, int32_t arg1);
    static int64_t parseUnsignedLong(String* arg0);
    static int64_t parseUnsignedLong(String* arg0, int32_t arg1);
    static int64_t remainderUnsigned(int64_t arg0, int64_t arg1);
    static int64_t reverse(int64_t arg0);
    static int64_t reverseBytes(int64_t arg0);
    static int64_t rotateLeft(int64_t arg0, int32_t arg1);
    static int64_t rotateRight(int64_t arg0, int32_t arg1);
    int16_t shortValue() override;
    static int32_t signum(int64_t arg0);

public: /* package */
    static int32_t stringSize(int64_t arg0);

public:
    static int64_t sum(int64_t arg0, int64_t arg1);
    static String* toBinaryString(int64_t arg0);
    static String* toHexString(int64_t arg0);
    static String* toOctalString(int64_t arg0);
    String* toString() override;
    static String* toString(int64_t arg0);
    static String* toString(int64_t arg0, int32_t arg1);
    /*static ::java::math::BigInteger* toUnsignedBigInteger(int64_t arg0); (private) */
    static String* toUnsignedString(int64_t arg0);
    static String* toUnsignedString(int64_t arg0, int32_t arg1);

public: /* package */
    static String* toUnsignedString0(int64_t arg0, int32_t arg1);

public:
    static Long* valueOf(String* arg0);
    static Long* valueOf(int64_t arg0);
    static Long* valueOf(String* arg0, int32_t arg1);

    // Generated
    Long(int64_t arg0);
    Long(String* arg0);
protected:
    Long(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    virtual int32_t compareTo(Object* o) override;
    static Class*& TYPE();

private:
    virtual ::java::lang::Class* getClass0();
};
