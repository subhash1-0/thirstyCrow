// Generated from /pastry-2.1/src/rice/pastry/leafset/LeafSet.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/pastry/leafset/fwd-pastry-2.1.hpp>
#include <rice/pastry/routing/fwd-pastry-2.1.hpp>
#include <java/util/Observable.hpp>
#include <java/io/Serializable.hpp>
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

class rice::pastry::leafset::LeafSet
    : public ::java::util::Observable
    , public virtual ::java::io::Serializable
    , public virtual ::java::lang::Iterable
{

public:
    typedef ::java::util::Observable super;

private:
    static constexpr int64_t serialVersionUID { int64_t(3960030608598552977LL) };
    ::rice::pastry::Id* baseId {  };
    ::rice::pastry::NodeHandle* baseHandle {  };
    SimilarSet* cwSet {  };
    SimilarSet* ccwSet {  };

public: /* package */
    bool observe {  };

private:
    int32_t theSize {  };

public: /* package */
    ::rice::pastry::routing::RoutingTable* routingTable {  };
protected:
    void ctor(LeafSet* that);
    void ctor(LeafSet* that, bool observe);
    void ctor(::rice::pastry::NodeHandle* localNode, int32_t size, ::rice::pastry::routing::RoutingTable* rt);
    void ctor(::rice::pastry::NodeHandle* localNode, int32_t size, bool observe);

private:
    void readObject(::java::io::ObjectInputStream* ois) /* throws(IOException, ClassNotFoundException) */;

public:
    virtual bool put(::rice::pastry::NodeHandle* handle);
    virtual bool put(::rice::pastry::NodeHandle* handle, bool suppressNotification);
    virtual bool test(::rice::pastry::NodeHandle* handle);
    virtual bool overlaps();
    virtual bool isComplete();
    virtual int32_t getIndex(::rice::pastry::NodeHandle* nh) /* throws(NoSuchElementException) */;
    virtual ::rice::pastry::NodeHandle* get(int32_t index);
    virtual bool member(::rice::pastry::NodeHandle* nid);
    virtual bool contains(::rice::pastry::NodeHandle* nh);
    virtual bool member(::rice::pastry::Id* nid);
    virtual void remove(::rice::pastry::NodeHandle* nh);
    virtual int32_t maxSize();
    virtual int32_t size();
    virtual int32_t cwSize();
    virtual int32_t ccwSize();

private:
    int32_t complement(int32_t inx);

public:
    virtual int32_t mostSimilar(::rice::pastry::Id* nid);
    virtual ::rice::pastry::NodeSet* neighborSet(int32_t max);
    virtual ::rice::pastry::NodeSet* replicaSet(::rice::pastry::Id* key, int32_t max);
    virtual int32_t getUniqueCount();
    ::java::util::Iterator* iterator() override;
    virtual ::java::util::Collection* getUniqueSet();

private:
    int32_t mod(int32_t x, int32_t y);

public:
    virtual ::rice::pastry::IdRange* range(::rice::pastry::NodeHandle* n, int32_t r);
    virtual ::rice::pastry::IdRange* range(::rice::pastry::NodeHandle* n, int32_t r, bool cw);
    virtual bool merge(LeafSet* remotels, ::rice::pastry::NodeHandle* from, ::rice::pastry::routing::RoutingTable* routeTable, bool testOnly, ::java::util::Set* insertedHandles);
    void addObserver(::java::util::Observer* o) override;
    void deleteObserver(::java::util::Observer* o) override;
    virtual void addNodeSetListener(::rice::pastry::NodeSetListener* listener);
    virtual void deleteNodeSetListener(::rice::pastry::NodeSetListener* listener);
    ::java::lang::String* toString() override;

public: /* protected */
    virtual bool isProperlyRemoved(::rice::pastry::NodeHandle* handle);
    virtual bool testOtherSet(SimilarSet* set, ::rice::pastry::NodeHandle* handle);

public:
    virtual bool directTest(::rice::pastry::NodeHandle* handle);
    virtual LeafSet* copy();
    static LeafSet* build(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::pastry::NodeHandleFactory* nhf) /* throws(IOException) */;
protected:
    void ctor(::rice::pastry::NodeHandle* localNode, int32_t size, bool observe, ::rice::pastry::NodeHandleArray* cwTable, ::rice::pastry::NodeHandleArray* ccwTable);

public:
    virtual void serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */;
    virtual ::java::util::List* asList();
    virtual void destroy();

    // Generated

private:
    LeafSet(LeafSet* that);
    LeafSet(LeafSet* that, bool observe);

public:
    LeafSet(::rice::pastry::NodeHandle* localNode, int32_t size, ::rice::pastry::routing::RoutingTable* rt);
    LeafSet(::rice::pastry::NodeHandle* localNode, int32_t size, bool observe);
    LeafSet(::rice::pastry::NodeHandle* localNode, int32_t size, bool observe, ::rice::pastry::NodeHandleArray* cwTable, ::rice::pastry::NodeHandleArray* ccwTable);
protected:
    LeafSet(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    void init();
    virtual ::java::lang::Class* getClass0();
};
