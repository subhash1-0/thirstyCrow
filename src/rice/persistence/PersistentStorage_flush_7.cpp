// Generated from /pastry-2.1/src/rice/persistence/PersistentStorage.java
#include <rice/persistence/PersistentStorage_flush_7.hpp>

#include <java/lang/Boolean.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/persistence/PersistentStorage.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::persistence::PersistentStorage_flush_7::PersistentStorage_flush_7(PersistentStorage *PersistentStorage_this, ::rice::Continuation* c, ::rice::selector::SelectorManager* sm)
    : super(*static_cast< ::default_init_tag* >(0))
    , PersistentStorage_this(PersistentStorage_this)
{
    clinit();
    ctor(c, sm);
}

rice::persistence::PersistentStorage_flush_7::PersistentStorage_flush_7(PersistentStorage *PersistentStorage_this)
    : super(*static_cast< ::default_init_tag* >(0))
    , PersistentStorage_this(PersistentStorage_this)
{
    clinit();
    ctor();
}

java::lang::String* rice::persistence::PersistentStorage_flush_7::toString()
{
    return u"flush"_j;
}

java::lang::Object* rice::persistence::PersistentStorage_flush_7::doWork() /* throws(Exception) */
{
    if(npc(PersistentStorage_this->logger)->level <= ::rice::environment::logging::Logger::FINER)
        npc(PersistentStorage_this->logger)->log(::java::lang::StringBuilder().append(u"COUNT: Flushing all data in "_j)->append(PersistentStorage_this->name)->toString());

    PersistentStorage_this->flushDirectory(PersistentStorage_this->appDirectory);
    return ::java::lang::Boolean::TRUE();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::persistence::PersistentStorage_flush_7::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::persistence::PersistentStorage_flush_7::getClass0()
{
    return class_();
}

