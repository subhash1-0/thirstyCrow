// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/direct/DirectAppSocket.java
#include <org/mpisws/p2p/transport/direct/DirectAppSocket_DirectAppSocketEndpoint_write_2.hpp>

#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <org/mpisws/p2p/transport/direct/DirectAppSocket_DirectAppSocketEndpoint.hpp>
#include <Array.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::transport::direct::DirectAppSocket_DirectAppSocketEndpoint_write_2::DirectAppSocket_DirectAppSocketEndpoint_write_2(DirectAppSocket_DirectAppSocketEndpoint *DirectAppSocket_DirectAppSocketEndpoint_this, ::int8_tArray* msg)
    : super(*static_cast< ::default_init_tag* >(0))
    , DirectAppSocket_DirectAppSocketEndpoint_this(DirectAppSocket_DirectAppSocketEndpoint_this)
    , msg(msg)
{
    clinit();
    init();
    ctor();
}

void org::mpisws::p2p::transport::direct::DirectAppSocket_DirectAppSocketEndpoint_write_2::init()
{
    mySeq = DirectAppSocket_DirectAppSocketEndpoint_this->seq++;
}

void org::mpisws::p2p::transport::direct::DirectAppSocket_DirectAppSocketEndpoint_write_2::deliver()
{
    npc(DirectAppSocket_DirectAppSocketEndpoint_this->counterpart)->addToReadQueue(msg);
}

int32_t org::mpisws::p2p::transport::direct::DirectAppSocket_DirectAppSocketEndpoint_write_2::getSeq()
{
    return mySeq;
}

java::lang::String* org::mpisws::p2p::transport::direct::DirectAppSocket_DirectAppSocketEndpoint_write_2::toString()
{
    return ::java::lang::StringBuilder().append(DirectAppSocket_DirectAppSocketEndpoint_this->toString())->append(u" deliver msg "_j)
        ->append(static_cast< ::java::lang::Object* >(msg))->toString();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::direct::DirectAppSocket_DirectAppSocketEndpoint_write_2::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::direct::DirectAppSocket_DirectAppSocketEndpoint_write_2::getClass0()
{
    return class_();
}

