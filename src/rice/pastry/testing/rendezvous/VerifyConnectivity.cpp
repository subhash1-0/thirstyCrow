// Generated from /pastry-2.1/src/rice/pastry/testing/rendezvous/VerifyConnectivity.java
#include <rice/pastry/testing/rendezvous/VerifyConnectivity.hpp>

#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/CharSequence.hpp>
#include <java/lang/Comparable.hpp>
#include <java/lang/Integer.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/String.hpp>
#include <java/net/InetAddress.hpp>
#include <java/net/InetSocketAddress.hpp>
#include <java/util/Collections.hpp>
#include <java/util/Set.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/pastry/socket/SocketPastryNodeFactory.hpp>
#include <rice/pastry/socket/nat/connectivityverifiier/ConnectivityVerifier.hpp>
#include <rice/pastry/socket/nat/connectivityverifiier/ConnectivityVerifierImpl.hpp>
#include <rice/pastry/standard/RandomNodeIdFactory.hpp>
#include <rice/pastry/testing/rendezvous/VerifyConnectivity_main_1.hpp>
#include <SubArray.hpp>
#include <ObjectArray.hpp>

template<typename ComponentType, typename... Bases> struct SubArray;
namespace java
{
    namespace io
    {
typedef ::SubArray< ::java::io::Serializable, ::java::lang::ObjectArray > SerializableArray;
    } // io

    namespace lang
    {
typedef ::SubArray< ::java::lang::CharSequence, ObjectArray > CharSequenceArray;
typedef ::SubArray< ::java::lang::Comparable, ObjectArray > ComparableArray;
typedef ::SubArray< ::java::lang::String, ObjectArray, ::java::io::SerializableArray, ComparableArray, CharSequenceArray > StringArray;
    } // lang
} // java

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::pastry::testing::rendezvous::VerifyConnectivity::VerifyConnectivity(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::testing::rendezvous::VerifyConnectivity::VerifyConnectivity()
    : VerifyConnectivity(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

void rice::pastry::testing::rendezvous::VerifyConnectivity::main(::java::lang::StringArray* args) /* throws(IOException) */
{
    clinit();
    auto bindport = ::java::lang::Integer::parseInt((*args)[int32_t(0)]);
    auto const externalPort = ::java::lang::Integer::parseInt((*args)[int32_t(3)]);
    auto bootaddr = ::java::net::InetAddress::getByName((*args)[int32_t(1)]);
    auto bootport = ::java::lang::Integer::parseInt((*args)[int32_t(2)]);
    auto const bootaddress = new ::java::net::InetSocketAddress(bootaddr, bootport);
    auto const env = new ::rice::environment::Environment();
    ::rice::pastry::NodeIdFactory* nidFactory = new ::rice::pastry::standard::RandomNodeIdFactory(env);
    auto const factory = new ::rice::pastry::socket::SocketPastryNodeFactory(nidFactory, bindport, env);
    ::rice::pastry::socket::nat::connectivityverifiier::ConnectivityVerifier* const verifier = new ::rice::pastry::socket::nat::connectivityverifiier::ConnectivityVerifierImpl(factory);
    npc(verifier)->findExternalAddress(npc(factory)->getNextInetSocketAddress(), ::java::util::Collections::singleton(bootaddress), new VerifyConnectivity_main_1(externalPort, factory, verifier, bootaddress, env));
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::testing::rendezvous::VerifyConnectivity::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.testing.rendezvous.VerifyConnectivity", 49);
    return c;
}

java::lang::Class* rice::pastry::testing::rendezvous::VerifyConnectivity::getClass0()
{
    return class_();
}

