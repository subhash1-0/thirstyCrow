// Generated from /pastry-2.1/src/org/mpisws/p2p/testing/transportlayer/peerreview/PRRegressionTest.java
#include <org/mpisws/p2p/testing/transportlayer/peerreview/PRRegressionTest_BogusTransport.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/RuntimeException.hpp>
#include <java/lang/String.hpp>
#include <java/nio/ByteBuffer.hpp>
#include <java/util/HashMap.hpp>
#include <java/util/Map.hpp>
#include <org/mpisws/p2p/testing/transportlayer/peerreview/PRRegressionTest_BogusTransport_receiveMessage_1.hpp>
#include <org/mpisws/p2p/testing/transportlayer/peerreview/PRRegressionTest_HandleImpl.hpp>
#include <org/mpisws/p2p/transport/MessageCallback.hpp>
#include <org/mpisws/p2p/transport/SocketCallback.hpp>
#include <org/mpisws/p2p/transport/TransportLayerCallback.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/selector/SelectorManager.hpp>

template<typename T, typename U>
static T java_cast(U* u)
{
    if(!u) return static_cast<T>(nullptr);
    auto t = dynamic_cast<T>(u);
    if(!t) throw new ::java::lang::ClassCastException();
    return t;
}

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_BogusTransport::PRRegressionTest_BogusTransport(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_BogusTransport::PRRegressionTest_BogusTransport(PRRegressionTest_HandleImpl* handle, ::java::security::cert::X509Certificate* cert, ::rice::environment::Environment* env) 
    : PRRegressionTest_BogusTransport(*static_cast< ::default_init_tag* >(0))
{
    ctor(handle,cert,env);
}

java::util::Map*& org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_BogusTransport::peerTable()
{
    clinit();
    return peerTable_;
}
java::util::Map* org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_BogusTransport::peerTable_;

void org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_BogusTransport::ctor(PRRegressionTest_HandleImpl* handle, ::java::security::cert::X509Certificate* cert, ::rice::environment::Environment* env)
{
    super::ctor();
    npc(peerTable_)->put(handle, this);
    this->localIdentifier = handle;
    this->env = env;
}

void org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_BogusTransport::acceptMessages(bool b)
{
    throw new ::java::lang::RuntimeException(u"implement"_j);
}

void org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_BogusTransport::acceptSockets(bool b)
{
    throw new ::java::lang::RuntimeException(u"implement"_j);
}

org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_HandleImpl* org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_BogusTransport::getLocalIdentifier()
{
    return localIdentifier;
}

org::mpisws::p2p::transport::SocketRequestHandle* org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_BogusTransport::openSocket(PRRegressionTest_HandleImpl* i, ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe, ::java::util::Map* options)
{
    throw new ::java::lang::RuntimeException(u"implement"_j);
}

org::mpisws::p2p::transport::SocketRequestHandle* org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_BogusTransport::openSocket(::java::lang::Object* i, ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe, ::java::util::Map* options)
{ 
    return openSocket(dynamic_cast< PRRegressionTest_HandleImpl* >(i), dynamic_cast< ::org::mpisws::p2p::transport::SocketCallback* >(deliverSocketToMe), options);
}

org::mpisws::p2p::transport::MessageRequestHandle* org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_BogusTransport::sendMessage(PRRegressionTest_HandleImpl* i, ::java::nio::ByteBuffer* m, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options)
{
    npc(java_cast< PRRegressionTest_BogusTransport* >(npc(peerTable_)->get(i)))->receiveMessage(localIdentifier, m);
    return nullptr;
}

org::mpisws::p2p::transport::MessageRequestHandle* org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_BogusTransport::sendMessage(::java::lang::Object* i, ::java::lang::Object* m, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options)
{ 
    return sendMessage(dynamic_cast< PRRegressionTest_HandleImpl* >(i), dynamic_cast< ::java::nio::ByteBuffer* >(m), dynamic_cast< ::org::mpisws::p2p::transport::MessageCallback* >(deliverAckToMe), options);
}

void org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_BogusTransport::receiveMessage(PRRegressionTest_HandleImpl* i, ::java::nio::ByteBuffer* m)
{
    npc(npc(env)->getSelectorManager())->invoke(new PRRegressionTest_BogusTransport_receiveMessage_1(this, i, m));
}

void org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_BogusTransport::setCallback(::org::mpisws::p2p::transport::TransportLayerCallback* callback)
{
    this->callback = callback;
}

void org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_BogusTransport::setErrorHandler(::org::mpisws::p2p::transport::ErrorHandler* handler)
{
    throw new ::java::lang::RuntimeException(u"implement"_j);
}

void org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_BogusTransport::destroy()
{
    throw new ::java::lang::RuntimeException(u"implement"_j);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_BogusTransport::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.testing.transportlayer.peerreview.PRRegressionTest.BogusTransport", 80);
    return c;
}

void org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_BogusTransport::clinit()
{
    super::clinit();
    static bool in_cl_init = false;
struct clinit_ {
    clinit_() {
        in_cl_init = true;
        peerTable_ = new ::java::util::HashMap();
    }
};

    if(!in_cl_init) {
        static clinit_ clinit_instance;
    }
}

java::lang::Class* org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_BogusTransport::getClass0()
{
    return class_();
}

