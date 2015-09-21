// Generated from /pastry-2.1/src/rice/p2p/scribe/ScribeImpl.java

#pragma once

#include <rice/p2p/scribe/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/Runnable.hpp>

struct default_init_tag;

class rice::p2p::scribe::ScribeImpl_destroy_2
    : public virtual ::java::lang::Object
    , public virtual ::java::lang::Runnable
{

public:
    typedef ::java::lang::Object super;
    void run() override;

    // Generated
    ScribeImpl_destroy_2(ScribeImpl *ScribeImpl_this);
    static ::java::lang::Class *class_();
    ScribeImpl *ScribeImpl_this;

private:
    virtual ::java::lang::Class* getClass0();
    friend class ScribeImpl;
    friend class ScribeImpl_ScribeImpl_1;
    friend class ScribeImpl_ScribeClientConverter;
    friend class ScribeImpl_TopicManager;
};
