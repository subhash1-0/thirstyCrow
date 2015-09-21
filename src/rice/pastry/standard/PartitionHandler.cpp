// Generated from /pastry-2.1/src/rice/pastry/standard/PartitionHandler.java
#include <rice/pastry/standard/PartitionHandler.hpp>

#include <java/io/IOException.hpp>
#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/Class.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Iterable.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/net/InetSocketAddress.hpp>
#include <java/net/SocketAddress.hpp>
#include <java/util/ArrayList.hpp>
#include <java/util/Collection.hpp>
#include <java/util/HashMap.hpp>
#include <java/util/Iterator.hpp>
#include <java/util/List.hpp>
#include <java/util/Map.hpp>
#include <java/util/Observer.hpp>
#include <java/util/Set.hpp>
#include <rice/Continuation.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/LogManager.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/environment/params/Parameters.hpp>
#include <rice/environment/random/RandomSource.hpp>
#include <rice/environment/time/TimeSource.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/commonapi/NodeHandleSet.hpp>
#include <rice/pastry/NodeHandle.hpp>
#include <rice/pastry/NodeSetEventSource.hpp>
#include <rice/pastry/NodeSetI.hpp>
#include <rice/pastry/NodeSetListener.hpp>
#include <rice/pastry/PastryNode.hpp>
#include <rice/pastry/join/JoinRequest.hpp>
#include <rice/pastry/leafset/LeafSet.hpp>
#include <rice/pastry/messaging/PRawMessage.hpp>
#include <rice/pastry/routing/RouteMessage.hpp>
#include <rice/pastry/routing/RouteSet.hpp>
#include <rice/pastry/routing/RoutingTable.hpp>
#include <rice/pastry/routing/SendOptions.hpp>
#include <rice/pastry/socket/SocketPastryNodeFactory.hpp>
#include <rice/pastry/standard/PartitionHandler_run_1.hpp>
#include <rice/pastry/standard/PartitionHandler_GoneSetEntry.hpp>
#include <rice/selector/Timer.hpp>
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
typedef ::SubArray< ::java::lang::Iterable, ObjectArray > IterableArray;
    } // lang

    namespace net
    {
typedef ::SubArray< ::java::net::SocketAddress, ::java::lang::ObjectArray, ::java::io::SerializableArray > SocketAddressArray;
typedef ::SubArray< ::java::net::InetSocketAddress, SocketAddressArray > InetSocketAddressArray;
    } // net

    namespace util
    {
typedef ::SubArray< ::java::util::Observer, ::java::lang::ObjectArray > ObserverArray;
    } // util
} // java

namespace rice
{
    namespace p2p
    {
        namespace commonapi
        {
typedef ::SubArray< ::rice::p2p::commonapi::NodeHandleSet, ::java::lang::ObjectArray, ::java::io::SerializableArray > NodeHandleSetArray;
        } // commonapi
    } // p2p

    namespace pastry
    {
typedef ::SubArray< ::rice::pastry::NodeSetI, ::java::lang::ObjectArray, ::rice::p2p::commonapi::NodeHandleSetArray > NodeSetIArray;

        namespace routing
        {
typedef ::SubArray< ::rice::pastry::routing::RouteSet, ::java::lang::ObjectArray, ::rice::pastry::NodeSetIArray, ::java::io::SerializableArray, ::java::util::ObserverArray, ::java::lang::IterableArray > RouteSetArray;
        } // routing
    } // pastry
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
rice::pastry::standard::PartitionHandler::PartitionHandler(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::standard::PartitionHandler::PartitionHandler(::rice::pastry::PastryNode* pn, ::rice::pastry::socket::SocketPastryNodeFactory* factory, ::java::net::InetSocketAddressArray* bootstraps) 
    : PartitionHandler(*static_cast< ::default_init_tag* >(0))
{
    ctor(pn,factory,bootstraps);
}

void rice::pastry::standard::PartitionHandler::ctor(::rice::pastry::PastryNode* pn, ::rice::pastry::socket::SocketPastryNodeFactory* factory, ::java::net::InetSocketAddressArray* bootstraps)
{
    super::ctor();
    pastryNode = pn;
    this->factory = factory;
    this->bootstraps = bootstraps;
    env = npc(pastryNode)->getEnvironment();
    gone = new ::java::util::HashMap();
    this->logger = npc(npc(npc(pn)->getEnvironment())->getLogManager())->getLogger(PartitionHandler::class_(), u""_j);
    maxGoneSize = npc(npc(env)->getParameters())->getInt(u"partition_handler_max_history_size"_j);
    maxGoneAge = npc(npc(env)->getParameters())->getInt(u"partition_handler_max_history_age"_j);
    bootstrapRate = npc(npc(env)->getParameters())->getDouble(u"partition_handler_bootstrap_check_rate"_j);
    npc(npc(pastryNode)->getLeafSet())->addNodeSetListener(this);
    npc(npc(pastryNode)->getRoutingTable())->addNodeSetListener(static_cast< ::rice::pastry::NodeSetListener* >(this));
}

void rice::pastry::standard::PartitionHandler::doGoneMaintainence()
{
    auto it = npc(npc(gone)->values())->iterator();
    auto now = npc(npc(env)->getTimeSource())->currentTimeMillis();
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(::java::lang::StringBuilder().append(u"Doing maintainence in PartitionHandler "_j)->append(now)->toString());

    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
        npc(logger)->log(::java::lang::StringBuilder().append(u"gone size 1 is "_j)->append(npc(gone)->size())
            ->append(u" of "_j)
            ->append(maxGoneSize)->toString());

    while (npc(it)->hasNext()) {
        auto g = java_cast< PartitionHandler_GoneSetEntry* >(java_cast< PartitionHandler_GoneSetEntry* >(npc(it)->next()));
        if(now - npc(g)->timestamp > maxGoneAge) {
            if(npc(logger)->level <= ::rice::environment::logging::Logger::FINEST)
                npc(logger)->log(::java::lang::StringBuilder().append(u"Removing "_j)->append(static_cast< ::java::lang::Object* >(g))
                    ->append(u" from gone due to expiry"_j)->toString());

            npc(it)->remove();
        } else if(npc(npc(g)->nh)->getLiveness() > ::rice::pastry::NodeHandle::LIVENESS_DEAD) {
            if(npc(logger)->level <= ::rice::environment::logging::Logger::FINEST)
                npc(logger)->log(::java::lang::StringBuilder().append(u"Removing "_j)->append(static_cast< ::java::lang::Object* >(g))
                    ->append(u" from gone due to death"_j)->toString());

            npc(it)->remove();
        }
    }
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
        npc(logger)->log(::java::lang::StringBuilder().append(u"gone size 2 is "_j)->append(npc(gone)->size())
            ->append(u" of "_j)
            ->append(maxGoneSize)->toString());

    while (npc(gone)->size() > maxGoneSize) {
        ::java::lang::Object* key = java_cast< ::rice::p2p::commonapi::Id* >(npc(npc(npc(gone)->keySet())->iterator())->next());
        npc(gone)->remove(key);
    }
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
        npc(logger)->log(::java::lang::StringBuilder().append(u"gone size 3 is "_j)->append(npc(gone)->size())
            ->append(u" of "_j)
            ->append(maxGoneSize)->toString());

}

java::util::List* rice::pastry::standard::PartitionHandler::getRoutingTableAsList()
{
    auto rt = npc(pastryNode)->getRoutingTable();
    ::java::util::List* rtHandles = new ::java::util::ArrayList(npc(rt)->numEntries());
    for (auto r = int32_t(0); r < npc(rt)->numRows(); r++) {
        auto row = npc(rt)->getRow(r);
        for (auto c = int32_t(0); c < npc(rt)->numColumns(); c++) {
            auto entry = (*row)[c];
            if(entry != nullptr) {
                for (auto i = int32_t(0); i < npc(entry)->size(); i++) {
                    auto nh = npc(entry)->get(i);
                    if(!npc(nh)->equals(static_cast< ::java::lang::Object* >(npc(pastryNode)->getLocalHandle()))) {
                        npc(rtHandles)->add(static_cast< ::java::lang::Object* >(nh));
                    }
                }
            }
        }
    }
    return rtHandles;
}

rice::pastry::NodeHandle* rice::pastry::standard::PartitionHandler::getCandidateNode()
{
    {
        synchronized synchronized_0(this);
        {
            auto which = npc(npc(env)->getRandomSource())->nextInt(maxGoneSize);
            if(npc(logger)->level <= ::rice::environment::logging::Logger::FINEST)
                npc(logger)->log(::java::lang::StringBuilder().append(u"getGone choosing node "_j)->append(which)
                    ->append(u" from gone or routing table"_j)->toString());

            auto it = npc(npc(gone)->values())->iterator();
            while (which > 0 && npc(it)->hasNext()) {
                which--;
                npc(it)->next();
            }
            if(npc(it)->hasNext()) {
                if(npc(logger)->level <= ::rice::environment::logging::Logger::FINEST)
                    npc(logger)->log(::java::lang::StringBuilder().append(u"getGone chose node from gone "_j)->append(which)->toString());

                return npc((java_cast< PartitionHandler_GoneSetEntry* >(java_cast< PartitionHandler_GoneSetEntry* >(npc(it)->next()))))->nh;
            }
        }
    }
    auto rtHandles = getRoutingTableAsList();
    if(npc(rtHandles)->isEmpty()) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
            npc(logger)->log(u"getGone returning null; routing table is empty!"_j);

        return nullptr;
    }
    auto which = npc(npc(env)->getRandomSource())->nextInt(npc(rtHandles)->size());
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINEST)
        npc(logger)->log(::java::lang::StringBuilder().append(u"getGone choosing node "_j)->append(which)
            ->append(u" from routing table"_j)->toString());

    return java_cast< ::rice::pastry::NodeHandle* >(java_cast< ::java::lang::Object* >(npc(rtHandles)->get(which)));
}

void rice::pastry::standard::PartitionHandler::getNodeHandleToProbe(::rice::Continuation* c)
{
    if(npc(npc(env)->getRandomSource())->nextDouble() > bootstrapRate) {
        auto nh = getCandidateNode();
        if(npc(logger)->level <= ::rice::environment::logging::Logger::FINEST)
            npc(logger)->log(::java::lang::StringBuilder().append(u"getGone chose "_j)->append(static_cast< ::java::lang::Object* >(nh))->toString());

        if(nh != nullptr) {
            npc(c)->receiveResult(nh);
            return;
        }
    }
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINEST)
        npc(logger)->log(u"getNodeHandleToProbe choosing bootstrap"_j);

    npc(factory)->getNodeHandle(bootstraps, c);
}

void rice::pastry::standard::PartitionHandler::run()
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
        npc(logger)->log(u"running partition handler"_j);

    doGoneMaintainence();
    getNodeHandleToProbe(new PartitionHandler_run_1(this));
}

void rice::pastry::standard::PartitionHandler::nodeSetUpdate(::rice::pastry::NodeSetEventSource* nodeSetEventSource, ::rice::pastry::NodeHandle* handle, bool added)
{
    if(npc(nodeSetEventSource)->equals(npc(pastryNode)->getLeafSet())) {
        if(added) {
            {
                synchronized synchronized_1(this);
                {
                    npc(gone)->remove(npc(handle)->getId());
                }
            }
        }
    }
    if(!added) {
        {
            synchronized synchronized_2(this);
            {
                if(npc(handle)->getLiveness() == ::rice::pastry::NodeHandle::LIVENESS_DEAD) {
                    if(npc(gone)->containsKey(npc(handle)->getId())) {
                        if(npc(logger)->level <= ::rice::environment::logging::Logger::FINEST)
                            npc(logger)->log(::java::lang::StringBuilder().append(u"PartitionHandler updating node "_j)->append(static_cast< ::java::lang::Object* >(handle))->toString());

                        npc((java_cast< PartitionHandler_GoneSetEntry* >(java_cast< PartitionHandler_GoneSetEntry* >(npc(gone)->get(npc(handle)->getId())))))->nh = handle;
                    } else {
                        auto g = new PartitionHandler_GoneSetEntry(handle, npc(npc(env)->getTimeSource())->currentTimeMillis());
                        if(npc(logger)->level <= ::rice::environment::logging::Logger::FINEST)
                            npc(logger)->log(::java::lang::StringBuilder().append(u"PartitionHandler adding node "_j)->append(static_cast< ::java::lang::Object* >(g))->toString());

                        npc(gone)->put(npc(handle)->getId(), g);
                    }
                }
            }
        }
    }
}

void rice::pastry::standard::PartitionHandler::start(::rice::selector::Timer* timer)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
        npc(logger)->log(u"installing partition handler"_j);

    npc(timer)->schedule(this, npc(npc(env)->getParameters())->getInt(u"partition_handler_check_interval"_j), npc(npc(env)->getParameters())->getInt(u"partition_handler_check_interval"_j));
}

void rice::pastry::standard::PartitionHandler::rejoin(::rice::pastry::NodeHandle* target)
{
    auto jr = new ::rice::pastry::join::JoinRequest(npc(pastryNode)->getLocalHandle(), npc(npc(pastryNode)->getRoutingTable())->baseBitLength());
    auto rm = new ::rice::pastry::routing::RouteMessage(npc(npc(pastryNode)->getLocalHandle())->getNodeId(), static_cast< ::rice::pastry::messaging::PRawMessage* >(jr), static_cast< ::rice::pastry::NodeHandle* >(nullptr), static_cast< ::rice::pastry::routing::SendOptions* >(nullptr), static_cast< int8_t >(npc(npc(env)->getParameters())->getInt(u"pastry_protocol_router_routeMsgVersion"_j)));
    npc(rm)->setPrevNode(npc(pastryNode)->getLocalHandle());
    npc(npc(rm)->getOptions())->setRerouteIfSuspected(false);
    auto nh = npc(pastryNode)->coalesce(target);
    try {
        npc(nh)->bootstrap(rm);
    } catch (::java::io::IOException* ioe) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(logger)->logException(u"Error bootstrapping."_j, ioe);

    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::standard::PartitionHandler::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.standard.PartitionHandler", 37);
    return c;
}

java::lang::Class* rice::pastry::standard::PartitionHandler::getClass0()
{
    return class_();
}

