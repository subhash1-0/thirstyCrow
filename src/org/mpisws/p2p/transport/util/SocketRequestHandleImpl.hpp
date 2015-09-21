// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/util/SocketRequestHandleImpl.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/util/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/SocketRequestHandle.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::util::SocketRequestHandleImpl
    : public virtual ::java::lang::Object
    , public virtual ::org::mpisws::p2p::transport::SocketRequestHandle
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    ::java::lang::Object* identifier {  };
    ::java::util::Map* options {  };
    ::rice::p2p::commonapi::Cancellable* subCancellable {  };
    ::rice::environment::logging::Logger* logger {  };
protected:
    void ctor(::java::lang::Object* i, ::java::util::Map* options, ::rice::environment::logging::Logger* logger);

public:
    ::java::lang::Object* getIdentifier() override;
    ::java::util::Map* getOptions() override;
    bool cancel() override;
    virtual void setSubCancellable(::rice::p2p::commonapi::Cancellable* sub);
    virtual ::rice::p2p::commonapi::Cancellable* getSubCancellable();
    ::java::lang::String* toString() override;

    // Generated
    SocketRequestHandleImpl(::java::lang::Object* i, ::java::util::Map* options, ::rice::environment::logging::Logger* logger);
protected:
    SocketRequestHandleImpl(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
