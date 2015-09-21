// Generated from /pastry-2.1/src/rice/environment/Environment.java
#include <rice/environment/Environment.hpp>

#include <java/io/IOException.hpp>
#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/CharSequence.hpp>
#include <java/lang/Class.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Comparable.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/IllegalArgumentException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/util/ArrayList.hpp>
#include <java/util/Collection.hpp>
#include <java/util/HashSet.hpp>
#include <java/util/Iterator.hpp>
#include <rice/Destructable.hpp>
#include <rice/environment/Environment_destroy_1.hpp>
#include <rice/environment/exception/ExceptionStrategy.hpp>
#include <rice/environment/exception/simple/SimpleExceptionStrategy.hpp>
#include <rice/environment/logging/CloneableLogManager.hpp>
#include <rice/environment/logging/LogManager.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/environment/logging/file/FileLogManager.hpp>
#include <rice/environment/logging/simple/SimpleLogManager.hpp>
#include <rice/environment/params/Parameters.hpp>
#include <rice/environment/params/simple/SimpleParameters.hpp>
#include <rice/environment/processing/Processor.hpp>
#include <rice/environment/processing/sim/SimProcessor.hpp>
#include <rice/environment/processing/simple/SimpleProcessor.hpp>
#include <rice/environment/random/RandomSource.hpp>
#include <rice/environment/random/simple/SimpleRandomSource.hpp>
#include <rice/environment/time/TimeSource.hpp>
#include <rice/environment/time/simple/SimpleTimeSource.hpp>
#include <rice/environment/time/simulated/DirectTimeSource.hpp>
#include <rice/selector/SelectorManager.hpp>
#include <SubArray.hpp>
#include <ObjectArray.hpp>

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

rice::environment::Environment::Environment(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::environment::Environment::Environment(::rice::selector::SelectorManager* sm, ::rice::environment::processing::Processor* proc, ::rice::environment::random::RandomSource* rs, ::rice::environment::time::TimeSource* time, ::rice::environment::logging::LogManager* lm, ::rice::environment::params::Parameters* params, ::rice::environment::exception::ExceptionStrategy* strategy) 
    : Environment(*static_cast< ::default_init_tag* >(0))
{
    ctor(sm,proc,rs,time,lm,params,strategy);
}

rice::environment::Environment::Environment(::java::lang::StringArray* orderedDefaultFiles, ::java::lang::String* paramFileName) 
    : Environment(*static_cast< ::default_init_tag* >(0))
{
    ctor(orderedDefaultFiles,paramFileName);
}

rice::environment::Environment::Environment(::java::lang::String* paramFileName) 
    : Environment(*static_cast< ::default_init_tag* >(0))
{
    ctor(paramFileName);
}

rice::environment::Environment::Environment() 
    : Environment(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

void rice::environment::Environment::init()
{
    destructables = new ::java::util::HashSet();
}

java::lang::StringArray*& rice::environment::Environment::defaultParamFileArray_()
{
    clinit();
    return defaultParamFileArray__;
}
java::lang::StringArray* rice::environment::Environment::defaultParamFileArray__;

void rice::environment::Environment::ctor(::rice::selector::SelectorManager* sm, ::rice::environment::processing::Processor* proc, ::rice::environment::random::RandomSource* rs, ::rice::environment::time::TimeSource* time, ::rice::environment::logging::LogManager* lm, ::rice::environment::params::Parameters* params, ::rice::environment::exception::ExceptionStrategy* strategy)
{
    super::ctor();
    init();
    this->selectorManager = sm;
    this->randomSource = rs;
    this->time = time;
    this->logManager = lm;
    this->params = params;
    this->processor = proc;
    this->exceptionStrategy = strategy;
    if(params == nullptr) {
        throw new ::java::lang::IllegalArgumentException(u"params cannot be null"_j);
    }
    chooseDefaults();
    logger = npc(this->logManager)->getLogger(getClass(), nullptr);
    npc(this->selectorManager)->setEnvironment(this);
    addDestructable(this->time);
}

void rice::environment::Environment::ctor(::java::lang::StringArray* orderedDefaultFiles, ::java::lang::String* paramFileName)
{
    ctor(nullptr, nullptr, nullptr, nullptr, nullptr, new ::rice::environment::params::simple::SimpleParameters(orderedDefaultFiles, paramFileName), nullptr);
}

rice::environment::Environment* rice::environment::Environment::directEnvironment(int32_t randomSeed)
{
    clinit();
    auto srs = new ::rice::environment::random::simple::SimpleRandomSource(static_cast< int64_t >(randomSeed), static_cast< ::rice::environment::logging::LogManager* >(nullptr));
    auto env = directEnvironment(static_cast< ::rice::environment::random::RandomSource* >(srs));
    npc(srs)->setLogManager(npc(env)->getLogManager());
    return env;
}

rice::environment::Environment* rice::environment::Environment::directEnvironment()
{
    clinit();
    return directEnvironment(static_cast< ::rice::environment::random::RandomSource* >(nullptr));
}

rice::environment::Environment* rice::environment::Environment::directEnvironment(::rice::environment::random::RandomSource* rs)
{
    clinit();
    ::rice::environment::params::Parameters* params = new ::rice::environment::params::simple::SimpleParameters(Environment::defaultParamFileArray__, nullptr);
    auto dts = new ::rice::environment::time::simulated::DirectTimeSource(params);
    auto lm = generateDefaultLogManager(dts, params);
    npc(dts)->setLogManager(lm);
    auto selector = generateDefaultSelectorManager(dts, lm, rs);
    npc(dts)->setSelectorManager(selector);
    ::rice::environment::processing::Processor* proc = new ::rice::environment::processing::sim::SimProcessor(selector);
    auto ret = new Environment(selector, proc, rs, dts, lm, params, generateDefaultExceptionStrategy(lm));
    return ret;
}

void rice::environment::Environment::ctor(::java::lang::String* paramFileName)
{
    ctor(defaultParamFileArray__, paramFileName);
}

void rice::environment::Environment::ctor()
{
    ctor(nullptr);
}

void rice::environment::Environment::chooseDefaults()
{
    if(time == nullptr) {
        time = generateDefaultTimeSource();
    }
    if(logManager == nullptr) {
        logManager = generateDefaultLogManager(time, params);
    }
    if(randomSource == nullptr) {
        randomSource = generateDefaultRandomSource(params, logManager);
    }
    if(selectorManager == nullptr) {
        selectorManager = generateDefaultSelectorManager(time, logManager, randomSource);
    }
    if(processor == nullptr) {
        if(npc(params)->contains(u"environment_use_sim_processor"_j) && npc(params)->getBoolean(u"environment_use_sim_processor"_j)) {
            processor = new ::rice::environment::processing::sim::SimProcessor(selectorManager);
        } else {
            processor = generateDefaultProcessor();
        }
    }
    if(exceptionStrategy == nullptr) {
        exceptionStrategy = generateDefaultExceptionStrategy(logManager);
    }
}

rice::environment::exception::ExceptionStrategy* rice::environment::Environment::generateDefaultExceptionStrategy(::rice::environment::logging::LogManager* manager)
{
    clinit();
    return new ::rice::environment::exception::simple::SimpleExceptionStrategy(manager);
}

rice::environment::random::RandomSource* rice::environment::Environment::generateDefaultRandomSource(::rice::environment::params::Parameters* params, ::rice::environment::logging::LogManager* logging)
{
    clinit();
    ::rice::environment::random::RandomSource* randomSource;
    if(npc(npc(params)->getString(u"random_seed"_j))->equalsIgnoreCase(u"clock"_j)) {
        randomSource = new ::rice::environment::random::simple::SimpleRandomSource(logging);
    } else {
        randomSource = new ::rice::environment::random::simple::SimpleRandomSource(npc(params)->getLong(u"random_seed"_j), logging);
    }
    return randomSource;
}

rice::environment::time::TimeSource* rice::environment::Environment::generateDefaultTimeSource()
{
    clinit();
    return new ::rice::environment::time::simple::SimpleTimeSource();
}

rice::environment::logging::LogManager* rice::environment::Environment::generateDefaultLogManager(::rice::environment::time::TimeSource* time, ::rice::environment::params::Parameters* params)
{
    clinit();
    if(npc(params)->getBoolean(u"environment_logToFile"_j)) {
        return new ::rice::environment::logging::file::FileLogManager(time, params);
    }
    return new ::rice::environment::logging::simple::SimpleLogManager(time, params);
}

rice::selector::SelectorManager* rice::environment::Environment::generateDefaultSelectorManager(::rice::environment::time::TimeSource* time, ::rice::environment::logging::LogManager* logging, ::rice::environment::random::RandomSource* randomSource)
{
    clinit();
    return new ::rice::selector::SelectorManager(u"Default"_j, time, logging, randomSource);
}

rice::environment::processing::Processor* rice::environment::Environment::generateDefaultProcessor()
{
    clinit();
    return new ::rice::environment::processing::simple::SimpleProcessor(u"Default"_j);
}

rice::selector::SelectorManager* rice::environment::Environment::getSelectorManager()
{
    return selectorManager;
}

rice::environment::processing::Processor* rice::environment::Environment::getProcessor()
{
    return processor;
}

rice::environment::random::RandomSource* rice::environment::Environment::getRandomSource()
{
    return randomSource;
}

rice::environment::time::TimeSource* rice::environment::Environment::getTimeSource()
{
    return time;
}

rice::environment::logging::LogManager* rice::environment::Environment::getLogManager()
{
    return logManager;
}

rice::environment::params::Parameters* rice::environment::Environment::getParameters()
{
    return params;
}

void rice::environment::Environment::destroy()
{
    try {
        npc(params)->store();
    } catch (::java::io::IOException* ioe) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(logger)->logException(u"Error during shutdown"_j, ioe);

    }
    if(npc(getSelectorManager())->isSelectorThread()) {
        callDestroyOnDestructables();
    } else {
        npc(getSelectorManager())->invoke(new Environment_destroy_1(this));
    }
}

void rice::environment::Environment::callDestroyOnDestructables()
{
    auto i = (new ::java::util::ArrayList(static_cast< ::java::util::Collection* >(destructables)))->iterator();
    while (npc(i)->hasNext()) {
        auto d = java_cast< ::rice::Destructable* >(java_cast< ::rice::Destructable* >(npc(i)->next()));
        npc(d)->destroy();
    }
    npc(selectorManager)->destroy();
    npc(processor)->destroy();
}

void rice::environment::Environment::addDestructable(::rice::Destructable* destructable)
{
    if(destructable == nullptr) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(logger)->logException(u"addDestructable(null)"_j, new ::java::lang::Exception(u"Stack Trace"_j));

        return;
    }
    npc(destructables)->add(static_cast< ::java::lang::Object* >(destructable));
}

void rice::environment::Environment::removeDestructable(::rice::Destructable* destructable)
{
    if(destructable == nullptr) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(logger)->logException(u"addDestructable(null)"_j, new ::java::lang::Exception(u"Stack Trace"_j));

        return;
    }
    npc(destructables)->remove(static_cast< ::java::lang::Object* >(destructable));
}

rice::environment::exception::ExceptionStrategy* rice::environment::Environment::getExceptionStrategy()
{
    return exceptionStrategy;
}

rice::environment::exception::ExceptionStrategy* rice::environment::Environment::setExceptionStrategy(::rice::environment::exception::ExceptionStrategy* newStrategy)
{
    auto ret = exceptionStrategy;
    exceptionStrategy = newStrategy;
    return ret;
}

rice::environment::Environment* rice::environment::Environment::cloneEnvironment(::java::lang::String* prefix)
{
    return cloneEnvironment(prefix, false, false);
}

rice::environment::Environment* rice::environment::Environment::cloneEnvironment(::java::lang::String* prefix, bool cloneSelector, bool cloneProcessor)
{
    auto lman = cloneLogManager(prefix);
    auto ts = cloneTimeSource(lman);
    auto rand = cloneRandomSource(lman);
    auto sman = cloneSelectorManager(prefix, ts, rand, lman, cloneSelector);
    auto proc = this->cloneProcessor(prefix, lman, cloneProcessor);
    auto ret = new Environment(sman, proc, rand, getTimeSource(), lman, getParameters(), getExceptionStrategy());
    addDestructable(ret);
    return ret;
}

rice::environment::time::TimeSource* rice::environment::Environment::cloneTimeSource(::rice::environment::logging::LogManager* lman)
{
    return getTimeSource();
}

rice::environment::logging::LogManager* rice::environment::Environment::cloneLogManager(::java::lang::String* prefix)
{
    auto lman = getLogManager();
    if(dynamic_cast< ::rice::environment::logging::CloneableLogManager* >(lman) != nullptr) {
        lman = npc((java_cast< ::rice::environment::logging::CloneableLogManager* >(getLogManager())))->clone(prefix);
    }
    return lman;
}

rice::selector::SelectorManager* rice::environment::Environment::cloneSelectorManager(::java::lang::String* prefix, ::rice::environment::time::TimeSource* ts, ::rice::environment::random::RandomSource* rs, ::rice::environment::logging::LogManager* lman, bool cloneSelector)
{
    auto sman = getSelectorManager();
    if(cloneSelector) {
        sman = new ::rice::selector::SelectorManager(::java::lang::StringBuilder().append(prefix)->append(u" Selector"_j)->toString(), ts, lman, rs);
    }
    return sman;
}

rice::environment::processing::Processor* rice::environment::Environment::cloneProcessor(::java::lang::String* prefix, ::rice::environment::logging::LogManager* lman, bool cloneProcessor)
{
    auto proc = getProcessor();
    if(cloneProcessor) {
        proc = new ::rice::environment::processing::simple::SimpleProcessor(::java::lang::StringBuilder().append(prefix)->append(u" Processor"_j)->toString());
    }
    return proc;
}

rice::environment::random::RandomSource* rice::environment::Environment::cloneRandomSource(::rice::environment::logging::LogManager* lman)
{
    auto randSeed = npc(getRandomSource())->nextLong();
    return new ::rice::environment::random::simple::SimpleRandomSource(randSeed, lman);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::environment::Environment::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.environment.Environment", 28);
    return c;
}

void rice::environment::Environment::clinit()
{
    super::clinit();
    static bool in_cl_init = false;
struct clinit_ {
    clinit_() {
        in_cl_init = true;
        defaultParamFileArray__ = (new ::java::lang::StringArray({u"freepastry"_j}));
    }
};

    if(!in_cl_init) {
        static clinit_ clinit_instance;
    }
}

java::lang::Class* rice::environment::Environment::getClass0()
{
    return class_();
}

