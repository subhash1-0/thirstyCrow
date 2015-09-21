// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/commonapi/CommonAPITransportLayerImpl.java

#pragma once

#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/commonapi/OptionsAdder.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::commonapi::CommonAPITransportLayerImpl_CommonAPITransportLayerImpl_1
    : public virtual ::java::lang::Object
    , public virtual OptionsAdder
{

public:
    typedef ::java::lang::Object super;
    ::java::util::Map* addOptions(::java::util::Map* options, ::rice::p2p::commonapi::rawserialization::RawMessage* m) override;

    // Generated
    CommonAPITransportLayerImpl_CommonAPITransportLayerImpl_1(CommonAPITransportLayerImpl *CommonAPITransportLayerImpl_this);
    static ::java::lang::Class *class_();
    CommonAPITransportLayerImpl *CommonAPITransportLayerImpl_this;

private:
    virtual ::java::lang::Class* getClass0();
    friend class CommonAPITransportLayerImpl;
    friend class CommonAPITransportLayerImpl_sendMessage_2;
};
