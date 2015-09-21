// Generated from /pastry-2.1/src/rice/pastry/peerreview/FetchLeafsetRequest.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/pastry/peerreview/fwd-pastry-2.1.hpp>
#include <rice/pastry/messaging/PRawMessage.hpp>

struct default_init_tag;

class rice::pastry::peerreview::FetchLeafsetRequest
    : public ::rice::pastry::messaging::PRawMessage
{

public:
    typedef ::rice::pastry::messaging::PRawMessage super;
    static constexpr int16_t TYPE { int16_t(1) };
    ::rice::pastry::Id* subject {  };
protected:
    void ctor(::rice::pastry::NodeHandle* sender, ::rice::pastry::Id* subject);

public:
    int16_t getType() override;
    void serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */ override;

    // Generated
    FetchLeafsetRequest(::rice::pastry::NodeHandle* sender, ::rice::pastry::Id* subject);
protected:
    FetchLeafsetRequest(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
