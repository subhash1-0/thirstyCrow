// Generated from /pastry-2.1/src/rice/p2p/past/gc/rawserialization/JavaSerializedGCPastContentHandle.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/p2p/past/fwd-pastry-2.1.hpp>
#include <rice/p2p/past/gc/fwd-pastry-2.1.hpp>
#include <rice/p2p/past/gc/rawserialization/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/p2p/past/gc/rawserialization/RawGCPastContentHandle.hpp>

struct default_init_tag;

class rice::p2p::past::gc::rawserialization::JavaSerializedGCPastContentHandle
    : public virtual ::java::lang::Object
    , public virtual RawGCPastContentHandle
{

public:
    typedef ::java::lang::Object super;
    static constexpr int16_t TYPE { int16_t(0) };
    ::rice::p2p::past::gc::GCPastContentHandle* handle {  };
protected:
    void ctor(::rice::p2p::past::gc::GCPastContentHandle* handle);

public:
    void serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */ override;
    int16_t getType() override;
    ::java::lang::String* toString() override;
    ::rice::p2p::commonapi::Id* getId() override;
    ::rice::p2p::commonapi::NodeHandle* getNodeHandle() override;
    virtual ::rice::p2p::past::PastContentHandle* getPCH();
    int64_t getVersion() override;
    int64_t getExpiration() override;

    // Generated
    JavaSerializedGCPastContentHandle(::rice::p2p::past::gc::GCPastContentHandle* handle);
protected:
    JavaSerializedGCPastContentHandle(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
