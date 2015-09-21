// Generated from /pastry-2.1/src/rice/pastry/direct/DirectPastryNodeFactory.java
#include <rice/pastry/direct/DirectPastryNodeFactory_getNodeHandleFactory_1.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/util/ArrayList.hpp>
#include <java/util/Collection.hpp>
#include <java/util/Iterator.hpp>
#include <rice/pastry/NodeHandle.hpp>
#include <rice/pastry/NodeHandleFactoryListener.hpp>
#include <rice/pastry/direct/DirectPastryNodeFactory.hpp>

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
rice::pastry::direct::DirectPastryNodeFactory_getNodeHandleFactory_1::DirectPastryNodeFactory_getNodeHandleFactory_1(DirectPastryNodeFactory *DirectPastryNodeFactory_this)
    : super(*static_cast< ::default_init_tag* >(0))
    , DirectPastryNodeFactory_this(DirectPastryNodeFactory_this)
{
    clinit();
    ctor();
}

rice::pastry::NodeHandle* rice::pastry::direct::DirectPastryNodeFactory_getNodeHandleFactory_1::readNodeHandle(::rice::p2p::commonapi::rawserialization::InputBuffer* buf) /* throws(IOException) */
{
    return nullptr;
}

rice::pastry::NodeHandle* rice::pastry::direct::DirectPastryNodeFactory_getNodeHandleFactory_1::coalesce(::rice::pastry::NodeHandle* handle)
{
    notifyListeners(handle);
    return nullptr;
}

void rice::pastry::direct::DirectPastryNodeFactory_getNodeHandleFactory_1::notifyListeners(::rice::pastry::NodeHandle* nh)
{
    auto temp = DirectPastryNodeFactory_this->listeners;
    {
        synchronized synchronized_0(DirectPastryNodeFactory_this->listeners);
        {
            temp = new ::java::util::ArrayList(static_cast< ::java::util::Collection* >(DirectPastryNodeFactory_this->listeners));
        }
    }
    for (auto _i = npc(temp)->iterator(); _i->hasNext(); ) {
        ::rice::pastry::NodeHandleFactoryListener* foo = java_cast< ::rice::pastry::NodeHandleFactoryListener* >(_i->next());
        {
            npc(foo)->nodeHandleFound(nh);
        }
    }
}

void rice::pastry::direct::DirectPastryNodeFactory_getNodeHandleFactory_1::addNodeHandleFactoryListener(::rice::pastry::NodeHandleFactoryListener* listener)
{
    {
        synchronized synchronized_1(DirectPastryNodeFactory_this->listeners);
        {
            npc(DirectPastryNodeFactory_this->listeners)->add(listener);
        }
    }
}

void rice::pastry::direct::DirectPastryNodeFactory_getNodeHandleFactory_1::removeNodeHandleFactoryListener(::rice::pastry::NodeHandleFactoryListener* listener)
{
    {
        synchronized synchronized_2(DirectPastryNodeFactory_this->listeners);
        {
            npc(DirectPastryNodeFactory_this->listeners)->remove(listener);
        }
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::direct::DirectPastryNodeFactory_getNodeHandleFactory_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::pastry::direct::DirectPastryNodeFactory_getNodeHandleFactory_1::getClass0()
{
    return class_();
}

