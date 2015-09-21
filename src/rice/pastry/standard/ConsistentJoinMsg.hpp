// Generated from /pastry-2.1/src/rice/pastry/standard/ConsistentJoinMsg.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/pastry/leafset/fwd-pastry-2.1.hpp>
#include <rice/pastry/standard/fwd-pastry-2.1.hpp>
#include <rice/pastry/messaging/PRawMessage.hpp>

struct default_init_tag;

class rice::pastry::standard::ConsistentJoinMsg
    : public ::rice::pastry::messaging::PRawMessage
{

public:
    typedef ::rice::pastry::messaging::PRawMessage super;

private:
    static constexpr int64_t serialVersionUID { int64_t(-8942404626084999673LL) };

public:
    static constexpr int16_t TYPE { int16_t(2) };

public: /* package */
    ::rice::pastry::leafset::LeafSet* ls {  };
    bool request {  };
    ::java::util::HashSet* failed {  };
protected:
    void ctor(::rice::pastry::leafset::LeafSet* ls, ::java::util::HashSet* failed, bool request);

public:
    ::java::lang::String* toString() override;
    int16_t getType() override;
    void serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */ override;
protected:
    void ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::pastry::NodeHandleFactory* nhf, ::rice::pastry::NodeHandle* sender) /* throws(IOException) */;

    // Generated

public:
    ConsistentJoinMsg(::rice::pastry::leafset::LeafSet* ls, ::java::util::HashSet* failed, bool request);
    ConsistentJoinMsg(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::pastry::NodeHandleFactory* nhf, ::rice::pastry::NodeHandle* sender);
protected:
    ConsistentJoinMsg(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
