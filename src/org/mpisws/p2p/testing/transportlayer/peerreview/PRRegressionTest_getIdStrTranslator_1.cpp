// Generated from /pastry-2.1/src/org/mpisws/p2p/testing/transportlayer/peerreview/PRRegressionTest.java
#include <org/mpisws/p2p/testing/transportlayer/peerreview/PRRegressionTest_getIdStrTranslator_1.hpp>

#include <java/lang/Integer.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/String.hpp>
#include <org/mpisws/p2p/testing/transportlayer/peerreview/PRRegressionTest_IdImpl.hpp>
#include <org/mpisws/p2p/testing/transportlayer/peerreview/PRRegressionTest.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_getIdStrTranslator_1::PRRegressionTest_getIdStrTranslator_1(PRRegressionTest *PRRegressionTest_this)
    : super(*static_cast< ::default_init_tag* >(0))
    , PRRegressionTest_this(PRRegressionTest_this)
{
    clinit();
    ctor();
}

org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_IdImpl* org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_getIdStrTranslator_1::readIdentifierFromString(::java::lang::String* s)
{
    return new PRRegressionTest_IdImpl(::java::lang::Integer::parseInt(s));
}

java::lang::String* org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_getIdStrTranslator_1::toString(PRRegressionTest_IdImpl* id)
{
    return ::java::lang::Integer::toString(npc(id)->id);
}

java::lang::String* org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_getIdStrTranslator_1::toString(::java::lang::Object* id)
{ 
    return toString(dynamic_cast< PRRegressionTest_IdImpl* >(id));
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_getIdStrTranslator_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::String* org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_getIdStrTranslator_1::toString()
{
    return super::toString();
}

java::lang::Class* org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_getIdStrTranslator_1::getClass0()
{
    return class_();
}

