// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <atomic>
#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/math/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <java/lang/Number.hpp>
#include <java/lang/Comparable.hpp>

template<typename ComponentType, typename... Bases> struct SubArray;
namespace java
{
    namespace lang
    {
typedef ::SubArray< ::java::lang::Comparable, ObjectArray > ComparableArray;
    } // lang

    namespace io
    {
typedef ::SubArray< ::java::io::ObjectStreamField, ::java::lang::ObjectArray, ::java::lang::ComparableArray > ObjectStreamFieldArray;
typedef ::SubArray< ::java::io::Serializable, ::java::lang::ObjectArray > SerializableArray;
    } // io

    namespace lang
    {
typedef ::SubArray< ::java::lang::CharSequence, ObjectArray > CharSequenceArray;
typedef ::SubArray< ::java::lang::Cloneable, ObjectArray > CloneableArray;
typedef ::SubArray< ::java::lang::Number, ObjectArray, ::java::io::SerializableArray > NumberArray;
typedef ::SubArray< ::java::lang::String, ObjectArray, ::java::io::SerializableArray, ComparableArray, CharSequenceArray > StringArray;
    } // lang

    namespace math
    {
typedef ::SubArray< ::java::math::BigInteger, ::java::lang::NumberArray, ::java::lang::ComparableArray > BigIntegerArray;
typedef ::SubArray< ::java::math::BigIntegerArray, ::java::lang::CloneableArray, ::java::io::SerializableArray > BigIntegerArrayArray;
    } // math
} // java

struct default_init_tag;

class java::math::BigInteger
    : public ::java::lang::Number
    , public virtual ::java::lang::Comparable
{

public:
    typedef ::java::lang::Number super;

private:
    static bool $assertionsDisabled_;

public: /* package */
    static constexpr int32_t BURNIKEL_ZIEGLER_OFFSET { int32_t(40) };
    static constexpr int32_t BURNIKEL_ZIEGLER_THRESHOLD { int32_t(80) };

private:
    static constexpr int32_t DEFAULT_PRIME_CERTAINTY { int32_t(100) };
    static constexpr int32_t KARATSUBA_SQUARE_THRESHOLD { int32_t(128) };
    static constexpr int32_t KARATSUBA_THRESHOLD { int32_t(80) };
    static double LOG_TWO_;

public: /* package */
    static constexpr int64_t LONG_MASK { int64_t(4294967295LL) };

private:
    static constexpr int32_t MAX_CONSTANT { int32_t(16) };
    static constexpr int32_t MAX_MAG_LENGTH { int32_t(67108864) };
    static constexpr int32_t MULTIPLY_SQUARE_THRESHOLD { int32_t(20) };
    static BigInteger* NEGATIVE_ONE_;
    static BigInteger* ONE_;
    static constexpr int32_t PRIME_SEARCH_BIT_LENGTH_LIMIT { int32_t(500000000) };
    static constexpr int32_t SCHOENHAGE_BASE_CONVERSION_THRESHOLD { int32_t(20) };
    static BigInteger* SMALL_PRIME_PRODUCT_;
    static constexpr int32_t SMALL_PRIME_THRESHOLD { int32_t(95) };
    static BigInteger* TEN_;
    static constexpr int32_t TOOM_COOK_SQUARE_THRESHOLD { int32_t(216) };
    static constexpr int32_t TOOM_COOK_THRESHOLD { int32_t(240) };
    static BigInteger* TWO_;
    static BigInteger* ZERO_;
    int32_t bitCount_ {  };
    int32_t bitLength_ {  };
    static ::int64_tArray* bitsPerDigit_;
    static ::int32_tArray* bnExpModThreshTable_;
    static ::int32_tArray* digitsPerInt_;
    static ::int32_tArray* digitsPerLong_;
    int32_t firstNonzeroIntNum_ {  };
    static ::int32_tArray* intRadix_;
    static ::doubleArray* logCache_;
    static BigIntegerArray* longRadix_;
    int32_t lowestSetBit {  };

public: /* package */
    ::int32_tArray* mag {  };

private:
    static BigIntegerArray* negConst_;
    static BigIntegerArray* posConst_;
    static std::atomic< BigIntegerArrayArray* > powerCache_;
    static ::java::io::ObjectStreamFieldArray* serialPersistentFields_;
    static constexpr int64_t serialVersionUID { int64_t(-8287574255936472291LL) };

public: /* package */
    int32_t signum_ {  };

private:
    static ::java::lang::StringArray* zeros_;

protected:
    void ctor(::int8_tArray* arg0);
    /*void ctor(::int32_tArray* arg0); (private) */
    void ctor(::java::lang::String* arg0);
    /*void ctor(int64_t arg0); (private) */
    void ctor(int32_t arg0, ::int8_tArray* arg1);
    /*void ctor(int32_t arg0, ::int32_tArray* arg1); (private) */
    void ctor(::java::lang::String* arg0, int32_t arg1);
    void ctor(int32_t arg0, ::java::util::Random* arg1);
    void ctor(::int32_tArray* arg0, int32_t arg1);
    /*void ctor(::int8_tArray* arg0, int32_t arg1); (private) */
    void ctor(::char16_tArray* arg0, int32_t arg1, int32_t arg2);
    void ctor(int32_t arg0, int32_t arg1, ::java::util::Random* arg2);

public:
    virtual BigInteger* abs();
    virtual BigInteger* add(BigInteger* arg0);

public: /* package */
    virtual BigInteger* add(int64_t arg0);
    /*static ::int32_tArray* add(::int32_tArray* arg0, int64_t arg1); (private) */
    /*static ::int32_tArray* add(::int32_tArray* arg0, ::int32_tArray* arg1); (private) */
    static int32_t addOne(::int32_tArray* arg0, int32_t arg1, int32_t arg2, int32_t arg3);

public:
    virtual BigInteger* and_(BigInteger* arg0);
    virtual BigInteger* andNot(BigInteger* arg0);
    virtual int32_t bitCount();
    virtual int32_t bitLength();
    /*static int32_t bitLength(::int32_tArray* arg0, int32_t arg1); (private) */

public: /* package */
    static int32_t bitLengthForInt(int32_t arg0);

public:
    virtual int8_t byteValueExact();
    /*void checkRange(); (private) */
    virtual BigInteger* clearBit(int32_t arg0);

public: /* package */
    int32_t compareMagnitude(BigInteger* arg0);
    int32_t compareMagnitude(int64_t arg0);

public:
    virtual int32_t compareTo(BigInteger* arg0);
    /*static void destructiveMulAdd(::int32_tArray* arg0, int32_t arg1, int32_t arg2); (private) */
    virtual BigInteger* divide(BigInteger* arg0);
    virtual BigIntegerArray* divideAndRemainder(BigInteger* arg0);
    /*BigIntegerArray* divideAndRemainderBurnikelZiegler(BigInteger* arg0); (private) */
    /*BigIntegerArray* divideAndRemainderKnuth(BigInteger* arg0); (private) */
    /*BigInteger* divideBurnikelZiegler(BigInteger* arg0); (private) */
    /*BigInteger* divideKnuth(BigInteger* arg0); (private) */
    double doubleValue() override;
    bool equals(::java::lang::Object* arg0) override;
    /*BigInteger* exactDivideBy3(); (private) */
    /*int32_t firstNonzeroIntNum(); (private) */
    virtual BigInteger* flipBit(int32_t arg0);
    float floatValue() override;
    virtual BigInteger* gcd(BigInteger* arg0);
    /*int32_t getInt(int32_t arg0); (private) */
    /*BigInteger* getLower(int32_t arg0); (private) */
    virtual int32_t getLowestSetBit();
    /*static int32_t getPrimeSearchLen(int32_t arg0); (private) */
    /*static BigInteger* getRadixConversionCache(int32_t arg0, int32_t arg1); (private) */
    /*BigInteger* getToomSlice(int32_t arg0, int32_t arg1, int32_t arg2, int32_t arg3); (private) */
    /*BigInteger* getUpper(int32_t arg0); (private) */
    int32_t hashCode() override;
    /*static int32_t intArrayCmpToLen(::int32_tArray* arg0, ::int32_tArray* arg1, int32_t arg2); (private) */
    /*int32_t intLength(); (private) */
    int32_t intValue() override;
    virtual int32_t intValueExact();
    virtual bool isProbablePrime(int32_t arg0);
    /*static int32_t jacobiSymbol(int32_t arg0, BigInteger* arg1); (private) */

public: /* package */
    virtual ::int32_tArray* javaIncrement(::int32_tArray* arg0);
    /*static BigInteger* largePrime(int32_t arg0, int32_t arg1, ::java::util::Random* arg2); (private) */
    /*static ::int32_tArray* leftShift(::int32_tArray* arg0, int32_t arg1, int32_t arg2); (private) */

public:
    int64_t longValue() override;
    virtual int64_t longValueExact();
    /*static BigInteger* lucasLehmerSequence(int32_t arg0, BigInteger* arg1, BigInteger* arg2); (private) */
    /*::int8_tArray* magSerializedForm(); (private) */
    /*static ::int32_tArray* makePositive(::int8_tArray* arg0); (private) */
    /*static ::int32_tArray* makePositive(::int32_tArray* arg0); (private) */
    virtual BigInteger* max(BigInteger* arg0);
    virtual BigInteger* min(BigInteger* arg0);
    virtual BigInteger* mod(BigInteger* arg0);
    /*BigInteger* mod2(int32_t arg0); (private) */
    virtual BigInteger* modInverse(BigInteger* arg0);
    virtual BigInteger* modPow(BigInteger* arg0, BigInteger* arg1);
    /*BigInteger* modPow2(BigInteger* arg0, int32_t arg1); (private) */
    /*static ::int32_tArray* montReduce(::int32_tArray* arg0, ::int32_tArray* arg1, int32_t arg2, int32_t arg3); (private) */

public: /* package */
    static int32_t mulAdd(::int32_tArray* arg0, ::int32_tArray* arg1, int32_t arg2, int32_t arg3, int32_t arg4);

public:
    virtual BigInteger* multiply(BigInteger* arg0);

public: /* package */
    virtual BigInteger* multiply(int64_t arg0);
    /*static BigInteger* multiplyByInt(::int32_tArray* arg0, int32_t arg1, int32_t arg2); (private) */
    /*static BigInteger* multiplyKaratsuba(BigInteger* arg0, BigInteger* arg1); (private) */
    /*::int32_tArray* multiplyToLen(::int32_tArray* arg0, int32_t arg1, ::int32_tArray* arg2, int32_t arg3, ::int32_tArray* arg4); (private) */
    /*static BigInteger* multiplyToomCook3(BigInteger* arg0, BigInteger* arg1); (private) */

public:
    virtual BigInteger* negate();
    virtual BigInteger* nextProbablePrime();
    virtual BigInteger* not_();
    /*BigInteger* oddModPow(BigInteger* arg0, BigInteger* arg1); (private) */
    virtual BigInteger* or_(BigInteger* arg0);
    /*int32_t parseInt(::char16_tArray* arg0, int32_t arg1, int32_t arg2); (private) */
    /*bool passesLucasLehmer(); (private) */
    /*bool passesMillerRabin(int32_t arg0, ::java::util::Random* arg1); (private) */
    virtual BigInteger* pow(int32_t arg0);

public: /* package */
    virtual bool primeToCertainty(int32_t arg0, ::java::util::Random* arg1);
    static void primitiveLeftShift(::int32_tArray* arg0, int32_t arg1, int32_t arg2);
    static void primitiveRightShift(::int32_tArray* arg0, int32_t arg1, int32_t arg2);

public:
    static BigInteger* probablePrime(int32_t arg0, ::java::util::Random* arg1);
    /*static ::int8_tArray* randomBits(int32_t arg0, ::java::util::Random* arg1); (private) */
    /*void readObject(::java::io::ObjectInputStream* arg0); (private) */
    virtual BigInteger* remainder(BigInteger* arg0);
    /*BigInteger* remainderBurnikelZiegler(BigInteger* arg0); (private) */
    /*BigInteger* remainderKnuth(BigInteger* arg0); (private) */
    /*static void reportOverflow(); (private) */
    virtual BigInteger* setBit(int32_t arg0);
    virtual BigInteger* shiftLeft(int32_t arg0);
    /*static ::int32_tArray* shiftLeft(::int32_tArray* arg0, int32_t arg1); (private) */
    virtual BigInteger* shiftRight(int32_t arg0);
    /*BigInteger* shiftRightImpl(int32_t arg0); (private) */
    virtual int16_t shortValueExact();
    /*int32_t signBit(); (private) */
    /*int32_t signInt(); (private) */
    virtual int32_t signum();
    /*static BigInteger* smallPrime(int32_t arg0, int32_t arg1, ::java::util::Random* arg2); (private) */
    /*::java::lang::String* smallToString(int32_t arg0); (private) */
    /*BigInteger* square(); (private) */
    /*BigInteger* squareKaratsuba(); (private) */
    /*static ::int32_tArray* squareToLen(::int32_tArray* arg0, int32_t arg1, ::int32_tArray* arg2); (private) */
    /*BigInteger* squareToomCook3(); (private) */
    /*static ::int32_tArray* stripLeadingZeroBytes(::int8_tArray* arg0); (private) */
    /*static ::int32_tArray* stripLeadingZeroInts(::int32_tArray* arg0); (private) */
    /*static int32_t subN(::int32_tArray* arg0, ::int32_tArray* arg1, int32_t arg2); (private) */
    virtual BigInteger* subtract(BigInteger* arg0);
    /*static ::int32_tArray* subtract(int64_t arg0, ::int32_tArray* arg1); (private) */
    /*static ::int32_tArray* subtract(::int32_tArray* arg0, int64_t arg1); (private) */
    /*static ::int32_tArray* subtract(::int32_tArray* arg0, ::int32_tArray* arg1); (private) */
    virtual bool testBit(int32_t arg0);
    virtual ::int8_tArray* toByteArray_();
    ::java::lang::String* toString() override;
    virtual ::java::lang::String* toString(int32_t arg0);
    /*static void toString(BigInteger* arg0, ::java::lang::StringBuilder* arg1, int32_t arg2, int32_t arg3); (private) */
    /*static ::int32_tArray* trustedStripLeadingZeroInts(::int32_tArray* arg0); (private) */
    static BigInteger* valueOf(int64_t arg0);
    /*static BigInteger* valueOf(::int32_tArray* arg0); (private) */
    /*void writeObject(::java::io::ObjectOutputStream* arg0); (private) */
    virtual BigInteger* xor_(BigInteger* arg0);

    // Generated
    BigInteger(::int8_tArray* arg0);
    BigInteger(::java::lang::String* arg0);
    BigInteger(int32_t arg0, ::int8_tArray* arg1);
    BigInteger(::java::lang::String* arg0, int32_t arg1);
    BigInteger(int32_t arg0, ::java::util::Random* arg1);

public: /* package */
    BigInteger(::int32_tArray* arg0, int32_t arg1);
    BigInteger(::char16_tArray* arg0, int32_t arg1, int32_t arg2);

public:
    BigInteger(int32_t arg0, int32_t arg1, ::java::util::Random* arg2);
protected:
    BigInteger(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    virtual int32_t compareTo(::java::lang::Object* arg0) override;

public: /* package */
    static bool& $assertionsDisabled();

private:
    static double& LOG_TWO();
    static BigInteger*& NEGATIVE_ONE();

public:
    static BigInteger*& ONE();

private:
    static BigInteger*& SMALL_PRIME_PRODUCT();

public:
    static BigInteger*& TEN();

private:
    static BigInteger*& TWO();

public:
    static BigInteger*& ZERO();

private:
    static ::int64_tArray*& bitsPerDigit();

public: /* package */
    static ::int32_tArray*& bnExpModThreshTable();

private:
    static ::int32_tArray*& digitsPerInt();
    static ::int32_tArray*& digitsPerLong();
    static ::int32_tArray*& intRadix();
    static ::doubleArray*& logCache();
    static BigIntegerArray*& longRadix();
    static BigIntegerArray*& negConst();
    static BigIntegerArray*& posConst();
    static std::atomic< BigIntegerArrayArray* >& powerCache();
    static ::java::io::ObjectStreamFieldArray*& serialPersistentFields();
    static ::java::lang::StringArray*& zeros();
    virtual ::java::lang::Class* getClass0();
};
