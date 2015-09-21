// Generated from /pastry-2.1/src/rice/pastry/pns/messages/LeafSetResponse.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/pastry/leafset/fwd-pastry-2.1.hpp>
#include <rice/pastry/pns/messages/fwd-pastry-2.1.hpp>
#include <rice/pastry/messaging/PRawMessage.hpp>

struct default_init_tag;

class rice::pastry::pns::messages::LeafSetResponse
    : public ::rice::pastry::messaging::PRawMessage
{

public:
    typedef ::rice::pastry::messaging::PRawMessage super;
    static constexpr int16_t TYPE { int16_t(2) };
    ::rice::pastry::leafset::LeafSet* leafset {  };
protected:
    void ctor(::rice::pastry::leafset::LeafSet* leafset, int32_t dest);

public:
    int16_t getType() override;
    void serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */ override;
    static ::rice::p2p::commonapi::Message* build(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::pastry::NodeHandleFactory* nhf, int32_t dest) /* throws(IOException) */;

    // Generated
    LeafSetResponse(::rice::pastry::leafset::LeafSet* leafset, int32_t dest);
protected:
    LeafSetResponse(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
