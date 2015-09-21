// Generated from /pastry-2.1/src/rice/pastry/PastryNode.java
#include <rice/pastry/PastryNode_send_5.hpp>

#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/util/Map.hpp>
#include <rice/pastry/NodeHandle.hpp>
#include <rice/pastry/PastryNode.hpp>
#include <rice/pastry/messaging/Message.hpp>

rice::pastry::PastryNode_send_5::PastryNode_send_5(PastryNode *PastryNode_this, ::java::util::Map* options, ::rice::pastry::messaging::Message* msg)
    : super(*static_cast< ::default_init_tag* >(0))
    , PastryNode_this(PastryNode_this)
    , options(options)
    , msg(msg)
{
    clinit();
    ctor();
}

bool rice::pastry::PastryNode_send_5::cancel()
{
    return false;
}

rice::pastry::NodeHandle* rice::pastry::PastryNode_send_5::getIdentifier()
{
    return PastryNode_this->localhandle;
}

java::util::Map* rice::pastry::PastryNode_send_5::getOptions()
{
    return options;
}

rice::pastry::messaging::Message* rice::pastry::PastryNode_send_5::getMessage()
{
    return msg;
}

java::lang::String* rice::pastry::PastryNode_send_5::toString()
{
    return ::java::lang::StringBuilder().append(u"TLPN$PMsgRecpt{"_j)->append(static_cast< ::java::lang::Object* >(msg))
        ->append(u","_j)
        ->append(static_cast< ::java::lang::Object* >(PastryNode_this->localhandle))
        ->append(u"}"_j)->toString();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::PastryNode_send_5::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::pastry::PastryNode_send_5::getClass0()
{
    return class_();
}

