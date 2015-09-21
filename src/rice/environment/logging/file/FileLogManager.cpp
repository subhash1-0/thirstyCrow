// Generated from /pastry-2.1/src/rice/environment/logging/file/FileLogManager.java
#include <rice/environment/logging/file/FileLogManager.hpp>

#include <java/io/FileOutputStream.hpp>
#include <java/io/IOException.hpp>
#include <java/io/OutputStream.hpp>
#include <java/io/PrintStream.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/RuntimeException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/System.hpp>
#include <java/lang/Throwable.hpp>
#include <rice/environment/logging/LogManager.hpp>
#include <rice/environment/params/Parameters.hpp>
#include <rice/environment/time/simple/SimpleTimeSource.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::environment::logging::file::FileLogManager::FileLogManager(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::environment::logging::file::FileLogManager::FileLogManager(::java::io::PrintStream* stream, ::rice::environment::time::TimeSource* timeSource, ::rice::environment::params::Parameters* params) 
    : FileLogManager(*static_cast< ::default_init_tag* >(0))
{
    ctor(stream,timeSource,params);
}

rice::environment::logging::file::FileLogManager::FileLogManager(::java::io::PrintStream* stream, ::rice::environment::time::TimeSource* timeSource, ::rice::environment::params::Parameters* params, ::java::lang::String* prefix) 
    : FileLogManager(*static_cast< ::default_init_tag* >(0))
{
    ctor(stream,timeSource,params,prefix);
}

rice::environment::logging::file::FileLogManager::FileLogManager(::java::io::PrintStream* stream, ::rice::environment::time::TimeSource* timeSource, ::rice::environment::params::Parameters* params, ::java::lang::String* prefix, ::java::lang::String* filePrefix, ::java::lang::String* fileSuffix, ::java::lang::String* dateFormat) 
    : FileLogManager(*static_cast< ::default_init_tag* >(0))
{
    ctor(stream,timeSource,params,prefix,filePrefix,fileSuffix,dateFormat);
}

rice::environment::logging::file::FileLogManager::FileLogManager(::rice::environment::params::Parameters* params) 
    : FileLogManager(*static_cast< ::default_init_tag* >(0))
{
    ctor(params);
}

rice::environment::logging::file::FileLogManager::FileLogManager(::java::io::PrintStream* stream, ::rice::environment::params::Parameters* params) 
    : FileLogManager(*static_cast< ::default_init_tag* >(0))
{
    ctor(stream,params);
}

rice::environment::logging::file::FileLogManager::FileLogManager(::rice::environment::time::TimeSource* timeSource, ::rice::environment::params::Parameters* params) 
    : FileLogManager(*static_cast< ::default_init_tag* >(0))
{
    ctor(timeSource,params);
}

void rice::environment::logging::file::FileLogManager::ctor(::java::io::PrintStream* stream, ::rice::environment::time::TimeSource* timeSource, ::rice::environment::params::Parameters* params)
{
    ctor(stream, timeSource, params, u""_j);
}

void rice::environment::logging::file::FileLogManager::ctor(::java::io::PrintStream* stream, ::rice::environment::time::TimeSource* timeSource, ::rice::environment::params::Parameters* params, ::java::lang::String* prefix)
{
    ctor(stream, timeSource, params, prefix, npc(params)->getString(u"fileLogManager_filePrefix"_j), npc(params)->getString(u"fileLogManager_fileSuffix"_j), nullptr);
}

void rice::environment::logging::file::FileLogManager::ctor(::java::io::PrintStream* stream, ::rice::environment::time::TimeSource* timeSource, ::rice::environment::params::Parameters* params, ::java::lang::String* prefix, ::java::lang::String* filePrefix, ::java::lang::String* fileSuffix, ::java::lang::String* dateFormat)
{
    super::ctor(stream, timeSource, params, prefix, dateFormat);
    this->filePrefix = filePrefix;
    this->fileSuffix = fileSuffix;
}

void rice::environment::logging::file::FileLogManager::ctor(::rice::environment::params::Parameters* params)
{
    ctor(getDefaultPrintStream(params), new ::rice::environment::time::simple::SimpleTimeSource(), params);
}

void rice::environment::logging::file::FileLogManager::ctor(::java::io::PrintStream* stream, ::rice::environment::params::Parameters* params)
{
    ctor(stream, new ::rice::environment::time::simple::SimpleTimeSource(), params);
}

void rice::environment::logging::file::FileLogManager::ctor(::rice::environment::time::TimeSource* timeSource, ::rice::environment::params::Parameters* params)
{
    ctor(getDefaultPrintStream(params), timeSource, params);
}

java::io::PrintStream* rice::environment::logging::file::FileLogManager::getDefaultPrintStream(::rice::environment::params::Parameters* params)
{
    clinit();
    return getPrintStream(npc(params)->getString(u"fileLogManager_filePrefix"_j), npc(params)->getString(u"fileLogManager_defaultFileName"_j), npc(params)->getString(u"fileLogManager_fileSuffix"_j), !npc(params)->getBoolean(u"fileLogManager_overwrite_existing_log_file"_j));
}

java::io::PrintStream* rice::environment::logging::file::FileLogManager::getPrintStream(::java::lang::String* filePrefix, ::java::lang::String* detail, ::java::lang::String* fileSuffix, bool append)
{
    clinit();
    auto newPS = ::java::lang::System::out();
    try {
        auto fname = ::java::lang::StringBuilder().append(filePrefix)->append(detail)
            ->append(fileSuffix)->toString();
        newPS = new ::java::io::PrintStream(static_cast< ::java::io::OutputStream* >(new ::java::io::FileOutputStream(fname, append)));
    } catch (::java::io::IOException* ioe) {
        throw new ::java::lang::RuntimeException(static_cast< ::java::lang::Throwable* >(ioe));
    }
    return newPS;
}

rice::environment::logging::LogManager* rice::environment::logging::file::FileLogManager::clone(::java::lang::String* detail)
{
    auto newPS = this->ps;
    auto append = !npc(params)->getBoolean(u"fileLogManager_overwrite_existing_log_file"_j);
    if(npc(params)->getBoolean(u"fileLogManager_multipleFiles"_j)) {
        newPS = getPrintStream(filePrefix, detail, fileSuffix, append);
    }
    auto linePrefix = u""_j;
    if(npc(params)->getBoolean(u"fileLogManager_keepLinePrefix"_j)) {
        linePrefix = detail;
    }
    return new FileLogManager(newPS, time, params, linePrefix, filePrefix, fileSuffix, dateFormat);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::environment::logging::file::FileLogManager::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.environment.logging.file.FileLogManager", 44);
    return c;
}

rice::environment::logging::LogManager* rice::environment::logging::file::FileLogManager::clone(::java::lang::String* detail, ::rice::environment::time::TimeSource* ts)
{
    return super::clone(detail, ts);
}

java::io::PrintStream* rice::environment::logging::file::FileLogManager::getPrintStream()
{
    return super::getPrintStream();
}

java::lang::Object* rice::environment::logging::file::FileLogManager::clone()
{
    return super::clone();
}

java::lang::Class* rice::environment::logging::file::FileLogManager::getClass0()
{
    return class_();
}

