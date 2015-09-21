// Generated from /pastry-2.1/src/rice/pastry/socket/nat/sbbi/SBBINatHandler.java
#include <rice/pastry/socket/nat/sbbi/SBBINatHandler.hpp>

#include <java/io/IOException.hpp>
#include <java/io/PrintStream.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/Class.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/Integer.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/NumberFormatException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/System.hpp>
#include <java/net/InetAddress.hpp>
#include <java/util/Iterator.hpp>
#include <java/util/Set.hpp>
#include <net/sbbi/upnp/devices/UPNPRootDevice.hpp>
#include <net/sbbi/upnp/impls/InternetGatewayDevice.hpp>
#include <net/sbbi/upnp/messages/ActionResponse.hpp>
#include <net/sbbi/upnp/messages/UPNPResponseException.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/LogManager.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/environment/params/Parameters.hpp>
#include <rice/pastry/socket/nat/CantFindFirewallException.hpp>
#include <ObjectArray.hpp>
#include <SubArray.hpp>

template<typename ComponentType, typename... Bases> struct SubArray;
namespace net
{
    namespace sbbi
    {
        namespace upnp
        {
            namespace impls
            {
typedef ::SubArray< ::net::sbbi::upnp::impls::InternetGatewayDevice, ::java::lang::ObjectArray > InternetGatewayDeviceArray;
            } // impls
        } // upnp
    } // sbbi
} // net

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

rice::pastry::socket::nat::sbbi::SBBINatHandler::SBBINatHandler(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::socket::nat::sbbi::SBBINatHandler::SBBINatHandler(::rice::environment::Environment* env, ::java::net::InetAddress* localAddress) 
    : SBBINatHandler(*static_cast< ::default_init_tag* >(0))
{
    ctor(env,localAddress);
}

void rice::pastry::socket::nat::sbbi::SBBINatHandler::init()
{
    searchedForFireWall = false;
    findPortTries = int32_t(0);
}

void rice::pastry::socket::nat::sbbi::SBBINatHandler::ctor(::rice::environment::Environment* env, ::java::net::InetAddress* localAddress)
{
    super::ctor();
    init();
    environment = env;
    logger = npc(npc(env)->getLogManager())->getLogger(SBBINatHandler::class_(), nullptr);
    this->localAddress = localAddress;
}

java::net::InetAddress* rice::pastry::socket::nat::sbbi::SBBINatHandler::findFireWall(::java::net::InetAddress* bindAddress) /* throws(IOException) */
{
    if(searchedForFireWall)
        return fireWallExternalAddress;

    searchedForFireWall = true;
    auto discoveryTimeout = npc(npc(environment)->getParameters())->getInt(u"nat_discovery_timeout"_j);
    auto IGDs = ::net::sbbi::upnp::impls::InternetGatewayDevice::getDevices(discoveryTimeout);
    if(IGDs != nullptr) {
        fireWall = (*IGDs)[int32_t(0)];
        try {
            fireWallExternalAddress = ::java::net::InetAddress::getByName(npc(fireWall)->getExternalIPAddress());
        } catch (::net::sbbi::upnp::messages::UPNPResponseException* ure) {
            if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                npc(logger)->logException(u"Error:"_j, ure);

            throw new ::java::io::IOException(npc(ure)->toString());
        }
    } else {
        throw new ::rice::pastry::socket::nat::CantFindFirewallException(::java::lang::StringBuilder().append(u"Could not find firewall for bindAddress:"_j)->append(static_cast< ::java::lang::Object* >(bindAddress))->toString());
    }
    return fireWallExternalAddress;
}

int32_t rice::pastry::socket::nat::sbbi::SBBINatHandler::findAvailableFireWallPort(int32_t internal, int32_t external, int32_t tries, ::java::lang::String* appName) /* throws(IOException) */
{
    try {
        findPortTries++;
        if(findPortTries > tries)
            throw new ::java::io::IOException(u"Couldn't find available port on firewall"_j);

        if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
            npc(logger)->log(::java::lang::StringBuilder().append(u"findFireWallPort("_j)->append(internal)
                ->append(u","_j)
                ->append(external)
                ->append(u")"_j)->toString());

        ::net::sbbi::upnp::messages::ActionResponse* response = nullptr;
        response = npc(fireWall)->getSpecificPortMappingEntry(nullptr, external, u"TCP"_j);
        if(checkSpecificPortMappingEntryResponse(response, internal, external, u"TCP"_j, appName)) {
        } else {
            return findAvailableFireWallPort(internal, external + int32_t(1), tries, appName);
        }
        response = npc(fireWall)->getSpecificPortMappingEntry(nullptr, external, u"UDP"_j);
        if(checkSpecificPortMappingEntryResponse(response, internal, external, u"UDP"_j, appName)) {
        } else {
            return findAvailableFireWallPort(internal, external + int32_t(1), tries, appName);
        }
        return external;
    } catch (::net::sbbi::upnp::messages::UPNPResponseException* ure) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(logger)->logException(u"Error:"_j, ure);

        throw new ::java::io::IOException(npc(ure)->toString());
    }
}

constexpr int32_t rice::pastry::socket::nat::sbbi::SBBINatHandler::MAX_PORT;

bool rice::pastry::socket::nat::sbbi::SBBINatHandler::checkSpecificPortMappingEntryResponse(::net::sbbi::upnp::messages::ActionResponse* response, int32_t internal, int32_t external, ::java::lang::String* type, ::java::lang::String* app)
{
    if(response == nullptr)
        return true;

    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINEST) {
        auto s = npc(response)->getOutActionArgumentNames();
        auto i = npc(s)->iterator();
        while (npc(i)->hasNext()) {
            auto key = java_cast< ::java::lang::String* >(java_cast< ::java::lang::Object* >(npc(i)->next()));
            auto val = npc(response)->getOutActionArgumentValue(key);
            npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"  "_j)->append(key)
                ->append(u" -> "_j)
                ->append(val)->toString());
        }
    }
    auto ret = true;
    auto internalPortStr = npc(response)->getOutActionArgumentValue(u"NewInternalPort"_j);
    if(internalPortStr != nullptr) {
        try {
            auto internalPort = ::java::lang::Integer::parseInt(internalPortStr);
            if(internalPort > MAX_PORT) {
                if(npc(logger)->level < ::rice::environment::logging::Logger::WARNING)
                    npc(logger)->log(::java::lang::StringBuilder().append(u"Warning, NAT "_j)->append(npc(npc(fireWall)->getIGDRootDevice())->getModelName())
                        ->append(u" returned an invalid value for entry NewInternalPort.  Expected an integer less than "_j)
                        ->append(MAX_PORT)
                        ->append(u", got: "_j)
                        ->append(internalPort)
                        ->append(u".  Query "_j)
                        ->append(external)
                        ->append(u":"_j)
                        ->append(type)
                        ->append(u"... overwriting entry."_j)->toString());

                return true;
            }
            if(internalPort != internal) {
                if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
                    npc(logger)->log(::java::lang::StringBuilder().append(u"internalPort("_j)->append(internalPort)
                        ->append(u") != internal("_j)
                        ->append(internal)
                        ->append(u")"_j)->toString());

                ret = false;
            }
        } catch (::java::lang::NumberFormatException* nfe) {
            if(npc(logger)->level < ::rice::environment::logging::Logger::WARNING)
                npc(logger)->log(::java::lang::StringBuilder().append(u"Warning, NAT "_j)->append(npc(npc(fireWall)->getIGDRootDevice())->getModelName())
                    ->append(u" returned an invalid value for entry NewInternalPort.  Expected an integer, got: "_j)
                    ->append(internalPortStr)
                    ->append(u".  Query "_j)
                    ->append(external)
                    ->append(u":"_j)
                    ->append(type)
                    ->append(u"... overwriting entry."_j)->toString());

            return true;
        }
    }
    auto appName = npc(response)->getOutActionArgumentValue(u"NewPortMappingDescription"_j);
    if(appName != nullptr) {
        auto tempName = npc(appName)->replaceAll(u" "_j, u""_j);
        if((npc(tempName)->equals(static_cast< ::java::lang::Object* >(u""_j))) || npc(appName)->equalsIgnoreCase(app)) {
        } else {
            if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
                npc(logger)->log(::java::lang::StringBuilder().append(u"appName("_j)->append(appName)
                    ->append(u") != app("_j)
                    ->append(app)
                    ->append(u")"_j)->toString());

            ret = false;
        }
    }
    auto newInternalClientString = npc(response)->getOutActionArgumentValue(u"NewInternalClient"_j);
    if(newInternalClientString == nullptr) {
        if(npc(logger)->level < ::rice::environment::logging::Logger::WARNING)
            npc(logger)->log(::java::lang::StringBuilder().append(u"Warning, NAT "_j)->append(npc(npc(fireWall)->getIGDRootDevice())->getModelName())
                ->append(u" returned no value for entry NewInternalClient.  Expected an IP address, got: "_j)
                ->append(newInternalClientString)
                ->append(u".  Query "_j)
                ->append(external)
                ->append(u":"_j)
                ->append(type)
                ->append(u"... overwriting entry."_j)->toString());

        return true;
    }
    try {
        auto client = ::java::net::InetAddress::getByName(newInternalClientString);
        if(!npc(client)->equals(static_cast< ::java::lang::Object* >(localAddress))) {
            if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
                npc(logger)->log(::java::lang::StringBuilder().append(u"client("_j)->append(static_cast< ::java::lang::Object* >(client))
                    ->append(u") != localAddress("_j)
                    ->append(static_cast< ::java::lang::Object* >(localAddress))
                    ->append(u")"_j)->toString());

            ret = false;
        }
    } catch (::java::lang::Exception* e) {
        if(npc(logger)->level < ::rice::environment::logging::Logger::WARNING)
            npc(logger)->log(::java::lang::StringBuilder().append(u"Warning, NAT "_j)->append(npc(npc(fireWall)->getIGDRootDevice())->getModelName())
                ->append(u" returned an invalid value for entry NewInternalClient.  Expected an IP address, got: "_j)
                ->append(newInternalClientString)
                ->append(u".  Query "_j)
                ->append(external)
                ->append(u":"_j)
                ->append(type)
                ->append(u"... overwriting entry."_j)->toString());

        return true;
    }
    auto enabledString = npc(response)->getOutActionArgumentValue(u"NewEnabled"_j);
    if(enabledString != nullptr) {
        try {
            auto enabled = ::java::lang::Integer::parseInt(enabledString);
            if(enabled == 0) {
                if(npc(logger)->level < ::rice::environment::logging::Logger::FINE)
                    npc(logger)->log(::java::lang::StringBuilder().append(u"Warning, NAT "_j)->append(npc(npc(fireWall)->getIGDRootDevice())->getModelName())
                        ->append(u" had an existing rule that was disabled, implicitly overwriting.  "_j)
                        ->append(u"Query "_j)
                        ->append(external)
                        ->append(u":"_j)
                        ->append(type)
                        ->append(u"."_j)
                        ->append(u"\n  NewInternalPort -> "_j)
                        ->append(internalPortStr)
                        ->append(u"\n  NewPortMappingDescription -> "_j)
                        ->append(appName)
                        ->append(u"\n  NewInternalClient -> "_j)
                        ->append(newInternalClientString)
                        ->append(u"\n  NewEnabled -> "_j)
                        ->append(enabledString)->toString());

                return true;
            } else if(enabled == 1) {
            } else {
                if(npc(logger)->level < ::rice::environment::logging::Logger::WARNING)
                    npc(logger)->log(::java::lang::StringBuilder().append(u"Warning, NAT "_j)->append(npc(npc(fireWall)->getIGDRootDevice())->getModelName())
                        ->append(u" returned an invalid value for entry NewEnabled.  Expected 0 or 1, got: "_j)
                        ->append(enabled)
                        ->append(u".  Query "_j)
                        ->append(external)
                        ->append(u":"_j)
                        ->append(type)
                        ->append(u"... overwriting entry."_j)->toString());

                return true;
            }
        } catch (::java::lang::NumberFormatException* nfe) {
            if(npc(logger)->level < ::rice::environment::logging::Logger::WARNING)
                npc(logger)->log(::java::lang::StringBuilder().append(u"Warning, NAT "_j)->append(npc(npc(fireWall)->getIGDRootDevice())->getModelName())
                    ->append(u" returned an invalid value for entry NewEnabled.  Expected 0 or 1, got: "_j)
                    ->append(enabledString)
                    ->append(u".  Query "_j)
                    ->append(external)
                    ->append(u":"_j)
                    ->append(type)
                    ->append(u"... overwriting entry."_j)->toString());

            return true;
        }
    } else {
    }
    if(ret == false) {
        if(npc(logger)->level < ::rice::environment::logging::Logger::INFO)
            npc(logger)->log(::java::lang::StringBuilder().append(u"Warning, NAT "_j)->append(npc(npc(fireWall)->getIGDRootDevice())->getModelName())
                ->append(u" had an existing rule, trying different port.  "_j)
                ->append(u"Query "_j)
                ->append(external)
                ->append(u":"_j)
                ->append(type)
                ->append(u"."_j)
                ->append(u"\n  NewInternalPort -> "_j)
                ->append(internalPortStr)
                ->append(u"\n  NewPortMappingDescription -> "_j)
                ->append(appName)
                ->append(u"\n  NewInternalClient -> "_j)
                ->append(newInternalClientString)
                ->append(u"\n  NewEnabled -> "_j)
                ->append(enabledString)->toString());

    }
    return ret;
}

void rice::pastry::socket::nat::sbbi::SBBINatHandler::openFireWallPort(int32_t local, int32_t external, ::java::lang::String* appName) /* throws(IOException) */
{
    try {
        auto mapped = true;
        mapped = npc(fireWall)->addPortMapping(appName, nullptr, local, external, npc(localAddress)->getHostAddress(), 0, u"UDP"_j);
        if(!mapped)
            throw new ::java::io::IOException(::java::lang::StringBuilder().append(u"Could not set firewall UDP port forwarding from external:"_j)->append(static_cast< ::java::lang::Object* >(fireWallExternalAddress))
                ->append(u":"_j)
                ->append(external)
                ->append(u" -> local:"_j)
                ->append(static_cast< ::java::lang::Object* >(localAddress))
                ->append(u":"_j)
                ->append(local)->toString());

        mapped = npc(fireWall)->addPortMapping(appName, nullptr, local, external, npc(localAddress)->getHostAddress(), 0, u"TCP"_j);
        if(!mapped)
            throw new ::java::io::IOException(::java::lang::StringBuilder().append(u"Could not set firewall TCP port forwarding from external:"_j)->append(static_cast< ::java::lang::Object* >(fireWallExternalAddress))
                ->append(u":"_j)
                ->append(external)
                ->append(u" -> local:"_j)
                ->append(static_cast< ::java::lang::Object* >(localAddress))
                ->append(u":"_j)
                ->append(local)->toString());

    } catch (::net::sbbi::upnp::messages::UPNPResponseException* ure) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(logger)->logException(u"Error:"_j, ure);

        throw new ::java::io::IOException(npc(ure)->toString());
    }
}

java::net::InetAddress* rice::pastry::socket::nat::sbbi::SBBINatHandler::getFireWallExternalAddress()
{
    return fireWallExternalAddress;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::socket::nat::sbbi::SBBINatHandler::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.socket.nat.sbbi.SBBINatHandler", 42);
    return c;
}

java::lang::Class* rice::pastry::socket::nat::sbbi::SBBINatHandler::getClass0()
{
    return class_();
}

