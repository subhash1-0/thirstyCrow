// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <java/util/function/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct java::util::Spliterator
    : public virtual ::java::lang::Object
{
    static constexpr int32_t CONCURRENT { int32_t(4096) };
    static constexpr int32_t DISTINCT { int32_t(1) };
    static constexpr int32_t IMMUTABLE { int32_t(1024) };
    static constexpr int32_t NONNULL { int32_t(256) };
    static constexpr int32_t ORDERED { int32_t(16) };
    static constexpr int32_t SIZED { int32_t(64) };
    static constexpr int32_t SORTED { int32_t(4) };
    static constexpr int32_t SUBSIZED { int32_t(16384) };

    virtual int32_t characteristics() = 0;
    virtual int64_t estimateSize() = 0;
    virtual void forEachRemaining(::java::util::function::Consumer* arg0);
    virtual Comparator* getComparator();
    virtual int64_t getExactSizeIfKnown();
    virtual bool hasCharacteristics(int32_t arg0);
    virtual bool tryAdvance(::java::util::function::Consumer* arg0) = 0;
    virtual Spliterator* trySplit() = 0;

    // Generated
    static ::java::lang::Class *class_();
};
