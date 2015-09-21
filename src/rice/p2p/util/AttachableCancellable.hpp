// Generated from /pastry-2.1/src/rice/p2p/util/AttachableCancellable.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/util/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/p2p/commonapi/Cancellable.hpp>

struct default_init_tag;

class rice::p2p::util::AttachableCancellable
    : public virtual ::java::lang::Object
    , public virtual ::rice::p2p::commonapi::Cancellable
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    ::java::util::Collection* subCancellable {  };

public:
    virtual bool isCancelled();
    bool cancel() override;
    virtual void attach(::rice::p2p::commonapi::Cancellable* c);
    virtual void detach(::rice::p2p::commonapi::Cancellable* c);

    // Generated
    AttachableCancellable();
protected:
    void ctor();
    AttachableCancellable(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    void init();
    virtual ::java::lang::Class* getClass0();
};
