// Generated from /pastry-2.1/src/rice/p2p/commonapi/Id.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <java/lang/Comparable.hpp>
#include <java/io/Serializable.hpp>

struct rice::p2p::commonapi::Id
    : public virtual ::java::lang::Comparable
    , public virtual ::java::io::Serializable
{
    virtual bool isBetween(Id* ccw, Id* cw) = 0;
    virtual bool clockwise(Id* nid) = 0;
    virtual Id* addToId(Id_Distance* offset) = 0;
    virtual Id_Distance* distanceFromId(Id* nid) = 0;
    virtual Id_Distance* longDistanceFromId(Id* nid) = 0;
    virtual ::int8_tArray* toByteArray_() = 0;
    virtual void toByteArray_(::int8_tArray* array, int32_t offset) = 0;
    virtual int32_t getByteArrayLength() = 0;
    virtual ::java::lang::String* toStringFull() = 0;
    virtual void serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */ = 0;
    virtual int16_t getType() = 0;

    // Generated
    static ::java::lang::Class *class_();
};
