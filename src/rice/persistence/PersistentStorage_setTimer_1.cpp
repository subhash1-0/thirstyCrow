// Generated from /pastry-2.1/src/rice/persistence/PersistentStorage.java
#include <rice/persistence/PersistentStorage_setTimer_1.hpp>

#include <java/lang/NullPointerException.hpp>
#include <java/lang/String.hpp>
#include <rice/Continuation_ListenerContinuation.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/processing/Processor.hpp>
#include <rice/persistence/PersistentStorage_setTimer_1_run_1_1.hpp>
#include <rice/persistence/PersistentStorage.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::persistence::PersistentStorage_setTimer_1::PersistentStorage_setTimer_1(PersistentStorage *PersistentStorage_this)
    : super(*static_cast< ::default_init_tag* >(0))
    , PersistentStorage_this(PersistentStorage_this)
{
    clinit();
    ctor();
}

java::lang::String* rice::persistence::PersistentStorage_setTimer_1::toString()
{
    return u"persistence dirty purge enqueue"_j;
}

void rice::persistence::PersistentStorage_setTimer_1::run()
{
    npc(npc(PersistentStorage_this->environment)->getProcessor())->processBlockingIO(new PersistentStorage_setTimer_1_run_1_1(this, new ::rice::Continuation_ListenerContinuation(u"Enqueue of writeMetadataFile"_j, PersistentStorage_this->environment), npc(PersistentStorage_this->environment)->getSelectorManager()));
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::persistence::PersistentStorage_setTimer_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::persistence::PersistentStorage_setTimer_1::getClass0()
{
    return class_();
}

