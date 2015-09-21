// Generated from /pastry-2.1/src/rice/pastry/socket/SPNFIdentitySerializer.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/identity/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/multiaddress/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/sourceroute/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/pastry/socket/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/identity/IdentitySerializer.hpp>

struct default_init_tag;

class rice::pastry::socket::SPNFIdentitySerializer
    : public virtual ::java::lang::Object
    , public virtual ::org::mpisws::p2p::transport::identity::IdentitySerializer
{

public:
    typedef ::java::lang::Object super;

public: /* protected */
    ::rice::pastry::PastryNode* pn {  };
    SocketNodeHandleFactory* factory {  };
protected:
    void ctor(::rice::pastry::PastryNode* pn, SocketNodeHandleFactory* factory);

public:
    virtual void serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf, TransportLayerNodeHandle* i) /* throws(IOException) */;
    virtual TransportLayerNodeHandle* deserialize(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::org::mpisws::p2p::transport::sourceroute::SourceRoute* i) /* throws(IOException) */;

public: /* protected */
    virtual SocketNodeHandle* buildSNH(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* i, int64_t epoch, ::rice::pastry::Id* nid) /* throws(IOException) */;

public:
    virtual ::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* translateDown(TransportLayerNodeHandle* i);
    virtual ::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* translateUp(::org::mpisws::p2p::transport::sourceroute::SourceRoute* i);

public: /* package */
    ::java::util::Map* listeners {  };

public:
    void addSerializerListener(::org::mpisws::p2p::transport::identity::SerializerListener* listener) override;
    void removeSerializerListener(::org::mpisws::p2p::transport::identity::SerializerListener* listener) override;

    // Generated
    SPNFIdentitySerializer(::rice::pastry::PastryNode* pn, SocketNodeHandleFactory* factory);
protected:
    SPNFIdentitySerializer(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    void init();

public:
    virtual ::java::lang::Object* deserialize(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::java::lang::Object* l) override;
    virtual void serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf, ::java::lang::Object* i) override;
    virtual ::java::lang::Object* translateDown(::java::lang::Object* i) override;
    virtual ::java::lang::Object* translateUp(::java::lang::Object* i) override;

private:
    virtual ::java::lang::Class* getClass0();
    friend class SPNFIdentitySerializer_addSerializerListener_1;
};
