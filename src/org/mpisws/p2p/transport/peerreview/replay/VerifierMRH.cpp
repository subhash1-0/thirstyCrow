// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/replay/VerifierMRH.java
#include <org/mpisws/p2p/transport/peerreview/replay/VerifierMRH.hpp>

#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/nio/ByteBuffer.hpp>
#include <org/mpisws/p2p/transport/MessageCallback.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::transport::peerreview::replay::VerifierMRH::VerifierMRH(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::transport::peerreview::replay::VerifierMRH::VerifierMRH(::java::lang::Object* i, ::java::nio::ByteBuffer* m, ::org::mpisws::p2p::transport::MessageCallback* callback, ::java::util::Map* options) 
    : VerifierMRH(*static_cast< ::default_init_tag* >(0))
{
    ctor(i,m,callback,options);
}

void org::mpisws::p2p::transport::peerreview::replay::VerifierMRH::ctor(::java::lang::Object* i, ::java::nio::ByteBuffer* m, ::org::mpisws::p2p::transport::MessageCallback* callback, ::java::util::Map* options)
{
    super::ctor(i, m, options);
    this->callback = callback;
}

void org::mpisws::p2p::transport::peerreview::replay::VerifierMRH::ack()
{
    if(callback != nullptr)
        npc(callback)->ack(this);

}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::peerreview::replay::VerifierMRH::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.peerreview.replay.VerifierMRH", 54);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::peerreview::replay::VerifierMRH::getClass0()
{
    return class_();
}

