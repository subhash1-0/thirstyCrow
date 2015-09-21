// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/identity/IdentityImpl.java
#include <org/mpisws/p2p/transport/identity/IdentityImpl.hpp>

#include <java/lang/Class.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/IllegalArgumentException.hpp>
#include <java/lang/IllegalStateException.hpp>
#include <java/lang/Integer.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/RuntimeException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/util/Collections.hpp>
#include <java/util/HashMap.hpp>
#include <java/util/HashSet.hpp>
#include <java/util/Iterator.hpp>
#include <java/util/Map.hpp>
#include <java/util/Set.hpp>
#include <org/mpisws/p2p/transport/identity/BindStrategy.hpp>
#include <org/mpisws/p2p/transport/identity/IdentityImpl_IdentityImpl_1.hpp>
#include <org/mpisws/p2p/transport/identity/IdentityImpl_IdentityMessageHandle.hpp>
#include <org/mpisws/p2p/transport/identity/IdentityImpl_LowerIdentityImpl.hpp>
#include <org/mpisws/p2p/transport/identity/IdentityImpl_UpperIdentityImpl.hpp>
#include <org/mpisws/p2p/transport/identity/IdentitySerializer.hpp>
#include <org/mpisws/p2p/transport/identity/NodeChangeStrategy.hpp>
#include <org/mpisws/p2p/transport/identity/SanityChecker.hpp>
#include <org/mpisws/p2p/transport/liveness/OverrideLiveness.hpp>
#include <org/mpisws/p2p/transport/util/OptionsFactory.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/LogManager.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/selector/SelectorManager.hpp>
#include <Array.hpp>

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
org::mpisws::p2p::transport::identity::IdentityImpl::IdentityImpl(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::transport::identity::IdentityImpl::IdentityImpl(::int8_tArray* localIdentifier, IdentitySerializer* serializer, NodeChangeStrategy* nodeChangeStrategy, SanityChecker* sanityChecker, BindStrategy* bindStrategy, ::rice::environment::Environment* environment) 
    : IdentityImpl(*static_cast< ::default_init_tag* >(0))
{
    ctor(localIdentifier,serializer,nodeChangeStrategy,sanityChecker,bindStrategy,environment);
}

void org::mpisws::p2p::transport::identity::IdentityImpl::init()
{
    intendedDestCtr = ::java::lang::Integer::MIN_VALUE;
}

constexpr int8_t org::mpisws::p2p::transport::identity::IdentityImpl::SUCCESS;

constexpr int8_t org::mpisws::p2p::transport::identity::IdentityImpl::FAILURE;

constexpr int8_t org::mpisws::p2p::transport::identity::IdentityImpl::NO_ID;

constexpr int8_t org::mpisws::p2p::transport::identity::IdentityImpl::NORMAL;

constexpr int8_t org::mpisws::p2p::transport::identity::IdentityImpl::INCORRECT_IDENTITY;

java::lang::String*& org::mpisws::p2p::transport::identity::IdentityImpl::NODE_HANDLE_FROM_INDEX()
{
    clinit();
    return NODE_HANDLE_FROM_INDEX_;
}
java::lang::String* org::mpisws::p2p::transport::identity::IdentityImpl::NODE_HANDLE_FROM_INDEX_;

java::lang::String*& org::mpisws::p2p::transport::identity::IdentityImpl::DONT_VERIFY()
{
    clinit();
    return DONT_VERIFY_;
}
java::lang::String* org::mpisws::p2p::transport::identity::IdentityImpl::DONT_VERIFY_;

void org::mpisws::p2p::transport::identity::IdentityImpl::ctor(::int8_tArray* localIdentifier, IdentitySerializer* serializer, NodeChangeStrategy* nodeChangeStrategy, SanityChecker* sanityChecker, BindStrategy* bindStrategy, ::rice::environment::Environment* environment)
{
    super::ctor();
    init();
    this->logger = npc(npc(environment)->getLogManager())->getLogger(IdentityImpl::class_(), nullptr);
    this->bindStrategy = bindStrategy;
    this->sanityChecker = sanityChecker;
    if(sanityChecker == nullptr)
        throw new ::java::lang::IllegalArgumentException(u"SanityChecker is null"_j);

    this->localIdentifier = localIdentifier;
    this->serializer = serializer;
    this->nodeChangeStrategy = nodeChangeStrategy;
    this->environment = environment;
    this->pendingMessages = new ::java::util::HashMap();
    this->deadForever = ::java::util::Collections::synchronizedSet(new ::java::util::HashSet());
    this->bindings = new ::java::util::HashMap();
    npc(serializer)->addSerializerListener(new IdentityImpl_IdentityImpl_1(this));
}

void org::mpisws::p2p::transport::identity::IdentityImpl::addPendingMessage(::java::lang::Object* i, IdentityImpl_IdentityMessageHandle* ret)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
        npc(logger)->log(::java::lang::StringBuilder().append(u"addPendingMessage("_j)->append(static_cast< ::java::lang::Object* >(i))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(ret))
            ->append(u")"_j)->toString());

    {
        synchronized synchronized_0(pendingMessages);
        {
            auto set = java_cast< ::java::util::Set* >(npc(pendingMessages)->get(i));
            if(set == nullptr) {
                set = new ::java::util::HashSet();
                npc(pendingMessages)->put(i, set);
            }
            npc(set)->add(static_cast< ::java::lang::Object* >(ret));
        }
    }
}

void org::mpisws::p2p::transport::identity::IdentityImpl::removePendingMessage(::java::lang::Object* i, IdentityImpl_IdentityMessageHandle* ret)
{
    {
        synchronized synchronized_1(pendingMessages);
        {
            auto set = java_cast< ::java::util::Set* >(npc(pendingMessages)->get(i));
            if(set == nullptr) {
                return;
            }
            npc(set)->remove(static_cast< ::java::lang::Object* >(ret));
            if(npc(set)->isEmpty()) {
                npc(pendingMessages)->remove(i);
            }
        }
    }
}

void org::mpisws::p2p::transport::identity::IdentityImpl::printMemStats(int32_t logLevel)
{
    if(logLevel <= ::rice::environment::logging::Logger::FINE) {
        {
            synchronized synchronized_2(pendingMessages);
            {
                auto queueSum = int32_t(0);
                for (auto _i = npc(npc(pendingMessages)->keySet())->iterator(); _i->hasNext(); ) {
                    ::java::lang::Object* i = java_cast< ::java::lang::Object* >(_i->next());
                    {
                        auto theSet = java_cast< ::java::util::Set* >(npc(pendingMessages)->get(i));
                        auto queueSize = int32_t(0);
                        if(theSet != nullptr) {
                            queueSize = npc(theSet)->size();
                        }
                        queueSum += queueSize;
                        if(logLevel <= ::rice::environment::logging::Logger::FINER) {
                            npc(logger)->log(::java::lang::StringBuilder().append(u"PM{"_j)->append(static_cast< ::java::lang::Object* >(i))
                                ->append(u","_j)
                                ->append(npc(upper)->getLiveness(i, static_cast< ::java::util::Map* >(nullptr)))
                                ->append(u"} queue:"_j)
                                ->append(queueSize)->toString());
                        }
                    }
                }
                npc(logger)->log(::java::lang::StringBuilder().append(u"NumUpperIds:"_j)->append(npc(pendingMessages)->size())
                    ->append(u" numPendingMsgs:"_j)
                    ->append(queueSum)->toString());
            }
        }
    }
}

void org::mpisws::p2p::transport::identity::IdentityImpl::setOverrideLiveness(::org::mpisws::p2p::transport::liveness::OverrideLiveness* ol)
{
    this->overrideLiveness = ol;
}

void org::mpisws::p2p::transport::identity::IdentityImpl::setDeadForever(::java::lang::Object* l, ::java::lang::Object* i, ::java::util::Map* options)
{
    if(npc(deadForever)->contains(static_cast< ::java::lang::Object* >(i)))
        return;

    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
        npc(logger)->logException(::java::lang::StringBuilder().append(u"setDeadForever("_j)->append(static_cast< ::java::lang::Object* >(l))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(i))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(options))
            ->append(u")"_j)->toString(), new ::java::lang::Exception(u"Stack Trace"_j));

    npc(deadForever)->add(static_cast< ::java::lang::Object* >(i));
    auto o2 = ::org::mpisws::p2p::transport::util::OptionsFactory::addOption(options, NODE_HANDLE_FROM_INDEX(), i);
    if(l == nullptr) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
            npc(logger)->log(::java::lang::StringBuilder().append(u"setDeadForever("_j)->append(static_cast< ::java::lang::Object* >(l))
                ->append(u","_j)
                ->append(static_cast< ::java::lang::Object* >(i))
                ->append(u","_j)
                ->append(static_cast< ::java::lang::Object* >(options))
                ->append(u"): l == null"_j)->toString());

        npc(upper)->setLiveness(i, LIVENESS_DEAD_FOREVER, o2);
    } else {
        npc(overrideLiveness)->setLiveness(l, LIVENESS_DEAD_FOREVER, o2);
    }
    auto cancelMe = java_cast< ::java::util::Set* >(npc(pendingMessages)->remove(i));
    if(cancelMe != nullptr) {
        for (auto _i = npc(cancelMe)->iterator(); _i->hasNext(); ) {
            IdentityImpl_IdentityMessageHandle* msg = java_cast< IdentityImpl_IdentityMessageHandle* >(_i->next());
            {
                npc(msg)->deadForever();
            }
        }
    }
    npc(upper)->clearState(i);
}

java::lang::Object* org::mpisws::p2p::transport::identity::IdentityImpl::getIntendedDest(::java::util::Map* options)
{
    if(options == nullptr) {
        throw new ::java::lang::IllegalArgumentException(u"options is null"_j);
    }
    if(!npc(options)->containsKey(NODE_HANDLE_FROM_INDEX()))
        throw new ::java::lang::IllegalArgumentException(::java::lang::StringBuilder().append(u"options doesn't have NODE_HANDLE_FROM_INDEX "_j)->append(static_cast< ::java::lang::Object* >(options))->toString());

    return java_cast< ::java::lang::Object* >(java_cast< ::java::lang::Object* >(npc(options)->get(NODE_HANDLE_FROM_INDEX())));
}

bool org::mpisws::p2p::transport::identity::IdentityImpl::addBinding(::java::lang::Object* u, ::java::lang::Object* l, ::java::util::Map* options)
{
    if(!npc(npc(environment)->getSelectorManager())->isSelectorThread())
        throw new ::java::lang::RuntimeException(u"Must be called on selector thread."_j);

    if(bindStrategy != nullptr && options != nullptr) {
        if(!npc(bindStrategy)->accept(u, l, options))
            return false;

    }
    auto m = java_cast< ::java::lang::Object* >(npc(serializer)->translateDown(u));
    if(npc(deadForever)->contains(static_cast< ::java::lang::Object* >(u)))
        return false;

    auto old = java_cast< ::java::lang::Object* >(npc(bindings)->get(m));
    if(old == nullptr) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
            npc(logger)->log(::java::lang::StringBuilder().append(u"addBinding("_j)->append(static_cast< ::java::lang::Object* >(u))
                ->append(u","_j)
                ->append(static_cast< ::java::lang::Object* >(l))
                ->append(u") old is null"_j)->toString());

        npc(bindings)->put(m, u);
        if(l != nullptr) {
            npc(overrideLiveness)->setLiveness(l, LIVENESS_ALIVE, ::org::mpisws::p2p::transport::util::OptionsFactory::addOption(options, NODE_HANDLE_FROM_INDEX(), u));
        } else {
            npc(upper)->setLiveness(u, LIVENESS_ALIVE, ::org::mpisws::p2p::transport::util::OptionsFactory::addOption(options, NODE_HANDLE_FROM_INDEX(), u));
        }
        return true;
    } else {
        if(npc(old)->equals(u)) {
            if(npc(logger)->level <= ::rice::environment::logging::Logger::FINEST)
                npc(logger)->log(::java::lang::StringBuilder().append(u"addBinding("_j)->append(static_cast< ::java::lang::Object* >(u))
                    ->append(u","_j)
                    ->append(static_cast< ::java::lang::Object* >(l))
                    ->append(u") old is equal"_j)->toString());

            if(l != nullptr) {
                npc(overrideLiveness)->setLiveness(l, LIVENESS_ALIVE, ::org::mpisws::p2p::transport::util::OptionsFactory::addOption(options, NODE_HANDLE_FROM_INDEX(), u));
            } else {
                npc(upper)->setLiveness(u, LIVENESS_ALIVE, ::org::mpisws::p2p::transport::util::OptionsFactory::addOption(options, NODE_HANDLE_FROM_INDEX(), u));
            }
            return true;
        }
        if(destinationChanged(old, u, l, options)) {
            npc(bindings)->put(m, u);
            if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
                npc(logger)->log(::java::lang::StringBuilder().append(u"addBinding("_j)->append(static_cast< ::java::lang::Object* >(u))
                    ->append(u","_j)
                    ->append(static_cast< ::java::lang::Object* >(l))
                    ->append(u") old "_j)
                    ->append(static_cast< ::java::lang::Object* >(old))
                    ->append(u" is dead"_j)->toString());

            if(l == nullptr) {
                if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
                    npc(logger)->log(::java::lang::StringBuilder().append(u"addBinding("_j)->append(static_cast< ::java::lang::Object* >(u))
                        ->append(u","_j)
                        ->append(static_cast< ::java::lang::Object* >(l))
                        ->append(u"): l == null"_j)->toString());

                npc(upper)->setLiveness(u, LIVENESS_ALIVE, ::org::mpisws::p2p::transport::util::OptionsFactory::addOption(options, NODE_HANDLE_FROM_INDEX(), u));
            } else {
                npc(overrideLiveness)->setLiveness(l, LIVENESS_ALIVE, ::org::mpisws::p2p::transport::util::OptionsFactory::addOption(options, NODE_HANDLE_FROM_INDEX(), u));
            }
            return true;
        } else {
            if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
                npc(logger)->log(::java::lang::StringBuilder().append(u"The nodeChangeStrategy found identifier "_j)->append(static_cast< ::java::lang::Object* >(u))
                    ->append(u" to be stale.  Should be using "_j)
                    ->append(static_cast< ::java::lang::Object* >(old))->toString());

            return false;
        }
    }
}

bool org::mpisws::p2p::transport::identity::IdentityImpl::destinationChanged(::java::lang::Object* oldDest, ::java::lang::Object* newDest, ::java::lang::Object* i, ::java::util::Map* options)
{
    if(npc(oldDest)->equals(newDest)) {
        return true;
    } else {
        if(npc(deadForever)->contains(static_cast< ::java::lang::Object* >(oldDest))) {
            return true;
        }
        if(npc(deadForever)->contains(static_cast< ::java::lang::Object* >(newDest))) {
            return false;
        }
        if(npc(nodeChangeStrategy)->canChange(oldDest, newDest)) {
            if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
                npc(logger)->log(::java::lang::StringBuilder().append(u"destinationChanged("_j)->append(static_cast< ::java::lang::Object* >(oldDest))
                    ->append(u"->"_j)
                    ->append(static_cast< ::java::lang::Object* >(newDest))
                    ->append(u","_j)
                    ->append(static_cast< ::java::lang::Object* >(i))
                    ->append(u","_j)
                    ->append(static_cast< ::java::lang::Object* >(options))
                    ->append(u")"_j)->toString());

            setDeadForever(i, oldDest, options);
            return true;
        } else {
            if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
                npc(logger)->log(::java::lang::StringBuilder().append(u"destinationDidntChange("_j)->append(static_cast< ::java::lang::Object* >(newDest))
                    ->append(u"->"_j)
                    ->append(static_cast< ::java::lang::Object* >(oldDest))
                    ->append(u","_j)
                    ->append(static_cast< ::java::lang::Object* >(i))
                    ->append(u","_j)
                    ->append(static_cast< ::java::lang::Object* >(options))
                    ->append(u")"_j)->toString());

            setDeadForever(i, newDest, options);
            return false;
        }
    }
}

void org::mpisws::p2p::transport::identity::IdentityImpl::initLowerLayer(::org::mpisws::p2p::transport::TransportLayer* tl, ::org::mpisws::p2p::transport::ErrorHandler* handler)
{
    lower = new IdentityImpl_LowerIdentityImpl(this, tl, handler);
}

org::mpisws::p2p::transport::identity::LowerIdentity* org::mpisws::p2p::transport::identity::IdentityImpl::getLowerIdentity()
{
    return lower;
}

org::mpisws::p2p::transport::identity::UpperIdentity* org::mpisws::p2p::transport::identity::IdentityImpl::getUpperIdentity()
{
    return upper;
}

void org::mpisws::p2p::transport::identity::IdentityImpl::initUpperLayer(::java::lang::Object* localIdentifier, ::org::mpisws::p2p::transport::TransportLayer* tl, ::org::mpisws::p2p::transport::liveness::LivenessProvider* live, ::org::mpisws::p2p::transport::proximity::ProximityProvider* prox, ::org::mpisws::p2p::transport::liveness::OverrideLiveness* overrideLiveness)
{
    if(upper != nullptr)
        throw new ::java::lang::IllegalStateException(::java::lang::StringBuilder().append(u"upper already initialized:"_j)->append(static_cast< ::java::lang::Object* >(upper))->toString());

    upper = new IdentityImpl_UpperIdentityImpl(this, localIdentifier, tl, live, prox);
    setOverrideLiveness(overrideLiveness);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::identity::IdentityImpl::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.identity.IdentityImpl", 46);
    return c;
}

void org::mpisws::p2p::transport::identity::IdentityImpl::clinit()
{
struct string_init_ {
    string_init_() {
    NODE_HANDLE_FROM_INDEX_ = u"identity.node_handle_to_index"_j;
    DONT_VERIFY_ = u"identity.dont_verify_dest"_j;
    }
};

    static string_init_ string_init_instance;

    super::clinit();
}

java::lang::Class* org::mpisws::p2p::transport::identity::IdentityImpl::getClass0()
{
    return class_();
}

