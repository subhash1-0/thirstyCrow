// Generated from /pastry-2.1/src/rice/selector/ProfileSelector.java
#include <rice/selector/ProfileSelector_Stat.hpp>

#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/selector/ProfileSelector.hpp>

rice::selector::ProfileSelector_Stat::ProfileSelector_Stat(ProfileSelector *ProfileSelector_this, const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
    , ProfileSelector_this(ProfileSelector_this)
{
    clinit();
}

rice::selector::ProfileSelector_Stat::ProfileSelector_Stat(ProfileSelector *ProfileSelector_this, ::java::lang::String* name) 
    : ProfileSelector_Stat(ProfileSelector_this, *static_cast< ::default_init_tag* >(0))
{
    ctor(name);
}

void rice::selector::ProfileSelector_Stat::init()
{
    num = int32_t(0);
    name = nullptr;
    totalTime = int32_t(0);
    maxTime = int32_t(0);
}

void rice::selector::ProfileSelector_Stat::ctor(::java::lang::String* name)
{
    super::ctor();
    init();
    this->name = name;
}

void rice::selector::ProfileSelector_Stat::addTime(int64_t t)
{
    num++;
    totalTime += t;
    if(t > maxTime) {
        maxTime = t;
    }
}

java::lang::String* rice::selector::ProfileSelector_Stat::toString()
{
    auto avgTime = totalTime / num;
    return ::java::lang::StringBuilder().append(name)->append(u"\t maxTime:"_j)
        ->append(maxTime)
        ->append(u"\t avgTime:"_j)
        ->append(avgTime)
        ->append(u"\t numInstances:"_j)
        ->append(num)
        ->append(u"\t totalTime:"_j)
        ->append(totalTime)->toString();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::selector::ProfileSelector_Stat::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.selector.ProfileSelector.Stat", 34);
    return c;
}

java::lang::Class* rice::selector::ProfileSelector_Stat::getClass0()
{
    return class_();
}

