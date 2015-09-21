// Generated from /pastry-2.1/src/rice/pastry/peerreview/FetchLeafsetApp.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/pastry/messaging/fwd-pastry-2.1.hpp>
#include <rice/pastry/peerreview/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/p2p/commonapi/rawserialization/MessageDeserializer.hpp>
#include <rice/pastry/messaging/Message.hpp>

struct default_init_tag;

class rice::pastry::peerreview::FetchLeafsetApp_FetchLeafsetApp_1
    : public virtual ::java::lang::Object
    , public virtual ::rice::p2p::commonapi::rawserialization::MessageDeserializer
{

public:
    typedef ::java::lang::Object super;
    ::rice::pastry::messaging::Message* deserialize(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, int16_t type, int32_t priority, ::rice::p2p::commonapi::NodeHandle* sender) /* throws(IOException) */ override;

    // Generated
    FetchLeafsetApp_FetchLeafsetApp_1(FetchLeafsetApp *FetchLeafsetApp_this, ::rice::pastry::PastryNode* pn);
    static ::java::lang::Class *class_();
    FetchLeafsetApp *FetchLeafsetApp_this;
    ::rice::pastry::PastryNode* pn;

private:
    virtual ::java::lang::Class* getClass0();
    friend class FetchLeafsetApp;
    friend class FetchLeafsetApp_getNeighbors_2;
};
