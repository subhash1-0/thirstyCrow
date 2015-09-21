// Generated from /pastry-2.1/src/rice/environment/logging/file/RotatingLogManager.java

#pragma once

#include <rice/environment/logging/file/fwd-pastry-2.1.hpp>
#include <rice/selector/TimerTask.hpp>

struct default_init_tag;

class rice::environment::logging::file::RotatingLogManager_LogRotationTask
    : public ::rice::selector::TimerTask
{

public:
    typedef ::rice::selector::TimerTask super;
    void run() override;

    // Generated
    RotatingLogManager_LogRotationTask(RotatingLogManager *RotatingLogManager_this);
protected:
    RotatingLogManager_LogRotationTask(RotatingLogManager *RotatingLogManager_this, const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    RotatingLogManager *RotatingLogManager_this;

private:
    virtual ::java::lang::Class* getClass0();
    friend class RotatingLogManager;
    friend class RotatingLogManager_LogSizeRotationTask;
};
