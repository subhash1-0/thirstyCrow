// Generated from /pastry-2.1/src/rice/pastry/pns/PNSApplication.java
#include <rice/pastry/pns/PNSApplication.hpp>

#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/Class.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/Integer.hpp>
#include <java/lang/Iterable.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/util/ArrayList.hpp>
#include <java/util/Collection.hpp>
#include <java/util/Collections.hpp>
#include <java/util/HashMap.hpp>
#include <java/util/HashSet.hpp>
#include <java/util/Iterator.hpp>
#include <java/util/List.hpp>
#include <java/util/Map.hpp>
#include <java/util/Observable.hpp>
#include <java/util/Observer.hpp>
#include <java/util/Set.hpp>
#include <org/mpisws/p2p/transport/proximity/ProximityListener.hpp>
#include <rice/Continuation.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/LogManager.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/environment/params/Parameters.hpp>
#include <rice/p2p/commonapi/Cancellable.hpp>
#include <rice/p2p/commonapi/NodeHandle.hpp>
#include <rice/p2p/commonapi/NodeHandleSet.hpp>
#include <rice/p2p/commonapi/rawserialization/RawSerializable.hpp>
#include <rice/p2p/util/AttachableCancellable.hpp>
#include <rice/p2p/util/tuples/MutableTuple.hpp>
#include <rice/p2p/util/tuples/Tuple.hpp>
#include <rice/pastry/Id.hpp>
#include <rice/pastry/NodeHandle.hpp>
#include <rice/pastry/NodeSetI.hpp>
#include <rice/pastry/PastryNode.hpp>
#include <rice/pastry/leafset/LeafSet.hpp>
#include <rice/pastry/messaging/Message.hpp>
#include <rice/pastry/pns/PNSApplication_getLeafSet_2.hpp>
#include <rice/pastry/pns/PNSApplication_getLeafSet_3.hpp>
#include <rice/pastry/pns/PNSApplication_getLeafSet_4.hpp>
#include <rice/pastry/pns/PNSApplication_getRouteRow_5.hpp>
#include <rice/pastry/pns/PNSApplication_getRouteRow_6.hpp>
#include <rice/pastry/pns/PNSApplication_getRouteRow_7.hpp>
#include <rice/pastry/pns/PNSApplication_getProximity_8.hpp>
#include <rice/pastry/pns/PNSApplication_getProximity_9.hpp>
#include <rice/pastry/pns/PNSApplication_sortedProximityCache_10.hpp>
#include <rice/pastry/pns/PNSApplication_getNearest_11.hpp>
#include <rice/pastry/pns/PNSApplication_getNearest_12.hpp>
#include <rice/pastry/pns/PNSApplication_seekThroughRouteRows_13.hpp>
#include <rice/pastry/pns/PNSApplication_closestToMe_14.hpp>
#include <rice/pastry/pns/PNSApplication_getNearHandles_1.hpp>
#include <rice/pastry/pns/PNSApplication_PNSDeserializer.hpp>
#include <rice/pastry/pns/messages/LeafSetRequest.hpp>
#include <rice/pastry/pns/messages/LeafSetResponse.hpp>
#include <rice/pastry/pns/messages/RouteRowRequest.hpp>
#include <rice/pastry/pns/messages/RouteRowResponse.hpp>
#include <rice/pastry/routing/RouteSet.hpp>
#include <rice/pastry/routing/RoutingTable.hpp>
#include <rice/pastry/transport/PMessageReceipt.hpp>
#include <rice/selector/SelectorManager.hpp>
#include <rice/selector/TimerTask.hpp>
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

    namespace lang
    {
typedef ::SubArray< ::java::lang::Iterable, ObjectArray > IterableArray;
    } // lang

    namespace util
    {
typedef ::SubArray< ::java::util::Collection, ::java::lang::ObjectArray, ::java::lang::IterableArray > CollectionArray;
typedef ::SubArray< ::java::util::Observable, ::java::lang::ObjectArray > ObservableArray;
typedef ::SubArray< ::java::util::Observer, ::java::lang::ObjectArray > ObserverArray;
    } // util
} // java

namespace rice
{
    namespace p2p
    {
        namespace commonapi
        {
typedef ::SubArray< ::rice::p2p::commonapi::NodeHandle, ::java::util::ObservableArray, ::java::io::SerializableArray > NodeHandleArray;
typedef ::SubArray< ::rice::p2p::commonapi::NodeHandleSet, ::java::lang::ObjectArray, ::java::io::SerializableArray > NodeHandleSetArray;

            namespace rawserialization
            {
typedef ::SubArray< ::rice::p2p::commonapi::rawserialization::RawSerializable, ::java::lang::ObjectArray > RawSerializableArray;
            } // rawserialization
        } // commonapi
    } // p2p

    namespace pastry
    {
typedef ::SubArray< ::rice::pastry::NodeHandle, ::rice::p2p::commonapi::NodeHandleArray, ::rice::p2p::commonapi::rawserialization::RawSerializableArray > NodeHandleArray;
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
rice::pastry::pns::PNSApplication::PNSApplication(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::pns::PNSApplication::PNSApplication(::rice::pastry::PastryNode* pn) 
    : PNSApplication(*static_cast< ::default_init_tag* >(0))
{
    ctor(pn);
}

rice::pastry::pns::PNSApplication::PNSApplication(::rice::pastry::PastryNode* pn, ::rice::environment::logging::Logger* logger) 
    : PNSApplication(*static_cast< ::default_init_tag* >(0))
{
    ctor(pn,logger);
}

void rice::pastry::pns::PNSApplication::init()
{
    pingCache = new ::java::util::HashMap();
    waitingForLeafSet = new ::java::util::HashMap();
    waitingForRouteRow = new ::java::util::HashMap();
    waitingForPing = new ::java::util::HashMap();
}

constexpr int32_t rice::pastry::pns::PNSApplication::DEFAULT_PROXIMITY;

void rice::pastry::pns::PNSApplication::ctor(::rice::pastry::PastryNode* pn)
{
    ctor(pn, npc(npc(npc(pn)->getEnvironment())->getLogManager())->getLogger(PNSApplication::class_(), nullptr));
}

void rice::pastry::pns::PNSApplication::ctor(::rice::pastry::PastryNode* pn, ::rice::environment::logging::Logger* logger)
{
    super::ctor(pn, nullptr, int32_t(0), nullptr, logger);
    init();
    setDeserializer(new PNSApplication_PNSDeserializer(this));
    this->environment = npc(pn)->getEnvironment();
    rtBase = static_cast< int8_t >(npc(npc(environment)->getParameters())->getInt(u"pastry_rtBaseBitLength"_j));
    depth = static_cast< int16_t >((::rice::pastry::Id::IdBitLength / rtBase));
}

bool rice::pastry::pns::PNSApplication::deliverWhenNotReady()
{
    return true;
}

void rice::pastry::pns::PNSApplication::messageForAppl(::rice::pastry::messaging::Message* msg)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
        npc(logger)->log(::java::lang::StringBuilder().append(u"messageForAppl("_j)->append(static_cast< ::java::lang::Object* >(msg))
            ->append(u")"_j)->toString());

    if(dynamic_cast< ::rice::pastry::pns::messages::LeafSetRequest* >(msg) != nullptr) {
        auto req = java_cast< ::rice::pastry::pns::messages::LeafSetRequest* >(msg);
        npc(thePastryNode)->send(npc(req)->getSender(), new ::rice::pastry::pns::messages::LeafSetResponse(npc(thePastryNode)->getLeafSet(), getAddress()), nullptr, nullptr);
        return;
    }
    if(dynamic_cast< ::rice::pastry::pns::messages::LeafSetResponse* >(msg) != nullptr) {
        auto response = java_cast< ::rice::pastry::pns::messages::LeafSetResponse* >(msg);
        {
            synchronized synchronized_0(waitingForLeafSet);
            {
                auto ls = npc(response)->leafset;
                auto waiters = java_cast< ::java::util::Collection* >(npc(waitingForLeafSet)->remove(npc(ls)->get(0)));
                if(waiters != nullptr) {
                    for (auto _i = npc(waiters)->iterator(); _i->hasNext(); ) {
                        ::rice::p2p::util::tuples::Tuple* w = java_cast< ::rice::p2p::util::tuples::Tuple* >(_i->next());
                        {
                            npc(java_cast< ::rice::p2p::commonapi::Cancellable* >(npc(w)->b()))->cancel();
                            npc(java_cast< ::rice::Continuation* >(npc(w)->a()))->receiveResult(ls);
                        }
                    }
                }
            }
        }
        return;
    }
    if(dynamic_cast< ::rice::pastry::pns::messages::RouteRowRequest* >(msg) != nullptr) {
        auto req = java_cast< ::rice::pastry::pns::messages::RouteRowRequest* >(msg);
        npc(thePastryNode)->send(npc(req)->getSender(), new ::rice::pastry::pns::messages::RouteRowResponse(npc(thePastryNode)->getLocalHandle(), npc(req)->index, npc(npc(thePastryNode)->getRoutingTable())->getRow(npc(req)->index), getAddress()), nullptr, nullptr);
        return;
    }
    if(dynamic_cast< ::rice::pastry::pns::messages::RouteRowResponse* >(msg) != nullptr) {
        auto response = java_cast< ::rice::pastry::pns::messages::RouteRowResponse* >(msg);
        {
            synchronized synchronized_1(waitingForRouteRow);
            {
                auto waiters = java_cast< ::java::util::CollectionArray* >(npc(waitingForRouteRow)->get(npc(response)->getSender()));
                if(waiters != nullptr) {
                    if((*waiters)[npc(response)->index] != nullptr) {
                        for (auto _i = new ::java::util::ArrayList(static_cast< ::java::util::Collection* >((*waiters)[npc(response)->index]))->iterator(); _i->hasNext(); ) {
                            ::rice::p2p::util::tuples::Tuple* w = java_cast< ::rice::p2p::util::tuples::Tuple* >(_i->next());
                            {
                                npc(java_cast< ::rice::p2p::commonapi::Cancellable* >(npc(w)->b()))->cancel();
                                npc(java_cast< ::rice::Continuation* >(npc(w)->a()))->receiveResult(npc(response)->row);
                            }
                        }
                        npc((*waiters)[npc(response)->index])->clear();
                        waiters->set(npc(response)->index, nullptr);
                        auto deleteIt = true;
                        for (auto i = int32_t(0); i < depth; i++) {
                            if((*waiters)[i] != nullptr) {
                                deleteIt = false;
                                break;
                            }
                        }
                        if(deleteIt)
                            npc(waitingForRouteRow)->remove(npc(response)->getSender());

                    }
                }
            }
        }
        return;
    }
    if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
        npc(logger)->log(::java::lang::StringBuilder().append(u"unrecognized message in messageForAppl("_j)->append(static_cast< ::java::lang::Object* >(msg))
            ->append(u")"_j)->toString());

}

rice::p2p::commonapi::Cancellable* rice::pastry::pns::PNSApplication::getNearHandles(::java::util::Collection* bootHandles, ::rice::Continuation* deliverResultToMe)
{
    if(bootHandles == nullptr || npc(bootHandles)->size() == 0 || java_cast< ::rice::pastry::NodeHandle* >(npc(npc(bootHandles)->iterator())->next()) == nullptr) {
        npc(deliverResultToMe)->receiveResult(bootHandles);
        return nullptr;
    }
    auto const ret = new ::rice::p2p::util::AttachableCancellable();
    ::java::util::Collection* const remaining = new ::java::util::HashSet(static_cast< ::java::util::Collection* >(bootHandles));
    npc(thePastryNode)->addProximityListener(static_cast< ::org::mpisws::p2p::transport::proximity::ProximityListener* >(this));
    auto const best = new ::rice::p2p::util::tuples::MutableTuple();
    for (auto _i = npc(bootHandles)->iterator(); _i->hasNext(); ) {
        ::rice::pastry::NodeHandle* nh = java_cast< ::rice::pastry::NodeHandle* >(_i->next());
        {
            auto const handle = nh;
            ::rice::Continuation* c = new PNSApplication_getNearHandles_1(this, handle, best, ret, bootHandles, deliverResultToMe, remaining);
            getProximity(handle, c, 10000);
        }
    }
    return ret;
}

java::util::List* rice::pastry::pns::PNSApplication::getNearHandlesHelper(::java::util::List* handles)
{
    return handles;
}

rice::p2p::commonapi::Cancellable* rice::pastry::pns::PNSApplication::getLeafSet(::rice::pastry::NodeHandle* handle, ::rice::Continuation* c)
{
    ::rice::p2p::util::AttachableCancellable* const cancellable = new PNSApplication_getLeafSet_2(this, handle, c);
    ::rice::selector::TimerTask* const task = new PNSApplication_getLeafSet_3(this, cancellable, c, handle);
    addToWaitingForLeafSet(handle, c, task);
    npc(cancellable)->attach(task);
    npc(cancellable)->attach(npc(thePastryNode)->send(handle, new ::rice::pastry::pns::messages::LeafSetRequest(this->getNodeHandle(), this->getAddress()), new PNSApplication_getLeafSet_4(this, cancellable, c), nullptr));
    return cancellable;
}

void rice::pastry::pns::PNSApplication::addToWaitingForLeafSet(::rice::pastry::NodeHandle* handle, ::rice::Continuation* c, ::rice::p2p::commonapi::Cancellable* cancelMeWhenSuccess)
{
    {
        synchronized synchronized_2(waitingForLeafSet);
        {
            auto waiters = java_cast< ::java::util::Collection* >(npc(waitingForLeafSet)->get(handle));
            if(waiters == nullptr) {
                waiters = new ::java::util::ArrayList();
                npc(waitingForLeafSet)->put(handle, waiters);
            }
            npc(waiters)->add(new ::rice::p2p::util::tuples::Tuple(c, cancelMeWhenSuccess));
        }
    }
}

bool rice::pastry::pns::PNSApplication::removeFromWaitingForLeafSet(::rice::pastry::NodeHandle* handle, ::rice::Continuation* c)
{
    {
        synchronized synchronized_3(waitingForLeafSet);
        {
            auto waiters = java_cast< ::java::util::Collection* >(npc(waitingForLeafSet)->get(handle));
            if(waiters == nullptr)
                return false;

            auto ret = false;
            auto i = npc(waiters)->iterator();
            while (npc(i)->hasNext()) {
                auto foo = java_cast< ::rice::p2p::util::tuples::Tuple* >(npc(i)->next());
                if(npc(java_cast< ::rice::Continuation* >(npc(foo)->a()))->equals(c)) {
                    ret = true;
                    npc(java_cast< ::rice::p2p::commonapi::Cancellable* >(npc(foo)->b()))->cancel();
                    npc(i)->remove();
                }
            }
            if(npc(waiters)->isEmpty())
                npc(waitingForLeafSet)->remove(handle);

            return ret;
        }
    }
}

rice::p2p::commonapi::Cancellable* rice::pastry::pns::PNSApplication::getRouteRow(::rice::pastry::NodeHandle* handle, int16_t row, ::rice::Continuation* c)
{
    ::rice::p2p::util::AttachableCancellable* const cancellable = new PNSApplication_getRouteRow_5(this, handle, row, c);
    ::rice::selector::TimerTask* const task = new PNSApplication_getRouteRow_6(this, cancellable, c, handle);
    addToWaitingForRouteRow(handle, row, c, task);
    npc(cancellable)->attach(task);
    npc(cancellable)->attach(npc(thePastryNode)->send(handle, new ::rice::pastry::pns::messages::RouteRowRequest(this->getNodeHandle(), row, this->getAddress()), new PNSApplication_getRouteRow_7(this, cancellable, c), nullptr));
    return cancellable;
}

void rice::pastry::pns::PNSApplication::addToWaitingForRouteRow(::rice::pastry::NodeHandle* handle, int32_t row, ::rice::Continuation* c, ::rice::p2p::commonapi::Cancellable* cancelMeWhenSuccess)
{
    {
        synchronized synchronized_4(waitingForRouteRow);
        {
            auto waiters = java_cast< ::java::util::CollectionArray* >(npc(waitingForRouteRow)->get(handle));
            if(waiters == nullptr) {
                waiters = new ::java::util::CollectionArray(depth);
                npc(waitingForRouteRow)->put(handle, waiters);
            }
            if((*waiters)[row] == nullptr) {
                waiters->set(row, new ::java::util::ArrayList());
            }
            npc((*waiters)[row])->add(new ::rice::p2p::util::tuples::Tuple(c, cancelMeWhenSuccess));
        }
    }
}

bool rice::pastry::pns::PNSApplication::removeFromWaitingForRouteRow(::rice::pastry::NodeHandle* handle, int32_t row, ::rice::Continuation* c)
{
    {
        synchronized synchronized_5(waitingForRouteRow);
        {
            auto waiters = java_cast< ::java::util::CollectionArray* >(npc(waitingForRouteRow)->get(handle));
            if(waiters == nullptr)
                return false;

            if((*waiters)[row] == nullptr)
                return false;

            auto ret = false;
            auto it = npc((*waiters)[row])->iterator();
            while (npc(it)->hasNext()) {
                auto foo = java_cast< ::rice::p2p::util::tuples::Tuple* >(npc(it)->next());
                if(npc(java_cast< ::rice::Continuation* >(npc(foo)->a()))->equals(c)) {
                    ret = true;
                    npc(java_cast< ::rice::p2p::commonapi::Cancellable* >(npc(foo)->b()))->cancel();
                    npc(it)->remove();
                }
            }
            if(npc((*waiters)[row])->isEmpty()) {
                waiters->set(row, nullptr);
            }
            auto deleteIt = true;
            for (auto i = int32_t(0); i < depth; i++) {
                if((*waiters)[i] != nullptr) {
                    deleteIt = false;
                    break;
                }
            }
            if(deleteIt)
                npc(waitingForRouteRow)->remove(handle);

            return ret;
        }
    }
}

rice::p2p::commonapi::Cancellable* rice::pastry::pns::PNSApplication::getProximity(::rice::pastry::NodeHandle* handle, ::rice::Continuation* c, int32_t timeout)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINEST)
        npc(logger)->log(::java::lang::StringBuilder().append(u"getProximity("_j)->append(static_cast< ::java::lang::Object* >(handle))
            ->append(u")"_j)->toString());

    int32_t prox;
    {
        synchronized synchronized_6(waitingForPing);
        {
            prox = npc(thePastryNode)->proximity(handle);
            if(prox == DEFAULT_PROXIMITY) {
                if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
                    npc(logger)->log(::java::lang::StringBuilder().append(u"getProximity("_j)->append(static_cast< ::java::lang::Object* >(handle))
                        ->append(u"): waiting for proximity update"_j)->toString());

                auto waiters = java_cast< ::java::util::Collection* >(npc(waitingForPing)->get(handle));
                if(waiters == nullptr) {
                    waiters = new ::java::util::ArrayList();
                    npc(waitingForPing)->put(handle, waiters);
                }
                npc(waiters)->add(c);
                ::rice::p2p::util::AttachableCancellable* const cancellable = new PNSApplication_getProximity_8(this, handle, c);
                ::rice::selector::TimerTask* task = new PNSApplication_getProximity_9(this, cancellable, c, handle);
                npc(cancellable)->attach(task);
                npc(npc(environment)->getSelectorManager())->schedule(task, static_cast< int64_t >(timeout));
                return cancellable;
            }
        }
    }
    {
        synchronized synchronized_7(pingCache);
        {
            npc(pingCache)->put(handle, ::java::lang::Integer::valueOf(prox));
        }
    }
    npc(c)->receiveResult(::java::lang::Integer::valueOf(prox));
    return nullptr;
}

void rice::pastry::pns::PNSApplication::proximityChanged(::rice::pastry::NodeHandle* i, int32_t newProximity, ::java::util::Map* options)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(::java::lang::StringBuilder().append(u"proximityChanged("_j)->append(static_cast< ::java::lang::Object* >(i))
            ->append(u","_j)
            ->append(newProximity)
            ->append(u")"_j)->toString());

    {
        synchronized synchronized_8(pingCache);
        {
            npc(pingCache)->put(i, ::java::lang::Integer::valueOf(newProximity));
        }
    }
    {
        synchronized synchronized_9(waitingForPing);
        {
            if(npc(waitingForPing)->containsKey(i)) {
                auto waiting = java_cast< ::java::util::Collection* >(npc(waitingForPing)->remove(i));
                for (auto _i = npc(waiting)->iterator(); _i->hasNext(); ) {
                    ::rice::Continuation* c = java_cast< ::rice::Continuation* >(_i->next());
                    {
                        npc(c)->receiveResult(::java::lang::Integer::valueOf(newProximity));
                    }
                }
            }
        }
    }
}

void rice::pastry::pns::PNSApplication::proximityChanged(::java::lang::Object* i, int32_t newProximity, ::java::util::Map* options)
{ 
    proximityChanged(dynamic_cast< ::rice::pastry::NodeHandle* >(i), newProximity, options);
}

void rice::pastry::pns::PNSApplication::purgeProximityCache()
{
    npc(pingCache)->clear();
}

java::util::List* rice::pastry::pns::PNSApplication::sortedProximityCache()
{
    auto handles = new ::java::util::ArrayList(static_cast< ::java::util::Collection* >(npc(pingCache)->keySet()));
    ::java::util::Collections::sort(handles, new PNSApplication_sortedProximityCache_10(this));
    return handles;
}

rice::p2p::commonapi::Cancellable* rice::pastry::pns::PNSApplication::getNearest(::rice::pastry::NodeHandle* seed, ::rice::Continuation* retToMe)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(::java::lang::StringBuilder().append(u"getNearest("_j)->append(static_cast< ::java::lang::Object* >(seed))
            ->append(u")"_j)->toString());

    if(seed == nullptr) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(logger)->logException(::java::lang::StringBuilder().append(u"getNearest("_j)->append(static_cast< ::java::lang::Object* >(seed))
                ->append(u")"_j)->toString(), new ::java::lang::Exception(u"Stack Trace"_j));

        npc(npc(environment)->getSelectorManager())->invoke(new PNSApplication_getNearest_11(this, retToMe));
        return nullptr;
    }
    auto const ret = new ::rice::p2p::util::AttachableCancellable();
    npc(ret)->attach(getLeafSet(seed, new PNSApplication_getNearest_12(this, seed, ret, retToMe)));
    return ret;
}

rice::p2p::commonapi::Cancellable* rice::pastry::pns::PNSApplication::seekThroughRouteRows(int16_t i, int16_t depth, ::rice::pastry::NodeHandle* currentClosest, ::rice::Continuation* returnToMe)
{
    auto const ret = new ::rice::p2p::util::AttachableCancellable();
    npc(ret)->attach(getRouteRow(currentClosest, i, new PNSApplication_seekThroughRouteRows_13(this, ret, currentClosest, i, depth, returnToMe)));
    return ret;
}

rice::p2p::commonapi::Cancellable* rice::pastry::pns::PNSApplication::closestToMe(::rice::pastry::NodeHandle* handle, ::rice::pastry::leafset::LeafSet* leafSet, ::rice::Continuation* c)
{
    if(leafSet == nullptr) {
        npc(c)->receiveResult(handle);
        return nullptr;
    }
    auto handles = new ::java::util::HashSet();
    for (auto i = int32_t(1); i <= npc(leafSet)->cwSize(); i++) 
                npc(handles)->add(static_cast< ::java::lang::Object* >(npc(leafSet)->get(i)));

    for (auto i = -npc(leafSet)->ccwSize(); i < 0; i++) 
                npc(handles)->add(static_cast< ::java::lang::Object* >(npc(leafSet)->get(i)));

    return closestToMe(handle, static_cast< ::java::util::Collection* >(handles), c);
}

rice::p2p::commonapi::Cancellable* rice::pastry::pns::PNSApplication::closestToMe(::rice::pastry::NodeHandle* handle, ::rice::pastry::routing::RouteSetArray* routeSets, ::rice::Continuation* c)
{
    auto handles = new ::java::util::ArrayList();
    for (auto i = int32_t(0); i < npc(routeSets)->length; i++) {
        auto set = (*routeSets)[i];
        if(set != nullptr) {
            for (auto j = int32_t(0); j < npc(set)->size(); j++) 
                                npc(handles)->add(static_cast< ::java::lang::Object* >(npc(set)->get(j)));

        }
    }
    return closestToMe(handle, static_cast< ::java::util::Collection* >(handles), c);
}

rice::p2p::commonapi::Cancellable* rice::pastry::pns::PNSApplication::closestToMe(::rice::pastry::NodeHandle* handle, ::java::util::Collection* handles, ::rice::Continuation* c)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(::java::lang::StringBuilder().append(u"closestToMe("_j)->append(static_cast< ::java::lang::Object* >(handle))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(handles))
            ->append(u")"_j)->toString());

    auto const ret = new ::rice::p2p::util::AttachableCancellable();
    auto const closestNode = (new ::rice::pastry::NodeHandleArray({handle}));
    ::java::util::Collection* const remaining = new ::java::util::HashSet(static_cast< ::java::util::Collection* >(handles));
    if(!npc(remaining)->contains(handle))
        npc(remaining)->add(handle);

    auto const nearestdist = (new ::int32_tArray({::java::lang::Integer::MAX_VALUE}));
    auto temp = new ::java::util::ArrayList(static_cast< ::java::util::Collection* >(remaining));
    for (auto _i = npc(temp)->iterator(); _i->hasNext(); ) {
        ::rice::pastry::NodeHandle* nh = java_cast< ::rice::pastry::NodeHandle* >(_i->next());
        {
            auto const tempNode = nh;
            if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
                npc(logger)->log(::java::lang::StringBuilder().append(u"closestToMe checking prox on "_j)->append(static_cast< ::java::lang::Object* >(tempNode))
                    ->append(u"("_j)
                    ->append(static_cast< ::java::lang::Object* >(handle))
                    ->append(u","_j)
                    ->append(static_cast< ::java::lang::Object* >(handles))
                    ->append(u")"_j)->toString());

            npc(ret)->attach(getProximity(handle, new PNSApplication_closestToMe_14(this, tempNode, handle, handles, remaining, nearestdist, closestNode, ret, c), 10000));
        }
    }
    return ret;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::pns::PNSApplication::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.pns.PNSApplication", 30);
    return c;
}

rice::pastry::leafset::LeafSet* rice::pastry::pns::PNSApplication::getLeafSet()
{
    return super::getLeafSet();
}

java::lang::Class* rice::pastry::pns::PNSApplication::getClass0()
{
    return class_();
}

