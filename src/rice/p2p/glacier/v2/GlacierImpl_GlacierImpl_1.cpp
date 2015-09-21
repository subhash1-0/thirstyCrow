// Generated from /pastry-2.1/src/rice/p2p/glacier/v2/GlacierImpl.java
#include <rice/p2p/glacier/v2/GlacierImpl_GlacierImpl_1.hpp>

#include <java/lang/IllegalArgumentException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/p2p/glacier/v2/GlacierImpl.hpp>
#include <rice/p2p/glacier/v2/messaging/GlacierDataMessage.hpp>
#include <rice/p2p/glacier/v2/messaging/GlacierFetchMessage.hpp>
#include <rice/p2p/glacier/v2/messaging/GlacierNeighborRequestMessage.hpp>
#include <rice/p2p/glacier/v2/messaging/GlacierNeighborResponseMessage.hpp>
#include <rice/p2p/glacier/v2/messaging/GlacierQueryMessage.hpp>
#include <rice/p2p/glacier/v2/messaging/GlacierRangeForwardMessage.hpp>
#include <rice/p2p/glacier/v2/messaging/GlacierRangeQueryMessage.hpp>
#include <rice/p2p/glacier/v2/messaging/GlacierRangeResponseMessage.hpp>
#include <rice/p2p/glacier/v2/messaging/GlacierRefreshCompleteMessage.hpp>
#include <rice/p2p/glacier/v2/messaging/GlacierRefreshPatchMessage.hpp>
#include <rice/p2p/glacier/v2/messaging/GlacierRefreshProbeMessage.hpp>
#include <rice/p2p/glacier/v2/messaging/GlacierRefreshResponseMessage.hpp>
#include <rice/p2p/glacier/v2/messaging/GlacierResponseMessage.hpp>
#include <rice/p2p/glacier/v2/messaging/GlacierSyncMessage.hpp>

rice::p2p::glacier::v2::GlacierImpl_GlacierImpl_1::GlacierImpl_GlacierImpl_1(GlacierImpl *GlacierImpl_this)
    : super(*static_cast< ::default_init_tag* >(0))
    , GlacierImpl_this(GlacierImpl_this)
{
    clinit();
    ctor();
}

rice::p2p::commonapi::Message* rice::p2p::glacier::v2::GlacierImpl_GlacierImpl_1::deserialize(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, int16_t type, int32_t priority, ::rice::p2p::commonapi::NodeHandle* sender) /* throws(IOException) */
{
    switch (type) {
    case ::rice::p2p::glacier::v2::messaging::GlacierDataMessage::TYPE:
        return ::rice::p2p::glacier::v2::messaging::GlacierDataMessage::build(buf, GlacierImpl_this->endpoint);
    case ::rice::p2p::glacier::v2::messaging::GlacierFetchMessage::TYPE:
        return ::rice::p2p::glacier::v2::messaging::GlacierFetchMessage::build(buf, GlacierImpl_this->endpoint);
    case ::rice::p2p::glacier::v2::messaging::GlacierNeighborRequestMessage::TYPE:
        return ::rice::p2p::glacier::v2::messaging::GlacierNeighborRequestMessage::build(buf, GlacierImpl_this->endpoint);
    case ::rice::p2p::glacier::v2::messaging::GlacierNeighborResponseMessage::TYPE:
        return ::rice::p2p::glacier::v2::messaging::GlacierNeighborResponseMessage::build(buf, GlacierImpl_this->endpoint);
    case ::rice::p2p::glacier::v2::messaging::GlacierQueryMessage::TYPE:
        return ::rice::p2p::glacier::v2::messaging::GlacierQueryMessage::build(buf, GlacierImpl_this->endpoint);
    case ::rice::p2p::glacier::v2::messaging::GlacierRangeForwardMessage::TYPE:
        return ::rice::p2p::glacier::v2::messaging::GlacierRangeForwardMessage::build(buf, GlacierImpl_this->endpoint);
    case ::rice::p2p::glacier::v2::messaging::GlacierRangeQueryMessage::TYPE:
        return ::rice::p2p::glacier::v2::messaging::GlacierRangeQueryMessage::build(buf, GlacierImpl_this->endpoint);
    case ::rice::p2p::glacier::v2::messaging::GlacierRangeResponseMessage::TYPE:
        return ::rice::p2p::glacier::v2::messaging::GlacierRangeResponseMessage::build(buf, GlacierImpl_this->endpoint);
    case ::rice::p2p::glacier::v2::messaging::GlacierRefreshCompleteMessage::TYPE:
        return ::rice::p2p::glacier::v2::messaging::GlacierRefreshCompleteMessage::build(buf, GlacierImpl_this->endpoint);
    case ::rice::p2p::glacier::v2::messaging::GlacierRefreshPatchMessage::TYPE:
        return ::rice::p2p::glacier::v2::messaging::GlacierRefreshPatchMessage::build(buf, GlacierImpl_this->endpoint);
    case ::rice::p2p::glacier::v2::messaging::GlacierRefreshProbeMessage::TYPE:
        return ::rice::p2p::glacier::v2::messaging::GlacierRefreshProbeMessage::build(buf, GlacierImpl_this->endpoint);
    case ::rice::p2p::glacier::v2::messaging::GlacierRefreshResponseMessage::TYPE:
        return ::rice::p2p::glacier::v2::messaging::GlacierRefreshResponseMessage::build(buf, GlacierImpl_this->endpoint);
    case ::rice::p2p::glacier::v2::messaging::GlacierResponseMessage::TYPE:
        return ::rice::p2p::glacier::v2::messaging::GlacierResponseMessage::build(buf, GlacierImpl_this->endpoint);
    case ::rice::p2p::glacier::v2::messaging::GlacierSyncMessage::TYPE:
        return ::rice::p2p::glacier::v2::messaging::GlacierSyncMessage::build(buf, GlacierImpl_this->endpoint);
    }

    throw new ::java::lang::IllegalArgumentException(::java::lang::StringBuilder().append(u"Unknown type:"_j)->append(type)->toString());
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::glacier::v2::GlacierImpl_GlacierImpl_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::glacier::v2::GlacierImpl_GlacierImpl_1::getClass0()
{
    return class_();
}

