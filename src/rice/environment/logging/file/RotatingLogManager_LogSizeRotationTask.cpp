// Generated from /pastry-2.1/src/rice/environment/logging/file/RotatingLogManager.java
#include <rice/environment/logging/file/RotatingLogManager_LogSizeRotationTask.hpp>

#include <java/io/File.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/String.hpp>
#include <rice/environment/logging/file/RotatingLogManager.hpp>
#include <rice/environment/params/Parameters.hpp>

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
rice::environment::logging::file::RotatingLogManager_LogSizeRotationTask::RotatingLogManager_LogSizeRotationTask(RotatingLogManager *RotatingLogManager_this, const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
    , RotatingLogManager_this(RotatingLogManager_this)
{
    clinit();
}

rice::environment::logging::file::RotatingLogManager_LogSizeRotationTask::RotatingLogManager_LogSizeRotationTask(RotatingLogManager *RotatingLogManager_this)
    : RotatingLogManager_LogSizeRotationTask(RotatingLogManager_this, *static_cast< ::default_init_tag* >(0))
{
    ctor();
}

void rice::environment::logging::file::RotatingLogManager_LogSizeRotationTask::run()
{
    {
        synchronized synchronized_0(RotatingLogManager_this);
        {
            if((new ::java::io::File(npc(RotatingLogManager_this->params)->getString(u"log_rotate_filename"_j)))->length() >= npc(RotatingLogManager_this->params)->getLong(u"log_rotate_max_size"_j))
                RotatingLogManager_this->rotate();

        }
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::environment::logging::file::RotatingLogManager_LogSizeRotationTask::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.environment.logging.file.RotatingLogManager.LogSizeRotationTask", 68);
    return c;
}

java::lang::Class* rice::environment::logging::file::RotatingLogManager_LogSizeRotationTask::getClass0()
{
    return class_();
}

