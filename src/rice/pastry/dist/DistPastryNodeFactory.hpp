// Generated from /pastry-2.1/src/rice/pastry/dist/DistPastryNodeFactory.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/pastry/dist/fwd-pastry-2.1.hpp>
#include <rice/pastry/socket/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct default_init_tag;

class rice::pastry::dist::DistPastryNodeFactory
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;

private:
    static int32_t PROTOCOL_SOCKET_;
    static int32_t PROTOCOL_RENDEZVOUS_;
    static int32_t PROTOCOL_DEFAULT_;

public:
    static ::rice::pastry::socket::SocketPastryNodeFactory* getFactory(::rice::pastry::NodeIdFactory* nf, int32_t protocol, int32_t port, ::rice::environment::Environment* env) /* throws(IOException) */;

    // Generated
    DistPastryNodeFactory();
protected:
    DistPastryNodeFactory(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    static void clinit();
    static int32_t& PROTOCOL_SOCKET();
    static int32_t& PROTOCOL_RENDEZVOUS();
    static int32_t& PROTOCOL_DEFAULT();

private:
    virtual ::java::lang::Class* getClass0();
};
