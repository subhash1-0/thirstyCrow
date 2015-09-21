// Generated from /pastry-2.1/src/rice/pastry/standard/RapidRerouter.java
#include <rice/pastry/standard/RapidRerouter.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/util/Collection.hpp>
#include <java/util/HashMap.hpp>
#include <java/util/HashSet.hpp>
#include <java/util/Iterator.hpp>
#include <java/util/Map.hpp>
#include <org/mpisws/p2p/transport/liveness/LivenessListener.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/pastry/NodeHandle.hpp>
#include <rice/pastry/PastryNode.hpp>
#include <rice/pastry/routing/RouteMessage.hpp>
#include <rice/pastry/routing/SendOptions.hpp>
#include <rice/pastry/standard/RapidRerouter_rerouteMe_1.hpp>
#include <rice/pastry/standard/RapidRerouter_RouterNotification.hpp>
#include <rice/pastry/standard/TooManyRouteAttempts.hpp>
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
rice::pastry::standard::RapidRerouter::RapidRerouter(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::standard::RapidRerouter::RapidRerouter(::rice::pastry::PastryNode* thePastryNode, ::rice::pastry::messaging::MessageDispatch* dispatch, ::rice::pastry::routing::RouterStrategy* strategy) 
    : RapidRerouter(*static_cast< ::default_init_tag* >(0))
{
    ctor(thePastryNode,dispatch,strategy);
}

constexpr int32_t rice::pastry::standard::RapidRerouter::MAX_RETRIES;

void rice::pastry::standard::RapidRerouter::ctor(::rice::pastry::PastryNode* thePastryNode, ::rice::pastry::messaging::MessageDispatch* dispatch, ::rice::pastry::routing::RouterStrategy* strategy)
{
    super::ctor(thePastryNode, dispatch, strategy);
    pending = new ::java::util::HashMap();
    npc(thePastryNode)->addLivenessListener(static_cast< ::org::mpisws::p2p::transport::liveness::LivenessListener* >(this));
}

void rice::pastry::standard::RapidRerouter::sendTheMessage(::rice::pastry::routing::RouteMessage* rm, ::rice::pastry::NodeHandle* handle)
{
    if(npc(npc(rm)->getOptions())->multipleHopsAllowed() && npc(npc(rm)->getOptions())->rerouteIfSuspected()) {
        if(npc(handle)->getLiveness() >= LIVENESS_SUSPECTED) {
            super::sendTheMessage(rm, handle);
            return;
        }
        auto notifyMe = new RapidRerouter_RouterNotification(this, rm, handle);
        addToPending(notifyMe, handle);
        npc(rm)->setTLCancellable(notifyMe);
        npc(notifyMe)->setCancellable(npc(thePastryNode)->send(handle, rm, notifyMe, npc(rm)->getTLOptions()));
    } else {
        super::sendTheMessage(rm, handle);
    }
}

void rice::pastry::standard::RapidRerouter::rerouteMe(::rice::pastry::routing::RouteMessage* rm, ::rice::pastry::NodeHandle* oldDest, ::java::lang::Exception* ioe)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(::java::lang::StringBuilder().append(u"rerouteMe("_j)->append(static_cast< ::java::lang::Object* >(rm))
            ->append(u" oldDest:"_j)
            ->append(static_cast< ::java::lang::Object* >(oldDest))
            ->append(u")"_j)->toString());

    npc(rm)->numRetries++;
    if(npc(rm)->numRetries > MAX_RETRIES) {
        auto dontPrint = false;
        if(ioe == nullptr) {
            dontPrint = npc(rm)->sendFailed(new TooManyRouteAttempts(rm, MAX_RETRIES));
        } else {
            dontPrint = npc(rm)->sendFailed(ioe);
        }
        if(dontPrint) {
            if(npc(logger)->level <= ::rice::environment::logging::Logger::CONFIG)
                npc(logger)->log(::java::lang::StringBuilder().append(u"rerouteMe() dropping "_j)->append(static_cast< ::java::lang::Object* >(rm))
                    ->append(u" after "_j)
                    ->append(npc(rm)->numRetries)
                    ->append(u" attempts to (re)route."_j)->toString());

        } else {
            if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                npc(logger)->log(::java::lang::StringBuilder().append(u"rerouteMe() dropping "_j)->append(static_cast< ::java::lang::Object* >(rm))
                    ->append(u" after "_j)
                    ->append(npc(rm)->numRetries)
                    ->append(u" attempts to (re)route."_j)->toString());

        }
        return;
    }
    npc(npc(npc(thePastryNode)->getEnvironment())->getSelectorManager())->invoke(new RapidRerouter_rerouteMe_1(this, rm));
}

void rice::pastry::standard::RapidRerouter::addToPending(RapidRerouter_RouterNotification* notifyMe, ::rice::pastry::NodeHandle* handle)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(::java::lang::StringBuilder().append(u"addToPending("_j)->append(static_cast< ::java::lang::Object* >(notifyMe))
            ->append(u" to:"_j)
            ->append(static_cast< ::java::lang::Object* >(handle))
            ->append(u")"_j)->toString());

    {
        synchronized synchronized_0(pending);
        {
            auto c = java_cast< ::java::util::Collection* >(npc(pending)->get(handle));
            if(c == nullptr) {
                c = new ::java::util::HashSet();
                npc(pending)->put(handle, c);
            }
            npc(c)->add(notifyMe);
        }
    }
}

bool rice::pastry::standard::RapidRerouter::removeFromPending(RapidRerouter_RouterNotification* notifyMe, ::rice::pastry::NodeHandle* handle)
{
    {
        synchronized synchronized_1(pending);
        {
            auto c = java_cast< ::java::util::Collection* >(npc(pending)->get(handle));
            if(c == nullptr) {
                if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
                    npc(logger)->log(::java::lang::StringBuilder().append(u"removeFromPending("_j)->append(static_cast< ::java::lang::Object* >(notifyMe))
                        ->append(u","_j)
                        ->append(static_cast< ::java::lang::Object* >(handle))
                        ->append(u") had no pending messages for handle."_j)->toString());

                return false;
            }
            auto ret = npc(c)->remove(notifyMe);
            if(npc(c)->isEmpty()) {
                npc(pending)->remove(handle);
            }
            if(!ret) {
                if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
                    npc(logger)->log(::java::lang::StringBuilder().append(u"removeFromPending("_j)->append(static_cast< ::java::lang::Object* >(notifyMe))
                        ->append(u","_j)
                        ->append(static_cast< ::java::lang::Object* >(handle))
                        ->append(u") msg was not there."_j)->toString());

            }
            return ret;
        }
    }
}

void rice::pastry::standard::RapidRerouter::livenessChanged(::rice::pastry::NodeHandle* i, int32_t val, ::java::util::Map* options)
{
    if(val >= LIVENESS_SUSPECTED) {
        ::java::util::Collection* rerouteMe;
        {
            synchronized synchronized_2(pending);
            {
                rerouteMe = java_cast< ::java::util::Collection* >(npc(pending)->remove(i));
            }
        }
        if(rerouteMe != nullptr) {
            if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
                npc(logger)->log(::java::lang::StringBuilder().append(u"removing all messages to:"_j)->append(static_cast< ::java::lang::Object* >(i))->toString());

            for (auto _i = npc(rerouteMe)->iterator(); _i->hasNext(); ) {
                RapidRerouter_RouterNotification* rn = java_cast< RapidRerouter_RouterNotification* >(_i->next());
                {
                    npc(rn)->cancel();
                    this->rerouteMe(npc(rn)->rm, npc(rn)->dest, nullptr);
                }
            }
        }
    }
}

void rice::pastry::standard::RapidRerouter::livenessChanged(::java::lang::Object* i, int32_t val, ::java::util::Map* options)
{ 
    livenessChanged(dynamic_cast< ::rice::pastry::NodeHandle* >(i), val, options);
}

void rice::pastry::standard::RapidRerouter::destroy()
{
    super::destroy();
    npc(thePastryNode)->removeLivenessListener(static_cast< ::org::mpisws::p2p::transport::liveness::LivenessListener* >(this));
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::standard::RapidRerouter::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.standard.RapidRerouter", 34);
    return c;
}

java::lang::Class* rice::pastry::standard::RapidRerouter::getClass0()
{
    return class_();
}

