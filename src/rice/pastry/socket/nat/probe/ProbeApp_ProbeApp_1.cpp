// Generated from /pastry-2.1/src/rice/pastry/socket/nat/probe/ProbeApp.java
#include <rice/pastry/socket/nat/probe/ProbeApp_ProbeApp_1.hpp>

#include <java/lang/IllegalArgumentException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/pastry/socket/nat/probe/ProbeApp.hpp>
#include <rice/pastry/socket/nat/probe/ProbeRequestMessage.hpp>

rice::pastry::socket::nat::probe::ProbeApp_ProbeApp_1::ProbeApp_ProbeApp_1(ProbeApp *ProbeApp_this)
    : super(*static_cast< ::default_init_tag* >(0))
    , ProbeApp_this(ProbeApp_this)
{
    clinit();
    ctor();
}

rice::p2p::commonapi::Message* rice::pastry::socket::nat::probe::ProbeApp_ProbeApp_1::deserialize(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, int16_t type, int32_t priority, ::rice::p2p::commonapi::NodeHandle* sender) /* throws(IOException) */
{
    switch (type) {
    case ProbeRequestMessage::TYPE:
        return ProbeRequestMessage::build(buf, ProbeApp_this->getAddress());
    default:
        throw new ::java::lang::IllegalArgumentException(::java::lang::StringBuilder().append(u"Unknown type: "_j)->append(type)->toString());
    }

}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::socket::nat::probe::ProbeApp_ProbeApp_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::pastry::socket::nat::probe::ProbeApp_ProbeApp_1::getClass0()
{
    return class_();
}

