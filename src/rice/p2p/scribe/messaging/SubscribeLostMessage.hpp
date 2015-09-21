// Generated from /pastry-2.1/src/rice/p2p/scribe/messaging/SubscribeLostMessage.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/scribe/fwd-pastry-2.1.hpp>
#include <rice/p2p/scribe/messaging/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/p2p/commonapi/Message.hpp>

struct default_init_tag;

class rice::p2p::scribe::messaging::SubscribeLostMessage
    : public virtual ::java::lang::Object
    , public virtual ::rice::p2p::commonapi::Message
{

public:
    typedef ::java::lang::Object super;

public: /* protected */
    ::java::util::Set* topics {  };
    int32_t id {  };

public: /* package */
    ::rice::p2p::commonapi::CancellableTask* task {  };
    ::rice::p2p::scribe::ScribeMultiClient* client {  };
protected:
    void ctor(::rice::p2p::commonapi::NodeHandle* source, ::java::util::Collection* topics, int32_t id, ::rice::p2p::scribe::ScribeMultiClient* client);

public:
    virtual ::rice::p2p::scribe::ScribeMultiClient* getClient();
    virtual ::java::util::Collection* getTopics();
    virtual int32_t getId();
    int32_t getPriority() override;
    virtual void putTask(::rice::p2p::commonapi::CancellableTask* task);
    virtual void cancel();
    virtual bool topicsAcked(::java::util::Collection* topic);

    // Generated
    SubscribeLostMessage(::rice::p2p::commonapi::NodeHandle* source, ::java::util::Collection* topics, int32_t id, ::rice::p2p::scribe::ScribeMultiClient* client);
protected:
    SubscribeLostMessage(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
