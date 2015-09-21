// Generated from /pastry-2.1/src/rice/p2p/util/TimerWeakHashMap.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/p2p/util/fwd-pastry-2.1.hpp>
#include <rice/selector/TimerTask.hpp>

struct default_init_tag;

class rice::p2p::util::TimerWeakHashMap_HardLinkTimerTask
    : public ::rice::selector::TimerTask
{

public:
    typedef ::rice::selector::TimerTask super;

public: /* package */
    ::java::lang::Object* hardLink {  };
protected:
    void ctor(::java::lang::Object* hardLink);

public:
    void run() override;

    // Generated
    TimerWeakHashMap_HardLinkTimerTask(::java::lang::Object* hardLink);
protected:
    TimerWeakHashMap_HardLinkTimerTask(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
    friend class TimerWeakHashMap;
};
