// Generated from /pastry-2.1/src/rice/pastry/socket/SPNFIdentitySerializer.java

#pragma once

#include <org/mpisws/p2p/transport/identity/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/pastry/socket/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/pastry/NodeHandleFactoryListener.hpp>

struct default_init_tag;

class rice::pastry::socket::SPNFIdentitySerializer_addSerializerListener_1
    : public virtual ::java::lang::Object
    , public virtual ::rice::pastry::NodeHandleFactoryListener
{

public:
    typedef ::java::lang::Object super;
    virtual void nodeHandleFound(SocketNodeHandle* nodeHandle);

    // Generated
    SPNFIdentitySerializer_addSerializerListener_1(SPNFIdentitySerializer *SPNFIdentitySerializer_this, ::org::mpisws::p2p::transport::identity::SerializerListener* listener);
    static ::java::lang::Class *class_();
    virtual void nodeHandleFound(::rice::pastry::NodeHandle* nodeHandle) override;
    SPNFIdentitySerializer *SPNFIdentitySerializer_this;
    ::org::mpisws::p2p::transport::identity::SerializerListener* listener;

private:
    virtual ::java::lang::Class* getClass0();
    friend class SPNFIdentitySerializer;
};
