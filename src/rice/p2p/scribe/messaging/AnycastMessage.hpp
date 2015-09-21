// Generated from /pastry-2.1/src/rice/p2p/scribe/messaging/AnycastMessage.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/p2p/scribe/fwd-pastry-2.1.hpp>
#include <rice/p2p/scribe/messaging/fwd-pastry-2.1.hpp>
#include <rice/p2p/scribe/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/p2p/scribe/messaging/ScribeMessage.hpp>

struct default_init_tag;

class rice::p2p::scribe::messaging::AnycastMessage
    : public ScribeMessage
{

public:
    typedef ScribeMessage super;
    static constexpr int16_t TYPE { int16_t(1) };

public: /* protected */
    ::rice::p2p::scribe::rawserialization::RawScribeContent* content {  };
    ::java::util::ArrayList* visited {  };
    ::java::util::LinkedList* toVisit {  };
    ::rice::p2p::commonapi::NodeHandle* initialRequestor {  };
protected:
    void ctor(::rice::p2p::commonapi::NodeHandle* source, ::rice::p2p::scribe::Topic* topic, ::rice::p2p::scribe::ScribeContent* content);
    void ctor(::rice::p2p::commonapi::NodeHandle* source, ::rice::p2p::scribe::Topic* topic, ::rice::p2p::scribe::rawserialization::RawScribeContent* content);

public:
    virtual ::rice::p2p::scribe::ScribeContent* getContent();
    virtual ::rice::p2p::scribe::rawserialization::RawScribeContent* getRawContent();
    virtual void setContent(::rice::p2p::scribe::rawserialization::RawScribeContent* content);
    virtual void setContent(::rice::p2p::scribe::ScribeContent* content);
    virtual ::rice::p2p::commonapi::NodeHandle* peekNext();
    virtual ::rice::p2p::commonapi::NodeHandle* getNext();
    virtual ::rice::p2p::commonapi::NodeHandle* peekLastToVisit();
    virtual void addVisited(::rice::p2p::commonapi::NodeHandle* handle);
    virtual void addFirst(::rice::p2p::commonapi::NodeHandle* handle);
    virtual void addLast(::rice::p2p::commonapi::NodeHandle* handle);
    ::java::lang::String* toString() override;
    virtual ::rice::p2p::commonapi::NodeHandle* getInitialRequestor();
    virtual ::rice::p2p::commonapi::NodeHandle* getLastVisited();
    virtual void remove(::rice::p2p::commonapi::NodeHandle* handle);
    virtual int32_t getVisitedSize();
    virtual int32_t getToVisitSize();
    virtual bool hasVisited(::rice::p2p::commonapi::NodeHandle* handle);
    int16_t getType() override;
    void serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */ override;

public: /* protected */
    virtual void serializeHelper(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */;

public:
    static AnycastMessage* build(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint, ::rice::p2p::scribe::rawserialization::ScribeContentDeserializer* scd) /* throws(IOException) */;
protected:
    void ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint, ::rice::p2p::scribe::rawserialization::ScribeContentDeserializer* cd) /* throws(IOException) */;

    // Generated

public:
    AnycastMessage(::rice::p2p::commonapi::NodeHandle* source, ::rice::p2p::scribe::Topic* topic, ::rice::p2p::scribe::ScribeContent* content);
    AnycastMessage(::rice::p2p::commonapi::NodeHandle* source, ::rice::p2p::scribe::Topic* topic, ::rice::p2p::scribe::rawserialization::RawScribeContent* content);

public: /* protected */
    AnycastMessage(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint, ::rice::p2p::scribe::rawserialization::ScribeContentDeserializer* cd);
protected:
    AnycastMessage(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
