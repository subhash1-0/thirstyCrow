// Generated from /pastry-2.1/src/rice/tutorial/rawserialization2/MyMsg.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/tutorial/rawserialization2/fwd-pastry-2.1.hpp>
#include <rice/p2p/past/messaging/LookupMessage.hpp>

struct default_init_tag;

class rice::tutorial::rawserialization2::MyMsg
    : public ::rice::p2p::past::messaging::LookupMessage
{

public:
    typedef ::rice::p2p::past::messaging::LookupMessage super;

public: /* package */
    ::rice::p2p::commonapi::Id* from {  };
    ::rice::p2p::commonapi::Id* to {  };
protected:
    void ctor(::rice::p2p::commonapi::NodeHandle* from, ::rice::p2p::commonapi::Id* to);

public:
    ::java::lang::String* toString() override;
    int32_t getPriority() override;
    void serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */ override;

    // Generated
    MyMsg(::rice::p2p::commonapi::NodeHandle* from, ::rice::p2p::commonapi::Id* to);
protected:
    MyMsg(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    virtual void serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf, bool javaSerialize);

private:
    virtual ::java::lang::Class* getClass0();
};
