// Generated from /pastry-2.1/src/rice/pastry/NodeHandle.java
#include <rice/pastry/NodeHandle.hpp>

#include <java/io/ObjectInputStream.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/RuntimeException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/System.hpp>
#include <java/util/ArrayList.hpp>
#include <java/util/Collection.hpp>
#include <java/util/Collections.hpp>
#include <java/util/Iterator.hpp>
#include <java/util/List.hpp>
#include <java/util/Observer.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/pastry/Id.hpp>
#include <rice/pastry/NodeHandle_ObsPri.hpp>
#include <rice/pastry/PastryNode.hpp>

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
rice::pastry::NodeHandle::NodeHandle(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::NodeHandle::NodeHandle()
    : NodeHandle(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

void rice::pastry::NodeHandle::ctor()
{
    super::ctor();
    init();
}

void rice::pastry::NodeHandle::init()
{
    obs = new ::java::util::ArrayList();
}

constexpr int32_t rice::pastry::NodeHandle::LIVENESS_ALIVE;

constexpr int32_t rice::pastry::NodeHandle::LIVENESS_SUSPECTED;

constexpr int32_t rice::pastry::NodeHandle::LIVENESS_DEAD;

constexpr int64_t rice::pastry::NodeHandle::serialVersionUID;

rice::p2p::commonapi::Id* rice::pastry::NodeHandle::getId()
{
    return getNodeId();
}

bool rice::pastry::NodeHandle::isAlive()
{
    return getLiveness() < LIVENESS_DEAD;
}

bool rice::pastry::NodeHandle::checkLiveness()
{
    return ping();
}

rice::pastry::PastryNode* rice::pastry::NodeHandle::getLocalNode()
{
    return localnode;
}

void rice::pastry::NodeHandle::assertLocalNode()
{
    if(localnode == nullptr) {
        throw new ::java::lang::RuntimeException(::java::lang::StringBuilder().append(u"PANIC: localnode is null in "_j)->append(static_cast< ::java::lang::Object* >(this))
            ->append(u"@"_j)
            ->append(::java::lang::System::identityHashCode(this))->toString());
    }
}

void rice::pastry::NodeHandle::bootstrap(::rice::pastry::messaging::Message* msg) /* throws(IOException) */
{
    receiveMessage(msg);
}

void rice::pastry::NodeHandle::readObject(::java::io::ObjectInputStream* in) /* throws(IOException, ClassNotFoundException) */
{
    npc(in)->defaultReadObject();
    obs = new ::java::util::ArrayList();
}

void rice::pastry::NodeHandle::addObserver(::java::util::Observer* o)
{
    addObserver(o, 0);
}

void rice::pastry::NodeHandle::addObserver(::java::util::Observer* o, int32_t priority)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
        npc(logger)->log(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(this))->append(u".addObserver("_j)
            ->append(static_cast< ::java::lang::Object* >(o))
            ->append(u")"_j)->toString());

    {
        synchronized synchronized_0(obs);
        {
            for (auto i = int32_t(0); i < npc(obs)->size(); i++) {
                auto op = java_cast< NodeHandle_ObsPri* >(npc(obs)->get(i));
                if(npc(npc(op)->obs)->equals(o)) {
                    if(npc(op)->pri != priority) {
                        if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                            npc(logger)->log(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(this))->append(u".addObserver("_j)
                                ->append(static_cast< ::java::lang::Object* >(o))
                                ->append(u","_j)
                                ->append(priority)
                                ->append(u") changed priority, was:"_j)
                                ->append(static_cast< ::java::lang::Object* >(op))->toString());

                        npc(op)->pri = priority;
                        ::java::util::Collections::sort(obs);
                        return;
                    }
                }
            }
            npc(obs)->add(static_cast< ::java::lang::Object* >(new NodeHandle_ObsPri(o, priority)));
            ::java::util::Collections::sort(obs);
        }
    }
}

void rice::pastry::NodeHandle::deleteObserver(::java::util::Observer* o)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
        npc(logger)->log(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(this))->append(u".deleteObserver("_j)
            ->append(static_cast< ::java::lang::Object* >(o))
            ->append(u")"_j)->toString());

    {
        synchronized synchronized_1(obs);
        {
            for (auto i = int32_t(0); i < npc(obs)->size(); i++) {
                auto op = java_cast< NodeHandle_ObsPri* >(npc(obs)->get(i));
                if(npc(npc(op)->obs)->equals(o)) {
                    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINEST)
                        npc(logger)->log(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(this))->append(u".deleteObserver("_j)
                            ->append(static_cast< ::java::lang::Object* >(o))
                            ->append(u"):success"_j)->toString());

                    npc(obs)->remove(i);
                    return;
                }
            }
            if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
                npc(logger)->log(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(this))->append(u".deleteObserver("_j)
                    ->append(static_cast< ::java::lang::Object* >(o))
                    ->append(u"):failure "_j)
                    ->append(static_cast< ::java::lang::Object* >(o))
                    ->append(u" was not an observer."_j)->toString());

        }
    }
}

void rice::pastry::NodeHandle::notifyObservers(::java::lang::Object* arg)
{
    ::java::util::List* l;
    {
        synchronized synchronized_2(obs);
        {
            l = new ::java::util::ArrayList(static_cast< ::java::util::Collection* >(obs));
        }
    }
    for (auto _i = npc(l)->iterator(); _i->hasNext(); ) {
        NodeHandle_ObsPri* op = java_cast< NodeHandle_ObsPri* >(_i->next());
        {
            if(npc(logger)->level <= ::rice::environment::logging::Logger::FINEST)
                npc(logger)->log(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(this))->append(u".notifyObservers("_j)
                    ->append(static_cast< ::java::lang::Object* >(arg))
                    ->append(u"):notifying "_j)
                    ->append(static_cast< ::java::lang::Object* >(op))->toString());

            npc(npc(op)->obs)->update(this, arg);
        }
    }
}

int32_t rice::pastry::NodeHandle::countObservers()
{
    return npc(obs)->size();
}

void rice::pastry::NodeHandle::deleteObservers()
{
    npc(obs)->clear();
}

void rice::pastry::NodeHandle::update(::java::lang::Object* update)
{
    if(logger != nullptr) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE) {
            npc(logger)->log(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(this))->append(u".update("_j)
                ->append(static_cast< ::java::lang::Object* >(update))
                ->append(u")"_j)
                ->append(countObservers())->toString());
        }
    }
    notifyObservers(update);
    if(logger != nullptr) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::FINEST) {
            npc(logger)->log(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(this))->append(u".update("_j)
                ->append(static_cast< ::java::lang::Object* >(update))
                ->append(u")"_j)
                ->append(countObservers())
                ->append(u" done"_j)->toString());
        }
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::NodeHandle::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.NodeHandle", 22);
    return c;
}

void rice::pastry::NodeHandle::notifyObservers()
{
    super::notifyObservers();
}

java::lang::Class* rice::pastry::NodeHandle::getClass0()
{
    return class_();
}

