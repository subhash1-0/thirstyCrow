// Generated from /pastry-2.1/src/rice/p2p/glacier/v2/GlacierContentHandle.java
#include <rice/p2p/glacier/v2/GlacierContentHandle.hpp>

#include <java/lang/NullPointerException.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/commonapi/NodeHandle.hpp>
#include <rice/p2p/glacier/v2/Manifest.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::glacier::v2::GlacierContentHandle::GlacierContentHandle(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::glacier::v2::GlacierContentHandle::GlacierContentHandle(::rice::p2p::commonapi::Id* id, int64_t version, ::rice::p2p::commonapi::NodeHandle* nodeHandle, Manifest* manifest) 
    : GlacierContentHandle(*static_cast< ::default_init_tag* >(0))
{
    ctor(id,version,nodeHandle,manifest);
}

void rice::p2p::glacier::v2::GlacierContentHandle::ctor(::rice::p2p::commonapi::Id* id, int64_t version, ::rice::p2p::commonapi::NodeHandle* nodeHandle, Manifest* manifest)
{
    super::ctor();
    this->id = id;
    this->nodeHandle = nodeHandle;
    this->manifest = manifest;
    this->version = version;
}

rice::p2p::commonapi::Id* rice::p2p::glacier::v2::GlacierContentHandle::getId()
{
    return id;
}

rice::p2p::commonapi::NodeHandle* rice::p2p::glacier::v2::GlacierContentHandle::getNodeHandle()
{
    return nodeHandle;
}

int64_t rice::p2p::glacier::v2::GlacierContentHandle::getVersion()
{
    return version;
}

int64_t rice::p2p::glacier::v2::GlacierContentHandle::getExpiration()
{
    return npc(manifest)->expirationDate;
}

rice::p2p::glacier::v2::Manifest* rice::p2p::glacier::v2::GlacierContentHandle::getManifest()
{
    return manifest;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::glacier::v2::GlacierContentHandle::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.glacier.v2.GlacierContentHandle", 40);
    return c;
}

java::lang::Class* rice::p2p::glacier::v2::GlacierContentHandle::getClass0()
{
    return class_();
}

