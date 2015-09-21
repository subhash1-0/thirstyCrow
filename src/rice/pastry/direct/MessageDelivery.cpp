// Generated from /pastry-2.1/src/rice/pastry/direct/MessageDelivery.java
#include <rice/pastry/direct/MessageDelivery.hpp>

#include <java/io/IOException.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/util/Map.hpp>
#include <org/mpisws/p2p/transport/direct/DirectTransportLayer.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/pastry/direct/BasicNetworkSimulator.hpp>

template<typename T, typename U>
static T java_cast(U* u)
{
    if(!u) return static_cast<T>(nullptr);
    auto t = dynamic_cast<T>(u);
    if(!t) throw new ::java::lang::ClassCastException();
    return t;
}

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::pastry::direct::MessageDelivery::MessageDelivery(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::direct::MessageDelivery::MessageDelivery(::java::lang::Object* m, ::java::lang::Object* to, ::java::lang::Object* from, ::java::util::Map* options, BasicNetworkSimulator* sim) 
    : MessageDelivery(*static_cast< ::default_init_tag* >(0))
{
    ctor(m,to,from,options,sim);
}

void rice::pastry::direct::MessageDelivery::ctor(::java::lang::Object* m, ::java::lang::Object* to, ::java::lang::Object* from, ::java::util::Map* options, BasicNetworkSimulator* sim)
{
    super::ctor();
    logger = npc((java_cast< ::org::mpisws::p2p::transport::direct::DirectTransportLayer* >(npc(sim)->getTL(static_cast< ::java::lang::Object* >(to)))))->getLogger();
    msg = m;
    node = to;
    this->options = options;
    this->from = from;
    this->networkSimulator = sim;
    this->seq = npc((java_cast< ::org::mpisws::p2p::transport::direct::DirectTransportLayer* >(npc(sim)->getTL(static_cast< ::java::lang::Object* >(to)))))->getNextSeq();
    logger = npc((java_cast< ::org::mpisws::p2p::transport::direct::DirectTransportLayer* >(npc(sim)->getTL(static_cast< ::java::lang::Object* >(to)))))->getLogger();
}

void rice::pastry::direct::MessageDelivery::deliver()
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(::java::lang::StringBuilder().append(u"MD: deliver "_j)->append(static_cast< ::java::lang::Object* >(java_cast< ::java::lang::Object* >(msg)))
            ->append(u" to "_j)
            ->append(static_cast< ::java::lang::Object* >(java_cast< ::java::lang::Object* >(node)))->toString());

    try {
        auto tl = npc(networkSimulator)->getTL(static_cast< ::java::lang::Object* >(java_cast< ::java::lang::Object* >(node)));
        if(tl != nullptr) {
            npc(networkSimulator)->notifySimulatorListenersReceived(java_cast< ::java::lang::Object* >(msg), java_cast< ::java::lang::Object* >(from), java_cast< ::java::lang::Object* >(node));
            npc(tl)->incomingMessage(java_cast< ::java::lang::Object* >(from), java_cast< ::java::lang::Object* >(msg), options);
        } else {
            if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                npc(logger)->log(::java::lang::StringBuilder().append(u"Message "_j)->append(static_cast< ::java::lang::Object* >(java_cast< ::java::lang::Object* >(msg)))
                    ->append(u" dropped because destination "_j)
                    ->append(static_cast< ::java::lang::Object* >(java_cast< ::java::lang::Object* >(node)))
                    ->append(u" is dead."_j)->toString());

        }
    } catch (::java::io::IOException* ioe) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(logger)->logException(::java::lang::StringBuilder().append(u"Error delivering message "_j)->append(static_cast< ::java::lang::Object* >(this))->toString(), ioe);

    }
}

int32_t rice::pastry::direct::MessageDelivery::getSeq()
{
    return seq;
}

java::lang::String* rice::pastry::direct::MessageDelivery::toString()
{
    return ::java::lang::StringBuilder().append(u"MD["_j)->append(static_cast< ::java::lang::Object* >(java_cast< ::java::lang::Object* >(msg)))
        ->append(u":"_j)
        ->append(static_cast< ::java::lang::Object* >(java_cast< ::java::lang::Object* >(from)))
        ->append(u"=>"_j)
        ->append(static_cast< ::java::lang::Object* >(java_cast< ::java::lang::Object* >(node)))
        ->append(u":"_j)
        ->append(seq)
        ->append(u"]"_j)->toString();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::direct::MessageDelivery::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.direct.MessageDelivery", 34);
    return c;
}

java::lang::Class* rice::pastry::direct::MessageDelivery::getClass0()
{
    return class_();
}

