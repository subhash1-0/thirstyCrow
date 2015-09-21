// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/identity/IdentityImpl.java
#include <org/mpisws/p2p/transport/identity/IdentityImpl_UpperIdentityImpl.hpp>

#include <java/lang/Class.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/Integer.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/RuntimeException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/util/ArrayList.hpp>
#include <java/util/Collection.hpp>
#include <java/util/HashMap.hpp>
#include <java/util/Iterator.hpp>
#include <java/util/List.hpp>
#include <java/util/Map.hpp>
#include <java/util/Set.hpp>
#include <org/mpisws/p2p/transport/ErrorHandler.hpp>
#include <org/mpisws/p2p/transport/MessageCallback.hpp>
#include <org/mpisws/p2p/transport/MessageRequestHandle.hpp>
#include <org/mpisws/p2p/transport/P2PSocket.hpp>
#include <org/mpisws/p2p/transport/SocketCallback.hpp>
#include <org/mpisws/p2p/transport/SocketRequestHandle.hpp>
#include <org/mpisws/p2p/transport/TransportLayer.hpp>
#include <org/mpisws/p2p/transport/TransportLayerCallback.hpp>
#include <org/mpisws/p2p/transport/exception/NodeIsFaultyException.hpp>
#include <org/mpisws/p2p/transport/identity/IdentityImpl_UpperIdentityImpl_openSocket_1.hpp>
#include <org/mpisws/p2p/transport/identity/IdentityImpl_IdentityMessageHandle.hpp>
#include <org/mpisws/p2p/transport/identity/IdentityImpl.hpp>
#include <org/mpisws/p2p/transport/identity/IdentitySerializer.hpp>
#include <org/mpisws/p2p/transport/identity/MemoryExpiredException.hpp>
#include <org/mpisws/p2p/transport/identity/SanityChecker.hpp>
#include <org/mpisws/p2p/transport/liveness/LivenessListener.hpp>
#include <org/mpisws/p2p/transport/liveness/LivenessProvider.hpp>
#include <org/mpisws/p2p/transport/proximity/ProximityListener.hpp>
#include <org/mpisws/p2p/transport/proximity/ProximityProvider.hpp>
#include <org/mpisws/p2p/transport/util/MessageRequestHandleImpl.hpp>
#include <org/mpisws/p2p/transport/util/OptionsFactory.hpp>
#include <org/mpisws/p2p/transport/util/SocketRequestHandleImpl.hpp>
#include <org/mpisws/p2p/transport/util/SocketWrapperSocket.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/LogManager.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/selector/SelectorManager.hpp>

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
org::mpisws::p2p::transport::identity::IdentityImpl_UpperIdentityImpl::IdentityImpl_UpperIdentityImpl(IdentityImpl *IdentityImpl_this, const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
    , IdentityImpl_this(IdentityImpl_this)
{
    clinit();
}

org::mpisws::p2p::transport::identity::IdentityImpl_UpperIdentityImpl::IdentityImpl_UpperIdentityImpl(IdentityImpl *IdentityImpl_this, ::java::lang::Object* local, ::org::mpisws::p2p::transport::TransportLayer* tl, ::org::mpisws::p2p::transport::liveness::LivenessProvider* live, ::org::mpisws::p2p::transport::proximity::ProximityProvider* prox) 
    : IdentityImpl_UpperIdentityImpl(IdentityImpl_this, *static_cast< ::default_init_tag* >(0))
{
    ctor(local,tl,live,prox);
}

void org::mpisws::p2p::transport::identity::IdentityImpl_UpperIdentityImpl::init()
{
    livenessListeners = new ::java::util::ArrayList();
    liveness = new ::java::util::HashMap();
    proxListeners = new ::java::util::ArrayList();
}

void org::mpisws::p2p::transport::identity::IdentityImpl_UpperIdentityImpl::ctor(::java::lang::Object* local, ::org::mpisws::p2p::transport::TransportLayer* tl, ::org::mpisws::p2p::transport::liveness::LivenessProvider* live, ::org::mpisws::p2p::transport::proximity::ProximityProvider* prox)
{
    super::ctor();
    init();
    this->localIdentifier = local;
    this->tl = tl;
    this->livenessProvider = live;
    this->prox = prox;
    logger = npc(npc(IdentityImpl_this->environment)->getLogManager())->getLogger(IdentityImpl::class_(), u"upper"_j);
    npc(tl)->setCallback(this);
    npc(livenessProvider)->addLivenessListener(this);
    npc(prox)->addProximityListener(this);
}

void org::mpisws::p2p::transport::identity::IdentityImpl_UpperIdentityImpl::clearState(::java::lang::Object* i)
{
    npc(livenessProvider)->clearState(java_cast< ::java::lang::Object* >(npc(IdentityImpl_this->serializer)->translateDown(i)));
}

org::mpisws::p2p::transport::SocketRequestHandle* org::mpisws::p2p::transport::identity::IdentityImpl_UpperIdentityImpl::openSocket(::java::lang::Object* i, ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe, ::java::util::Map* options)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(::java::lang::StringBuilder().append(u"openSocket("_j)->append(static_cast< ::java::lang::Object* >(i))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(deliverSocketToMe))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(options))
            ->append(u")"_j)->toString());

    auto const handle = new ::org::mpisws::p2p::transport::util::SocketRequestHandleImpl(i, options, logger);
    auto middle = java_cast< ::java::lang::Object* >(npc(IdentityImpl_this->serializer)->translateDown(i));
    if(IdentityImpl_this->addBinding(i, nullptr, options)) {
    } else {
        npc(deliverSocketToMe)->receiveException(handle, new ::org::mpisws::p2p::transport::exception::NodeIsFaultyException(i));
        return handle;
    }
    auto newOptions = ::org::mpisws::p2p::transport::util::OptionsFactory::copyOptions(options);
    npc(newOptions)->put(IdentityImpl::NODE_HANDLE_FROM_INDEX(), i);
    npc(handle)->setSubCancellable(npc(tl)->openSocket(middle, new IdentityImpl_UpperIdentityImpl_openSocket_1(this, deliverSocketToMe, handle, i, options), newOptions));
    return handle;
}

org::mpisws::p2p::transport::MessageRequestHandle* org::mpisws::p2p::transport::identity::IdentityImpl_UpperIdentityImpl::sendMessage(::java::lang::Object* i, ::java::lang::Object* m, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options)
{
    if(!npc(npc(IdentityImpl_this->environment)->getSelectorManager())->isSelectorThread())
        throw new ::java::lang::RuntimeException(u"Must be called on selector thread."_j);

    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(::java::lang::StringBuilder().append(u"sendMessage("_j)->append(static_cast< ::java::lang::Object* >(i))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(m))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(options))
            ->append(u")"_j)->toString());

    if(npc(IdentityImpl_this->deadForever)->contains(static_cast< ::java::lang::Object* >(i))) {
        ::org::mpisws::p2p::transport::MessageRequestHandle* mrh = new ::org::mpisws::p2p::transport::util::MessageRequestHandleImpl(i, m, options);
        npc(deliverAckToMe)->sendFailed(mrh, new ::org::mpisws::p2p::transport::exception::NodeIsFaultyException(i, m));
        return mrh;
    }
    IdentityImpl_IdentityMessageHandle* ret;
    auto middle = java_cast< ::java::lang::Object* >(npc(IdentityImpl_this->serializer)->translateDown(i));
    if(IdentityImpl_this->addBinding(i, nullptr, options)) {
    } else {
        ::org::mpisws::p2p::transport::MessageRequestHandle* mrh = new ::org::mpisws::p2p::transport::util::MessageRequestHandleImpl(i, m, options);
        npc(deliverAckToMe)->sendFailed(mrh, new ::org::mpisws::p2p::transport::exception::NodeIsFaultyException(i, m));
        return mrh;
    }
    options = ::org::mpisws::p2p::transport::util::OptionsFactory::copyOptions(options);
    npc(options)->put(IdentityImpl::NODE_HANDLE_FROM_INDEX(), i);
    ret = new IdentityImpl_IdentityMessageHandle(IdentityImpl_this, i, m, options, deliverAckToMe);
    IdentityImpl_this->addPendingMessage(i, ret);
    npc(ret)->setSubCancellable(npc(tl)->sendMessage(middle, m, ret, options));
    return ret;
}

void org::mpisws::p2p::transport::identity::IdentityImpl_UpperIdentityImpl::incomingSocket(::org::mpisws::p2p::transport::P2PSocket* s) /* throws(IOException) */
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(::java::lang::StringBuilder().append(u"incomingSocket("_j)->append(static_cast< ::java::lang::Object* >(s))
            ->append(u")"_j)->toString());

    auto const from = java_cast< ::java::lang::Object* >(IdentityImpl_this->getIntendedDest(npc(s)->getOptions()));
    if(from == nullptr) {
        npc(errorHandler)->receivedException(nullptr, new MemoryExpiredException(::java::lang::StringBuilder().append(u"No record of the upper identifier for "_j)->append(static_cast< ::java::lang::Object* >(java_cast< ::java::lang::Object* >(npc(s)->getIdentifier())))
            ->append(u" index="_j)
            ->append(static_cast< ::java::lang::Object* >(java_cast< ::java::lang::Object* >(npc(npc(s)->getOptions())->get(IdentityImpl::NODE_HANDLE_FROM_INDEX()))))->toString()));
        npc(s)->close();
        return;
    }
    if(npc(IdentityImpl_this->sanityChecker)->isSane(from, java_cast< ::java::lang::Object* >(npc(s)->getIdentifier()))) {
        npc(callback)->incomingSocket(new ::org::mpisws::p2p::transport::util::SocketWrapperSocket(from, s, logger, errorHandler, npc(s)->getOptions()));
    } else {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(logger)->logException(::java::lang::StringBuilder().append(u"incomingSocket() Sanity checker did not match "_j)->append(static_cast< ::java::lang::Object* >(from))
                ->append(u" to "_j)
                ->append(static_cast< ::java::lang::Object* >(java_cast< ::java::lang::Object* >(npc(s)->getIdentifier())))
                ->append(u" options:"_j)
                ->append(static_cast< ::java::lang::Object* >(npc(s)->getOptions()))->toString(), new ::java::lang::Exception(u"Stack Trace"_j));

        npc(s)->close();
    }
}

void org::mpisws::p2p::transport::identity::IdentityImpl_UpperIdentityImpl::messageReceived(::java::lang::Object* i, ::java::lang::Object* m, ::java::util::Map* options) /* throws(IOException) */
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(::java::lang::StringBuilder().append(u"messageReceived("_j)->append(static_cast< ::java::lang::Object* >(i))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(m))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(options))
            ->append(u")"_j)->toString());

    auto const from = java_cast< ::java::lang::Object* >(IdentityImpl_this->getIntendedDest(options));
    if(from == nullptr) {
        npc(errorHandler)->receivedException(nullptr, new MemoryExpiredException(::java::lang::StringBuilder().append(u"No record of the upper identifier for "_j)->append(static_cast< ::java::lang::Object* >(i))
            ->append(u" index="_j)
            ->append(static_cast< ::java::lang::Object* >(java_cast< ::java::lang::Object* >(npc(options)->get(IdentityImpl::NODE_HANDLE_FROM_INDEX()))))
            ->append(u" dropping message"_j)
            ->append(static_cast< ::java::lang::Object* >(m))->toString()));
        return;
    }
    if(npc(IdentityImpl_this->sanityChecker)->isSane(from, i)) {
        npc(callback)->messageReceived(from, m, options);
    } else {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(logger)->logException(::java::lang::StringBuilder().append(u"messageReceived() Sanity checker did not match "_j)->append(static_cast< ::java::lang::Object* >(from))
                ->append(u" to "_j)
                ->append(static_cast< ::java::lang::Object* >(i))
                ->append(u" options:"_j)
                ->append(static_cast< ::java::lang::Object* >(options))->toString(), new ::java::lang::Exception(u"Stack Trace"_j));

    }
}

bool org::mpisws::p2p::transport::identity::IdentityImpl_UpperIdentityImpl::checkLiveness(::java::lang::Object* i, ::java::util::Map* options)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(::java::lang::StringBuilder().append(u"checkLiveness("_j)->append(static_cast< ::java::lang::Object* >(i))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(options))
            ->append(u")"_j)->toString());

    if(npc(IdentityImpl_this->deadForever)->contains(static_cast< ::java::lang::Object* >(i)))
        return false;

    options = ::org::mpisws::p2p::transport::util::OptionsFactory::copyOptions(options);
    npc(options)->put(IdentityImpl::NODE_HANDLE_FROM_INDEX(), i);
    return npc(livenessProvider)->checkLiveness(java_cast< ::java::lang::Object* >(npc(IdentityImpl_this->serializer)->translateDown(i)), options);
}

void org::mpisws::p2p::transport::identity::IdentityImpl_UpperIdentityImpl::addLivenessListener(::org::mpisws::p2p::transport::liveness::LivenessListener* name)
{
    {
        synchronized synchronized_0(livenessListeners);
        {
            npc(livenessListeners)->add(static_cast< ::java::lang::Object* >(name));
        }
    }
}

bool org::mpisws::p2p::transport::identity::IdentityImpl_UpperIdentityImpl::removeLivenessListener(::org::mpisws::p2p::transport::liveness::LivenessListener* name)
{
    {
        synchronized synchronized_1(livenessListeners);
        {
            return npc(livenessListeners)->remove(static_cast< ::java::lang::Object* >(name));
        }
    }
}

int32_t org::mpisws::p2p::transport::identity::IdentityImpl_UpperIdentityImpl::getLiveness(::java::lang::Object* i, ::java::util::Map* options)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
        npc(logger)->log(::java::lang::StringBuilder().append(u"getLiveness("_j)->append(static_cast< ::java::lang::Object* >(i))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(options))
            ->append(u")"_j)->toString());

    if(npc(IdentityImpl_this->deadForever)->contains(static_cast< ::java::lang::Object* >(i)))
        return LIVENESS_DEAD_FOREVER;

    options = ::org::mpisws::p2p::transport::util::OptionsFactory::copyOptions(options);
    npc(options)->put(IdentityImpl::NODE_HANDLE_FROM_INDEX(), i);
    return npc(livenessProvider)->getLiveness(java_cast< ::java::lang::Object* >(npc(IdentityImpl_this->serializer)->translateDown(i)), options);
}

void org::mpisws::p2p::transport::identity::IdentityImpl_UpperIdentityImpl::livenessChanged(::java::lang::Object* i, int32_t val, ::java::util::Map* options)
{
    if(npc(IdentityImpl_this->deadForever)->contains(static_cast< ::java::lang::Object* >(i))) {
        if(val < LIVENESS_DEAD) {
            if(npc(logger)->level <= ::rice::environment::logging::Logger::SEVERE)
                npc(logger)->log(::java::lang::StringBuilder().append(u"Node "_j)->append(static_cast< ::java::lang::Object* >(i))
                    ->append(u" came back from the dead!  It's a miracle! "_j)
                    ->append(val)
                    ->append(u" Ignoring."_j)->toString());

        }
        return;
    }
    auto upper = java_cast< ::java::lang::Object* >(IdentityImpl_this->getIntendedDest(options));
    if(upper == nullptr) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(logger)->logException(::java::lang::StringBuilder().append(u"Memory for index "_j)->append(static_cast< ::java::lang::Object* >(java_cast< ::java::lang::Object* >(npc(options)->get(IdentityImpl::NODE_HANDLE_FROM_INDEX()))))
                ->append(u" collected suppressing livenessChanged()"_j)->toString(), new ::java::lang::Exception(u"Stack Trace"_j));

        return;
    }
    setLiveness(upper, val, options);
}

void org::mpisws::p2p::transport::identity::IdentityImpl_UpperIdentityImpl::setLiveness(::java::lang::Object* i, int32_t val, ::java::util::Map* options)
{
    auto oldLiveness = -int32_t(55);
    if(npc(liveness)->containsKey(i)) {
        oldLiveness = (npc(java_cast< ::java::lang::Integer* >(npc(liveness)->get(i))))->intValue();
    }
    if(val != oldLiveness) {
        npc(liveness)->put(i, ::java::lang::Integer::valueOf(val));
        notifyLivenessListeners(i, val, options);
    }
}

void org::mpisws::p2p::transport::identity::IdentityImpl_UpperIdentityImpl::notifyLivenessListeners(::java::lang::Object* i, int32_t liveness, ::java::util::Map* options)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
        npc(logger)->log(::java::lang::StringBuilder().append(u"notifyLivenessListeners("_j)->append(static_cast< ::java::lang::Object* >(i))
            ->append(u","_j)
            ->append(liveness)
            ->append(u")"_j)->toString());

    ::java::util::List* temp;
    {
        synchronized synchronized_2(livenessListeners);
        {
            temp = new ::java::util::ArrayList(static_cast< ::java::util::Collection* >(livenessListeners));
        }
    }
    for (auto _i = npc(temp)->iterator(); _i->hasNext(); ) {
        ::org::mpisws::p2p::transport::liveness::LivenessListener* listener = java_cast< ::org::mpisws::p2p::transport::liveness::LivenessListener* >(_i->next());
        {
            npc(listener)->livenessChanged(i, liveness, options);
        }
    }
}

void org::mpisws::p2p::transport::identity::IdentityImpl_UpperIdentityImpl::addProximityListener(::org::mpisws::p2p::transport::proximity::ProximityListener* name)
{
    {
        synchronized synchronized_3(proxListeners);
        {
            npc(proxListeners)->add(name);
        }
    }
}

bool org::mpisws::p2p::transport::identity::IdentityImpl_UpperIdentityImpl::removeProximityListener(::org::mpisws::p2p::transport::proximity::ProximityListener* name)
{
    {
        synchronized synchronized_4(proxListeners);
        {
            return npc(proxListeners)->remove(name);
        }
    }
}

int32_t org::mpisws::p2p::transport::identity::IdentityImpl_UpperIdentityImpl::proximity(::java::lang::Object* i, ::java::util::Map* options)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINEST)
        npc(logger)->log(::java::lang::StringBuilder().append(u"proximity("_j)->append(static_cast< ::java::lang::Object* >(i))
            ->append(u")"_j)->toString());

    if(npc(IdentityImpl_this->deadForever)->contains(static_cast< ::java::lang::Object* >(i)))
        return ::java::lang::Integer::MAX_VALUE;

    return npc(prox)->proximity(java_cast< ::java::lang::Object* >(npc(IdentityImpl_this->serializer)->translateDown(i)), ::org::mpisws::p2p::transport::util::OptionsFactory::addOption(options, IdentityImpl::NODE_HANDLE_FROM_INDEX(), i));
}

void org::mpisws::p2p::transport::identity::IdentityImpl_UpperIdentityImpl::proximityChanged(::java::lang::Object* i, int32_t newProx, ::java::util::Map* options)
{
    auto upper = java_cast< ::java::lang::Object* >(IdentityImpl_this->getIntendedDest(options));
    if(upper == nullptr) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(logger)->logException(::java::lang::StringBuilder().append(u"Memory for "_j)->append(static_cast< ::java::lang::Object* >(java_cast< ::java::lang::Object* >(npc(options)->get(IdentityImpl::NODE_HANDLE_FROM_INDEX()))))
                ->append(u" collected suppressing proximityChanged()"_j)->toString(), new ::java::lang::Exception(u"Stack Trace"_j));

        return;
    }
    notifyProximityListeners(upper, newProx, options);
}

void org::mpisws::p2p::transport::identity::IdentityImpl_UpperIdentityImpl::notifyProximityListeners(::java::lang::Object* i, int32_t newProx, ::java::util::Map* options)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
        npc(logger)->log(::java::lang::StringBuilder().append(u"notifyProximityListeners("_j)->append(static_cast< ::java::lang::Object* >(i))
            ->append(u","_j)
            ->append(newProx)
            ->append(u")"_j)->toString());

    ::java::util::List* temp;
    {
        synchronized synchronized_5(proxListeners);
        {
            temp = new ::java::util::ArrayList(static_cast< ::java::util::Collection* >(proxListeners));
        }
    }
    for (auto _i = npc(temp)->iterator(); _i->hasNext(); ) {
        ::org::mpisws::p2p::transport::proximity::ProximityListener* listener = java_cast< ::org::mpisws::p2p::transport::proximity::ProximityListener* >(_i->next());
        {
            npc(listener)->proximityChanged(i, newProx, options);
        }
    }
}

void org::mpisws::p2p::transport::identity::IdentityImpl_UpperIdentityImpl::acceptMessages(bool b)
{
    npc(tl)->acceptMessages(b);
}

void org::mpisws::p2p::transport::identity::IdentityImpl_UpperIdentityImpl::acceptSockets(bool b)
{
    npc(tl)->acceptSockets(b);
}

java::lang::Object* org::mpisws::p2p::transport::identity::IdentityImpl_UpperIdentityImpl::getLocalIdentifier()
{
    return java_cast< ::java::lang::Object* >(localIdentifier);
}

void org::mpisws::p2p::transport::identity::IdentityImpl_UpperIdentityImpl::setCallback(::org::mpisws::p2p::transport::TransportLayerCallback* callback)
{
    this->callback = callback;
}

void org::mpisws::p2p::transport::identity::IdentityImpl_UpperIdentityImpl::setErrorHandler(::org::mpisws::p2p::transport::ErrorHandler* handler)
{
    this->errorHandler = handler;
}

void org::mpisws::p2p::transport::identity::IdentityImpl_UpperIdentityImpl::destroy()
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
        npc(logger)->log(u"destroy()"_j);

    npc(tl)->destroy();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::identity::IdentityImpl_UpperIdentityImpl::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.identity.IdentityImpl.UpperIdentityImpl", 64);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::identity::IdentityImpl_UpperIdentityImpl::getClass0()
{
    return class_();
}

