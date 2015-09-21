// Generated from /pastry-2.1/src/rice/pastry/peerreview/FetchLeafsetApp.java
#include <rice/pastry/peerreview/FetchLeafsetApp_FetchLeafsetApp_1.hpp>

#include <java/io/IOException.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/p2p/commonapi/NodeHandle.hpp>
#include <rice/pastry/Id.hpp>
#include <rice/pastry/NodeHandle.hpp>
#include <rice/pastry/PastryNode.hpp>
#include <rice/pastry/peerreview/FetchLeafsetApp.hpp>
#include <rice/pastry/peerreview/FetchLeafsetRequest.hpp>
#include <rice/pastry/peerreview/FetchLeafsetResponse.hpp>

template<typename T, typename U>
static T java_cast(U* u)
{
    if(!u) return static_cast<T>(nullptr);
    auto t = dynamic_cast<T>(u);
    if(!t) throw new ::java::lang::ClassCastException();
    return t;
}

rice::pastry::peerreview::FetchLeafsetApp_FetchLeafsetApp_1::FetchLeafsetApp_FetchLeafsetApp_1(FetchLeafsetApp *FetchLeafsetApp_this, ::rice::pastry::PastryNode* pn)
    : super(*static_cast< ::default_init_tag* >(0))
    , FetchLeafsetApp_this(FetchLeafsetApp_this)
    , pn(pn)
{
    clinit();
    ctor();
}

rice::pastry::messaging::Message* rice::pastry::peerreview::FetchLeafsetApp_FetchLeafsetApp_1::deserialize(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, int16_t type, int32_t priority, ::rice::p2p::commonapi::NodeHandle* sender) /* throws(IOException) */
{
    switch (type) {
    case FetchLeafsetRequest::TYPE:
        if(sender == nullptr)
            throw new ::java::io::IOException(u"Sender is null for FetchLeafsetRequest"_j);

        return new FetchLeafsetRequest(java_cast< ::rice::pastry::NodeHandle* >(sender), ::rice::pastry::Id::build(buf));
    case FetchLeafsetResponse::TYPE:
        return new FetchLeafsetResponse(buf, pn, java_cast< ::rice::pastry::NodeHandle* >(sender));
    }

    throw new ::java::io::IOException(::java::lang::StringBuilder().append(u"Unknown type:"_j)->append(type)->toString());
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::peerreview::FetchLeafsetApp_FetchLeafsetApp_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::pastry::peerreview::FetchLeafsetApp_FetchLeafsetApp_1::getClass0()
{
    return class_();
}

