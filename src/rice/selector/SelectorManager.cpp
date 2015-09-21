// Generated from /pastry-2.1/src/rice/selector/SelectorManager.java
#include <rice/selector/SelectorManager.hpp>

#include <java/io/IOException.hpp>
#include <java/io/PrintStream.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/Class.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/IllegalArgumentException.hpp>
#include <java/lang/Integer.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/Runnable.hpp>
#include <java/lang/RuntimeException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/System.hpp>
#include <java/lang/Thread.hpp>
#include <java/lang/Throwable.hpp>
#include <java/nio/channels/CancelledKeyException.hpp>
#include <java/nio/channels/SelectableChannel.hpp>
#include <java/nio/channels/SelectionKey.hpp>
#include <java/nio/channels/Selector.hpp>
#include <java/util/ArrayList.hpp>
#include <java/util/Collection.hpp>
#include <java/util/HashMap.hpp>
#include <java/util/HashSet.hpp>
#include <java/util/Iterator.hpp>
#include <java/util/LinkedList.hpp>
#include <java/util/PriorityQueue.hpp>
#include <java/util/Queue.hpp>
#include <java/util/Set.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/exception/ExceptionStrategy.hpp>
#include <rice/environment/logging/LogManager.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/environment/random/RandomSource.hpp>
#include <rice/environment/random/simple/SimpleRandomSource.hpp>
#include <rice/environment/time/TimeSource.hpp>
#include <rice/selector/LoopObserver.hpp>
#include <rice/selector/SelectionKeyHandler.hpp>
#include <rice/selector/TimerTask.hpp>
#include <ObjectArray.hpp>
#include <SubArray.hpp>

template<typename ComponentType, typename... Bases> struct SubArray;
namespace java
{
    namespace io
    {
typedef ::SubArray< ::java::io::Serializable, ::java::lang::ObjectArray > SerializableArray;
    } // io

    namespace lang
    {
typedef ::SubArray< ::java::lang::CharSequence, ObjectArray > CharSequenceArray;
typedef ::SubArray< ::java::lang::Comparable, ObjectArray > ComparableArray;
typedef ::SubArray< ::java::lang::String, ObjectArray, ::java::io::SerializableArray, ComparableArray, CharSequenceArray > StringArray;
    } // lang

    namespace nio
    {
        namespace channels
        {
typedef ::SubArray< ::java::nio::channels::SelectionKey, ::java::lang::ObjectArray > SelectionKeyArray;
        } // channels
    } // nio
} // java

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
rice::selector::SelectorManager::SelectorManager(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::selector::SelectorManager::SelectorManager(::java::lang::String* instance, ::rice::environment::time::TimeSource* timeSource, ::rice::environment::logging::LogManager* log, ::rice::environment::random::RandomSource* random) 
    : SelectorManager(*static_cast< ::default_init_tag* >(0))
{
    ctor(instance,timeSource,log,random);
}

rice::selector::SelectorManager::SelectorManager(::java::lang::String* instance, ::rice::environment::time::TimeSource* timeSource, ::rice::environment::logging::LogManager* log) 
    : SelectorManager(*static_cast< ::default_init_tag* >(0))
{
    ctor(instance,timeSource,log);
}

void rice::selector::SelectorManager::init()
{
    timerQueue = new ::java::util::PriorityQueue();
    wakeupTime = int32_t(0);
    lastTime = int32_t(0);
    running = true;
    select_ = true;
    useLoopListeners_ = true;
    loopObservers = new ::java::util::ArrayList();
    seqLock = new ::java::lang::Object();
    seqCtr = ::java::lang::Integer::MIN_VALUE;
}

int32_t& rice::selector::SelectorManager::TIMEOUT()
{
    clinit();
    return TIMEOUT_;
}
int32_t rice::selector::SelectorManager::TIMEOUT_;

void rice::selector::SelectorManager::ctor(::java::lang::String* instance, ::rice::environment::time::TimeSource* timeSource, ::rice::environment::logging::LogManager* log, ::rice::environment::random::RandomSource* random)
{
    super::ctor(instance == nullptr ? u"Selector Thread"_j : ::java::lang::StringBuilder().append(u"Selector Thread -- "_j)->append(instance)->toString());
    init();
    this->random = random;
    if(this->random == nullptr)
        this->random = new ::rice::environment::random::simple::SimpleRandomSource(log);

    this->instance = instance;
    this->logger = npc(log)->getLogger(getClass(), instance);
    this->invocations = new ::java::util::LinkedList();
    this->modifyKeys = new ::java::util::HashSet();
    this->cancelledKeys = new ::java::util::HashSet();
    this->timeSource = timeSource;
    try {
        selector = ::java::nio::channels::Selector::open();
    } catch (::java::io::IOException* e) {
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"SEVERE ERROR (SelectorManager): Error creating selector "_j)->append(static_cast< ::java::lang::Object* >(e))->toString());
    }
    lastTime = npc(timeSource)->currentTimeMillis();
}

void rice::selector::SelectorManager::ctor(::java::lang::String* instance, ::rice::environment::time::TimeSource* timeSource, ::rice::environment::logging::LogManager* log)
{
    ctor(instance, timeSource, log, new ::rice::environment::random::simple::SimpleRandomSource(log));
}

void rice::selector::SelectorManager::setEnvironment(::rice::environment::Environment* env)
{
    if(env == nullptr)
        throw new ::java::lang::IllegalArgumentException(u"env is null!"_j);

    if(environment != nullptr)
        return;

    environment = env;
    npc(environment)->addDestructable(this);
    start();
}

void rice::selector::SelectorManager::cancel(::java::nio::channels::SelectionKey* key)
{
    if(key == nullptr)
        throw new ::java::lang::NullPointerException();

    npc(cancelledKeys)->add(static_cast< ::java::lang::Object* >(key));
}

java::nio::channels::SelectionKey* rice::selector::SelectorManager::getKey(::java::nio::channels::SelectableChannel* channel)
{
    return npc(channel)->keyFor(selector);
}

java::nio::channels::SelectionKey* rice::selector::SelectorManager::register_(::java::nio::channels::SelectableChannel* channel, SelectionKeyHandler* handler, int32_t ops) /* throws(IOException) */
{
    if((channel == nullptr) || (handler == nullptr))
        throw new ::java::lang::NullPointerException();

    auto key = npc(channel)->register_(selector, ops, handler);
    if(cancelledKeys != nullptr)
        npc(cancelledKeys)->remove(static_cast< ::java::lang::Object* >(key));

    return key;
}

void rice::selector::SelectorManager::invoke(::java::lang::Runnable* d)
{
    if(d == nullptr)
        throw new ::java::lang::NullPointerException();

    if(invocations == nullptr)
        return;

    npc(invocations)->add(static_cast< ::java::lang::Object* >(d));
    wakeup();
}

int32_t rice::selector::SelectorManager::getNumInvocations()
{
    return npc(invocations)->size();
}

void rice::selector::SelectorManager::modifyKey(::java::nio::channels::SelectionKey* key)
{
    if(key == nullptr)
        throw new ::java::lang::NullPointerException();

    npc(modifyKeys)->add(static_cast< ::java::lang::Object* >(key));
    wakeup();
}

void rice::selector::SelectorManager::onLoop()
{
}

void rice::selector::SelectorManager::run()
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
        npc(logger)->log(::java::lang::StringBuilder().append(u"SelectorManager -- "_j)->append(instance)
            ->append(u" starting..."_j)->toString());

    lastTime = npc(timeSource)->currentTimeMillis();
    while (running) {
        try {
            if(useLoopListeners_)
                notifyLoopListeners();

            ::java::lang::Thread::yield();
            executeDueTasks();
            onLoop();
            doInvocations();
            if(select_) {
                doSelections();
                auto selectTime = SelectorManager::TIMEOUT_;
                if(npc(timerQueue)->size() > 0) {
                    auto first = java_cast< TimerTask* >(java_cast< TimerTask* >(npc(timerQueue)->peek()));
                    selectTime = static_cast< int32_t >((npc(first)->scheduledExecutionTime() - npc(timeSource)->currentTimeMillis()));
                }
                select(selectTime);
                if(npc(cancelledKeys)->size() > 0) {
                    auto i = npc(cancelledKeys)->iterator();
                    while (npc(i)->hasNext()) 
                                                npc((java_cast< ::java::nio::channels::SelectionKey* >(java_cast< ::java::nio::channels::SelectionKey* >(npc(i)->next()))))->cancel();

                    npc(cancelledKeys)->clear();
                    npc(selector)->selectNow();
                }
            }
        } catch (::java::lang::Throwable* t) {
            if(npc(logger)->level <= ::rice::environment::logging::Logger::SEVERE)
                npc(logger)->logException(u"ERROR (SelectorManager.run): "_j, t);

            npc(npc(environment)->getExceptionStrategy())->handleException(this, t);
        }
    }
    npc(invocations)->clear();
    npc(loopObservers)->clear();
    npc(cancelledKeys)->clear();
    npc(timerQueue)->clear();
    invocations = nullptr;
    loopObservers = nullptr;
    cancelledKeys = nullptr;
    timerQueue = nullptr;
    try {
        if(selector != nullptr) {
            npc(selector)->close();
        }
    } catch (::java::io::IOException* ioe) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(logger)->logException(u"Error cancelling selector:"_j, ioe);

    }
    if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
        npc(logger)->log(::java::lang::StringBuilder().append(u"Selector "_j)->append(instance)
            ->append(u" shutting down."_j)->toString());

}

void rice::selector::SelectorManager::destroy()
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE) {
        npc(logger)->logException(u"destroying SelectorManager"_j, new ::java::lang::Exception(u"Stack Trace"_j));
    } else if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO) {
        npc(logger)->log(u"destroying SelectorManager"_j);
    }
    running = false;
}

void rice::selector::SelectorManager::useLoopListeners(bool val)
{
    useLoopListeners_ = val;
}

void rice::selector::SelectorManager::notifyLoopListeners()
{
    auto now = npc(timeSource)->currentTimeMillis();
    auto diff = now - lastTime;
    {
        synchronized synchronized_0(loopObservers);
        {
            auto i = npc(loopObservers)->iterator();
            while (npc(i)->hasNext()) {
                auto lo = java_cast< LoopObserver* >(java_cast< LoopObserver* >(npc(i)->next()));
                if(npc(lo)->delayInterest() <= diff) {
                    npc(lo)->loopTime(static_cast< int32_t >(diff));
                }
            }
        }
    }
    lastTime = now;
}

void rice::selector::SelectorManager::addLoopObserver(LoopObserver* lo)
{
    {
        synchronized synchronized_1(loopObservers);
        {
            npc(loopObservers)->add(static_cast< ::java::lang::Object* >(lo));
        }
    }
}

void rice::selector::SelectorManager::removeLoopObserver(LoopObserver* lo)
{
    {
        synchronized synchronized_2(loopObservers);
        {
            npc(loopObservers)->remove(static_cast< ::java::lang::Object* >(lo));
        }
    }
}

void rice::selector::SelectorManager::doSelections() /* throws(IOException) */
{
    auto keys = selectedKeys();
    if(npc(keys)->length > 1000 && npc(logger)->level <= ::rice::environment::logging::Logger::FINE) {
        npc(logger)->log(u"lots of selection keys!"_j);
        auto histo = new ::java::util::HashMap();
        for (auto i = int32_t(0); i < npc(keys)->length; i++) {
            auto keyclass = npc(npc((*keys)[i])->getClass())->getName();
            if(npc(histo)->containsKey(static_cast< ::java::lang::Object* >(keyclass))) {
                npc(histo)->put(static_cast< ::java::lang::Object* >(keyclass), static_cast< ::java::lang::Object* >(new ::java::lang::Integer(npc((java_cast< ::java::lang::Integer* >(java_cast< ::java::lang::Integer* >(npc(histo)->get(static_cast< ::java::lang::Object* >(keyclass))))))->intValue() + int32_t(1))));
            } else {
                npc(histo)->put(static_cast< ::java::lang::Object* >(keyclass), static_cast< ::java::lang::Object* >(new ::java::lang::Integer(int32_t(1))));
            }
        }
        npc(logger)->log(u"begin selection keys by class"_j);
        auto it = npc(npc(histo)->keySet())->iterator();
        while (npc(it)->hasNext()) {
            auto name = java_cast< ::java::lang::String* >(java_cast< ::java::lang::String* >(npc(it)->next()));
            npc(logger)->log(::java::lang::StringBuilder().append(u"Selection Key: "_j)->append(name)
                ->append(u": "_j)
                ->append(static_cast< ::java::lang::Object* >(java_cast< ::java::lang::Integer* >(npc(histo)->get(static_cast< ::java::lang::Object* >(name)))))->toString());
        }
        npc(logger)->log(u"end selection keys by class"_j);
    }
    for (auto i = int32_t(0); i < npc(keys)->length; i++) {
        npc(npc(selector)->selectedKeys())->remove(static_cast< ::java::lang::Object* >((*keys)[i]));
        {
            synchronized synchronized_3((*keys)[i]);
            {
                auto skh = java_cast< SelectionKeyHandler* >(npc((*keys)[i])->attachment());
                if(skh != nullptr) {
                    if(npc((*keys)[i])->isValid() && npc((*keys)[i])->isAcceptable()) {
                        npc(skh)->accept((*keys)[i]);
                    }
                    if(npc((*keys)[i])->isValid() && npc((*keys)[i])->isConnectable()) {
                        npc(skh)->connect((*keys)[i]);
                    }
                    if(npc((*keys)[i])->isValid() && npc((*keys)[i])->isReadable()) {
                        npc(skh)->read((*keys)[i]);
                    }
                    if(npc((*keys)[i])->isValid() && npc((*keys)[i])->isWritable()) {
                        npc(skh)->write((*keys)[i]);
                    }
                } else {
                    npc(npc((*keys)[i])->channel())->close();
                    npc((*keys)[i])->cancel();
                }
            }
        }
    }
}

void rice::selector::SelectorManager::doInvocations()
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINEST)
        npc(logger)->log(u"SM.doInvocations()"_j);

    ::java::util::Iterator* i;
    {
        synchronized synchronized_4(this);
        {
            i = (new ::java::util::ArrayList(static_cast< ::java::util::Collection* >(invocations)))->iterator();
            npc(invocations)->clear();
        }
    }
    while (npc(i)->hasNext()) {
        auto run = java_cast< ::java::lang::Runnable* >(java_cast< ::java::lang::Runnable* >(npc(i)->next()));
        try {
            npc(run)->run();
        } catch (::java::lang::RuntimeException* e) {
            {
                synchronized synchronized_5(this);
                {
                    auto ctr = int32_t(0);
                    while (npc(i)->hasNext()) {
                        npc(invocations)->add(ctr, static_cast< ::java::lang::Object* >(java_cast< ::java::lang::Runnable* >(npc(i)->next())));
                        ctr++;
                    }
                }
            }
            throw e;
        }
    }
    ::java::util::Iterator* i2;
    {
        synchronized synchronized_6(this);
        {
            i2 = (new ::java::util::ArrayList(static_cast< ::java::util::Collection* >(modifyKeys)))->iterator();
            npc(modifyKeys)->clear();
        }
    }
    while (npc(i2)->hasNext()) {
        auto key = java_cast< ::java::nio::channels::SelectionKey* >(java_cast< ::java::nio::channels::SelectionKey* >(npc(i2)->next()));
        if(npc(key)->isValid() && (npc(key)->attachment() != nullptr))
            npc((java_cast< SelectionKeyHandler* >(npc(key)->attachment())))->modifyKey(key);

    }
}

java::lang::Runnable* rice::selector::SelectorManager::getInvocation()
{
    if(npc(invocations)->size() > 0)
        return java_cast< ::java::lang::Runnable* >(java_cast< ::java::lang::Runnable* >(npc(invocations)->removeFirst()));
    else
        return nullptr;
}

java::nio::channels::SelectionKey* rice::selector::SelectorManager::getModifyKey()
{
    if(npc(modifyKeys)->size() > 0) {
        ::java::lang::Object* result = java_cast< ::java::nio::channels::SelectionKey* >(npc(npc(modifyKeys)->iterator())->next());
        npc(modifyKeys)->remove(result);
        return java_cast< ::java::nio::channels::SelectionKey* >(result);
    } else {
        return nullptr;
    }
}

int32_t rice::selector::SelectorManager::select(int32_t time) /* throws(IOException) */
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINEST)
        npc(logger)->log(::java::lang::StringBuilder().append(u"SM.select("_j)->append(time)
            ->append(u")"_j)->toString());

    if(time > TIMEOUT_)
        time = TIMEOUT_;

    try {
        if((time <= 0) || (npc(invocations)->size() > 0) || (npc(modifyKeys)->size() > 0))
            return npc(selector)->selectNow();

        wakeupTime = npc(timeSource)->currentTimeMillis() + time;
        return npc(selector)->select(time);
    } catch (::java::nio::channels::CancelledKeyException* cce) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(logger)->logException(u"CCE: cause:"_j, npc(cce)->getCause());

        throw cce;
    } catch (::java::io::IOException* e) {
        if(npc(npc(e)->getMessage())->indexOf(u"Interrupted system call"_j) >= 0) {
            if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                npc(logger)->log(u"Got interrupted system call, continuing anyway..."_j);

            return 1;
        } else {
            throw e;
        }
    }
}

java::nio::channels::SelectionKeyArray* rice::selector::SelectorManager::selectedKeys() /* throws(IOException) */
{
    auto s = npc(selector)->selectedKeys();
    auto k = java_cast< ::java::nio::channels::SelectionKeyArray* >(java_cast< ::java::nio::channels::SelectionKeyArray* >(npc(s)->toArray_(static_cast< ::java::lang::ObjectArray* >(new ::java::nio::channels::SelectionKeyArray(int32_t(0))))));
    for (auto c = int32_t(0); c < npc(k)->length; c++) {
        auto temp = (*k)[c];
        auto swapIndex = npc(random)->nextInt(npc(k)->length);
        k->set(c, (*k)[swapIndex]);
        k->set(swapIndex, temp);
    }
    return k;
}

bool rice::selector::SelectorManager::isSelectorThread()
{
    return (::java::lang::Thread::currentThread() == static_cast< ::java::lang::Thread* >(this));
}

rice::selector::TimerTask* rice::selector::SelectorManager::schedule(TimerTask* task)
{
    addTask(task);
    return task;
}

rice::selector::TimerTask* rice::selector::SelectorManager::schedule(TimerTask* task, int64_t delay)
{
    npc(task)->setNextExecutionTime(npc(timeSource)->currentTimeMillis() + delay);
    addTask(task);
    return task;
}

rice::selector::TimerTask* rice::selector::SelectorManager::schedule(TimerTask* task, int64_t delay, int64_t period)
{
    npc(task)->setNextExecutionTime(npc(timeSource)->currentTimeMillis() + delay);
    npc(task)->period = static_cast< int32_t >(period);
    addTask(task);
    return task;
}

rice::selector::TimerTask* rice::selector::SelectorManager::scheduleAtFixedRate(TimerTask* task, int64_t delay, int64_t period)
{
    npc(task)->setNextExecutionTime(npc(timeSource)->currentTimeMillis() + delay);
    npc(task)->period = static_cast< int32_t >(period);
    npc(task)->fixedRate = true;
    addTask(task);
    return task;
}

void rice::selector::SelectorManager::addTask(TimerTask* task)
{
    {
        synchronized synchronized_7(seqLock);
        {
            npc(task)->seq = seqCtr++;
        }
    }
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
        npc(logger)->log(::java::lang::StringBuilder().append(u"addTask("_j)->append(static_cast< ::java::lang::Object* >(task))
            ->append(u") scheduled for "_j)
            ->append(npc(task)->scheduledExecutionTime())->toString());

    if(!npc(timerQueue)->add(static_cast< ::java::lang::Object* >(task))) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(logger)->log(::java::lang::StringBuilder().append(u"ERROR: Got false while enqueueing task "_j)->append(static_cast< ::java::lang::Object* >(task))
                ->append(u"!"_j)->toString());

        ::java::lang::Thread::dumpStack();
    } else {
        npc(task)->setSelectorManager(this);
    }
    if(select_) {
        if(wakeupTime >= npc(task)->scheduledExecutionTime()) {
            wakeup();
        }
    } else {
        if(npc(task)->scheduledExecutionTime() == getNextTaskExecutionTime()) {
            wakeup();
        }
    }
}

void rice::selector::SelectorManager::removeTask(TimerTask* task)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
        npc(logger)->log(::java::lang::StringBuilder().append(u"removeTask("_j)->append(static_cast< ::java::lang::Object* >(task))
            ->append(u") scheduled for "_j)
            ->append(npc(task)->scheduledExecutionTime())->toString());

    npc(timerQueue)->remove(task);
}

void rice::selector::SelectorManager::wakeup()
{
    npc(selector)->wakeup();
    this->notifyAll();
}

int64_t rice::selector::SelectorManager::getNextTaskExecutionTime()
{
    if(npc(timerQueue)->size() > 0) {
        auto next = java_cast< TimerTask* >(java_cast< TimerTask* >(npc(timerQueue)->peek()));
        return npc(next)->scheduledExecutionTime();
    }
    return -int32_t(1);
}

void rice::selector::SelectorManager::executeDueTasks()
{
    auto now = npc(timeSource)->currentTimeMillis();
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINEST)
        npc(logger)->log(::java::lang::StringBuilder().append(u"SM.executeDueTasks() "_j)->append(now)->toString());

    auto executeNow = new ::java::util::ArrayList();
    {
        synchronized synchronized_8(this);
        {
            auto done = false;
            while (!done) {
                if(npc(timerQueue)->size() > 0) {
                    auto next = java_cast< TimerTask* >(java_cast< TimerTask* >(npc(timerQueue)->peek()));
                    if(npc(next)->scheduledExecutionTime() <= now) {
                        npc(executeNow)->add(static_cast< ::java::lang::Object* >(next));
                        npc(timerQueue)->poll();
                    } else {
                        done = true;
                    }
                } else {
                    done = true;
                }
            }
        }
    }
    auto addBack = new ::java::util::ArrayList();
    auto i = npc(executeNow)->iterator();
    while (npc(i)->hasNext()) {
        auto next = java_cast< TimerTask* >(npc(i)->next());
        try {
            if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
                npc(logger)->log(::java::lang::StringBuilder().append(u"executing task "_j)->append(static_cast< ::java::lang::Object* >(next))->toString());

            if(executeTask(next)) {
                npc(addBack)->add(static_cast< ::java::lang::Object* >(next));
            }
        } catch (::java::lang::RuntimeException* e) {
            while (npc(i)->hasNext()) {
                npc(addBack)->add(static_cast< ::java::lang::Object* >(java_cast< TimerTask* >(npc(i)->next())));
            }
            {
                synchronized synchronized_9(this);
                {
                    i = npc(addBack)->iterator();
                    while (npc(i)->hasNext()) {
                        auto tt = java_cast< TimerTask* >(java_cast< TimerTask* >(npc(i)->next()));
                        npc(timerQueue)->add(static_cast< ::java::lang::Object* >(tt));
                    }
                }
            }
            throw e;
        }
    }
    {
        synchronized synchronized_10(this);
        {
            i = npc(addBack)->iterator();
            while (npc(i)->hasNext()) {
                auto tt = java_cast< TimerTask* >(java_cast< TimerTask* >(npc(i)->next()));
                npc(timerQueue)->add(static_cast< ::java::lang::Object* >(tt));
            }
        }
    }
}

bool rice::selector::SelectorManager::executeTask(TimerTask* next)
{
    return npc(next)->execute(timeSource);
}

rice::selector::Timer* rice::selector::SelectorManager::getTimer()
{
    return this;
}

java::nio::channels::Selector* rice::selector::SelectorManager::getSelector()
{
    return selector;
}

void rice::selector::SelectorManager::setSelect(bool b)
{
    select_ = b;
}

rice::environment::Environment* rice::selector::SelectorManager::getEnvironment()
{
    return environment;
}

void rice::selector::SelectorManager::setLogLevel(int32_t level)
{
    npc(logger)->level = level;
}

void rice::selector::SelectorManager::main(::java::lang::StringArray* args)
{
    clinit();
    new ::rice::environment::Environment();
    new ::rice::environment::Environment();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::selector::SelectorManager::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.selector.SelectorManager", 29);
    return c;
}

void rice::selector::SelectorManager::clinit()
{
    super::clinit();
    static bool in_cl_init = false;
struct clinit_ {
    clinit_() {
        in_cl_init = true;
        TIMEOUT_ = int32_t(500);
    }
};

    if(!in_cl_init) {
        static clinit_ clinit_instance;
    }
}

java::lang::Class* rice::selector::SelectorManager::getClass0()
{
    return class_();
}

