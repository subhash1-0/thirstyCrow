// Generated from /pastry-2.1/src/rice/pastry/NodeSetUpdate.java
#include <rice/pastry/NodeSetUpdate.hpp>

#include <rice/pastry/NodeHandle.hpp>

rice::pastry::NodeSetUpdate::NodeSetUpdate(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::NodeSetUpdate::NodeSetUpdate(NodeHandle* which, bool how) 
    : NodeSetUpdate(*static_cast< ::default_init_tag* >(0))
{
    ctor(which,how);
}

void rice::pastry::NodeSetUpdate::ctor(NodeHandle* which, bool how)
{
    super::ctor();
    changed = which;
    added = how;
}

rice::pastry::NodeHandle* rice::pastry::NodeSetUpdate::handle()
{
    return changed;
}

bool rice::pastry::NodeSetUpdate::wasAdded()
{
    return added;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::NodeSetUpdate::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.NodeSetUpdate", 25);
    return c;
}

java::lang::Class* rice::pastry::NodeSetUpdate::getClass0()
{
    return class_();
}

