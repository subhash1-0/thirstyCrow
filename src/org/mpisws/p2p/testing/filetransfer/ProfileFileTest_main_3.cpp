// Generated from /pastry-2.1/src/org/mpisws/p2p/testing/filetransfer/ProfileFileTest.java
#include <org/mpisws/p2p/testing/filetransfer/ProfileFileTest_main_3.hpp>

#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/net/InetSocketAddress.hpp>
#include <java/util/Map.hpp>
#include <rice/environment/logging/Logger.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::testing::filetransfer::ProfileFileTest_main_3::ProfileFileTest_main_3(::rice::environment::logging::Logger* logger)
    : super(*static_cast< ::default_init_tag* >(0))
    , logger(logger)
{
    clinit();
    ctor();
}

void org::mpisws::p2p::testing::filetransfer::ProfileFileTest_main_3::livenessChanged(::java::net::InetSocketAddress* i, int32_t val, ::java::util::Map* options)
{
    npc(logger)->log(::java::lang::StringBuilder().append(u"Node2: livenessChanged("_j)->append(static_cast< ::java::lang::Object* >(i))
        ->append(u","_j)
        ->append(val)
        ->append(u","_j)
        ->append(static_cast< ::java::lang::Object* >(options))
        ->append(u")"_j)->toString());
}

void org::mpisws::p2p::testing::filetransfer::ProfileFileTest_main_3::livenessChanged(::java::lang::Object* i, int32_t val, ::java::util::Map* options)
{ 
    livenessChanged(dynamic_cast< ::java::net::InetSocketAddress* >(i), val, options);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::testing::filetransfer::ProfileFileTest_main_3::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::testing::filetransfer::ProfileFileTest_main_3::getClass0()
{
    return class_();
}

