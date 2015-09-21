// Generated from /pastry-2.1/src/org/mpisws/p2p/testing/transportlayer/peerreview/PRRegressionTest.java
#include <org/mpisws/p2p/testing/transportlayer/peerreview/PRRegressionTest_IdImpl.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/p2p/commonapi/rawserialization/InputBuffer.hpp>
#include <rice/p2p/commonapi/rawserialization/OutputBuffer.hpp>

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

org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_IdImpl::PRRegressionTest_IdImpl(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_IdImpl::PRRegressionTest_IdImpl(int32_t id) 
    : PRRegressionTest_IdImpl(*static_cast< ::default_init_tag* >(0))
{
    ctor(id);
}

void org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_IdImpl::ctor(int32_t id)
{
    super::ctor();
    this->id = id;
}

void org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_IdImpl::serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */
{
    npc(buf)->writeInt(id);
}

org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_IdImpl* org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_IdImpl::build(::rice::p2p::commonapi::rawserialization::InputBuffer* buf) /* throws(IOException) */
{
    clinit();
    return new PRRegressionTest_IdImpl(npc(buf)->readInt());
}

java::lang::String* org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_IdImpl::toString()
{
    return ::java::lang::StringBuilder().append(u"Id<"_j)->append(id)
        ->append(u">"_j)->toString();
}

int32_t org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_IdImpl::hashCode()
{
    return id;
}

bool org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_IdImpl::equals(::java::lang::Object* o)
{
    auto that = java_cast< PRRegressionTest_IdImpl* >(o);
    return (this->id == npc(that)->id);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_IdImpl::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.testing.transportlayer.peerreview.PRRegressionTest.IdImpl", 72);
    return c;
}

java::lang::Class* org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_IdImpl::getClass0()
{
    return class_();
}

