// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <java/util/concurrent/atomic/fwd-pastry-2.1.hpp>
#include <java/util/stream/fwd-pastry-2.1.hpp>
#include <sun/misc/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <java/io/Serializable.hpp>

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
    } // io
} // java

struct default_init_tag;

class java::util::Random
    : public virtual ::java::lang::Object
    , public virtual ::java::io::Serializable
{

public:
    typedef ::java::lang::Object super;

private:
    static ::java::lang::String* BadBound_;
    static ::java::lang::String* BadRange_;
    static ::java::lang::String* BadSize_;
    static constexpr double DOUBLE_UNIT { 1.1102230246251565E-16 };
    static constexpr int64_t addend { int64_t(11LL) };
    bool haveNextNextGaussian {  };
    static constexpr int64_t mask { int64_t(281474976710655LL) };
    static constexpr int64_t multiplier { int64_t(25214903917LL) };
    double nextNextGaussian {  };
    ::java::util::concurrent::atomic::AtomicLong* seed {  };
    static int64_t seedOffset_;
    static ::java::util::concurrent::atomic::AtomicLong* seedUniquifier__;
    static ::java::io::ObjectStreamFieldArray* serialPersistentFields_;

public: /* package */
    static constexpr int64_t serialVersionUID { int64_t(3905348978240129619LL) };

private:
    static ::sun::misc::Unsafe* unsafe_;

protected:
    void ctor();
    void ctor(int64_t arg0);

public:
    virtual ::java::util::stream::DoubleStream* doubles();
    virtual ::java::util::stream::DoubleStream* doubles(int64_t arg0);
    virtual ::java::util::stream::DoubleStream* doubles(double arg0, double arg1);
    virtual ::java::util::stream::DoubleStream* doubles(int64_t arg0, double arg1, double arg2);
    /*static int64_t initialScramble(int64_t arg0); (private) */

public: /* package */
    double internalNextDouble(double arg0, double arg1);
    int32_t internalNextInt(int32_t arg0, int32_t arg1);
    int64_t internalNextLong(int64_t arg0, int64_t arg1);

public:
    virtual ::java::util::stream::IntStream* ints();
    virtual ::java::util::stream::IntStream* ints(int64_t arg0);
    virtual ::java::util::stream::IntStream* ints(int32_t arg0, int32_t arg1);
    virtual ::java::util::stream::IntStream* ints(int64_t arg0, int32_t arg1, int32_t arg2);
    virtual ::java::util::stream::LongStream* longs();
    virtual ::java::util::stream::LongStream* longs(int64_t arg0);
    virtual ::java::util::stream::LongStream* longs(int64_t arg0, int64_t arg1);
    virtual ::java::util::stream::LongStream* longs(int64_t arg0, int64_t arg1, int64_t arg2);

public: /* protected */
    virtual int32_t next(int32_t arg0);

public:
    virtual bool nextBoolean();
    virtual void nextBytes(::int8_tArray* arg0);
    virtual double nextDouble();
    virtual float nextFloat();
    virtual double nextGaussian();
    virtual int32_t nextInt();
    virtual int32_t nextInt(int32_t arg0);
    virtual int64_t nextLong();
    /*void readObject(::java::io::ObjectInputStream* arg0); (private) */
    /*void resetSeed(int64_t arg0); (private) */
    /*static int64_t seedUniquifier(); (private) */
    virtual void setSeed(int64_t arg0);
    /*void writeObject(::java::io::ObjectOutputStream* arg0); (private) */

    // Generated
    Random();
    Random(int64_t arg0);
protected:
    Random(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

public: /* package */
    static ::java::lang::String*& BadBound();
    static ::java::lang::String*& BadRange();
    static ::java::lang::String*& BadSize();

private:
    static int64_t& seedOffset();
    static ::java::util::concurrent::atomic::AtomicLong*& seedUniquifier_();
    static ::java::io::ObjectStreamFieldArray*& serialPersistentFields();
    static ::sun::misc::Unsafe*& unsafe();
    virtual ::java::lang::Class* getClass0();
};
