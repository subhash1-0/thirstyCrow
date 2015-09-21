// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/exception/NodeIsFaultyException.java
#include <org/mpisws/p2p/transport/exception/NodeIsFaultyException.hpp>

#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/Throwable.hpp>

org::mpisws::p2p::transport::exception::NodeIsFaultyException::NodeIsFaultyException(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::transport::exception::NodeIsFaultyException::NodeIsFaultyException(::java::lang::Object* identifier, ::java::lang::Object* message) 
    : NodeIsFaultyException(*static_cast< ::default_init_tag* >(0))
{
    ctor(identifier,message);
}

org::mpisws::p2p::transport::exception::NodeIsFaultyException::NodeIsFaultyException(::java::lang::Object* identifier, ::java::lang::Object* message, ::java::lang::Throwable* cause) 
    : NodeIsFaultyException(*static_cast< ::default_init_tag* >(0))
{
    ctor(identifier,message,cause);
}

org::mpisws::p2p::transport::exception::NodeIsFaultyException::NodeIsFaultyException(::java::lang::Object* identifier) 
    : NodeIsFaultyException(*static_cast< ::default_init_tag* >(0))
{
    ctor(identifier);
}

void org::mpisws::p2p::transport::exception::NodeIsFaultyException::ctor(::java::lang::Object* identifier, ::java::lang::Object* message)
{
    super::ctor(::java::lang::StringBuilder().append(u"Node "_j)->append(static_cast< ::java::lang::Object* >(identifier))
        ->append(u" is faulty"_j)
        ->append((message == nullptr ? u""_j : ::java::lang::StringBuilder().append(u", couldn't deliver message "_j)->append(static_cast< ::java::lang::Object* >(message))->toString()))->toString());
    this->identifier = identifier;
    this->message = message;
}

void org::mpisws::p2p::transport::exception::NodeIsFaultyException::ctor(::java::lang::Object* identifier, ::java::lang::Object* message, ::java::lang::Throwable* cause)
{
    ctor(identifier, message);
    this->cause = cause;
}

void org::mpisws::p2p::transport::exception::NodeIsFaultyException::ctor(::java::lang::Object* identifier)
{
    ctor(identifier, nullptr);
}

java::lang::Object* org::mpisws::p2p::transport::exception::NodeIsFaultyException::getIdentifier()
{
    return identifier;
}

java::lang::Object* org::mpisws::p2p::transport::exception::NodeIsFaultyException::getAttemptedMessage()
{
    return message;
}

java::lang::Throwable* org::mpisws::p2p::transport::exception::NodeIsFaultyException::getCause()
{
    return cause;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::exception::NodeIsFaultyException::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.exception.NodeIsFaultyException", 56);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::exception::NodeIsFaultyException::getClass0()
{
    return class_();
}

