// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/direct/EventSimulator.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/direct/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/fwd-pastry-2.1.hpp>
#include <rice/environment/random/fwd-pastry-2.1.hpp>
#include <rice/environment/time/fwd-pastry-2.1.hpp>
#include <rice/selector/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::direct::EventSimulator
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;

public: /* protected */
    ::rice::environment::Environment* environment {  };
    ::rice::environment::random::RandomSource* random {  };
    ::rice::selector::SelectorManager* manager {  };

private:
    bool isDirectTimeSource {  };

public: /* protected */
    ::rice::environment::time::TimeSource* timeSource {  };
    ::rice::environment::logging::Logger* logger {  };
protected:
    void ctor(::rice::environment::Environment* env, ::rice::environment::random::RandomSource* random, ::rice::environment::logging::Logger* logger);

public: /* package */
    int64_t maxSpeedRequestSystemTime {  };
    int64_t maxSpeedRequestSimTime {  };
    float maxSpeed {  };
    bool printedDirectTimeSourceWarning {  };

public:
    virtual void setMaxSpeed(float speed);
    virtual void setFullSpeed();

public: /* protected */
    virtual bool simulate() /* throws(InterruptedException) */;

public: /* package */
    bool running {  };

public:
    virtual void start();
    virtual void stop();

    // Generated
    EventSimulator(::rice::environment::Environment* env, ::rice::environment::random::RandomSource* random, ::rice::environment::logging::Logger* logger);
protected:
    EventSimulator(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    void init();
    virtual ::java::lang::Class* getClass0();
    friend class EventSimulator_start_1;
    friend class EventSimulator_start_1_run_1_1;
    friend class EventSimulator_stop_2;
};
