// Generated from /pastry-2.1/src/rice/environment/logging/simple/SimpleLogger.java
#include <rice/environment/logging/simple/SimpleLogger.hpp>

#include <java/io/PrintStream.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/Throwable.hpp>
#include <java/text/ParseException.hpp>
#include <java/util/Date.hpp>
#include <javax/swing/text/DateFormatter.hpp>
#include <rice/environment/logging/AbstractLogManager.hpp>
#include <rice/environment/time/TimeSource.hpp>

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
rice::environment::logging::simple::SimpleLogger::SimpleLogger(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::environment::logging::simple::SimpleLogger::SimpleLogger(::java::lang::String* loggerName, ::rice::environment::logging::AbstractLogManager* alm, int32_t level, bool useDefault) 
    : SimpleLogger(*static_cast< ::default_init_tag* >(0))
{
    ctor(loggerName,alm,level,useDefault);
}

void rice::environment::logging::simple::SimpleLogger::ctor(::java::lang::String* loggerName, ::rice::environment::logging::AbstractLogManager* alm, int32_t level, bool useDefault)
{
    super::ctor();
    this->loggerName = loggerName;
    this->alm = alm;
    this->level = level;
    this->useDefault = useDefault;
}

void rice::environment::logging::simple::SimpleLogger::log(::java::lang::String* message)
{
    {
        synchronized synchronized_0(alm);
        {
            auto dateString = ::java::lang::StringBuilder().append(u""_j)->append(npc(npc(alm)->getTimeSource())->currentTimeMillis())->toString();
            if(npc(alm)->dateFormatter != nullptr) {
                try {
                    auto date = new ::java::util::Date(npc(npc(alm)->getTimeSource())->currentTimeMillis());
                    dateString = npc(npc(alm)->dateFormatter)->valueToString(static_cast< ::java::lang::Object* >(date));
                } catch (::java::text::ParseException* pe) {
                    npc(pe)->printStackTrace();
                }
            }
            npc(npc(alm)->getPrintStream())->println(::java::lang::StringBuilder().append(npc(alm)->getPrefix())->append(u":"_j)
                ->append(loggerName)
                ->append(u":"_j)
                ->append(dateString)
                ->append(u":"_j)
                ->append(message)->toString());
        }
    }
}

void rice::environment::logging::simple::SimpleLogger::logException(::java::lang::String* message, ::java::lang::Throwable* exception)
{
    {
        synchronized synchronized_1(alm);
        {
            auto dateString = ::java::lang::StringBuilder().append(u""_j)->append(npc(npc(alm)->getTimeSource())->currentTimeMillis())->toString();
            if(npc(alm)->dateFormatter != nullptr) {
                try {
                    auto date = new ::java::util::Date(npc(npc(alm)->getTimeSource())->currentTimeMillis());
                    dateString = npc(npc(alm)->dateFormatter)->valueToString(static_cast< ::java::lang::Object* >(date));
                } catch (::java::text::ParseException* pe) {
                    npc(pe)->printStackTrace();
                }
            }
            npc(npc(alm)->getPrintStream())->print(::java::lang::StringBuilder().append(npc(alm)->getPrefix())->append(u":"_j)
                ->append(loggerName)
                ->append(u":"_j)
                ->append(dateString)
                ->append(u":"_j)
                ->append(message)
                ->append(u" "_j)->toString());
            if(exception != nullptr)
                npc(exception)->printStackTrace(npc(alm)->getPrintStream());

        }
    }
}

java::lang::String* rice::environment::logging::simple::SimpleLogger::toString()
{
    return loggerName;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::environment::logging::simple::SimpleLogger::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.environment.logging.simple.SimpleLogger", 44);
    return c;
}

void rice::environment::logging::simple::SimpleLogger::log(int32_t priority, ::java::lang::String* message)
{
    super::log(priority, message);
}

void rice::environment::logging::simple::SimpleLogger::logException(int32_t priority, ::java::lang::String* message, ::java::lang::Throwable* exception)
{
    super::logException(priority, message, exception);
}

java::lang::Class* rice::environment::logging::simple::SimpleLogger::getClass0()
{
    return class_();
}

