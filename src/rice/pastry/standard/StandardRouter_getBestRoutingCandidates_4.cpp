// Generated from /pastry-2.1/src/rice/pastry/standard/StandardRouter.java
#include <rice/pastry/standard/StandardRouter_getBestRoutingCandidates_4.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/RuntimeException.hpp>
#include <java/lang/String.hpp>
#include <java/util/ArrayList.hpp>
#include <java/util/Iterator.hpp>
#include <java/util/NoSuchElementException.hpp>
#include <rice/pastry/Id.hpp>
#include <rice/pastry/NodeHandle.hpp>
#include <rice/pastry/PastryNode.hpp>
#include <rice/pastry/routing/RouteSet.hpp>
#include <rice/pastry/routing/RoutingTable.hpp>
#include <rice/pastry/standard/StandardRouter.hpp>

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

rice::pastry::standard::StandardRouter_getBestRoutingCandidates_4::StandardRouter_getBestRoutingCandidates_4(StandardRouter *StandardRouter_this, ::rice::pastry::Id* target, int32_t lsPos)
    : super(*static_cast< ::default_init_tag* >(0))
    , StandardRouter_this(StandardRouter_this)
    , target(target)
    , lsPos(lsPos)
{
    clinit();
    init();
    ctor();
}

void rice::pastry::standard::StandardRouter_getBestRoutingCandidates_4::init()
{
    rtIterator = nullptr;
    iterator = nullptr;
    lsCollection = nullptr;
    k = int32_t(0);
    {
        best = npc(npc(StandardRouter_this->thePastryNode)->getRoutingTable())->getBestEntry(target);
        if(best == nullptr || npc(best)->isEmpty()) {
            rtIterator = npc(npc(StandardRouter_this->thePastryNode)->getRoutingTable())->alternateRoutesIterator(java_cast< ::rice::pastry::Id* >(target));
            lsCollection = StandardRouter_this->getLSCollection(lsPos);
            iterator = rtIterator;
        }
        next_ = getNext();
    }
}

bool rice::pastry::standard::StandardRouter_getBestRoutingCandidates_4::hasNext()
{
    if(next_ == nullptr)
        next_ = getNext();

    return (next_ != nullptr);
}

rice::pastry::NodeHandle* rice::pastry::standard::StandardRouter_getBestRoutingCandidates_4::getNext()
{
    if(iterator == nullptr && best != nullptr) {
        auto ret = npc(best)->get(k);
        k++;
        if(k >= npc(best)->size()) {
            rtIterator = npc(npc(StandardRouter_this->thePastryNode)->getRoutingTable())->alternateRoutesIterator(java_cast< ::rice::pastry::Id* >(target));
            lsCollection = StandardRouter_this->getLSCollection(lsPos);
            iterator = rtIterator;
        }
        return ret;
    }
    if(npc(iterator)->hasNext()) {
        auto ret = java_cast< ::rice::pastry::NodeHandle* >(npc(iterator)->next());
        if(best != nullptr && npc(best)->getIndex(ret) != -int32_t(1)) {
            return getNext();
        }
        if(iterator == rtIterator && npc(lsCollection)->contains(static_cast< ::java::lang::Object* >(ret))) {
            iterator = npc(lsCollection)->iterator();
            return java_cast< ::rice::pastry::NodeHandle* >(npc(iterator)->next());
        } else {
            return ret;
        }
    } else {
        if(iterator == rtIterator) {
            iterator = npc(lsCollection)->iterator();
            return getNext();
        }
    }
    return nullptr;
}

rice::pastry::NodeHandle* rice::pastry::standard::StandardRouter_getBestRoutingCandidates_4::next()
{
    if(hasNext()) {
        auto ret = next_;
        next_ = nullptr;
        return ret;
    }
    throw new ::java::util::NoSuchElementException();
}

void rice::pastry::standard::StandardRouter_getBestRoutingCandidates_4::remove()
{
    throw new ::java::lang::RuntimeException(u"Operation not allowed."_j);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::standard::StandardRouter_getBestRoutingCandidates_4::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::pastry::standard::StandardRouter_getBestRoutingCandidates_4::getClass0()
{
    return class_();
}

