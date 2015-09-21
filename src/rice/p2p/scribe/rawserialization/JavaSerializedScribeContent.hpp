// Generated from /pastry-2.1/src/rice/p2p/scribe/rawserialization/JavaSerializedScribeContent.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/p2p/scribe/fwd-pastry-2.1.hpp>
#include <rice/p2p/scribe/rawserialization/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/p2p/scribe/rawserialization/RawScribeContent.hpp>

struct default_init_tag;

class rice::p2p::scribe::rawserialization::JavaSerializedScribeContent
    : public virtual ::java::lang::Object
    , public virtual RawScribeContent
{

public:
    typedef ::java::lang::Object super;
    static constexpr int16_t TYPE { int16_t(0) };
    ::rice::p2p::scribe::ScribeContent* content {  };
protected:
    void ctor(::rice::p2p::scribe::ScribeContent* content);

public:
    void serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */ override;
    int16_t getType() override;
    ::java::lang::String* toString() override;
    virtual ::rice::p2p::scribe::ScribeContent* getContent();

    // Generated
    JavaSerializedScribeContent(::rice::p2p::scribe::ScribeContent* content);
protected:
    JavaSerializedScribeContent(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
