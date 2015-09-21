// Generated from /pastry-2.1/src/rice/p2p/glacier/v2/GlacierImpl.java
#include <rice/p2p/glacier/v2/GlacierImpl_refresh_20.hpp>

#include <rice/p2p/glacier/v2/GlacierImpl_refresh_20_receiveResult_20_1.hpp>
#include <rice/p2p/glacier/v2/GlacierImpl.hpp>

rice::p2p::glacier::v2::GlacierImpl_refresh_20::GlacierImpl_refresh_20(GlacierImpl *GlacierImpl_this, ::rice::p2p::glacier::VersionKey* thisVersionKey, ::rice::p2p::commonapi::Id* thisId, int64_t thisVersion, int64_t thisExpiration, ::rice::Continuation* thisContinuation)
    : super(*static_cast< ::default_init_tag* >(0))
    , GlacierImpl_this(GlacierImpl_this)
    , thisVersionKey(thisVersionKey)
    , thisId(thisId)
    , thisVersion(thisVersion)
    , thisExpiration(thisExpiration)
    , thisContinuation(thisContinuation)
{
    clinit();
    ctor();
}

void rice::p2p::glacier::v2::GlacierImpl_refresh_20::receiveResult(::java::lang::Object* o)
{
    GlacierImpl_this->retrieveManifest(thisVersionKey, GlacierImpl_this->tagRefresh, new GlacierImpl_refresh_20_receiveResult_20_1(this, thisId, thisVersion, thisExpiration, thisContinuation));
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::glacier::v2::GlacierImpl_refresh_20::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::glacier::v2::GlacierImpl_refresh_20::getClass0()
{
    return class_();
}

