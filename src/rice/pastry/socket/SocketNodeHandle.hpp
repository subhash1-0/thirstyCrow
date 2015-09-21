// Generated from /pastry-2.1/src/rice/pastry/socket/SocketNodeHandle.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/net/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/multiaddress/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/pastry/messaging/fwd-pastry-2.1.hpp>
#include <rice/pastry/socket/fwd-pastry-2.1.hpp>
#include <rice/pastry/dist/DistNodeHandle.hpp>
#include <org/mpisws/p2p/transport/multiaddress/MultiInetSocketAddress.hpp>

struct default_init_tag;

class rice::pastry::socket::SocketNodeHandle
    : public ::rice::pastry::dist::DistNodeHandle
{

public:
    typedef ::rice::pastry::dist::DistNodeHandle super;
    ::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* eaddress {  };

public: /* protected */
    int64_t epoch {  };
protected:
    void ctor(::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* eisa, int64_t epoch, ::rice::pastry::Id* id, ::rice::pastry::PastryNode* node);

public:
    int64_t getEpoch() override;
    virtual void setLocalNode(::rice::pastry::PastryNode* pn);
    virtual ::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* getIdentifier();
    int32_t getLiveness() override;
    ::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* getAddress() override;
    ::java::net::InetSocketAddress* getInetSocketAddress() override;
    bool checkLiveness() override;
    virtual bool isLocal();
    void receiveMessage(::rice::pastry::messaging::Message* msg) override;
    ::java::lang::String* toString() override;
    virtual ::java::lang::String* toStringFull();
    bool equals(::java::lang::Object* obj) override;
    int32_t hashCode() override;
    int32_t proximity() override;
    bool ping() override;
    void update(::java::util::Observable* o, ::java::lang::Object* obj) override;

public: /* package */
    static SocketNodeHandle* build(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::pastry::PastryNode* local) /* throws(IOException) */;

public:
    void serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */ override;

    // Generated

public: /* protected */
    SocketNodeHandle(::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* eisa, int64_t epoch, ::rice::pastry::Id* id, ::rice::pastry::PastryNode* node);
protected:
    SocketNodeHandle(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    virtual void update(::java::lang::Object* update);

private:
    virtual ::java::lang::Class* getClass0();
};
