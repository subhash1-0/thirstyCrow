// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/simpleidentity/MutableInetSocketAddressStrategy.java
#include <org/mpisws/p2p/transport/simpleidentity/MutableInetSocketAddressStrategy.hpp>

#include <java/io/PrintStream.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/System.hpp>
#include <java/net/InetAddress.hpp>
#include <java/net/InetSocketAddress.hpp>
#include <org/mpisws/p2p/transport/simpleidentity/Serializer.hpp>
#include <rice/p2p/util/rawserialization/SimpleOutputBuffer.hpp>
#include <Array.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::transport::simpleidentity::MutableInetSocketAddressStrategy::MutableInetSocketAddressStrategy(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::transport::simpleidentity::MutableInetSocketAddressStrategy::MutableInetSocketAddressStrategy(int32_t port, Serializer* serializer) 
    : MutableInetSocketAddressStrategy(*static_cast< ::default_init_tag* >(0))
{
    ctor(port,serializer);
}

void org::mpisws::p2p::transport::simpleidentity::MutableInetSocketAddressStrategy::ctor(int32_t port, Serializer* serializer)
{
    super::ctor();
    this->serializer = serializer;
    this->port = port;
}

int8_tArray* org::mpisws::p2p::transport::simpleidentity::MutableInetSocketAddressStrategy::getLocalIdentifierBytes() /* throws(IOException) */
{
    auto newAddr = getLocalAddress();
    if(lastLocalAddress == nullptr || npc(newAddr)->equals(static_cast< ::java::lang::Object* >(lastLocalAddress))) {
        lastLocalAddress = newAddr;
        lastBytes = serializeAddress(new ::java::net::InetSocketAddress(newAddr, port));
    }
    return lastBytes;
}

int8_tArray* org::mpisws::p2p::transport::simpleidentity::MutableInetSocketAddressStrategy::serializeAddress(::java::net::InetSocketAddress* addr) /* throws(IOException) */
{
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"Address changed to "_j)->append(static_cast< ::java::lang::Object* >(addr))->toString());
    auto sob = new ::rice::p2p::util::rawserialization::SimpleOutputBuffer();
    npc(serializer)->serialize(addr, sob);
    return npc(sob)->getBytes();
}

java::net::InetAddress* org::mpisws::p2p::transport::simpleidentity::MutableInetSocketAddressStrategy::getLocalAddress() /* throws(IOException) */
{
    return ::java::net::InetAddress::getLocalHost();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::simpleidentity::MutableInetSocketAddressStrategy::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.simpleidentity.MutableInetSocketAddressStrategy", 72);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::simpleidentity::MutableInetSocketAddressStrategy::getClass0()
{
    return class_();
}

