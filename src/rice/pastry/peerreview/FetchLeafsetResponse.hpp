// Generated from /pastry-2.1/src/rice/pastry/peerreview/FetchLeafsetResponse.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/pastry/leafset/fwd-pastry-2.1.hpp>
#include <rice/pastry/peerreview/fwd-pastry-2.1.hpp>
#include <rice/pastry/messaging/PRawMessage.hpp>

struct default_init_tag;

class rice::pastry::peerreview::FetchLeafsetResponse
    : public ::rice::pastry::messaging::PRawMessage
{

public:
    typedef ::rice::pastry::messaging::PRawMessage super;
    static constexpr int16_t TYPE { int16_t(2) };
    ::rice::pastry::Id* subject {  };
    ::rice::pastry::leafset::LeafSet* leafSet {  };
protected:
    void ctor(::rice::pastry::Id* subject, ::rice::pastry::leafset::LeafSet* leafSet);

public:
    int16_t getType() override;
    void serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */ override;
protected:
    void ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::pastry::NodeHandleFactory* nhf, ::rice::pastry::NodeHandle* sender) /* throws(IOException) */;

    // Generated

public:
    FetchLeafsetResponse(::rice::pastry::Id* subject, ::rice::pastry::leafset::LeafSet* leafSet);
    FetchLeafsetResponse(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::pastry::NodeHandleFactory* nhf, ::rice::pastry::NodeHandle* sender);
protected:
    FetchLeafsetResponse(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
