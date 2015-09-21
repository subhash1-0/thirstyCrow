// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/math/BigInteger.hpp>

template<typename ComponentType, typename... Bases> struct SubArray;
namespace java
{
    namespace io
    {
typedef ::SubArray< ::java::io::Serializable, ::java::lang::ObjectArray > SerializableArray;
    } // io

    namespace lang
    {
typedef ::SubArray< ::java::lang::Comparable, ObjectArray > ComparableArray;
typedef ::SubArray< ::java::lang::Number, ObjectArray, ::java::io::SerializableArray > NumberArray;
    } // lang

    namespace math
    {
typedef ::SubArray< ::java::math::BigInteger, ::java::lang::NumberArray, ::java::lang::ComparableArray > BigIntegerArray;
    } // math
} // java

extern void unimplemented_(const char16_t* name);
java::math::BigInteger::BigInteger(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::math::BigInteger::BigInteger(::int8_tArray* arg0)
    : BigInteger(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0);
}

java::math::BigInteger::BigInteger(::java::lang::String* arg0)
    : BigInteger(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0);
}

java::math::BigInteger::BigInteger(int32_t arg0, ::int8_tArray* arg1)
    : BigInteger(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0, arg1);
}

java::math::BigInteger::BigInteger(::java::lang::String* arg0, int32_t arg1)
    : BigInteger(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0, arg1);
}

java::math::BigInteger::BigInteger(int32_t arg0, ::java::util::Random* arg1)
    : BigInteger(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0, arg1);
}

java::math::BigInteger::BigInteger(::int32_tArray* arg0, int32_t arg1)
    : BigInteger(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0, arg1);
}

java::math::BigInteger::BigInteger(::char16_tArray* arg0, int32_t arg1, int32_t arg2)
    : BigInteger(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0, arg1, arg2);
}

java::math::BigInteger::BigInteger(int32_t arg0, int32_t arg1, ::java::util::Random* arg2)
    : BigInteger(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0, arg1, arg2);
}

bool& java::math::BigInteger::$assertionsDisabled()
{
    clinit();
    return $assertionsDisabled_;
}
bool java::math::BigInteger::$assertionsDisabled_;
constexpr int32_t java::math::BigInteger::BURNIKEL_ZIEGLER_OFFSET;
constexpr int32_t java::math::BigInteger::BURNIKEL_ZIEGLER_THRESHOLD;
constexpr int32_t java::math::BigInteger::DEFAULT_PRIME_CERTAINTY;
constexpr int32_t java::math::BigInteger::KARATSUBA_SQUARE_THRESHOLD;
constexpr int32_t java::math::BigInteger::KARATSUBA_THRESHOLD;
double& java::math::BigInteger::LOG_TWO()
{
    clinit();
    return LOG_TWO_;
}
double java::math::BigInteger::LOG_TWO_;
constexpr int64_t java::math::BigInteger::LONG_MASK;
constexpr int32_t java::math::BigInteger::MAX_CONSTANT;
constexpr int32_t java::math::BigInteger::MAX_MAG_LENGTH;
constexpr int32_t java::math::BigInteger::MULTIPLY_SQUARE_THRESHOLD;
java::math::BigInteger*& java::math::BigInteger::NEGATIVE_ONE()
{
    clinit();
    return NEGATIVE_ONE_;
}
java::math::BigInteger* java::math::BigInteger::NEGATIVE_ONE_;
java::math::BigInteger*& java::math::BigInteger::ONE()
{
    clinit();
    return ONE_;
}
java::math::BigInteger* java::math::BigInteger::ONE_;
constexpr int32_t java::math::BigInteger::PRIME_SEARCH_BIT_LENGTH_LIMIT;
constexpr int32_t java::math::BigInteger::SCHOENHAGE_BASE_CONVERSION_THRESHOLD;
java::math::BigInteger*& java::math::BigInteger::SMALL_PRIME_PRODUCT()
{
    clinit();
    return SMALL_PRIME_PRODUCT_;
}
java::math::BigInteger* java::math::BigInteger::SMALL_PRIME_PRODUCT_;
constexpr int32_t java::math::BigInteger::SMALL_PRIME_THRESHOLD;
java::math::BigInteger*& java::math::BigInteger::TEN()
{
    clinit();
    return TEN_;
}
java::math::BigInteger* java::math::BigInteger::TEN_;
constexpr int32_t java::math::BigInteger::TOOM_COOK_SQUARE_THRESHOLD;
constexpr int32_t java::math::BigInteger::TOOM_COOK_THRESHOLD;
java::math::BigInteger*& java::math::BigInteger::TWO()
{
    clinit();
    return TWO_;
}
java::math::BigInteger* java::math::BigInteger::TWO_;
java::math::BigInteger*& java::math::BigInteger::ZERO()
{
    clinit();
    return ZERO_;
}
java::math::BigInteger* java::math::BigInteger::ZERO_;
int64_tArray*& java::math::BigInteger::bitsPerDigit()
{
    clinit();
    return bitsPerDigit_;
}
int64_tArray* java::math::BigInteger::bitsPerDigit_;
int32_tArray*& java::math::BigInteger::bnExpModThreshTable()
{
    clinit();
    return bnExpModThreshTable_;
}
int32_tArray* java::math::BigInteger::bnExpModThreshTable_;
int32_tArray*& java::math::BigInteger::digitsPerInt()
{
    clinit();
    return digitsPerInt_;
}
int32_tArray* java::math::BigInteger::digitsPerInt_;
int32_tArray*& java::math::BigInteger::digitsPerLong()
{
    clinit();
    return digitsPerLong_;
}
int32_tArray* java::math::BigInteger::digitsPerLong_;
int32_tArray*& java::math::BigInteger::intRadix()
{
    clinit();
    return intRadix_;
}
int32_tArray* java::math::BigInteger::intRadix_;
doubleArray*& java::math::BigInteger::logCache()
{
    clinit();
    return logCache_;
}
doubleArray* java::math::BigInteger::logCache_;
java::math::BigIntegerArray*& java::math::BigInteger::longRadix()
{
    clinit();
    return longRadix_;
}
java::math::BigIntegerArray* java::math::BigInteger::longRadix_;
java::math::BigIntegerArray*& java::math::BigInteger::negConst()
{
    clinit();
    return negConst_;
}
java::math::BigIntegerArray* java::math::BigInteger::negConst_;
java::math::BigIntegerArray*& java::math::BigInteger::posConst()
{
    clinit();
    return posConst_;
}
java::math::BigIntegerArray* java::math::BigInteger::posConst_;
std::atomic< java::math::BigIntegerArrayArray* >& java::math::BigInteger::powerCache()
{
    clinit();
    return powerCache_;
}
std::atomic< java::math::BigIntegerArrayArray* > java::math::BigInteger::powerCache_;
java::io::ObjectStreamFieldArray*& java::math::BigInteger::serialPersistentFields()
{
    clinit();
    return serialPersistentFields_;
}
java::io::ObjectStreamFieldArray* java::math::BigInteger::serialPersistentFields_;
constexpr int64_t java::math::BigInteger::serialVersionUID;
java::lang::StringArray*& java::math::BigInteger::zeros()
{
    clinit();
    return zeros_;
}
java::lang::StringArray* java::math::BigInteger::zeros_;

void ::java::math::BigInteger::ctor(::int8_tArray* arg0)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::math::BigInteger::ctor(::int8_tArray* arg0)");
}

/* private: void ::java::math::BigInteger::ctor(::int32_tArray* arg0) */
void ::java::math::BigInteger::ctor(::java::lang::String* arg0)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::math::BigInteger::ctor(::java::lang::String* arg0)");
}

/* private: void ::java::math::BigInteger::ctor(int64_t arg0) */
void ::java::math::BigInteger::ctor(int32_t arg0, ::int8_tArray* arg1)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::math::BigInteger::ctor(int32_t arg0, ::int8_tArray* arg1)");
}

/* private: void ::java::math::BigInteger::ctor(int32_t arg0, ::int32_tArray* arg1) */
void ::java::math::BigInteger::ctor(::java::lang::String* arg0, int32_t arg1)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::math::BigInteger::ctor(::java::lang::String* arg0, int32_t arg1)");
}

void ::java::math::BigInteger::ctor(int32_t arg0, ::java::util::Random* arg1)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::math::BigInteger::ctor(int32_t arg0, ::java::util::Random* arg1)");
}

void ::java::math::BigInteger::ctor(::int32_tArray* arg0, int32_t arg1)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::math::BigInteger::ctor(::int32_tArray* arg0, int32_t arg1)");
}

/* private: void ::java::math::BigInteger::ctor(::int8_tArray* arg0, int32_t arg1) */
void ::java::math::BigInteger::ctor(::char16_tArray* arg0, int32_t arg1, int32_t arg2)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::math::BigInteger::ctor(::char16_tArray* arg0, int32_t arg1, int32_t arg2)");
}

void ::java::math::BigInteger::ctor(int32_t arg0, int32_t arg1, ::java::util::Random* arg2)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::math::BigInteger::ctor(int32_t arg0, int32_t arg1, ::java::util::Random* arg2)");
}

java::math::BigInteger* java::math::BigInteger::abs()
{ /* stub */
    unimplemented_(u"java::math::BigInteger* java::math::BigInteger::abs()");
    return 0;
}

java::math::BigInteger* java::math::BigInteger::add(BigInteger* arg0)
{ /* stub */
    unimplemented_(u"java::math::BigInteger* java::math::BigInteger::add(BigInteger* arg0)");
    return 0;
}

java::math::BigInteger* java::math::BigInteger::add(int64_t arg0)
{ /* stub */
    unimplemented_(u"java::math::BigInteger* java::math::BigInteger::add(int64_t arg0)");
    return 0;
}

/* private: int32_tArray* java::math::BigInteger::add(::int32_tArray* arg0, int64_t arg1) */
/* private: int32_tArray* java::math::BigInteger::add(::int32_tArray* arg0, ::int32_tArray* arg1) */
int32_t java::math::BigInteger::addOne(::int32_tArray* arg0, int32_t arg1, int32_t arg2, int32_t arg3)
{ /* stub */
    clinit();
    unimplemented_(u"int32_t java::math::BigInteger::addOne(::int32_tArray* arg0, int32_t arg1, int32_t arg2, int32_t arg3)");
    return 0;
}

java::math::BigInteger* java::math::BigInteger::and_(BigInteger* arg0)
{ /* stub */
    unimplemented_(u"java::math::BigInteger* java::math::BigInteger::and_(BigInteger* arg0)");
    return 0;
}

java::math::BigInteger* java::math::BigInteger::andNot(BigInteger* arg0)
{ /* stub */
    unimplemented_(u"java::math::BigInteger* java::math::BigInteger::andNot(BigInteger* arg0)");
    return 0;
}

int32_t java::math::BigInteger::bitCount()
{ /* stub */
    unimplemented_(u"int32_t java::math::BigInteger::bitCount()");
    return 0;
}

int32_t java::math::BigInteger::bitLength()
{ /* stub */
    unimplemented_(u"int32_t java::math::BigInteger::bitLength()");
    return 0;
}

/* private: int32_t java::math::BigInteger::bitLength(::int32_tArray* arg0, int32_t arg1) */
int32_t java::math::BigInteger::bitLengthForInt(int32_t arg0)
{ /* stub */
    clinit();
    unimplemented_(u"int32_t java::math::BigInteger::bitLengthForInt(int32_t arg0)");
    return 0;
}

int8_t java::math::BigInteger::byteValueExact()
{ /* stub */
    unimplemented_(u"int8_t java::math::BigInteger::byteValueExact()");
    return 0;
}

/* private: void java::math::BigInteger::checkRange() */
java::math::BigInteger* java::math::BigInteger::clearBit(int32_t arg0)
{ /* stub */
    unimplemented_(u"java::math::BigInteger* java::math::BigInteger::clearBit(int32_t arg0)");
    return 0;
}

int32_t java::math::BigInteger::compareMagnitude(BigInteger* arg0)
{ /* stub */
    unimplemented_(u"int32_t java::math::BigInteger::compareMagnitude(BigInteger* arg0)");
    return 0;
}

int32_t java::math::BigInteger::compareMagnitude(int64_t arg0)
{ /* stub */
    unimplemented_(u"int32_t java::math::BigInteger::compareMagnitude(int64_t arg0)");
    return 0;
}

int32_t java::math::BigInteger::compareTo(BigInteger* arg0)
{ /* stub */
    unimplemented_(u"int32_t java::math::BigInteger::compareTo(BigInteger* arg0)");
    return 0;
}

int32_t java::math::BigInteger::compareTo(::java::lang::Object* arg0)
{ 
    return compareTo(dynamic_cast< BigInteger* >(arg0));
}

/* private: void java::math::BigInteger::destructiveMulAdd(::int32_tArray* arg0, int32_t arg1, int32_t arg2) */
java::math::BigInteger* java::math::BigInteger::divide(BigInteger* arg0)
{ /* stub */
    unimplemented_(u"java::math::BigInteger* java::math::BigInteger::divide(BigInteger* arg0)");
    return 0;
}

java::math::BigIntegerArray* java::math::BigInteger::divideAndRemainder(BigInteger* arg0)
{ /* stub */
    unimplemented_(u"java::math::BigIntegerArray* java::math::BigInteger::divideAndRemainder(BigInteger* arg0)");
    return 0;
}

/* private: java::math::BigIntegerArray* java::math::BigInteger::divideAndRemainderBurnikelZiegler(BigInteger* arg0) */
/* private: java::math::BigIntegerArray* java::math::BigInteger::divideAndRemainderKnuth(BigInteger* arg0) */
/* private: java::math::BigInteger* java::math::BigInteger::divideBurnikelZiegler(BigInteger* arg0) */
/* private: java::math::BigInteger* java::math::BigInteger::divideKnuth(BigInteger* arg0) */
double java::math::BigInteger::doubleValue()
{ /* stub */
    unimplemented_(u"double java::math::BigInteger::doubleValue()");
    return 0;
}

bool java::math::BigInteger::equals(::java::lang::Object* arg0)
{ /* stub */
    unimplemented_(u"bool java::math::BigInteger::equals(::java::lang::Object* arg0)");
    return 0;
}

/* private: java::math::BigInteger* java::math::BigInteger::exactDivideBy3() */
/* private: int32_t java::math::BigInteger::firstNonzeroIntNum() */
java::math::BigInteger* java::math::BigInteger::flipBit(int32_t arg0)
{ /* stub */
    unimplemented_(u"java::math::BigInteger* java::math::BigInteger::flipBit(int32_t arg0)");
    return 0;
}

float java::math::BigInteger::floatValue()
{ /* stub */
    unimplemented_(u"float java::math::BigInteger::floatValue()");
    return 0;
}

java::math::BigInteger* java::math::BigInteger::gcd(BigInteger* arg0)
{ /* stub */
    unimplemented_(u"java::math::BigInteger* java::math::BigInteger::gcd(BigInteger* arg0)");
    return 0;
}

/* private: int32_t java::math::BigInteger::getInt(int32_t arg0) */
/* private: java::math::BigInteger* java::math::BigInteger::getLower(int32_t arg0) */
int32_t java::math::BigInteger::getLowestSetBit()
{ /* stub */
return lowestSetBit ; /* getter */
}

/* private: int32_t java::math::BigInteger::getPrimeSearchLen(int32_t arg0) */
/* private: java::math::BigInteger* java::math::BigInteger::getRadixConversionCache(int32_t arg0, int32_t arg1) */
/* private: java::math::BigInteger* java::math::BigInteger::getToomSlice(int32_t arg0, int32_t arg1, int32_t arg2, int32_t arg3) */
/* private: java::math::BigInteger* java::math::BigInteger::getUpper(int32_t arg0) */
int32_t java::math::BigInteger::hashCode()
{ /* stub */
    unimplemented_(u"int32_t java::math::BigInteger::hashCode()");
    return 0;
}

/* private: int32_t java::math::BigInteger::intArrayCmpToLen(::int32_tArray* arg0, ::int32_tArray* arg1, int32_t arg2) */
/* private: int32_t java::math::BigInteger::intLength() */
int32_t java::math::BigInteger::intValue()
{ /* stub */
    unimplemented_(u"int32_t java::math::BigInteger::intValue()");
    return 0;
}

int32_t java::math::BigInteger::intValueExact()
{ /* stub */
    unimplemented_(u"int32_t java::math::BigInteger::intValueExact()");
    return 0;
}

bool java::math::BigInteger::isProbablePrime(int32_t arg0)
{ /* stub */
    unimplemented_(u"bool java::math::BigInteger::isProbablePrime(int32_t arg0)");
    return 0;
}

/* private: int32_t java::math::BigInteger::jacobiSymbol(int32_t arg0, BigInteger* arg1) */
int32_tArray* java::math::BigInteger::javaIncrement(::int32_tArray* arg0)
{ /* stub */
    unimplemented_(u"int32_tArray* java::math::BigInteger::javaIncrement(::int32_tArray* arg0)");
    return 0;
}

/* private: java::math::BigInteger* java::math::BigInteger::largePrime(int32_t arg0, int32_t arg1, ::java::util::Random* arg2) */
/* private: int32_tArray* java::math::BigInteger::leftShift(::int32_tArray* arg0, int32_t arg1, int32_t arg2) */
int64_t java::math::BigInteger::longValue()
{ /* stub */
    unimplemented_(u"int64_t java::math::BigInteger::longValue()");
    return 0;
}

int64_t java::math::BigInteger::longValueExact()
{ /* stub */
    unimplemented_(u"int64_t java::math::BigInteger::longValueExact()");
    return 0;
}

/* private: java::math::BigInteger* java::math::BigInteger::lucasLehmerSequence(int32_t arg0, BigInteger* arg1, BigInteger* arg2) */
/* private: int8_tArray* java::math::BigInteger::magSerializedForm() */
/* private: int32_tArray* java::math::BigInteger::makePositive(::int8_tArray* arg0) */
/* private: int32_tArray* java::math::BigInteger::makePositive(::int32_tArray* arg0) */
java::math::BigInteger* java::math::BigInteger::max(BigInteger* arg0)
{ /* stub */
    unimplemented_(u"java::math::BigInteger* java::math::BigInteger::max(BigInteger* arg0)");
    return 0;
}

java::math::BigInteger* java::math::BigInteger::min(BigInteger* arg0)
{ /* stub */
    unimplemented_(u"java::math::BigInteger* java::math::BigInteger::min(BigInteger* arg0)");
    return 0;
}

java::math::BigInteger* java::math::BigInteger::mod(BigInteger* arg0)
{ /* stub */
    unimplemented_(u"java::math::BigInteger* java::math::BigInteger::mod(BigInteger* arg0)");
    return 0;
}

/* private: java::math::BigInteger* java::math::BigInteger::mod2(int32_t arg0) */
java::math::BigInteger* java::math::BigInteger::modInverse(BigInteger* arg0)
{ /* stub */
    unimplemented_(u"java::math::BigInteger* java::math::BigInteger::modInverse(BigInteger* arg0)");
    return 0;
}

java::math::BigInteger* java::math::BigInteger::modPow(BigInteger* arg0, BigInteger* arg1)
{ /* stub */
    unimplemented_(u"java::math::BigInteger* java::math::BigInteger::modPow(BigInteger* arg0, BigInteger* arg1)");
    return 0;
}

/* private: java::math::BigInteger* java::math::BigInteger::modPow2(BigInteger* arg0, int32_t arg1) */
/* private: int32_tArray* java::math::BigInteger::montReduce(::int32_tArray* arg0, ::int32_tArray* arg1, int32_t arg2, int32_t arg3) */
int32_t java::math::BigInteger::mulAdd(::int32_tArray* arg0, ::int32_tArray* arg1, int32_t arg2, int32_t arg3, int32_t arg4)
{ /* stub */
    clinit();
    unimplemented_(u"int32_t java::math::BigInteger::mulAdd(::int32_tArray* arg0, ::int32_tArray* arg1, int32_t arg2, int32_t arg3, int32_t arg4)");
    return 0;
}

java::math::BigInteger* java::math::BigInteger::multiply(BigInteger* arg0)
{ /* stub */
    unimplemented_(u"java::math::BigInteger* java::math::BigInteger::multiply(BigInteger* arg0)");
    return 0;
}

java::math::BigInteger* java::math::BigInteger::multiply(int64_t arg0)
{ /* stub */
    unimplemented_(u"java::math::BigInteger* java::math::BigInteger::multiply(int64_t arg0)");
    return 0;
}

/* private: java::math::BigInteger* java::math::BigInteger::multiplyByInt(::int32_tArray* arg0, int32_t arg1, int32_t arg2) */
/* private: java::math::BigInteger* java::math::BigInteger::multiplyKaratsuba(BigInteger* arg0, BigInteger* arg1) */
/* private: int32_tArray* java::math::BigInteger::multiplyToLen(::int32_tArray* arg0, int32_t arg1, ::int32_tArray* arg2, int32_t arg3, ::int32_tArray* arg4) */
/* private: java::math::BigInteger* java::math::BigInteger::multiplyToomCook3(BigInteger* arg0, BigInteger* arg1) */
java::math::BigInteger* java::math::BigInteger::negate()
{ /* stub */
    unimplemented_(u"java::math::BigInteger* java::math::BigInteger::negate()");
    return 0;
}

java::math::BigInteger* java::math::BigInteger::nextProbablePrime()
{ /* stub */
    unimplemented_(u"java::math::BigInteger* java::math::BigInteger::nextProbablePrime()");
    return 0;
}

java::math::BigInteger* java::math::BigInteger::not_()
{ /* stub */
    unimplemented_(u"java::math::BigInteger* java::math::BigInteger::not_()");
    return 0;
}

/* private: java::math::BigInteger* java::math::BigInteger::oddModPow(BigInteger* arg0, BigInteger* arg1) */
java::math::BigInteger* java::math::BigInteger::or_(BigInteger* arg0)
{ /* stub */
    unimplemented_(u"java::math::BigInteger* java::math::BigInteger::or_(BigInteger* arg0)");
    return 0;
}

/* private: int32_t java::math::BigInteger::parseInt(::char16_tArray* arg0, int32_t arg1, int32_t arg2) */
/* private: bool java::math::BigInteger::passesLucasLehmer() */
/* private: bool java::math::BigInteger::passesMillerRabin(int32_t arg0, ::java::util::Random* arg1) */
java::math::BigInteger* java::math::BigInteger::pow(int32_t arg0)
{ /* stub */
    unimplemented_(u"java::math::BigInteger* java::math::BigInteger::pow(int32_t arg0)");
    return 0;
}

bool java::math::BigInteger::primeToCertainty(int32_t arg0, ::java::util::Random* arg1)
{ /* stub */
    unimplemented_(u"bool java::math::BigInteger::primeToCertainty(int32_t arg0, ::java::util::Random* arg1)");
    return 0;
}

void java::math::BigInteger::primitiveLeftShift(::int32_tArray* arg0, int32_t arg1, int32_t arg2)
{ /* stub */
    clinit();
    unimplemented_(u"void java::math::BigInteger::primitiveLeftShift(::int32_tArray* arg0, int32_t arg1, int32_t arg2)");
}

void java::math::BigInteger::primitiveRightShift(::int32_tArray* arg0, int32_t arg1, int32_t arg2)
{ /* stub */
    clinit();
    unimplemented_(u"void java::math::BigInteger::primitiveRightShift(::int32_tArray* arg0, int32_t arg1, int32_t arg2)");
}

java::math::BigInteger* java::math::BigInteger::probablePrime(int32_t arg0, ::java::util::Random* arg1)
{ /* stub */
    clinit();
    unimplemented_(u"java::math::BigInteger* java::math::BigInteger::probablePrime(int32_t arg0, ::java::util::Random* arg1)");
    return 0;
}

/* private: int8_tArray* java::math::BigInteger::randomBits(int32_t arg0, ::java::util::Random* arg1) */
/* private: void java::math::BigInteger::readObject(::java::io::ObjectInputStream* arg0) */
java::math::BigInteger* java::math::BigInteger::remainder(BigInteger* arg0)
{ /* stub */
    unimplemented_(u"java::math::BigInteger* java::math::BigInteger::remainder(BigInteger* arg0)");
    return 0;
}

/* private: java::math::BigInteger* java::math::BigInteger::remainderBurnikelZiegler(BigInteger* arg0) */
/* private: java::math::BigInteger* java::math::BigInteger::remainderKnuth(BigInteger* arg0) */
/* private: void java::math::BigInteger::reportOverflow() */
java::math::BigInteger* java::math::BigInteger::setBit(int32_t arg0)
{ /* stub */
    unimplemented_(u"java::math::BigInteger* java::math::BigInteger::setBit(int32_t arg0)");
    return 0;
}

java::math::BigInteger* java::math::BigInteger::shiftLeft(int32_t arg0)
{ /* stub */
    unimplemented_(u"java::math::BigInteger* java::math::BigInteger::shiftLeft(int32_t arg0)");
    return 0;
}

/* private: int32_tArray* java::math::BigInteger::shiftLeft(::int32_tArray* arg0, int32_t arg1) */
java::math::BigInteger* java::math::BigInteger::shiftRight(int32_t arg0)
{ /* stub */
    unimplemented_(u"java::math::BigInteger* java::math::BigInteger::shiftRight(int32_t arg0)");
    return 0;
}

/* private: java::math::BigInteger* java::math::BigInteger::shiftRightImpl(int32_t arg0) */
int16_t java::math::BigInteger::shortValueExact()
{ /* stub */
    unimplemented_(u"int16_t java::math::BigInteger::shortValueExact()");
    return 0;
}

/* private: int32_t java::math::BigInteger::signBit() */
/* private: int32_t java::math::BigInteger::signInt() */
int32_t java::math::BigInteger::signum()
{ /* stub */
    unimplemented_(u"int32_t java::math::BigInteger::signum()");
    return 0;
}

/* private: java::math::BigInteger* java::math::BigInteger::smallPrime(int32_t arg0, int32_t arg1, ::java::util::Random* arg2) */
/* private: java::lang::String* java::math::BigInteger::smallToString(int32_t arg0) */
/* private: java::math::BigInteger* java::math::BigInteger::square() */
/* private: java::math::BigInteger* java::math::BigInteger::squareKaratsuba() */
/* private: int32_tArray* java::math::BigInteger::squareToLen(::int32_tArray* arg0, int32_t arg1, ::int32_tArray* arg2) */
/* private: java::math::BigInteger* java::math::BigInteger::squareToomCook3() */
/* private: int32_tArray* java::math::BigInteger::stripLeadingZeroBytes(::int8_tArray* arg0) */
/* private: int32_tArray* java::math::BigInteger::stripLeadingZeroInts(::int32_tArray* arg0) */
/* private: int32_t java::math::BigInteger::subN(::int32_tArray* arg0, ::int32_tArray* arg1, int32_t arg2) */
java::math::BigInteger* java::math::BigInteger::subtract(BigInteger* arg0)
{ /* stub */
    unimplemented_(u"java::math::BigInteger* java::math::BigInteger::subtract(BigInteger* arg0)");
    return 0;
}

/* private: int32_tArray* java::math::BigInteger::subtract(int64_t arg0, ::int32_tArray* arg1) */
/* private: int32_tArray* java::math::BigInteger::subtract(::int32_tArray* arg0, int64_t arg1) */
/* private: int32_tArray* java::math::BigInteger::subtract(::int32_tArray* arg0, ::int32_tArray* arg1) */
bool java::math::BigInteger::testBit(int32_t arg0)
{ /* stub */
    unimplemented_(u"bool java::math::BigInteger::testBit(int32_t arg0)");
    return 0;
}

int8_tArray* java::math::BigInteger::toByteArray_()
{ /* stub */
    unimplemented_(u"int8_tArray* java::math::BigInteger::toByteArray_()");
    return 0;
}

java::lang::String* java::math::BigInteger::toString()
{ /* stub */
    unimplemented_(u"java::lang::String* java::math::BigInteger::toString()");
    return 0;
}

java::lang::String* java::math::BigInteger::toString(int32_t arg0)
{ /* stub */
    unimplemented_(u"java::lang::String* java::math::BigInteger::toString(int32_t arg0)");
    return 0;
}

/* private: void java::math::BigInteger::toString(BigInteger* arg0, ::java::lang::StringBuilder* arg1, int32_t arg2, int32_t arg3) */
/* private: int32_tArray* java::math::BigInteger::trustedStripLeadingZeroInts(::int32_tArray* arg0) */
java::math::BigInteger* java::math::BigInteger::valueOf(int64_t arg0)
{ /* stub */
    clinit();
    unimplemented_(u"java::math::BigInteger* java::math::BigInteger::valueOf(int64_t arg0)");
    return 0;
}

/* private: java::math::BigInteger* java::math::BigInteger::valueOf(::int32_tArray* arg0) */
/* private: void java::math::BigInteger::writeObject(::java::io::ObjectOutputStream* arg0) */
java::math::BigInteger* java::math::BigInteger::xor_(BigInteger* arg0)
{ /* stub */
    unimplemented_(u"java::math::BigInteger* java::math::BigInteger::xor_(BigInteger* arg0)");
    return 0;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::math::BigInteger::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.math.BigInteger", 20);
    return c;
}

java::lang::Class* java::math::BigInteger::getClass0()
{
    return class_();
}

