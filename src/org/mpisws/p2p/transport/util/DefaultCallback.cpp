// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/util/DefaultCallback.java
#include <org/mpisws/p2p/transport/util/DefaultCallback.hpp>

#include <java/lang/Class.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <org/mpisws/p2p/transport/P2PSocket.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/LogManager.hpp>
#include <rice/environment/logging/Logger.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::transport::util::DefaultCallback::DefaultCallback(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::transport::util::DefaultCallback::DefaultCallback(::rice::environment::Environment* environment) 
    : DefaultCallback(*static_cast< ::default_init_tag* >(0))
{
    ctor(environment);
}

org::mpisws::p2p::transport::util::DefaultCallback::DefaultCallback(::rice::environment::logging::Logger* logger) 
    : DefaultCallback(*static_cast< ::default_init_tag* >(0))
{
    ctor(logger);
}

void org::mpisws::p2p::transport::util::DefaultCallback::ctor(::rice::environment::Environment* environment)
{
    super::ctor();
    logger = npc(npc(environment)->getLogManager())->getLogger(DefaultCallback::class_(), nullptr);
}

void org::mpisws::p2p::transport::util::DefaultCallback::ctor(::rice::environment::logging::Logger* logger)
{
    super::ctor();
    this->logger = logger;
}

void org::mpisws::p2p::transport::util::DefaultCallback::incomingSocket(::org::mpisws::p2p::transport::P2PSocket* s) /* throws(IOException) */
{
    npc(logger)->log(::java::lang::StringBuilder().append(u"incomingSocket("_j)->append(static_cast< ::java::lang::Object* >(s))
        ->append(u")"_j)->toString());
}

void org::mpisws::p2p::transport::util::DefaultCallback::livenessChanged(::java::lang::Object* i, int32_t state)
{
    npc(logger)->log(::java::lang::StringBuilder().append(u"livenessChanged("_j)->append(static_cast< ::java::lang::Object* >(i))
        ->append(u","_j)
        ->append(state)
        ->append(u")"_j)->toString());
}

void org::mpisws::p2p::transport::util::DefaultCallback::messageReceived(::java::lang::Object* i, ::java::lang::Object* m, ::java::util::Map* options) /* throws(IOException) */
{
    npc(logger)->log(::java::lang::StringBuilder().append(u"messageReceived("_j)->append(static_cast< ::java::lang::Object* >(i))
        ->append(u","_j)
        ->append(static_cast< ::java::lang::Object* >(m))
        ->append(u")"_j)->toString());
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::util::DefaultCallback::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.util.DefaultCallback", 45);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::util::DefaultCallback::getClass0()
{
    return class_();
}

