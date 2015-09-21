// Generated from /pastry-2.1/src/rice/pastry/transport/PMessageReceiptImpl.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/pastry/messaging/fwd-pastry-2.1.hpp>
#include <rice/pastry/transport/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/pastry/transport/PMessageReceipt.hpp>
#include <rice/pastry/NodeHandle.hpp>
#include <rice/pastry/messaging/Message.hpp>

struct default_init_tag;

class rice::pastry::transport::PMessageReceiptImpl
    : public virtual ::java::lang::Object
    , public virtual PMessageReceipt
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    ::org::mpisws::p2p::transport::MessageRequestHandle* internal {  };
    ::rice::pastry::messaging::Message* message {  };
    ::java::util::Map* options {  };
    bool cancelled {  };
protected:
    void ctor(::rice::pastry::messaging::Message* msg, ::java::util::Map* options);

public:
    ::rice::pastry::NodeHandle* getIdentifier() override;
    ::rice::pastry::messaging::Message* getMessage() override;
    ::java::util::Map* getOptions() override;
    bool cancel() override;
    virtual void setInternal(::org::mpisws::p2p::transport::MessageRequestHandle* name);
    virtual ::org::mpisws::p2p::transport::MessageRequestHandle* getInternal();
    virtual bool isCancelled();
    ::java::lang::String* toString() override;

    // Generated
    PMessageReceiptImpl(::rice::pastry::messaging::Message* msg, ::java::util::Map* options);
protected:
    PMessageReceiptImpl(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    void init();
    virtual ::java::lang::Class* getClass0();
};
