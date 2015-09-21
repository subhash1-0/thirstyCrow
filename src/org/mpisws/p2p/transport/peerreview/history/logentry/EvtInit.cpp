// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/history/logentry/EvtInit.java
#include <org/mpisws/p2p/transport/peerreview/history/logentry/EvtInit.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/nio/ByteBuffer.hpp>
#include <org/mpisws/p2p/transport/util/Serializer.hpp>
#include <rice/p2p/commonapi/rawserialization/RawSerializable.hpp>

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

org::mpisws::p2p::transport::peerreview::history::logentry::EvtInit::EvtInit(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::transport::peerreview::history::logentry::EvtInit::EvtInit(::rice::p2p::commonapi::rawserialization::RawSerializable* handle) 
    : EvtInit(*static_cast< ::default_init_tag* >(0))
{
    ctor(handle);
}

org::mpisws::p2p::transport::peerreview::history::logentry::EvtInit::EvtInit(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::org::mpisws::p2p::transport::util::Serializer* handleSerializer)  /* throws(IOException) */
    : EvtInit(*static_cast< ::default_init_tag* >(0))
{
    ctor(buf,handleSerializer);
}

void org::mpisws::p2p::transport::peerreview::history::logentry::EvtInit::ctor(::rice::p2p::commonapi::rawserialization::RawSerializable* handle)
{
    super::ctor();
    this->handle = handle;
}

int16_t org::mpisws::p2p::transport::peerreview::history::logentry::EvtInit::getType()
{
    return EVT_INIT;
}

void org::mpisws::p2p::transport::peerreview::history::logentry::EvtInit::ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::org::mpisws::p2p::transport::util::Serializer* handleSerializer) /* throws(IOException) */
{
    super::ctor();
    handle = java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(handleSerializer)->deserialize(buf));
}

void org::mpisws::p2p::transport::peerreview::history::logentry::EvtInit::serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */
{
    npc(java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(handle))->serialize(buf);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::peerreview::history::logentry::EvtInit::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.peerreview.history.logentry.EvtInit", 60);
    return c;
}

java::nio::ByteBuffer* org::mpisws::p2p::transport::peerreview::history::logentry::EvtInit::serialize()
{
    return super::serialize();
}

java::lang::Class* org::mpisws::p2p::transport::peerreview::history::logentry::EvtInit::getClass0()
{
    return class_();
}

