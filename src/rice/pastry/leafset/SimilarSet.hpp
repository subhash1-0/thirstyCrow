// Generated from /pastry-2.1/src/rice/pastry/leafset/SimilarSet.java

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
#include <rice/pastry/NodeSetEventSource.hpp>
#include <java/io/Serializable.hpp>

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

class rice::pastry::leafset::SimilarSet
    : public ::java::util::Observable
    , public virtual ::rice::pastry::NodeSetEventSource
    , public virtual ::java::io::Serializable
{

public:
    typedef ::java::util::Observable super;

private:
    static constexpr int64_t serialVersionUID { int64_t(2289610430696506873LL) };
    ::rice::pastry::NodeHandle* ln {  };
    bool clockwise {  };
    ::rice::pastry::NodeHandleArray* nodes {  };
    int32_t theSize {  };
    LeafSet* leafSet {  };
protected:
    void ctor(SimilarSet* that, LeafSet* ls);

public: /* protected */
    virtual void swap(int32_t i, int32_t j);
protected:
    void ctor(LeafSet* leafSet, ::rice::pastry::NodeHandle* localNode, int32_t size, bool cw);
    void ctor(LeafSet* leafSet, ::rice::pastry::NodeHandle* localNode, int32_t size, bool cw, ::rice::pastry::NodeHandleArray* handles);

public:
    virtual bool test(::rice::pastry::NodeHandle* handle);
    virtual bool put(::rice::pastry::NodeHandle* handle);
    virtual bool put(::rice::pastry::NodeHandle* handle, bool suppressNotify);

public: /* package */
    ::java::util::ArrayList* listeners {  };

public:
    void addObserver(::java::util::Observer* o) override;
    void deleteObserver(::java::util::Observer* o) override;
    void addNodeSetListener(::rice::pastry::NodeSetListener* listener) override;
    void removeNodeSetListener(::rice::pastry::NodeSetListener* listener) override;

public: /* protected */
    virtual void notifyListeners(::rice::pastry::NodeHandle* handle, bool added);

public:
    virtual ::rice::pastry::NodeHandle* get(::rice::pastry::Id* nid);
    virtual ::rice::pastry::NodeHandle* get(::rice::pastry::NodeHandle* nh);
    virtual ::rice::pastry::NodeHandle* get(int32_t i);
    virtual bool member(::rice::pastry::NodeHandle* nid);
    virtual bool member(::rice::pastry::Id* nid);
    virtual ::rice::pastry::NodeHandle* remove(::rice::pastry::Id* nid);
    virtual ::rice::pastry::NodeHandle* remove(::rice::pastry::NodeHandle* nh);

public: /* package */
    virtual void findMoreEntriesFromRoutingTable();

private:
    bool addNextEntry(::rice::pastry::routing::RouteSet* rs);

public: /* protected */
    virtual ::rice::pastry::NodeHandle* remove(int32_t i);

public:
    virtual int32_t getIndex(::rice::pastry::Id* nid);
    virtual int32_t getIndex(::rice::pastry::NodeHandle* nh);
    virtual int32_t size();

public: /* package */
    ::rice::pastry::Id_Distance* d1 {  };
    ::rice::pastry::Id_Distance* d {  };

public:
    virtual int32_t mostSimilar(::rice::pastry::Id* nid);
    virtual bool putHandle(::rice::p2p::commonapi::NodeHandle* handle);
    virtual ::rice::p2p::commonapi::NodeHandle* getHandle(int32_t i);
    virtual bool memberHandle(::rice::p2p::commonapi::Id* id);
    virtual ::rice::p2p::commonapi::NodeHandle* removeHandle(::rice::p2p::commonapi::Id* id);
    virtual int32_t getIndexHandle(::rice::p2p::commonapi::Id* id) /* throws(NoSuchElementException) */;

public: /* package */
    virtual SimilarSet* copy(LeafSet* newLeafSet);

public:
    virtual ::java::util::Collection* getCollection();

private:
    void readObject(::java::io::ObjectInputStream* in) /* throws(IOException, ClassNotFoundException) */;

public:
    ::java::lang::String* toString() override;
    virtual void destroy();

    // Generated

private:
    SimilarSet(SimilarSet* that, LeafSet* ls);

public:
    SimilarSet(LeafSet* leafSet, ::rice::pastry::NodeHandle* localNode, int32_t size, bool cw);
    SimilarSet(LeafSet* leafSet, ::rice::pastry::NodeHandle* localNode, int32_t size, bool cw, ::rice::pastry::NodeHandleArray* handles);
protected:
    SimilarSet(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    void init();
    virtual ::java::lang::Class* getClass0();
    friend class SimilarSet_addNextEntry_1;
};
