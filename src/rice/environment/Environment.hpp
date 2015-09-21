// Generated from /pastry-2.1/src/rice/environment/Environment.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/environment/exception/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/fwd-pastry-2.1.hpp>
#include <rice/environment/params/fwd-pastry-2.1.hpp>
#include <rice/environment/processing/fwd-pastry-2.1.hpp>
#include <rice/environment/random/fwd-pastry-2.1.hpp>
#include <rice/environment/time/fwd-pastry-2.1.hpp>
#include <rice/selector/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/Destructable.hpp>

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

struct default_init_tag;

class rice::environment::Environment
    : public virtual ::java::lang::Object
    , public virtual ::rice::Destructable
{

public:
    typedef ::java::lang::Object super;

private:
    static ::java::lang::StringArray* defaultParamFileArray__;
    ::rice::selector::SelectorManager* selectorManager {  };
    ::rice::environment::processing::Processor* processor {  };
    ::rice::environment::random::RandomSource* randomSource {  };
    ::rice::environment::time::TimeSource* time {  };
    ::rice::environment::logging::LogManager* logManager {  };
    ::rice::environment::params::Parameters* params {  };
    ::rice::environment::logging::Logger* logger {  };
    ::rice::environment::exception::ExceptionStrategy* exceptionStrategy {  };
    ::java::util::HashSet* destructables {  };
protected:
    void ctor(::rice::selector::SelectorManager* sm, ::rice::environment::processing::Processor* proc, ::rice::environment::random::RandomSource* rs, ::rice::environment::time::TimeSource* time, ::rice::environment::logging::LogManager* lm, ::rice::environment::params::Parameters* params, ::rice::environment::exception::ExceptionStrategy* strategy);
    void ctor(::java::lang::StringArray* orderedDefaultFiles, ::java::lang::String* paramFileName);

public:
    static Environment* directEnvironment(int32_t randomSeed);
    static Environment* directEnvironment();
    static Environment* directEnvironment(::rice::environment::random::RandomSource* rs);
protected:
    void ctor(::java::lang::String* paramFileName);
    void ctor();

public: /* protected */
    virtual void chooseDefaults();

public:
    static ::rice::environment::exception::ExceptionStrategy* generateDefaultExceptionStrategy(::rice::environment::logging::LogManager* manager);
    static ::rice::environment::random::RandomSource* generateDefaultRandomSource(::rice::environment::params::Parameters* params, ::rice::environment::logging::LogManager* logging);
    static ::rice::environment::time::TimeSource* generateDefaultTimeSource();
    static ::rice::environment::logging::LogManager* generateDefaultLogManager(::rice::environment::time::TimeSource* time, ::rice::environment::params::Parameters* params);
    static ::rice::selector::SelectorManager* generateDefaultSelectorManager(::rice::environment::time::TimeSource* time, ::rice::environment::logging::LogManager* logging, ::rice::environment::random::RandomSource* randomSource);
    static ::rice::environment::processing::Processor* generateDefaultProcessor();
    virtual ::rice::selector::SelectorManager* getSelectorManager();
    virtual ::rice::environment::processing::Processor* getProcessor();
    virtual ::rice::environment::random::RandomSource* getRandomSource();
    virtual ::rice::environment::time::TimeSource* getTimeSource();
    virtual ::rice::environment::logging::LogManager* getLogManager();
    virtual ::rice::environment::params::Parameters* getParameters();
    void destroy() override;

private:
    void callDestroyOnDestructables();

public:
    virtual void addDestructable(::rice::Destructable* destructable);
    virtual void removeDestructable(::rice::Destructable* destructable);
    virtual ::rice::environment::exception::ExceptionStrategy* getExceptionStrategy();
    virtual ::rice::environment::exception::ExceptionStrategy* setExceptionStrategy(::rice::environment::exception::ExceptionStrategy* newStrategy);
    virtual Environment* cloneEnvironment(::java::lang::String* prefix);
    virtual Environment* cloneEnvironment(::java::lang::String* prefix, bool cloneSelector, bool cloneProcessor);

public: /* protected */
    virtual ::rice::environment::time::TimeSource* cloneTimeSource(::rice::environment::logging::LogManager* lman);
    virtual ::rice::environment::logging::LogManager* cloneLogManager(::java::lang::String* prefix);
    virtual ::rice::selector::SelectorManager* cloneSelectorManager(::java::lang::String* prefix, ::rice::environment::time::TimeSource* ts, ::rice::environment::random::RandomSource* rs, ::rice::environment::logging::LogManager* lman, bool cloneSelector);
    virtual ::rice::environment::processing::Processor* cloneProcessor(::java::lang::String* prefix, ::rice::environment::logging::LogManager* lman, bool cloneProcessor);
    virtual ::rice::environment::random::RandomSource* cloneRandomSource(::rice::environment::logging::LogManager* lman);

    // Generated

public:
    Environment(::rice::selector::SelectorManager* sm, ::rice::environment::processing::Processor* proc, ::rice::environment::random::RandomSource* rs, ::rice::environment::time::TimeSource* time, ::rice::environment::logging::LogManager* lm, ::rice::environment::params::Parameters* params, ::rice::environment::exception::ExceptionStrategy* strategy);
    Environment(::java::lang::StringArray* orderedDefaultFiles, ::java::lang::String* paramFileName);
    Environment(::java::lang::String* paramFileName);
    Environment();
protected:
    Environment(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    static void clinit();

private:
    void init();

public:
    static ::java::lang::StringArray*& defaultParamFileArray_();

private:
    virtual ::java::lang::Class* getClass0();
    friend class Environment_destroy_1;
};
