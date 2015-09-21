// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/priority/QueueOverflowException.java
#include <org/mpisws/p2p/transport/priority/QueueOverflowException.hpp>

#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/Throwable.hpp>

org::mpisws::p2p::transport::priority::QueueOverflowException::QueueOverflowException(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::transport::priority::QueueOverflowException::QueueOverflowException(::java::lang::Object* identifier, ::java::lang::Object* message) 
    : QueueOverflowException(*static_cast< ::default_init_tag* >(0))
{
    ctor(identifier,message);
}

org::mpisws::p2p::transport::priority::QueueOverflowException::QueueOverflowException(::java::lang::Object* identifier, ::java::lang::Object* message, ::java::lang::Throwable* cause) 
    : QueueOverflowException(*static_cast< ::default_init_tag* >(0))
{
    ctor(identifier,message,cause);
}

void org::mpisws::p2p::transport::priority::QueueOverflowException::ctor(::java::lang::Object* identifier, ::java::lang::Object* message)
{
    super::ctor(::java::lang::StringBuilder().append(u"Queue to "_j)->append(static_cast< ::java::lang::Object* >(identifier))
        ->append(u" overflowed. Couldn't deliver message "_j)
        ->append(static_cast< ::java::lang::Object* >(message))->toString());
    this->identifier = identifier;
    this->message = message;
}

void org::mpisws::p2p::transport::priority::QueueOverflowException::ctor(::java::lang::Object* identifier, ::java::lang::Object* message, ::java::lang::Throwable* cause)
{
    ctor(identifier, message);
    this->cause = cause;
}

java::lang::Object* org::mpisws::p2p::transport::priority::QueueOverflowException::getIdentifier()
{
    return identifier;
}

java::lang::Object* org::mpisws::p2p::transport::priority::QueueOverflowException::getAttemptedMessage()
{
    return message;
}

java::lang::Throwable* org::mpisws::p2p::transport::priority::QueueOverflowException::getCause()
{
    return cause;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::priority::QueueOverflowException::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.priority.QueueOverflowException", 56);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::priority::QueueOverflowException::getClass0()
{
    return class_();
}

