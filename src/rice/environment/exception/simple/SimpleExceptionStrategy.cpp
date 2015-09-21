// Generated from /pastry-2.1/src/rice/environment/exception/simple/SimpleExceptionStrategy.java
#include <rice/environment/exception/simple/SimpleExceptionStrategy.hpp>

#include <java/lang/Class.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/LogManager.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/selector/SelectorManager.hpp>

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

rice::environment::exception::simple::SimpleExceptionStrategy::SimpleExceptionStrategy(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::environment::exception::simple::SimpleExceptionStrategy::SimpleExceptionStrategy(::rice::environment::logging::LogManager* manager) 
    : SimpleExceptionStrategy(*static_cast< ::default_init_tag* >(0))
{
    ctor(manager);
}

void rice::environment::exception::simple::SimpleExceptionStrategy::ctor(::rice::environment::logging::LogManager* manager)
{
    super::ctor();
    logger = npc(manager)->getLogger(SimpleExceptionStrategy::class_(), nullptr);
}

void rice::environment::exception::simple::SimpleExceptionStrategy::handleException(::java::lang::Object* source, ::java::lang::Throwable* t)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
        npc(logger)->logException(::java::lang::StringBuilder().append(u"handleException("_j)->append(static_cast< ::java::lang::Object* >(source))
            ->append(u")"_j)->toString(), t);

    if(dynamic_cast< ::rice::selector::SelectorManager* >(source) != nullptr) {
        auto sm = java_cast< ::rice::selector::SelectorManager* >(source);
        npc(npc(sm)->getEnvironment())->destroy();
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::environment::exception::simple::SimpleExceptionStrategy::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.environment.exception.simple.SimpleExceptionStrategy", 57);
    return c;
}

java::lang::Class* rice::environment::exception::simple::SimpleExceptionStrategy::getClass0()
{
    return class_();
}

