// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/wire/UDPLayerImpl.java
#include <org/mpisws/p2p/transport/wire/UDPLayerImpl_destroy_1.hpp>

#include <java/io/IOException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/nio/channels/DatagramChannel.hpp>
#include <java/nio/channels/SelectableChannel.hpp>
#include <java/nio/channels/SelectionKey.hpp>
#include <org/mpisws/p2p/transport/wire/UDPLayerImpl.hpp>
#include <rice/environment/logging/Logger.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::transport::wire::UDPLayerImpl_destroy_1::UDPLayerImpl_destroy_1(UDPLayerImpl *UDPLayerImpl_this)
    : super(*static_cast< ::default_init_tag* >(0))
    , UDPLayerImpl_this(UDPLayerImpl_this)
{
    clinit();
    ctor();
}

void org::mpisws::p2p::transport::wire::UDPLayerImpl_destroy_1::run()
{
    try {
        if(npc(UDPLayerImpl_this->logger)->level <= ::rice::environment::logging::Logger::INFO)
            npc(UDPLayerImpl_this->logger)->log(::java::lang::StringBuilder().append(u"destroy(): "_j)->append(static_cast< ::java::lang::Object* >(UDPLayerImpl_this->channel))->toString());

        if(UDPLayerImpl_this->key != nullptr) {
            if(npc(UDPLayerImpl_this->key)->channel() != nullptr)
                npc(npc(UDPLayerImpl_this->key)->channel())->close();

            npc(UDPLayerImpl_this->key)->cancel();
            npc(UDPLayerImpl_this->key)->attach(nullptr);
        }
    } catch (::java::io::IOException* ioe) {
        if(npc(UDPLayerImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(UDPLayerImpl_this->logger)->logException(u"Error destroying UDPLayer"_j, ioe);

    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::wire::UDPLayerImpl_destroy_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::wire::UDPLayerImpl_destroy_1::getClass0()
{
    return class_();
}

