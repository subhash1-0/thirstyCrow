// Generated from /pastry-2.1/src/rice/pastry/NodeSet.java
#include <rice/pastry/NodeSet.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/util/Collection.hpp>
#include <java/util/Iterator.hpp>
#include <java/util/List.hpp>
#include <java/util/Vector.hpp>
#include <rice/environment/random/RandomSource.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/commonapi/NodeHandle.hpp>
#include <rice/p2p/commonapi/rawserialization/InputBuffer.hpp>
#include <rice/p2p/commonapi/rawserialization/OutputBuffer.hpp>
#include <rice/pastry/Id.hpp>
#include <rice/pastry/NodeHandle.hpp>
#include <rice/pastry/NodeHandleFactory.hpp>

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
rice::pastry::NodeSet::NodeSet(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::NodeSet::NodeSet() 
    : NodeSet(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

rice::pastry::NodeSet::NodeSet(::java::util::Vector* s) 
    : NodeSet(*static_cast< ::default_init_tag* >(0))
{
    ctor(s);
}

rice::pastry::NodeSet::NodeSet(NodeSet* o) 
    : NodeSet(*static_cast< ::default_init_tag* >(0))
{
    ctor(o);
}

rice::pastry::NodeSet::NodeSet(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, NodeHandleFactory* nhf)  /* throws(IOException) */
    : NodeSet(*static_cast< ::default_init_tag* >(0))
{
    ctor(buf,nhf);
}

constexpr int16_t rice::pastry::NodeSet::TYPE;

constexpr int64_t rice::pastry::NodeSet::serialVersionUID;

void rice::pastry::NodeSet::ctor()
{
    super::ctor();
    set = new ::java::util::Vector();
}

void rice::pastry::NodeSet::ctor(::java::util::Vector* s)
{
    super::ctor();
    set = s;
}

void rice::pastry::NodeSet::ctor(NodeSet* o)
{
    super::ctor();
    set = new ::java::util::Vector(static_cast< ::java::util::Collection* >(npc(o)->set));
}

bool rice::pastry::NodeSet::put(NodeHandle* handle)
{
    if(npc(set)->contains(static_cast< ::java::lang::Object* >(handle)))
        return false;

    npc(set)->add(static_cast< ::java::lang::Object* >(handle));
    return true;
}

void rice::pastry::NodeSet::randomize(::rice::environment::random::RandomSource* random)
{
    for (auto i = int32_t(0); i < npc(set)->size(); i++) {
        auto a = npc(random)->nextInt(npc(set)->size());
        auto b = npc(random)->nextInt(npc(set)->size());
        auto tmp = java_cast< NodeHandle* >(npc(set)->elementAt(a));
        npc(set)->setElementAt(java_cast< NodeHandle* >(npc(set)->elementAt(b)), a);
        npc(set)->setElementAt(tmp, b);
    }
}

rice::pastry::NodeHandle* rice::pastry::NodeSet::get(Id* nid)
{
    try {
        return java_cast< NodeHandle* >(java_cast< NodeHandle* >(npc(set)->elementAt(getIndex(nid))));
    } catch (::java::lang::Exception* e) {
        return nullptr;
    }
}

rice::pastry::NodeHandle* rice::pastry::NodeSet::get(int32_t i)
{
    NodeHandle* h;
    try {
        h = java_cast< NodeHandle* >(java_cast< NodeHandle* >(npc(set)->elementAt(i)));
    } catch (::java::lang::Exception* e) {
        return nullptr;
    }
    return h;
}

bool rice::pastry::NodeSet::memberId(::rice::p2p::commonapi::Id* id)
{
    return (getIndexId(id) >= 0);
}

rice::pastry::NodeHandle* rice::pastry::NodeSet::remove(Id* nid)
{
    try {
        return java_cast< NodeHandle* >(java_cast< NodeHandle* >(npc(set)->remove(getIndex(nid))));
    } catch (::java::lang::Exception* e) {
        return nullptr;
    }
}

int32_t rice::pastry::NodeSet::size()
{
    return npc(set)->size();
}

int32_t rice::pastry::NodeSet::getIndex(Id* nid)
{
    return getIndexId(nid);
}

int32_t rice::pastry::NodeSet::getIndex(NodeHandle* nh)
{
    NodeHandle* h;
    for (auto i = int32_t(0); i < npc(set)->size(); i++) {
        try {
            h = java_cast< NodeHandle* >(java_cast< NodeHandle* >(npc(set)->elementAt(i)));
            if(npc(h)->equals(static_cast< ::java::lang::Object* >(nh)))
                return i;

        } catch (::java::lang::Exception* e) {
        }
    }
    return -int32_t(1);
}

int32_t rice::pastry::NodeSet::getIndexId(::rice::p2p::commonapi::Id* nid)
{
    NodeHandle* h;
    for (auto i = int32_t(0); i < npc(set)->size(); i++) {
        try {
            h = java_cast< NodeHandle* >(java_cast< NodeHandle* >(npc(set)->elementAt(i)));
            if(npc(npc(h)->getNodeId())->equals(static_cast< ::java::lang::Object* >(nid)))
                return i;

        } catch (::java::lang::Exception* e) {
        }
    }
    return -int32_t(1);
}

bool rice::pastry::NodeSet::insert(int32_t index, NodeHandle* handle)
{
    if(npc(set)->contains(static_cast< ::java::lang::Object* >(handle)))
        return false;

    npc(set)->add(index, static_cast< ::java::lang::Object* >(handle));
    return true;
}

rice::pastry::NodeHandle* rice::pastry::NodeSet::remove(NodeHandle* handle)
{
    if(npc(set)->remove(static_cast< ::java::lang::Object* >(handle))) {
        return handle;
    }
    return nullptr;
}

void rice::pastry::NodeSet::remove(int32_t index)
{
    npc(set)->remove(index);
}

int32_t rice::pastry::NodeSet::indexOf(NodeHandle* handle)
{
    return npc(set)->indexOf(static_cast< ::java::lang::Object* >(handle));
}

bool rice::pastry::NodeSet::member(NodeHandle* handle)
{
    return npc(set)->contains(static_cast< ::java::lang::Object* >(handle));
}

rice::pastry::NodeSet* rice::pastry::NodeSet::subSet(int32_t from, int32_t to)
{
    NodeSet* res;
    try {
        res = new NodeSet(static_cast< ::java::util::Vector* >(new ::java::util::Vector(static_cast< ::java::util::Collection* >(npc(set)->subList(from, to)))));
    } catch (::java::lang::Exception* e) {
        return nullptr;
    }
    return res;
}

java::util::Iterator* rice::pastry::NodeSet::getIterator()
{
    return npc(set)->iterator();
}

java::lang::String* rice::pastry::NodeSet::toString()
{
    auto s = u"NodeSet: "_j;
    for (auto i = int32_t(0); i < size(); i++) 
                s = ::java::lang::StringBuilder().append(s)->append(static_cast< ::java::lang::Object* >(npc(get(i))->getNodeId()))->toString();

    return s;
}

bool rice::pastry::NodeSet::putHandle(::rice::p2p::commonapi::NodeHandle* handle)
{
    return put(java_cast< NodeHandle* >(handle));
}

rice::p2p::commonapi::NodeHandle* rice::pastry::NodeSet::getHandle(::rice::p2p::commonapi::Id* id)
{
    {
        synchronized synchronized_0(set);
        {
            for (auto _i = npc(set)->iterator(); _i->hasNext(); ) {
                NodeHandle* nh = java_cast< NodeHandle* >(_i->next());
                {
                    if(npc(npc(nh)->getId())->equals(id))
                        return nh;

                }
            }
        }
    }
    return nullptr;
}

rice::p2p::commonapi::NodeHandle* rice::pastry::NodeSet::getHandle(int32_t i)
{
    return get(i);
}

bool rice::pastry::NodeSet::memberHandle(::rice::p2p::commonapi::Id* id)
{
    return memberId(id);
}

rice::p2p::commonapi::NodeHandle* rice::pastry::NodeSet::removeHandle(::rice::p2p::commonapi::Id* id)
{
    return remove(java_cast< Id* >(id));
}

int32_t rice::pastry::NodeSet::getIndexHandle(::rice::p2p::commonapi::Id* id) /* throws(NoSuchElementException) */
{
    return getIndex(java_cast< Id* >(id));
}

java::util::Iterator* rice::pastry::NodeSet::iterator()
{
    return npc(set)->iterator();
}

void rice::pastry::NodeSet::ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, NodeHandleFactory* nhf) /* throws(IOException) */
{
    super::ctor();
    auto numNodes = npc(buf)->readShort();
    set = new ::java::util::Vector(static_cast< int32_t >(numNodes));
    for (auto i = int32_t(0); i < numNodes; i++) {
        npc(set)->add(static_cast< ::java::lang::Object* >(java_cast< NodeHandle* >(npc(nhf)->readNodeHandle(buf))));
    }
}

void rice::pastry::NodeSet::serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */
{
    npc(buf)->writeShort(static_cast< int16_t >(npc(set)->size()));
    auto i = npc(set)->iterator();
    while (npc(i)->hasNext()) {
        auto nh = java_cast< NodeHandle* >(java_cast< NodeHandle* >(npc(i)->next()));
        npc(nh)->serialize(buf);
    }
}

int16_t rice::pastry::NodeSet::getType()
{
    return TYPE;
}

java::util::Collection* rice::pastry::NodeSet::getCollection()
{
    return set;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::NodeSet::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.NodeSet", 19);
    return c;
}

java::lang::Class* rice::pastry::NodeSet::getClass0()
{
    return class_();
}

