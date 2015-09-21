// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/challenge/PacketInfo.java
#include <org/mpisws/p2p/transport/peerreview/challenge/PacketInfo.hpp>

#include <java/lang/Object.hpp>
#include <java/util/Map.hpp>
#include <org/mpisws/p2p/transport/peerreview/infostore/Evidence.hpp>

org::mpisws::p2p::transport::peerreview::challenge::PacketInfo::PacketInfo(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::transport::peerreview::challenge::PacketInfo::PacketInfo(::java::lang::Object* source, ::org::mpisws::p2p::transport::peerreview::infostore::Evidence* message, bool isAccusation, ::java::lang::Object* subject, ::java::lang::Object* originator, int64_t evidenceSeq, ::java::util::Map* options) 
    : PacketInfo(*static_cast< ::default_init_tag* >(0))
{
    ctor(source,message,isAccusation,subject,originator,evidenceSeq,options);
}

void org::mpisws::p2p::transport::peerreview::challenge::PacketInfo::ctor(::java::lang::Object* source, ::org::mpisws::p2p::transport::peerreview::infostore::Evidence* message, bool isAccusation, ::java::lang::Object* subject, ::java::lang::Object* originator, int64_t evidenceSeq, ::java::util::Map* options)
{
    super::ctor();
    this->source = source;
    this->message = message;
    this->isAccusation = isAccusation;
    this->subject = subject;
    this->originator = originator;
    this->evidenceSeq = evidenceSeq;
    this->options = options;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::peerreview::challenge::PacketInfo::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.peerreview.challenge.PacketInfo", 56);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::peerreview::challenge::PacketInfo::getClass0()
{
    return class_();
}

