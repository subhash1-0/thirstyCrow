// Generated from /pastry-2.1/src/rice/pastry/routing/RouteSet.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/pastry/routing/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/pastry/NodeSetI.hpp>
#include <java/io/Serializable.hpp>
#include <java/util/Observer.hpp>
#include <java/lang/Iterable.hpp>

template<typename ComponentType, typename... Bases> struct SubArray;
namespace java
{
    namespace io
    {
typedef ::SubArray< ::java::io::Serializable, ::java::lang::ObjectArray > SerializableArray;
    } // io

    namespace util
    {
typedef ::SubArray< ::java::util::Observable, ::java::lang::ObjectArray > ObservableArray;
    } // util
} // java

namespace rice
{
    namespace p2p
    {
        namespace commonapi
        {
typedef ::SubArray< ::rice::p2p::commonapi::NodeHandle, ::java::util::ObservableArray, ::java::io::SerializableArray > NodeHandleArray;

            namespace rawserialization
            {
typedef ::SubArray< ::rice::p2p::commonapi::rawserialization::RawSerializable, ::java::lang::ObjectArray > RawSerializableArray;
            } // rawserialization
        } // commonapi
    } // p2p

    namespace pastry
    {
typedef ::SubArray< ::rice::pastry::NodeHandle, ::rice::p2p::commonapi::NodeHandleArray, ::rice::p2p::commonapi::rawserialization::RawSerializableArray > NodeHandleArray;
    } // pastry
} // rice

struct default_init_tag;

class rice::pastry::routing::RouteSet
    : public virtual ::java::lang::Object
    , public virtual ::rice::pastry::NodeSetI
    , public virtual ::java::io::Serializable
    , public virtual ::java::util::Observer
    , public virtual ::java::lang::Iterable
{

public:
    typedef ::java::lang::Object super;
    static constexpr int16_t TYPE { int16_t(2) };

private:
    static constexpr int64_t serialVersionUID { int64_t(8156336294555109590LL) };
    ::rice::pastry::NodeHandleArray* nodes {  };
    int32_t theSize {  };
    int32_t closest {  };

public: /* package */
    int32_t row {  };
    int32_t col {  };
    ::rice::pastry::PastryNode* localNode {  };
protected:
    void ctor(int32_t maxSize, int32_t row, int32_t col, ::rice::pastry::PastryNode* local, ::rice::pastry::NodeHandle* initialVal);
    void ctor(int32_t maxSize, int32_t row, int32_t col, ::rice::pastry::PastryNode* local);

public:
    ::java::lang::String* toString() override;
    bool put(::rice::pastry::NodeHandle* handle) override;
    void update(::java::util::Observable* o, ::java::lang::Object* arg) override;
    virtual ::rice::pastry::NodeHandle* remove(::rice::pastry::Id* nid);
    ::rice::pastry::NodeHandle* remove(::rice::pastry::NodeHandle* nh) override;

public: /* package */
    RoutingTable* observer {  };

private:
    void notifyTable(::rice::pastry::NodeHandle* handle, bool added);

public:
    virtual void setRoutingTable(RoutingTable* rt);
    bool member(::rice::pastry::NodeHandle* nh) override;
    virtual bool member(::rice::pastry::Id* nid);
    int32_t size() override;
    virtual int32_t capacity();
    virtual void pingAllNew();
    virtual ::rice::pastry::NodeHandle* closestNode();
    virtual ::rice::pastry::NodeHandle* closestNode(int32_t minLiveness);
    ::rice::pastry::NodeHandle* get(int32_t i) override;
    ::rice::pastry::NodeHandle* get(::rice::pastry::Id* nid) override;
    int32_t getIndex(::rice::pastry::Id* nid) override;
    int32_t getIndex(::rice::pastry::NodeHandle* nh) override;

private:
    void readObject(::java::io::ObjectInputStream* in) /* throws(IOException, ClassNotFoundException) */;
    void writeObject(::java::io::ObjectOutputStream* out) /* throws(IOException, ClassNotFoundException) */;

public:
    bool putHandle(::rice::p2p::commonapi::NodeHandle* handle) override;
    ::rice::p2p::commonapi::NodeHandle* getHandle(::rice::p2p::commonapi::Id* id) override;
    ::rice::p2p::commonapi::NodeHandle* getHandle(int32_t i) override;
    bool memberHandle(::rice::p2p::commonapi::Id* id) override;
    ::rice::p2p::commonapi::NodeHandle* removeHandle(::rice::p2p::commonapi::Id* id) override;
    int32_t getIndexHandle(::rice::p2p::commonapi::Id* id) /* throws(NoSuchElementException) */ override;
    int16_t getType() override;
    void serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */ override;
protected:
    void ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::pastry::NodeHandleFactory* nhf, ::rice::pastry::PastryNode* local) /* throws(IOException) */;

public:
    virtual void destroy();
    ::java::util::Iterator* iterator() override;
    virtual bool isEmpty();

    // Generated
    RouteSet(int32_t maxSize, int32_t row, int32_t col, ::rice::pastry::PastryNode* local, ::rice::pastry::NodeHandle* initialVal);
    RouteSet(int32_t maxSize, int32_t row, int32_t col, ::rice::pastry::PastryNode* local);
    RouteSet(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::pastry::NodeHandleFactory* nhf, ::rice::pastry::PastryNode* local);
protected:
    RouteSet(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
