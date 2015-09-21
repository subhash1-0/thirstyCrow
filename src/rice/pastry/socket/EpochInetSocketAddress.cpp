// Generated from /pastry-2.1/src/rice/pastry/socket/EpochInetSocketAddress.java
#include <rice/pastry/socket/EpochInetSocketAddress.hpp>

#include <java/io/Serializable.hpp>
#include <java/lang/ArrayIndexOutOfBoundsException.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/RuntimeException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/net/InetAddress.hpp>
#include <java/net/InetSocketAddress.hpp>
#include <java/net/SocketAddress.hpp>
#include <rice/p2p/commonapi/rawserialization/InputBuffer.hpp>
#include <rice/p2p/commonapi/rawserialization/OutputBuffer.hpp>
#include <Array.hpp>
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
typedef ::SubArray< ::java::net::InetAddress, ::java::lang::ObjectArray, ::java::io::SerializableArray > InetAddressArray;
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

rice::pastry::socket::EpochInetSocketAddress::EpochInetSocketAddress(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::socket::EpochInetSocketAddress::EpochInetSocketAddress(::java::net::InetSocketAddress* address) 
    : EpochInetSocketAddress(*static_cast< ::default_init_tag* >(0))
{
    ctor(address);
}

rice::pastry::socket::EpochInetSocketAddress::EpochInetSocketAddress(::java::net::InetSocketAddress* address, int64_t epoch) 
    : EpochInetSocketAddress(*static_cast< ::default_init_tag* >(0))
{
    ctor(address,epoch);
}

rice::pastry::socket::EpochInetSocketAddress::EpochInetSocketAddress(::java::net::InetSocketAddressArray* addressList, int64_t epoch) 
    : EpochInetSocketAddress(*static_cast< ::default_init_tag* >(0))
{
    ctor(addressList,epoch);
}

constexpr int64_t rice::pastry::socket::EpochInetSocketAddress::serialVersionUID;

constexpr int64_t rice::pastry::socket::EpochInetSocketAddress::EPOCH_UNKNOWN;

void rice::pastry::socket::EpochInetSocketAddress::ctor(::java::net::InetSocketAddress* address)
{
    ctor(address, EPOCH_UNKNOWN);
}

void rice::pastry::socket::EpochInetSocketAddress::ctor(::java::net::InetSocketAddress* address, int64_t epoch)
{
    ctor(new ::java::net::InetSocketAddressArray({address}), epoch);
}

void rice::pastry::socket::EpochInetSocketAddress::ctor(::java::net::InetSocketAddressArray* addressList, int64_t epoch)
{
    super::ctor();
    this->address = addressList;
    this->epoch = epoch;
}

int32_t rice::pastry::socket::EpochInetSocketAddress::hashCode()
{
    auto result = static_cast< int32_t >(epoch);
    for (auto i = int32_t(0); i < npc(address)->length; i++) {
        result ^= npc((*address)[i])->hashCode();
    }
    return result;
}

bool rice::pastry::socket::EpochInetSocketAddress::equals(::java::lang::Object* o)
{
    if(o == nullptr)
        return false;

    if(!(dynamic_cast< EpochInetSocketAddress* >(o) != nullptr))
        return false;

    auto that = java_cast< EpochInetSocketAddress* >(o);
    if(this->epoch != npc(that)->epoch)
        return false;

    return addressEquals(that);
}

bool rice::pastry::socket::EpochInetSocketAddress::addressEquals(EpochInetSocketAddress* that)
{
    if(npc(this->address)->length != npc(npc(that)->address)->length)
        return false;

    for (auto ctr = int32_t(0); ctr < npc(this->address)->length; ctr++) {
        if(!npc((*this->address)[ctr])->equals(static_cast< ::java::lang::Object* >((*npc(that)->address)[ctr])))
            return false;

    }
    return true;
}

java::lang::String* rice::pastry::socket::EpochInetSocketAddress::toString()
{
    auto s = u""_j;
    for (auto ctr = int32_t(0); ctr < npc(address)->length; ctr++) {
        s = ::java::lang::StringBuilder(s).append(static_cast< ::java::lang::Object* >((*address)[ctr]))->toString();
        if(ctr < npc(address)->length - int32_t(1))
            s = ::java::lang::StringBuilder(s).append(u":"_j)->toString();

    }
    return ::java::lang::StringBuilder().append(s)->append(u" ["_j)
        ->append(epoch)
        ->append(u"]"_j)->toString();
}

java::net::InetSocketAddress* rice::pastry::socket::EpochInetSocketAddress::getAddress(EpochInetSocketAddress* local)
{
    try {
        for (auto ctr = int32_t(0); ctr < npc(address)->length; ctr++) {
            if(!npc(npc((*address)[ctr])->getAddress())->equals(static_cast< ::java::lang::Object* >(npc((*npc(local)->address)[ctr])->getAddress()))) {
                return (*address)[ctr];
            }
        }
    } catch (::java::lang::ArrayIndexOutOfBoundsException* aioobe) {
        throw new ::java::lang::RuntimeException(::java::lang::StringBuilder().append(u"ArrayIndexOutOfBoundsException in "_j)->append(static_cast< ::java::lang::Object* >(this))
            ->append(u".getAddress("_j)
            ->append(static_cast< ::java::lang::Object* >(local))
            ->append(u")"_j)->toString(), aioobe);
    }
    return (*address)[npc(address)->length - int32_t(1)];
}

java::net::InetSocketAddress* rice::pastry::socket::EpochInetSocketAddress::getAddress(::java::net::InetAddressArray* local)
{
    try {
        for (auto ctr = int32_t(0); ctr < npc(address)->length; ctr++) {
            if(!npc(npc((*address)[ctr])->getAddress())->equals(static_cast< ::java::lang::Object* >((*local)[ctr]))) {
                return (*address)[ctr];
            }
        }
    } catch (::java::lang::ArrayIndexOutOfBoundsException* aioobe) {
        auto s = u""_j;
        for (auto ctr = int32_t(0); ctr < npc(local)->length; ctr++) {
            s = ::java::lang::StringBuilder(s).append(static_cast< ::java::lang::Object* >((*local)[ctr]))->toString();
            if(ctr < npc(local)->length - int32_t(1))
                s = ::java::lang::StringBuilder(s).append(u":"_j)->toString();

        }
        throw new ::java::lang::RuntimeException(::java::lang::StringBuilder().append(u"ArrayIndexOutOfBoundsException in "_j)->append(static_cast< ::java::lang::Object* >(this))
            ->append(u".getAddress("_j)
            ->append(npc(local)->length)
            ->append(u")"_j)->toString(), aioobe);
    }
    return (*address)[npc(address)->length - int32_t(1)];
}

java::net::InetSocketAddress* rice::pastry::socket::EpochInetSocketAddress::getInnermostAddress()
{
    return (*address)[npc(address)->length - int32_t(1)];
}

int64_t rice::pastry::socket::EpochInetSocketAddress::getEpoch()
{
    return epoch;
}

rice::pastry::socket::EpochInetSocketAddress* rice::pastry::socket::EpochInetSocketAddress::build(::rice::p2p::commonapi::rawserialization::InputBuffer* buf) /* throws(IOException) */
{
    clinit();
    auto numAddresses = npc(buf)->readByte();
    auto saddr = new ::java::net::InetSocketAddressArray(numAddresses);
    for (auto ctr = int32_t(0); ctr < numAddresses; ctr++) {
        auto addrBytes = new ::int8_tArray(int32_t(4));
        npc(buf)->read(addrBytes);
        auto addr = ::java::net::InetAddress::getByAddress(addrBytes);
        auto port = npc(buf)->readShort();
        saddr->set(ctr, new ::java::net::InetSocketAddress(addr, int32_t(65535) & port));
    }
    auto epoch = npc(buf)->readLong();
    return new EpochInetSocketAddress(saddr, epoch);
}

void rice::pastry::socket::EpochInetSocketAddress::serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */
{
    npc(buf)->writeByte(static_cast< int8_t >(npc(address)->length));
    for (auto ctr = int32_t(0); ctr < npc(address)->length; ctr++) {
        npc(buf)->write(npc(npc((*address)[ctr])->getAddress())->getAddress(), 0, 4);
        npc(buf)->writeShort(static_cast< int16_t >(npc((*address)[ctr])->getPort()));
    }
    npc(buf)->writeLong(epoch);
}

int16_t rice::pastry::socket::EpochInetSocketAddress::getSerializedLength()
{
    return static_cast< int16_t >((int32_t(8) + int32_t(1) + (npc(address)->length * int32_t(6))));
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::socket::EpochInetSocketAddress::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.socket.EpochInetSocketAddress", 41);
    return c;
}

java::lang::Class* rice::pastry::socket::EpochInetSocketAddress::getClass0()
{
    return class_();
}

