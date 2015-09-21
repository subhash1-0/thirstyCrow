// Generated from /pastry-2.1/src/rice/pastry/NodeSet.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/environment/random/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/pastry/NodeSetI.hpp>
#include <java/io/Serializable.hpp>

struct default_init_tag;

class rice::pastry::NodeSet
    : public virtual ::java::lang::Object
    , public virtual NodeSetI
    , public virtual ::java::io::Serializable
{

public:
    typedef ::java::lang::Object super;
    static constexpr int16_t TYPE { int16_t(1) };

public: /* package */
    static constexpr int64_t serialVersionUID { int64_t(4410658508346287677LL) };

private:
    ::java::util::Vector* set {  };
protected:
    void ctor();
    void ctor(::java::util::Vector* s);
    void ctor(NodeSet* o);

public:
    bool put(NodeHandle* handle) override;
    virtual void randomize(::rice::environment::random::RandomSource* random);
    NodeHandle* get(Id* nid) override;
    NodeHandle* get(int32_t i) override;

private:
    bool memberId(::rice::p2p::commonapi::Id* id);

public:
    virtual NodeHandle* remove(Id* nid);
    int32_t size() override;
    int32_t getIndex(Id* nid) override;
    int32_t getIndex(NodeHandle* nh) override;

private:
    int32_t getIndexId(::rice::p2p::commonapi::Id* nid);

public:
    virtual bool insert(int32_t index, NodeHandle* handle);
    NodeHandle* remove(NodeHandle* handle) override;
    virtual void remove(int32_t index);
    virtual int32_t indexOf(NodeHandle* handle);
    bool member(NodeHandle* handle) override;

public: /* package */
    virtual NodeSet* subSet(int32_t from, int32_t to);

public:
    virtual ::java::util::Iterator* getIterator();
    ::java::lang::String* toString() override;
    bool putHandle(::rice::p2p::commonapi::NodeHandle* handle) override;
    ::rice::p2p::commonapi::NodeHandle* getHandle(::rice::p2p::commonapi::Id* id) override;
    ::rice::p2p::commonapi::NodeHandle* getHandle(int32_t i) override;
    bool memberHandle(::rice::p2p::commonapi::Id* id) override;
    ::rice::p2p::commonapi::NodeHandle* removeHandle(::rice::p2p::commonapi::Id* id) override;
    int32_t getIndexHandle(::rice::p2p::commonapi::Id* id) /* throws(NoSuchElementException) */ override;
    virtual ::java::util::Iterator* iterator();
protected:
    void ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, NodeHandleFactory* nhf) /* throws(IOException) */;

public:
    void serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */ override;
    int16_t getType() override;
    virtual ::java::util::Collection* getCollection();

    // Generated
    NodeSet();
    NodeSet(::java::util::Vector* s);
    NodeSet(NodeSet* o);
    NodeSet(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, NodeHandleFactory* nhf);
protected:
    NodeSet(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
