// Generated from /pastry-2.1/src/rice/pastry/messaging/MessageDispatch.java
#include <rice/pastry/messaging/MessageDispatch.hpp>

#include <java/lang/Class.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/IllegalArgumentException.hpp>
#include <java/lang/Integer.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/util/Collection.hpp>
#include <java/util/HashMap.hpp>
#include <java/util/Iterator.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/LogManager.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/pastry/PastryNode.hpp>
#include <rice/pastry/client/PastryAppl.hpp>
#include <rice/pastry/messaging/Message.hpp>
#include <rice/pastry/transport/Deserializer.hpp>

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

rice::pastry::messaging::MessageDispatch::MessageDispatch(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::messaging::MessageDispatch::MessageDispatch(::rice::pastry::PastryNode* pn, ::rice::pastry::transport::Deserializer* deserializer) 
    : MessageDispatch(*static_cast< ::default_init_tag* >(0))
{
    ctor(pn,deserializer);
}

void rice::pastry::messaging::MessageDispatch::ctor(::rice::pastry::PastryNode* pn, ::rice::pastry::transport::Deserializer* deserializer)
{
    super::ctor();
    this->deserializer = deserializer;
    addressBook = new ::java::util::HashMap();
    this->localNode = pn;
    this->logger = npc(npc(npc(pn)->getEnvironment())->getLogManager())->getLogger(getClass(), nullptr);
}

void rice::pastry::messaging::MessageDispatch::registerReceiver(int32_t address, ::rice::pastry::client::PastryAppl* receiver)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(::java::lang::StringBuilder().append(u"Registering "_j)->append(static_cast< ::java::lang::Object* >(receiver))
            ->append(u" for address "_j)
            ->append(address)->toString());

    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINEST)
        npc(logger)->logException(::java::lang::StringBuilder().append(u"Registering receiver for address "_j)->append(address)->toString(), new ::java::lang::Exception(u"stack trace"_j));

    if(java_cast< ::rice::pastry::client::PastryAppl* >(npc(addressBook)->get(static_cast< ::java::lang::Object* >(::java::lang::Integer::valueOf(address)))) != nullptr) {
        throw new ::java::lang::IllegalArgumentException(::java::lang::StringBuilder().append(u"Registering receiver for already-registered address "_j)->append(address)->toString());
    }
    npc(deserializer)->setDeserializer(address, npc(receiver)->getDeserializer());
    npc(addressBook)->put(static_cast< ::java::lang::Object* >(::java::lang::Integer::valueOf(address)), static_cast< ::java::lang::Object* >(receiver));
}

rice::pastry::client::PastryAppl* rice::pastry::messaging::MessageDispatch::getDestination(Message* msg)
{
    return getDestinationByAddress(npc(msg)->getDestination());
}

rice::pastry::client::PastryAppl* rice::pastry::messaging::MessageDispatch::getDestinationByAddress(int32_t addr)
{
    auto mr = java_cast< ::rice::pastry::client::PastryAppl* >(java_cast< ::rice::pastry::client::PastryAppl* >(npc(addressBook)->get(static_cast< ::java::lang::Object* >(::java::lang::Integer::valueOf(addr)))));
    return mr;
}

bool rice::pastry::messaging::MessageDispatch::dispatchMessage(Message* msg)
{
    if(npc(msg)->getDestination() == 0) {
        auto logger = npc(npc(npc(localNode)->getEnvironment())->getLogManager())->getLogger(MessageDispatch::class_(), nullptr);
        if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(logger)->logException(::java::lang::StringBuilder().append(u"Message "_j)->append(static_cast< ::java::lang::Object* >(msg))
                ->append(u","_j)
                ->append(npc(npc(msg)->getClass())->getName())
                ->append(u" has no destination."_j)->toString(), new ::java::lang::Exception(u"Stack Trace"_j));

        return false;
    }
    auto mr = java_cast< ::rice::pastry::client::PastryAppl* >(java_cast< ::rice::pastry::client::PastryAppl* >(npc(addressBook)->get(static_cast< ::java::lang::Object* >(::java::lang::Integer::valueOf(npc(msg)->getDestination())))));
    if(mr == nullptr) {
        if((npc(logger)->level <= ::rice::environment::logging::Logger::FINE) || (npc(localNode)->isReady() && (npc(logger)->level <= ::rice::environment::logging::Logger::INFO))) {
            npc(logger)->log(::java::lang::StringBuilder().append(u"Dropping message "_j)->append(static_cast< ::java::lang::Object* >(msg))
                ->append(u" because the application address "_j)
                ->append(npc(msg)->getDestination())
                ->append(u" is unknown."_j)->toString());
        }
        return false;
    } else {
        npc(mr)->receiveMessage(msg);
        return true;
    }
}

void rice::pastry::messaging::MessageDispatch::destroy()
{
    auto i = npc(npc(addressBook)->values())->iterator();
    while (npc(i)->hasNext()) {
        auto mr = java_cast< ::rice::pastry::client::PastryAppl* >(npc(i)->next());
        if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
            npc(logger)->log(::java::lang::StringBuilder().append(u"Destroying "_j)->append(static_cast< ::java::lang::Object* >(mr))->toString());

        npc(mr)->destroy();
    }
    npc(addressBook)->clear();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::messaging::MessageDispatch::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.messaging.MessageDispatch", 37);
    return c;
}

java::lang::Class* rice::pastry::messaging::MessageDispatch::getClass0()
{
    return class_();
}

