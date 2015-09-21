// Generated from /pastry-2.1/src/rice/environment/Environment.java
#include <rice/environment/Environment_destroy_1.hpp>

#include <rice/environment/Environment.hpp>

rice::environment::Environment_destroy_1::Environment_destroy_1(Environment *Environment_this)
    : super(*static_cast< ::default_init_tag* >(0))
    , Environment_this(Environment_this)
{
    clinit();
    ctor();
}

void rice::environment::Environment_destroy_1::run()
{
    Environment_this->callDestroyOnDestructables();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::environment::Environment_destroy_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::environment::Environment_destroy_1::getClass0()
{
    return class_();
}

