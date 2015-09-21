// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/multiaddress/MultiInetSocketAddress.java
#include <org/mpisws/p2p/transport/multiaddress/MultiInetSocketAddress.hpp>

#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuffer.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/net/InetAddress.hpp>
#include <java/net/InetSocketAddress.hpp>
#include <java/net/SocketAddress.hpp>
#include <java/util/Map.hpp>
#include <org/mpisws/p2p/transport/simpleidentity/InetSocketAddressSerializer.hpp>
#include <rice/p2p/commonapi/rawserialization/InputBuffer.hpp>
#include <rice/p2p/commonapi/rawserialization/OutputBuffer.hpp>
#include <SubArray.hpp>
#include <ObjectArray.hpp>

template<typename ComponentType, typename... Bases> struct SubArray;
namespace java
{
    namespace io
    {
typedef ::SubArray< ::java::io::Serializable, ::java::lang::ObjectArray > SerializableArray;
    } // io

    namespace net
    {
typedef ::SubArray< ::java::net::SocketAddress, ::java::lang::ObjectArray, ::java::io::SerializableArray > SocketAddressArray;
typedef ::SubArray< ::java::net::InetSocketAddress, SocketAddressArray > InetSocketAddressArray;
    } // net
} // java

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

org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress::MultiInetSocketAddress(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress::MultiInetSocketAddress(::java::net::InetSocketAddress* address) 
    : MultiInetSocketAddress(*static_cast< ::default_init_tag* >(0))
{
    ctor(address);
}

org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress::MultiInetSocketAddress(::java::net::InetSocketAddressArray* addressList) 
    : MultiInetSocketAddress(*static_cast< ::default_init_tag* >(0))
{
    ctor(addressList);
}

org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress::MultiInetSocketAddress(::java::net::InetSocketAddress* outer, ::java::net::InetSocketAddress* inner) 
    : MultiInetSocketAddress(*static_cast< ::default_init_tag* >(0))
{
    ctor(outer,inner);
}

org::mpisws::p2p::transport::simpleidentity::InetSocketAddressSerializer*& org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress::serializer()
{
    clinit();
    return serializer_;
}
org::mpisws::p2p::transport::simpleidentity::InetSocketAddressSerializer* org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress::serializer_;

void org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress::ctor(::java::net::InetSocketAddress* address)
{
    ctor(new ::java::net::InetSocketAddressArray({address}));
}

void org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress::ctor(::java::net::InetSocketAddressArray* addressList)
{
    super::ctor();
    this->address = addressList;
}

void org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress::ctor(::java::net::InetSocketAddress* outer, ::java::net::InetSocketAddress* inner)
{
    ctor(new ::java::net::InetSocketAddressArray({
        outer
        , inner
    }));
}

int32_t org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress::hashCode()
{
    auto result = int32_t(31173);
    for (auto i = int32_t(0); i < npc(address)->length; i++) {
        result ^= npc((*address)[i])->hashCode();
    }
    return result;
}

bool org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress::equals(::java::lang::Object* o)
{
    if(o == nullptr)
        return false;

    if(!(dynamic_cast< MultiInetSocketAddress* >(o) != nullptr))
        return false;

    auto that = java_cast< MultiInetSocketAddress* >(o);
    return addressEquals(that);
}

bool org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress::addressEquals(MultiInetSocketAddress* that)
{
    if(npc(this->address)->length != npc(npc(that)->address)->length) {
        if(npc(npc(that)->getInnermostAddress())->equals(static_cast< ::java::lang::Object* >(this->getInnermostAddress()))) {
            return true;
        }
        return false;
    }
    for (auto ctr = int32_t(0); ctr < npc(this->address)->length; ctr++) {
        if(!npc((*this->address)[ctr])->equals(static_cast< ::java::lang::Object* >((*npc(that)->address)[ctr])))
            return false;

    }
    return true;
}

java::lang::String* org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress::toString()
{
    auto s = u""_j;
    for (auto ctr = int32_t(0); ctr < npc(address)->length; ctr++) {
        s = ::java::lang::StringBuilder(s).append(static_cast< ::java::lang::Object* >((*address)[ctr]))->toString();
        if(ctr < npc(address)->length - int32_t(1))
            s = ::java::lang::StringBuilder(s).append(u":"_j)->toString();

    }
    return s;
}

void org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress::toStringShort(::java::lang::StringBuffer* result)
{
    for (auto ctr = int32_t(0); ctr < npc(address)->length; ctr++) {
        auto theAddr = (*address)[ctr];
        auto theAddr2 = npc(theAddr)->getAddress();
        if(theAddr2 == nullptr) {
            npc(result)->append(npc(theAddr)->toString());
        } else {
            auto ha = npc(theAddr2)->getHostAddress();
            npc(result)->append(::java::lang::StringBuilder().append(ha)->append(u":"_j)
                ->append(npc(theAddr)->getPort())->toString());
        }
        if(ctr < npc(address)->length - int32_t(1))
            npc(result)->append(u";"_j);

    }
}

java::net::InetSocketAddress* org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress::getInnermostAddress()
{
    return (*address)[npc(address)->length - int32_t(1)];
}

java::net::InetSocketAddress* org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress::getOutermostAddress()
{
    return (*address)[int32_t(0)];
}

int32_t org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress::getNumAddresses()
{
    return npc(address)->length;
}

java::net::InetSocketAddress* org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress::getAddress(int32_t index)
{
    return (*address)[index];
}

org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress::build(::rice::p2p::commonapi::rawserialization::InputBuffer* buf) /* throws(IOException) */
{
    clinit();
    auto numAddresses = npc(buf)->readByte();
    auto saddr = new ::java::net::InetSocketAddressArray(numAddresses);
    for (auto ctr = int32_t(0); ctr < numAddresses; ctr++) {
        saddr->set(ctr, npc(serializer_)->deserialize(buf, static_cast< ::java::net::InetSocketAddress* >(nullptr), static_cast< ::java::util::Map* >(nullptr)));
    }
    return new MultiInetSocketAddress(saddr);
}

void org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress::serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */
{
    npc(buf)->writeByte(static_cast< int8_t >(npc(address)->length));
    for (auto ctr = int32_t(0); ctr < npc(address)->length; ctr++) {
        npc(serializer_)->serialize((*address)[ctr], buf);
    }
}

int16_t org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress::getSerializedLength()
{
    auto ret = int32_t(1);
    for (auto ctr = int32_t(0); ctr < npc(address)->length; ctr++) {
        ret += npc(serializer_)->getSerializedLength((*address)[ctr]);
    }
    return static_cast< int16_t >(ret);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.multiaddress.MultiInetSocketAddress", 60);
    return c;
}

void org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress::clinit()
{
    super::clinit();
    static bool in_cl_init = false;
struct clinit_ {
    clinit_() {
        in_cl_init = true;
        serializer_ = new ::org::mpisws::p2p::transport::simpleidentity::InetSocketAddressSerializer();
    }
};

    if(!in_cl_init) {
        static clinit_ clinit_instance;
    }
}

java::lang::Class* org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress::getClass0()
{
    return class_();
}

