// Generated from /pastry-2.1/src/rice/pastry/socket/internet/InternetPastryNodeFactory.java
#include <rice/pastry/socket/internet/InternetPastryNodeFactory.hpp>

#include <java/io/IOException.hpp>
#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/Class.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/ClassNotFoundException.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/NoClassDefFoundError.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/RuntimeException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/Throwable.hpp>
#include <java/lang/reflect/AnnotatedElement.hpp>
#include <java/lang/reflect/Constructor.hpp>
#include <java/lang/reflect/GenericDeclaration.hpp>
#include <java/lang/reflect/InvocationTargetException.hpp>
#include <java/lang/reflect/Type.hpp>
#include <java/net/BindException.hpp>
#include <java/net/InetAddress.hpp>
#include <java/net/InetSocketAddress.hpp>
#include <java/net/UnknownHostException.hpp>
#include <java/util/ArrayList.hpp>
#include <java/util/Collection.hpp>
#include <java/util/Iterator.hpp>
#include <java/util/Map.hpp>
#include <org/mpisws/p2p/transport/multiaddress/MultiInetSocketAddress.hpp>
#include <rice/Continuation.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/environment/params/Parameters.hpp>
#include <rice/p2p/commonapi/Cancellable.hpp>
#include <rice/pastry/socket/internet/InternetPastryNodeFactory_findExternalNodes_1.hpp>
#include <rice/pastry/socket/internet/InternetPastryNodeFactory_findExternalAddressHelper_2.hpp>
#include <rice/pastry/socket/internet/InternetPastryNodeFactory_verifyConnectivityThenMakeNewNode_3.hpp>
#include <rice/pastry/socket/internet/InternetPastryNodeFactory_verifyConnectivityThenMakeNewNode_4.hpp>
#include <rice/pastry/socket/nat/CantFindFirewallException.hpp>
#include <rice/pastry/socket/nat/NATHandler.hpp>
#include <rice/pastry/socket/nat/StubNATHandler.hpp>
#include <rice/pastry/socket/nat/connectivityverifiier/ConnectivityVerifier.hpp>
#include <rice/pastry/socket/nat/connectivityverifiier/ConnectivityVerifierImpl.hpp>
#include <rice/selector/SelectorManager.hpp>
#include <rice/selector/Timer.hpp>
#include <SubArray.hpp>
#include <ObjectArray.hpp>
#include <Array.hpp>

template<typename ComponentType, typename... Bases> struct SubArray;
namespace java
{
    namespace io
    {
typedef ::SubArray< ::java::io::Serializable, ::java::lang::ObjectArray > SerializableArray;
    } // io

    namespace lang
    {
        namespace reflect
        {
typedef ::SubArray< ::java::lang::reflect::AnnotatedElement, ::java::lang::ObjectArray > AnnotatedElementArray;
typedef ::SubArray< ::java::lang::reflect::GenericDeclaration, ::java::lang::ObjectArray, AnnotatedElementArray > GenericDeclarationArray;
typedef ::SubArray< ::java::lang::reflect::Type, ::java::lang::ObjectArray > TypeArray;
        } // reflect
typedef ::SubArray< ::java::lang::Class, ObjectArray, ::java::io::SerializableArray, ::java::lang::reflect::GenericDeclarationArray, ::java::lang::reflect::TypeArray, ::java::lang::reflect::AnnotatedElementArray > ClassArray;
    } // lang

    namespace net
    {
typedef ::SubArray< ::java::net::InetAddress, ::java::lang::ObjectArray, ::java::io::SerializableArray > InetAddressArray;
    } // net
} // java

namespace rice
{
    namespace p2p
    {
        namespace commonapi
        {
typedef ::SubArray< ::rice::p2p::commonapi::Cancellable, ::java::lang::ObjectArray > CancellableArray;
        } // commonapi
    } // p2p
} // rice

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

rice::pastry::socket::internet::InternetPastryNodeFactory::InternetPastryNodeFactory(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::socket::internet::InternetPastryNodeFactory::InternetPastryNodeFactory(::rice::pastry::NodeIdFactory* nf, int32_t startPort, ::rice::environment::Environment* env)  /* throws(IOException) */
    : InternetPastryNodeFactory(*static_cast< ::default_init_tag* >(0))
{
    ctor(nf,startPort,env);
}

rice::pastry::socket::internet::InternetPastryNodeFactory::InternetPastryNodeFactory(::rice::pastry::NodeIdFactory* nf, ::java::net::InetAddress* bindAddress, int32_t startPort, ::rice::environment::Environment* env, ::rice::pastry::socket::nat::NATHandler* handler, ::java::util::Collection* probeAddresses, ::java::net::InetAddressArray* externalAddresses)  /* throws(IOException) */
    : InternetPastryNodeFactory(*static_cast< ::default_init_tag* >(0))
{
    ctor(nf,bindAddress,startPort,env,handler,probeAddresses,externalAddresses);
}

constexpr int32_t rice::pastry::socket::internet::InternetPastryNodeFactory::ALWAYS;

constexpr int32_t rice::pastry::socket::internet::InternetPastryNodeFactory::PREFIX_MATCH;

constexpr int32_t rice::pastry::socket::internet::InternetPastryNodeFactory::NEVER;

constexpr int32_t rice::pastry::socket::internet::InternetPastryNodeFactory::BOOT;

constexpr int32_t rice::pastry::socket::internet::InternetPastryNodeFactory::OVERWRITE;

constexpr int32_t rice::pastry::socket::internet::InternetPastryNodeFactory::USE_DIFFERENT_PORT;

constexpr int32_t rice::pastry::socket::internet::InternetPastryNodeFactory::FAIL;

constexpr int32_t rice::pastry::socket::internet::InternetPastryNodeFactory::RENDEZVOUS;

void rice::pastry::socket::internet::InternetPastryNodeFactory::ctor(::rice::pastry::NodeIdFactory* nf, int32_t startPort, ::rice::environment::Environment* env) /* throws(IOException) */
{
    ctor(nf, nullptr, startPort, env, nullptr, nullptr, nullptr);
}

void rice::pastry::socket::internet::InternetPastryNodeFactory::ctor(::rice::pastry::NodeIdFactory* nf, ::java::net::InetAddress* bindAddress, int32_t startPort, ::rice::environment::Environment* env, ::rice::pastry::socket::nat::NATHandler* handler, ::java::util::Collection* probeAddresses, ::java::net::InetAddressArray* externalAddresses) /* throws(IOException) */
{
    super::ctor(nf, bindAddress, startPort, env, false);
    auto params = npc(env)->getParameters();
    this->natHandler = handler;
    if(natHandler == nullptr) {
        this->natHandler = getDefaultNatHandler(env, this->localAddress);
    }
    this->probeAddresses = probeAddresses;
    this->externalAddresses = externalAddresses;
    if(npc(params)->contains(u"external_address"_j)) {
        externalAddresses = new ::java::net::InetAddressArray(int32_t(1));
        externalAddresses->set(int32_t(0), npc(npc(params)->getInetSocketAddress(u"external_address"_j))->getAddress());
    }
    this->connectivityVerifier = new ::rice::pastry::socket::nat::connectivityverifiier::ConnectivityVerifierImpl(this);
    findExternalAddressIfNecessary(this->localAddress);
}

rice::pastry::socket::nat::NATHandler* rice::pastry::socket::internet::InternetPastryNodeFactory::getDefaultNatHandler(::rice::environment::Environment* env, ::java::net::InetAddress* localAddress)
{
    auto params = npc(env)->getParameters();
    if(npc(params)->contains(u"nat_handler_class"_j)) {
        try {
            auto natHandlerClass = ::java::lang::Class::forName(npc(params)->getString(u"nat_handler_class"_j));
            auto args = (new ::java::lang::ClassArray({
                static_cast< ::java::lang::Class* >(::rice::environment::Environment::class_())
                , static_cast< ::java::lang::Class* >(::java::net::InetAddress::class_())
            }));
            auto constructor = npc(natHandlerClass)->getConstructor(args);
            auto foo = (new ::java::lang::ObjectArray({
                static_cast< ::java::lang::Object* >(env)
                , static_cast< ::java::lang::Object* >(localAddress)
            }));
            return java_cast< ::rice::pastry::socket::nat::NATHandler* >(java_cast< ::java::lang::Object* >(npc(constructor)->newInstance(foo)));
        } catch (::java::lang::ClassNotFoundException* e) {
            if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
                npc(logger)->log(u"Didn't find UPnP libs, skipping UPnP"_j);

            return new ::rice::pastry::socket::nat::StubNATHandler(env, localAddress);
        } catch (::java::lang::NoClassDefFoundError* e) {
            if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
                npc(logger)->log(u"Didn't find UPnP libs, skipping UPnP"_j);

            return new ::rice::pastry::socket::nat::StubNATHandler(env, localAddress);
        } catch (::java::lang::reflect::InvocationTargetException* e) {
            if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
                npc(logger)->log(u"Didn't find UPnP libs, skipping UPnP"_j);

            return new ::rice::pastry::socket::nat::StubNATHandler(env, localAddress);
        } catch (::java::lang::Exception* e) {
            if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                npc(logger)->logException(u"Error constructing NATHandler."_j, e);

            throw new ::java::lang::RuntimeException(static_cast< ::java::lang::Throwable* >(e));
        }
    } else {
        return new ::rice::pastry::socket::nat::StubNATHandler(env, localAddress);
    }
}

bool rice::pastry::socket::internet::InternetPastryNodeFactory::shouldFindExternalAddress(::java::net::InetAddress* address)
{
    switch (getFireWallPolicyVariable(u"nat_search_policy"_j)) {
    case NEVER:
        return false;
    case PREFIX_MATCH:
        return !isInternetRoutablePrefix(address);
    case ALWAYS:
        return true;
    }

    return true;
}

bool rice::pastry::socket::internet::InternetPastryNodeFactory::findExternalAddressIfNecessary(::java::net::InetAddress* address) /* throws(IOException) */
{
    if(!shouldFindExternalAddress(address))
        return true;

    try {
        npc(natHandler)->findFireWall(address);
    } catch (::rice::pastry::socket::nat::CantFindFirewallException* cffe) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
            npc(logger)->log(::java::lang::StringBuilder().append(u"Can't find firewall, continuing. For better performance, enable UPnP.  Will try to verify if user configured a port forward rule..."_j)->append(static_cast< ::java::lang::Object* >(cffe))->toString());

        return false;
    } catch (::java::io::IOException* ioe) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(logger)->log(npc(ioe)->toString());

        return false;
    }
    if(this->externalAddresses == nullptr) {
        this->externalAddresses = new ::java::net::InetAddressArray(int32_t(1));
        this->externalAddresses->set(int32_t(0), npc(natHandler)->getFireWallExternalAddress());
        if((*this->externalAddresses)[int32_t(0)] == nullptr) {
            return false;
        } else {
            return true;
        }
    } else {
        if(npc((*externalAddresses)[int32_t(0)])->equals(static_cast< ::java::lang::Object* >(npc(natHandler)->getFireWallExternalAddress()))) {
            return true;
        } else {
            throw new ::java::io::IOException(::java::lang::StringBuilder().append(u"Firewall disagrees with the externalAddresses. externalAddresses:"_j)->append(static_cast< ::java::lang::Object* >((*externalAddresses)[int32_t(0)]))
                ->append(u" firewall:"_j)
                ->append(static_cast< ::java::lang::Object* >(npc(natHandler)->getFireWallExternalAddress()))->toString());
        }
    }
}

void rice::pastry::socket::internet::InternetPastryNodeFactory::newNodeSelector(::rice::pastry::Id* nodeId, ::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* proxyAddress, ::rice::Continuation* deliverResultToMe, ::java::util::Map* initialVars)
{
    if(!npc(npc(npc(proxyAddress)->getInnermostAddress())->getAddress())->equals(static_cast< ::java::lang::Object* >(this->localAddress))) {
        throw new ::java::lang::RuntimeException(::java::lang::StringBuilder().append(u"proxyAddress.innermostAddress() must be the local bind address. proxyAddress:"_j)->append(static_cast< ::java::lang::Object* >(proxyAddress))
            ->append(u" bindAddress:"_j)
            ->append(static_cast< ::java::lang::Object* >(this->localAddress))->toString());
    }
    if(!shouldFindExternalAddress(npc(npc(proxyAddress)->getInnermostAddress())->getAddress())) {
        verifyConnectivityThenMakeNewNode(nodeId, proxyAddress, deliverResultToMe);
        return;
    }
    if(npc(proxyAddress)->getNumAddresses() > 2) {
        throw new ::java::lang::RuntimeException(::java::lang::StringBuilder().append(u"this factory only supports 1 layer deep NAT configurations try setting nat_search_policy = never if you are sure that your NAT configuration is "_j)->append(static_cast< ::java::lang::Object* >(proxyAddress))->toString());
    }
    if(npc(proxyAddress)->getNumAddresses() == 1) {
        findExternalAddress(nodeId, npc(proxyAddress)->getInnermostAddress(), deliverResultToMe);
    } else {
        openFirewallPort(nodeId, npc(proxyAddress)->getInnermostAddress(), deliverResultToMe, npc(npc(proxyAddress)->getOutermostAddress())->getAddress(), npc(npc(proxyAddress)->getOutermostAddress())->getPort());
    }
}

void rice::pastry::socket::internet::InternetPastryNodeFactory::findExternalAddress(::rice::pastry::Id* nodeId, ::java::net::InetSocketAddress* bindAddress, ::rice::Continuation* deliverResultToMe)
{
    if(npc(npc(environment)->getParameters())->contains(u"external_address"_j)) {
        try {
            auto pAddress = npc(npc(environment)->getParameters())->getInetSocketAddress(u"external_address"_j);
            openFirewallPort(nodeId, bindAddress, deliverResultToMe, npc(pAddress)->getAddress(), npc(pAddress)->getPort());
        } catch (::java::net::UnknownHostException* uhe) {
            npc(deliverResultToMe)->receiveException(uhe);
        }
    } else {
        ::java::util::Collection* myProbeAddresses = nullptr;
        ::java::util::Collection* nonInternetRoutable = nullptr;
        if(java_cast< ::java::util::Collection* >(this->probeAddresses) != nullptr) {
            myProbeAddresses = new ::java::util::ArrayList(static_cast< ::java::util::Collection* >(probeAddresses));
            nonInternetRoutable = new ::java::util::ArrayList();
            while (npc(myProbeAddresses)->remove(bindAddress)) 
                                ;

            auto i = npc(myProbeAddresses)->iterator();
            while (npc(i)->hasNext()) {
                auto foo = java_cast< ::java::net::InetSocketAddress* >(npc(i)->next());
                if(!isInternetRoutablePrefix(npc(foo)->getAddress())) {
                    npc(nonInternetRoutable)->add(foo);
                    npc(i)->remove();
                }
            }
        }
        if((myProbeAddresses == nullptr || npc(myProbeAddresses)->isEmpty()) && (nonInternetRoutable != nullptr && !npc(nonInternetRoutable)->isEmpty())) {
            findExternalNodes(nodeId, bindAddress, nonInternetRoutable, deliverResultToMe);
        } else {
            findExternalAddressHelper(nodeId, bindAddress, deliverResultToMe, myProbeAddresses);
        }
    }
}

void rice::pastry::socket::internet::InternetPastryNodeFactory::findExternalNodes(::rice::pastry::Id* nodeId, ::java::net::InetSocketAddress* bindAddress, ::java::util::Collection* nonInternetRoutable, ::rice::Continuation* deliverResultToMe)
{
    if(nonInternetRoutable == nullptr || npc(nonInternetRoutable)->isEmpty())
        findExternalAddressHelper(nodeId, bindAddress, deliverResultToMe, nullptr);

    npc(connectivityVerifier)->findExternalNodes(bindAddress, nonInternetRoutable, new InternetPastryNodeFactory_findExternalNodes_1(this, nodeId, bindAddress, deliverResultToMe, nonInternetRoutable));
}

void rice::pastry::socket::internet::InternetPastryNodeFactory::findExternalAddressHelper(::rice::pastry::Id* nodeId, ::java::net::InetSocketAddress* bindAddress, ::rice::Continuation* deliverResultToMe, ::java::util::Collection* myProbeAddresses)
{
    if(myProbeAddresses != nullptr && !npc(myProbeAddresses)->isEmpty()) {
        npc(connectivityVerifier)->findExternalAddress(bindAddress, myProbeAddresses, new InternetPastryNodeFactory_findExternalAddressHelper_2(this, deliverResultToMe, nodeId, bindAddress));
    } else {
        openFirewallPort(nodeId, bindAddress, deliverResultToMe, npc(natHandler)->getFireWallExternalAddress(), -int32_t(1));
    }
}

void rice::pastry::socket::internet::InternetPastryNodeFactory::openFirewallPort(::rice::pastry::Id* nodeId, ::java::net::InetSocketAddress* bindAddress, ::rice::Continuation* deliverResultToMe, ::java::net::InetAddress* externalAddress, int32_t requestedPort)
{
    auto params = npc(environment)->getParameters();
    auto firewallSearchTries = npc(params)->getInt(u"nat_find_port_max_tries"_j);
    auto firewallAppName = npc(params)->getString(u"nat_app_name"_j);
    int32_t port;
    if(requestedPort == -int32_t(1)) {
        port = npc(bindAddress)->getPort();
    } else {
        port = requestedPort;
    }
    auto rendezvous = false;
    try {
        if(npc(natHandler)->getFireWallExternalAddress() == nullptr) {
            rendezvous = true;
        } else {
            auto availableFireWallPort = npc(natHandler)->findAvailableFireWallPort(npc(bindAddress)->getPort(), port, firewallSearchTries, firewallAppName);
            if(requestedPort == -int32_t(1) || availableFireWallPort == port) {
                port = availableFireWallPort;
            } else {
                switch (getFireWallPolicyVariable(u"nat_state_policy"_j)) {
                case OVERWRITE:
                    break;
                case FAIL:
                    npc(deliverResultToMe)->receiveException(new ::java::net::BindException(::java::lang::StringBuilder().append(u"Firewall is already bound to the requested port:"_j)->append(static_cast< ::java::lang::Object* >(externalAddress))
                        ->append(u":"_j)
                        ->append(port)->toString()));
                    return;
                case RENDEZVOUS:
                    rendezvous = true;
                    break;
                case USE_DIFFERENT_PORT:
                    port = availableFireWallPort;
                    break;
                }

            }
        }
        if(rendezvous) {
            port = npc(bindAddress)->getPort();
        } else {
            npc(natHandler)->openFireWallPort(npc(bindAddress)->getPort(), port, firewallAppName);
        }
    } catch (::java::io::IOException* ioe) {
        port = 0;
    }
    ::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* fullAddress;
    if(externalAddress == nullptr) {
        fullAddress = new ::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress(bindAddress);
    } else {
        fullAddress = new ::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress(new ::java::net::InetSocketAddress(externalAddress, port), bindAddress);
    }
    verifyConnectivityThenMakeNewNode(nodeId, fullAddress, deliverResultToMe);
}

void rice::pastry::socket::internet::InternetPastryNodeFactory::verifyConnectivityThenMakeNewNode(::rice::pastry::Id* nodeId, ::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* proxyAddress, ::rice::Continuation* deliverResultToMe)
{
    if(npc(npc(proxyAddress)->getOutermostAddress())->getPort() < 1) {
        newNodeSelector(nodeId, proxyAddress, deliverResultToMe, static_cast< ::java::util::Map* >(nullptr), true);
        return;
    }
    if(!shouldCheckConnectivity(proxyAddress, probeAddresses)) {
        newNodeSelector(nodeId, proxyAddress, deliverResultToMe, static_cast< ::java::util::Map* >(nullptr), false);
        return;
    }
    auto const timeout = new ::boolArray(int32_t(1));
    (*timeout)[int32_t(0)] = false;
    auto const cancelme = new ::rice::p2p::commonapi::CancellableArray(int32_t(1));
    ::rice::selector::TimerTask* const timer = new InternetPastryNodeFactory_verifyConnectivityThenMakeNewNode_3(this, timeout, cancelme, nodeId, proxyAddress, deliverResultToMe);
    npc(npc(npc(environment)->getSelectorManager())->getTimer())->schedule(timer, 10000);
    cancelme->set(int32_t(0), npc(connectivityVerifier)->verifyConnectivity(proxyAddress, probeAddresses, new InternetPastryNodeFactory_verifyConnectivityThenMakeNewNode_4(this, timeout, timer, nodeId, proxyAddress, deliverResultToMe)));
}

bool rice::pastry::socket::internet::InternetPastryNodeFactory::isInternetRoutable(::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* proxyAddress)
{
    if(npc(proxyAddress)->getNumAddresses() == 1) {
        auto address = npc(proxyAddress)->getInnermostAddress();
        if(isInternetRoutablePrefix(npc(address)->getAddress())) {
            return true;
        }
    }
    return false;
}

int32_t rice::pastry::socket::internet::InternetPastryNodeFactory::getFireWallPolicyVariable(::java::lang::String* key)
{
    auto val = npc(npc(environment)->getParameters())->getString(key);
    if(npc(val)->equalsIgnoreCase(u"prefix"_j))
        return PREFIX_MATCH;

    if(npc(val)->equalsIgnoreCase(u"change"_j))
        return USE_DIFFERENT_PORT;

    if(npc(val)->equalsIgnoreCase(u"never"_j))
        return NEVER;

    if(npc(val)->equalsIgnoreCase(u"overwrite"_j))
        return OVERWRITE;

    if(npc(val)->equalsIgnoreCase(u"always"_j))
        return ALWAYS;

    if(npc(val)->equalsIgnoreCase(u"boot"_j))
        return BOOT;

    if(npc(val)->equalsIgnoreCase(u"fail"_j))
        return FAIL;

    if(npc(val)->equalsIgnoreCase(u"rendezvous"_j))
        return RENDEZVOUS;

    throw new ::java::lang::RuntimeException(::java::lang::StringBuilder().append(u"Unknown value "_j)->append(val)
        ->append(u" for "_j)
        ->append(key)->toString());
}

bool rice::pastry::socket::internet::InternetPastryNodeFactory::shouldCheckConnectivity(::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* proxyAddress, ::java::util::Collection* bootstraps)
{
    if(bootstraps == nullptr)
        return false;

    switch (getFireWallPolicyVariable(u"firewall_test_policy"_j)) {
    case NEVER:
        return false;
    case BOOT:
        if(!npc(bootstraps)->contains(npc(proxyAddress)->getOutermostAddress()))
            return true;

    case PREFIX_MATCH:
        return !isInternetRoutable(proxyAddress);
    case ALWAYS:
        return true;
    }

    return true;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::socket::internet::InternetPastryNodeFactory::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.socket.internet.InternetPastryNodeFactory", 53);
    return c;
}

void rice::pastry::socket::internet::InternetPastryNodeFactory::newNodeSelector(::rice::pastry::Id* nodeId, ::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* proxyAddress, ::rice::Continuation* deliverResultToMe, ::java::util::Map* initialVars, bool firewalled)
{
    super::newNodeSelector(nodeId, proxyAddress, deliverResultToMe, initialVars, firewalled);
}

void rice::pastry::socket::internet::InternetPastryNodeFactory::newNodeSelector(::rice::pastry::Id* nodeId, ::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* proxyAddress, ::rice::Continuation* deliverResultToMe, ::java::util::Map* initialVars, int8_t contactState)
{
    super::newNodeSelector(nodeId, proxyAddress, deliverResultToMe, initialVars, contactState);
}

java::lang::Class* rice::pastry::socket::internet::InternetPastryNodeFactory::getClass0()
{
    return class_();
}

