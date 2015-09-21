// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/message/AuthPushMessage.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/commitment/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/message/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/util/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/peerreview/message/PeerReviewMessage.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::peerreview::message::AuthPushMessage
    : public virtual ::java::lang::Object
    , public virtual PeerReviewMessage
{

public:
    typedef ::java::lang::Object super;
    ::java::util::Map* authenticators {  };
protected:
    void ctor(::java::util::Map* authenticators);

public:
    int16_t getType() override;
    static /* <I extends RawSerializable> */AuthPushMessage* build(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::org::mpisws::p2p::transport::util::Serializer* idSerializer, ::org::mpisws::p2p::transport::peerreview::commitment::AuthenticatorSerializer* authSerializer) /* throws(IOException) */;
    void serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */ override;

    // Generated
    AuthPushMessage(::java::util::Map* authenticators);
protected:
    AuthPushMessage(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
