// Generated from /pastry-2.1/src/rice/p2p/multiring/RingId.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/p2p/multiring/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/p2p/commonapi/Id.hpp>

struct default_init_tag;

class rice::p2p::multiring::RingId
    : public virtual ::java::lang::Object
    , public virtual ::rice::p2p::commonapi::Id
{

public:
    typedef ::java::lang::Object super;

private:
    static int16_t TYPE_;
    static constexpr int64_t serialVersionUID { int64_t(-4390496639871320200LL) };
    static ::java::util::WeakHashMap* RINGID_MAP_;

public: /* protected */
    ::rice::p2p::commonapi::Id* id {  };
    ::rice::p2p::commonapi::Id* ringId {  };
protected:
    void ctor(::rice::p2p::commonapi::Id* ringId, ::rice::p2p::commonapi::Id* id);

public:
    static RingId* build(::rice::p2p::commonapi::Id* ringId, ::rice::p2p::commonapi::Id* id);

private:
    static RingId* resolve(RingId* id);
    ::java::lang::Object* readResolve() /* throws(ObjectStreamException) */;

public:
    static RingId* build(::java::lang::String* s);
    virtual ::rice::p2p::commonapi::Id* getId();
    virtual ::rice::p2p::commonapi::Id* getRingId();
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

private:
    RingId(::rice::p2p::commonapi::Id* ringId, ::rice::p2p::commonapi::Id* id);

public:
    RingId(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint);
protected:
    RingId(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    static void clinit();
    virtual int32_t compareTo(::java::lang::Object* o) override;
    static int16_t& TYPE();

private:
    static ::java::util::WeakHashMap*& RINGID_MAP();
    virtual ::java::lang::Class* getClass0();
};
