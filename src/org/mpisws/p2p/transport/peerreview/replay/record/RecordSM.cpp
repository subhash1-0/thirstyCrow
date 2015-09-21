// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/replay/record/RecordSM.java
#include <org/mpisws/p2p/transport/peerreview/replay/record/RecordSM.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/RuntimeException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/util/Queue.hpp>
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
org::mpisws::p2p::transport::peerreview::replay::record::RecordSM::RecordSM(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::transport::peerreview::replay::record::RecordSM::RecordSM(::java::lang::String* instance, ::rice::environment::time::TimeSource* realTime, ::rice::environment::time::simulated::DirectTimeSource* simTime, ::rice::environment::logging::LogManager* log, ::rice::environment::random::RandomSource* rs) 
    : RecordSM(*static_cast< ::default_init_tag* >(0))
{
    ctor(instance,realTime,simTime,log,rs);
}

void org::mpisws::p2p::transport::peerreview::replay::record::RecordSM::ctor(::java::lang::String* instance, ::rice::environment::time::TimeSource* realTime, ::rice::environment::time::simulated::DirectTimeSource* simTime, ::rice::environment::logging::LogManager* log, ::rice::environment::random::RandomSource* rs)
{
    super::ctor(instance, simTime, log, rs);
    this->realTime = realTime;
    this->simTime = simTime;
}

void org::mpisws::p2p::transport::peerreview::replay::record::RecordSM::addTask(::rice::selector::TimerTask* task)
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

void org::mpisws::p2p::transport::peerreview::replay::record::RecordSM::executeDueTasks()
{
    auto now = npc(realTime)->currentTimeMillis();
    auto done = false;
    while (!done) {
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
                        done = true;
                    }
                } else {
                    done = true;
                }
            }
        }
        if(!done) {
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
}

void org::mpisws::p2p::transport::peerreview::replay::record::RecordSM::doInvocations()
{
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::peerreview::replay::record::RecordSM::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.peerreview.replay.record.RecordSM", 58);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::peerreview::replay::record::RecordSM::getClass0()
{
    return class_();
}

