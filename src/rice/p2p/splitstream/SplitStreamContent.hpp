// Generated from /pastry-2.1/src/rice/p2p/splitstream/SplitStreamContent.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/p2p/splitstream/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/p2p/scribe/rawserialization/RawScribeContent.hpp>

struct default_init_tag;

class rice::p2p::splitstream::SplitStreamContent
    : public virtual ::java::lang::Object
    , public virtual ::rice::p2p::scribe::rawserialization::RawScribeContent
{

public:
    typedef ::java::lang::Object super;
    static constexpr int16_t TYPE { int16_t(1) };

public: /* protected */
    ::int8_tArray* data {  };
protected:
    void ctor(::int8_tArray* data);

public:
    virtual ::int8_tArray* getData();
    int16_t getType() override;
    void serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */ override;
protected:
    void ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf) /* throws(IOException) */;

    // Generated

public:
    SplitStreamContent(::int8_tArray* data);
    SplitStreamContent(::rice::p2p::commonapi::rawserialization::InputBuffer* buf);
protected:
    SplitStreamContent(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
