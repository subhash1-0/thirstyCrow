// Generated from /pastry-2.1/src/org/mpisws/p2p/testing/transportlayer/peerreview/PRRegressionTest.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/testing/transportlayer/peerreview/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/util/Serializer.hpp>
#include <org/mpisws/p2p/testing/transportlayer/peerreview/PRRegressionTest_HandleImpl.hpp>

struct default_init_tag;

class org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_HandleSerializer
    : public virtual ::java::lang::Object
    , public virtual ::org::mpisws::p2p::transport::util::Serializer
{

public:
    typedef ::java::lang::Object super;
    PRRegressionTest_HandleImpl* deserialize(::rice::p2p::commonapi::rawserialization::InputBuffer* buf) /* throws(IOException) */ override;
    virtual void serialize(PRRegressionTest_HandleImpl* i, ::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */;

    // Generated
    PRRegressionTest_HandleSerializer();
protected:
    PRRegressionTest_HandleSerializer(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    virtual void serialize(::java::lang::Object* i, ::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) override;

private:
    virtual ::java::lang::Class* getClass0();
    friend class PRRegressionTest;
    friend class PRRegressionTest_IdExtractor;
    friend class PRRegressionTest_IdSerializer;
    friend class PRRegressionTest_HandleImpl;
    friend class PRRegressionTest_IdImpl;
    friend class PRRegressionTest_BogusTransport;
    friend class PRRegressionTest_BogusTransport_receiveMessage_1;
    friend class PRRegressionTest_BogusApp;
    friend class PRRegressionTest_BogusApp_scheduleMessageToBeSent_1;
    friend class PRRegressionTest_BogusApp_sendMessage_2;
    friend class PRRegressionTest_Player;
    friend class PRRegressionTest_Player_Player_1;
    friend class PRRegressionTest_Player_getIdTransport_2;
    friend class PRRegressionTest_getIdStrTranslator_1;
    friend class PRRegressionTest_MyIdTL;
    friend class PRRegressionTest_MyIdTL_requestCertificate_1;
    friend class PRRegressionTest_PRRegressionTest_2;
    friend class PRRegressionTest_PRRegressionTest_3;
};
