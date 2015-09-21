// Generated from /pastry-2.1/src/rice/p2p/past/rawserialization/JavaPastContentHandleDeserializer.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/p2p/past/fwd-pastry-2.1.hpp>
#include <rice/p2p/past/rawserialization/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/p2p/past/rawserialization/PastContentHandleDeserializer.hpp>

struct default_init_tag;

class rice::p2p::past::rawserialization::JavaPastContentHandleDeserializer
    : public virtual ::java::lang::Object
    , public virtual PastContentHandleDeserializer
{

public:
    typedef ::java::lang::Object super;
    ::rice::p2p::past::PastContentHandle* deserializePastContentHandle(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint, int16_t contentType) /* throws(IOException) */ override;

    // Generated
    JavaPastContentHandleDeserializer();
protected:
    JavaPastContentHandleDeserializer(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
