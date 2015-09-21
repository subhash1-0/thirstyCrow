// Generated from /pastry-2.1/src/rice/pastry/leafset/SimilarSet.java
#include <rice/pastry/leafset/SimilarSet.hpp>

#include <java/io/ObjectInputStream.hpp>
#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Iterable.hpp>
#include <java/lang/Math.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/System.hpp>
#include <java/util/ArrayList.hpp>
#include <java/util/Collections.hpp>
#include <java/util/Iterator.hpp>
#include <java/util/Observable.hpp>
#include <java/util/Observer.hpp>
#include <rice/p2p/commonapi/Id_Distance.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/commonapi/NodeHandle.hpp>
#include <rice/p2p/commonapi/NodeHandleSet.hpp>
#include <rice/p2p/commonapi/rawserialization/RawSerializable.hpp>
#include <rice/pastry/Id_Distance.hpp>
#include <rice/pastry/Id.hpp>
#include <rice/pastry/NodeHandle.hpp>
#include <rice/pastry/NodeSetI.hpp>
#include <rice/pastry/NodeSetListener.hpp>
#include <rice/pastry/NodeSetUpdate.hpp>
#include <rice/pastry/leafset/LeafSet.hpp>
#include <rice/pastry/leafset/SimilarSet_addNextEntry_1.hpp>
#include <rice/pastry/routing/RouteSet.hpp>
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

    namespace lang
    {
typedef ::SubArray< ::java::lang::Iterable, ObjectArray > IterableArray;
    } // lang

    namespace util
    {
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
rice::pastry::leafset::SimilarSet::SimilarSet(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::leafset::SimilarSet::SimilarSet(SimilarSet* that, LeafSet* ls) 
    : SimilarSet(*static_cast< ::default_init_tag* >(0))
{
    ctor(that,ls);
}

rice::pastry::leafset::SimilarSet::SimilarSet(LeafSet* leafSet, ::rice::pastry::NodeHandle* localNode, int32_t size, bool cw) 
    : SimilarSet(*static_cast< ::default_init_tag* >(0))
{
    ctor(leafSet,localNode,size,cw);
}

rice::pastry::leafset::SimilarSet::SimilarSet(LeafSet* leafSet, ::rice::pastry::NodeHandle* localNode, int32_t size, bool cw, ::rice::pastry::NodeHandleArray* handles) 
    : SimilarSet(*static_cast< ::default_init_tag* >(0))
{
    ctor(leafSet,localNode,size,cw,handles);
}

void rice::pastry::leafset::SimilarSet::init()
{
    listeners = new ::java::util::ArrayList();
    d1 = new ::rice::pastry::Id_Distance();
    d = new ::rice::pastry::Id_Distance();
}

constexpr int64_t rice::pastry::leafset::SimilarSet::serialVersionUID;

void rice::pastry::leafset::SimilarSet::ctor(SimilarSet* that, LeafSet* ls)
{
    super::ctor();
    init();
    this->ln = npc(that)->ln;
    this->clockwise = npc(that)->clockwise;
    this->nodes = new ::rice::pastry::NodeHandleArray(npc(npc(that)->nodes)->length);
    ::java::lang::System::arraycopy(npc(that)->nodes, 0, nodes, 0, npc(nodes)->length);
    this->theSize = npc(that)->theSize;
    this->leafSet = ls;
}

void rice::pastry::leafset::SimilarSet::swap(int32_t i, int32_t j)
{
    auto handle = (*nodes)[i];
    nodes->set(i, (*nodes)[j]);
    nodes->set(j, handle);
}

void rice::pastry::leafset::SimilarSet::ctor(LeafSet* leafSet, ::rice::pastry::NodeHandle* localNode, int32_t size, bool cw)
{
    super::ctor();
    init();
    this->leafSet = leafSet;
    ln = localNode;
    clockwise = cw;
    theSize = 0;
    nodes = new ::rice::pastry::NodeHandleArray(size);
}

void rice::pastry::leafset::SimilarSet::ctor(LeafSet* leafSet, ::rice::pastry::NodeHandle* localNode, int32_t size, bool cw, ::rice::pastry::NodeHandleArray* handles)
{
    super::ctor();
    init();
    this->leafSet = leafSet;
    ln = localNode;
    clockwise = cw;
    theSize = ::java::lang::Math::min(npc(handles)->length, size);
    nodes = new ::rice::pastry::NodeHandleArray(size);
    ::java::lang::System::arraycopy(handles, 0, nodes, 0, theSize);
}

bool rice::pastry::leafset::SimilarSet::test(::rice::pastry::NodeHandle* handle)
{
    auto nid = npc(handle)->getNodeId();
    if(npc(nid)->equals(npc(ln)->getNodeId()))
        return false;

    for (auto i = int32_t(0); i < theSize; i++) 
                if(npc(nid)->equals(npc((*nodes)[i])->getNodeId()))
            return false;


    if(theSize < npc(nodes)->length)
        return true;

    if(clockwise) {
        if(!npc(nid)->isBetween(npc(ln)->getNodeId(), npc((*nodes)[theSize - int32_t(1)])->getNodeId()))
            return false;

    } else {
        if(!npc(nid)->isBetween(npc((*nodes)[theSize - int32_t(1)])->getNodeId(), npc(ln)->getNodeId()))
            return false;

    }
    return true;
}

bool rice::pastry::leafset::SimilarSet::put(::rice::pastry::NodeHandle* handle)
{
    return put(handle, false);
}

bool rice::pastry::leafset::SimilarSet::put(::rice::pastry::NodeHandle* handle, bool suppressNotify)
{
    auto nid = npc(handle)->getNodeId();
    if(!test(handle))
        return false;

    if(theSize < npc(nodes)->length) {
        nodes->set(theSize, handle);
        theSize++;
    } else {
        auto removed = (*nodes)[theSize - int32_t(1)];
        nodes->set(theSize - int32_t(1), handle);
        if(npc(leafSet)->isProperlyRemoved(removed)) {
            if(npc(leafSet)->observe) {
                notifyListeners(removed, false);
            }
        }
    }
    if(clockwise) {
        for (auto i = theSize - int32_t(1); i > 0; i--) 
                        if(npc(nid)->isBetween(npc(ln)->getNodeId(), npc((*nodes)[i - int32_t(1)])->getNodeId()))
                swap(i, i - int32_t(1));
            else
                break;

    } else {
        for (auto i = theSize - int32_t(1); i > 0; i--) 
                        if(npc(nid)->isBetween(npc((*nodes)[i - int32_t(1)])->getNodeId(), npc(ln)->getNodeId()))
                swap(i, i - int32_t(1));
            else
                break;

    }
    if(!suppressNotify && !npc(leafSet)->testOtherSet(this, handle)) {
        if(npc(leafSet)->observe)
            notifyListeners(handle, true);

    }
    return true;
}

void rice::pastry::leafset::SimilarSet::addObserver(::java::util::Observer* o)
{
    super::addObserver(o);
}

void rice::pastry::leafset::SimilarSet::deleteObserver(::java::util::Observer* o)
{
    super::deleteObserver(o);
}

void rice::pastry::leafset::SimilarSet::addNodeSetListener(::rice::pastry::NodeSetListener* listener)
{
    {
        synchronized synchronized_0(listeners);
        {
            npc(listeners)->add(static_cast< ::java::lang::Object* >(listener));
        }
    }
}

void rice::pastry::leafset::SimilarSet::removeNodeSetListener(::rice::pastry::NodeSetListener* listener)
{
    {
        synchronized synchronized_1(listeners);
        {
            npc(listeners)->remove(static_cast< ::java::lang::Object* >(listener));
        }
    }
}

void rice::pastry::leafset::SimilarSet::notifyListeners(::rice::pastry::NodeHandle* handle, bool added)
{
    {
        synchronized synchronized_2(listeners);
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

rice::pastry::NodeHandle* rice::pastry::leafset::SimilarSet::get(::rice::pastry::Id* nid)
{
    for (auto i = int32_t(0); i < theSize; i++) 
                if(npc(npc((*nodes)[i])->getNodeId())->equals(nid))
            return (*nodes)[i];


    return nullptr;
}

rice::pastry::NodeHandle* rice::pastry::leafset::SimilarSet::get(::rice::pastry::NodeHandle* nh)
{
    for (auto i = int32_t(0); i < theSize; i++) 
                if(npc((*nodes)[i])->equals(static_cast< ::java::lang::Object* >(nh)))
            return (*nodes)[i];


    return nullptr;
}

rice::pastry::NodeHandle* rice::pastry::leafset::SimilarSet::get(int32_t i)
{
    if(i < -int32_t(1) || i >= theSize)
        return nullptr;

    if(i == -int32_t(1))
        return ln;

    return (*nodes)[i];
}

bool rice::pastry::leafset::SimilarSet::member(::rice::pastry::NodeHandle* nid)
{
    for (auto i = int32_t(0); i < theSize; i++) 
                if(npc((*nodes)[i])->equals(static_cast< ::java::lang::Object* >(nid)))
            return true;


    return false;
}

bool rice::pastry::leafset::SimilarSet::member(::rice::pastry::Id* nid)
{
    for (auto i = int32_t(0); i < theSize; i++) 
                if(npc(npc((*nodes)[i])->getId())->equals(nid))
            return true;


    return false;
}

rice::pastry::NodeHandle* rice::pastry::leafset::SimilarSet::remove(::rice::pastry::Id* nid)
{
    for (auto i = int32_t(0); i < theSize; i++) {
        if(npc(npc((*nodes)[i])->getNodeId())->equals(nid)) {
            return remove(i);
        }
    }
    return nullptr;
}

rice::pastry::NodeHandle* rice::pastry::leafset::SimilarSet::remove(::rice::pastry::NodeHandle* nh)
{
    for (auto i = int32_t(0); i < theSize; i++) {
        if(npc((*nodes)[i])->equals(static_cast< ::java::lang::Object* >(nh))) {
            return remove(i);
        }
    }
    return nullptr;
}

void rice::pastry::leafset::SimilarSet::findMoreEntriesFromRoutingTable()
{
    if(theSize < npc(nodes)->length) {
        auto table = npc(leafSet)->routingTable;
        if(table == nullptr)
            return;

        int32_t numRows = npc(table)->numRows();
        auto lnId = java_cast< ::rice::pastry::Id* >(npc(ln)->getId());
        auto numCols = npc(table)->numColumns();
        int32_t baseBitLength = npc(table)->baseBitLength();
        for (auto rowIndex = int32_t(0); rowIndex < numRows; rowIndex++) {
            auto row = npc(table)->getRow(rowIndex);
            if(row != nullptr) {
                auto colIndexStart = npc(lnId)->getDigit(rowIndex, baseBitLength);
                if(clockwise) {
                    for (auto colIndex = colIndexStart + int32_t(1); colIndex < numCols; colIndex++) {
                        if(addNextEntry((*row)[colIndex]))
                            return;

                    }
                } else {
                    for (auto colIndex = colIndexStart - int32_t(1); colIndex >= 0; colIndex--) {
                        if(addNextEntry((*row)[colIndex]))
                            return;

                    }
                }
            }
        }
        for (auto rowIndex = numRows - int32_t(1); rowIndex >= 0; rowIndex--) {
            auto row = npc(table)->getRow(rowIndex);
            if(row != nullptr) {
                auto colIndexEnd = npc(lnId)->getDigit(rowIndex, baseBitLength);
                if(clockwise) {
                    for (auto colIndex = int32_t(0); colIndex < colIndexEnd; colIndex++) {
                        if(addNextEntry((*row)[colIndex]))
                            return;

                    }
                } else {
                    for (auto colIndex = numCols - int32_t(1); colIndex > colIndexEnd; colIndex--) {
                        if(addNextEntry((*row)[colIndex]))
                            return;

                    }
                }
            }
        }
    }
}

bool rice::pastry::leafset::SimilarSet::addNextEntry(::rice::pastry::routing::RouteSet* rs)
{
    if(rs == nullptr)
        return false;

    if(npc(rs)->size() == 1) {
        auto nh = npc(rs)->get(int32_t(0));
        if(npc(nh)->isAlive()) {
            if(put(nh)) {
            }
        }
        return theSize == npc(nodes)->length;
    }
    auto toUse = new ::java::util::ArrayList();
    for (auto index = int32_t(0); index < npc(rs)->size(); index++) {
        auto nh = npc(rs)->get(index);
        if(npc(nh)->isAlive())
            npc(toUse)->add(static_cast< ::java::lang::Object* >(nh));

    }
    {
        ::java::util::Iterator* i;
        switch (npc(toUse)->size()) {
        case int32_t(0):
            return false;
        case int32_t(1): {
                auto nh = java_cast< ::rice::pastry::NodeHandle* >(npc(toUse)->get(int32_t(0)));
                if(put(nh)) {
                }
            }
            break;
        default:
            ::java::util::Collections::sort(toUse, new SimilarSet_addNextEntry_1(this));
            i = npc(toUse)->iterator();
            while (npc(i)->hasNext()) {
                auto nh = java_cast< ::rice::pastry::NodeHandle* >(npc(i)->next());
                if(put(nh)) {
                }
            }
        }
    }

    return theSize == npc(nodes)->length;
}

rice::pastry::NodeHandle* rice::pastry::leafset::SimilarSet::remove(int32_t i)
{
    if(i < 0 || i >= theSize)
        return nullptr;

    auto handle = (*nodes)[i];
    for (auto j = i + int32_t(1); j < theSize; j++) {
        nodes->set(j - int32_t(1), (*nodes)[j]);
    }
    theSize--;
    if(npc(leafSet)->isProperlyRemoved(handle)) {
        if(npc(leafSet)->observe)
            notifyListeners(handle, false);

    }
    return handle;
}

int32_t rice::pastry::leafset::SimilarSet::getIndex(::rice::pastry::Id* nid)
{
    for (auto i = int32_t(0); i < theSize; i++) 
                if(npc(npc((*nodes)[i])->getNodeId())->equals(nid))
            return i;


    return -int32_t(1);
}

int32_t rice::pastry::leafset::SimilarSet::getIndex(::rice::pastry::NodeHandle* nh)
{
    for (auto i = int32_t(0); i < theSize; i++) 
                if(npc((*nodes)[i])->equals(static_cast< ::java::lang::Object* >(nh)))
            return i;


    return -int32_t(1);
}

int32_t rice::pastry::leafset::SimilarSet::size()
{
    return theSize;
}

int32_t rice::pastry::leafset::SimilarSet::mostSimilar(::rice::pastry::Id* nid)
{
    if(theSize == 0)
        return -int32_t(1);

    auto other = d;
    auto minDist = npc(npc(ln)->getNodeId())->distance(nid, d1);
    auto min = -int32_t(1);
    for (auto i = int32_t(0); i < theSize; i++) {
        other = npc(npc((*nodes)[i])->getNodeId())->distance(nid, other);
        auto cmp = npc(other)->compareTo(static_cast< ::rice::p2p::commonapi::Id_Distance* >(minDist));
        if((!clockwise && cmp < 0) || (clockwise && cmp <= 0)) {
            auto tmp = minDist;
            minDist = other;
            other = tmp;
            min = i;
        }
    }
    return min;
}

bool rice::pastry::leafset::SimilarSet::putHandle(::rice::p2p::commonapi::NodeHandle* handle)
{
    return put(java_cast< ::rice::pastry::NodeHandle* >(handle));
}

rice::p2p::commonapi::NodeHandle* rice::pastry::leafset::SimilarSet::getHandle(int32_t i)
{
    return get(i);
}

bool rice::pastry::leafset::SimilarSet::memberHandle(::rice::p2p::commonapi::Id* id)
{
    return member(java_cast< ::rice::pastry::Id* >(id));
}

rice::p2p::commonapi::NodeHandle* rice::pastry::leafset::SimilarSet::removeHandle(::rice::p2p::commonapi::Id* id)
{
    return remove(java_cast< ::rice::pastry::Id* >(id));
}

int32_t rice::pastry::leafset::SimilarSet::getIndexHandle(::rice::p2p::commonapi::Id* id) /* throws(NoSuchElementException) */
{
    return getIndex(java_cast< ::rice::pastry::Id* >(id));
}

rice::pastry::leafset::SimilarSet* rice::pastry::leafset::SimilarSet::copy(LeafSet* newLeafSet)
{
    return new SimilarSet(this, newLeafSet);
}

java::util::Collection* rice::pastry::leafset::SimilarSet::getCollection()
{
    auto al = new ::java::util::ArrayList();
    for (auto i = int32_t(0); i < theSize; i++) {
        auto nh = (*nodes)[i];
        if(nh != nullptr) {
            npc(al)->add(static_cast< ::java::lang::Object* >(nh));
        }
    }
    return al;
}

void rice::pastry::leafset::SimilarSet::readObject(::java::io::ObjectInputStream* in) /* throws(IOException, ClassNotFoundException) */
{
    npc(in)->defaultReadObject();
    d1 = new ::rice::pastry::Id_Distance();
    d = new ::rice::pastry::Id_Distance();
    listeners = new ::java::util::ArrayList();
}

java::lang::String* rice::pastry::leafset::SimilarSet::toString()
{
    return ::java::lang::StringBuilder().append(u"SimilarSet{"_j)->append(static_cast< ::java::lang::Object* >(ln))
        ->append(u"}"_j)->toString();
}

void rice::pastry::leafset::SimilarSet::destroy()
{
    for (auto i = int32_t(0); i < npc(nodes)->length; i++) {
        if((*nodes)[i] != nullptr) {
            nodes->set(i, nullptr);
        }
    }
    theSize = 0;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::leafset::SimilarSet::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.leafset.SimilarSet", 30);
    return c;
}

java::lang::Class* rice::pastry::leafset::SimilarSet::getClass0()
{
    return class_();
}

