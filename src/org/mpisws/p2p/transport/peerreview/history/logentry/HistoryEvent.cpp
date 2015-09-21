// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/history/logentry/HistoryEvent.java
#include <org/mpisws/p2p/transport/peerreview/history/logentry/HistoryEvent.hpp>

#include <java/lang/NullPointerException.hpp>
#include <java/nio/ByteBuffer.hpp>
#include <rice/p2p/util/rawserialization/SimpleOutputBuffer.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::transport::peerreview::history::logentry::HistoryEvent::HistoryEvent(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::transport::peerreview::history::logentry::HistoryEvent::HistoryEvent()
    : HistoryEvent(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

java::nio::ByteBuffer* org::mpisws::p2p::transport::peerreview::history::logentry::HistoryEvent::serialize() /* throws(IOException) */
{
    auto sob = new ::rice::p2p::util::rawserialization::SimpleOutputBuffer();
    serialize(sob);
    return npc(sob)->getByteBuffer();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::peerreview::history::logentry::HistoryEvent::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.peerreview.history.logentry.HistoryEvent", 65);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::peerreview::history::logentry::HistoryEvent::getClass0()
{
    return class_();
}

