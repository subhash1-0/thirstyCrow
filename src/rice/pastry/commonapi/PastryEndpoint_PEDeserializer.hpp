// Generated from /pastry-2.1/src/rice/pastry/commonapi/PastryEndpoint.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/pastry/commonapi/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/p2p/commonapi/rawserialization/MessageDeserializer.hpp>

struct default_init_tag;

class rice::pastry::commonapi::PastryEndpoint_PEDeserializer
    : public virtual ::java::lang::Object
    , public virtual ::rice::p2p::commonapi::rawserialization::MessageDeserializer
{

public:
    typedef ::java::lang::Object super;
    ::rice::p2p::commonapi::Message* deserialize(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, int16_t type, int32_t priority, ::rice::p2p::commonapi::NodeHandle* sender) /* throws(IOException) */ override;

    // Generated
    PastryEndpoint_PEDeserializer(PastryEndpoint *PastryEndpoint_this);
protected:
    PastryEndpoint_PEDeserializer(PastryEndpoint *PastryEndpoint_this, const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    PastryEndpoint *PastryEndpoint_this;

private:
    virtual ::java::lang::Class* getClass0();
    friend class PastryEndpoint;
    friend class PastryEndpoint_routeHelper_1;
    friend class PastryEndpoint_routeHelper_2;
    friend class PastryEndpoint_networkNeighbors_3;
};
