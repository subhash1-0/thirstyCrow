// Generated from /pastry-2.1/src/rice/pastry/routing/RouteSet.java
#include <rice/pastry/routing/RouteSet.hpp>

#include <java/io/ObjectInputStream.hpp>
#include <java/io/ObjectOutputStream.hpp>
#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/CharSequence.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Comparable.hpp>
#include <java/lang/Integer.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/util/Arrays.hpp>
#include <java/util/Iterator.hpp>
#include <java/util/List.hpp>
#include <java/util/NoSuchElementException.hpp>
#include <java/util/Observable.hpp>
#include <java/util/Observer.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/commonapi/NodeHandle.hpp>
#include <rice/p2p/commonapi/rawserialization/InputBuffer.hpp>
#include <rice/p2p/commonapi/rawserialization/OutputBuffer.hpp>
#include <rice/p2p/commonapi/rawserialization/RawSerializable.hpp>
#include <rice/pastry/Id.hpp>
#include <rice/pastry/NodeHandle.hpp>
#include <rice/pastry/NodeHandleFactory.hpp>
#include <rice/pastry/PastryNode.hpp>
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
typedef ::SubArray< ::java::lang::CharSequence, ObjectArray > CharSequenceArray;
typedef ::SubArray< ::java::lang::Comparable, ObjectArray > ComparableArray;
typedef ::SubArray< ::java::lang::String, ObjectArray, ::java::io::SerializableArray, ComparableArray, CharSequenceArray > StringArray;
    } // lang

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

rice::pastry::routing::RouteSet::RouteSet(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::routing::RouteSet::RouteSet(int32_t maxSize, int32_t row, int32_t col, ::rice::pastry::PastryNode* local, ::rice::pastry::NodeHandle* initialVal) 
    : RouteSet(*static_cast< ::default_init_tag* >(0))
{
    ctor(maxSize,row,col,local,initialVal);
}

rice::pastry::routing::RouteSet::RouteSet(int32_t maxSize, int32_t row, int32_t col, ::rice::pastry::PastryNode* local) 
    : RouteSet(*static_cast< ::default_init_tag* >(0))
{
    ctor(maxSize,row,col,local);
}

rice::pastry::routing::RouteSet::RouteSet(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::pastry::NodeHandleFactory* nhf, ::rice::pastry::PastryNode* local)  /* throws(IOException) */
    : RouteSet(*static_cast< ::default_init_tag* >(0))
{
    ctor(buf,nhf,local);
}

constexpr int16_t rice::pastry::routing::RouteSet::TYPE;

constexpr int64_t rice::pastry::routing::RouteSet::serialVersionUID;

void rice::pastry::routing::RouteSet::ctor(int32_t maxSize, int32_t row, int32_t col, ::rice::pastry::PastryNode* local, ::rice::pastry::NodeHandle* initialVal)
{
    ctor(maxSize, row, col, local);
    nodes->set(theSize++, initialVal);
    closest = 0;
}

void rice::pastry::routing::RouteSet::ctor(int32_t maxSize, int32_t row, int32_t col, ::rice::pastry::PastryNode* local)
{
    super::ctor();
    this->localNode = local;
    nodes = new ::rice::pastry::NodeHandleArray(maxSize);
    theSize = 0;
    closest = -int32_t(1);
    this->row = row;
    this->col = col;
}

java::lang::String* rice::pastry::routing::RouteSet::toString()
{
    auto s = u"RS"_j;
    if(col >= 0) {
        s = ::java::lang::StringBuilder(s).append(::java::lang::StringBuilder().append(u"("_j)->append(row)
            ->append(u","_j)
            ->append((*::rice::pastry::Id::tran())[col])
            ->append(u"):"_j)->toString())->toString();
    } else {
        s = ::java::lang::StringBuilder(s).append(u":"_j)->toString();
    }
    for (auto i = int32_t(0); i < npc(nodes)->length; i++) {
        s = ::java::lang::StringBuilder(s).append(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >((*nodes)[i]))->append(u","_j)->toString())->toString();
    }
    return s;
}

bool rice::pastry::routing::RouteSet::put(::rice::pastry::NodeHandle* handle)
{
    if(!npc(handle)->isAlive())
        return false;

    auto worstIndex = -int32_t(1);
    auto worstProximity = ::java::lang::Integer::MIN_VALUE;
    for (auto i = int32_t(0); i < theSize; i++) {
        if(npc((*nodes)[i])->equals(static_cast< ::java::lang::Object* >(handle)))
            return false;

        if(!npc((*nodes)[i])->isAlive()) {
            notifyTable((*nodes)[i], false);
            npc((*nodes)[i])->deleteObserver(static_cast< ::java::util::Observer* >(this));
            nodes->set(i, handle);
            notifyTable(handle, true);
            npc(handle)->addObserver(static_cast< ::java::util::Observer* >(this));
            return true;
        }
        auto p = npc(localNode)->proximity((*nodes)[i]);
        if(p >= worstProximity) {
            worstProximity = p;
            worstIndex = i;
        }
    }
    if(theSize < npc(nodes)->length) {
        nodes->set(theSize++, handle);
        notifyTable(handle, true);
        npc(handle)->ping();
        npc(handle)->addObserver(static_cast< ::java::util::Observer* >(this));
        return true;
    } else {
        if(npc(localNode)->proximity(handle) == ::java::lang::Integer::MAX_VALUE) {
            npc(handle)->ping();
            npc(handle)->addObserver(static_cast< ::java::util::Observer* >(this));
            return false;
        } else if(npc(localNode)->proximity(handle) < worstProximity) {
            notifyTable((*nodes)[worstIndex], false);
            npc((*nodes)[worstIndex])->deleteObserver(static_cast< ::java::util::Observer* >(this));
            nodes->set(worstIndex, handle);
            notifyTable(handle, true);
            npc(handle)->addObserver(static_cast< ::java::util::Observer* >(this));
            return true;
        } else {
            return false;
        }
    }
}

void rice::pastry::routing::RouteSet::update(::java::util::Observable* o, ::java::lang::Object* arg)
{
    if((java_cast< ::java::lang::Integer* >(arg)) == ::rice::pastry::NodeHandle::PROXIMITY_CHANGED()) {
        put(java_cast< ::rice::pastry::NodeHandle* >(o));
    } else if((java_cast< ::java::lang::Integer* >(arg)) == ::rice::pastry::NodeHandle::DECLARED_DEAD()) {
        remove(java_cast< ::rice::pastry::NodeHandle* >(o));
    }
}

rice::pastry::NodeHandle* rice::pastry::routing::RouteSet::remove(::rice::pastry::Id* nid)
{
    for (auto i = int32_t(0); i < theSize; i++) {
        if(npc(npc((*nodes)[i])->getNodeId())->equals(nid)) {
            auto handle = (*nodes)[i];
            nodes->set(i, (*nodes)[--theSize]);
            notifyTable(handle, false);
            npc(handle)->deleteObserver(static_cast< ::java::util::Observer* >(this));
            return handle;
        }
    }
    return nullptr;
}

rice::pastry::NodeHandle* rice::pastry::routing::RouteSet::remove(::rice::pastry::NodeHandle* nh)
{
    for (auto i = int32_t(0); i < theSize; i++) {
        if(npc((*nodes)[i])->equals(static_cast< ::java::lang::Object* >(nh))) {
            auto handle = (*nodes)[i];
            nodes->set(i, (*nodes)[--theSize]);
            notifyTable(handle, false);
            npc(handle)->deleteObserver(static_cast< ::java::util::Observer* >(this));
            return handle;
        }
    }
    return nullptr;
}

void rice::pastry::routing::RouteSet::notifyTable(::rice::pastry::NodeHandle* handle, bool added)
{
    if(observer != nullptr)
        npc(observer)->nodeSetUpdate(this, handle, added);

}

void rice::pastry::routing::RouteSet::setRoutingTable(RoutingTable* rt)
{
    observer = rt;
}

bool rice::pastry::routing::RouteSet::member(::rice::pastry::NodeHandle* nh)
{
    for (auto i = int32_t(0); i < theSize; i++) 
                if(npc((*nodes)[i])->equals(static_cast< ::java::lang::Object* >(nh)))
            return true;


    return false;
}

bool rice::pastry::routing::RouteSet::member(::rice::pastry::Id* nid)
{
    for (auto i = int32_t(0); i < theSize; i++) 
                if(npc(npc((*nodes)[i])->getNodeId())->equals(nid))
            return true;


    return false;
}

int32_t rice::pastry::routing::RouteSet::size()
{
    return theSize;
}

int32_t rice::pastry::routing::RouteSet::capacity()
{
    return npc(nodes)->length;
}

void rice::pastry::routing::RouteSet::pingAllNew()
{
    for (auto i = int32_t(0); i < theSize; i++) {
        if(npc(localNode)->proximity((*nodes)[i]) == ::java::lang::Integer::MAX_VALUE)
            npc((*nodes)[i])->ping();

    }
}

rice::pastry::NodeHandle* rice::pastry::routing::RouteSet::closestNode()
{
    return closestNode(::rice::pastry::NodeHandle::LIVENESS_SUSPECTED);
}

rice::pastry::NodeHandle* rice::pastry::routing::RouteSet::closestNode(int32_t minLiveness)
{
    auto bestProximity = ::java::lang::Integer::MAX_VALUE;
    ::rice::pastry::NodeHandle* bestNode = nullptr;
    for (auto i = int32_t(0); i < theSize; i++) {
        if(npc((*nodes)[i])->getLiveness() > minLiveness)
            continue;

        auto p = npc(localNode)->proximity((*nodes)[i]);
        if(p <= bestProximity) {
            bestProximity = p;
            bestNode = (*nodes)[i];
            closest = i;
        }
    }
    if(bestNode != nullptr && bestProximity == ::java::lang::Integer::MAX_VALUE)
        npc(bestNode)->ping();

    return bestNode;
}

rice::pastry::NodeHandle* rice::pastry::routing::RouteSet::get(int32_t i)
{
    if(i < 0 || i >= theSize)
        throw new ::java::util::NoSuchElementException();

    return (*nodes)[i];
}

rice::pastry::NodeHandle* rice::pastry::routing::RouteSet::get(::rice::pastry::Id* nid)
{
    for (auto i = int32_t(0); i < theSize; i++) 
                if(npc(npc((*nodes)[i])->getNodeId())->equals(nid))
            return (*nodes)[i];


    return nullptr;
}

int32_t rice::pastry::routing::RouteSet::getIndex(::rice::pastry::Id* nid)
{
    for (auto i = int32_t(0); i < theSize; i++) 
                if(npc(npc((*nodes)[i])->getNodeId())->equals(nid))
            return i;


    return -int32_t(1);
}

int32_t rice::pastry::routing::RouteSet::getIndex(::rice::pastry::NodeHandle* nh)
{
    for (auto i = int32_t(0); i < theSize; i++) 
                if(npc((*nodes)[i])->equals(static_cast< ::java::lang::Object* >(nh)))
            return i;


    return -int32_t(1);
}

void rice::pastry::routing::RouteSet::readObject(::java::io::ObjectInputStream* in) /* throws(IOException, ClassNotFoundException) */
{
    nodes = java_cast< ::rice::pastry::NodeHandleArray* >(npc(in)->readObject());
    theSize = npc(in)->readInt();
    closest = npc(in)->readInt();
    if(closest != -int32_t(1))
        npc((*nodes)[closest])->ping();

    closest = -int32_t(1);
}

void rice::pastry::routing::RouteSet::writeObject(::java::io::ObjectOutputStream* out) /* throws(IOException, ClassNotFoundException) */
{
    if(closest == -int32_t(1))
        closestNode();

    auto tmp = new ::rice::pastry::NodeHandleArray(npc(nodes)->length);
    auto j = int32_t(0);
    for (auto i = int32_t(0); i < npc(tmp)->length; i++) {
        if(((*nodes)[i] != nullptr) && (npc((*nodes)[i])->isAlive())) {
            tmp->set(j, (*nodes)[i]);
            j++;
        }
    }
    npc(out)->writeObject(static_cast< ::java::lang::Object* >(tmp));
    npc(out)->writeInt(j);
    auto closest = -int32_t(1);
    for (auto i = int32_t(0); i < j; i++) 
                if((closest == -int32_t(1)) || (npc(localNode)->proximity((*tmp)[i]) < npc(localNode)->proximity((*tmp)[closest])))
            closest = i;


    npc(out)->writeInt(closest);
}

bool rice::pastry::routing::RouteSet::putHandle(::rice::p2p::commonapi::NodeHandle* handle)
{
    return put(java_cast< ::rice::pastry::NodeHandle* >(handle));
}

rice::p2p::commonapi::NodeHandle* rice::pastry::routing::RouteSet::getHandle(::rice::p2p::commonapi::Id* id)
{
    return getHandle(static_cast< ::rice::p2p::commonapi::Id* >(java_cast< ::rice::pastry::Id* >(id)));
}

rice::p2p::commonapi::NodeHandle* rice::pastry::routing::RouteSet::getHandle(int32_t i)
{
    return get(i);
}

bool rice::pastry::routing::RouteSet::memberHandle(::rice::p2p::commonapi::Id* id)
{
    return member(java_cast< ::rice::pastry::Id* >(id));
}

rice::p2p::commonapi::NodeHandle* rice::pastry::routing::RouteSet::removeHandle(::rice::p2p::commonapi::Id* id)
{
    return remove(java_cast< ::rice::pastry::Id* >(id));
}

int32_t rice::pastry::routing::RouteSet::getIndexHandle(::rice::p2p::commonapi::Id* id) /* throws(NoSuchElementException) */
{
    return getIndex(java_cast< ::rice::pastry::Id* >(id));
}

int16_t rice::pastry::routing::RouteSet::getType()
{
    return TYPE;
}

void rice::pastry::routing::RouteSet::serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */
{
    npc(buf)->writeByte(static_cast< int8_t >(npc(nodes)->length));
    npc(buf)->writeByte(static_cast< int8_t >(theSize));
    npc(buf)->writeByte(static_cast< int8_t >(closest));
    for (auto i = int32_t(0); i < theSize; i++) {
        npc((*nodes)[i])->serialize(buf);
    }
}

void rice::pastry::routing::RouteSet::ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::pastry::NodeHandleFactory* nhf, ::rice::pastry::PastryNode* local) /* throws(IOException) */
{
    super::ctor();
    this->localNode = local;
    auto maxSize = npc(buf)->readByte();
    theSize = npc(buf)->readByte();
    closest = npc(buf)->readByte();
    nodes = new ::rice::pastry::NodeHandleArray(maxSize);
    for (auto i = int32_t(0); i < theSize; i++) {
        nodes->set(i, java_cast< ::rice::pastry::NodeHandle* >(npc(nhf)->readNodeHandle(buf)));
    }
    row = -int32_t(1);
    col = -int32_t(1);
}

void rice::pastry::routing::RouteSet::destroy()
{
    for (auto i = int32_t(0); i < npc(nodes)->length; i++) {
        if((*nodes)[i] != nullptr) {
            npc((*nodes)[i])->deleteObserver(static_cast< ::java::util::Observer* >(this));
            nodes->set(i, nullptr);
        }
    }
}

java::util::Iterator* rice::pastry::routing::RouteSet::iterator()
{
    return npc(::java::util::Arrays::asList(nodes))->iterator();
}

bool rice::pastry::routing::RouteSet::isEmpty()
{
    return theSize <= 0;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::routing::RouteSet::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.routing.RouteSet", 28);
    return c;
}

java::lang::Class* rice::pastry::routing::RouteSet::getClass0()
{
    return class_();
}

