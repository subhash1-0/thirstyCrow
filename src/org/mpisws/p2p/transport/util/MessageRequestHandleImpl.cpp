// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/util/MessageRequestHandleImpl.java
#include <org/mpisws/p2p/transport/util/MessageRequestHandleImpl.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/util/Map.hpp>
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

org::mpisws::p2p::transport::util::MessageRequestHandleImpl::MessageRequestHandleImpl(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::transport::util::MessageRequestHandleImpl::MessageRequestHandleImpl(::java::lang::Object* i, ::java::lang::Object* m, ::java::util::Map* options) 
    : MessageRequestHandleImpl(*static_cast< ::default_init_tag* >(0))
{
    ctor(i,m,options);
}

void org::mpisws::p2p::transport::util::MessageRequestHandleImpl::ctor(::java::lang::Object* i, ::java::lang::Object* m, ::java::util::Map* options)
{
    super::ctor();
    this->identifier = i;
    this->msg = m;
    this->options = options;
}

java::lang::Object* org::mpisws::p2p::transport::util::MessageRequestHandleImpl::getIdentifier()
{
    return java_cast< ::java::lang::Object* >(identifier);
}

java::lang::Object* org::mpisws::p2p::transport::util::MessageRequestHandleImpl::getMessage()
{
    return java_cast< ::java::lang::Object* >(msg);
}

java::util::Map* org::mpisws::p2p::transport::util::MessageRequestHandleImpl::getOptions()
{
    return options;
}

bool org::mpisws::p2p::transport::util::MessageRequestHandleImpl::cancel()
{
    if(subCancellable == nullptr)
        return false;

    return npc(subCancellable)->cancel();
}

void org::mpisws::p2p::transport::util::MessageRequestHandleImpl::setSubCancellable(::rice::p2p::commonapi::Cancellable* cancellable)
{
    this->subCancellable = cancellable;
}

rice::p2p::commonapi::Cancellable* org::mpisws::p2p::transport::util::MessageRequestHandleImpl::getSubCancellable()
{
    return subCancellable;
}

java::lang::String* org::mpisws::p2p::transport::util::MessageRequestHandleImpl::toString()
{
    return ::java::lang::StringBuilder().append(u"MRHi("_j)->append(static_cast< ::java::lang::Object* >(java_cast< ::java::lang::Object* >(identifier)))
        ->append(u","_j)
        ->append(static_cast< ::java::lang::Object* >(java_cast< ::java::lang::Object* >(msg)))
        ->append(u","_j)
        ->append(static_cast< ::java::lang::Object* >(options))
        ->append(u")"_j)->toString();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::util::MessageRequestHandleImpl::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.util.MessageRequestHandleImpl", 54);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::util::MessageRequestHandleImpl::getClass0()
{
    return class_();
}

