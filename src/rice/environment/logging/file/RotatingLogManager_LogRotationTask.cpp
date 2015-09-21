// Generated from /pastry-2.1/src/rice/environment/logging/file/RotatingLogManager.java
#include <rice/environment/logging/file/RotatingLogManager_LogRotationTask.hpp>

#include <rice/environment/logging/file/RotatingLogManager.hpp>

rice::environment::logging::file::RotatingLogManager_LogRotationTask::RotatingLogManager_LogRotationTask(RotatingLogManager *RotatingLogManager_this, const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
    , RotatingLogManager_this(RotatingLogManager_this)
{
    clinit();
}

rice::environment::logging::file::RotatingLogManager_LogRotationTask::RotatingLogManager_LogRotationTask(RotatingLogManager *RotatingLogManager_this)
    : RotatingLogManager_LogRotationTask(RotatingLogManager_this, *static_cast< ::default_init_tag* >(0))
{
    ctor();
}

void rice::environment::logging::file::RotatingLogManager_LogRotationTask::run()
{
    RotatingLogManager_this->rotate();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::environment::logging::file::RotatingLogManager_LogRotationTask::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.environment.logging.file.RotatingLogManager.LogRotationTask", 64);
    return c;
}

java::lang::Class* rice::environment::logging::file::RotatingLogManager_LogRotationTask::getClass0()
{
    return class_();
}

