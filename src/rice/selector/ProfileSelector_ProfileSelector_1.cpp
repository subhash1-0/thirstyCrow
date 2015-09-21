// Generated from /pastry-2.1/src/rice/selector/ProfileSelector.java
#include <rice/selector/ProfileSelector_ProfileSelector_1.hpp>

#include <java/io/PrintStream.hpp>
#include <java/lang/InterruptedException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/System.hpp>
#include <java/lang/Thread.hpp>
#include <rice/selector/ProfileSelector.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::selector::ProfileSelector_ProfileSelector_1::ProfileSelector_ProfileSelector_1(ProfileSelector *ProfileSelector_this, int32_t lastTaskTime)
    : super(*static_cast< ::default_init_tag* >(0))
    , ProfileSelector_this(ProfileSelector_this)
    , lastTaskTime(lastTaskTime)
{
    clinit();
    ctor();
}

void rice::selector::ProfileSelector_ProfileSelector_1::run()
{
    while (true) {
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"LastTask: type:"_j)->append(ProfileSelector_this->lastTaskType)
            ->append(u" class:"_j)
            ->append(ProfileSelector_this->lastTaskClass)
            ->append(u" toString():"_j)
            ->append(ProfileSelector_this->lastTaskToString)
            ->append(u" hash:"_j)
            ->append(ProfileSelector_this->lastTaskHash)->toString());
        try {
            ::java::lang::Thread::sleep(lastTaskTime);
        } catch (::java::lang::InterruptedException* ie) {
        }
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::selector::ProfileSelector_ProfileSelector_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::selector::ProfileSelector_ProfileSelector_1::getClass0()
{
    return class_();
}

