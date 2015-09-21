// Generated from /pastry-2.1/src/rice/p2p/past/gc/rawserialization/JavaSerializedGCPastContent.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/p2p/past/fwd-pastry-2.1.hpp>
#include <rice/p2p/past/gc/fwd-pastry-2.1.hpp>
#include <rice/p2p/past/gc/rawserialization/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/p2p/past/gc/rawserialization/RawGCPastContent.hpp>

struct default_init_tag;

class rice::p2p::past::gc::rawserialization::JavaSerializedGCPastContent
    : public virtual ::java::lang::Object
    , public virtual RawGCPastContent
{

public:
    typedef ::java::lang::Object super;
    static constexpr int16_t TYPE { int16_t(0) };
    ::rice::p2p::past::gc::GCPastContent* content {  };
protected:
    void ctor(::rice::p2p::past::gc::GCPastContent* content);

public:
    void serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */ override;
    int16_t getType() override;
    ::java::lang::String* toString() override;
    virtual ::rice::p2p::past::PastContent* getContent();
    ::rice::p2p::past::PastContent* checkInsert(::rice::p2p::commonapi::Id* id, ::rice::p2p::past::PastContent* existingContent) /* throws(PastException) */ override;
    ::rice::p2p::past::PastContentHandle* getHandle(::rice::p2p::past::Past* local) override;
    ::rice::p2p::commonapi::Id* getId() override;
    bool isMutable() override;
    int64_t getVersion() override;
    ::rice::p2p::past::gc::GCPastContentHandle* getHandle(::rice::p2p::past::gc::GCPast* local, int64_t expiration) override;
    ::rice::p2p::past::gc::GCPastMetadata* getMetadata(int64_t expiration) override;

    // Generated
    JavaSerializedGCPastContent(::rice::p2p::past::gc::GCPastContent* content);
protected:
    JavaSerializedGCPastContent(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
