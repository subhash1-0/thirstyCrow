// Generated from /pastry-2.1/src/rice/tutorial/rawserialization/MyMsg.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/tutorial/rawserialization/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/p2p/commonapi/rawserialization/RawMessage.hpp>

struct default_init_tag;

class rice::tutorial::rawserialization::MyMsg
    : public virtual ::java::lang::Object
    , public virtual ::rice::p2p::commonapi::rawserialization::RawMessage
{

public:
    typedef ::java::lang::Object super;

public: /* protected */
    static constexpr int16_t TYPE { int16_t(1) };

public: /* package */
    ::rice::p2p::commonapi::Id* from {  };
    ::rice::p2p::commonapi::Id* to {  };
protected:
    void ctor(::rice::p2p::commonapi::Id* from, ::rice::p2p::commonapi::Id* to);

public:
    ::java::lang::String* toString() override;
    int32_t getPriority() override;
    int16_t getType() override;
protected:
    void ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint) /* throws(IOException) */;

public:
    void serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */ override;

    // Generated
    MyMsg(::rice::p2p::commonapi::Id* from, ::rice::p2p::commonapi::Id* to);
    MyMsg(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint);
protected:
    MyMsg(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
