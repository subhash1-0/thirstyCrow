// Generated from /pastry-2.1/src/rice/p2p/commonapi/IdFactory.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/environment/random/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct rice::p2p::commonapi::IdFactory
    : public virtual ::java::lang::Object
{
    virtual Id* buildId(::int8_tArray* material) = 0;
    virtual Id* buildId(::int32_tArray* material) = 0;
    virtual Id* buildId(::java::lang::String* string) = 0;
    virtual Id* buildRandomId(::java::util::Random* rng) = 0;
    virtual Id* buildRandomId(::rice::environment::random::RandomSource* rng) = 0;
    virtual Id* buildIdFromToString(::java::lang::String* string) = 0;
    virtual Id* buildIdFromToString(::char16_tArray* chars, int32_t offset, int32_t length) = 0;
    virtual IdRange* buildIdRangeFromPrefix(::java::lang::String* string) = 0;
    virtual int32_t getIdToStringLength() = 0;
    virtual Id_Distance* buildIdDistance(::int8_tArray* material) = 0;
    virtual IdRange* buildIdRange(Id* cw, Id* ccw) = 0;
    virtual IdSet* buildIdSet() = 0;
    virtual IdSet* buildIdSet(::java::util::SortedMap* map) = 0;
    virtual NodeHandleSet* buildNodeHandleSet() = 0;

    // Generated
    static ::java::lang::Class *class_();
};
