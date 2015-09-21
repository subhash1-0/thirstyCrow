// Generated from /pastry-2.1/src/rice/tutorial/ssl/DistTutorial.java
#include <rice/tutorial/ssl/DistTutorial_DistTutorial_1_getBindStrategy_1_1.hpp>

#include <java/io/PrintStream.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/System.hpp>
#include <java/util/Map.hpp>
#include <org/mpisws/p2p/transport/sourceroute/SourceRoute.hpp>
#include <org/mpisws/p2p/transport/ssl/SSLTransportLayer.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/pastry/socket/TransportLayerNodeHandle.hpp>
#include <rice/tutorial/ssl/DistTutorial_DistTutorial_1.hpp>

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

rice::tutorial::ssl::DistTutorial_DistTutorial_1_getBindStrategy_1_1::DistTutorial_DistTutorial_1_getBindStrategy_1_1(DistTutorial_DistTutorial_1 *DistTutorial_DistTutorial_1_this)
    : super(*static_cast< ::default_init_tag* >(0))
    , DistTutorial_DistTutorial_1_this(DistTutorial_DistTutorial_1_this)
{
    clinit();
    ctor();
}

bool rice::tutorial::ssl::DistTutorial_DistTutorial_1_getBindStrategy_1_1::accept(::rice::pastry::socket::TransportLayerNodeHandle* u, ::org::mpisws::p2p::transport::sourceroute::SourceRoute* l, ::java::util::Map* options)
{
    auto idName = java_cast< ::java::lang::String* >(java_cast< ::java::lang::Object* >(npc(options)->get(::org::mpisws::p2p::transport::ssl::SSLTransportLayer::OPTION_CERT_SUBJECT())));
    if(idName != nullptr) {
        if(npc(npc(npc(u)->getId())->toStringFull())->equals(static_cast< ::java::lang::Object* >(idName))) {
            return true;
        } else {
            npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"Rejecting id:"_j)->append(static_cast< ::java::lang::Object* >(u))
                ->append(u" which does not match the certificate entry:"_j)
                ->append(idName)->toString());
            return false;
        }
    }
    return true;
}

bool rice::tutorial::ssl::DistTutorial_DistTutorial_1_getBindStrategy_1_1::accept(::java::lang::Object* u, ::java::lang::Object* l, ::java::util::Map* options)
{ 
    return accept(dynamic_cast< ::rice::pastry::socket::TransportLayerNodeHandle* >(u), dynamic_cast< ::org::mpisws::p2p::transport::sourceroute::SourceRoute* >(l), options);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::tutorial::ssl::DistTutorial_DistTutorial_1_getBindStrategy_1_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::tutorial::ssl::DistTutorial_DistTutorial_1_getBindStrategy_1_1::getClass0()
{
    return class_();
}

