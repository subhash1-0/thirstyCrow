// Generated from /pastry-2.1/src/rice/environment/logging/AbstractLogManager.java
#include <rice/environment/logging/AbstractLogManager_AbstractLogManager_1.hpp>

#include <java/lang/Boolean.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/util/Collection.hpp>
#include <java/util/Hashtable.hpp>
#include <java/util/Iterator.hpp>
#include <java/util/Set.hpp>
#include <rice/environment/logging/AbstractLogManager.hpp>
#include <rice/environment/logging/HeirarchyLogger.hpp>
#include <rice/environment/logging/Logger.hpp>

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
rice::environment::logging::AbstractLogManager_AbstractLogManager_1::AbstractLogManager_AbstractLogManager_1(AbstractLogManager *AbstractLogManager_this)
    : super(*static_cast< ::default_init_tag* >(0))
    , AbstractLogManager_this(AbstractLogManager_this)
{
    clinit();
    ctor();
}

void rice::environment::logging::AbstractLogManager_AbstractLogManager_1::parameterChange(::java::lang::String* paramName, ::java::lang::String* newVal)
{
    if(npc(paramName)->equals(static_cast< ::java::lang::Object* >(u"logging_enable"_j))) {
        AbstractLogManager_this->enabled = npc(::java::lang::Boolean::valueOf(newVal))->booleanValue();
    } else if(npc(paramName)->equals(static_cast< ::java::lang::Object* >(u"loglevel"_j))) {
        {
            synchronized synchronized_0(this);
            {
                AbstractLogManager_this->globalLogLevel = AbstractLogManager_this->parseVal(paramName);
                auto i = npc(npc(AbstractLogManager_this->loggers)->values())->iterator();
                while (npc(i)->hasNext()) {
                    auto hl = java_cast< HeirarchyLogger* >(java_cast< Logger* >(npc(i)->next()));
                    if(npc(hl)->useDefault) {
                        npc(hl)->level = AbstractLogManager_this->globalLogLevel;
                    }
                }
            }
        }
    } else if(npc(paramName)->endsWith(u"_loglevel"_j)) {
        auto loggerName = npc(paramName)->substring(0, npc(paramName)->length() - npc(u"_loglevel"_j)->length());
        if((newVal == nullptr) || (npc(newVal)->equals(static_cast< ::java::lang::Object* >(u""_j)))) {
            auto i = npc(npc(AbstractLogManager_this->loggers)->keySet())->iterator();
            while (npc(i)->hasNext()) {
                auto name = java_cast< ::java::lang::String* >(java_cast< ::java::lang::String* >(npc(i)->next()));
                if(npc(name)->startsWith(loggerName)) {
                    auto hl = java_cast< HeirarchyLogger* >(java_cast< Logger* >(npc(AbstractLogManager_this->loggers)->get(static_cast< ::java::lang::Object* >(name))));
                    npc(hl)->useDefault = true;
                    npc(hl)->level = AbstractLogManager_this->globalLogLevel;
                }
            }
        } else {
            auto i = npc(npc(AbstractLogManager_this->loggers)->keySet())->iterator();
            while (npc(i)->hasNext()) {
                auto name = java_cast< ::java::lang::String* >(java_cast< ::java::lang::String* >(npc(i)->next()));
                if(npc(name)->startsWith(loggerName)) {
                    auto hl = java_cast< HeirarchyLogger* >(java_cast< Logger* >(npc(AbstractLogManager_this->loggers)->get(static_cast< ::java::lang::Object* >(name))));
                    npc(hl)->useDefault = false;
                    npc(hl)->level = AbstractLogManager_this->parseVal(paramName);
                }
            }
        }
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::environment::logging::AbstractLogManager_AbstractLogManager_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::environment::logging::AbstractLogManager_AbstractLogManager_1::getClass0()
{
    return class_();
}

