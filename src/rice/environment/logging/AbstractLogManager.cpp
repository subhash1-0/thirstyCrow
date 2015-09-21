// Generated from /pastry-2.1/src/rice/environment/logging/AbstractLogManager.java
#include <rice/environment/logging/AbstractLogManager.hpp>

#include <java/io/FileNotFoundException.hpp>
#include <java/io/FileOutputStream.hpp>
#include <java/io/OutputStream.hpp>
#include <java/io/PrintStream.hpp>
#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/CharSequence.hpp>
#include <java/lang/Class.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Comparable.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/NumberFormatException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/RuntimeException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/System.hpp>
#include <java/lang/Throwable.hpp>
#include <java/text/SimpleDateFormat.hpp>
#include <java/util/Hashtable.hpp>
#include <javax/swing/text/DateFormatter.hpp>
#include <rice/environment/logging/AbstractLogManager_AbstractLogManager_1.hpp>
#include <rice/environment/logging/AbstractLogManager_NullOutputStream.hpp>
#include <rice/environment/logging/InvalidLogLevelException.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/environment/params/Parameters.hpp>
#include <rice/environment/time/TimeSource.hpp>
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

rice::environment::logging::AbstractLogManager::AbstractLogManager(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::environment::logging::AbstractLogManager::AbstractLogManager(::java::io::PrintStream* stream, ::rice::environment::time::TimeSource* timeSource, ::rice::environment::params::Parameters* params, ::java::lang::String* prefix, ::java::lang::String* df) 
    : AbstractLogManager(*static_cast< ::default_init_tag* >(0))
{
    ctor(stream,timeSource,params,prefix,df);
}

void rice::environment::logging::AbstractLogManager::init()
{
    packageOnly = true;
}

java::io::PrintStream*& rice::environment::logging::AbstractLogManager::nullPrintStream()
{
    clinit();
    return nullPrintStream_;
}
java::io::PrintStream* rice::environment::logging::AbstractLogManager::nullPrintStream_;

java::lang::String*& rice::environment::logging::AbstractLogManager::SYSTEM_OUT()
{
    clinit();
    return SYSTEM_OUT_;
}
java::lang::String* rice::environment::logging::AbstractLogManager::SYSTEM_OUT_;

java::lang::String*& rice::environment::logging::AbstractLogManager::SYSTEM_ERR()
{
    clinit();
    return SYSTEM_ERR_;
}
java::lang::String* rice::environment::logging::AbstractLogManager::SYSTEM_ERR_;

void rice::environment::logging::AbstractLogManager::ctor(::java::io::PrintStream* stream, ::rice::environment::time::TimeSource* timeSource, ::rice::environment::params::Parameters* params, ::java::lang::String* prefix, ::java::lang::String* df)
{
    super::ctor();
    init();
    this->ps = stream;
    if(ps == nullptr) {
        ps = ::java::lang::System::out();
        if(npc(params)->contains(u"logging_output_stream"_j)) {
            auto loggingType = npc(params)->getString(u"logging_output_stream"_j);
            if(npc(loggingType)->equals(static_cast< ::java::lang::Object* >(SYSTEM_OUT_))) {
                ps = ::java::lang::System::out();
            } else if(npc(loggingType)->equals(static_cast< ::java::lang::Object* >(SYSTEM_ERR_))) {
                ps = ::java::lang::System::err();
            } else {
                try {
                    ps = new ::java::io::PrintStream(static_cast< ::java::io::OutputStream* >(new ::java::io::FileOutputStream(loggingType, true)));
                } catch (::java::io::FileNotFoundException* fnfe) {
                    throw new ::java::lang::RuntimeException(static_cast< ::java::lang::Throwable* >(fnfe));
                }
            }
        }
    }
    this->time = timeSource;
    this->params = params;
    this->prefix = prefix;
    this->dateFormat = df;
    if(this->dateFormat == nullptr) {
        this->dateFormat = npc(params)->getString(u"logging_date_format"_j);
    }
    if(this->dateFormat != nullptr && !npc(this->dateFormat)->equals(static_cast< ::java::lang::Object* >(u""_j))) {
        dateFormatter = new ::javax::swing::text::DateFormatter(new ::java::text::SimpleDateFormat(this->dateFormat));
    }
    this->enabled = npc(params)->getBoolean(u"logging_enable"_j);
    if(npc(params)->contains(u"logging_packageOnly"_j)) {
        this->packageOnly = npc(params)->getBoolean(u"logging_packageOnly"_j);
    }
    this->loggers = new ::java::util::Hashtable();
    this->globalLogLevel = parseVal(u"loglevel"_j);
    npc(params)->addChangeListener(new AbstractLogManager_AbstractLogManager_1(this));
}

int32_t rice::environment::logging::AbstractLogManager::parseVal(::java::lang::String* key)
{
    try {
        return npc(params)->getInt(key);
    } catch (::java::lang::NumberFormatException* nfe) {
        auto val = npc(params)->getString(key);
        if(npc(val)->equalsIgnoreCase(u"ALL"_j))
            return Logger::ALL;

        if(npc(val)->equalsIgnoreCase(u"OFF"_j))
            return Logger::OFF;

        if(npc(val)->equalsIgnoreCase(u"SEVERE"_j))
            return Logger::SEVERE;

        if(npc(val)->equalsIgnoreCase(u"WARNING"_j))
            return Logger::WARNING;

        if(npc(val)->equalsIgnoreCase(u"INFO"_j))
            return Logger::INFO;

        if(npc(val)->equalsIgnoreCase(u"CONFIG"_j))
            return Logger::CONFIG;

        if(npc(val)->equalsIgnoreCase(u"FINE"_j))
            return Logger::FINE;

        if(npc(val)->equalsIgnoreCase(u"FINER"_j))
            return Logger::FINER;

        if(npc(val)->equalsIgnoreCase(u"FINEST"_j))
            return Logger::FINEST;

        throw new InvalidLogLevelException(key, val);
    }
}

rice::environment::logging::Logger* rice::environment::logging::AbstractLogManager::getLogger(::java::lang::Class* clazz, ::java::lang::String* instance)
{
    ::java::lang::String* loggerName;
    auto className = npc(clazz)->getName();
    ::java::lang::StringArray* parts = nullptr;
    if(packageOnly) {
        parts = npc(className)->split(u"\\."_j);
        loggerName = (*parts)[int32_t(0)];
        for (auto curPart = int32_t(1); curPart < npc(parts)->length - int32_t(1); curPart++) {
            loggerName = ::java::lang::StringBuilder(loggerName).append(::java::lang::StringBuilder().append(u"."_j)->append((*parts)[curPart])->toString())->toString();
        }
    } else {
        loggerName = className;
    }
    if(instance != nullptr) {
        loggerName = ::java::lang::StringBuilder().append(loggerName)->append(u"@"_j)
            ->append(instance)->toString();
    }
    if(npc(loggers)->containsKey(static_cast< ::java::lang::Object* >(loggerName))) {
        return java_cast< Logger* >(java_cast< Logger* >(npc(loggers)->get(static_cast< ::java::lang::Object* >(loggerName))));
    }
    if(parts == nullptr)
        parts = npc(className)->split(u"\\."_j);

    auto level = globalLogLevel;
    auto useDefault = true;
    ::java::lang::String* baseStr;
    auto lastPart = npc(parts)->length;
    if(packageOnly)
        lastPart--;

    for (auto numParts = lastPart; numParts >= 0; numParts--) {
        baseStr = (*parts)[int32_t(0)];
        for (auto curPart = int32_t(1); curPart < numParts; curPart++) {
            baseStr = ::java::lang::StringBuilder(baseStr).append(::java::lang::StringBuilder().append(u"."_j)->append((*parts)[curPart])->toString())->toString();
        }
        if(instance != nullptr) {
            auto searchString = ::java::lang::StringBuilder().append(baseStr)->append(u"@"_j)
                ->append(instance)
                ->append(u"_loglevel"_j)->toString();
            if(npc(params)->contains(searchString)) {
                level = parseVal(searchString);
                useDefault = false;
                break;
            }
        }
        auto searchString = ::java::lang::StringBuilder().append(baseStr)->append(u"_loglevel"_j)->toString();
        if(npc(params)->contains(searchString)) {
            level = parseVal(searchString);
            useDefault = false;
            break;
        }
    }
    auto logger = constructLogger(loggerName, level, useDefault);
    npc(loggers)->put(static_cast< ::java::lang::Object* >(loggerName), static_cast< ::java::lang::Object* >(logger));
    return logger;
}

rice::environment::time::TimeSource* rice::environment::logging::AbstractLogManager::getTimeSource()
{
    return time;
}

java::io::PrintStream* rice::environment::logging::AbstractLogManager::getPrintStream()
{
    if(enabled) {
        return ps;
    } else {
        return nullPrintStream_;
    }
}

java::lang::String* rice::environment::logging::AbstractLogManager::getPrefix()
{
    return prefix;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::environment::logging::AbstractLogManager::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.environment.logging.AbstractLogManager", 43);
    return c;
}

void rice::environment::logging::AbstractLogManager::clinit()
{
struct string_init_ {
    string_init_() {
    SYSTEM_OUT_ = u"System.out"_j;
    SYSTEM_ERR_ = u"System.err"_j;
    }
};

    static string_init_ string_init_instance;

    super::clinit();
    static bool in_cl_init = false;
struct clinit_ {
    clinit_() {
        in_cl_init = true;
        nullPrintStream_ = new ::java::io::PrintStream(static_cast< ::java::io::OutputStream* >(new AbstractLogManager_NullOutputStream()));
    }
};

    if(!in_cl_init) {
        static clinit_ clinit_instance;
    }
}

java::lang::Class* rice::environment::logging::AbstractLogManager::getClass0()
{
    return class_();
}

