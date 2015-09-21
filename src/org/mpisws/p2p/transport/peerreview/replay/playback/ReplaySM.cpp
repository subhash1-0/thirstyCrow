// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/replay/playback/ReplaySM.java
#include <org/mpisws/p2p/transport/peerreview/replay/playback/ReplaySM.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/IllegalArgumentException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/RuntimeException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/util/Queue.hpp>
#include <org/mpisws/p2p/transport/peerreview/replay/Verifier.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/environment/time/TimeSource.hpp>
#include <rice/environment/time/simulated/DirectTimeSource.hpp>
#include <rice/selector/TimerTask.hpp>

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
org::mpisws::p2p::transport::peerreview::replay::playback::ReplaySM::ReplaySM(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::transport::peerreview::replay::playback::ReplaySM::ReplaySM(::java::lang::String* instance, ::rice::environment::time::simulated::DirectTimeSource* timeSource, ::rice::environment::logging::LogManager* log) 
    : ReplaySM(*static_cast< ::default_init_tag* >(0))
{
    ctor(instance,timeSource,log);
}

void org::mpisws::p2p::transport::peerreview::replay::playback::ReplaySM::ctor(::java::lang::String* instance, ::rice::environment::time::simulated::DirectTimeSource* timeSource, ::rice::environment::logging::LogManager* log)
{
    super::ctor(instance, timeSource, log, nullptr);
    this->simTime = timeSource;
    setSelect(false);
}

void org::mpisws::p2p::transport::peerreview::replay::playback::ReplaySM::setVerifier(::org::mpisws::p2p::transport::peerreview::replay::Verifier* v)
{
    this->verifier = v;
}

void org::mpisws::p2p::transport::peerreview::replay::playback::ReplaySM::setEnvironment(::rice::environment::Environment* env)
{
    if(env == nullptr)
        throw new ::java::lang::IllegalArgumentException(u"env is null!"_j);

    if(environment != nullptr)
        return;

    environment = env;
}

void org::mpisws::p2p::transport::peerreview::replay::playback::ReplaySM::addTask(::rice::selector::TimerTask* task)
{
    auto now = npc(timeSource)->currentTimeMillis();
    if((npc(task)->scheduledExecutionTime() < now) && (dynamic_cast< ::rice::environment::time::simulated::DirectTimeSource* >(timeSource) != nullptr)) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(logger)->logException(::java::lang::StringBuilder().append(u"Can't schedule a task in the past. "_j)->append(static_cast< ::java::lang::Object* >(task))
                ->append(u" now:"_j)
                ->append(now)
                ->append(u" task.execTime:"_j)
                ->append(npc(task)->scheduledExecutionTime())->toString(), new ::java::lang::Exception(u"Stack Trace"_j));

        throw new ::java::lang::RuntimeException(u"Can't schedule a task in the past."_j);
    }
    super::addTask(task);
}

bool org::mpisws::p2p::transport::peerreview::replay::playback::ReplaySM::makeProgress()
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
        npc(logger)->log(u"executeDueTasks()"_j);

    if(isSuccess())
        return false;

    auto timerProgress = true;
    auto now = npc(verifier)->getNextEventTime();
    while (timerProgress) {
        now = npc(verifier)->getNextEventTime();
        if(now == -int32_t(1))
            return false;

        ::rice::selector::TimerTask* next = nullptr;
        {
            synchronized synchronized_0(this);
            {
                if(npc(timerQueue)->size() > 0) {
                    next = java_cast< ::rice::selector::TimerTask* >(java_cast< ::rice::selector::TimerTask* >(npc(timerQueue)->peek()));
                    if(npc(next)->scheduledExecutionTime() <= now) {
                        npc(timerQueue)->poll();
                        npc(simTime)->setTime(npc(next)->scheduledExecutionTime());
                    } else {
                        timerProgress = false;
                    }
                } else {
                    timerProgress = false;
                }
            }
        }
        if(timerProgress) {
            super::doInvocations();
            if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
                npc(logger)->log(::java::lang::StringBuilder().append(u"executing task "_j)->append(static_cast< ::java::lang::Object* >(next))->toString());

            if(npc(next)->execute(simTime)) {
                {
                    synchronized synchronized_1(this);
                    {
                        npc(timerQueue)->add(static_cast< ::java::lang::Object* >(next));
                    }
                }
            }
        }
    }
    npc(simTime)->setTime(now);
    super::doInvocations();
    return npc(verifier)->makeProgress();
}

bool org::mpisws::p2p::transport::peerreview::replay::playback::ReplaySM::isSuccess()
{
    auto ret = npc(verifier)->isSuccess();
    if(ret) {
        npc(environment)->destroy();
    }
    return ret;
}

void org::mpisws::p2p::transport::peerreview::replay::playback::ReplaySM::doInvocations()
{
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::peerreview::replay::playback::ReplaySM::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.peerreview.replay.playback.ReplaySM", 60);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::peerreview::replay::playback::ReplaySM::getClass0()
{
    return class_();
}

