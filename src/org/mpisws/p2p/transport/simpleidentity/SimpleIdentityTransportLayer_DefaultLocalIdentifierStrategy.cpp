// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/simpleidentity/SimpleIdentityTransportLayer.java
#include <org/mpisws/p2p/transport/simpleidentity/SimpleIdentityTransportLayer_DefaultLocalIdentifierStrategy.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/TransportLayer.hpp>
#include <org/mpisws/p2p/transport/simpleidentity/Serializer.hpp>
#include <org/mpisws/p2p/transport/simpleidentity/SimpleIdentityTransportLayer.hpp>
#include <rice/p2p/util/rawserialization/SimpleOutputBuffer.hpp>
#include <Array.hpp>

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

org::mpisws::p2p::transport::simpleidentity::SimpleIdentityTransportLayer_DefaultLocalIdentifierStrategy::SimpleIdentityTransportLayer_DefaultLocalIdentifierStrategy(SimpleIdentityTransportLayer *SimpleIdentityTransportLayer_this, const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
    , SimpleIdentityTransportLayer_this(SimpleIdentityTransportLayer_this)
{
    clinit();
}

org::mpisws::p2p::transport::simpleidentity::SimpleIdentityTransportLayer_DefaultLocalIdentifierStrategy::SimpleIdentityTransportLayer_DefaultLocalIdentifierStrategy(SimpleIdentityTransportLayer *SimpleIdentityTransportLayer_this, ::java::lang::Object* i)  /* throws(IOException) */
    : SimpleIdentityTransportLayer_DefaultLocalIdentifierStrategy(SimpleIdentityTransportLayer_this, *static_cast< ::default_init_tag* >(0))
{
    ctor(i);
}

void org::mpisws::p2p::transport::simpleidentity::SimpleIdentityTransportLayer_DefaultLocalIdentifierStrategy::ctor(::java::lang::Object* i) /* throws(IOException) */
{
    super::ctor();
    auto sob = new ::rice::p2p::util::rawserialization::SimpleOutputBuffer();
    npc(SimpleIdentityTransportLayer_this->serializer)->serialize(java_cast< ::java::lang::Object* >(npc(SimpleIdentityTransportLayer_this->tl)->getLocalIdentifier()), sob);
    localIdentifierBytes = npc(sob)->getBytes();
}

int8_tArray* org::mpisws::p2p::transport::simpleidentity::SimpleIdentityTransportLayer_DefaultLocalIdentifierStrategy::getLocalIdentifierBytes()
{
    return localIdentifierBytes;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::simpleidentity::SimpleIdentityTransportLayer_DefaultLocalIdentifierStrategy::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.simpleidentity.SimpleIdentityTransportLayer.DefaultLocalIdentifierStrategy", 99);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::simpleidentity::SimpleIdentityTransportLayer_DefaultLocalIdentifierStrategy::getClass0()
{
    return class_();
}

