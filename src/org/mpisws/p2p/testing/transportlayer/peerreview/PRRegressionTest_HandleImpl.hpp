// Generated from /pastry-2.1/src/org/mpisws/p2p/testing/transportlayer/peerreview/PRRegressionTest.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/testing/transportlayer/peerreview/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/p2p/commonapi/rawserialization/RawSerializable.hpp>

struct default_init_tag;

class org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_HandleImpl
    : public virtual ::java::lang::Object
    , public virtual ::rice::p2p::commonapi::rawserialization::RawSerializable
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    ::java::lang::String* name {  };
    PRRegressionTest_IdImpl* id {  };
protected:
    void ctor(::java::lang::String* s, PRRegressionTest_IdImpl* id);

public:
    void serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */ override;
    static PRRegressionTest_HandleImpl* build(::rice::p2p::commonapi::rawserialization::InputBuffer* buf) /* throws(IOException) */;
    ::java::lang::String* toString() override;
    int32_t hashCode() override;
    bool equals(::java::lang::Object* o) override;

    // Generated
    PRRegressionTest_HandleImpl(::java::lang::String* s, PRRegressionTest_IdImpl* id);
protected:
    PRRegressionTest_HandleImpl(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
    friend class PRRegressionTest;
    friend class PRRegressionTest_IdExtractor;
    friend class PRRegressionTest_HandleSerializer;
    friend class PRRegressionTest_IdSerializer;
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
