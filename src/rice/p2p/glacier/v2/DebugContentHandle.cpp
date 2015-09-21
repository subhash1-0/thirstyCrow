// Generated from /pastry-2.1/src/rice/p2p/glacier/v2/DebugContentHandle.java
#include <rice/p2p/glacier/v2/DebugContentHandle.hpp>

#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/commonapi/NodeHandle.hpp>

rice::p2p::glacier::v2::DebugContentHandle::DebugContentHandle(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::glacier::v2::DebugContentHandle::DebugContentHandle(::rice::p2p::commonapi::Id* id, int64_t version, int64_t expiration, ::rice::p2p::commonapi::NodeHandle* nodeHandle) 
    : DebugContentHandle(*static_cast< ::default_init_tag* >(0))
{
    ctor(id,version,expiration,nodeHandle);
}

void rice::p2p::glacier::v2::DebugContentHandle::ctor(::rice::p2p::commonapi::Id* id, int64_t version, int64_t expiration, ::rice::p2p::commonapi::NodeHandle* nodeHandle)
{
    super::ctor();
    myId = id;
    myNodeHandle = nodeHandle;
    myExpiration = expiration;
    myVersion = version;
}

rice::p2p::commonapi::Id* rice::p2p::glacier::v2::DebugContentHandle::getId()
{
    return myId;
}

rice::p2p::commonapi::NodeHandle* rice::p2p::glacier::v2::DebugContentHandle::getNodeHandle()
{
    return myNodeHandle;
}

int64_t rice::p2p::glacier::v2::DebugContentHandle::getVersion()
{
    return myVersion;
}

int64_t rice::p2p::glacier::v2::DebugContentHandle::getExpiration()
{
    return myExpiration;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::glacier::v2::DebugContentHandle::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.glacier.v2.DebugContentHandle", 38);
    return c;
}

java::lang::Class* rice::p2p::glacier::v2::DebugContentHandle::getClass0()
{
    return class_();
}

