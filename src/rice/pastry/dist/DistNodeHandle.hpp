// Generated from /pastry-2.1/src/rice/pastry/dist/DistNodeHandle.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/net/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/pastry/dist/fwd-pastry-2.1.hpp>
#include <rice/pastry/socket/TransportLayerNodeHandle.hpp>
#include <java/util/Observer.hpp>

struct default_init_tag;

class rice::pastry::dist::DistNodeHandle
    : public ::rice::pastry::socket::TransportLayerNodeHandle
    , public virtual ::java::util::Observer
{

public:
    typedef ::rice::pastry::socket::TransportLayerNodeHandle super;

public: /* package */
    static constexpr int64_t serialVersionUID { int64_t(6030505652558872412LL) };

public: /* protected */
    ::rice::pastry::Id* nodeId {  };
protected:
    void ctor(::rice::pastry::Id* nodeId);

public:
    ::rice::pastry::Id* getNodeId() override;
    /*::java::lang::String* toString(); (already declared) */
    /*bool equals(::java::lang::Object* obj); (already declared) */
    /*int32_t hashCode(); (already declared) */
    virtual ::java::net::InetSocketAddress* getInetSocketAddress() = 0;

    // Generated
    DistNodeHandle(::rice::pastry::Id* nodeId);
protected:
    DistNodeHandle(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
