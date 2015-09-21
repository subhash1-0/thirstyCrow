// Generated from /pastry-2.1/src/rice/environment/logging/HeirarchyLogger.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <rice/environment/logging/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/Logger.hpp>

struct default_init_tag;

class rice::environment::logging::HeirarchyLogger
    : public Logger
{

public:
    typedef Logger super;
    bool useDefault {  };

    // Generated
    HeirarchyLogger();
protected:
    void ctor();
    HeirarchyLogger(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    void init();
    virtual ::java::lang::Class* getClass0();
};
