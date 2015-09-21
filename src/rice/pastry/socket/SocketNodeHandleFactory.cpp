// Generated from /pastry-2.1/src/rice/pastry/socket/SocketNodeHandleFactory.java
#include <rice/pastry/socket/SocketNodeHandleFactory.hpp>

#include <java/lang/Class.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/util/ArrayList.hpp>
#include <java/util/Collection.hpp>
#include <java/util/HashMap.hpp>
#include <java/util/Iterator.hpp>
#include <java/util/Map.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/LogManager.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/pastry/NodeHandleFactoryListener.hpp>
#include <rice/pastry/PastryNode.hpp>
#include <rice/pastry/socket/SocketNodeHandle.hpp>

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
rice::pastry::socket::SocketNodeHandleFactory::SocketNodeHandleFactory(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::socket::SocketNodeHandleFactory::SocketNodeHandleFactory(::rice::pastry::PastryNode* pn) 
    : SocketNodeHandleFactory(*static_cast< ::default_init_tag* >(0))
{
    ctor(pn);
}

void rice::pastry::socket::SocketNodeHandleFactory::init()
{
    listeners = new ::java::util::ArrayList();
}

void rice::pastry::socket::SocketNodeHandleFactory::ctor(::rice::pastry::PastryNode* pn)
{
    super::ctor();
    init();
    this->pn = pn;
    this->logger = npc(npc(npc(pn)->getEnvironment())->getLogManager())->getLogger(SocketNodeHandleFactory::class_(), nullptr);
    handleSet = new ::java::util::HashMap();
}

rice::pastry::socket::SocketNodeHandle* rice::pastry::socket::SocketNodeHandleFactory::getNodeHandle(::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* i, int64_t epoch, ::rice::pastry::Id* id)
{
    auto handle = new SocketNodeHandle(i, epoch, id, pn);
    return java_cast< SocketNodeHandle* >(coalesce(handle));
}

rice::pastry::socket::SocketNodeHandle* rice::pastry::socket::SocketNodeHandleFactory::readNodeHandle(::rice::p2p::commonapi::rawserialization::InputBuffer* buf) /* throws(IOException) */
{
    return coalesce(SocketNodeHandle::build(buf, pn));
}

rice::pastry::socket::SocketNodeHandle* rice::pastry::socket::SocketNodeHandleFactory::coalesce(SocketNodeHandle* h)
{
    auto handle = java_cast< SocketNodeHandle* >(h);
    if(npc(handleSet)->containsKey(handle)) {
        return java_cast< SocketNodeHandle* >(npc(handleSet)->get(handle));
    }
    npc(handle)->setLocalNode(pn);
    npc(handleSet)->put(handle, handle);
    notifyListeners(handle);
    return handle;
}

rice::pastry::NodeHandle* rice::pastry::socket::SocketNodeHandleFactory::coalesce(::rice::pastry::NodeHandle* handle)
{ 
    return coalesce(dynamic_cast< SocketNodeHandle* >(handle));
}

void rice::pastry::socket::SocketNodeHandleFactory::notifyListeners(SocketNodeHandle* nh)
{
    auto temp = listeners;
    {
        synchronized synchronized_0(listeners);
        {
            temp = new ::java::util::ArrayList(static_cast< ::java::util::Collection* >(listeners));
        }
    }
    for (auto _i = npc(temp)->iterator(); _i->hasNext(); ) {
        ::rice::pastry::NodeHandleFactoryListener* foo = java_cast< ::rice::pastry::NodeHandleFactoryListener* >(_i->next());
        {
            npc(foo)->nodeHandleFound(nh);
        }
    }
}

void rice::pastry::socket::SocketNodeHandleFactory::addNodeHandleFactoryListener(::rice::pastry::NodeHandleFactoryListener* listener)
{
    {
        synchronized synchronized_1(listeners);
        {
            npc(listeners)->add(listener);
        }
    }
}

void rice::pastry::socket::SocketNodeHandleFactory::removeNodeHandleFactoryListener(::rice::pastry::NodeHandleFactoryListener* listener)
{
    {
        synchronized synchronized_2(listeners);
        {
            npc(listeners)->remove(listener);
        }
    }
}

rice::pastry::socket::SocketNodeHandle* rice::pastry::socket::SocketNodeHandleFactory::deserialize(::rice::p2p::commonapi::rawserialization::InputBuffer* buf) /* throws(IOException) */
{
    return readNodeHandle(buf);
}

void rice::pastry::socket::SocketNodeHandleFactory::serialize(SocketNodeHandle* i, ::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */
{
    npc(i)->serialize(buf);
}

void rice::pastry::socket::SocketNodeHandleFactory::serialize(::java::lang::Object* i, ::rice::p2p::commonapi::rawserialization::OutputBuffer* buf)
{ 
    serialize(dynamic_cast< SocketNodeHandle* >(i), buf);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::socket::SocketNodeHandleFactory::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.socket.SocketNodeHandleFactory", 42);
    return c;
}

java::lang::Class* rice::pastry::socket::SocketNodeHandleFactory::getClass0()
{
    return class_();
}

