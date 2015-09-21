// Generated from /pastry-2.1/src/rice/environment/params/simple/ParamsNotPresentException.java
#include <rice/environment/params/simple/ParamsNotPresentException.hpp>

#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::environment::params::simple::ParamsNotPresentException::ParamsNotPresentException(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::environment::params::simple::ParamsNotPresentException::ParamsNotPresentException(::java::lang::String* reason, ::java::lang::Exception* e) 
    : ParamsNotPresentException(*static_cast< ::default_init_tag* >(0))
{
    ctor(reason,e);
}

void rice::environment::params::simple::ParamsNotPresentException::ctor(::java::lang::String* reason, ::java::lang::Exception* e)
{
    super::ctor(reason);
    this->subexception = e;
}

void rice::environment::params::simple::ParamsNotPresentException::printStackTrace(::java::io::PrintStream* arg0)
{
    super::printStackTrace(arg0);
    npc(subexception)->printStackTrace(arg0);
}

void rice::environment::params::simple::ParamsNotPresentException::printStackTrace()
{
    super::printStackTrace();
    npc(subexception)->printStackTrace();
}

void rice::environment::params::simple::ParamsNotPresentException::printStackTrace(::java::io::PrintWriter* pw)
{
    super::printStackTrace(pw);
    npc(subexception)->printStackTrace(pw);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::environment::params::simple::ParamsNotPresentException::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.environment.params.simple.ParamsNotPresentException", 56);
    return c;
}

java::lang::Class* rice::environment::params::simple::ParamsNotPresentException::getClass0()
{
    return class_();
}

