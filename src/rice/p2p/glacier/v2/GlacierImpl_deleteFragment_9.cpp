// Generated from /pastry-2.1/src/rice/p2p/glacier/v2/GlacierImpl.java
#include <rice/p2p/glacier/v2/GlacierImpl_deleteFragment_9.hpp>

#include <java/io/Serializable.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/Continuation.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/glacier/GlacierException.hpp>
#include <rice/p2p/glacier/v2/GlacierImpl_deleteFragment_9_receiveResult_9_1.hpp>
#include <rice/p2p/glacier/v2/GlacierImpl.hpp>
#include <rice/persistence/StorageManager.hpp>

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

rice::p2p::glacier::v2::GlacierImpl_deleteFragment_9::GlacierImpl_deleteFragment_9(GlacierImpl *GlacierImpl_this, ::rice::p2p::commonapi::Id* fkey, ::rice::Continuation* command)
    : super(*static_cast< ::default_init_tag* >(0))
    , GlacierImpl_this(GlacierImpl_this)
    , fkey(fkey)
    , command(command)
{
    clinit();
    ctor();
}

void rice::p2p::glacier::v2::GlacierImpl_deleteFragment_9::receiveResult(::java::lang::Object* o)
{
    if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Fragment "_j)->append(npc(fkey)->toStringFull())
            ->append(u" retrieved, storing in trash"_j)->toString());

    if(o != nullptr) {
        npc(GlacierImpl_this->trashStorage)->store(fkey, nullptr, java_cast< ::java::io::Serializable* >(o), new GlacierImpl_deleteFragment_9_receiveResult_9_1(this, fkey, command));
    } else {
        receiveException(static_cast< ::java::lang::Exception* >(new ::rice::p2p::glacier::GlacierException(::java::lang::StringBuilder().append(u"Move to trash: Fragment "_j)->append(static_cast< ::java::lang::Object* >(fkey))
            ->append(u" does not exist?!?"_j)->toString())));
    }
}

void rice::p2p::glacier::v2::GlacierImpl_deleteFragment_9::receiveException(::java::lang::Exception* e)
{
    if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
        npc(GlacierImpl_this->logger)->logException(::java::lang::StringBuilder().append(u"Cannot retrieve fragment "_j)->append(static_cast< ::java::lang::Object* >(fkey))
            ->append(u" for deletion: e="_j)->toString(), e);

    npc(command)->receiveException(new ::rice::p2p::glacier::GlacierException(::java::lang::StringBuilder().append(u"Cannot retrieve fragment "_j)->append(static_cast< ::java::lang::Object* >(fkey))
        ->append(u" for deletion"_j)->toString()));
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::glacier::v2::GlacierImpl_deleteFragment_9::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::glacier::v2::GlacierImpl_deleteFragment_9::getClass0()
{
    return class_();
}

