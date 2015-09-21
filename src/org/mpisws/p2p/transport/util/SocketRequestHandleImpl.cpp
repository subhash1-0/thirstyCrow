// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/util/SocketRequestHandleImpl.java
#include <org/mpisws/p2p/transport/util/SocketRequestHandleImpl.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/IllegalArgumentException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/util/Map.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/p2p/commonapi/Cancellable.hpp>

template<typename T, typename U>
static T java_cast(U* u)
{
    if(!u) return static_cast<T>(nullptr);
    auto t = dynamic_cast<T>(u);
    if(!t) throw new ::java::lang::ClassCastException();
    return t;
}

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::transport::util::SocketRequestHandleImpl::SocketRequestHandleImpl(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::transport::util::SocketRequestHandleImpl::SocketRequestHandleImpl(::java::lang::Object* i, ::java::util::Map* options, ::rice::environment::logging::Logger* logger) 
    : SocketRequestHandleImpl(*static_cast< ::default_init_tag* >(0))
{
    ctor(i,options,logger);
}

void org::mpisws::p2p::transport::util::SocketRequestHandleImpl::ctor(::java::lang::Object* i, ::java::util::Map* options, ::rice::environment::logging::Logger* logger)
{
    super::ctor();
    this->identifier = i;
    this->options = options;
    if(logger == nullptr)
        throw new ::java::lang::IllegalArgumentException(u"logger is null"_j);

    this->logger = logger;
}

java::lang::Object* org::mpisws::p2p::transport::util::SocketRequestHandleImpl::getIdentifier()
{
    return java_cast< ::java::lang::Object* >(identifier);
}

java::util::Map* org::mpisws::p2p::transport::util::SocketRequestHandleImpl::getOptions()
{
    return options;
}

bool org::mpisws::p2p::transport::util::SocketRequestHandleImpl::cancel()
{
    if(subCancellable != nullptr) {
        return npc(subCancellable)->cancel();
    }
    return false;
}

void org::mpisws::p2p::transport::util::SocketRequestHandleImpl::setSubCancellable(::rice::p2p::commonapi::Cancellable* sub)
{
    this->subCancellable = sub;
}

rice::p2p::commonapi::Cancellable* org::mpisws::p2p::transport::util::SocketRequestHandleImpl::getSubCancellable()
{
    return subCancellable;
}

java::lang::String* org::mpisws::p2p::transport::util::SocketRequestHandleImpl::toString()
{
    return ::java::lang::StringBuilder().append(u"SRHi{"_j)->append(static_cast< ::java::lang::Object* >(java_cast< ::java::lang::Object* >(identifier)))
        ->append(u","_j)
        ->append(static_cast< ::java::lang::Object* >(options))
        ->append(u"}"_j)->toString();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::util::SocketRequestHandleImpl::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.util.SocketRequestHandleImpl", 53);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::util::SocketRequestHandleImpl::getClass0()
{
    return class_();
}

