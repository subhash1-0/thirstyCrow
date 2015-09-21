// Generated from /pastry-2.1/src/rice/selector/ProfileSelector.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/selector/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <java/util/Comparator.hpp>

struct default_init_tag;

class rice::selector::ProfileSelector_printStats_2
    : public virtual ::java::lang::Object
    , public virtual ::java::util::Comparator
{

public:
    typedef ::java::lang::Object super;
    bool equals(::java::lang::Object* arg0) override;
    virtual int32_t compare(ProfileSelector_Stat* arg0, ProfileSelector_Stat* arg1);

    // Generated
    ProfileSelector_printStats_2(ProfileSelector *ProfileSelector_this);
    static ::java::lang::Class *class_();
    virtual int32_t compare(::java::lang::Object* arg0, ::java::lang::Object* arg1) override;
    ProfileSelector *ProfileSelector_this;

private:
    virtual ::java::lang::Class* getClass0();
    friend class ProfileSelector;
    friend class ProfileSelector_ProfileSelector_1;
    friend class ProfileSelector_Stat;
};
