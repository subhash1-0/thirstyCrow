// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/direct/DirectAppSocket.java
#include <org/mpisws/p2p/transport/direct/DirectAppSocket_DirectAppSocketEndpoint_read_1.hpp>

#include <java/lang/NullPointerException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <org/mpisws/p2p/transport/direct/DirectAppSocket_DirectAppSocketEndpoint.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::transport::direct::DirectAppSocket_DirectAppSocketEndpoint_read_1::DirectAppSocket_DirectAppSocketEndpoint_read_1(DirectAppSocket_DirectAppSocketEndpoint *DirectAppSocket_DirectAppSocketEndpoint_this)
    : super(*static_cast< ::default_init_tag* >(0))
    , DirectAppSocket_DirectAppSocketEndpoint_this(DirectAppSocket_DirectAppSocketEndpoint_this)
{
    clinit();
    ctor();
}

void org::mpisws::p2p::transport::direct::DirectAppSocket_DirectAppSocketEndpoint_read_1::deliver()
{
    npc(DirectAppSocket_DirectAppSocketEndpoint_this->counterpart)->notifyCanWrite();
}

int32_t org::mpisws::p2p::transport::direct::DirectAppSocket_DirectAppSocketEndpoint_read_1::getSeq()
{
    return 0;
}

java::lang::String* org::mpisws::p2p::transport::direct::DirectAppSocket_DirectAppSocketEndpoint_read_1::toString()
{
    return ::java::lang::StringBuilder().append(DirectAppSocket_DirectAppSocketEndpoint_this->toString())->append(u" counterpart notifyCanWrite()"_j)->toString();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::direct::DirectAppSocket_DirectAppSocketEndpoint_read_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::direct::DirectAppSocket_DirectAppSocketEndpoint_read_1::getClass0()
{
    return class_();
}

