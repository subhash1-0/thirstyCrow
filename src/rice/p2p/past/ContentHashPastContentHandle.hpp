// Generated from /pastry-2.1/src/rice/p2p/past/ContentHashPastContentHandle.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/p2p/past/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/p2p/past/rawserialization/RawPastContentHandle.hpp>

struct default_init_tag;

class rice::p2p::past::ContentHashPastContentHandle
    : public virtual ::java::lang::Object
    , public virtual ::rice::p2p::past::rawserialization::RawPastContentHandle
{

public:
    typedef ::java::lang::Object super;
    static constexpr int16_t TYPE { int16_t(-12) };

private:
    ::rice::p2p::commonapi::NodeHandle* storageNode {  };
    ::rice::p2p::commonapi::Id* myId {  };
protected:
    void ctor(::rice::p2p::commonapi::NodeHandle* nh, ::rice::p2p::commonapi::Id* id);

public:
    ::rice::p2p::commonapi::Id* getId() override;
    ::rice::p2p::commonapi::NodeHandle* getNodeHandle() override;
protected:
    void ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint) /* throws(IOException) */;

public:
    void serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */ override;
    int16_t getType() override;

    // Generated
    ContentHashPastContentHandle(::rice::p2p::commonapi::NodeHandle* nh, ::rice::p2p::commonapi::Id* id);
    ContentHashPastContentHandle(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint);
protected:
    ContentHashPastContentHandle(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
