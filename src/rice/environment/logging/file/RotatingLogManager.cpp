// Generated from /pastry-2.1/src/rice/environment/logging/file/RotatingLogManager.java
#include <rice/environment/logging/file/RotatingLogManager.hpp>

#include <java/io/File.hpp>
#include <java/io/FileNotFoundException.hpp>
#include <java/io/FileOutputStream.hpp>
#include <java/io/OutputStream.hpp>
#include <java/io/PrintStream.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/RuntimeException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/System.hpp>
#include <java/text/ParseException.hpp>
#include <java/text/SimpleDateFormat.hpp>
#include <java/util/Date.hpp>
#include <javax/swing/text/DateFormatter.hpp>
#include <rice/environment/logging/AbstractLogManager.hpp>
#include <rice/environment/logging/file/RotatingLogManager_LogRotationTask.hpp>
#include <rice/environment/logging/file/RotatingLogManager_LogSizeRotationTask.hpp>
#include <rice/environment/logging/simple/SimpleLogger.hpp>
#include <rice/environment/params/Parameters.hpp>
#include <rice/selector/SelectorManager.hpp>
#include <rice/selector/Timer.hpp>
#include <rice/selector/TimerTask.hpp>

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
rice::environment::logging::file::RotatingLogManager::RotatingLogManager(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::environment::logging::file::RotatingLogManager::RotatingLogManager(::rice::environment::time::TimeSource* timeSource, ::rice::environment::params::Parameters* params) 
    : RotatingLogManager(*static_cast< ::default_init_tag* >(0))
{
    ctor(timeSource,params);
}

rice::environment::logging::file::RotatingLogManager::RotatingLogManager(::rice::environment::time::TimeSource* timeSource, ::rice::environment::params::Parameters* params, ::java::lang::String* prefix, ::java::lang::String* dateFormat) 
    : RotatingLogManager(*static_cast< ::default_init_tag* >(0))
{
    ctor(timeSource,params,prefix,dateFormat);
}

void rice::environment::logging::file::RotatingLogManager::ctor(::rice::environment::time::TimeSource* timeSource, ::rice::environment::params::Parameters* params)
{
    ctor(timeSource, params, u""_j, nullptr);
}

void rice::environment::logging::file::RotatingLogManager::ctor(::rice::environment::time::TimeSource* timeSource, ::rice::environment::params::Parameters* params, ::java::lang::String* prefix, ::java::lang::String* dateFormat)
{
    super::ctor(::rice::environment::logging::AbstractLogManager::nullPrintStream(), timeSource, params, prefix, dateFormat);
    rotate();
}

void rice::environment::logging::file::RotatingLogManager::startRotateTask(::rice::selector::SelectorManager* sm)
{
    if(rotateTask == nullptr) {
        rotateTask = new RotatingLogManager_LogRotationTask(this);
        npc(npc(sm)->getTimer())->schedule(rotateTask, npc(params)->getInt(u"log_rotate_interval"_j), npc(params)->getInt(u"log_rotate_interval"_j));
        if(npc(params)->contains(u"log_rotate_size_check_interval"_j) && sizeRotateTask == nullptr) {
            sizeRotateTask = new RotatingLogManager_LogSizeRotationTask(this);
            npc(npc(sm)->getTimer())->schedule(sizeRotateTask, npc(params)->getInt(u"log_rotate_size_check_interval"_j), npc(params)->getInt(u"log_rotate_size_check_interval"_j));
        }
    } else {
        throw new ::java::lang::RuntimeException(u"Task already started"_j);
    }
}

void rice::environment::logging::file::RotatingLogManager::cancelRotateTask()
{
    npc(rotateTask)->cancel();
    rotateTask = nullptr;
}

void rice::environment::logging::file::RotatingLogManager::rotate()
{
    {
        synchronized synchronized_0(this);
        {
            auto oldps = super::ps;
            auto dateFormat = npc(params)->getString(u"log_rotating_date_format"_j);
            ::javax::swing::text::DateFormatter* dateFormatter = nullptr;
            if(dateFormat != nullptr && !npc(dateFormat)->equals(static_cast< ::java::lang::Object* >(u""_j))) {
                dateFormatter = new ::javax::swing::text::DateFormatter(new ::java::text::SimpleDateFormat(dateFormat));
            }
            npc(::java::lang::System::out())->println(u"rotate: about to rotate log"_j);
            auto filename = npc(params)->getString(u"log_rotate_filename"_j);
            auto oldfile = new ::java::io::File(filename);
            if(npc(oldfile)->exists()) {
                auto filedate = npc(oldfile)->lastModified();
                auto rot_filename = ::java::lang::StringBuilder().append(filename)->append(u"."_j)
                    ->append(filedate)->toString();
                if(dateFormatter != nullptr) {
                    try {
                        rot_filename = ::java::lang::StringBuilder().append(filename)->append(u"."_j)
                            ->append(npc(dateFormatter)->valueToString(static_cast< ::java::lang::Object* >(new ::java::util::Date(filedate))))->toString();
                    } catch (::java::text::ParseException* pe) {
                        npc(pe)->printStackTrace();
                    }
                }
                npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"rotate: renaming "_j)->append(filename)
                    ->append(u" to "_j)
                    ->append(rot_filename)->toString());
                if(oldps != nullptr)
                    npc(oldps)->close();

                auto result = npc(oldfile)->renameTo(new ::java::io::File(rot_filename));
            }
            try {
                ps = new ::java::io::PrintStream(static_cast< ::java::io::OutputStream* >(new ::java::io::FileOutputStream(oldfile, true)), true);
            } catch (::java::io::FileNotFoundException* e) {
                npc(::java::lang::System::err())->println(::java::lang::StringBuilder().append(u"could not rotate log "_j)->append(filename)
                    ->append(u" because of "_j)
                    ->append(static_cast< ::java::lang::Object* >(e))->toString());
            }
            npc(::java::lang::System::out())->println(u"rotate: starting new log"_j);
        }
    }
}

java::io::PrintStream* rice::environment::logging::file::RotatingLogManager::getPrintStream()
{
    {
        synchronized synchronized_1(this);
        {
            if(enabled) {
                return ps;
            } else {
                return nullPrintStream();
            }
        }
    }
}

rice::environment::logging::Logger* rice::environment::logging::file::RotatingLogManager::constructLogger(::java::lang::String* clazz, int32_t level, bool useDefault)
{
    return new ::rice::environment::logging::simple::SimpleLogger(clazz, this, level, useDefault);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::environment::logging::file::RotatingLogManager::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.environment.logging.file.RotatingLogManager", 48);
    return c;
}

java::lang::Class* rice::environment::logging::file::RotatingLogManager::getClass0()
{
    return class_();
}

