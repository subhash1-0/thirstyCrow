// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/direct/DirectTransportLayer.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/direct/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/p2p/commonapi/Cancellable.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::direct::DirectTransportLayer_CancelAndClose
    : public virtual ::java::lang::Object
    , public virtual ::rice::p2p::commonapi::Cancellable
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    DirectAppSocket* closeMe {  };
    ::rice::p2p::commonapi::Cancellable* cancelMe {  };
protected:
    void ctor(DirectAppSocket* socket, ::rice::p2p::commonapi::CancellableTask* task);

public:
    bool cancel() override;

    // Generated
    DirectTransportLayer_CancelAndClose(DirectAppSocket* socket, ::rice::p2p::commonapi::CancellableTask* task);
protected:
    DirectTransportLayer_CancelAndClose(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
    friend class DirectTransportLayer;
};
