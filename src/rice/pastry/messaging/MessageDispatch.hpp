// Generated from /pastry-2.1/src/rice/pastry/messaging/MessageDispatch.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/pastry/client/fwd-pastry-2.1.hpp>
#include <rice/pastry/messaging/fwd-pastry-2.1.hpp>
#include <rice/pastry/transport/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/Destructable.hpp>

struct default_init_tag;

class rice::pastry::messaging::MessageDispatch
    : public virtual ::java::lang::Object
    , public virtual ::rice::Destructable
{

public:
    typedef ::java::lang::Object super;

private:
    ::java::util::HashMap* addressBook {  };

public: /* protected */
    ::rice::pastry::PastryNode* localNode {  };
    ::rice::environment::logging::Logger* logger {  };
    ::rice::pastry::transport::Deserializer* deserializer {  };
protected:
    void ctor(::rice::pastry::PastryNode* pn, ::rice::pastry::transport::Deserializer* deserializer);

public:
    virtual void registerReceiver(int32_t address, ::rice::pastry::client::PastryAppl* receiver);
    virtual ::rice::pastry::client::PastryAppl* getDestination(Message* msg);
    virtual ::rice::pastry::client::PastryAppl* getDestinationByAddress(int32_t addr);
    virtual bool dispatchMessage(Message* msg);
    void destroy() override;

    // Generated
    MessageDispatch(::rice::pastry::PastryNode* pn, ::rice::pastry::transport::Deserializer* deserializer);
protected:
    MessageDispatch(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
