// Generated from /pastry-2.1/src/rice/p2p/multiring/MultiringNodeHandleSet.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/p2p/multiring/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/p2p/commonapi/NodeHandleSet.hpp>

struct default_init_tag;

class rice::p2p::multiring::MultiringNodeHandleSet
    : public virtual ::java::lang::Object
    , public virtual ::rice::p2p::commonapi::NodeHandleSet
{

public:
    typedef ::java::lang::Object super;
    static constexpr int16_t TYPE { int16_t(10) };

public: /* protected */
    ::rice::p2p::commonapi::NodeHandleSet* set {  };
    ::rice::p2p::commonapi::Id* ringId {  };
protected:
    void ctor(::rice::p2p::commonapi::Id* ringId, ::rice::p2p::commonapi::NodeHandleSet* set);

public: /* protected */
    virtual ::rice::p2p::commonapi::NodeHandleSet* getSet();

public:
    bool putHandle(::rice::p2p::commonapi::NodeHandle* handle) override;
    ::rice::p2p::commonapi::NodeHandle* getHandle(::rice::p2p::commonapi::Id* id) override;
    ::rice::p2p::commonapi::NodeHandle* getHandle(int32_t i) override;
    bool memberHandle(::rice::p2p::commonapi::Id* id) override;
    ::rice::p2p::commonapi::NodeHandle* removeHandle(::rice::p2p::commonapi::Id* id) override;
    int32_t size() override;
    int32_t getIndexHandle(::rice::p2p::commonapi::Id* id) /* throws(NoSuchElementException) */ override;
    bool equals(::java::lang::Object* o) override;
    int32_t hashCode() override;
    ::java::lang::String* toString() override;
protected:
    void ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint) /* throws(IOException) */;

public:
    void serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */ override;
    int16_t getType() override;

    // Generated

public: /* protected */
    MultiringNodeHandleSet(::rice::p2p::commonapi::Id* ringId, ::rice::p2p::commonapi::NodeHandleSet* set);

public:
    MultiringNodeHandleSet(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint);
protected:
    MultiringNodeHandleSet(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
