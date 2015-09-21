// Generated from /pastry-2.1/src/rice/p2p/past/gc/GCId.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/p2p/past/gc/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/p2p/commonapi/Id.hpp>

struct default_init_tag;

class rice::p2p::past::gc::GCId
    : public virtual ::java::lang::Object
    , public virtual ::rice::p2p::commonapi::Id
{

public:
    typedef ::java::lang::Object super;
    static constexpr int16_t TYPE { int16_t(3) };

public: /* protected */
    ::rice::p2p::commonapi::Id* id {  };
    int64_t expiration {  };
protected:
    void ctor(::rice::p2p::commonapi::Id* id, int64_t expiration);

public:
    virtual ::rice::p2p::commonapi::Id* getId();
    virtual int64_t getExpiration();
    bool isBetween(::rice::p2p::commonapi::Id* ccw, ::rice::p2p::commonapi::Id* cw) override;
    bool clockwise(::rice::p2p::commonapi::Id* nid) override;
    ::rice::p2p::commonapi::Id* addToId(::rice::p2p::commonapi::Id_Distance* offset) override;
    ::rice::p2p::commonapi::Id_Distance* distanceFromId(::rice::p2p::commonapi::Id* nid) override;
    ::rice::p2p::commonapi::Id_Distance* longDistanceFromId(::rice::p2p::commonapi::Id* nid) override;
    ::int8_tArray* toByteArray_() override;
    void toByteArray_(::int8_tArray* array, int32_t offset) override;
    int32_t getByteArrayLength() override;
    bool equals(::java::lang::Object* o) override;
    int32_t hashCode() override;
    ::java::lang::String* toString() override;
    ::java::lang::String* toStringFull() override;
    virtual int32_t compareTo(::rice::p2p::commonapi::Id* o);
    int16_t getType() override;
    void serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */ override;
protected:
    void ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint) /* throws(IOException) */;

    // Generated

public:
    GCId(::rice::p2p::commonapi::Id* id, int64_t expiration);
    GCId(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint);
protected:
    GCId(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    virtual int32_t compareTo(::java::lang::Object* o) override;

private:
    virtual ::java::lang::Class* getClass0();
};
