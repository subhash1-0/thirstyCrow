// Generated from /pastry-2.1/src/rice/selector/ProfileSelector.java
#include <rice/selector/ProfileSelector_printStats_2.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <rice/selector/ProfileSelector_Stat.hpp>
#include <rice/selector/ProfileSelector.hpp>

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

rice::selector::ProfileSelector_printStats_2::ProfileSelector_printStats_2(ProfileSelector *ProfileSelector_this)
    : super(*static_cast< ::default_init_tag* >(0))
    , ProfileSelector_this(ProfileSelector_this)
{
    clinit();
    ctor();
}

bool rice::selector::ProfileSelector_printStats_2::equals(::java::lang::Object* arg0)
{
    return false;
}

int32_t rice::selector::ProfileSelector_printStats_2::compare(ProfileSelector_Stat* arg0, ProfileSelector_Stat* arg1)
{
    auto stat1 = java_cast< ProfileSelector_Stat* >(arg0);
    auto stat2 = java_cast< ProfileSelector_Stat* >(arg1);
    return static_cast< int32_t >((npc(stat2)->totalTime - npc(stat1)->totalTime));
}

int32_t rice::selector::ProfileSelector_printStats_2::compare(::java::lang::Object* arg0, ::java::lang::Object* arg1)
{ 
    return compare(dynamic_cast< ProfileSelector_Stat* >(arg0), dynamic_cast< ProfileSelector_Stat* >(arg1));
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::selector::ProfileSelector_printStats_2::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::selector::ProfileSelector_printStats_2::getClass0()
{
    return class_();
}

