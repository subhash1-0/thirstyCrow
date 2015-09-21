// Generated from /pastry-2.1/src/rice/pastry/socket/SocketPastryNodeFactory.java
#include <rice/pastry/socket/SocketPastryNodeFactory_TLBootstrapper.hpp>

#include <java/lang/Class.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/net/InetSocketAddress.hpp>
#include <java/util/ArrayList.hpp>
#include <java/util/Collection.hpp>
#include <java/util/Collections.hpp>
#include <java/util/HashSet.hpp>
#include <java/util/Iterator.hpp>
#include <java/util/List.hpp>
#include <org/mpisws/p2p/transport/TransportLayer.hpp>
#include <org/mpisws/p2p/transport/liveness/LivenessListener.hpp>
#include <org/mpisws/p2p/transport/liveness/LivenessProvider.hpp>
#include <org/mpisws/p2p/transport/multiaddress/MultiInetSocketAddress.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/LogManager.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/environment/params/Parameters.hpp>
#include <rice/pastry/Id.hpp>
#include <rice/pastry/NodeHandle.hpp>
#include <rice/pastry/PastryNode.hpp>
#include <rice/pastry/socket/SocketNodeHandle.hpp>
#include <rice/pastry/socket/SocketNodeHandleFactory.hpp>
#include <rice/pastry/socket/SocketPastryNodeFactory_TLBootstrapper_boot_1.hpp>
#include <rice/pastry/socket/SocketPastryNodeFactory_TLBootstrapper_boot_2.hpp>
#include <rice/pastry/socket/SocketPastryNodeFactory_TLBootstrapper_boot_3.hpp>
#include <rice/pastry/socket/SocketPastryNodeFactory_TLBootstrapper_boot_4.hpp>
#include <rice/pastry/socket/SocketPastryNodeFactory.hpp>
#include <rice/pastry/socket/TransportLayerNodeHandle.hpp>
#include <rice/pastry/standard/ProximityNeighborSelector.hpp>
#include <rice/selector/SelectorManager.hpp>
#include <rice/selector/TimerTask.hpp>

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
rice::pastry::socket::SocketPastryNodeFactory_TLBootstrapper::SocketPastryNodeFactory_TLBootstrapper(SocketPastryNodeFactory *SocketPastryNodeFactory_this, const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
    , SocketPastryNodeFactory_this(SocketPastryNodeFactory_this)
{
    clinit();
}

rice::pastry::socket::SocketPastryNodeFactory_TLBootstrapper::SocketPastryNodeFactory_TLBootstrapper(SocketPastryNodeFactory *SocketPastryNodeFactory_this, ::rice::pastry::PastryNode* pn, ::org::mpisws::p2p::transport::TransportLayer* tl, SocketNodeHandleFactory* handleFactory, ::rice::pastry::standard::ProximityNeighborSelector* pns) 
    : SocketPastryNodeFactory_TLBootstrapper(SocketPastryNodeFactory_this, *static_cast< ::default_init_tag* >(0))
{
    ctor(pn,tl,handleFactory,pns);
}

void rice::pastry::socket::SocketPastryNodeFactory_TLBootstrapper::init()
{
    listener = new ::java::util::ArrayList();
}

void rice::pastry::socket::SocketPastryNodeFactory_TLBootstrapper::ctor(::rice::pastry::PastryNode* pn, ::org::mpisws::p2p::transport::TransportLayer* tl, SocketNodeHandleFactory* handleFactory, ::rice::pastry::standard::ProximityNeighborSelector* pns)
{
    super::ctor();
    init();
    this->logger = npc(npc(npc(pn)->getEnvironment())->getLogManager())->getLogger(SocketPastryNodeFactory_TLBootstrapper::class_(), nullptr);
    this->pn = pn;
    this->tl = tl;
    this->handleFactory = handleFactory;
    this->pns = pns;
}

void rice::pastry::socket::SocketPastryNodeFactory_TLBootstrapper::bootAsBootstrap()
{
    npc(pn)->doneNode(::java::util::Collections::EMPTY_LIST());
}

void rice::pastry::socket::SocketPastryNodeFactory_TLBootstrapper::boot(::java::util::Collection* bootaddresses_temp)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(::java::lang::StringBuilder().append(u"boot("_j)->append(static_cast< ::java::lang::Object* >(bootaddresses_temp))
            ->append(u")"_j)->toString());

    ::java::util::Collection* bootaddresses;
    if(bootaddresses_temp == nullptr) {
        bootaddresses = ::java::util::Collections::EMPTY_LIST();
    } else {
        bootaddresses = bootaddresses_temp;
    }
    auto const seed = npc(npc(SocketPastryNodeFactory_this->environment)->getParameters())->getBoolean(u"rice_socket_seed"_j) || npc(bootaddresses)->isEmpty() || npc(bootaddresses)->contains(npc(npc((java_cast< SocketNodeHandle* >(npc(pn)->getLocalHandle())))->getAddress())->getInnermostAddress());
    if(npc(bootaddresses)->isEmpty() || (npc(bootaddresses)->size() == 1 && seed)) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
            npc(logger)->log(u"boot() calling pn.doneNode(empty)"_j);

        bootAsBootstrap();
        return;
    }
    ::java::util::Collection* const tempBootHandles = new ::java::util::ArrayList(npc(bootaddresses)->size());
    ::java::util::Collection* const bootHandles = new ::java::util::HashSet();
    auto local = java_cast< TransportLayerNodeHandle* >(npc(tl)->getLocalIdentifier());
    auto localAddr = npc(java_cast< ::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* >(npc(local)->getAddress()))->getInnermostAddress();
    for (auto _i = npc(bootaddresses)->iterator(); _i->hasNext(); ) {
        ::java::net::InetSocketAddress* addr = java_cast< ::java::net::InetSocketAddress* >(_i->next());
        {
            if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
                npc(logger)->log(::java::lang::StringBuilder().append(u"addr:"_j)->append(static_cast< ::java::lang::Object* >(addr))
                    ->append(u" local:"_j)
                    ->append(static_cast< ::java::lang::Object* >(localAddr))->toString());

            if(!npc(addr)->equals(static_cast< ::java::lang::Object* >(localAddr))) {
                npc(tempBootHandles)->add(getTempNodeHandle(addr));
            }
        }
    }
    ::rice::Continuation* const beginPns = new SocketPastryNodeFactory_TLBootstrapper_boot_1(this, seed, bootaddresses);
    npc(listener)->add(static_cast< ::java::lang::Object* >(new SocketPastryNodeFactory_TLBootstrapper_boot_2(this, bootHandles, tempBootHandles, beginPns)));
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(u"boot() adding liveness listener"_j);

    npc(npc(pn)->getLivenessProvider())->addLivenessListener(java_cast< ::org::mpisws::p2p::transport::liveness::LivenessListener* >(npc(listener)->get(0)));
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(u"boot() checking liveness"_j);

    for (auto _i = npc(tempBootHandles)->iterator(); _i->hasNext(); ) {
        SocketNodeHandle* h = java_cast< SocketNodeHandle* >(_i->next());
        {
            checkLiveness(h, nullptr);
        }
    }
    {
        synchronized synchronized_0(bootHandles);
        {
            if(npc(bootHandles)->size() < npc(tempBootHandles)->size()) {
                npc(npc(SocketPastryNodeFactory_this->environment)->getSelectorManager())->schedule(static_cast< ::rice::selector::TimerTask* >(new SocketPastryNodeFactory_TLBootstrapper_boot_3(this, beginPns, bootHandles)), static_cast< int64_t >(int32_t(20000)));
            }
        }
    }
    if(npc(tempBootHandles)->isEmpty()) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
            npc(logger)->log(u"invoking receiveResult (this is probably the first node in the ring)"_j);

        npc(npc(SocketPastryNodeFactory_this->environment)->getSelectorManager())->invoke(new SocketPastryNodeFactory_TLBootstrapper_boot_4(this, beginPns, bootHandles));
    }
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(u"boot() returning"_j);

}

rice::pastry::socket::SocketNodeHandle* rice::pastry::socket::SocketPastryNodeFactory_TLBootstrapper::getTempNodeHandle(::java::net::InetSocketAddress* addr)
{
    return npc(handleFactory)->getNodeHandle(new ::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress(addr), -int32_t(1), ::rice::pastry::Id::build());
}

void rice::pastry::socket::SocketPastryNodeFactory_TLBootstrapper::checkLiveness(SocketNodeHandle* h, ::java::util::Map* options)
{
    npc(npc(pn)->getLivenessProvider())->checkLiveness(h, nullptr);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::socket::SocketPastryNodeFactory_TLBootstrapper::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.socket.SocketPastryNodeFactory.TLBootstrapper", 57);
    return c;
}

java::lang::Class* rice::pastry::socket::SocketPastryNodeFactory_TLBootstrapper::getClass0()
{
    return class_();
}

