// Generated from /pastry-2.1/src/rice/p2p/glacier/v2/messaging/GlacierTimeoutMessage.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/p2p/glacier/v2/messaging/fwd-pastry-2.1.hpp>
#include <rice/p2p/glacier/v2/messaging/GlacierMessage.hpp>

struct default_init_tag;

class rice::p2p::glacier::v2::messaging::GlacierTimeoutMessage
    : public GlacierMessage
{

public:
    typedef GlacierMessage super;
    static constexpr int16_t TYPE { int16_t(15) };
protected:
    void ctor(int32_t uid, ::rice::p2p::commonapi::NodeHandle* local);

public:
    ::java::lang::String* toString() override;
    int16_t getType() override;
    void serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */ override;

    // Generated
    GlacierTimeoutMessage(int32_t uid, ::rice::p2p::commonapi::NodeHandle* local);
protected:
    GlacierTimeoutMessage(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
