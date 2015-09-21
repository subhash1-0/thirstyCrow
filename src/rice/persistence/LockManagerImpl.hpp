// Generated from /pastry-2.1/src/rice/persistence/LockManagerImpl.java

#pragma once

#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/persistence/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/persistence/LockManager.hpp>

struct default_init_tag;

class rice::persistence::LockManagerImpl
    : public virtual ::java::lang::Object
    , public virtual LockManager
{

public:
    typedef ::java::lang::Object super;

private:
    ::java::util::HashMap* locks {  };

public: /* protected */
    ::rice::environment::logging::Logger* logger {  };
protected:
    void ctor(::rice::environment::Environment* env);

public:
    void lock(::rice::p2p::commonapi::Id* id, ::rice::Continuation* c) override;
    void unlock(::rice::p2p::commonapi::Id* id) override;

    // Generated
    LockManagerImpl(::rice::environment::Environment* env);
protected:
    LockManagerImpl(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
