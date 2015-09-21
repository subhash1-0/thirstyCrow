// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <java/util/function/fwd-pastry-2.1.hpp>
#include <java/util/stream/fwd-pastry-2.1.hpp>
#include <java/util/stream/BaseStream.hpp>

struct java::util::stream::Stream
    : public virtual BaseStream
{

    virtual bool allMatch(::java::util::function::Predicate* arg0) = 0;
    virtual bool anyMatch(::java::util::function::Predicate* arg0) = 0;
    static Stream_Builder* builder();
    virtual ::java::lang::Object* collect(Collector* arg0) = 0;
    virtual ::java::lang::Object* collect(::java::util::function::Supplier* arg0, ::java::util::function::BiConsumer* arg1, ::java::util::function::BiConsumer* arg2) = 0;
    static Stream* concat(Stream* arg0, Stream* arg1);
    virtual int64_t count() = 0;
    virtual Stream* distinct() = 0;
    static Stream* empty();
    virtual Stream* filter(::java::util::function::Predicate* arg0) = 0;
    virtual ::java::util::Optional* findAny() = 0;
    virtual ::java::util::Optional* findFirst() = 0;
    virtual Stream* flatMap(::java::util::function::Function* arg0) = 0;
    virtual DoubleStream* flatMapToDouble(::java::util::function::Function* arg0) = 0;
    virtual IntStream* flatMapToInt(::java::util::function::Function* arg0) = 0;
    virtual LongStream* flatMapToLong(::java::util::function::Function* arg0) = 0;
    virtual void forEach(::java::util::function::Consumer* arg0) = 0;
    virtual void forEachOrdered(::java::util::function::Consumer* arg0) = 0;
    static Stream* generate(::java::util::function::Supplier* arg0);
    static Stream* iterate(::java::lang::Object* arg0, ::java::util::function::UnaryOperator* arg1);
    virtual Stream* limit(int64_t arg0) = 0;
    virtual Stream* map(::java::util::function::Function* arg0) = 0;
    virtual DoubleStream* mapToDouble(::java::util::function::ToDoubleFunction* arg0) = 0;
    virtual IntStream* mapToInt(::java::util::function::ToIntFunction* arg0) = 0;
    virtual LongStream* mapToLong(::java::util::function::ToLongFunction* arg0) = 0;
    virtual ::java::util::Optional* max(::java::util::Comparator* arg0) = 0;
    virtual ::java::util::Optional* min(::java::util::Comparator* arg0) = 0;
    virtual bool noneMatch(::java::util::function::Predicate* arg0) = 0;
    static Stream* of(::java::lang::Object* arg0);
    static Stream* of(::java::lang::ObjectArray* arg0);
    virtual Stream* peek(::java::util::function::Consumer* arg0) = 0;
    virtual ::java::util::Optional* reduce(::java::util::function::BinaryOperator* arg0) = 0;
    virtual ::java::lang::Object* reduce(::java::lang::Object* arg0, ::java::util::function::BinaryOperator* arg1) = 0;
    virtual ::java::lang::Object* reduce(::java::lang::Object* arg0, ::java::util::function::BiFunction* arg1, ::java::util::function::BinaryOperator* arg2) = 0;
    virtual Stream* skip(int64_t arg0) = 0;
    virtual Stream* sorted() = 0;
    virtual Stream* sorted(::java::util::Comparator* arg0) = 0;
    virtual ::java::lang::ObjectArray* toArray_() = 0;
    virtual ::java::lang::ObjectArray* toArray_(::java::util::function::IntFunction* arg0) = 0;

    // Generated
    static ::java::lang::Class *class_();
};
