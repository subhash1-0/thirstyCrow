// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/util/MessageRequestHandleImpl.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/util/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/MessageRequestHandle.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::util::MessageRequestHandleImpl
    : public virtual ::java::lang::Object
    , public virtual ::org::mpisws::p2p::transport::MessageRequestHandle
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    ::rice::p2p::commonapi::Cancellable* subCancellable {  };
    ::java::lang::Object* identifier {  };
    ::java::lang::Object* msg {  };
    ::java::util::Map* options {  };
protected:
    void ctor(::java::lang::Object* i, ::java::lang::Object* m, ::java::util::Map* options);

public:
    ::java::lang::Object* getIdentifier() override;
    ::java::lang::Object* getMessage() override;
    ::java::util::Map* getOptions() override;
    bool cancel() override;
    virtual void setSubCancellable(::rice::p2p::commonapi::Cancellable* cancellable);
    virtual ::rice::p2p::commonapi::Cancellable* getSubCancellable();
    ::java::lang::String* toString() override;

    // Generated
    MessageRequestHandleImpl(::java::lang::Object* i, ::java::lang::Object* m, ::java::util::Map* options);
protected:
    MessageRequestHandleImpl(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
