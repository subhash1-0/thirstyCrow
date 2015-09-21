// Generated from /pastry-2.1/src/rice/pastry/testing/PastryRegrTest.java
#include <rice/pastry/testing/PastryRegrTest.hpp>

#include <java/io/PrintStream.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/IllegalArgumentException.hpp>
#include <java/lang/Integer.hpp>
#include <java/lang/InterruptedException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/System.hpp>
#include <java/util/Comparator.hpp>
#include <java/util/Date.hpp>
#include <java/util/SortedMap.hpp>
#include <java/util/SortedSet.hpp>
#include <java/util/TreeMap.hpp>
#include <java/util/TreeSet.hpp>
#include <java/util/Vector.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/random/RandomSource.hpp>
#include <rice/environment/time/TimeSource.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/commonapi/RangeCannotBeDeterminedException.hpp>
#include <rice/pastry/Id_Distance.hpp>
#include <rice/pastry/Id.hpp>
#include <rice/pastry/IdRange.hpp>
#include <rice/pastry/NodeHandle.hpp>
#include <rice/pastry/NodeSet.hpp>
#include <rice/pastry/PastryNode.hpp>
#include <rice/pastry/PastryNodeFactory.hpp>
#include <rice/pastry/client/CommonAPIAppl.hpp>
#include <rice/pastry/client/PastryAppl.hpp>
#include <rice/pastry/leafset/InitiateLeafSetMaintenance.hpp>
#include <rice/pastry/leafset/LeafSet.hpp>
#include <rice/pastry/routing/InitiateRouteSetMaintenance.hpp>
#include <rice/pastry/routing/RouteSet.hpp>
#include <rice/pastry/routing/RoutingTable.hpp>
#include <rice/pastry/testing/PastryRegrTest_checkLeafSet_DistComp_1.hpp>
#include <rice/pastry/testing/RegrTestApp.hpp>
#include <Array.hpp>
#include <ObjectArray.hpp>
#include <SubArray.hpp>

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

namespace rice
{
    namespace pastry
    {
        namespace client
        {
typedef ::SubArray< ::rice::pastry::client::PastryAppl, ::java::lang::ObjectArray > PastryApplArray;
typedef ::SubArray< ::rice::pastry::client::CommonAPIAppl, PastryApplArray > CommonAPIApplArray;
        } // client

        namespace testing
        {
typedef ::SubArray< ::rice::pastry::testing::RegrTestApp, ::rice::pastry::client::CommonAPIApplArray > RegrTestAppArray;
        } // testing
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
rice::pastry::testing::PastryRegrTest::PastryRegrTest(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::testing::PastryRegrTest::PastryRegrTest(::rice::environment::Environment* env) 
    : PastryRegrTest(*static_cast< ::default_init_tag* >(0))
{
    ctor(env);
}

void rice::pastry::testing::PastryRegrTest::ctor(::rice::environment::Environment* env)
{
    super::ctor();
    this->environment = env;
    pastryNodes = new ::java::util::Vector();
    pastryNodesSorted = new ::java::util::TreeMap();
    pastryNodesSortedReady = new ::java::util::TreeMap();
    pastryNodesLastAdded = new ::java::util::Vector();
    inConcJoin = false;
    rtApps = new ::java::util::Vector();
}

void rice::pastry::testing::PastryRegrTest::makePastryNode()
{
    auto bootstrap = getBootstrap(npc(pastryNodes)->size() == 0);
    auto pn = generateNode(bootstrap);
    npc(pastryNodes)->addElement(pn);
    npc(pastryNodesSorted)->put(npc(pn)->getNodeId(), pn);
    npc(pastryNodesLastAdded)->clear();
    npc(pastryNodesLastAdded)->addElement(pn);
    auto rta = new RegrTestApp(pn, this);
    npc(rtApps)->addElement(rta);
    registerapp(pn, rta);
    checkLeafSet(rta);
    checkRoutingTable(rta);
}

rice::pastry::PastryNode* rice::pastry::testing::PastryRegrTest::generateNode(::rice::pastry::NodeHandle* bootstrap)
{
    auto pn = npc(factory)->newNode(bootstrap);
    return pn;
}

void rice::pastry::testing::PastryRegrTest::makePastryNode(int32_t num)
{
    auto rta = new RegrTestAppArray(num);
    pause(1000);
    npc(pastryNodesLastAdded)->clear();
    inConcJoin = true;
    auto n = npc(pastryNodes)->size();
    if(n == 0)
        num = 1;

    for (auto i = int32_t(0); i < num; i++) {
        ::rice::pastry::NodeHandle* bootstrap;
        bootstrap = getBootstrap(n == 0);
        auto pn = generateNode(bootstrap);
        npc(pastryNodes)->addElement(pn);
        npc(pastryNodesSorted)->put(npc(pn)->getNodeId(), pn);
        npc(pastryNodesLastAdded)->addElement(pn);
        rta->set(i, new RegrTestApp(pn, this));
        npc(rtApps)->addElement((*rta)[i]);
        registerapp(pn, (*rta)[i]);
        if(bootstrap != nullptr)
            if(n == 0) {
                {
                    synchronized synchronized_0(pn);
                    {
                        while (!npc(pn)->isReady()) {
                            try {
                                npc(pn)->wait(500);
                            } catch (::java::lang::InterruptedException* ie) {
                            }
                        }
                    }
                }
            }

    }
    for (auto i = int32_t(0); i < npc(pastryNodesLastAdded)->size(); i++) {
        auto pn = java_cast< ::rice::pastry::PastryNode* >(java_cast< ::java::lang::Object* >(npc(pastryNodesLastAdded)->get(i)));
        {
            synchronized synchronized_1(pn);
            {
                while (!npc(pn)->isReady()) {
                    try {
                        npc(pn)->wait(500);
                    } catch (::java::lang::InterruptedException* ie) {
                    }
                }
            }
        }
    }
    pause(2500);
    inConcJoin = false;
    for (auto i = int32_t(0); i < num; i++) {
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"created "_j)->append(static_cast< ::java::lang::Object* >(npc((*rta)[i])->getNodeId()))->toString());
        auto pn = npc((*rta)[i])->getPastryNode();
        npc(pastryNodesSortedReady)->put(npc(pn)->getNodeId(), pn);
        checkLeafSet((*rta)[i]);
        checkRoutingTable((*rta)[i]);
    }
    for (auto i = int32_t(0); i < npc(rtApps)->size(); i++) {
    }
}

void rice::pastry::testing::PastryRegrTest::sendPings(int32_t k)
{
    auto n = npc(rtApps)->size();
    for (auto i = int32_t(0); i < k; i++) {
        auto from = npc(npc(environment)->getRandomSource())->nextInt(n);
        auto to = npc(npc(environment)->getRandomSource())->nextInt(n);
        auto keyBytes = new ::int8_tArray(::rice::pastry::Id::IdBitLength / int32_t(8));
        npc(npc(environment)->getRandomSource())->nextBytes(keyBytes);
        auto key = ::rice::pastry::Id::build(keyBytes);
        auto rta = java_cast< RegrTestApp* >(java_cast< ::java::lang::Object* >(npc(rtApps)->get(from)));
        auto pn = java_cast< ::rice::pastry::PastryNode* >(java_cast< ::java::lang::Object* >(npc(pastryNodes)->get(to)));
        npc(rta)->sendTrace(npc(pn)->getNodeId());
        npc(rta)->sendTrace(key);
    }
}

void rice::pastry::testing::PastryRegrTest::checkLeafSet(RegrTestApp* rta)
{
    auto ls = npc(rta)->getLeafSet();
    auto localId = npc(rta)->getNodeId();
    if(npc(ls)->size() < npc(ls)->maxSize() && (npc(pastryNodesSorted)->size() - int32_t(1)) * int32_t(2) != npc(ls)->size())
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"checkLeafSet: incorrect size "_j)->append(static_cast< ::java::lang::Object* >(npc(rta)->getNodeId()))
            ->append(u" ls.size()="_j)
            ->append(npc(ls)->size())
            ->append(u" total nodes="_j)
            ->append(npc(pastryNodesSorted)->size())
            ->append(u"\n"_j)
            ->append(static_cast< ::java::lang::Object* >(ls))->toString());

    for (auto i = -npc(ls)->ccwSize(); i < 0; i++) {
        auto nh = npc(ls)->get(i);
        if(!npc(nh)->isAlive())
            npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"checkLeafSet: dead node handle "_j)->append(static_cast< ::java::lang::Object* >(npc(nh)->getNodeId()))
                ->append(u" in leafset at "_j)
                ->append(static_cast< ::java::lang::Object* >(npc(rta)->getNodeId()))
                ->append(u"\n"_j)
                ->append(static_cast< ::java::lang::Object* >(ls))->toString());

        auto nid = npc(npc(ls)->get(i))->getNodeId();
        int32_t inBetween;
        if(npc(localId)->compareTo(static_cast< ::rice::p2p::commonapi::Id* >(nid)) > 0)
            inBetween = npc(npc(pastryNodesSorted)->subMap(nid, localId))->size();
        else
            inBetween = npc(npc(pastryNodesSorted)->tailMap(nid))->size() + npc(npc(pastryNodesSorted)->headMap(localId))->size();
        if(inBetween != -i)
            npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"checkLeafSet: failure at"_j)->append(static_cast< ::java::lang::Object* >(npc(rta)->getNodeId()))
                ->append(u"i="_j)
                ->append(i)
                ->append(u" inBetween="_j)
                ->append(inBetween)
                ->append(u"\n"_j)
                ->append(static_cast< ::java::lang::Object* >(ls))->toString());

    }
    for (auto i = int32_t(1); i <= npc(ls)->cwSize(); i++) {
        auto nh = npc(ls)->get(i);
        if(!npc(nh)->isAlive())
            npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"checkLeafSet: dead node handle "_j)->append(static_cast< ::java::lang::Object* >(npc(nh)->getNodeId()))
                ->append(u" in leafset at "_j)
                ->append(static_cast< ::java::lang::Object* >(npc(rta)->getNodeId()))
                ->append(u"\n"_j)
                ->append(static_cast< ::java::lang::Object* >(ls))->toString());

        auto nid = npc(npc(ls)->get(i))->getNodeId();
        int32_t inBetween;
        if(npc(localId)->compareTo(static_cast< ::rice::p2p::commonapi::Id* >(nid)) < 0)
            inBetween = npc(npc(pastryNodesSorted)->subMap(localId, nid))->size();
        else
            inBetween = npc(npc(pastryNodesSorted)->tailMap(localId))->size() + npc(npc(pastryNodesSorted)->headMap(nid))->size();
        if(inBetween != i)
            npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"checkLeafSet: failure at"_j)->append(static_cast< ::java::lang::Object* >(npc(rta)->getNodeId()))
                ->append(u"i="_j)
                ->append(i)
                ->append(u" inBetween="_j)
                ->append(inBetween)
                ->append(u"\n"_j)
                ->append(static_cast< ::java::lang::Object* >(ls))->toString());

    }
    for (auto k = -npc(ls)->ccwSize(); k <= npc(ls)->cwSize(); k++) {
        auto id = npc(npc(ls)->get(k))->getNodeId();
        auto distanceSet = new ::java::util::TreeSet(static_cast< ::java::util::Comparator* >(new PastryRegrTest_checkLeafSet_DistComp_1(this, id)));
        for (auto i = -npc(ls)->ccwSize(); i <= npc(ls)->cwSize(); i++) {
            auto nh = npc(ls)->get(i);
            npc(distanceSet)->add(static_cast< ::java::lang::Object* >(npc(nh)->getNodeId()));
        }
        auto expectedSize = npc(npc(distanceSet)->headSet(static_cast< ::java::lang::Object* >(npc(npc(ls)->get(-npc(ls)->ccwSize()))->getNodeId())))->size() + int32_t(1);
        auto expectedSize1 = npc(npc(distanceSet)->headSet(static_cast< ::java::lang::Object* >(npc(npc(ls)->get(npc(ls)->cwSize()))->getNodeId())))->size() + int32_t(1);
        if(expectedSize1 < expectedSize)
            expectedSize = expectedSize1;

        if(npc(ls)->overlaps())
            expectedSize = npc(distanceSet)->size();

        auto rs = npc(ls)->replicaSet(id, expectedSize);
        for (auto i = int32_t(0); i < npc(rs)->size(); i++) {
            auto nh = npc(rs)->get(i);
            auto nid = npc(nh)->getNodeId();
            auto inBetween = npc(npc(distanceSet)->subSet(static_cast< ::java::lang::Object* >(id), static_cast< ::java::lang::Object* >(nid)))->size();
            if(inBetween != i)
                npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"checkLeafSet: replicaSet failure at"_j)->append(static_cast< ::java::lang::Object* >(npc(rta)->getNodeId()))
                    ->append(u" i="_j)
                    ->append(i)
                    ->append(u" k="_j)
                    ->append(k)
                    ->append(u" inBetween="_j)
                    ->append(inBetween)
                    ->append(u"\n"_j)
                    ->append(static_cast< ::java::lang::Object* >(rs))
                    ->append(u"\n"_j)
                    ->append(static_cast< ::java::lang::Object* >(ls))->toString());

        }
        if(npc(rs)->size() != expectedSize)
            npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"checkLeafSet: replicaSet size failure at "_j)->append(static_cast< ::java::lang::Object* >(npc(rta)->getNodeId()))
                ->append(u" k="_j)
                ->append(k)
                ->append(u" expectedSize="_j)
                ->append(expectedSize)
                ->append(u" "_j)
                ->append(u"\n"_j)
                ->append(static_cast< ::java::lang::Object* >(rs))
                ->append(u"\n"_j)
                ->append(static_cast< ::java::lang::Object* >(ls))
                ->append(u" distanceSet:"_j)
                ->append(static_cast< ::java::lang::Object* >(distanceSet))->toString());

        int32_t maxRank;
        if(npc(ls)->overlaps() || npc(ls)->size() == 0)
            maxRank = npc(rs)->size() - int32_t(1);
        else
            maxRank = (k > 0) ? (npc(ls)->cwSize() - k - int32_t(1)) : (npc(ls)->ccwSize() + k - int32_t(1));
        int32_t nearestPos;
        ::rice::pastry::Id* nearest = nullptr;
        for (auto j = -int32_t(1); j <= maxRank * int32_t(2) + int32_t(1); j++) {
            ::rice::pastry::IdRange* range = nullptr;
            if(j < 0)
                try {
                    range = npc(rta)->range(npc(ls)->get(k), maxRank, nearest, true);
                } catch (::java::lang::IllegalArgumentException* iae) {
                } catch (::rice::p2p::commonapi::RangeCannotBeDeterminedException* rcbde) {
                } catch (::java::lang::NullPointerException* npe) {
                }
            else
                try {
                    range = npc(rta)->range(npc(ls)->get(k), j / int32_t(2), nearest, false);
                } catch (::java::lang::NullPointerException* npe) {
                } catch (::rice::p2p::commonapi::RangeCannotBeDeterminedException* rcbde) {
                }
            if(range == nullptr) {
                if(maxRank >= 0) {
                    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"checkLeafSet: range size failure at "_j)->append(static_cast< ::java::lang::Object* >(npc(rta)->getNodeId()))
                        ->append(u" k="_j)
                        ->append(k)
                        ->append(u" maxRank="_j)
                        ->append(maxRank)
                        ->append(u"\n"_j)
                        ->append(static_cast< ::java::lang::Object* >(rs))
                        ->append(u"\n"_j)
                        ->append(static_cast< ::java::lang::Object* >(ls))->toString());
                }
                continue;
            }
            nearest = npc(npc(ls)->get(k))->getNodeId();
            nearestPos = k;
            auto cs = npc(ls)->replicaSet(npc(range)->getCCW(), maxRank + int32_t(1));
            if((j >= 0 && npc(cs)->get(j / int32_t(2)) == nullptr) || (j >= 0 && !npc(npc(npc(cs)->get(j / int32_t(2)))->getNodeId())->equals(nearest)) || (j < 0 && !npc(ls)->overlaps() && !npc(npc(npc(cs)->get(maxRank))->getNodeId())->equals(nearest))|| (j < 0 && npc(ls)->overlaps() && !npc(range)->isFull())) {
                npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"checkLeafSet: range failure 1 at "_j)->append(static_cast< ::java::lang::Object* >(npc(rta)->getNodeId()))
                    ->append(u" k="_j)
                    ->append(k)
                    ->append(u" j="_j)
                    ->append(j)
                    ->append(u" maxRank="_j)
                    ->append(maxRank)
                    ->append(u"\n"_j)
                    ->append(static_cast< ::java::lang::Object* >(cs))
                    ->append(u"\n"_j)
                    ->append(static_cast< ::java::lang::Object* >(ls))
                    ->append(u"\n"_j)
                    ->append(static_cast< ::java::lang::Object* >(range))
                    ->append(u"\nnearest="_j)
                    ->append(static_cast< ::java::lang::Object* >(nearest))->toString());
                npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"dist(nearest)="_j)->append(static_cast< ::java::lang::Object* >(npc(nearest)->distance(npc(range)->getCCW())))->toString());
                if(npc(ls)->get(nearestPos - int32_t(1)) != nullptr)
                    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"dist(nearest-1)="_j)->append(static_cast< ::java::lang::Object* >(npc(npc(npc(ls)->get(nearestPos - int32_t(1)))->getNodeId())->distance(npc(range)->getCCW())))->toString());

                if(npc(ls)->get(nearestPos + int32_t(1)) != nullptr)
                    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"dist(nearest+1)="_j)->append(static_cast< ::java::lang::Object* >(npc(npc(npc(ls)->get(nearestPos + int32_t(1)))->getNodeId())->distance(npc(range)->getCCW())))->toString());

            }
            cs = npc(ls)->replicaSet(npc(npc(range)->getCW())->getCCW(), maxRank + int32_t(1));
            if((j >= 0 && npc(cs)->get(j / int32_t(2)) == nullptr) || (j >= 0 && !npc(npc(npc(cs)->get(j / int32_t(2)))->getNodeId())->equals(nearest)) || (j < 0 && !npc(ls)->overlaps() && !npc(npc(npc(cs)->get(maxRank))->getNodeId())->equals(nearest))|| (j < 0 && npc(ls)->overlaps() && !npc(range)->isFull())) {
                npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"checkLeafSet: range failure 2 at "_j)->append(static_cast< ::java::lang::Object* >(npc(rta)->getNodeId()))
                    ->append(u" k="_j)
                    ->append(k)
                    ->append(u" j="_j)
                    ->append(j)
                    ->append(u" maxRank="_j)
                    ->append(maxRank)
                    ->append(u"\n"_j)
                    ->append(static_cast< ::java::lang::Object* >(cs))
                    ->append(u"\n"_j)
                    ->append(static_cast< ::java::lang::Object* >(ls))
                    ->append(u"\n"_j)
                    ->append(static_cast< ::java::lang::Object* >(range))
                    ->append(u"\nnearest="_j)
                    ->append(static_cast< ::java::lang::Object* >(nearest))->toString());
                npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"dist(nearest)="_j)->append(static_cast< ::java::lang::Object* >(npc(nearest)->distance(npc(range)->getCW())))->toString());
                if(npc(ls)->get(nearestPos - int32_t(1)) != nullptr)
                    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"dist(nearest-1)="_j)->append(static_cast< ::java::lang::Object* >(npc(npc(npc(ls)->get(nearestPos - int32_t(1)))->getNodeId())->distance(npc(range)->getCW())))->toString());

                if(npc(ls)->get(nearestPos + int32_t(1)) != nullptr)
                    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"dist(nearest+1)="_j)->append(static_cast< ::java::lang::Object* >(npc(npc(npc(ls)->get(nearestPos + int32_t(1)))->getNodeId())->distance(npc(range)->getCW())))->toString());

            }
            nearest = npc(range)->getCW();
        }
    }
}

void rice::pastry::testing::PastryRegrTest::checkRoutingTable(RegrTestApp* rta)
{
    auto rt = npc(rta)->getRoutingTable();
    for (auto i = npc(rt)->numRows() - int32_t(1); i >= 0; i--) {
        for (auto j = int32_t(0); j < npc(rt)->numColumns(); j++) {
            auto const rs = npc(rt)->getRouteSet(i, j);
            auto domainFirst = npc(npc(rta)->getNodeId())->getDomainPrefix(i, j, 0, npc(rt)->baseBitLength());
            auto domainLast = npc(npc(rta)->getNodeId())->getDomainPrefix(i, j, -int32_t(1), npc(rt)->baseBitLength());
            if(rs == nullptr || npc(rs)->size() == 0) {
                auto inBetween = npc(npc(pastryNodesSorted)->subMap(domainFirst, domainLast))->size() + (npc(pastryNodesSorted)->containsKey(domainLast) ? int32_t(1) : int32_t(0));
                if(inBetween > 0) {
                    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"checkRoutingTable: missing RT entry at"_j)->append(static_cast< ::java::lang::Object* >(npc(rta)->getNodeId()))
                        ->append(u"row="_j)
                        ->append(i)
                        ->append(u" column="_j)
                        ->append(j)
                        ->append(u" inBetween="_j)
                        ->append(inBetween)->toString());
                }
            } else {
                auto nh = java_cast< ::rice::pastry::NodeHandle* >(npc(rs)->closestNode());
                auto bestProximity = ::java::lang::Integer::MAX_VALUE;
                if(nh != nullptr) {
                    bestProximity = npc(npc(rta)->getPastryNode())->proximity(nh);
                    if(bestProximity == ::java::lang::Integer::MAX_VALUE) {
                        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"checkRoutingTable failure 0, row="_j)->append(i)
                            ->append(u" column="_j)
                            ->append(j)->toString());
                    }
                }
                for (auto k = int32_t(0); k < npc(rs)->size(); k++) {
                    if(npc(npc(rs)->get(k))->isAlive() && npc(npc(rta)->getPastryNode())->proximity(npc(rs)->get(k)) < bestProximity) {
                        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"checkRoutingTable failure 1, row="_j)->append(i)
                            ->append(u" column="_j)
                            ->append(j)
                            ->append(u" rank="_j)
                            ->append(k)->toString());
                    }
                    auto nh2 = npc(rs)->get(k);
                    auto id = npc(nh2)->getNodeId();
                    if(!npc(pastryNodesSorted)->containsKey(id)) {
                        if(isReallyAlive(nh2))
                            npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"checkRoutingTable failure 2, row="_j)->append(i)
                                ->append(u" column="_j)
                                ->append(j)
                                ->append(u" rank="_j)
                                ->append(k)->toString());

                    } else if(!npc(npc(pastryNodesSorted)->subMap(domainFirst, domainLast))->containsKey(id) && !npc(domainLast)->equals(id))
                        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"checkRoutingTable failure 3, row="_j)->append(i)
                            ->append(u" column="_j)
                            ->append(j)
                            ->append(u" rank="_j)
                            ->append(k)->toString());

                }
            }
        }
    }
}

void rice::pastry::testing::PastryRegrTest::initiateLeafSetMaintenance()
{
    for (auto i = int32_t(0); i < npc(pastryNodes)->size(); i++) {
        auto pn = java_cast< ::rice::pastry::PastryNode* >(java_cast< ::java::lang::Object* >(npc(pastryNodes)->get(i)));
        npc(pn)->receiveMessage(new ::rice::pastry::leafset::InitiateLeafSetMaintenance());
        while (simulate()) 
                        ;

    }
}

void rice::pastry::testing::PastryRegrTest::initiateRouteSetMaintenance()
{
    for (auto i = int32_t(0); i < npc(pastryNodes)->size(); i++) {
        auto pn = java_cast< ::rice::pastry::PastryNode* >(java_cast< ::java::lang::Object* >(npc(pastryNodes)->get(i)));
        npc(pn)->receiveMessage(new ::rice::pastry::routing::InitiateRouteSetMaintenance());
        while (simulate()) 
                        ;

    }
}

void rice::pastry::testing::PastryRegrTest::killNodes(int32_t num)
{
    for (auto i = int32_t(0); i < num; i++) {
        auto n = npc(npc(environment)->getRandomSource())->nextInt(npc(pastryNodes)->size());
        auto pn = java_cast< ::rice::pastry::PastryNode* >(java_cast< ::java::lang::Object* >(npc(pastryNodes)->get(n)));
        npc(pastryNodes)->remove(n);
        npc(rtApps)->remove(n);
        npc(pastryNodesSorted)->remove(npc(pn)->getNodeId());
        npc(pastryNodesSortedReady)->remove(npc(pn)->getNodeId());
        killNode(pn);
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"Killed "_j)->append(static_cast< ::java::lang::Object* >(npc(pn)->getNodeId()))->toString());
        try {
            npc(npc(environment)->getTimeSource())->sleep(2000);
        } catch (::java::lang::InterruptedException* ie) {
        }
    }
}

void rice::pastry::testing::PastryRegrTest::mainfunc(PastryRegrTest* pt, ::java::lang::StringArray* args, int32_t n, int32_t d, int32_t k, int32_t m, int32_t numConcJoins)
{
    clinit();
    auto old = new ::java::util::Date();
    while (npc(npc(pt)->pastryNodes)->size() < n) {
        auto remaining = n - npc(npc(pt)->pastryNodes)->size();
        if(remaining > numConcJoins)
            remaining = numConcJoins;

        npc(pt)->makePastryNode(remaining);
        if(npc(npc(pt)->pastryNodes)->size() % m == 0) {
            auto now = new ::java::util::Date();
            npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(npc(npc(pt)->pastryNodes)->size())->append(u" "_j)
                ->append((npc(now)->getTime() - npc(old)->getTime()))->toString());
            old = now;
        }
        npc(pt)->sendPings(k);
    }
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(npc(npc(pt)->pastryNodes)->size())->append(u" nodes constructed"_j)->toString());
    npc(::java::lang::System::out())->println(u"starting RT and leafset check"_j);
    for (auto j = int32_t(0); j < npc(npc(pt)->rtApps)->size(); j++) {
        npc(pt)->checkLeafSet(java_cast< RegrTestApp* >(java_cast< ::java::lang::Object* >(npc(npc(pt)->rtApps)->get(j))));
        npc(pt)->checkRoutingTable(java_cast< RegrTestApp* >(java_cast< ::java::lang::Object* >(npc(npc(pt)->rtApps)->get(j))));
    }
    npc(::java::lang::System::out())->println(u"finished RT and leafset check"_j);
    npc(pt)->killNodes(d);
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(d)->append(u" nodes killed"_j)->toString());
    npc(pt)->sendPings((n - d) * k);
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append((n - d) * k)->append(u" messages sent"_j)->toString());
    npc(::java::lang::System::out())->println(u"starting leafset/RT maintenance"_j);
    npc(pt)->initiateLeafSetMaintenance();
    npc(pt)->initiateRouteSetMaintenance();
    npc(::java::lang::System::out())->println(u"finished leafset/RT maintenance"_j);
    npc(pt)->sendPings((n - d) * k);
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append((n - d) * k)->append(u" messages sent"_j)->toString());
    npc(pt)->pause(5000);
    npc(::java::lang::System::out())->println(u"starting RT and leafset check"_j);
    for (auto i = int32_t(0); i < npc(npc(pt)->rtApps)->size(); i++) {
        npc(pt)->checkLeafSet(java_cast< RegrTestApp* >(java_cast< ::java::lang::Object* >(npc(npc(pt)->rtApps)->get(i))));
        npc(pt)->checkRoutingTable(java_cast< RegrTestApp* >(java_cast< ::java::lang::Object* >(npc(npc(pt)->rtApps)->get(i))));
    }
    for (auto i = int32_t(0); i < 4; i++) {
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"Starting leafset/RT maintenance, round "_j)->append((i + int32_t(2)))->toString());
        npc(pt)->initiateLeafSetMaintenance();
        npc(pt)->initiateRouteSetMaintenance();
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"finished leafset/RT maintenance, round "_j)->append((i + int32_t(2)))->toString());
        npc(pt)->sendPings((n - d) * k);
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append((n - d) * k)->append(u" messages sent"_j)->toString());
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"starting RT and leafset check, round "_j)->append((i + int32_t(2)))->toString());
        for (auto j = int32_t(0); j < npc(npc(pt)->rtApps)->size(); j++) {
            npc(pt)->checkLeafSet(java_cast< RegrTestApp* >(java_cast< ::java::lang::Object* >(npc(npc(pt)->rtApps)->get(j))));
            npc(pt)->checkRoutingTable(java_cast< RegrTestApp* >(java_cast< ::java::lang::Object* >(npc(npc(pt)->rtApps)->get(j))));
        }
        npc(pt)->pause(1000);
    }
    npc(pt)->pause(5000);
    npc(::java::lang::System::out())->println(u"finished, exiting..."_j);
    ::java::lang::System::exit(0);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::testing::PastryRegrTest::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.testing.PastryRegrTest", 34);
    return c;
}

java::lang::Class* rice::pastry::testing::PastryRegrTest::getClass0()
{
    return class_();
}

