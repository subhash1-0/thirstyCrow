// Generated from /pastry-2.1/src/rice/tutorial/deterministicsimulator/MyMsg.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/tutorial/deterministicsimulator/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/p2p/commonapi/Message.hpp>

struct default_init_tag;

class rice::tutorial::deterministicsimulator::MyMsg
    : public virtual ::java::lang::Object
    , public virtual ::rice::p2p::commonapi::Message
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    ::rice::p2p::commonapi::Id* from {  };
    ::rice::p2p::commonapi::Id* to {  };
protected:
    void ctor(::rice::p2p::commonapi::Id* from, ::rice::p2p::commonapi::Id* to);

public:
    ::java::lang::String* toString() override;
    int32_t getPriority() override;

    // Generated
    MyMsg(::rice::p2p::commonapi::Id* from, ::rice::p2p::commonapi::Id* to);
protected:
    MyMsg(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
