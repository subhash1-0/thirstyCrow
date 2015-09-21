// Generated from /pastry-2.1/src/rice/environment/time/simulated/DirectTimeSource.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/fwd-pastry-2.1.hpp>
#include <rice/environment/params/fwd-pastry-2.1.hpp>
#include <rice/environment/time/simulated/fwd-pastry-2.1.hpp>
#include <rice/selector/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/environment/time/TimeSource.hpp>

struct default_init_tag;

class rice::environment::time::simulated::DirectTimeSource
    : public virtual ::java::lang::Object
    , public virtual ::rice::environment::time::TimeSource
{

public:
    typedef ::java::lang::Object super;

public: /* protected */
    int64_t time {  };
    ::rice::environment::logging::Logger* logger {  };
    ::java::lang::String* instance {  };
    ::rice::selector::SelectorManager* selectorManager {  };
    ::java::util::HashSet* pendingTimers {  };
protected:
    void ctor(int64_t time);
    void ctor(int64_t time, ::java::lang::String* instance);
    void ctor(::rice::environment::params::Parameters* p);

public:
    virtual void setLogManager(::rice::environment::logging::LogManager* manager);
    virtual void setSelectorManager(::rice::selector::SelectorManager* sm);
    int64_t currentTimeMillis() override;
    virtual void setTime(int64_t newTime);
    virtual void incrementTime(int32_t millis);
    void sleep(int64_t delay) /* throws(InterruptedException) */ override;
    void destroy() override;

    // Generated
    DirectTimeSource(int64_t time);
    DirectTimeSource(int64_t time, ::java::lang::String* instance);
    DirectTimeSource(::rice::environment::params::Parameters* p);
protected:
    DirectTimeSource(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    void init();
    virtual ::java::lang::Class* getClass0();
    friend class DirectTimeSource_BlockingTimerTask;
};
