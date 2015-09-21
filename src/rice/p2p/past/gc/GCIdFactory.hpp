// Generated from /pastry-2.1/src/rice/p2p/past/gc/GCIdFactory.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/environment/random/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/past/gc/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/p2p/commonapi/IdFactory.hpp>

struct default_init_tag;

class rice::p2p::past::gc::GCIdFactory
    : public virtual ::java::lang::Object
    , public virtual ::rice::p2p::commonapi::IdFactory
{

public:
    typedef ::java::lang::Object super;

public: /* protected */
    ::rice::p2p::commonapi::IdFactory* factory {  };
protected:
    void ctor(::rice::p2p::commonapi::IdFactory* factory);

public:
    virtual ::rice::p2p::commonapi::Id* buildNormalId(::int8_tArray* material);
    ::rice::p2p::commonapi::Id* buildId(::int8_tArray* material) override;
    ::rice::p2p::commonapi::Id* buildId(::int32_tArray* material) override;
    ::rice::p2p::commonapi::Id* buildId(::java::lang::String* string) override;
    ::rice::p2p::commonapi::Id* buildRandomId(::java::util::Random* rng) override;
    ::rice::p2p::commonapi::Id* buildRandomId(::rice::environment::random::RandomSource* rng) override;
    ::rice::p2p::commonapi::Id* buildIdFromToString(::java::lang::String* string) override;
    ::rice::p2p::commonapi::Id* buildIdFromToString(::char16_tArray* chars, int32_t offset, int32_t length) override;
    ::rice::p2p::commonapi::IdRange* buildIdRangeFromPrefix(::java::lang::String* string) override;
    int32_t getIdToStringLength() override;
    ::rice::p2p::commonapi::Id_Distance* buildIdDistance(::int8_tArray* material) override;
    ::rice::p2p::commonapi::IdRange* buildIdRange(::rice::p2p::commonapi::Id* cw, ::rice::p2p::commonapi::Id* ccw) override;
    ::rice::p2p::commonapi::IdSet* buildIdSet() override;
    ::rice::p2p::commonapi::IdSet* buildIdSet(::java::util::SortedMap* map) override;
    ::rice::p2p::commonapi::NodeHandleSet* buildNodeHandleSet() override;

    // Generated
    GCIdFactory(::rice::p2p::commonapi::IdFactory* factory);
protected:
    GCIdFactory(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
    friend class GCIdFactory_GCSortedMap;
    friend class GCIdFactory_GCEntrySet;
    friend class GCIdFactory_GCEntrySet_iterator_1;
    friend class GCIdFactory_GCMapEntry;
};
