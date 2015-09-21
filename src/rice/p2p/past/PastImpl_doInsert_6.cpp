// Generated from /pastry-2.1/src/rice/p2p/past/PastImpl.java
#include <rice/p2p/past/PastImpl_doInsert_6.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/Continuation_MultiContinuation.hpp>
#include <rice/Continuation_NamedContinuation.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/commonapi/NodeHandle.hpp>
#include <rice/p2p/commonapi/NodeHandleSet.hpp>
#include <rice/p2p/past/PastImpl_doInsert_6_receiveResult_6_1.hpp>
#include <rice/p2p/past/PastImpl_MessageBuilder.hpp>
#include <rice/p2p/past/PastImpl.hpp>
#include <rice/p2p/past/messaging/PastMessage.hpp>

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

rice::p2p::past::PastImpl_doInsert_6::PastImpl_doInsert_6(PastImpl *PastImpl_this, ::rice::p2p::commonapi::Id* id, PastImpl_MessageBuilder* builder, bool useSocket, ::rice::Continuation* continuation)
    : super(*static_cast< ::default_init_tag* >(0))
    , PastImpl_this(PastImpl_this)
    , id(id)
    , builder(builder)
    , useSocket(useSocket)
{
    clinit();
    ctor(continuation);
}

void rice::p2p::past::PastImpl_doInsert_6::receiveResult(::java::lang::Object* o)
{
    auto replicas = java_cast< ::rice::p2p::commonapi::NodeHandleSet* >(o);
    if(npc(PastImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINER)
        npc(PastImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Received replicas "_j)->append(static_cast< ::java::lang::Object* >(replicas))
            ->append(u" for id "_j)
            ->append(static_cast< ::java::lang::Object* >(id))->toString());

    ::rice::Continuation_MultiContinuation* multi = new PastImpl_doInsert_6_receiveResult_6_1(this, parent, npc(replicas)->size());
    for (auto i = int32_t(0); i < npc(replicas)->size(); i++) {
        auto handle = npc(replicas)->getHandle(i);
        auto m = npc(builder)->buildMessage();
        ::rice::Continuation* c = new ::rice::Continuation_NamedContinuation(::java::lang::StringBuilder().append(u"InsertMessage to "_j)->append(static_cast< ::java::lang::Object* >(npc(replicas)->getHandle(i)))
            ->append(u" for "_j)
            ->append(static_cast< ::java::lang::Object* >(id))->toString(), npc(multi)->getSubContinuation(i));
        if(useSocket) {
            PastImpl_this->sendViaSocket(handle, m, c);
        } else {
            PastImpl_this->sendRequest(handle, m, c);
        }
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::past::PastImpl_doInsert_6::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::past::PastImpl_doInsert_6::getClass0()
{
    return class_();
}

