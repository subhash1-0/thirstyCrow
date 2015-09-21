// Generated from /pastry-2.1/src/rice/pastry/standard/StandardRouteSetProtocol.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/pastry/messaging/fwd-pastry-2.1.hpp>
#include <rice/pastry/standard/fwd-pastry-2.1.hpp>
#include <rice/pastry/messaging/PJavaSerializedDeserializer.hpp>

struct default_init_tag;

class rice::pastry::standard::StandardRouteSetProtocol_SRSPDeserializer
    : public ::rice::pastry::messaging::PJavaSerializedDeserializer
{

public:
    typedef ::rice::pastry::messaging::PJavaSerializedDeserializer super;
protected:
    void ctor(::rice::pastry::PastryNode* pn);

public:
    ::rice::pastry::messaging::Message* deserialize(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, int16_t type, int32_t priority, ::rice::pastry::NodeHandle* sender) /* throws(IOException) */ override;

    // Generated
    StandardRouteSetProtocol_SRSPDeserializer(::rice::pastry::PastryNode* pn);
protected:
    StandardRouteSetProtocol_SRSPDeserializer(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    ::rice::p2p::commonapi::Message* deserialize(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, int16_t type, int32_t priority, ::rice::p2p::commonapi::NodeHandle* sender);

private:
    virtual ::java::lang::Class* getClass0();
    friend class StandardRouteSetProtocol;
};
