// Generated from /pastry-2.1/src/rice/pastry/transport/PMessageReceiptImpl.java
#include <rice/pastry/transport/PMessageReceiptImpl.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/RuntimeException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/util/Map.hpp>
#include <org/mpisws/p2p/transport/MessageRequestHandle.hpp>
#include <rice/pastry/NodeHandle.hpp>
#include <rice/pastry/messaging/Message.hpp>

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

extern void lock(::java::lang::Object *);
extern void unlock(::java::lang::Object *);

namespace
{
    struct synchronized
    {
        synchronized(::java::lang::Object *o) : o(o) { ::lock(o); }
        ~synchronized() { ::unlock(o); }
    private:
        synchronized(const synchronized&); synchronized& operator=(const synchronized&);
        ::java::lang::Object *o;
    };
}
rice::pastry::transport::PMessageReceiptImpl::PMessageReceiptImpl(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::transport::PMessageReceiptImpl::PMessageReceiptImpl(::rice::pastry::messaging::Message* msg, ::java::util::Map* options) 
    : PMessageReceiptImpl(*static_cast< ::default_init_tag* >(0))
{
    ctor(msg,options);
}

void rice::pastry::transport::PMessageReceiptImpl::init()
{
    cancelled = false;
}

void rice::pastry::transport::PMessageReceiptImpl::ctor(::rice::pastry::messaging::Message* msg, ::java::util::Map* options)
{
    super::ctor();
    init();
    this->message = msg;
    this->options = options;
}

rice::pastry::NodeHandle* rice::pastry::transport::PMessageReceiptImpl::getIdentifier()
{
    if(internal == nullptr)
        return nullptr;

    return java_cast< ::rice::pastry::NodeHandle* >(java_cast< ::rice::pastry::NodeHandle* >(npc(internal)->getIdentifier()));
}

rice::pastry::messaging::Message* rice::pastry::transport::PMessageReceiptImpl::getMessage()
{
    return message;
}

java::util::Map* rice::pastry::transport::PMessageReceiptImpl::getOptions()
{
    return options;
}

bool rice::pastry::transport::PMessageReceiptImpl::cancel()
{
    auto callCancel = false;
    {
        synchronized synchronized_0(this);
        {
            if(cancelled)
                return false;

            cancelled = true;
            if(internal != nullptr)
                callCancel = true;

        }
    }
    if(callCancel)
        return npc(internal)->cancel();

    return false;
}

void rice::pastry::transport::PMessageReceiptImpl::setInternal(::org::mpisws::p2p::transport::MessageRequestHandle* name)
{
    auto callCancel = false;
    {
        synchronized synchronized_1(this);
        {
            if(internal != nullptr && internal != name) {
                throw new ::java::lang::RuntimeException(::java::lang::StringBuilder().append(u"Internal already set old:"_j)->append(static_cast< ::java::lang::Object* >(internal))
                    ->append(u" new:"_j)
                    ->append(static_cast< ::java::lang::Object* >(name))->toString());
            }
            internal = name;
            callCancel = cancelled;
        }
    }
    if(callCancel)
        npc(internal)->cancel();

}

org::mpisws::p2p::transport::MessageRequestHandle* rice::pastry::transport::PMessageReceiptImpl::getInternal()
{
    return internal;
}

bool rice::pastry::transport::PMessageReceiptImpl::isCancelled()
{
    return cancelled;
}

java::lang::String* rice::pastry::transport::PMessageReceiptImpl::toString()
{
    return ::java::lang::StringBuilder().append(u"PMsgRecptI{"_j)->append(static_cast< ::java::lang::Object* >(message))
        ->append(u","_j)
        ->append(static_cast< ::java::lang::Object* >(getIdentifier()))
        ->append(u"}"_j)->toString();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::transport::PMessageReceiptImpl::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.transport.PMessageReceiptImpl", 41);
    return c;
}

java::lang::Class* rice::pastry::transport::PMessageReceiptImpl::getClass0()
{
    return class_();
}

