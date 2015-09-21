// Generated from /pastry-2.1/src/rice/p2p/splitstream/SplitStreamImpl.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/p2p/scribe/fwd-pastry-2.1.hpp>
#include <rice/p2p/splitstream/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/p2p/scribe/rawserialization/ScribeContentDeserializer.hpp>

struct default_init_tag;

class rice::p2p::splitstream::SplitStreamImpl_SplitStreamImpl_2
    : public virtual ::java::lang::Object
    , public virtual ::rice::p2p::scribe::rawserialization::ScribeContentDeserializer
{

public:
    typedef ::java::lang::Object super;
    ::rice::p2p::scribe::ScribeContent* deserializeScribeContent(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint, int16_t contentType) /* throws(IOException) */ override;

    // Generated
    SplitStreamImpl_SplitStreamImpl_2(SplitStreamImpl *SplitStreamImpl_this);
    static ::java::lang::Class *class_();
    SplitStreamImpl *SplitStreamImpl_this;

private:
    virtual ::java::lang::Class* getClass0();
    friend class SplitStreamImpl;
    friend class SplitStreamImpl_SplitStreamImpl_1;
};
