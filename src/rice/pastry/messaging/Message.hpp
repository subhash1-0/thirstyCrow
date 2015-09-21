// Generated from /pastry-2.1/src/rice/pastry/messaging/Message.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/pastry/messaging/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <java/io/Serializable.hpp>
#include <rice/p2p/commonapi/Message.hpp>

struct default_init_tag;

class rice::pastry::messaging::Message
    : public virtual ::java::lang::Object
    , public virtual ::java::io::Serializable
    , public virtual ::rice::p2p::commonapi::Message
{

public:
    typedef ::java::lang::Object super;

private:
    static constexpr int64_t serialVersionUID { int64_t(8921944904321235696LL) };

public:
    static constexpr int32_t DEFAULT_PRIORITY_LEVEL { int32_t(0) };

private:
    int32_t destination {  };
    ::rice::pastry::NodeHandle* sender {  };
    bool priority {  };
    int32_t priorityLevel {  };
    ::java::util::Date* theStamp {  };
protected:
    void ctor(int32_t dest);
    void ctor(int32_t dest, ::java::util::Date* timestamp);

public:
    virtual int32_t getDestination();
    virtual ::java::util::Date* getDate();
    virtual ::rice::pastry::Id* getSenderId();
    virtual ::rice::pastry::NodeHandle* getSender();
    virtual void setSender(::rice::pastry::NodeHandle* nh);
    int32_t getPriority() override;

public: /* protected */
    virtual void setPriority(int32_t prio);

public:
    virtual bool stamp(::java::util::Date* time);

    // Generated
    Message(int32_t dest);
    Message(int32_t dest, ::java::util::Date* timestamp);
protected:
    Message(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    void init();
    virtual ::java::lang::Class* getClass0();
};
