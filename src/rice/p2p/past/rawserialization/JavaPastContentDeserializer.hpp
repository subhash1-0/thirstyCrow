// Generated from /pastry-2.1/src/rice/p2p/past/rawserialization/JavaPastContentDeserializer.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/p2p/past/fwd-pastry-2.1.hpp>
#include <rice/p2p/past/rawserialization/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/p2p/past/rawserialization/PastContentDeserializer.hpp>

struct default_init_tag;

class rice::p2p::past::rawserialization::JavaPastContentDeserializer
    : public virtual ::java::lang::Object
    , public virtual PastContentDeserializer
{

public:
    typedef ::java::lang::Object super;
protected:
    void ctor();

public:
    ::rice::p2p::past::PastContent* deserializePastContent(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint, int16_t contentType) /* throws(IOException) */ override;

    // Generated
    JavaPastContentDeserializer();
protected:
    JavaPastContentDeserializer(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
