// Generated from /pastry-2.1/src/rice/p2p/past/rawserialization/JavaSerializedPastContent.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/p2p/past/fwd-pastry-2.1.hpp>
#include <rice/p2p/past/rawserialization/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/p2p/past/rawserialization/RawPastContent.hpp>

struct default_init_tag;

class rice::p2p::past::rawserialization::JavaSerializedPastContent
    : public virtual ::java::lang::Object
    , public virtual RawPastContent
{

public:
    typedef ::java::lang::Object super;
    static constexpr int16_t TYPE { int16_t(0) };
    ::rice::p2p::past::PastContent* content {  };
protected:
    void ctor(::rice::p2p::past::PastContent* content);

public:
    void serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */ override;
    int16_t getType() override;
    ::java::lang::String* toString() override;
    virtual ::rice::p2p::past::PastContent* getContent();
    ::rice::p2p::past::PastContent* checkInsert(::rice::p2p::commonapi::Id* id, ::rice::p2p::past::PastContent* existingContent) /* throws(PastException) */ override;
    ::rice::p2p::past::PastContentHandle* getHandle(::rice::p2p::past::Past* local) override;
    ::rice::p2p::commonapi::Id* getId() override;
    bool isMutable() override;

    // Generated
    JavaSerializedPastContent(::rice::p2p::past::PastContent* content);
protected:
    JavaSerializedPastContent(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
