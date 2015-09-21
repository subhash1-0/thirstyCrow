// Generated from /pastry-2.1/src/rice/pastry/ExponentialBackoffScheduledMessage.java
#include <rice/pastry/ExponentialBackoffScheduledMessage.hpp>

#include <java/lang/Math.hpp>
#include <java/lang/NullPointerException.hpp>
#include <rice/pastry/ExponentialBackoffScheduledMessage_EBTimerTask.hpp>
#include <rice/selector/Timer.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::pastry::ExponentialBackoffScheduledMessage::ExponentialBackoffScheduledMessage(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::ExponentialBackoffScheduledMessage::ExponentialBackoffScheduledMessage(PastryNode* node, ::rice::pastry::messaging::Message* msg, ::rice::selector::Timer* timer, int64_t initialDelay, int64_t initialPeriod, double expBase, int64_t maxPeriod) 
    : ExponentialBackoffScheduledMessage(*static_cast< ::default_init_tag* >(0))
{
    ctor(node,msg,timer,initialDelay,initialPeriod,expBase,maxPeriod);
}

rice::pastry::ExponentialBackoffScheduledMessage::ExponentialBackoffScheduledMessage(PastryNode* node, ::rice::pastry::messaging::Message* msg, ::rice::selector::Timer* timer, int64_t initialDelay, double expBase) 
    : ExponentialBackoffScheduledMessage(*static_cast< ::default_init_tag* >(0))
{
    ctor(node,msg,timer,initialDelay,expBase);
}

void rice::pastry::ExponentialBackoffScheduledMessage::init()
{
    cancelled = false;
    numTimes = int32_t(0);
    lastTime = int32_t(0);
    maxTime = -int32_t(1);
}

void rice::pastry::ExponentialBackoffScheduledMessage::ctor(PastryNode* node, ::rice::pastry::messaging::Message* msg, ::rice::selector::Timer* timer, int64_t initialDelay, int64_t initialPeriod, double expBase, int64_t maxPeriod)
{
    super::ctor(node, msg);
    init();
    this->timer = timer;
    this->initialPeriod = initialPeriod;
    this->expBase = expBase;
    this->maxTime = maxPeriod;
    schedule(initialDelay);
}

void rice::pastry::ExponentialBackoffScheduledMessage::ctor(PastryNode* node, ::rice::pastry::messaging::Message* msg, ::rice::selector::Timer* timer, int64_t initialDelay, double expBase)
{
    ctor(node, msg, timer, initialDelay, initialDelay, expBase, -int32_t(1));
    numTimes = 1;
}

void rice::pastry::ExponentialBackoffScheduledMessage::schedule(int64_t time)
{
    myTask = new ExponentialBackoffScheduledMessage_EBTimerTask(this);
    npc(timer)->schedule(myTask, time);
}

bool rice::pastry::ExponentialBackoffScheduledMessage::cancel()
{
    super::cancel();
    if(myTask != nullptr) {
        npc(myTask)->cancel();
        myTask = nullptr;
    }
    auto temp = cancelled;
    cancelled = true;
    return temp;
}

void rice::pastry::ExponentialBackoffScheduledMessage::run()
{
    if(!cancelled) {
        if(myTask != nullptr) {
            lastTime = npc(myTask)->scheduledExecutionTime();
        }
        super::run();
        auto time = static_cast< int64_t >((initialPeriod * ::java::lang::Math::pow(expBase, numTimes)));
        if(maxTime >= 0) {
            time = ::java::lang::Math::min(time, maxTime);
        }
        schedule(time);
        numTimes++;
    }
}

int64_t rice::pastry::ExponentialBackoffScheduledMessage::scheduledExecutionTime()
{
    return lastTime;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::ExponentialBackoffScheduledMessage::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.ExponentialBackoffScheduledMessage", 46);
    return c;
}

java::lang::Class* rice::pastry::ExponentialBackoffScheduledMessage::getClass0()
{
    return class_();
}

