// Generated from /pastry-2.1/src/org/mpisws/p2p/testing/transportlayer/peerreview/PRRegressionTest.java
#include <org/mpisws/p2p/testing/transportlayer/peerreview/PRRegressionTest_HandleImpl.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <org/mpisws/p2p/testing/transportlayer/peerreview/PRRegressionTest_IdImpl.hpp>
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

org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_HandleImpl::PRRegressionTest_HandleImpl(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_HandleImpl::PRRegressionTest_HandleImpl(::java::lang::String* s, PRRegressionTest_IdImpl* id) 
    : PRRegressionTest_HandleImpl(*static_cast< ::default_init_tag* >(0))
{
    ctor(s,id);
}

void org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_HandleImpl::ctor(::java::lang::String* s, PRRegressionTest_IdImpl* id)
{
    super::ctor();
    this->name = s;
    this->id = id;
}

void org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_HandleImpl::serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */
{
    npc(buf)->writeUTF(name);
    npc(id)->serialize(buf);
}

org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_HandleImpl* org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_HandleImpl::build(::rice::p2p::commonapi::rawserialization::InputBuffer* buf) /* throws(IOException) */
{
    clinit();
    return new PRRegressionTest_HandleImpl(npc(buf)->readUTF(), PRRegressionTest_IdImpl::build(buf));
}

java::lang::String* org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_HandleImpl::toString()
{
    return ::java::lang::StringBuilder().append(u"HandleImpl<"_j)->append(name)
        ->append(u">"_j)->toString();
}

int32_t org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_HandleImpl::hashCode()
{
    return npc(id)->hashCode() ^ npc(name)->hashCode();
}

bool org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_HandleImpl::equals(::java::lang::Object* o)
{
    auto that = java_cast< PRRegressionTest_HandleImpl* >(o);
    if(!npc(id)->equals(static_cast< ::java::lang::Object* >(npc(that)->id)))
        return false;

    return npc(name)->equals(static_cast< ::java::lang::Object* >(npc(that)->name));
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_HandleImpl::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.testing.transportlayer.peerreview.PRRegressionTest.HandleImpl", 76);
    return c;
}

java::lang::Class* org::mpisws::p2p::testing::transportlayer::peerreview::PRRegressionTest_HandleImpl::getClass0()
{
    return class_();
}

