// Generated from /pastry-2.1/src/rice/p2p/past/rawserialization/JavaSerializedPastContentHandle.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/p2p/past/fwd-pastry-2.1.hpp>
#include <rice/p2p/past/rawserialization/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/p2p/past/rawserialization/RawPastContentHandle.hpp>

struct default_init_tag;

class rice::p2p::past::rawserialization::JavaSerializedPastContentHandle
    : public virtual ::java::lang::Object
    , public virtual RawPastContentHandle
{

public:
    typedef ::java::lang::Object super;
    static constexpr int16_t TYPE { int16_t(0) };
    ::rice::p2p::past::PastContentHandle* handle {  };
protected:
    void ctor(::rice::p2p::past::PastContentHandle* handle);

public:
    void serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */ override;
    int16_t getType() override;
    ::java::lang::String* toString() override;
    ::rice::p2p::commonapi::Id* getId() override;
    ::rice::p2p::commonapi::NodeHandle* getNodeHandle() override;
    virtual ::rice::p2p::past::PastContentHandle* getPCH();

    // Generated
    JavaSerializedPastContentHandle(::rice::p2p::past::PastContentHandle* handle);
protected:
    JavaSerializedPastContentHandle(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
