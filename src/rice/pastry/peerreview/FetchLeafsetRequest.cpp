// Generated from /pastry-2.1/src/rice/pastry/peerreview/FetchLeafsetRequest.java
#include <rice/pastry/peerreview/FetchLeafsetRequest.hpp>

#include <java/lang/IllegalArgumentException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/String.hpp>
#include <rice/pastry/Id.hpp>
#include <rice/pastry/NodeHandle.hpp>
#include <rice/pastry/peerreview/FetchLeafsetApp.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::pastry::peerreview::FetchLeafsetRequest::FetchLeafsetRequest(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::peerreview::FetchLeafsetRequest::FetchLeafsetRequest(::rice::pastry::NodeHandle* sender, ::rice::pastry::Id* subject) 
    : FetchLeafsetRequest(*static_cast< ::default_init_tag* >(0))
{
    ctor(sender,subject);
}

constexpr int16_t rice::pastry::peerreview::FetchLeafsetRequest::TYPE;

void rice::pastry::peerreview::FetchLeafsetRequest::ctor(::rice::pastry::NodeHandle* sender, ::rice::pastry::Id* subject)
{
    super::ctor(FetchLeafsetApp::APP_ID);
    if(sender == nullptr)
        throw new ::java::lang::IllegalArgumentException(u"sender is null!"_j);

    setSender(sender);
    this->subject = subject;
}

int16_t rice::pastry::peerreview::FetchLeafsetRequest::getType()
{
    return TYPE;
}

void rice::pastry::peerreview::FetchLeafsetRequest::serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */
{
    npc(subject)->serialize(buf);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::peerreview::FetchLeafsetRequest::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.peerreview.FetchLeafsetRequest", 42);
    return c;
}

java::lang::Class* rice::pastry::peerreview::FetchLeafsetRequest::getClass0()
{
    return class_();
}

