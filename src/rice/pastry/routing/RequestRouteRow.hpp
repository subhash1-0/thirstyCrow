// Generated from /pastry-2.1/src/rice/pastry/routing/RequestRouteRow.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/pastry/routing/fwd-pastry-2.1.hpp>
#include <rice/pastry/messaging/PRawMessage.hpp>
#include <java/io/Serializable.hpp>

struct default_init_tag;

class rice::pastry::routing::RequestRouteRow
    : public ::rice::pastry::messaging::PRawMessage
    , public virtual ::java::io::Serializable
{

public:
    typedef ::rice::pastry::messaging::PRawMessage super;
    static constexpr int16_t TYPE { int16_t(1) };

private:
    int16_t row {  };
protected:
    void ctor(::rice::pastry::NodeHandle* nh, int16_t r);
    void ctor(::java::util::Date* stamp, ::rice::pastry::NodeHandle* nh, int16_t r);

public:
    virtual ::rice::pastry::NodeHandle* returnHandle();
    virtual int16_t getRow();
    ::java::lang::String* toString() override;
    int16_t getType() override;
    void serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */ override;
protected:
    void ctor(::rice::pastry::NodeHandle* sender, ::rice::p2p::commonapi::rawserialization::InputBuffer* buf) /* throws(IOException) */;

    // Generated

public:
    RequestRouteRow(::rice::pastry::NodeHandle* nh, int16_t r);
    RequestRouteRow(::java::util::Date* stamp, ::rice::pastry::NodeHandle* nh, int16_t r);
    RequestRouteRow(::rice::pastry::NodeHandle* sender, ::rice::p2p::commonapi::rawserialization::InputBuffer* buf);
protected:
    RequestRouteRow(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
