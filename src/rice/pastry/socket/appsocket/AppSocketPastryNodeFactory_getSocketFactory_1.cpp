// Generated from /pastry-2.1/src/rice/pastry/socket/appsocket/AppSocketPastryNodeFactory.java
#include <rice/pastry/socket/appsocket/AppSocketPastryNodeFactory_getSocketFactory_1.hpp>

#include <java/lang/Boolean.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Integer.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/util/Map.hpp>
#include <org/mpisws/p2p/transport/SocketRequestHandle.hpp>
#include <org/mpisws/p2p/transport/TransportLayer.hpp>
#include <org/mpisws/p2p/transport/identity/IdentityImpl.hpp>
#include <org/mpisws/p2p/transport/multiaddress/MultiInetSocketAddress.hpp>
#include <org/mpisws/p2p/transport/util/OptionsFactory.hpp>
#include <org/mpisws/p2p/transport/util/SocketRequestHandleImpl.hpp>
#include <rice/p2p/commonapi/Cancellable.hpp>
#include <rice/pastry/Id.hpp>
#include <rice/pastry/socket/SocketNodeHandle.hpp>
#include <rice/pastry/socket/SocketNodeHandleFactory.hpp>
#include <rice/pastry/socket/TransportLayerNodeHandle.hpp>
#include <rice/pastry/socket/appsocket/AppSocketPastryNodeFactory_getSocketFactory_1_getSocketChannel_1_2.hpp>
#include <rice/pastry/socket/appsocket/AppSocketPastryNodeFactory_getSocketFactory_1_getSocket_1_3.hpp>
#include <rice/pastry/socket/appsocket/AppSocketPastryNodeFactory_getSocketFactory_1_getAppSocket_1_1.hpp>
#include <rice/pastry/socket/appsocket/AppSocketPastryNodeFactory.hpp>
#include <rice/pastry/transport/NodeHandleAdapter.hpp>

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

extern void lock(::java::lang::Object *);
extern void unlock(::java::lang::Object *);

namespace
{
    struct synchronized
    {
        synchronized(::java::lang::Object *o) : o(o) { ::lock(o); }
        ~synchronized() { ::unlock(o); }
    private:
        synchronized(const synchronized&); synchronized& operator=(const synchronized&);
        ::java::lang::Object *o;
    };
}
rice::pastry::socket::appsocket::AppSocketPastryNodeFactory_getSocketFactory_1::AppSocketPastryNodeFactory_getSocketFactory_1(AppSocketPastryNodeFactory *AppSocketPastryNodeFactory_this, ::rice::pastry::socket::SocketNodeHandleFactory* handleFactory, ::rice::pastry::transport::NodeHandleAdapter* nha)
    : super(*static_cast< ::default_init_tag* >(0))
    , AppSocketPastryNodeFactory_this(AppSocketPastryNodeFactory_this)
    , handleFactory(handleFactory)
    , nha(nha)
{
    clinit();
    init();
    ctor();
}

void rice::pastry::socket::appsocket::AppSocketPastryNodeFactory_getSocketFactory_1::init()
{
    uid = ::java::lang::Integer::MIN_VALUE;
}

rice::p2p::commonapi::Cancellable* rice::pastry::socket::appsocket::AppSocketPastryNodeFactory_getSocketFactory_1::getAppSocket(::java::net::InetSocketAddress* addr, int32_t appid, ::rice::Continuation* c, ::java::util::Map* options)
{
    return getSocket(addr, appid, new AppSocketPastryNodeFactory_getSocketFactory_1_getAppSocket_1_1(this, c), options);
}

rice::p2p::commonapi::Cancellable* rice::pastry::socket::appsocket::AppSocketPastryNodeFactory_getSocketFactory_1::getSocketChannel(::java::net::InetSocketAddress* addr, int32_t appid, ::rice::Continuation* c, ::java::util::Map* options)
{
    int32_t myUid;
    {
        synchronized synchronized_0(this);
        {
            myUid = uid++;
        }
    }
    options = ::org::mpisws::p2p::transport::util::OptionsFactory::addOption(options, AppSocketPastryNodeFactory::STORE_SOCKET(), ::java::lang::Integer::valueOf(myUid));
    return getSocket(addr, appid, new AppSocketPastryNodeFactory_getSocketFactory_1_getSocketChannel_1_2(this, c, myUid), options);
}

rice::p2p::commonapi::Cancellable* rice::pastry::socket::appsocket::AppSocketPastryNodeFactory_getSocketFactory_1::getSocket(::java::net::InetSocketAddress* addr, int32_t appid, ::rice::Continuation* c, ::java::util::Map* options)
{
    auto handle = getHandle(addr);
    auto const ret = new ::org::mpisws::p2p::transport::util::SocketRequestHandleImpl(handle, options, AppSocketPastryNodeFactory_this->logger);
    options = ::org::mpisws::p2p::transport::util::OptionsFactory::addOption(options, ::org::mpisws::p2p::transport::identity::IdentityImpl::DONT_VERIFY(), ::java::lang::Boolean::valueOf(true));
    npc(ret)->setSubCancellable(npc(getTL())->openSocket(handle, new AppSocketPastryNodeFactory_getSocketFactory_1_getSocket_1_3(this, ret, appid, c), options));
    return ret;
}

rice::pastry::socket::TransportLayerNodeHandle* rice::pastry::socket::appsocket::AppSocketPastryNodeFactory_getSocketFactory_1::getHandle(::java::net::InetSocketAddress* addr)
{
    return npc(handleFactory)->getNodeHandle(new ::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress(addr), -int32_t(1), ::rice::pastry::Id::build());
}

org::mpisws::p2p::transport::TransportLayer* rice::pastry::socket::appsocket::AppSocketPastryNodeFactory_getSocketFactory_1::getTL()
{
    return java_cast< ::org::mpisws::p2p::transport::TransportLayer* >(npc(nha)->getTL());
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::socket::appsocket::AppSocketPastryNodeFactory_getSocketFactory_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::pastry::socket::appsocket::AppSocketPastryNodeFactory_getSocketFactory_1::getClass0()
{
    return class_();
}

