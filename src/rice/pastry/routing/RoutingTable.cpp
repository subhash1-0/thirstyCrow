// Generated from /pastry-2.1/src/rice/pastry/routing/RoutingTable.java
#include <rice/pastry/routing/RoutingTable.hpp>

#include <java/io/Serializable.hpp>
#include <java/lang/ArrayIndexOutOfBoundsException.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/CharSequence.hpp>
#include <java/lang/Class.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Cloneable.hpp>
#include <java/lang/Comparable.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/Integer.hpp>
#include <java/lang/Iterable.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/util/ArrayList.hpp>
#include <java/util/Collections.hpp>
#include <java/util/HashSet.hpp>
#include <java/util/Iterator.hpp>
#include <java/util/List.hpp>
#include <java/util/Observer.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/LogManager.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/p2p/commonapi/Id_Distance.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/commonapi/NodeHandleSet.hpp>
#include <rice/pastry/Id_Distance.hpp>
#include <rice/pastry/Id.hpp>
#include <rice/pastry/NodeHandle.hpp>
#include <rice/pastry/NodeSet.hpp>
#include <rice/pastry/NodeSetI.hpp>
#include <rice/pastry/NodeSetListener.hpp>
#include <rice/pastry/NodeSetUpdate.hpp>
#include <rice/pastry/PastryNode.hpp>
#include <rice/pastry/routing/RouteSet.hpp>
#include <rice/pastry/routing/RoutingTable_alternateRoutesIterator_1.hpp>
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
typedef ::SubArray< ::java::lang::Cloneable, ObjectArray > CloneableArray;
typedef ::SubArray< ::java::lang::Comparable, ObjectArray > ComparableArray;
typedef ::SubArray< ::java::lang::Iterable, ObjectArray > IterableArray;
typedef ::SubArray< ::java::lang::String, ObjectArray, ::java::io::SerializableArray, ComparableArray, CharSequenceArray > StringArray;
    } // lang

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
typedef ::SubArray< ::rice::pastry::routing::RouteSetArray, ::java::lang::CloneableArray, ::java::io::SerializableArray > RouteSetArrayArray;
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
rice::pastry::routing::RoutingTable::RoutingTable(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::routing::RoutingTable::RoutingTable(::rice::pastry::NodeHandle* me, int32_t max, int8_t base, ::rice::pastry::PastryNode* pn) 
    : RoutingTable(*static_cast< ::default_init_tag* >(0))
{
    ctor(me,max,base,pn);
}

void rice::pastry::routing::RoutingTable::init()
{
    listeners = new ::java::util::ArrayList();
}

void rice::pastry::routing::RoutingTable::ctor(::rice::pastry::NodeHandle* me, int32_t max, int8_t base, ::rice::pastry::PastryNode* pn)
{
    super::ctor();
    init();
    logger = npc(npc(npc(pn)->getEnvironment())->getLogManager())->getLogger(RoutingTable::class_(), nullptr);
    this->pn = pn;
    idBaseBitLength = base;
    myNodeId = npc(me)->getNodeId();
    myNodeHandle = me;
    maxEntries = max;
    cols = int32_t(1) << idBaseBitLength;
    rows = ::rice::pastry::Id::IdBitLength / idBaseBitLength;
    routingTable = new RouteSetArrayArray(rows);
    for (auto i = int32_t(0); i < rows; i++) {
        auto myCol = npc(myNodeId)->getDigit(i, idBaseBitLength);
        (*routingTable)[i]->set(myCol, new RouteSet(maxEntries, i, myCol, pn, myNodeHandle));
        npc((*(*routingTable)[i])[myCol])->setRoutingTable(this);
    }
}

int32_t rice::pastry::routing::RoutingTable::numColumns()
{
    return npc((*routingTable)[int32_t(0)])->length;
}

int16_t rice::pastry::routing::RoutingTable::numRows()
{
    return static_cast< int16_t >(npc(routingTable)->length);
}

int8_t rice::pastry::routing::RoutingTable::baseBitLength()
{
    return idBaseBitLength;
}

rice::pastry::NodeHandle* rice::pastry::routing::RoutingTable::bestAlternateRoute(::rice::pastry::Id* key)
{
    return bestAlternateRoute(::rice::pastry::NodeHandle::LIVENESS_SUSPECTED, key);
}

rice::pastry::NodeHandle* rice::pastry::routing::RoutingTable::bestAlternateRoute(int32_t minLiveness, ::rice::pastry::Id* key)
{
    auto diffDigit = npc(myNodeId)->indexOfMSDD(key, idBaseBitLength);
    if(diffDigit < 0)
        return nullptr;

    auto keyDigit = npc(key)->getDigit(diffDigit, idBaseBitLength);
    auto myDigit = npc(myNodeId)->getDigit(diffDigit, idBaseBitLength);
    auto bestDistance = npc(myNodeId)->distance(key);
    ::rice::pastry::NodeHandle* alt = nullptr;
    auto finished = false;
    for (auto i = int32_t(1); !finished; i++) {
        for (auto j = int32_t(0); j < 2; j++) {
            auto digit = (j == 0) ? (keyDigit + i) & (cols - int32_t(1)) : (keyDigit + cols - i) & (cols - int32_t(1));
            auto rs = getRouteSet(diffDigit, digit);
            for (auto k = int32_t(0); rs != nullptr && k < npc(rs)->size(); k++) {
                auto n = npc(rs)->get(k);
                if(npc(n)->getLiveness() <= minLiveness) {
                    auto nDist = npc(npc(n)->getNodeId())->distance(key);
                    if(npc(bestDistance)->compareTo(static_cast< ::rice::p2p::commonapi::Id_Distance* >(nDist)) > 0) {
                        bestDistance = nDist;
                        alt = n;
                    }
                }
            }
            if(digit == myDigit)
                finished = true;

        }
    }
    return alt;
}

rice::pastry::NodeSet* rice::pastry::routing::RoutingTable::alternateRoutes(::rice::pastry::Id* key, int32_t max)
{
    auto set = new ::rice::pastry::NodeSet();
    auto diffDigit = npc(myNodeId)->indexOfMSDD(key, idBaseBitLength);
    if(diffDigit < 0)
        return set;

    auto keyDigit = npc(key)->getDigit(diffDigit, idBaseBitLength);
    auto myDigit = npc(myNodeId)->getDigit(diffDigit, idBaseBitLength);
    auto myDistance = npc(myNodeId)->distance(key);
    auto finished = false;
    auto count = int32_t(0);
    for (auto i = int32_t(0); !finished; i++) {
        for (auto j = int32_t(0); j < 2; j++) {
            auto digit = (j == 0) ? (keyDigit + i) & (cols - int32_t(1)) : (keyDigit + cols - i) & (cols - int32_t(1));
            auto rs = getRouteSet(diffDigit, digit);
            for (auto k = int32_t(0); rs != nullptr && k < npc(rs)->size(); k++) {
                auto n = npc(rs)->get(k);
                if(npc(n)->isAlive()) {
                    auto nDist = npc(npc(n)->getNodeId())->distance(key);
                    if(npc(myDistance)->compareTo(static_cast< ::rice::p2p::commonapi::Id_Distance* >(nDist)) > 0) {
                        npc(set)->put(n);
                        count++;
                    }
                    if(count >= max) {
                        return set;
                    }
                }
            }
            if(digit == myDigit)
                finished = true;

        }
    }
    return set;
}

java::util::Iterator* rice::pastry::routing::RoutingTable::alternateRoutesIterator(::rice::pastry::Id* key)
{
    auto const diffDigit = npc(myNodeId)->indexOfMSDD(key, idBaseBitLength);
    if(diffDigit < 0)
        return npc(::java::util::Collections::EMPTY_LIST())->iterator();

    auto const myDistance = npc(myNodeId)->distance(key);
    return new RoutingTable_alternateRoutesIterator_1(this, key, diffDigit, myDistance);
}

rice::pastry::routing::RouteSet* rice::pastry::routing::RoutingTable::getRouteSet(int32_t index, int32_t digit)
{
    auto ns = (*(*routingTable)[index])[digit];
    return ns;
}

rice::pastry::routing::RouteSet* rice::pastry::routing::RoutingTable::getBestEntry(::rice::pastry::Id* key)
{
    auto diffDigit = npc(myNodeId)->indexOfMSDD(key, idBaseBitLength);
    if(diffDigit < 0)
        return nullptr;

    auto digit = npc(key)->getDigit(diffDigit, idBaseBitLength);
    return (*(*routingTable)[diffDigit])[digit];
}

rice::pastry::routing::RouteSet* rice::pastry::routing::RoutingTable::makeBestEntry(::rice::pastry::Id* key)
{
    auto diffDigit = npc(myNodeId)->indexOfMSDD(key, idBaseBitLength);
    if(diffDigit < 0)
        return nullptr;

    auto digit = npc(key)->getDigit(diffDigit, idBaseBitLength);
    if((*(*routingTable)[diffDigit])[digit] == nullptr) {
        (*routingTable)[diffDigit]->set(digit, new RouteSet(maxEntries, diffDigit, digit, pn));
        npc((*(*routingTable)[diffDigit])[digit])->setRoutingTable(this);
    }
    return (*(*routingTable)[diffDigit])[digit];
}

bool rice::pastry::routing::RoutingTable::put(::rice::pastry::NodeHandle* handle)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
        npc(logger)->log(::java::lang::StringBuilder().append(u"RT: put("_j)->append(static_cast< ::java::lang::Object* >(handle))
            ->append(u")"_j)->toString());

    auto nid = npc(handle)->getNodeId();
    auto ns = makeBestEntry(nid);
    if(ns != nullptr) {
        return npc(ns)->put(handle);
    }
    return false;
}

constexpr int32_t rice::pastry::routing::RoutingTable::TEST_FAIL_NO_PREFIX_MATCH;

constexpr int32_t rice::pastry::routing::RoutingTable::TEST_FAIL_EXISTING_ARE_BETTER;

constexpr int32_t rice::pastry::routing::RoutingTable::TEST_SUCCESS_BETTER_PROXIMITY;

constexpr int32_t rice::pastry::routing::RoutingTable::TEST_SUCCESS_ENTRY_WAS_DEAD;

constexpr int32_t rice::pastry::routing::RoutingTable::TEST_SUCCESS_AVAILABLE_SPACE;

constexpr int32_t rice::pastry::routing::RoutingTable::TEST_SUCCESS_NO_ENTRIES;

int32_t rice::pastry::routing::RoutingTable::test(::rice::pastry::NodeHandle* handle)
{
    auto key = npc(handle)->getNodeId();
    auto diffDigit = npc(myNodeId)->indexOfMSDD(key, idBaseBitLength);
    if(diffDigit < 0)
        return TEST_FAIL_NO_PREFIX_MATCH;

    auto digit = npc(key)->getDigit(diffDigit, idBaseBitLength);
    if((*(*routingTable)[diffDigit])[digit] == nullptr) {
        return TEST_SUCCESS_NO_ENTRIES;
    }
    auto rs = (*(*routingTable)[diffDigit])[digit];
    if(npc(rs)->size() == 0)
        return TEST_SUCCESS_NO_ENTRIES;

    if(npc(rs)->size() < npc(rs)->capacity())
        return TEST_SUCCESS_AVAILABLE_SPACE;

    auto prox = npc(pn)->proximity(handle);
    if(prox == ::java::lang::Integer::MAX_VALUE)
        return TEST_FAIL_EXISTING_ARE_BETTER;

    for (auto i = int32_t(0); i < npc(rs)->size(); i++) {
        auto nh = npc(rs)->get(i);
        if(!npc(nh)->isAlive())
            return TEST_SUCCESS_ENTRY_WAS_DEAD;

        if(npc(pn)->proximity(nh) > prox)
            return TEST_SUCCESS_BETTER_PROXIMITY;

    }
    return TEST_FAIL_EXISTING_ARE_BETTER;
}

rice::pastry::NodeHandle* rice::pastry::routing::RoutingTable::get(::rice::pastry::Id* nid)
{
    auto ns = getBestEntry(nid);
    if(ns == nullptr)
        return nullptr;

    return npc(ns)->get(nid);
}

rice::pastry::routing::RouteSetArray* rice::pastry::routing::RoutingTable::getRow(int32_t i)
{
    try {
        return (*routingTable)[i];
    } catch (::java::lang::ArrayIndexOutOfBoundsException* aioobe) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(logger)->log(::java::lang::StringBuilder().append(u"Warning, call to RoutingTable.getRow("_j)->append(i)
                ->append(u") max should be "_j)
                ->append((npc(routingTable)->length - int32_t(1)))->toString());

        return nullptr;
    }
}

rice::pastry::NodeHandle* rice::pastry::routing::RoutingTable::remove(::rice::pastry::NodeHandle* nh)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
        npc(logger)->log(::java::lang::StringBuilder().append(u"RT: remove("_j)->append(static_cast< ::java::lang::Object* >(nh))
            ->append(u")"_j)->toString());

    auto ns = getBestEntry(npc(nh)->getNodeId());
    if(ns == nullptr)
        return nullptr;

    return npc(ns)->remove(nh);
}

void rice::pastry::routing::RoutingTable::nodeSetUpdate(::java::lang::Object* o, ::rice::pastry::NodeHandle* handle, bool added)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE) {
        auto rs = java_cast< RouteSet* >(o);
        if(added) {
            npc(logger)->log(::java::lang::StringBuilder().append(u"RT: added("_j)->append(static_cast< ::java::lang::Object* >(handle))
                ->append(u")@("_j)
                ->append(npc(rs)->row)
                ->append(u","_j)
                ->append((*::rice::pastry::Id::tran())[npc(rs)->col])
                ->append(u")"_j)->toString());
        } else {
            npc(logger)->log(::java::lang::StringBuilder().append(u"RT: removed("_j)->append(static_cast< ::java::lang::Object* >(handle))
                ->append(u")@("_j)
                ->append(npc(rs)->row)
                ->append(u","_j)
                ->append((*::rice::pastry::Id::tran())[npc(rs)->col])
                ->append(u")"_j)->toString());
        }
    }
    {
        synchronized synchronized_0(listeners);
        {
            for (auto i = int32_t(0); i < npc(listeners)->size(); i++) {
                npc((java_cast< ::rice::pastry::NodeSetListener* >(java_cast< ::rice::pastry::NodeSetListener* >(npc(listeners)->get(i)))))->nodeSetUpdate(this, handle, added);
            }
        }
    }
    if(countObservers() > 0) {
        setChanged();
        notifyObservers(new ::rice::pastry::NodeSetUpdate(handle, added));
    }
}

java::lang::String* rice::pastry::routing::RoutingTable::toString()
{
    auto s = u"routing table: \n"_j;
    for (auto i = npc(routingTable)->length - int32_t(1); i >= 0; i--) {
        for (auto j = int32_t(0); j < npc((*routingTable)[i])->length; j++) {
            if((*(*routingTable)[i])[j] != nullptr)
                s = ::java::lang::StringBuilder(s).append((::java::lang::StringBuilder().append(u""_j)->append(npc((*(*routingTable)[i])[j])->size())
                    ->append(u"\t"_j)->toString()))->toString();
            else
                s = ::java::lang::StringBuilder(s).append((::java::lang::StringBuilder().append(u""_j)->append(int32_t(0))
                    ->append(u"\t"_j)->toString()))->toString();
        }
        s = ::java::lang::StringBuilder(s).append((u"\n"_j))->toString();
    }
    return s;
}

java::lang::String* rice::pastry::routing::RoutingTable::printSelf()
{
    auto s = ::java::lang::StringBuilder().append(u"routing table for "_j)->append(static_cast< ::java::lang::Object* >(this->myNodeId))
        ->append(u"\n"_j)->toString();
    auto depthToPrint = int32_t(0);
    for (auto i = int32_t(0); i < npc(routingTable)->length; i++) {
        auto sum = int32_t(0);
        for (auto j = int32_t(0); j < npc((*routingTable)[i])->length; j++) {
            if((*(*routingTable)[i])[j] != nullptr)
                sum++;

        }
        if(sum > 1) {
            depthToPrint = i;
            break;
        }
    }
    for (auto i = npc(routingTable)->length - int32_t(1); i >= depthToPrint; i--) {
        for (auto j = int32_t(0); j < npc((*routingTable)[i])->length; j++) {
            auto rs = (*(*routingTable)[i])[j];
            ::rice::pastry::NodeHandle* nh = nullptr;
            if((*(*routingTable)[i])[j] != nullptr) {
                nh = npc(rs)->get(int32_t(0));
            }
            if(nh != nullptr) {
                s = ::java::lang::StringBuilder(s).append((::java::lang::StringBuilder().append(u""_j)->append(npc((java_cast< ::rice::pastry::Id* >((npc(nh)->getId()))))->toStringBare())->toString()))->toString();
                if(npc(nh)->equals(static_cast< ::java::lang::Object* >(myNodeHandle))) {
                    s = ::java::lang::StringBuilder(s).append(u"*"_j)->toString();
                }
            } else {
                s = ::java::lang::StringBuilder(s).append((::java::lang::StringBuilder().append(u""_j)->append(int32_t(0))->toString()))->toString();
            }
            s = ::java::lang::StringBuilder(s).append(u"\t"_j)->toString();
        }
        s = ::java::lang::StringBuilder(s).append((u"\n"_j))->toString();
    }
    return s;
}

int32_t rice::pastry::routing::RoutingTable::numEntries()
{
    auto count = int32_t(0);
    int32_t maxr = numRows();
    auto maxc = numColumns();
    for (auto r = int32_t(0); r < maxr; r++) {
        for (auto c = int32_t(0); c < maxc; c++) {
            auto rs = (*(*routingTable)[r])[c];
            if(rs != nullptr) {
                count += npc(rs)->size();
            }
        }
    }
    return count;
}

int32_t rice::pastry::routing::RoutingTable::numUniqueEntries()
{
    auto set = new ::java::util::HashSet();
    int32_t maxr = numRows();
    auto maxc = numColumns();
    for (auto r = int32_t(0); r < maxr; r++) {
        for (auto c = int32_t(0); c < maxc; c++) {
            auto rs = (*(*routingTable)[r])[c];
            if(rs != nullptr) {
                for (auto i = int32_t(0); i < npc(rs)->size(); i++) {
                    npc(set)->add(static_cast< ::java::lang::Object* >(npc(rs)->get(i)));
                }
            }
        }
    }
    return npc(set)->size();
}

void rice::pastry::routing::RoutingTable::addObserver(::java::util::Observer* o)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
        npc(logger)->logException(u"WARNING: Observer on RoutingTable is deprecated"_j, new ::java::lang::Exception(u"Stack Trace"_j));

    super::addObserver(o);
}

void rice::pastry::routing::RoutingTable::deleteObserver(::java::util::Observer* o)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
        npc(logger)->log(u"WARNING: Observer on RoutingTable is deprecated"_j);

    super::deleteObserver(o);
}

void rice::pastry::routing::RoutingTable::addNodeSetListener(::rice::pastry::NodeSetListener* listener)
{
    {
        synchronized synchronized_1(listeners);
        {
            npc(listeners)->add(static_cast< ::java::lang::Object* >(listener));
        }
    }
}

void rice::pastry::routing::RoutingTable::removeNodeSetListener(::rice::pastry::NodeSetListener* listener)
{
    {
        synchronized synchronized_2(listeners);
        {
            npc(listeners)->remove(static_cast< ::java::lang::Object* >(listener));
        }
    }
}

java::util::List* rice::pastry::routing::RoutingTable::asList()
{
    ::java::util::List* rtHandles = new ::java::util::ArrayList(numEntries());
    for (auto r = int32_t(0); r < numRows(); r++) {
        auto row = getRow(r);
        for (auto c = int32_t(0); c < numColumns(); c++) {
            auto entry = (*row)[c];
            if(entry != nullptr) {
                for (auto i = int32_t(0); i < npc(entry)->size(); i++) {
                    auto nh = npc(entry)->get(i);
                    if(!npc(nh)->equals(static_cast< ::java::lang::Object* >(npc(pn)->getLocalHandle()))) {
                        npc(rtHandles)->add(static_cast< ::java::lang::Object* >(nh));
                    }
                }
            }
        }
    }
    return rtHandles;
}

void rice::pastry::routing::RoutingTable::destroy()
{
    for (auto r = int32_t(0); r < npc(routingTable)->length; r++) {
        for (auto c = int32_t(0); c < npc((*routingTable)[r])->length; c++) {
            if((*(*routingTable)[r])[c] != nullptr) {
                npc((*(*routingTable)[r])[c])->destroy();
                (*routingTable)[r]->set(c, nullptr);
            }
        }
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::routing::RoutingTable::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.routing.RoutingTable", 32);
    return c;
}

java::lang::Class* rice::pastry::routing::RoutingTable::getClass0()
{
    return class_();
}

