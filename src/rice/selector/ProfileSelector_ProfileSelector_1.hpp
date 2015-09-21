// Generated from /pastry-2.1/src/rice/selector/ProfileSelector.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <rice/selector/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/Runnable.hpp>

struct default_init_tag;

class rice::selector::ProfileSelector_ProfileSelector_1
    : public virtual ::java::lang::Object
    , public virtual ::java::lang::Runnable
{

public:
    typedef ::java::lang::Object super;
    void run() override;

    // Generated
    ProfileSelector_ProfileSelector_1(ProfileSelector *ProfileSelector_this, int32_t lastTaskTime);
    static ::java::lang::Class *class_();
    ProfileSelector *ProfileSelector_this;
    int32_t lastTaskTime;

private:
    virtual ::java::lang::Class* getClass0();
    friend class ProfileSelector;
    friend class ProfileSelector_printStats_2;
    friend class ProfileSelector_Stat;
};
