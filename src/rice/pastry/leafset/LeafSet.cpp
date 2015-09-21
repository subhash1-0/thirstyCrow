// Generated from /pastry-2.1/src/rice/pastry/leafset/LeafSet.java
#include <rice/pastry/leafset/LeafSet.hpp>

#include <java/io/ObjectInputStream.hpp>
#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/IllegalArgumentException.hpp>
#include <java/lang/Integer.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/util/ArrayList.hpp>
#include <java/util/Collection.hpp>
#include <java/util/HashSet.hpp>
#include <java/util/Iterator.hpp>
#include <java/util/List.hpp>
#include <java/util/NoSuchElementException.hpp>
#include <java/util/Observable.hpp>
#include <java/util/Set.hpp>
#include <rice/p2p/commonapi/Id_Distance.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/commonapi/NodeHandle.hpp>
#include <rice/p2p/commonapi/rawserialization/InputBuffer.hpp>
#include <rice/p2p/commonapi/rawserialization/OutputBuffer.hpp>
#include <rice/p2p/commonapi/rawserialization/RawSerializable.hpp>
#include <rice/pastry/Id_Distance.hpp>
#include <rice/pastry/Id.hpp>
#include <rice/pastry/IdRange.hpp>
#include <rice/pastry/NodeHandle.hpp>
#include <rice/pastry/NodeHandleFactory.hpp>
#include <rice/pastry/NodeSet.hpp>
#include <rice/pastry/leafset/LSRangeCannotBeDeterminedException.hpp>
#include <rice/pastry/leafset/SimilarSet.hpp>
#include <rice/pastry/routing/RoutingTable.hpp>
#include <SubArray.hpp>
#include <ObjectArray.hpp>

template<typename ComponentType, typename... Bases> struct SubArray;
namespace java
{
    namespace io
    {
typedef ::SubArray< ::java::io::Serializable, ::java::lang::ObjectArray > SerializableArray;
    } // io

    namespace util
    {
typedef ::SubArray< ::java::util::Observable, ::java::lang::ObjectArray > ObservableArray;
    } // util
} // java

namespace rice
{
    namespace p2p
    {
        namespace commonapi
        {
typedef ::SubArray< ::rice::p2p::commonapi::NodeHandle, ::java::util::ObservableArray, ::java::io::SerializableArray > NodeHandleArray;

            namespace rawserialization
            {
typedef ::SubArray< ::rice::p2p::commonapi::rawserialization::RawSerializable, ::java::lang::ObjectArray > RawSerializableArray;
            } // rawserialization
        } // commonapi
    } // p2p

    namespace pastry
    {
typedef ::SubArray< ::rice::pastry::NodeHandle, ::rice::p2p::commonapi::NodeHandleArray, ::rice::p2p::commonapi::rawserialization::RawSerializableArray > NodeHandleArray;
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

rice::pastry::leafset::LeafSet::LeafSet(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::leafset::LeafSet::LeafSet(LeafSet* that) 
    : LeafSet(*static_cast< ::default_init_tag* >(0))
{
    ctor(that);
}

rice::pastry::leafset::LeafSet::LeafSet(LeafSet* that, bool observe) 
    : LeafSet(*static_cast< ::default_init_tag* >(0))
{
    ctor(that,observe);
}

rice::pastry::leafset::LeafSet::LeafSet(::rice::pastry::NodeHandle* localNode, int32_t size, ::rice::pastry::routing::RoutingTable* rt) 
    : LeafSet(*static_cast< ::default_init_tag* >(0))
{
    ctor(localNode,size,rt);
}

rice::pastry::leafset::LeafSet::LeafSet(::rice::pastry::NodeHandle* localNode, int32_t size, bool observe) 
    : LeafSet(*static_cast< ::default_init_tag* >(0))
{
    ctor(localNode,size,observe);
}

rice::pastry::leafset::LeafSet::LeafSet(::rice::pastry::NodeHandle* localNode, int32_t size, bool observe, ::rice::pastry::NodeHandleArray* cwTable, ::rice::pastry::NodeHandleArray* ccwTable) 
    : LeafSet(*static_cast< ::default_init_tag* >(0))
{
    ctor(localNode,size,observe,cwTable,ccwTable);
}

void rice::pastry::leafset::LeafSet::init()
{
    observe = true;
}

constexpr int64_t rice::pastry::leafset::LeafSet::serialVersionUID;

void rice::pastry::leafset::LeafSet::ctor(LeafSet* that)
{
    ctor(that, true);
}

void rice::pastry::leafset::LeafSet::ctor(LeafSet* that, bool observe)
{
    super::ctor();
    init();
    this->observe = observe;
    this->baseId = npc(that)->baseId;
    this->baseHandle = npc(that)->baseHandle;
    this->ccwSet = npc(npc(that)->ccwSet)->copy(this);
    this->cwSet = npc(npc(that)->cwSet)->copy(this);
    this->theSize = npc(that)->theSize;
}

void rice::pastry::leafset::LeafSet::ctor(::rice::pastry::NodeHandle* localNode, int32_t size, ::rice::pastry::routing::RoutingTable* rt)
{
    ctor(localNode, size, true);
    this->routingTable = rt;
}

void rice::pastry::leafset::LeafSet::ctor(::rice::pastry::NodeHandle* localNode, int32_t size, bool observe)
{
    super::ctor();
    init();
    this->observe = observe;
    baseHandle = localNode;
    baseId = npc(localNode)->getNodeId();
    theSize = size;
    cwSet = new SimilarSet(this, localNode, size / int32_t(2), true);
    ccwSet = new SimilarSet(this, localNode, size / int32_t(2), false);
}

void rice::pastry::leafset::LeafSet::readObject(::java::io::ObjectInputStream* ois) /* throws(IOException, ClassNotFoundException) */
{
    npc(ois)->defaultReadObject();
    observe = true;
}

bool rice::pastry::leafset::LeafSet::put(::rice::pastry::NodeHandle* handle)
{
    return put(handle, false);
}

bool rice::pastry::leafset::LeafSet::put(::rice::pastry::NodeHandle* handle, bool suppressNotification)
{
    auto nid = npc(handle)->getNodeId();
    if(npc(nid)->equals(baseId))
        return false;

    if(member(handle))
        return false;

    auto res = npc(cwSet)->put(handle, suppressNotification) | npc(ccwSet)->put(handle, suppressNotification);
    return res;
}

bool rice::pastry::leafset::LeafSet::test(::rice::pastry::NodeHandle* handle)
{
    auto nid = npc(handle)->getNodeId();
    if(npc(nid)->equals(baseId))
        return false;

    if(member(handle))
        return false;

    return npc(cwSet)->test(handle) | npc(ccwSet)->test(handle);
}

bool rice::pastry::leafset::LeafSet::overlaps()
{
    if(size() > 0 && (npc(ccwSet)->member(npc(cwSet)->get(npc(cwSet)->size() - int32_t(1))) || npc(cwSet)->member(npc(ccwSet)->get(npc(ccwSet)->size() - int32_t(1)))))
        return true;
    else
        return false;
}

bool rice::pastry::leafset::LeafSet::isComplete()
{
    if(size() == maxSize())
        return true;

    if(overlaps())
        return true;

    return false;
}

int32_t rice::pastry::leafset::LeafSet::getIndex(::rice::pastry::NodeHandle* nh) /* throws(NoSuchElementException) */
{
    if(npc(baseId)->equals(static_cast< ::java::lang::Object* >(npc(nh)->getId())))
        return 0;

    auto cwIndex = npc(cwSet)->getIndex(nh);
    auto ccwIndex = npc(ccwSet)->getIndex(nh);
    if(cwIndex >= 0 && ccwIndex >= 0) {
        if(cwIndex <= ccwIndex) {
            return cwIndex + int32_t(1);
        }
        return -ccwIndex - int32_t(1);
    }
    if(cwIndex >= 0)
        return cwIndex + int32_t(1);

    if(ccwIndex >= 0)
        return -ccwIndex - int32_t(1);

    throw new ::java::util::NoSuchElementException();
}

rice::pastry::NodeHandle* rice::pastry::leafset::LeafSet::get(int32_t index)
{
    if(index == 0)
        return baseHandle;

    if(index >= 0)
        return npc(cwSet)->get(index - int32_t(1));
    else
        return npc(ccwSet)->get(-index - int32_t(1));
}

bool rice::pastry::leafset::LeafSet::member(::rice::pastry::NodeHandle* nid)
{
    return npc(cwSet)->member(nid) || npc(ccwSet)->member(nid);
}

bool rice::pastry::leafset::LeafSet::contains(::rice::pastry::NodeHandle* nh)
{
    return member(nh);
}

bool rice::pastry::leafset::LeafSet::member(::rice::pastry::Id* nid)
{
    return npc(cwSet)->member(nid) || npc(ccwSet)->member(nid);
}

void rice::pastry::leafset::LeafSet::remove(::rice::pastry::NodeHandle* nh)
{
    npc(cwSet)->remove(nh);
    npc(ccwSet)->remove(nh);
    npc(cwSet)->findMoreEntriesFromRoutingTable();
    npc(ccwSet)->findMoreEntriesFromRoutingTable();
}

int32_t rice::pastry::leafset::LeafSet::maxSize()
{
    return theSize;
}

int32_t rice::pastry::leafset::LeafSet::size()
{
    return cwSize() + ccwSize();
}

int32_t rice::pastry::leafset::LeafSet::cwSize()
{
    return npc(cwSet)->size();
}

int32_t rice::pastry::leafset::LeafSet::ccwSize()
{
    return npc(ccwSet)->size();
}

int32_t rice::pastry::leafset::LeafSet::complement(int32_t inx)
{
    int32_t res;
    if(inx == 0)
        return 0;

    if(inx < 0) {
        if(inx < -ccwSize())
            return inx;

        res = npc(cwSet)->getIndex(npc(ccwSet)->get(-inx - int32_t(1))) + int32_t(1);
    } else {
        if(inx > cwSize())
            return inx;

        res = -npc(ccwSet)->getIndex(npc(cwSet)->get(inx - int32_t(1))) - int32_t(1);
    }
    if(res == 0)
        res = inx;

    return res;
}

int32_t rice::pastry::leafset::LeafSet::mostSimilar(::rice::pastry::Id* nid)
{
    ::rice::pastry::Id_Distance* cwMinDist;
    ::rice::pastry::Id_Distance* ccwMinDist;
    int32_t cwMS;
    int32_t ccwMS;
    int32_t res;
    if(npc(baseId)->clockwise(nid)) {
        cwMS = npc(cwSet)->mostSimilar(nid);
        if(cwMS < npc(cwSet)->size() - int32_t(1))
            return cwMS + int32_t(1);

        ccwMS = npc(ccwSet)->mostSimilar(nid);
    } else {
        ccwMS = npc(ccwSet)->mostSimilar(nid);
        if(ccwMS < npc(ccwSet)->size() - int32_t(1))
            return -ccwMS - int32_t(1);

        cwMS = npc(cwSet)->mostSimilar(nid);
    }
    cwMinDist = npc(npc(npc(cwSet)->get(cwMS))->getNodeId())->distance(nid);
    ccwMinDist = npc(npc(npc(ccwSet)->get(ccwMS))->getNodeId())->distance(nid);
    auto cmp = npc(cwMinDist)->compareTo(static_cast< ::rice::p2p::commonapi::Id_Distance* >(ccwMinDist));
    if(cmp < 0 || (cmp == 0 && npc(nid)->clockwise(npc(npc(cwSet)->get(cwMS))->getNodeId())))
        return cwMS + int32_t(1);
    else
        return -ccwMS - int32_t(1);
}

rice::pastry::NodeSet* rice::pastry::leafset::LeafSet::neighborSet(int32_t max)
{
    ::rice::pastry::NodeSet* set;
    auto cwSize = this->cwSize();
    auto ccwSize = this->ccwSize();
    auto cwExtreme = get(cwSize);
    auto ccwExtreme = get(-ccwSize);
    set = replicaSet(baseId, max);
    if(!npc(set)->member(cwExtreme) && !npc(set)->member(ccwExtreme)) {
        return set;
    } else {
        if(!npc(set)->member(cwExtreme)) {
            for (auto i = int32_t(1); i <= cwSize; i++) {
                npc(set)->put(get(i));
            }
        }
        if(!npc(set)->member(ccwExtreme)) {
            for (auto i = int32_t(1); i <= ccwSize; i++) {
                npc(set)->put(get(-i));
            }
        }
        return set;
    }
}

rice::pastry::NodeSet* rice::pastry::leafset::LeafSet::replicaSet(::rice::pastry::Id* key, int32_t max)
{
    auto set = new ::rice::pastry::NodeSet();
    if(max < 1)
        return set;

    if(!overlaps() && size() > 0 && !npc(key)->isBetween(npc(get(-npc(ccwSet)->size()))->getNodeId(), npc(get(npc(cwSet)->size()))->getNodeId()) && !npc(key)->equals(npc(get(npc(cwSet)->size()))->getNodeId()))
        return set;

    auto nearest = mostSimilar(key);
    npc(set)->put(get(nearest));
    auto cw = nearest;
    auto ccw = nearest;
    auto wrapped = int32_t(0);
    while (npc(set)->size() < max && wrapped < 3) {
        int32_t tmp;
        auto cwNode = get(cw);
        auto ccwNode = get(ccw);
        auto cwDist = npc(npc(cwNode)->getNodeId())->distance(key);
        auto ccwDist = npc(npc(ccwNode)->getNodeId())->distance(key);
        if(npc(cwDist)->compareTo(static_cast< ::rice::p2p::commonapi::Id_Distance* >(ccwDist)) <= 0) {
            npc(set)->put(cwNode);
            tmp = cw;
            if(cw == npc(cwSet)->size()) {
                if((cw = complement(cw)) == tmp)
                    return set;

                wrapped++;
            }
            cw++;
        } else {
            npc(set)->put(ccwNode);
            tmp = ccw;
            if(-ccw == npc(ccwSet)->size()) {
                if((ccw = complement(ccw)) == tmp)
                    return set;

                wrapped++;
            }
            ccw--;
        }
    }
    return set;
}

int32_t rice::pastry::leafset::LeafSet::getUniqueCount()
{
    return npc(getUniqueSet())->size() + int32_t(1);
}

java::util::Iterator* rice::pastry::leafset::LeafSet::iterator()
{
    return npc(getUniqueSet())->iterator();
}

java::util::Collection* rice::pastry::leafset::LeafSet::getUniqueSet()
{
    auto superset = new ::java::util::HashSet();
    npc(superset)->addAll(static_cast< ::java::util::Collection* >(npc(cwSet)->getCollection()));
    npc(superset)->addAll(static_cast< ::java::util::Collection* >(npc(ccwSet)->getCollection()));
    return superset;
}

int32_t rice::pastry::leafset::LeafSet::mod(int32_t x, int32_t y)
{
    if((x < 0) ^ (y < 0))
        return y + (x % y);
    else
        return x % y;
}

rice::pastry::IdRange* rice::pastry::leafset::LeafSet::range(::rice::pastry::NodeHandle* n, int32_t r)
{
    if(r < 0)
        throw new ::java::lang::IllegalArgumentException(::java::lang::StringBuilder().append(u"Range must be greater than or equal to zero. Attempted "_j)->append(r)->toString());

    if(!(member(n) || npc(baseHandle)->equals(static_cast< ::java::lang::Object* >(n))))
        throw new LSRangeCannotBeDeterminedException(::java::lang::StringBuilder().append(u"Node "_j)->append(static_cast< ::java::lang::Object* >(n))
            ->append(u" is not in this leafset."_j)->toString(), r, ::java::lang::Integer::MIN_VALUE, getUniqueCount(), n, this);

    auto pos = getIndex(n);
    auto num = getUniqueCount();
    ::rice::pastry::NodeHandle* cw;
    ::rice::pastry::NodeHandle* ccw;
    if(overlaps() || (num == 1)) {
        if(r + int32_t(1) >= num) {
            return new ::rice::pastry::IdRange(npc(n)->getNodeId(), npc(n)->getNodeId());
        }
        ccw = get(mod(pos - r - int32_t(1) + npc(ccwSet)->size(), num) - npc(ccwSet)->size());
        cw = get(mod(pos + r + int32_t(1)+ npc(ccwSet)->size(), num) - npc(ccwSet)->size());
    } else {
        ccw = get(pos - r - int32_t(1));
        cw = get(pos + r + int32_t(1));
    }
    if((ccw == nullptr) || (cw == nullptr)) {
        throw new LSRangeCannotBeDeterminedException(u"This leafset doesn't have enough information to provide the correct range."_j, r, pos, getUniqueCount(), n, this);
    }
    auto cwRange = (new ::rice::pastry::IdRange(npc(n)->getNodeId(), npc(cw)->getNodeId()))->ccwHalf();
    auto ccwRange = (new ::rice::pastry::IdRange(npc(ccw)->getNodeId(), npc(n)->getNodeId()))->cwHalf();
    return npc(ccwRange)->merge(cwRange);
}

rice::pastry::IdRange* rice::pastry::leafset::LeafSet::range(::rice::pastry::NodeHandle* n, int32_t r, bool cw)
{
    auto rr = range(n, r);
    if(r == 0)
        return rr;

    ::rice::pastry::IdRange* rprev = nullptr;
    try {
        rprev = range(n, r - int32_t(1));
    } catch (LSRangeCannotBeDeterminedException* rcbde) {
    }
    if(rr == nullptr || rprev == nullptr)
        return rr;

    ::rice::pastry::IdRange* res;
    if(!cw)
        res = npc(rr)->diff(rprev);
    else
        res = npc(rprev)->diff(rr);
    return res;
}

bool rice::pastry::leafset::LeafSet::merge(LeafSet* remotels, ::rice::pastry::NodeHandle* from, ::rice::pastry::routing::RoutingTable* routeTable, bool testOnly, ::java::util::Set* insertedHandles)
{
    bool changed, result = false;
    auto cwSize = npc(remotels)->cwSize();
    auto ccwSize = npc(remotels)->ccwSize();
    ::java::util::Set* myInsertedHandles = new ::java::util::HashSet();
    auto cw = npc(npc(remotels)->cwSet)->getIndex(baseId);
    auto ccw = npc(npc(remotels)->ccwSet)->getIndex(baseId);
    if(cw < 0) {
        if(ccw < 0) {
            if(npc(remotels)->size() < 2) {
                cw = ccw = 0;
            } else {
                auto closest = npc(remotels)->mostSimilar(baseId);
                auto closestId = npc(npc(remotels)->get(closest))->getNodeId();
                if(closest == -npc(remotels)->ccwSize() || closest == npc(remotels)->cwSize()) {
                }
                if(closest == 0) {
                    if(npc(baseId)->clockwise(closestId)) {
                        cw = closest;
                        ccw = npc(remotels)->complement(closest - int32_t(1));
                    } else {
                        cw = npc(remotels)->complement(closest + int32_t(1));
                        ccw = closest;
                    }
                } else if(closest < 0) {
                    if(npc(baseId)->clockwise(closestId)) {
                        cw = closest;
                        ccw = npc(remotels)->complement(closest - int32_t(1));
                    } else {
                        cw = closest + int32_t(1);
                        ccw = npc(remotels)->complement(closest);
                    }
                } else {
                    if(npc(baseId)->clockwise(closestId)) {
                        cw = npc(remotels)->complement(closest);
                        ccw = closest - int32_t(1);
                    } else {
                        ccw = closest;
                        cw = npc(remotels)->complement(closest + int32_t(1));
                    }
                }
            }
        } else {
            ccw = -ccw - int32_t(2);
            cw = ccw + int32_t(2);
        }
    } else {
        if(ccw < 0) {
            cw = cw + int32_t(2);
            ccw = cw - int32_t(2);
        } else {
            auto tmp = ccw;
            ccw = cw;
            cw = -tmp;
        }
    }
    for (auto i = cw; i <= cwSize; i++) {
        ::rice::pastry::NodeHandle* nh;
        if(i == 0)
            nh = from;
        else
            nh = npc(remotels)->get(i);
        if(npc(nh)->isAlive() == false)
            continue;

        if(testOnly) {
            changed = npc(cwSet)->test(nh);
        } else {
            changed = npc(cwSet)->put(nh, true);
            if(changed)
                npc(myInsertedHandles)->add(static_cast< ::java::lang::Object* >(nh));

            npc(routeTable)->put(nh);
        }
        result |= changed;
        if(insertedHandles != nullptr && changed)
            npc(insertedHandles)->add(static_cast< ::java::lang::Object* >(nh));

    }
    for (auto i = ccw; i >= -ccwSize; i--) {
        ::rice::pastry::NodeHandle* nh;
        if(i == 0)
            nh = from;
        else
            nh = npc(remotels)->get(i);
        if(npc(nh)->isAlive() == false)
            continue;

        if(testOnly) {
            changed = npc(ccwSet)->test(nh);
        } else {
            changed = npc(ccwSet)->put(nh, true);
            if(changed)
                npc(myInsertedHandles)->add(static_cast< ::java::lang::Object* >(nh));

            npc(routeTable)->put(nh);
        }
        result |= changed;
        if(insertedHandles != nullptr && changed)
            npc(insertedHandles)->add(static_cast< ::java::lang::Object* >(nh));

    }
    if(overlaps()) {
        for (auto i = -ccwSize; i <= cwSize; i++) {
            ::rice::pastry::NodeHandle* nh;
            if(i == 0)
                nh = from;
            else
                nh = npc(remotels)->get(i);
            if(npc(nh)->isAlive() == false)
                continue;

            if(testOnly) {
                changed = test(nh);
            } else {
                changed = put(nh);
                if(changed)
                    npc(myInsertedHandles)->add(static_cast< ::java::lang::Object* >(nh));

                npc(routeTable)->put(nh);
            }
            result |= changed;
            if(insertedHandles != nullptr && changed)
                npc(insertedHandles)->add(static_cast< ::java::lang::Object* >(nh));

        }
    }
    auto i = npc(myInsertedHandles)->iterator();
    while (npc(i)->hasNext()) {
        npc(cwSet)->notifyListeners(java_cast< ::rice::pastry::NodeHandle* >(npc(i)->next()), true);
    }
    return result;
}

void rice::pastry::leafset::LeafSet::addObserver(::java::util::Observer* o)
{
    npc(cwSet)->addObserver(o);
    npc(ccwSet)->addObserver(o);
}

void rice::pastry::leafset::LeafSet::deleteObserver(::java::util::Observer* o)
{
    npc(cwSet)->deleteObserver(o);
    npc(ccwSet)->deleteObserver(o);
}

void rice::pastry::leafset::LeafSet::addNodeSetListener(::rice::pastry::NodeSetListener* listener)
{
    npc(cwSet)->addNodeSetListener(listener);
    npc(ccwSet)->addNodeSetListener(listener);
}

void rice::pastry::leafset::LeafSet::deleteNodeSetListener(::rice::pastry::NodeSetListener* listener)
{
    npc(cwSet)->removeNodeSetListener(listener);
    npc(ccwSet)->removeNodeSetListener(listener);
}

java::lang::String* rice::pastry::leafset::LeafSet::toString()
{
    auto s = u"leafset: "_j;
    for (auto i = -npc(ccwSet)->size(); i < 0; i++) 
                s = ::java::lang::StringBuilder().append(s)->append(static_cast< ::java::lang::Object* >(npc(get(i))->getNodeId()))->toString();

    s = ::java::lang::StringBuilder().append(s)->append(u" [ "_j)
        ->append(static_cast< ::java::lang::Object* >(baseId))
        ->append(u" ] "_j)->toString();
    for (auto i = int32_t(1); i <= npc(cwSet)->size(); i++) 
                s = ::java::lang::StringBuilder().append(s)->append(static_cast< ::java::lang::Object* >(npc(get(i))->getNodeId()))->toString();

    s = ::java::lang::StringBuilder(s).append(::java::lang::StringBuilder().append(u" complete:"_j)->append(isComplete())->toString())->toString();
    s = ::java::lang::StringBuilder(s).append(::java::lang::StringBuilder().append(u" size:"_j)->append(size())->toString())->toString();
    if(size() > 0)
        s = ::java::lang::StringBuilder(s).append(::java::lang::StringBuilder().append(u" s1:"_j)->append(npc(ccwSet)->member(npc(cwSet)->get(npc(cwSet)->size() - int32_t(1))))->toString())->toString();

    s = ::java::lang::StringBuilder(s).append(::java::lang::StringBuilder().append(u" s2:"_j)->append(npc(cwSet)->member(npc(ccwSet)->get(npc(ccwSet)->size() - int32_t(1))))->toString())->toString();
    return s;
}

bool rice::pastry::leafset::LeafSet::isProperlyRemoved(::rice::pastry::NodeHandle* handle)
{
    return !member(handle);
}

bool rice::pastry::leafset::LeafSet::testOtherSet(SimilarSet* set, ::rice::pastry::NodeHandle* handle)
{
    auto otherSet = ccwSet;
    if(otherSet == set) {
        otherSet = cwSet;
    }
    return npc(otherSet)->test(handle);
}

bool rice::pastry::leafset::LeafSet::directTest(::rice::pastry::NodeHandle* handle)
{
    return npc(cwSet)->test(handle) || npc(ccwSet)->test(handle);
}

rice::pastry::leafset::LeafSet* rice::pastry::leafset::LeafSet::copy()
{
    return new LeafSet(this);
}

rice::pastry::leafset::LeafSet* rice::pastry::leafset::LeafSet::build(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::pastry::NodeHandleFactory* nhf) /* throws(IOException) */
{
    clinit();
    auto theSize = npc(buf)->readByte();
    auto numUniqueHandles = npc(buf)->readByte();
    auto cwSize = npc(buf)->readByte();
    auto ccwSize = npc(buf)->readByte();
    auto baseHandle = java_cast< ::rice::pastry::NodeHandle* >(npc(nhf)->readNodeHandle(buf));
    auto nhTable = new ::rice::pastry::NodeHandleArray(numUniqueHandles);
    for (auto i = int32_t(0); i < numUniqueHandles; i++) {
        nhTable->set(i, java_cast< ::rice::pastry::NodeHandle* >(npc(nhf)->readNodeHandle(buf)));
    }
    auto cwTable = new ::rice::pastry::NodeHandleArray(cwSize);
    auto ccwTable = new ::rice::pastry::NodeHandleArray(ccwSize);
    for (auto i = int32_t(0); i < cwSize; i++) {
        cwTable->set(i, (*nhTable)[npc(buf)->readByte()]);
    }
    for (auto i = int32_t(0); i < ccwSize; i++) {
        ccwTable->set(i, (*nhTable)[npc(buf)->readByte()]);
    }
    return new LeafSet(baseHandle, theSize, true, cwTable, ccwTable);
}

void rice::pastry::leafset::LeafSet::ctor(::rice::pastry::NodeHandle* localNode, int32_t size, bool observe, ::rice::pastry::NodeHandleArray* cwTable, ::rice::pastry::NodeHandleArray* ccwTable)
{
    super::ctor();
    init();
    this->observe = observe;
    baseHandle = localNode;
    baseId = npc(localNode)->getNodeId();
    theSize = size;
    cwSet = new SimilarSet(this, localNode, size / int32_t(2), true, cwTable);
    ccwSet = new SimilarSet(this, localNode, size / int32_t(2), false, ccwTable);
}

void rice::pastry::leafset::LeafSet::serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */
{
    auto superset = new ::java::util::HashSet();
    npc(superset)->addAll(static_cast< ::java::util::Collection* >(npc(cwSet)->getCollection()));
    npc(superset)->addAll(static_cast< ::java::util::Collection* >(npc(ccwSet)->getCollection()));
    auto list = new ::java::util::ArrayList(static_cast< ::java::util::Collection* >(superset));
    npc(buf)->writeByte(static_cast< int8_t >(theSize));
    npc(buf)->writeByte(static_cast< int8_t >(npc(list)->size()));
    npc(buf)->writeByte(static_cast< int8_t >(cwSize()));
    npc(buf)->writeByte(static_cast< int8_t >(ccwSize()));
    npc(baseHandle)->serialize(buf);
    auto it = npc(list)->iterator();
    while (npc(it)->hasNext()) {
        auto nh = java_cast< ::rice::pastry::NodeHandle* >(java_cast< ::rice::pastry::NodeHandle* >(npc(it)->next()));
        npc(nh)->serialize(buf);
    }
    for (auto i = int32_t(0); i < npc(cwSet)->size(); i++) {
        npc(buf)->writeByte(static_cast< int8_t >(npc(list)->indexOf(static_cast< ::java::lang::Object* >(npc(cwSet)->get(i)))));
    }
    for (auto i = int32_t(0); i < npc(ccwSet)->size(); i++) {
        npc(buf)->writeByte(static_cast< int8_t >(npc(list)->indexOf(static_cast< ::java::lang::Object* >(npc(ccwSet)->get(i)))));
    }
}

java::util::List* rice::pastry::leafset::LeafSet::asList()
{
    ::java::util::List* l = new ::java::util::ArrayList();
    for (auto i = -ccwSize(); i <= cwSize(); i++) {
        if(i != 0) {
            npc(l)->add(static_cast< ::java::lang::Object* >(get(i)));
        }
    }
    return l;
}

void rice::pastry::leafset::LeafSet::destroy()
{
    npc(cwSet)->destroy();
    npc(ccwSet)->destroy();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::leafset::LeafSet::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.leafset.LeafSet", 27);
    return c;
}

java::lang::Class* rice::pastry::leafset::LeafSet::getClass0()
{
    return class_();
}

