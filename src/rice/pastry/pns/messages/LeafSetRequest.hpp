// Generated from /pastry-2.1/src/rice/pastry/pns/messages/LeafSetRequest.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/pastry/pns/messages/fwd-pastry-2.1.hpp>
#include <rice/pastry/messaging/PRawMessage.hpp>

struct default_init_tag;

class rice::pastry::pns::messages::LeafSetRequest
    : public ::rice::pastry::messaging::PRawMessage
{

public:
    typedef ::rice::pastry::messaging::PRawMessage super;
    static constexpr int16_t TYPE { int16_t(1) };
protected:
    void ctor(::rice::pastry::NodeHandle* nodeHandle, int32_t dest);

public:
    static LeafSetRequest* build(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::pastry::NodeHandle* sender, int32_t dest) /* throws(IOException) */;
    int16_t getType() override;
    void serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */ override;

    // Generated
    LeafSetRequest(::rice::pastry::NodeHandle* nodeHandle, int32_t dest);
protected:
    LeafSetRequest(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
