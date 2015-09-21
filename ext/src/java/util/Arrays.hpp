// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <java/util/function/fwd-pastry-2.1.hpp>
#include <java/util/stream/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

template<typename ComponentType, typename... Bases> struct SubArray;
namespace java
{
    namespace lang
    {
typedef ::SubArray< ::java::lang::Comparable, ObjectArray > ComparableArray;
    } // lang
} // java

struct default_init_tag;

class java::util::Arrays
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;

private:
    static bool $assertionsDisabled_;
    static constexpr int32_t INSERTIONSORT_THRESHOLD { int32_t(7) };
    static constexpr int32_t MIN_ARRAY_SORT_GRAN { int32_t(8192) };

    /*void ctor(); (private) */

public:
    static List* asList(::java::lang::ObjectArray* arg0);
    static int32_t binarySearch(::int64_tArray* arg0, int64_t arg1);
    static int32_t binarySearch(::int32_tArray* arg0, int32_t arg1);
    static int32_t binarySearch(::int16_tArray* arg0, int16_t arg1);
    static int32_t binarySearch(::char16_tArray* arg0, char16_t arg1);
    static int32_t binarySearch(::int8_tArray* arg0, int8_t arg1);
    static int32_t binarySearch(::doubleArray* arg0, double arg1);
    static int32_t binarySearch(::floatArray* arg0, float arg1);
    static int32_t binarySearch(::java::lang::ObjectArray* arg0, ::java::lang::Object* arg1);
    static int32_t binarySearch(::java::lang::ObjectArray* arg0, ::java::lang::Object* arg1, Comparator* arg2);
    static int32_t binarySearch(::int64_tArray* arg0, int32_t arg1, int32_t arg2, int64_t arg3);
    static int32_t binarySearch(::int32_tArray* arg0, int32_t arg1, int32_t arg2, int32_t arg3);
    static int32_t binarySearch(::int16_tArray* arg0, int32_t arg1, int32_t arg2, int16_t arg3);
    static int32_t binarySearch(::char16_tArray* arg0, int32_t arg1, int32_t arg2, char16_t arg3);
    static int32_t binarySearch(::int8_tArray* arg0, int32_t arg1, int32_t arg2, int8_t arg3);
    static int32_t binarySearch(::doubleArray* arg0, int32_t arg1, int32_t arg2, double arg3);
    static int32_t binarySearch(::floatArray* arg0, int32_t arg1, int32_t arg2, float arg3);
    static int32_t binarySearch(::java::lang::ObjectArray* arg0, int32_t arg1, int32_t arg2, ::java::lang::Object* arg3);
    static int32_t binarySearch(::java::lang::ObjectArray* arg0, int32_t arg1, int32_t arg2, ::java::lang::Object* arg3, Comparator* arg4);
    /*static int32_t binarySearch0(::int64_tArray* arg0, int32_t arg1, int32_t arg2, int64_t arg3); (private) */
    /*static int32_t binarySearch0(::int32_tArray* arg0, int32_t arg1, int32_t arg2, int32_t arg3); (private) */
    /*static int32_t binarySearch0(::int16_tArray* arg0, int32_t arg1, int32_t arg2, int16_t arg3); (private) */
    /*static int32_t binarySearch0(::char16_tArray* arg0, int32_t arg1, int32_t arg2, char16_t arg3); (private) */
    /*static int32_t binarySearch0(::int8_tArray* arg0, int32_t arg1, int32_t arg2, int8_t arg3); (private) */
    /*static int32_t binarySearch0(::doubleArray* arg0, int32_t arg1, int32_t arg2, double arg3); (private) */
    /*static int32_t binarySearch0(::floatArray* arg0, int32_t arg1, int32_t arg2, float arg3); (private) */
    /*static int32_t binarySearch0(::java::lang::ObjectArray* arg0, int32_t arg1, int32_t arg2, ::java::lang::Object* arg3); (private) */
    /*static int32_t binarySearch0(::java::lang::ObjectArray* arg0, int32_t arg1, int32_t arg2, ::java::lang::Object* arg3, Comparator* arg4); (private) */
    static ::java::lang::ObjectArray* copyOf(::java::lang::ObjectArray* arg0, int32_t arg1);
    static ::int8_tArray* copyOf(::int8_tArray* arg0, int32_t arg1);
    static ::int16_tArray* copyOf(::int16_tArray* arg0, int32_t arg1);
    static ::int32_tArray* copyOf(::int32_tArray* arg0, int32_t arg1);
    static ::int64_tArray* copyOf(::int64_tArray* arg0, int32_t arg1);
    static ::char16_tArray* copyOf(::char16_tArray* arg0, int32_t arg1);
    static ::floatArray* copyOf(::floatArray* arg0, int32_t arg1);
    static ::doubleArray* copyOf(::doubleArray* arg0, int32_t arg1);
    static ::boolArray* copyOf(::boolArray* arg0, int32_t arg1);
    static ::java::lang::ObjectArray* copyOf(::java::lang::ObjectArray* arg0, int32_t arg1, ::java::lang::Class* arg2);
    static ::java::lang::ObjectArray* copyOfRange(::java::lang::ObjectArray* arg0, int32_t arg1, int32_t arg2);
    static ::int8_tArray* copyOfRange(::int8_tArray* arg0, int32_t arg1, int32_t arg2);
    static ::int16_tArray* copyOfRange(::int16_tArray* arg0, int32_t arg1, int32_t arg2);
    static ::int32_tArray* copyOfRange(::int32_tArray* arg0, int32_t arg1, int32_t arg2);
    static ::int64_tArray* copyOfRange(::int64_tArray* arg0, int32_t arg1, int32_t arg2);
    static ::char16_tArray* copyOfRange(::char16_tArray* arg0, int32_t arg1, int32_t arg2);
    static ::floatArray* copyOfRange(::floatArray* arg0, int32_t arg1, int32_t arg2);
    static ::doubleArray* copyOfRange(::doubleArray* arg0, int32_t arg1, int32_t arg2);
    static ::boolArray* copyOfRange(::boolArray* arg0, int32_t arg1, int32_t arg2);
    static ::java::lang::ObjectArray* copyOfRange(::java::lang::ObjectArray* arg0, int32_t arg1, int32_t arg2, ::java::lang::Class* arg3);
    static bool deepEquals(::java::lang::ObjectArray* arg0, ::java::lang::ObjectArray* arg1);

public: /* package */
    static bool deepEquals0(::java::lang::Object* arg0, ::java::lang::Object* arg1);

public:
    static int32_t deepHashCode(::java::lang::ObjectArray* arg0);
    static ::java::lang::String* deepToString(::java::lang::ObjectArray* arg0);
    /*static void deepToString(::java::lang::ObjectArray* arg0, ::java::lang::StringBuilder* arg1, Set* arg2); (private) */
    static bool equals(::int64_tArray* arg0, ::int64_tArray* arg1);
    static bool equals(::int32_tArray* arg0, ::int32_tArray* arg1);
    static bool equals(::int16_tArray* arg0, ::int16_tArray* arg1);
    static bool equals(::char16_tArray* arg0, ::char16_tArray* arg1);
    static bool equals(::int8_tArray* arg0, ::int8_tArray* arg1);
    static bool equals(::boolArray* arg0, ::boolArray* arg1);
    static bool equals(::doubleArray* arg0, ::doubleArray* arg1);
    static bool equals(::floatArray* arg0, ::floatArray* arg1);
    static bool equals(::java::lang::ObjectArray* arg0, ::java::lang::ObjectArray* arg1);
    static void fill(::int64_tArray* arg0, int64_t arg1);
    static void fill(::int32_tArray* arg0, int32_t arg1);
    static void fill(::int16_tArray* arg0, int16_t arg1);
    static void fill(::char16_tArray* arg0, char16_t arg1);
    static void fill(::int8_tArray* arg0, int8_t arg1);
    static void fill(::boolArray* arg0, bool arg1);
    static void fill(::doubleArray* arg0, double arg1);
    static void fill(::floatArray* arg0, float arg1);
    static void fill(::java::lang::ObjectArray* arg0, ::java::lang::Object* arg1);
    static void fill(::int64_tArray* arg0, int32_t arg1, int32_t arg2, int64_t arg3);
    static void fill(::int32_tArray* arg0, int32_t arg1, int32_t arg2, int32_t arg3);
    static void fill(::int16_tArray* arg0, int32_t arg1, int32_t arg2, int16_t arg3);
    static void fill(::char16_tArray* arg0, int32_t arg1, int32_t arg2, char16_t arg3);
    static void fill(::int8_tArray* arg0, int32_t arg1, int32_t arg2, int8_t arg3);
    static void fill(::boolArray* arg0, int32_t arg1, int32_t arg2, bool arg3);
    static void fill(::doubleArray* arg0, int32_t arg1, int32_t arg2, double arg3);
    static void fill(::floatArray* arg0, int32_t arg1, int32_t arg2, float arg3);
    static void fill(::java::lang::ObjectArray* arg0, int32_t arg1, int32_t arg2, ::java::lang::Object* arg3);
    static int32_t hashCode(::int64_tArray* arg0);
    static int32_t hashCode(::int32_tArray* arg0);
    static int32_t hashCode(::int16_tArray* arg0);
    static int32_t hashCode(::char16_tArray* arg0);
    static int32_t hashCode(::int8_tArray* arg0);
    static int32_t hashCode(::boolArray* arg0);
    static int32_t hashCode(::floatArray* arg0);
    static int32_t hashCode(::doubleArray* arg0);
    static int32_t hashCode(::java::lang::ObjectArray* arg0);
    /*static void legacyMergeSort(::java::lang::ObjectArray* arg0); (private) */
    /*static void legacyMergeSort(::java::lang::ObjectArray* arg0, Comparator* arg1); (private) */
    /*static void legacyMergeSort(::java::lang::ObjectArray* arg0, int32_t arg1, int32_t arg2); (private) */
    /*static void legacyMergeSort(::java::lang::ObjectArray* arg0, int32_t arg1, int32_t arg2, Comparator* arg3); (private) */
    /*static void mergeSort(::java::lang::ObjectArray* arg0, ::java::lang::ObjectArray* arg1, int32_t arg2, int32_t arg3, int32_t arg4); (private) */
    /*static void mergeSort(::java::lang::ObjectArray* arg0, ::java::lang::ObjectArray* arg1, int32_t arg2, int32_t arg3, int32_t arg4, Comparator* arg5); (private) */
    static void parallelPrefix(::java::lang::ObjectArray* arg0, ::java::util::function::BinaryOperator* arg1);
    static void parallelPrefix(::int64_tArray* arg0, ::java::util::function::LongBinaryOperator* arg1);
    static void parallelPrefix(::doubleArray* arg0, ::java::util::function::DoubleBinaryOperator* arg1);
    static void parallelPrefix(::int32_tArray* arg0, ::java::util::function::IntBinaryOperator* arg1);
    static void parallelPrefix(::java::lang::ObjectArray* arg0, int32_t arg1, int32_t arg2, ::java::util::function::BinaryOperator* arg3);
    static void parallelPrefix(::int64_tArray* arg0, int32_t arg1, int32_t arg2, ::java::util::function::LongBinaryOperator* arg3);
    static void parallelPrefix(::doubleArray* arg0, int32_t arg1, int32_t arg2, ::java::util::function::DoubleBinaryOperator* arg3);
    static void parallelPrefix(::int32_tArray* arg0, int32_t arg1, int32_t arg2, ::java::util::function::IntBinaryOperator* arg3);
    static void parallelSetAll(::java::lang::ObjectArray* arg0, ::java::util::function::IntFunction* arg1);
    static void parallelSetAll(::int32_tArray* arg0, ::java::util::function::IntUnaryOperator* arg1);
    static void parallelSetAll(::int64_tArray* arg0, ::java::util::function::IntToLongFunction* arg1);
    static void parallelSetAll(::doubleArray* arg0, ::java::util::function::IntToDoubleFunction* arg1);
    static void parallelSort(::int8_tArray* arg0);
    static void parallelSort(::char16_tArray* arg0);
    static void parallelSort(::int16_tArray* arg0);
    static void parallelSort(::int32_tArray* arg0);
    static void parallelSort(::int64_tArray* arg0);
    static void parallelSort(::floatArray* arg0);
    static void parallelSort(::doubleArray* arg0);
    static void parallelSort(::java::lang::ComparableArray* arg0);
    static void parallelSort(::java::lang::ObjectArray* arg0, Comparator* arg1);
    static void parallelSort(::int8_tArray* arg0, int32_t arg1, int32_t arg2);
    static void parallelSort(::char16_tArray* arg0, int32_t arg1, int32_t arg2);
    static void parallelSort(::int16_tArray* arg0, int32_t arg1, int32_t arg2);
    static void parallelSort(::int32_tArray* arg0, int32_t arg1, int32_t arg2);
    static void parallelSort(::int64_tArray* arg0, int32_t arg1, int32_t arg2);
    static void parallelSort(::floatArray* arg0, int32_t arg1, int32_t arg2);
    static void parallelSort(::doubleArray* arg0, int32_t arg1, int32_t arg2);
    static void parallelSort(::java::lang::ComparableArray* arg0, int32_t arg1, int32_t arg2);
    static void parallelSort(::java::lang::ObjectArray* arg0, int32_t arg1, int32_t arg2, Comparator* arg3);
    /*static void rangeCheck(int32_t arg0, int32_t arg1, int32_t arg2); (private) */
    static void setAll(::java::lang::ObjectArray* arg0, ::java::util::function::IntFunction* arg1);
    static void setAll(::int32_tArray* arg0, ::java::util::function::IntUnaryOperator* arg1);
    static void setAll(::int64_tArray* arg0, ::java::util::function::IntToLongFunction* arg1);
    static void setAll(::doubleArray* arg0, ::java::util::function::IntToDoubleFunction* arg1);
    static void sort(::int32_tArray* arg0);
    static void sort(::int64_tArray* arg0);
    static void sort(::int16_tArray* arg0);
    static void sort(::char16_tArray* arg0);
    static void sort(::int8_tArray* arg0);
    static void sort(::floatArray* arg0);
    static void sort(::doubleArray* arg0);
    static void sort(::java::lang::ObjectArray* arg0);
    static void sort(::java::lang::ObjectArray* arg0, Comparator* arg1);
    static void sort(::int32_tArray* arg0, int32_t arg1, int32_t arg2);
    static void sort(::int64_tArray* arg0, int32_t arg1, int32_t arg2);
    static void sort(::int16_tArray* arg0, int32_t arg1, int32_t arg2);
    static void sort(::char16_tArray* arg0, int32_t arg1, int32_t arg2);
    static void sort(::int8_tArray* arg0, int32_t arg1, int32_t arg2);
    static void sort(::floatArray* arg0, int32_t arg1, int32_t arg2);
    static void sort(::doubleArray* arg0, int32_t arg1, int32_t arg2);
    static void sort(::java::lang::ObjectArray* arg0, int32_t arg1, int32_t arg2);
    static void sort(::java::lang::ObjectArray* arg0, int32_t arg1, int32_t arg2, Comparator* arg3);
    static Spliterator* spliterator(::java::lang::ObjectArray* arg0);
    static Spliterator_OfInt* spliterator(::int32_tArray* arg0);
    static Spliterator_OfLong* spliterator(::int64_tArray* arg0);
    static Spliterator_OfDouble* spliterator(::doubleArray* arg0);
    static Spliterator* spliterator(::java::lang::ObjectArray* arg0, int32_t arg1, int32_t arg2);
    static Spliterator_OfInt* spliterator(::int32_tArray* arg0, int32_t arg1, int32_t arg2);
    static Spliterator_OfLong* spliterator(::int64_tArray* arg0, int32_t arg1, int32_t arg2);
    static Spliterator_OfDouble* spliterator(::doubleArray* arg0, int32_t arg1, int32_t arg2);
    static ::java::util::stream::Stream* stream(::java::lang::ObjectArray* arg0);
    static ::java::util::stream::IntStream* stream(::int32_tArray* arg0);
    static ::java::util::stream::LongStream* stream(::int64_tArray* arg0);
    static ::java::util::stream::DoubleStream* stream(::doubleArray* arg0);
    static ::java::util::stream::Stream* stream(::java::lang::ObjectArray* arg0, int32_t arg1, int32_t arg2);
    static ::java::util::stream::IntStream* stream(::int32_tArray* arg0, int32_t arg1, int32_t arg2);
    static ::java::util::stream::LongStream* stream(::int64_tArray* arg0, int32_t arg1, int32_t arg2);
    static ::java::util::stream::DoubleStream* stream(::doubleArray* arg0, int32_t arg1, int32_t arg2);
    /*static void swap(::java::lang::ObjectArray* arg0, int32_t arg1, int32_t arg2); (private) */
    static ::java::lang::String* toString(::int64_tArray* arg0);
    static ::java::lang::String* toString(::int32_tArray* arg0);
    static ::java::lang::String* toString(::int16_tArray* arg0);
    static ::java::lang::String* toString(::char16_tArray* arg0);
    static ::java::lang::String* toString(::int8_tArray* arg0);
    static ::java::lang::String* toString(::boolArray* arg0);
    static ::java::lang::String* toString(::floatArray* arg0);
    static ::java::lang::String* toString(::doubleArray* arg0);
    static ::java::lang::String* toString(::java::lang::ObjectArray* arg0);

    // Generated
    Arrays();
protected:
    Arrays(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

public: /* package */
    static bool& $assertionsDisabled();

private:
    virtual ::java::lang::Class* getClass0();
};
