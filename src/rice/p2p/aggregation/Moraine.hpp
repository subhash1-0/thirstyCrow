// Generated from /pastry-2.1/src/rice/p2p/aggregation/Moraine.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/fwd-pastry-2.1.hpp>
#include <rice/p2p/aggregation/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/glacier/fwd-pastry-2.1.hpp>
#include <rice/p2p/past/fwd-pastry-2.1.hpp>
#include <rice/p2p/past/gc/fwd-pastry-2.1.hpp>
#include <rice/p2p/past/rawserialization/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/p2p/past/gc/GCPast.hpp>
#include <rice/p2p/glacier/VersioningPast.hpp>

template<typename ComponentType, typename... Bases> struct SubArray;
namespace java
{
    namespace io
    {
typedef ::SubArray< ::java::io::Serializable, ::java::lang::ObjectArray > SerializableArray;
    } // io

    namespace lang
    {
typedef ::SubArray< ::java::lang::Comparable, ObjectArray > ComparableArray;
    } // lang
} // java

namespace rice
{
    namespace p2p
    {
        namespace commonapi
        {
typedef ::SubArray< ::rice::p2p::commonapi::Id, ::java::lang::ObjectArray, ::java::lang::ComparableArray, ::java::io::SerializableArray > IdArray;
        } // commonapi
    } // p2p
} // rice

struct default_init_tag;

class rice::p2p::aggregation::Moraine
    : public virtual ::java::lang::Object
    , public virtual ::rice::p2p::past::gc::GCPast
    , public virtual ::rice::p2p::glacier::VersioningPast
{

public:
    typedef ::java::lang::Object super;

public: /* protected */
    ::rice::p2p::past::gc::GCPast* newPast {  };
    ::rice::p2p::past::gc::GCPast* oldPast {  };
    ::rice::p2p::glacier::VersioningPast* vNewPast {  };
    ::rice::p2p::glacier::VersioningPast* vOldPast {  };
    ::rice::environment::logging::Logger* logger {  };
protected:
    void ctor(::rice::p2p::past::gc::GCPast* newPast, ::rice::p2p::past::gc::GCPast* oldPast);

public:
    void insert(::rice::p2p::past::PastContent* obj, ::rice::Continuation* command) override;
    void lookup(::rice::p2p::commonapi::Id* id, ::rice::Continuation* command) override;
    void lookup(::rice::p2p::commonapi::Id* id, bool cache, ::rice::Continuation* command) override;
    void lookupHandles(::rice::p2p::commonapi::Id* id, int32_t max, ::rice::Continuation* command) override;
    void lookupHandle(::rice::p2p::commonapi::Id* id, ::rice::p2p::commonapi::NodeHandle* handle, ::rice::Continuation* command) override;
    void fetch(::rice::p2p::past::PastContentHandle* handle, ::rice::Continuation* command) override;
    ::rice::p2p::commonapi::NodeHandle* getLocalNodeHandle() override;
    int32_t getReplicationFactor() override;
    ::rice::environment::Environment* getEnvironment() override;
    ::java::lang::String* getInstance() override;
    void setContentDeserializer(::rice::p2p::past::rawserialization::PastContentDeserializer* deserializer) override;
    void setContentHandleDeserializer(::rice::p2p::past::rawserialization::PastContentHandleDeserializer* deserializer) override;
    void insert(::rice::p2p::past::PastContent* obj, int64_t expiration, ::rice::Continuation* command) override;
    void refresh(::rice::p2p::commonapi::IdArray* ids, ::int64_tArray* expirations, ::rice::Continuation* command) override;
    void refresh(::rice::p2p::commonapi::IdArray* ids, int64_t expiration, ::rice::Continuation* command) override;
    void lookup(::rice::p2p::commonapi::Id* id, int64_t version, ::rice::Continuation* command) override;
    void lookupHandles(::rice::p2p::commonapi::Id* id, int64_t version, int32_t num, ::rice::Continuation* command) override;
    void refresh(::rice::p2p::commonapi::IdArray* ids, ::int64_tArray* versions, ::int64_tArray* expirations, ::rice::Continuation* command) override;

    // Generated
    Moraine(::rice::p2p::past::gc::GCPast* newPast, ::rice::p2p::past::gc::GCPast* oldPast);
protected:
    Moraine(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
    friend class Moraine_lookup_1;
    friend class Moraine_lookup_1_receiveResult_1_1;
    friend class Moraine_lookupHandles_2;
    friend class Moraine_fetch_3;
    friend class Moraine_refresh_4;
    friend class Moraine_lookup_5;
    friend class Moraine_lookup_5_receiveResult_5_1;
    friend class Moraine_lookupHandles_6;
    friend class Moraine_refresh_7;
};
