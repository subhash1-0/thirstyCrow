// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/direct/DirectAppSocket.java
#include <org/mpisws/p2p/transport/direct/DirectAppSocket_DirectAppSocketEndpoint_register_4.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <org/mpisws/p2p/transport/direct/DirectAppSocket_DirectAppSocketEndpoint.hpp>
#include <org/mpisws/p2p/transport/direct/DirectAppSocket.hpp>
#include <org/mpisws/p2p/transport/direct/GenericNetworkSimulator.hpp>

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

org::mpisws::p2p::transport::direct::DirectAppSocket_DirectAppSocketEndpoint_register_4::DirectAppSocket_DirectAppSocketEndpoint_register_4(DirectAppSocket_DirectAppSocketEndpoint *DirectAppSocket_DirectAppSocketEndpoint_this)
    : super(*static_cast< ::default_init_tag* >(0))
    , DirectAppSocket_DirectAppSocketEndpoint_this(DirectAppSocket_DirectAppSocketEndpoint_this)
{
    clinit();
    ctor();
}

void org::mpisws::p2p::transport::direct::DirectAppSocket_DirectAppSocketEndpoint_register_4::deliver()
{
    if(!npc(DirectAppSocket_DirectAppSocketEndpoint_this->DirectAppSocket_this->simulator)->isAlive(java_cast< ::java::lang::Object* >(DirectAppSocket_DirectAppSocketEndpoint_this->localNodeHandle)))
        return;

    DirectAppSocket_DirectAppSocketEndpoint_this->notifyCanRead();
}

int32_t org::mpisws::p2p::transport::direct::DirectAppSocket_DirectAppSocketEndpoint_register_4::getSeq()
{
    return 0;
}

java::lang::String* org::mpisws::p2p::transport::direct::DirectAppSocket_DirectAppSocketEndpoint_register_4::toString()
{
    return ::java::lang::StringBuilder().append(DirectAppSocket_DirectAppSocketEndpoint_this->toString())->append(u" notifyCanRead()"_j)->toString();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::direct::DirectAppSocket_DirectAppSocketEndpoint_register_4::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::direct::DirectAppSocket_DirectAppSocketEndpoint_register_4::getClass0()
{
    return class_();
}

