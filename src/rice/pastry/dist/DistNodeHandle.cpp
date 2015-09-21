// Generated from /pastry-2.1/src/rice/pastry/dist/DistNodeHandle.java
#include <rice/pastry/dist/DistNodeHandle.hpp>

#include <rice/pastry/Id.hpp>

rice::pastry::dist::DistNodeHandle::DistNodeHandle(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::dist::DistNodeHandle::DistNodeHandle(::rice::pastry::Id* nodeId) 
    : DistNodeHandle(*static_cast< ::default_init_tag* >(0))
{
    ctor(nodeId);
}

constexpr int64_t rice::pastry::dist::DistNodeHandle::serialVersionUID;

void rice::pastry::dist::DistNodeHandle::ctor(::rice::pastry::Id* nodeId)
{
    super::ctor();
    this->nodeId = nodeId;
}

rice::pastry::Id* rice::pastry::dist::DistNodeHandle::getNodeId()
{
    return nodeId;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::dist::DistNodeHandle::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.dist.DistNodeHandle", 31);
    return c;
}

java::lang::Class* rice::pastry::dist::DistNodeHandle::getClass0()
{
    return class_();
}

