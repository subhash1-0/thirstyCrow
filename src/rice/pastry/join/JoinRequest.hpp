// Generated from /pastry-2.1/src/rice/pastry/join/JoinRequest.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/pastry/join/fwd-pastry-2.1.hpp>
#include <rice/pastry/leafset/fwd-pastry-2.1.hpp>
#include <rice/pastry/routing/fwd-pastry-2.1.hpp>
#include <rice/pastry/messaging/PRawMessage.hpp>

template<typename ComponentType, typename... Bases> struct SubArray;
namespace java
{
    namespace io
    {
typedef ::SubArray< ::java::io::Serializable, ::java::lang::ObjectArray > SerializableArray;
    } // io

    namespace lang
    {
typedef ::SubArray< ::java::lang::Cloneable, ObjectArray > CloneableArray;
typedef ::SubArray< ::java::lang::Iterable, ObjectArray > IterableArray;
    } // lang

    namespace util
    {
typedef ::SubArray< ::java::util::Observer, ::java::lang::ObjectArray > ObserverArray;
    } // util
} // java

namespace rice
{
    namespace p2p
    {
        namespace commonapi
        {
typedef ::SubArray< ::rice::p2p::commonapi::NodeHandleSet, ::java::lang::ObjectArray, ::java::io::SerializableArray > NodeHandleSetArray;
        } // commonapi
    } // p2p

    namespace pastry
    {
typedef ::SubArray< ::rice::pastry::NodeSetI, ::java::lang::ObjectArray, ::rice::p2p::commonapi::NodeHandleSetArray > NodeSetIArray;

        namespace routing
        {
typedef ::SubArray< ::rice::pastry::routing::RouteSet, ::java::lang::ObjectArray, ::rice::pastry::NodeSetIArray, ::java::io::SerializableArray, ::java::util::ObserverArray, ::java::lang::IterableArray > RouteSetArray;
typedef ::SubArray< ::rice::pastry::routing::RouteSetArray, ::java::lang::CloneableArray, ::java::io::SerializableArray > RouteSetArrayArray;
        } // routing
    } // pastry
} // rice

struct default_init_tag;

class rice::pastry::join::JoinRequest
    : public ::rice::pastry::messaging::PRawMessage
{

public:
    typedef ::rice::pastry::messaging::PRawMessage super;
    static constexpr int8_t HAS_HANDLE { int8_t(1) };
    static constexpr int8_t HAS_JOIN_HANDLE { int8_t(2) };
    static constexpr int8_t HAS_LEAFSET { int8_t(2) };

public: /* package */
    static constexpr int64_t serialVersionUID { int64_t(231671018732832563LL) };

public:
    static constexpr int16_t TYPE { int16_t(1) };

public: /* protected */
    ::rice::pastry::NodeHandle* handle {  };
    ::rice::pastry::NodeHandle* joinHandle {  };

private:
    int16_t rowCount {  };
    ::rice::pastry::routing::RouteSetArrayArray* rows {  };
    ::rice::pastry::leafset::LeafSet* leafSet {  };
    int8_t rtBaseBitLength {  };

public: /* protected */
    int64_t timestamp {  };
protected:
    void ctor(::rice::pastry::NodeHandle* nh, int8_t rtBaseBitLength);
    void ctor(::rice::pastry::NodeHandle* nh, int8_t rtBaseBitLength, int64_t timestamp);
    void ctor(::rice::pastry::NodeHandle* nh, ::java::util::Date* stamp, int8_t rtBaseBitLength);

public:
    virtual ::rice::pastry::NodeHandle* getHandle();
    virtual ::rice::pastry::NodeHandle* getJoinHandle();
    virtual ::rice::pastry::leafset::LeafSet* getLeafSet();
    virtual bool accepted();
    virtual void acceptJoin(::rice::pastry::NodeHandle* nh, ::rice::pastry::leafset::LeafSet* ls);
    virtual int32_t lastRow();
    virtual void pushRow(::rice::pastry::routing::RouteSetArray* row);
    virtual ::rice::pastry::routing::RouteSetArray* getRow(int32_t i);
    virtual int32_t numRows();

private:
    void initialize(int8_t rtBaseBitLength);

public:
    ::java::lang::String* toString() override;
    int16_t getType() override;
    void serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */ override;
protected:
    void ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::pastry::NodeHandleFactory* nhf, ::rice::pastry::NodeHandle* sender, ::rice::pastry::PastryNode* localNode) /* throws(IOException) */;

    // Generated

public:
    JoinRequest(::rice::pastry::NodeHandle* nh, int8_t rtBaseBitLength);
    JoinRequest(::rice::pastry::NodeHandle* nh, int8_t rtBaseBitLength, int64_t timestamp);
    JoinRequest(::rice::pastry::NodeHandle* nh, ::java::util::Date* stamp, int8_t rtBaseBitLength);
    JoinRequest(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::pastry::NodeHandleFactory* nhf, ::rice::pastry::NodeHandle* sender, ::rice::pastry::PastryNode* localNode);
protected:
    JoinRequest(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
