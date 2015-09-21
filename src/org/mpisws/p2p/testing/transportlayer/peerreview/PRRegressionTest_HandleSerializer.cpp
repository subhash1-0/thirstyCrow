// Generated from /pastry-2.1/src/org/mpisws/p2p/testing/transportlayer/peerreview/PRRegressionTest.java
#include <org/mpisws/p2p/testing/transportlayer/peerreview/PRRegressionTest_HandleSerializer.hpp>

#include <java/lang/NullPointerException.hpp>
#include <org/mpisws/p2p/testing/transportlayer/peerreview/PRRegressionTest_HandleImpl.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_HandleSerializer::PRRegressionTest_HandleSerializer(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_HandleSerializer::PRRegressionTest_HandleSerializer()
    : PRRegressionTest_HandleSerializer(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_HandleImpl* org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_HandleSerializer::deserialize(::rice::p2p::commonapi::rawserialization::InputBuffer* buf) /* throws(IOException) */
{
    return PRRegressionTest_HandleImpl::build(buf);
}

void org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_HandleSerializer::serialize(PRRegressionTest_HandleImpl* i, ::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */
{
    npc(i)->serialize(buf);
}

void org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_HandleSerializer::serialize(::java::lang::Object* i, ::rice::p2p::commonapi::rawserialization::OutputBuffer* buf)
{ 
    serialize(dynamic_cast< PRRegressionTest_HandleImpl* >(i), buf);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_HandleSerializer::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.testing.transportlayer.peerreview.PRRegressionTest.HandleSerializer", 82);
    return c;
}

java::lang::Class* org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_HandleSerializer::getClass0()
{
    return class_();
}

