// Generated from /pastry-2.1/src/rice/p2p/glacier/FragmentKey.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/p2p/glacier/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/p2p/commonapi/Id.hpp>

struct default_init_tag;

class rice::p2p::glacier::FragmentKey
    : public virtual ::java::lang::Object
    , public virtual ::rice::p2p::commonapi::Id
{

public:
    typedef ::java::lang::Object super;
    static constexpr int16_t TYPE { int16_t(42) };

public: /* protected */
    VersionKey* key {  };
    int32_t id {  };

private:
    static constexpr int64_t serialVersionUID { int64_t(5373228569261524536LL) };
protected:
    void ctor(VersionKey* key, int32_t id);

public:
    bool isBetween(::rice::p2p::commonapi::Id* ccw, ::rice::p2p::commonapi::Id* cw) override;
    virtual VersionKey* getVersionKey();
    virtual int32_t getFragmentID();
    virtual FragmentKey* getPeerKey(int32_t otherId);
    bool equals(::java::lang::Object* peer) override;
    ::int8_tArray* toByteArray_() override;
    void toByteArray_(::int8_tArray* result, int32_t offset) override;
    int32_t getByteArrayLength() override;
    ::java::lang::String* toStringFull() override;
    ::java::lang::String* toString() override;
    ::rice::p2p::commonapi::Id_Distance* longDistanceFromId(::rice::p2p::commonapi::Id* nid) override;
    ::rice::p2p::commonapi::Id_Distance* distanceFromId(::rice::p2p::commonapi::Id* nid) override;
    ::rice::p2p::commonapi::Id* addToId(::rice::p2p::commonapi::Id_Distance* offset) override;
    bool clockwise(::rice::p2p::commonapi::Id* nid) override;
    virtual int32_t compareTo(::rice::p2p::commonapi::Id* o);
    int32_t hashCode() override;
protected:
    void ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint) /* throws(IOException) */;

public:
    void serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */ override;
    int16_t getType() override;

    // Generated
    FragmentKey(VersionKey* key, int32_t id);
    FragmentKey(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint);
protected:
    FragmentKey(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    virtual int32_t compareTo(::java::lang::Object* o) override;

private:
    virtual ::java::lang::Class* getClass0();
};
