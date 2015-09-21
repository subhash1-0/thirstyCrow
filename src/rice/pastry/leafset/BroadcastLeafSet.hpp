// Generated from /pastry-2.1/src/rice/pastry/leafset/BroadcastLeafSet.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/pastry/leafset/fwd-pastry-2.1.hpp>
#include <rice/pastry/messaging/PRawMessage.hpp>

struct default_init_tag;

class rice::pastry::leafset::BroadcastLeafSet
    : public ::rice::pastry::messaging::PRawMessage
{

public:
    typedef ::rice::pastry::messaging::PRawMessage super;
    static constexpr int16_t TYPE { int16_t(2) };
    static constexpr int32_t Update { int32_t(0) };
    static constexpr int32_t JoinInitial { int32_t(1) };
    static constexpr int32_t JoinAdvertise { int32_t(2) };
    static constexpr int32_t Correction { int32_t(3) };

private:
    ::rice::pastry::NodeHandle* fromNode {  };
    LeafSet* theLeafSet {  };
    int32_t theType {  };
    int64_t requestTimeStamp {  };
protected:
    void ctor(::rice::pastry::NodeHandle* from, LeafSet* leafSet, int32_t type, int64_t requestTimeStamp);
    void ctor(::java::util::Date* stamp, ::rice::pastry::NodeHandle* from, LeafSet* leafSet, int32_t type, int64_t requestTimeStamp);

public:
    virtual ::rice::pastry::NodeHandle* from();
    virtual LeafSet* leafSet();
    virtual int32_t type();
    ::java::lang::String* toString() override;
    int16_t getType() override;
    void serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */ override;
protected:
    void ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::pastry::NodeHandleFactory* nhf) /* throws(IOException) */;

public:
    virtual int64_t getTimeStamp();

    // Generated
    BroadcastLeafSet(::rice::pastry::NodeHandle* from, LeafSet* leafSet, int32_t type, int64_t requestTimeStamp);
    BroadcastLeafSet(::java::util::Date* stamp, ::rice::pastry::NodeHandle* from, LeafSet* leafSet, int32_t type, int64_t requestTimeStamp);
    BroadcastLeafSet(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::pastry::NodeHandleFactory* nhf);
protected:
    BroadcastLeafSet(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
