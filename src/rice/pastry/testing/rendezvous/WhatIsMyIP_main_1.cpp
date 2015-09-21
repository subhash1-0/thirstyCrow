// Generated from /pastry-2.1/src/rice/pastry/testing/rendezvous/WhatIsMyIP.java
#include <rice/pastry/testing/rendezvous/WhatIsMyIP_main_1.hpp>

#include <java/io/IOException.hpp>
#include <java/io/PrintStream.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/System.hpp>
#include <java/net/InetAddress.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::pastry::testing::rendezvous::WhatIsMyIP_main_1::WhatIsMyIP_main_1()
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
    ctor();
}

void rice::pastry::testing::rendezvous::WhatIsMyIP_main_1::receiveResult(::java::net::InetAddress* result)
{
    npc(::java::lang::System::out())->println(static_cast< ::java::lang::Object* >(result));
}

void rice::pastry::testing::rendezvous::WhatIsMyIP_main_1::receiveResult(::java::lang::Object* result)
{ 
    receiveResult(dynamic_cast< ::java::net::InetAddress* >(result));
}

void rice::pastry::testing::rendezvous::WhatIsMyIP_main_1::receiveException(::java::io::IOException* exception)
{
}

void rice::pastry::testing::rendezvous::WhatIsMyIP_main_1::receiveException(::java::lang::Exception* exception)
{ 
    receiveException(dynamic_cast< ::java::io::IOException* >(exception));
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::testing::rendezvous::WhatIsMyIP_main_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::pastry::testing::rendezvous::WhatIsMyIP_main_1::getClass0()
{
    return class_();
}

