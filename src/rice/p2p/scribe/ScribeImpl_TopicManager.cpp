// Generated from /pastry-2.1/src/rice/p2p/scribe/ScribeImpl.java
#include <rice/p2p/scribe/ScribeImpl_TopicManager.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/util/ArrayList.hpp>
#include <java/util/Collection.hpp>
#include <java/util/Collections.hpp>
#include <java/util/Hashtable.hpp>
#include <java/util/Iterator.hpp>
#include <java/util/List.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/p2p/commonapi/Endpoint.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/commonapi/NodeHandle.hpp>
#include <rice/p2p/commonapi/rawserialization/RawMessage.hpp>
#include <rice/p2p/scribe/ScribeImpl.hpp>
#include <rice/p2p/scribe/ScribeMultiClient.hpp>
#include <rice/p2p/scribe/Topic.hpp>
#include <rice/p2p/scribe/maintenance/MaintainableScribe.hpp>
#include <rice/p2p/scribe/messaging/DropMessage.hpp>
#include <rice/p2p/scribe/messaging/SubscribeAckMessage.hpp>

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
rice::p2p::scribe::ScribeImpl_TopicManager::ScribeImpl_TopicManager(ScribeImpl *ScribeImpl_this, const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
    , ScribeImpl_this(ScribeImpl_this)
{
    clinit();
}

rice::p2p::scribe::ScribeImpl_TopicManager::ScribeImpl_TopicManager(ScribeImpl *ScribeImpl_this, Topic* topic) 
    : ScribeImpl_TopicManager(ScribeImpl_this, *static_cast< ::default_init_tag* >(0))
{
    ctor(topic);
}

void rice::p2p::scribe::ScribeImpl_TopicManager::ctor(Topic* topic)
{
    super::ctor();
    this->topic = topic;
    this->clients = new ::java::util::ArrayList();
    this->children = new ::java::util::ArrayList();
    setPathToRoot(nullptr);
}

rice::p2p::scribe::Topic* rice::p2p::scribe::ScribeImpl_TopicManager::getTopic()
{
    return topic;
}

rice::p2p::commonapi::NodeHandle* rice::p2p::scribe::ScribeImpl_TopicManager::getParent()
{
    return parent;
}

java::util::Collection* rice::p2p::scribe::ScribeImpl_TopicManager::getClients()
{
    return ::java::util::Collections::unmodifiableCollection(clients);
}

bool rice::p2p::scribe::ScribeImpl_TopicManager::containsClient(ScribeMultiClient* client)
{
    return npc(clients)->contains(static_cast< ::java::lang::Object* >(client));
}

java::util::Collection* rice::p2p::scribe::ScribeImpl_TopicManager::getChildren()
{
    return ::java::util::Collections::unmodifiableCollection(children);
}

int32_t rice::p2p::scribe::ScribeImpl_TopicManager::numChildren()
{
    return npc(children)->size();
}

java::util::List* rice::p2p::scribe::ScribeImpl_TopicManager::getPathToRoot()
{
    return pathToRoot;
}

void rice::p2p::scribe::ScribeImpl_TopicManager::setPathToRoot(::java::util::List* pathToRoot)
{
    if(pathToRoot == nullptr) {
        this->pathToRoot = new ::java::util::ArrayList();
    } else {
        this->pathToRoot = new ::java::util::ArrayList(static_cast< ::java::util::Collection* >(pathToRoot));
    }
    npc(java_cast< ::java::util::List* >(this->pathToRoot))->add(static_cast< ::java::lang::Object* >(npc(ScribeImpl_this->endpoint)->getId()));
    if(!npc(children)->isEmpty()) {
        ::java::util::List* sendDrop = new ::java::util::ArrayList();
        ::java::util::List* sendUpdate = new ::java::util::ArrayList();
        {
            synchronized synchronized_0(ScribeImpl_this->topicManagers);
            {
                auto children = getChildren();
                for (auto _i = npc(children)->iterator(); _i->hasNext(); ) {
                    ::rice::p2p::commonapi::NodeHandle* child = java_cast< ::rice::p2p::commonapi::NodeHandle* >(_i->next());
                    {
                        if(npc(java_cast< ::java::util::List* >(this->pathToRoot))->contains(static_cast< ::java::lang::Object* >(npc(child)->getId()))) {
                            npc(sendDrop)->add(static_cast< ::java::lang::Object* >(child));
                        } else {
                            npc(sendUpdate)->add(static_cast< ::java::lang::Object* >(child));
                        }
                    }
                }
                for (auto _i = npc(sendDrop)->iterator(); _i->hasNext(); ) {
                    ::rice::p2p::commonapi::NodeHandle* child = java_cast< ::rice::p2p::commonapi::NodeHandle* >(_i->next());
                    {
                        removeChild(child);
                    }
                }
            }
        }
        for (auto _i = npc(sendDrop)->iterator(); _i->hasNext(); ) {
            ::rice::p2p::commonapi::NodeHandle* child = java_cast< ::rice::p2p::commonapi::NodeHandle* >(_i->next());
            {
                npc(ScribeImpl_this->endpoint)->route(static_cast< ::rice::p2p::commonapi::Id* >(nullptr), static_cast< ::rice::p2p::commonapi::rawserialization::RawMessage* >(new ::rice::p2p::scribe::messaging::DropMessage(ScribeImpl_this->localHandle, topic)), child);
            }
        }
        for (auto _i = npc(sendUpdate)->iterator(); _i->hasNext(); ) {
            ::rice::p2p::commonapi::NodeHandle* child = java_cast< ::rice::p2p::commonapi::NodeHandle* >(_i->next());
            {
                npc(ScribeImpl_this->endpoint)->route(static_cast< ::rice::p2p::commonapi::Id* >(nullptr), static_cast< ::rice::p2p::commonapi::rawserialization::RawMessage* >(new ::rice::p2p::scribe::messaging::SubscribeAckMessage(ScribeImpl_this->localHandle, ::java::util::Collections::singletonList(topic), ::java::util::Collections::singletonList(getPathToRoot()), ::rice::p2p::scribe::maintenance::MaintainableScribe::MAINTENANCE_ID)), child);
            }
        }
    }
}

void rice::p2p::scribe::ScribeImpl_TopicManager::setParent(::rice::p2p::commonapi::NodeHandle* handle, ::java::util::List* pathToRoot)
{
    if(npc(ScribeImpl_this->logger)->level <= ::rice::environment::logging::Logger::INFO)
        npc(ScribeImpl_this->logger)->log(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(this))->append(u"setParent("_j)
            ->append(static_cast< ::java::lang::Object* >(handle))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(pathToRoot))
            ->append(u") prev:"_j)
            ->append(static_cast< ::java::lang::Object* >(parent))->toString());

    if((handle != nullptr) && !npc(handle)->isAlive()) {
        if(npc(ScribeImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(ScribeImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Setting dead parent "_j)->append(static_cast< ::java::lang::Object* >(handle))
                ->append(u" for "_j)
                ->append(static_cast< ::java::lang::Object* >(topic))->toString());

    }
    if((handle != nullptr) && (parent != nullptr)) {
        if(npc(handle)->equals(parent)) {
            setPathToRoot(pathToRoot);
            return;
        }
        if(npc(ScribeImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
            npc(ScribeImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Unexpectedly changing parents for topic "_j)->append(static_cast< ::java::lang::Object* >(topic))
                ->append(u":"_j)
                ->append(static_cast< ::java::lang::Object* >(parent))
                ->append(u"=>"_j)
                ->append(static_cast< ::java::lang::Object* >(handle))->toString());

    }
    auto prevParent = parent;
    parent = handle;
    setPathToRoot(pathToRoot);
    {
        synchronized synchronized_1(ScribeImpl_this->topicManagers);
        {
            ScribeImpl_this->removeFromAllParents(topic, prevParent);
            ScribeImpl_this->addToAllParents(topic, parent);
        }
    }
}

java::lang::String* rice::p2p::scribe::ScribeImpl_TopicManager::toString()
{
    return npc(topic)->toString();
}

void rice::p2p::scribe::ScribeImpl_TopicManager::addClient(ScribeMultiClient* client)
{
    if(client == nullptr)
        return;

    if(!npc(clients)->contains(static_cast< ::java::lang::Object* >(client))) {
        npc(clients)->add(static_cast< ::java::lang::Object* >(client));
    }
}

bool rice::p2p::scribe::ScribeImpl_TopicManager::removeClient(ScribeMultiClient* client)
{
    npc(clients)->remove(static_cast< ::java::lang::Object* >(client));
    auto unsub = ((npc(clients)->size() == 0) && (npc(children)->size() == 0));
    return unsub;
}

bool rice::p2p::scribe::ScribeImpl_TopicManager::containsChild(::rice::p2p::commonapi::NodeHandle* child)
{
    if(npc(children)->contains(static_cast< ::java::lang::Object* >(child))) {
        return true;
    } else {
        return false;
    }
}

void rice::p2p::scribe::ScribeImpl_TopicManager::addChild(::rice::p2p::commonapi::NodeHandle* child)
{
    if(npc(ScribeImpl_this->logger)->level <= ::rice::environment::logging::Logger::INFO)
        npc(ScribeImpl_this->logger)->log(::java::lang::StringBuilder().append(u"addChild( "_j)->append(static_cast< ::java::lang::Object* >(topic))
            ->append(u", "_j)
            ->append(static_cast< ::java::lang::Object* >(child))
            ->append(u")"_j)->toString());

    if(!npc(children)->contains(static_cast< ::java::lang::Object* >(child))) {
        if(npc(child)->isAlive()) {
            npc(children)->add(static_cast< ::java::lang::Object* >(child));
            ScribeImpl_this->addToAllChildren(topic, child);
        } else {
            if(npc(ScribeImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
                npc(ScribeImpl_this->logger)->logException(::java::lang::StringBuilder().append(u"WARNING: addChild("_j)->append(static_cast< ::java::lang::Object* >(topic))
                    ->append(u", "_j)
                    ->append(static_cast< ::java::lang::Object* >(child))
                    ->append(u") did not add child since the child.isAlive() failed"_j)->toString(), new ::java::lang::Exception(u"Stack Trace"_j));

        }
    }
}

bool rice::p2p::scribe::ScribeImpl_TopicManager::removeChild(::rice::p2p::commonapi::NodeHandle* child)
{
    if(npc(ScribeImpl_this->logger)->level <= ::rice::environment::logging::Logger::INFO)
        npc(ScribeImpl_this->logger)->log(::java::lang::StringBuilder().append(u"removeChild( "_j)->append(static_cast< ::java::lang::Object* >(topic))
            ->append(u", "_j)
            ->append(static_cast< ::java::lang::Object* >(child))
            ->append(u")"_j)->toString());

    npc(children)->remove(static_cast< ::java::lang::Object* >(child));
    auto unsub = ((npc(clients)->size() == 0) && (npc(children)->size() == 0));
    ScribeImpl_this->removeFromAllChildren(topic, child);
    return unsub;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::scribe::ScribeImpl_TopicManager::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.scribe.ScribeImpl.TopicManager", 39);
    return c;
}

java::lang::Class* rice::p2p::scribe::ScribeImpl_TopicManager::getClass0()
{
    return class_();
}

