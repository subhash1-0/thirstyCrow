// Generated from /pastry-2.1/src/rice/p2p/multiring/MultiringNodeCollection.java
#include <rice/p2p/multiring/MultiringNodeCollection.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/IllegalArgumentException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/util/Vector.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/commonapi/MessageReceipt.hpp>
#include <rice/p2p/multiring/MultiringNode.hpp>
#include <rice/p2p/multiring/RingId.hpp>
#include <Array.hpp>

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

rice::p2p::multiring::MultiringNodeCollection::MultiringNodeCollection(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::multiring::MultiringNodeCollection::MultiringNodeCollection(MultiringNode* node, int32_t BASE) 
    : MultiringNodeCollection(*static_cast< ::default_init_tag* >(0))
{
    ctor(node,BASE);
}

void rice::p2p::multiring::MultiringNodeCollection::ctor(MultiringNode* node, int32_t BASE)
{
    super::ctor();
    this->nodes = new ::java::util::Vector();
    npc(this->nodes)->add(static_cast< ::java::lang::Object* >(node));
    this->BASE = BASE;
}

void rice::p2p::multiring::MultiringNodeCollection::addNode(MultiringNode* node)
{
    if(!npc(npc(node)->getNodeId())->equals(npc((java_cast< MultiringNode* >(java_cast< ::java::lang::Object* >(npc(nodes)->elementAt(0)))))->getNodeId()))
        throw new ::java::lang::IllegalArgumentException(u"Node added does not have the correct nodeId!"_j);

    broadcastNewNode(node);
    npc(nodes)->add(static_cast< ::java::lang::Object* >(node));
}

void rice::p2p::multiring::MultiringNodeCollection::broadcastNewNode(MultiringNode* node)
{
    for (auto i = int32_t(0); i < npc(nodes)->size(); i++) {
        auto thisNode = java_cast< MultiringNode* >(java_cast< ::java::lang::Object* >(npc(nodes)->elementAt(i)));
        if(npc(npc(thisNode)->getRingId())->equals(npc(node)->getRingId()))
            throw new ::java::lang::IllegalArgumentException(::java::lang::StringBuilder().append(u"ERROR: Attempt to add already-existing ringId "_j)->append(static_cast< ::java::lang::Object* >(node))
                ->append(u" "_j)
                ->append(static_cast< ::java::lang::Object* >(npc(node)->getId()))
                ->append(u" "_j)
                ->append(static_cast< ::java::lang::Object* >(thisNode))
                ->append(u" "_j)
                ->append(static_cast< ::java::lang::Object* >(npc(thisNode)->getId()))->toString());

        npc(thisNode)->nodeAdded(npc(node)->getRingId());
        npc(node)->nodeAdded(npc(thisNode)->getRingId());
    }
}

rice::p2p::commonapi::MessageReceipt* rice::p2p::multiring::MultiringNodeCollection::route(RingId* id, ::rice::p2p::commonapi::rawserialization::RawMessage* message, ::java::lang::String* application, ::rice::p2p::commonapi::DeliveryNotification* deliverAckToMe, ::java::util::Map* options)
{
    auto best = java_cast< MultiringNode* >(java_cast< ::java::lang::Object* >(npc(nodes)->elementAt(0)));
    for (auto i = int32_t(1); i < npc(nodes)->size(); i++) {
        auto thisNode = java_cast< MultiringNode* >(java_cast< ::java::lang::Object* >(npc(nodes)->elementAt(i)));
        auto bestShared = getLengthOfSharedPrefix(java_cast< RingId* >(npc(best)->getId()), id);
        auto thisShared = getLengthOfSharedPrefix(java_cast< RingId* >(npc(thisNode)->getId()), id);
        auto bestLength = getLength(java_cast< RingId* >(npc(best)->getId()));
        auto thisLength = getLength(java_cast< RingId* >(npc(thisNode)->getId()));
        if((thisShared > bestShared) || ((thisShared == bestShared) && (thisLength < bestLength)))
            best = thisNode;

    }
    return npc(best)->route(id, message, application, deliverAckToMe, options);
}

int32_t rice::p2p::multiring::MultiringNodeCollection::getLength(RingId* a)
{
    auto ba = npc(npc(a)->getRingId())->toByteArray_();
    for (auto i = int32_t(0); i < npc(ba)->length / BASE; i++) {
        auto zero = true;
        for (auto j = int32_t(0); j < BASE; j++) 
                        if((*ba)[npc(ba)->length - int32_t(1) - (BASE * i + j)] != 0)
                zero = false;


        if(zero)
            return i;

    }
    return (npc(ba)->length / BASE);
}

int32_t rice::p2p::multiring::MultiringNodeCollection::getLengthOfSharedPrefix(RingId* a, RingId* b)
{
    auto ba = npc(npc(a)->getRingId())->toByteArray_();
    auto bb = npc(npc(b)->getRingId())->toByteArray_();
    for (auto i = int32_t(0); i < npc(ba)->length / BASE; i++) {
        auto same = true;
        for (auto j = int32_t(0); j < BASE; j++) 
                        if((*ba)[npc(ba)->length - int32_t(1) - (BASE * i + j)] != (*bb)[npc(ba)->length - int32_t(1) - (BASE * i + j)])
                same = false;


        if(!same)
            return i;

    }
    return (npc(ba)->length / BASE);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::multiring::MultiringNodeCollection::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.multiring.MultiringNodeCollection", 42);
    return c;
}

java::lang::Class* rice::p2p::multiring::MultiringNodeCollection::getClass0()
{
    return class_();
}

