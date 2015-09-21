// Generated from /pastry-2.1/src/rice/p2p/past/gc/GCPastImpl.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/past/fwd-pastry-2.1.hpp>
#include <rice/p2p/past/gc/fwd-pastry-2.1.hpp>
#include <rice/p2p/past/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/persistence/fwd-pastry-2.1.hpp>
#include <rice/p2p/past/PastImpl.hpp>
#include <rice/p2p/past/gc/GCPast.hpp>

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

class rice::p2p::past::gc::GCPastImpl
    : public ::rice::p2p::past::PastImpl
    , public virtual GCPast
{

public:
    typedef ::rice::p2p::past::PastImpl super;
    static constexpr int64_t DEFAULT_EXPIRATION { int64_t(9223372036854775807LL) };

public: /* protected */
    ::rice::p2p::commonapi::IdFactory* realFactory {  };

public:
    int32_t collected {  };
    int32_t refreshed {  };
    ::java::lang::String* toString() override;
protected:
    void ctor(::rice::p2p::commonapi::Node* node, ::rice::persistence::StorageManager* manager, int32_t replicas, ::java::lang::String* instance, ::rice::p2p::past::PastPolicy* policy, int64_t collectionInterval);
    void ctor(::rice::p2p::commonapi::Node* node, ::rice::persistence::StorageManager* manager, ::rice::persistence::Cache* backup, int32_t replicas, ::java::lang::String* instance, ::rice::p2p::past::PastPolicy* policy, int64_t collectionInterval, ::rice::persistence::StorageManager* trash);

public:
    void insert(::rice::p2p::past::PastContent* obj, ::rice::Continuation* command) override;
    void insert(::rice::p2p::past::PastContent* obj, int64_t expiration, ::rice::Continuation* command) override;
    void refresh(::rice::p2p::commonapi::IdArray* array, int64_t expiration, ::rice::Continuation* command) override;
    void refresh(::rice::p2p::commonapi::IdArray* array, ::int64_tArray* expirations, ::rice::Continuation* command) override;

public: /* protected */
    virtual void refresh(GCIdSet* ids, ::rice::Continuation* command);

public:
    bool forward(::rice::p2p::commonapi::RouteMessage* message) override;
    void deliver(::rice::p2p::commonapi::Id* id, ::rice::p2p::commonapi::Message* message) override;

public: /* protected */
    virtual void collect(::java::util::SortedMap* map, ::rice::Continuation* command);

public:
    void fetch(::rice::p2p::commonapi::Id* id, ::rice::p2p::commonapi::NodeHandle* hint, ::rice::Continuation* command) override;
    void remove(::rice::p2p::commonapi::Id* id, ::rice::Continuation* command) override;
    ::rice::p2p::commonapi::IdSet* scan(::rice::p2p::commonapi::IdRange* range) override;
    ::rice::p2p::commonapi::IdSet* scan() override;
    bool exists(::rice::p2p::commonapi::Id* id) override;
    void existsInOverlay(::rice::p2p::commonapi::Id* id, ::rice::Continuation* command) override;
    void reInsert(::rice::p2p::commonapi::Id* id, ::rice::Continuation* command) override;

    // Generated
    GCPastImpl(::rice::p2p::commonapi::Node* node, ::rice::persistence::StorageManager* manager, int32_t replicas, ::java::lang::String* instance, ::rice::p2p::past::PastPolicy* policy, int64_t collectionInterval);
    GCPastImpl(::rice::p2p::commonapi::Node* node, ::rice::persistence::StorageManager* manager, ::rice::persistence::Cache* backup, int32_t replicas, ::java::lang::String* instance, ::rice::p2p::past::PastPolicy* policy, int64_t collectionInterval, ::rice::persistence::StorageManager* trash);
protected:
    GCPastImpl(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    void init();

public:
    virtual void fetch(::rice::p2p::past::PastContentHandle* handle, ::rice::Continuation* command);
    virtual ::rice::environment::Environment* getEnvironment();
    virtual ::java::lang::String* getInstance();
    virtual ::rice::p2p::commonapi::NodeHandle* getLocalNodeHandle();
    virtual int32_t getReplicationFactor();
    virtual void lookup(::rice::p2p::commonapi::Id* id, ::rice::Continuation* command);
    virtual void lookup(::rice::p2p::commonapi::Id* id, bool cache, ::rice::Continuation* command);
    virtual void lookupHandle(::rice::p2p::commonapi::Id* id, ::rice::p2p::commonapi::NodeHandle* handle, ::rice::Continuation* command);
    virtual void lookupHandles(::rice::p2p::commonapi::Id* id, int32_t max, ::rice::Continuation* command);
    virtual void setContentDeserializer(::rice::p2p::past::rawserialization::PastContentDeserializer* deserializer);
    virtual void setContentHandleDeserializer(::rice::p2p::past::rawserialization::PastContentHandleDeserializer* deserializer);

private:
    virtual ::java::lang::Class* getClass0();
    friend class GCPastImpl_GCPastDeserializer;
    friend class GCPastImpl_insert_1;
    friend class GCPastImpl_refresh_2;
    friend class GCPastImpl_refresh_3;
    friend class GCPastImpl_refresh_3_receiveResult_3_1;
    friend class GCPastImpl_refresh_3_receiveResult_3_2;
    friend class GCPastImpl_refresh_3_receiveResult_3_2_receiveResult_3_2_1;
    friend class GCPastImpl_deliver_4;
    friend class GCPastImpl_deliver_5;
    friend class GCPastImpl_deliver_5_receiveResult_5_1;
    friend class GCPastImpl_deliver_5_receiveResult_5_2;
    friend class GCPastImpl_deliver_5_receiveResult_5_2_receiveResult_5_2_1;
    friend class GCPastImpl_deliver_6;
    friend class GCPastImpl_deliver_7;
    friend class GCPastImpl_collect_8;
    friend class GCPastImpl_collect_8_receiveResult_8_1;
    friend class GCPastImpl_collect_8_receiveResult_8_1_receiveResult_8_1_1;
    friend class GCPastImpl_fetch_9;
    friend class GCPastImpl_fetch_10;
    friend class GCPastImpl_reInsert_11;
    friend class GCPastImpl_reInsert_11_receiveResult_11_1;
    friend class GCPastImpl_ReplicaMap;
};
