// Generated from /pastry-2.1/src/rice/p2p/multiring/MultiringNode.java
#include <rice/p2p/multiring/MultiringNode_MultiringNode_1.hpp>

#include <java/lang/IllegalArgumentException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/p2p/multiring/MultiringNode.hpp>
#include <rice/p2p/multiring/messaging/RingMessage.hpp>

rice::p2p::multiring::MultiringNode_MultiringNode_1::MultiringNode_MultiringNode_1(MultiringNode *MultiringNode_this)
    : super(*static_cast< ::default_init_tag* >(0))
    , MultiringNode_this(MultiringNode_this)
{
    clinit();
    ctor();
}

rice::p2p::scribe::ScribeContent* rice::p2p::multiring::MultiringNode_MultiringNode_1::deserializeScribeContent(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint, int16_t type) /* throws(IOException) */
{
    switch (type) {
    case ::rice::p2p::multiring::messaging::RingMessage::TYPE:
        return new ::rice::p2p::multiring::messaging::RingMessage(buf, endpoint, MultiringNode_this->endpoints);
    }

    throw new ::java::lang::IllegalArgumentException(::java::lang::StringBuilder().append(u"Invalid type:"_j)->append(type)->toString());
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::multiring::MultiringNode_MultiringNode_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::multiring::MultiringNode_MultiringNode_1::getClass0()
{
    return class_();
}

