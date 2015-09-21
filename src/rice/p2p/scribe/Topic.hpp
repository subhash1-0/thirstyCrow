// Generated from /pastry-2.1/src/rice/p2p/scribe/Topic.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/p2p/scribe/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <java/io/Serializable.hpp>
#include <java/lang/Comparable.hpp>

struct default_init_tag;

class rice::p2p::scribe::Topic
    : public virtual ::java::lang::Object
    , public virtual ::java::io::Serializable
    , public virtual ::java::lang::Comparable
{

public:
    typedef ::java::lang::Object super;

public: /* protected */
    ::rice::p2p::commonapi::Id* id {  };
protected:
    void ctor(::rice::p2p::commonapi::Id* id);
    void ctor(::rice::p2p::commonapi::IdFactory* factory, ::java::lang::String* name);

public:
    virtual ::rice::p2p::commonapi::Id* getId();
    static ::rice::p2p::commonapi::Id* getId(::rice::p2p::commonapi::IdFactory* factory, ::java::lang::String* name);
    bool equals(::java::lang::Object* o) override;
    int32_t hashCode() override;
    ::java::lang::String* toString() override;
protected:
    void ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint) /* throws(IOException) */;

public:
    virtual void serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */;
    virtual int32_t compareTo(Topic* that);

    // Generated
    Topic(::rice::p2p::commonapi::Id* id);
    Topic(::rice::p2p::commonapi::IdFactory* factory, ::java::lang::String* name);
    Topic(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint);
protected:
    Topic(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    virtual int32_t compareTo(::java::lang::Object* arg0) override;

private:
    virtual ::java::lang::Class* getClass0();
};
