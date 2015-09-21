// Generated from /pastry-2.1/src/rice/p2p/util/TimerWeakHashMap.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/p2p/util/fwd-pastry-2.1.hpp>
#include <rice/selector/fwd-pastry-2.1.hpp>
#include <java/util/WeakHashMap.hpp>

struct default_init_tag;

class rice::p2p::util::TimerWeakHashMap
    : public ::java::util::WeakHashMap
{

public:
    typedef ::java::util::WeakHashMap super;

public: /* package */
    int32_t defaultDelay {  };
    ::rice::selector::Timer* timer {  };
protected:
    void ctor(::rice::selector::Timer* t, int32_t delay);

public:
    ::java::lang::Object* put(::java::lang::Object* key, ::java::lang::Object* val) override;
    virtual void refresh(::java::lang::Object* key);
    virtual void refresh(::java::lang::Object* key, int32_t delay);

    // Generated
    TimerWeakHashMap(::rice::selector::Timer* t, int32_t delay);
protected:
    TimerWeakHashMap(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
    friend class TimerWeakHashMap_HardLinkTimerTask;
};
