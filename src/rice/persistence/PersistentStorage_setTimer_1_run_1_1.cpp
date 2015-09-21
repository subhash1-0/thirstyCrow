// Generated from /pastry-2.1/src/rice/persistence/PersistentStorage.java
#include <rice/persistence/PersistentStorage_setTimer_1_run_1_1.hpp>

#include <java/lang/Boolean.hpp>
#include <java/lang/String.hpp>
#include <rice/persistence/PersistentStorage_setTimer_1.hpp>
#include <rice/persistence/PersistentStorage.hpp>

rice::persistence::PersistentStorage_setTimer_1_run_1_1::PersistentStorage_setTimer_1_run_1_1(PersistentStorage_setTimer_1 *PersistentStorage_setTimer_1_this, ::rice::Continuation* c, ::rice::selector::SelectorManager* sm)
    : super(*static_cast< ::default_init_tag* >(0))
    , PersistentStorage_setTimer_1_this(PersistentStorage_setTimer_1_this)
{
    clinit();
    ctor(c, sm);
}

rice::persistence::PersistentStorage_setTimer_1_run_1_1::PersistentStorage_setTimer_1_run_1_1(PersistentStorage_setTimer_1 *PersistentStorage_setTimer_1_this)
    : super(*static_cast< ::default_init_tag* >(0))
    , PersistentStorage_setTimer_1_this(PersistentStorage_setTimer_1_this)
{
    clinit();
    ctor();
}

java::lang::String* rice::persistence::PersistentStorage_setTimer_1_run_1_1::toString()
{
    return u"persistence dirty purge"_j;
}

java::lang::Object* rice::persistence::PersistentStorage_setTimer_1_run_1_1::doWork() /* throws(Exception) */
{
    PersistentStorage_setTimer_1_this->PersistentStorage_this->writeDirty();
    return ::java::lang::Boolean::TRUE();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::persistence::PersistentStorage_setTimer_1_run_1_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::persistence::PersistentStorage_setTimer_1_run_1_1::getClass0()
{
    return class_();
}

