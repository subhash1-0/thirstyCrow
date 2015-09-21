// Generated from /pastry-2.1/src/rice/pastry/dist/DistPastryNodeFactory.java
#include <rice/pastry/dist/DistPastryNodeFactory.hpp>

#include <java/lang/IllegalArgumentException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/pastry/socket/SocketPastryNodeFactory.hpp>
#include <rice/pastry/socket/nat/rendezvous/RendezvousSocketPastryNodeFactory.hpp>

rice::pastry::dist::DistPastryNodeFactory::DistPastryNodeFactory(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::dist::DistPastryNodeFactory::DistPastryNodeFactory()
    : DistPastryNodeFactory(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

int32_t& rice::pastry::dist::DistPastryNodeFactory::PROTOCOL_SOCKET()
{
    clinit();
    return PROTOCOL_SOCKET_;
}
int32_t rice::pastry::dist::DistPastryNodeFactory::PROTOCOL_SOCKET_;

int32_t& rice::pastry::dist::DistPastryNodeFactory::PROTOCOL_RENDEZVOUS()
{
    clinit();
    return PROTOCOL_RENDEZVOUS_;
}
int32_t rice::pastry::dist::DistPastryNodeFactory::PROTOCOL_RENDEZVOUS_;

int32_t& rice::pastry::dist::DistPastryNodeFactory::PROTOCOL_DEFAULT()
{
    clinit();
    return PROTOCOL_DEFAULT_;
}
int32_t rice::pastry::dist::DistPastryNodeFactory::PROTOCOL_DEFAULT_;

rice::pastry::socket::SocketPastryNodeFactory* rice::pastry::dist::DistPastryNodeFactory::getFactory(::rice::pastry::NodeIdFactory* nf, int32_t protocol, int32_t port, ::rice::environment::Environment* env) /* throws(IOException) */
{
    clinit();
    if(protocol == PROTOCOL_SOCKET_) {
        return new ::rice::pastry::socket::SocketPastryNodeFactory(nf, port, env);
    }
    if(protocol == PROTOCOL_RENDEZVOUS_) {
        return new ::rice::pastry::socket::nat::rendezvous::RendezvousSocketPastryNodeFactory(nf, port, env, false);
    }
    throw new ::java::lang::IllegalArgumentException(::java::lang::StringBuilder().append(u"Unsupported Protocol "_j)->append(protocol)->toString());
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::dist::DistPastryNodeFactory::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.dist.DistPastryNodeFactory", 38);
    return c;
}

void rice::pastry::dist::DistPastryNodeFactory::clinit()
{
    super::clinit();
    static bool in_cl_init = false;
struct clinit_ {
    clinit_() {
        in_cl_init = true;
        PROTOCOL_SOCKET_ = int32_t(2);
        PROTOCOL_RENDEZVOUS_ = int32_t(3);
        PROTOCOL_DEFAULT_ = DistPastryNodeFactory::PROTOCOL_SOCKET_;
    }
};

    if(!in_cl_init) {
        static clinit_ clinit_instance;
    }
}

java::lang::Class* rice::pastry::dist::DistPastryNodeFactory::getClass0()
{
    return class_();
}

