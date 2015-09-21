// Generated from /pastry-2.1/src/rice/pastry/peerreview/FetchLeafsetResponse.java
#include <rice/pastry/peerreview/FetchLeafsetResponse.hpp>

#include <java/lang/NullPointerException.hpp>
#include <rice/pastry/Id.hpp>
#include <rice/pastry/leafset/LeafSet.hpp>
#include <rice/pastry/peerreview/FetchLeafsetApp.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::pastry::peerreview::FetchLeafsetResponse::FetchLeafsetResponse(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::peerreview::FetchLeafsetResponse::FetchLeafsetResponse(::rice::pastry::Id* subject, ::rice::pastry::leafset::LeafSet* leafSet) 
    : FetchLeafsetResponse(*static_cast< ::default_init_tag* >(0))
{
    ctor(subject,leafSet);
}

rice::pastry::peerreview::FetchLeafsetResponse::FetchLeafsetResponse(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::pastry::NodeHandleFactory* nhf, ::rice::pastry::NodeHandle* sender)  /* throws(IOException) */
    : FetchLeafsetResponse(*static_cast< ::default_init_tag* >(0))
{
    ctor(buf,nhf,sender);
}

constexpr int16_t rice::pastry::peerreview::FetchLeafsetResponse::TYPE;

void rice::pastry::peerreview::FetchLeafsetResponse::ctor(::rice::pastry::Id* subject, ::rice::pastry::leafset::LeafSet* leafSet)
{
    super::ctor(FetchLeafsetApp::APP_ID);
    this->subject = subject;
    this->leafSet = leafSet;
}

int16_t rice::pastry::peerreview::FetchLeafsetResponse::getType()
{
    return TYPE;
}

void rice::pastry::peerreview::FetchLeafsetResponse::serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */
{
    npc(subject)->serialize(buf);
    npc(leafSet)->serialize(buf);
}

void rice::pastry::peerreview::FetchLeafsetResponse::ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::pastry::NodeHandleFactory* nhf, ::rice::pastry::NodeHandle* sender) /* throws(IOException) */
{
    super::ctor(FetchLeafsetApp::APP_ID);
    subject = ::rice::pastry::Id::build(buf);
    leafSet = ::rice::pastry::leafset::LeafSet::build(buf, nhf);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::peerreview::FetchLeafsetResponse::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.peerreview.FetchLeafsetResponse", 43);
    return c;
}

java::lang::Class* rice::pastry::peerreview::FetchLeafsetResponse::getClass0()
{
    return class_();
}

