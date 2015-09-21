// Generated from /pastry-2.1/src/rice/p2p/commonapi/exception/AppNotRegisteredException.java
#include <rice/p2p/commonapi/exception/AppNotRegisteredException.hpp>

#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>

rice::p2p::commonapi::exception::AppNotRegisteredException::AppNotRegisteredException(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::commonapi::exception::AppNotRegisteredException::AppNotRegisteredException(int32_t appid) 
    : AppNotRegisteredException(*static_cast< ::default_init_tag* >(0))
{
    ctor(appid);
}

void rice::p2p::commonapi::exception::AppNotRegisteredException::ctor(int32_t appid)
{
    super::ctor(::java::lang::StringBuilder().append(u"Application with id "_j)->append(appid)
        ->append(u" not registered."_j)->toString());
    this->appid = appid;
}

int32_t rice::p2p::commonapi::exception::AppNotRegisteredException::getAppid()
{
    return appid;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::commonapi::exception::AppNotRegisteredException::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.commonapi.exception.AppNotRegisteredException", 54);
    return c;
}

java::lang::Class* rice::p2p::commonapi::exception::AppNotRegisteredException::getClass0()
{
    return class_();
}

