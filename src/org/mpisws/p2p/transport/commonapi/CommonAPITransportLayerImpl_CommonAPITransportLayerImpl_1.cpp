// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/commonapi/CommonAPITransportLayerImpl.java
#include <org/mpisws/p2p/transport/commonapi/CommonAPITransportLayerImpl_CommonAPITransportLayerImpl_1.hpp>

#include <java/lang/Class.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Short.hpp>
#include <java/lang/String.hpp>
#include <java/util/Map.hpp>
#include <org/mpisws/p2p/transport/commonapi/CommonAPITransportLayerImpl.hpp>
#include <org/mpisws/p2p/transport/util/OptionsFactory.hpp>
#include <rice/p2p/commonapi/rawserialization/RawMessage.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::transport::commonapi::CommonAPITransportLayerImpl_CommonAPITransportLayerImpl_1::CommonAPITransportLayerImpl_CommonAPITransportLayerImpl_1(CommonAPITransportLayerImpl *CommonAPITransportLayerImpl_this)
    : super(*static_cast< ::default_init_tag* >(0))
    , CommonAPITransportLayerImpl_this(CommonAPITransportLayerImpl_this)
{
    clinit();
    ctor();
}

java::util::Map* org::mpisws::p2p::transport::commonapi::CommonAPITransportLayerImpl_CommonAPITransportLayerImpl_1::addOptions(::java::util::Map* options, ::rice::p2p::commonapi::rawserialization::RawMessage* m)
{
    return ::org::mpisws::p2p::transport::util::OptionsFactory::addOption(options, CommonAPITransportLayerImpl::MSG_STRING(), npc(m)->toString(), CommonAPITransportLayerImpl::MSG_TYPE(), ::java::lang::Short::valueOf(npc(m)->getType()), CommonAPITransportLayerImpl::MSG_CLASS(), npc(npc(m)->getClass())->getName());
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::commonapi::CommonAPITransportLayerImpl_CommonAPITransportLayerImpl_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::commonapi::CommonAPITransportLayerImpl_CommonAPITransportLayerImpl_1::getClass0()
{
    return class_();
}

