// Generated from /pastry-2.1/src/rice/selector/ProfileSelector.java
#include <rice/selector/ProfileSelector.hpp>

#include <java/io/PrintStream.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/Class.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/Runnable.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/System.hpp>
#include <java/lang/Thread.hpp>
#include <java/nio/channels/SelectableChannel.hpp>
#include <java/nio/channels/SelectionKey.hpp>
#include <java/nio/channels/Selector.hpp>
#include <java/util/ArrayList.hpp>
#include <java/util/Collection.hpp>
#include <java/util/Collections.hpp>
#include <java/util/Date.hpp>
#include <java/util/HashSet.hpp>
#include <java/util/Hashtable.hpp>
#include <java/util/Iterator.hpp>
#include <java/util/LinkedList.hpp>
#include <java/util/Set.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/environment/random/RandomSource.hpp>
#include <rice/environment/random/simple/SimpleRandomSource.hpp>
#include <rice/environment/time/TimeSource.hpp>
#include <rice/selector/ProfileSelector_ProfileSelector_1.hpp>
#include <rice/selector/ProfileSelector_printStats_2.hpp>
#include <rice/selector/ProfileSelector_Stat.hpp>
#include <rice/selector/SelectionKeyHandler.hpp>
#include <rice/selector/TimerTask.hpp>
#include <ObjectArray.hpp>
#include <SubArray.hpp>

template<typename ComponentType, typename... Bases> struct SubArray;
namespace java
{
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
rice::selector::ProfileSelector::ProfileSelector(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::selector::ProfileSelector::ProfileSelector(::java::lang::String* instance, ::rice::environment::time::TimeSource* timeSource, ::rice::environment::logging::LogManager* log) 
    : ProfileSelector(*static_cast< ::default_init_tag* >(0))
{
    ctor(instance,timeSource,log);
}

rice::selector::ProfileSelector::ProfileSelector(::java::lang::String* instance, ::rice::environment::time::TimeSource* timeSource, ::rice::environment::logging::LogManager* log, ::rice::environment::random::RandomSource* rand) 
    : ProfileSelector(*static_cast< ::default_init_tag* >(0))
{
    ctor(instance,timeSource,log,rand);
}

rice::selector::ProfileSelector::ProfileSelector(::java::lang::String* instance, ::rice::environment::time::TimeSource* timeSource, ::rice::environment::logging::LogManager* log, ::rice::environment::random::RandomSource* rand, int32_t lastTaskTime) 
    : ProfileSelector(*static_cast< ::default_init_tag* >(0))
{
    ctor(instance,timeSource,log,rand,lastTaskTime);
}

void rice::selector::ProfileSelector::init()
{
    HEART_BEAT_INTERVAL = int32_t(60000);
    lastHeartBeat = int32_t(0);
    lastTaskType = nullptr;
    lastTaskClass = nullptr;
    lastTaskToString = nullptr;
    lastTaskHash = int32_t(0);
    numInvocationsScheduled = int32_t(0);
    numInvocationsExecuted = int32_t(0);
    maxInvokes = int32_t(0);
    stats = new ::java::util::Hashtable();
}

bool& rice::selector::ProfileSelector::useHeartbeat()
{
    clinit();
    return useHeartbeat_;
}
bool rice::selector::ProfileSelector::useHeartbeat_;

bool& rice::selector::ProfileSelector::recordStats()
{
    clinit();
    return recordStats_;
}
bool rice::selector::ProfileSelector::recordStats_;

void rice::selector::ProfileSelector::ctor(::java::lang::String* instance, ::rice::environment::time::TimeSource* timeSource, ::rice::environment::logging::LogManager* log)
{
    ctor(instance, timeSource, log, nullptr);
}

void rice::selector::ProfileSelector::ctor(::java::lang::String* instance, ::rice::environment::time::TimeSource* timeSource, ::rice::environment::logging::LogManager* log, ::rice::environment::random::RandomSource* rand)
{
    ctor(instance, timeSource, log, nullptr, int32_t(60000));
}

void rice::selector::ProfileSelector::ctor(::java::lang::String* instance, ::rice::environment::time::TimeSource* timeSource, ::rice::environment::logging::LogManager* log, ::rice::environment::random::RandomSource* rand, int32_t lastTaskTime)
{
    super::ctor(instance, timeSource, log, (rand == nullptr) ? static_cast< ::rice::environment::random::RandomSource* >(new ::rice::environment::random::simple::SimpleRandomSource(log)) : rand);
    init();
    (new ::java::lang::Thread(static_cast< ::java::lang::Runnable* >(new ProfileSelector_ProfileSelector_1(this, lastTaskTime)), u"ProfileSelectorWatchdog"_j))->start();
}

void rice::selector::ProfileSelector::onLoop()
{
    if(!useHeartbeat_)
        return;

    auto curTime = npc(timeSource)->currentTimeMillis();
    if((curTime - lastHeartBeat) > HEART_BEAT_INTERVAL) {
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"selector heartbeat "_j)->append(static_cast< ::java::lang::Object* >(new ::java::util::Date()))
            ->append(u" maxInvokes:"_j)
            ->append(maxInvokes)
            ->append(u" invokesSched:"_j)
            ->append(numInvocationsScheduled)
            ->append(u" invokesExe:"_j)
            ->append(numInvocationsExecuted)
            ->append(u" CurrentThread:"_j)
            ->append(static_cast< ::java::lang::Object* >(::java::lang::Thread::currentThread()))
            ->append(u"@"_j)
            ->append(::java::lang::System::identityHashCode(::java::lang::Thread::currentThread()))->toString());
        printStats();
        lastHeartBeat = curTime;
    }
}

void rice::selector::ProfileSelector::invoke(::java::lang::Runnable* d)
{
    {
        synchronized synchronized_0(this);
        {
            numInvocationsScheduled++;
            super::invoke(d);
        }
    }
    auto numInvokes = npc(invocations)->size();
    if(numInvokes > maxInvokes) {
        maxInvokes = numInvokes;
    }
}

void rice::selector::ProfileSelector::addStat(::java::lang::String* s, int64_t time)
{
    if(!recordStats_)
        return;

    auto st = java_cast< ProfileSelector_Stat* >(java_cast< ProfileSelector_Stat* >(npc(stats)->get(static_cast< ::java::lang::Object* >(s))));
    if(st == nullptr) {
        st = new ProfileSelector_Stat(this, s);
        npc(stats)->put(static_cast< ::java::lang::Object* >(s), static_cast< ::java::lang::Object* >(st));
    }
    npc(st)->addTime(time);
}

void rice::selector::ProfileSelector::printStats()
{
    if(!recordStats_)
        return;

    auto list = new ::java::util::ArrayList(npc(stats)->size());
    if(stats != nullptr) {
        {
            synchronized synchronized_1(stats);
            {
                auto e = npc(npc(stats)->values())->iterator();
                while (npc(e)->hasNext()) {
                    auto s = java_cast< ProfileSelector_Stat* >(java_cast< ProfileSelector_Stat* >(npc(e)->next()));
                    npc(list)->add(static_cast< ::java::lang::Object* >(s));
                }
            }
        }
    }
    ::java::util::Collections::sort(list, new ProfileSelector_printStats_2(this));
    auto i = npc(list)->iterator();
    while (npc(i)->hasNext()) {
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"  "_j)->append(static_cast< ::java::lang::Object* >(java_cast< ProfileSelector_Stat* >(npc(i)->next())))->toString());
    }
}

bool rice::selector::ProfileSelector::executeTask(TimerTask* next)
{
    lastTaskType = ::java::lang::StringBuilder().append(u"Executing "_j)->append(static_cast< ::java::lang::Object* >(next))->toString();
    auto startTime = npc(timeSource)->currentTimeMillis();
    auto ret = super::executeTask(next);
    auto time = static_cast< int32_t >((npc(timeSource)->currentTimeMillis() - startTime));
    lastTaskType = ::java::lang::StringBuilder().append(u"Executing "_j)->append(static_cast< ::java::lang::Object* >(next))
        ->append(u" Complete"_j)->toString();
    addStat(::java::lang::StringBuilder().append(u"executing "_j)->append(static_cast< ::java::lang::Object* >(npc(next)->getClass()))->toString(), time);
    return ret;
}

void rice::selector::ProfileSelector::doSelections() /* throws(IOException) */
{
    auto keys = selectedKeys();
    for (auto i = int32_t(0); i < npc(keys)->length; i++) {
        npc(npc(selector)->selectedKeys())->remove(static_cast< ::java::lang::Object* >((*keys)[i]));
        auto skh = java_cast< SelectionKeyHandler* >(npc((*keys)[i])->attachment());
        if(skh != nullptr) {
            if(npc((*keys)[i])->isValid() && npc((*keys)[i])->isAcceptable()) {
                lastTaskType = u"Accept"_j;
                lastTaskClass = npc(npc(skh)->getClass())->getName();
                lastTaskToString = npc(skh)->toString();
                lastTaskHash = ::java::lang::System::identityHashCode(skh);
                auto startTime = npc(timeSource)->currentTimeMillis();
                npc(skh)->accept((*keys)[i]);
                auto time = static_cast< int32_t >((npc(timeSource)->currentTimeMillis() - startTime));
                lastTaskType = u"Accept Complete"_j;
                addStat(u"accepting"_j, time);
            }
            if(npc((*keys)[i])->isValid() && npc((*keys)[i])->isConnectable()) {
                lastTaskType = u"Connect"_j;
                lastTaskClass = npc(npc(skh)->getClass())->getName();
                lastTaskToString = npc(skh)->toString();
                lastTaskHash = ::java::lang::System::identityHashCode(skh);
                auto startTime = npc(timeSource)->currentTimeMillis();
                npc(skh)->connect((*keys)[i]);
                auto time = static_cast< int32_t >((npc(timeSource)->currentTimeMillis() - startTime));
                lastTaskType = u"Connect Complete"_j;
                addStat(u"connecting"_j, time);
            }
            if(npc((*keys)[i])->isValid() && npc((*keys)[i])->isReadable()) {
                lastTaskType = u"Read"_j;
                lastTaskClass = npc(npc(skh)->getClass())->getName();
                lastTaskToString = npc(skh)->toString();
                lastTaskHash = ::java::lang::System::identityHashCode(skh);
                auto startTime = npc(timeSource)->currentTimeMillis();
                npc(skh)->read((*keys)[i]);
                auto time = static_cast< int32_t >((npc(timeSource)->currentTimeMillis() - startTime));
                lastTaskType = u"Read Complete"_j;
            }
            if(npc((*keys)[i])->isValid() && npc((*keys)[i])->isWritable()) {
                lastTaskType = u"Write"_j;
                lastTaskClass = npc(npc(skh)->getClass())->getName();
                lastTaskToString = npc(skh)->toString();
                lastTaskHash = ::java::lang::System::identityHashCode(skh);
                auto startTime = npc(timeSource)->currentTimeMillis();
                npc(skh)->write((*keys)[i]);
                auto time = static_cast< int32_t >((npc(timeSource)->currentTimeMillis() - startTime));
                lastTaskType = u"Write Complete"_j;
            }
        } else {
            npc(npc((*keys)[i])->channel())->close();
            npc((*keys)[i])->cancel();
        }
    }
}

void rice::selector::ProfileSelector::doInvocations()
{
    ::java::util::Iterator* i;
    {
        synchronized synchronized_2(this);
        {
            i = (new ::java::util::ArrayList(static_cast< ::java::util::Collection* >(invocations)))->iterator();
            npc(invocations)->clear();
        }
    }
    ::java::lang::Runnable* run;
    while (npc(i)->hasNext()) {
        numInvocationsExecuted++;
        run = java_cast< ::java::lang::Runnable* >(java_cast< ::java::lang::Runnable* >(npc(i)->next()));
        try {
            lastTaskType = u"Invocation"_j;
            lastTaskClass = npc(npc(run)->getClass())->getName();
            lastTaskToString = npc(run)->toString();
            lastTaskHash = ::java::lang::System::identityHashCode(run);
            auto startTime = npc(timeSource)->currentTimeMillis();
            npc(run)->run();
            auto time = static_cast< int32_t >((npc(timeSource)->currentTimeMillis() - startTime));
            lastTaskType = u"Invocation Complete"_j;
        } catch (::java::lang::Exception* e) {
            if(npc(logger)->level <= ::rice::environment::logging::Logger::SEVERE)
                npc(logger)->logException(::java::lang::StringBuilder().append(u"Invoking runnable caused exception "_j)->append(static_cast< ::java::lang::Object* >(e))
                    ->append(u" - continuing"_j)->toString(), e);

        }
    }
    ::java::util::Iterator* i2;
    {
        synchronized synchronized_3(this);
        {
            i2 = (new ::java::util::ArrayList(static_cast< ::java::util::Collection* >(modifyKeys)))->iterator();
        }
    }
    ::java::nio::channels::SelectionKey* key;
    while (npc(i2)->hasNext()) {
        key = java_cast< ::java::nio::channels::SelectionKey* >(java_cast< ::java::nio::channels::SelectionKey* >(npc(i2)->next()));
        if(npc(key)->isValid() && (npc(key)->attachment() != nullptr)) {
            auto skh = java_cast< SelectionKeyHandler* >(npc(key)->attachment());
            lastTaskType = u"ModifyKey"_j;
            lastTaskClass = npc(npc(skh)->getClass())->getName();
            lastTaskHash = ::java::lang::System::identityHashCode(skh);
            lastTaskToString = npc(skh)->toString();
            npc(skh)->modifyKey(key);
            lastTaskType = u"ModifyKey Complete"_j;
        }
    }
}

void rice::selector::ProfileSelector::doInvocations2()
{
    auto run = getInvocation();
    while (run != nullptr) {
        try {
            lastTaskType = u"Invocation"_j;
            lastTaskClass = npc(npc(run)->getClass())->getName();
            lastTaskToString = npc(run)->toString();
            lastTaskHash = ::java::lang::System::identityHashCode(run);
            auto startTime = npc(timeSource)->currentTimeMillis();
            npc(run)->run();
            auto time = static_cast< int32_t >((npc(timeSource)->currentTimeMillis() - startTime));
            addStat(npc(npc(run)->getClass())->getName(), time);
            lastTaskType = u"Invocation Complete"_j;
        } catch (::java::lang::Exception* e) {
            if(npc(logger)->level <= ::rice::environment::logging::Logger::SEVERE)
                npc(logger)->logException(::java::lang::StringBuilder().append(u"Invoking runnable caused exception "_j)->append(static_cast< ::java::lang::Object* >(e))
                    ->append(u" - continuing"_j)->toString(), e);

        }
        run = getInvocation();
    }
    auto key = getModifyKey();
    while (key != nullptr) {
        if(npc(key)->isValid() && (npc(key)->attachment() != nullptr)) {
            auto skh = java_cast< SelectionKeyHandler* >(npc(key)->attachment());
            lastTaskType = u"ModifyKey"_j;
            lastTaskClass = npc(npc(skh)->getClass())->getName();
            lastTaskHash = ::java::lang::System::identityHashCode(skh);
            lastTaskToString = npc(skh)->toString();
            npc(skh)->modifyKey(key);
            lastTaskType = u"ModifyKey Complete"_j;
        }
        key = getModifyKey();
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::selector::ProfileSelector::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.selector.ProfileSelector", 29);
    return c;
}

void rice::selector::ProfileSelector::clinit()
{
    super::clinit();
    static bool in_cl_init = false;
struct clinit_ {
    clinit_() {
        in_cl_init = true;
        useHeartbeat_ = true;
        recordStats_ = true;
    }
};

    if(!in_cl_init) {
        static clinit_ clinit_instance;
    }
}

java::lang::Class* rice::selector::ProfileSelector::getClass0()
{
    return class_();
}

