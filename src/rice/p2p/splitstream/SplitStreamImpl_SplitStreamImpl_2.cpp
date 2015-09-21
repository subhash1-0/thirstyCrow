// Generated from /pastry-2.1/src/rice/p2p/splitstream/SplitStreamImpl.java
#include <rice/p2p/splitstream/SplitStreamImpl_SplitStreamImpl_2.hpp>

#include <java/lang/IllegalArgumentException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/p2p/splitstream/SplitStreamContent.hpp>
#include <rice/p2p/splitstream/SplitStreamImpl.hpp>
#include <rice/p2p/splitstream/SplitStreamSubscribeContent.hpp>

rice::p2p::splitstream::SplitStreamImpl_SplitStreamImpl_2::SplitStreamImpl_SplitStreamImpl_2(SplitStreamImpl *SplitStreamImpl_this)
    : super(*static_cast< ::default_init_tag* >(0))
    , SplitStreamImpl_this(SplitStreamImpl_this)
{
    clinit();
    ctor();
}

rice::p2p::scribe::ScribeContent* rice::p2p::splitstream::SplitStreamImpl_SplitStreamImpl_2::deserializeScribeContent(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint, int16_t contentType) /* throws(IOException) */
{
    switch (contentType) {
    case SplitStreamContent::TYPE:
        return new SplitStreamContent(buf);
    case SplitStreamSubscribeContent::TYPE:
        return new SplitStreamSubscribeContent(buf);
    }

    throw new ::java::lang::IllegalArgumentException(::java::lang::StringBuilder().append(u"Invalid type:"_j)->append(contentType)->toString());
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::splitstream::SplitStreamImpl_SplitStreamImpl_2::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::splitstream::SplitStreamImpl_SplitStreamImpl_2::getClass0()
{
    return class_();
}

