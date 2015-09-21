// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/direct/DirectAppSocket.java
#include <org/mpisws/p2p/transport/direct/DirectAppSocket_DirectAppSocketEndpoint_shutdownOutput_5.hpp>

#include <java/lang/NullPointerException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <org/mpisws/p2p/transport/direct/DirectAppSocket_DirectAppSocketEndpoint.hpp>
#include <org/mpisws/p2p/transport/direct/DirectAppSocket.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::transport::direct::DirectAppSocket_DirectAppSocketEndpoint_shutdownOutput_5::DirectAppSocket_DirectAppSocketEndpoint_shutdownOutput_5(DirectAppSocket_DirectAppSocketEndpoint *DirectAppSocket_DirectAppSocketEndpoint_this)
    : super(*static_cast< ::default_init_tag* >(0))
    , DirectAppSocket_DirectAppSocketEndpoint_this(DirectAppSocket_DirectAppSocketEndpoint_this)
{
    clinit();
    init();
    ctor();
}

void org::mpisws::p2p::transport::direct::DirectAppSocket_DirectAppSocketEndpoint_shutdownOutput_5::init()
{
    mySeq = DirectAppSocket_DirectAppSocketEndpoint_this->seq++;
}

void org::mpisws::p2p::transport::direct::DirectAppSocket_DirectAppSocketEndpoint_shutdownOutput_5::deliver()
{
    npc(DirectAppSocket_DirectAppSocketEndpoint_this->counterpart)->addToReadQueue(DirectAppSocket::EOF_());
}

int32_t org::mpisws::p2p::transport::direct::DirectAppSocket_DirectAppSocketEndpoint_shutdownOutput_5::getSeq()
{
    return mySeq;
}

java::lang::String* org::mpisws::p2p::transport::direct::DirectAppSocket_DirectAppSocketEndpoint_shutdownOutput_5::toString()
{
    return ::java::lang::StringBuilder().append(DirectAppSocket_DirectAppSocketEndpoint_this->toString())->append(u" counterpart shutDownOutput()"_j)->toString();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::direct::DirectAppSocket_DirectAppSocketEndpoint_shutdownOutput_5::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::direct::DirectAppSocket_DirectAppSocketEndpoint_shutdownOutput_5::getClass0()
{
    return class_();
}

