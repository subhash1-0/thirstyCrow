// Generated from /pastry-2.1/src/rice/selector/ProfileSelector.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/fwd-pastry-2.1.hpp>
#include <rice/environment/random/fwd-pastry-2.1.hpp>
#include <rice/environment/time/fwd-pastry-2.1.hpp>
#include <rice/selector/fwd-pastry-2.1.hpp>
#include <rice/selector/SelectorManager.hpp>

struct default_init_tag;

class rice::selector::ProfileSelector
    : public SelectorManager
{

public:
    typedef SelectorManager super;

private:
    static bool useHeartbeat_;

public: /* package */
    int32_t HEART_BEAT_INTERVAL {  };
    int64_t lastHeartBeat {  };

private:
    static bool recordStats_;

public:
    ::java::lang::String* lastTaskType {  };
    ::java::lang::String* lastTaskClass {  };
    ::java::lang::String* lastTaskToString {  };
    int64_t lastTaskHash {  };

public: /* package */
    int32_t numInvocationsScheduled {  };
    int32_t numInvocationsExecuted {  };
protected:
    void ctor(::java::lang::String* instance, ::rice::environment::time::TimeSource* timeSource, ::rice::environment::logging::LogManager* log);
    void ctor(::java::lang::String* instance, ::rice::environment::time::TimeSource* timeSource, ::rice::environment::logging::LogManager* log, ::rice::environment::random::RandomSource* rand);
    void ctor(::java::lang::String* instance, ::rice::environment::time::TimeSource* timeSource, ::rice::environment::logging::LogManager* log, ::rice::environment::random::RandomSource* rand, int32_t lastTaskTime);

public: /* protected */
    void onLoop() override;

public: /* package */
    int32_t maxInvokes {  };

public:
    void invoke(::java::lang::Runnable* d) override;

private:
    ::java::util::Hashtable* stats {  };

public:
    virtual void addStat(::java::lang::String* s, int64_t time);
    virtual void printStats();

public: /* protected */
    bool executeTask(TimerTask* next) override;
    void doSelections() /* throws(IOException) */ override;
    void doInvocations() override;
    virtual void doInvocations2();

    // Generated

public:
    ProfileSelector(::java::lang::String* instance, ::rice::environment::time::TimeSource* timeSource, ::rice::environment::logging::LogManager* log);
    ProfileSelector(::java::lang::String* instance, ::rice::environment::time::TimeSource* timeSource, ::rice::environment::logging::LogManager* log, ::rice::environment::random::RandomSource* rand);
    ProfileSelector(::java::lang::String* instance, ::rice::environment::time::TimeSource* timeSource, ::rice::environment::logging::LogManager* log, ::rice::environment::random::RandomSource* rand, int32_t lastTaskTime);
protected:
    ProfileSelector(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    static void clinit();

private:
    void init();

public:
    static bool& useHeartbeat();
    static bool& recordStats();

private:
    virtual ::java::lang::Class* getClass0();
    friend class ProfileSelector_ProfileSelector_1;
    friend class ProfileSelector_printStats_2;
    friend class ProfileSelector_Stat;
};
