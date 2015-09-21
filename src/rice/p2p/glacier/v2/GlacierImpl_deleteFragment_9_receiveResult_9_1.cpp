// Generated from /pastry-2.1/src/rice/p2p/glacier/v2/GlacierImpl.java
#include <rice/p2p/glacier/v2/GlacierImpl_deleteFragment_9_receiveResult_9_1.hpp>

#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/Continuation.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/glacier/v2/GlacierImpl_deleteFragment_9.hpp>
#include <rice/p2p/glacier/v2/GlacierImpl.hpp>
#include <rice/persistence/StorageManager.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::glacier::v2::GlacierImpl_deleteFragment_9_receiveResult_9_1::GlacierImpl_deleteFragment_9_receiveResult_9_1(GlacierImpl_deleteFragment_9 *GlacierImpl_deleteFragment_9_this, ::rice::p2p::commonapi::Id* fkey, ::rice::Continuation* command)
    : super(*static_cast< ::default_init_tag* >(0))
    , GlacierImpl_deleteFragment_9_this(GlacierImpl_deleteFragment_9_this)
    , fkey(fkey)
    , command(command)
{
    clinit();
    ctor();
}

void rice::p2p::glacier::v2::GlacierImpl_deleteFragment_9_receiveResult_9_1::receiveResult(::java::lang::Object* o)
{
    if(npc(GlacierImpl_deleteFragment_9_this->GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(GlacierImpl_deleteFragment_9_this->GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Deleting fragment "_j)->append(npc(fkey)->toStringFull())->toString());

    npc(GlacierImpl_deleteFragment_9_this->GlacierImpl_this->fragmentStorage)->unstore(fkey, command);
}

void rice::p2p::glacier::v2::GlacierImpl_deleteFragment_9_receiveResult_9_1::receiveException(::java::lang::Exception* e)
{
    if(npc(GlacierImpl_deleteFragment_9_this->GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
        npc(GlacierImpl_deleteFragment_9_this->GlacierImpl_this->logger)->logException(::java::lang::StringBuilder().append(u"Cannot store in trash: "_j)->append(npc(fkey)->toStringFull())
            ->append(u", e="_j)->toString(), e);

    npc(command)->receiveException(e);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::glacier::v2::GlacierImpl_deleteFragment_9_receiveResult_9_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::glacier::v2::GlacierImpl_deleteFragment_9_receiveResult_9_1::getClass0()
{
    return class_();
}

