// Generated from /pastry-2.1/src/rice/pastry/routing/RoutingTable.java
#include <rice/pastry/routing/RoutingTable_alternateRoutesIterator_1.hpp>

#include <java/lang/NullPointerException.hpp>
#include <java/lang/RuntimeException.hpp>
#include <java/lang/String.hpp>
#include <rice/p2p/commonapi/Id_Distance.hpp>
#include <rice/pastry/Id_Distance.hpp>
#include <rice/pastry/Id.hpp>
#include <rice/pastry/NodeHandle.hpp>
#include <rice/pastry/routing/RouteSet.hpp>
#include <rice/pastry/routing/RoutingTable.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::pastry::routing::RoutingTable_alternateRoutesIterator_1::RoutingTable_alternateRoutesIterator_1(RoutingTable *RoutingTable_this, ::rice::pastry::Id* key, int32_t diffDigit, ::rice::pastry::Id_Distance* myDistance)
    : super(*static_cast< ::default_init_tag* >(0))
    , RoutingTable_this(RoutingTable_this)
    , key(key)
    , diffDigit(diffDigit)
    , myDistance(myDistance)
{
    clinit();
    init();
    ctor();
}

void rice::pastry::routing::RoutingTable_alternateRoutesIterator_1::init()
{
    keyDigit = npc(key)->getDigit(diffDigit, RoutingTable_this->idBaseBitLength);
    myDigit = npc(RoutingTable_this->myNodeId)->getDigit(diffDigit, RoutingTable_this->idBaseBitLength);
    i = int32_t(0);
    j = int32_t(1);
    k = int32_t(0);
    next_ = nullptr;
    rs = nullptr;
    {
        digit = (j == 0) ? (keyDigit + i) & (RoutingTable_this->cols - int32_t(1)) : (keyDigit + RoutingTable_this->cols - i) & (RoutingTable_this->cols - int32_t(1));
        rs = RoutingTable_this->getRouteSet(diffDigit, digit);
    }
}

rice::pastry::NodeHandle* rice::pastry::routing::RoutingTable_alternateRoutesIterator_1::findNext()
{
    if(rs != nullptr && k < npc(rs)->size()) {
        auto n = npc(rs)->get(k);
        if(npc(n)->isAlive()) {
            auto nDist = npc(npc(n)->getNodeId())->distance(key);
            k++;
            if(npc(myDistance)->compareTo(static_cast< ::rice::p2p::commonapi::Id_Distance* >(nDist)) > 0) {
                return n;
            } else {
                return findNext();
            }
        } else {
            RoutingTable_this->remove(n);
        }
    } else {
        k = 0;
        j++;
        if(j < 2) {
            digit = (j == 0) ? (keyDigit + i) & (RoutingTable_this->cols - int32_t(1)) : (keyDigit + RoutingTable_this->cols - i) & (RoutingTable_this->cols - int32_t(1));
            if(digit == myDigit)
                return nullptr;

            rs = RoutingTable_this->getRouteSet(diffDigit, digit);
            return findNext();
        } else {
            i++;
            j = 0;
            auto digit = (j == 0) ? (keyDigit + i) & (RoutingTable_this->cols - int32_t(1)) : (keyDigit + RoutingTable_this->cols - i) & (RoutingTable_this->cols - int32_t(1));
            rs = RoutingTable_this->getRouteSet(diffDigit, digit);
            k = 0;
            return findNext();
        }
    }
    return nullptr;
}

bool rice::pastry::routing::RoutingTable_alternateRoutesIterator_1::hasNext()
{
    if(next_ == nullptr)
        next_ = findNext();

    return (next_ != nullptr);
}

rice::pastry::NodeHandle* rice::pastry::routing::RoutingTable_alternateRoutesIterator_1::next()
{
    if(hasNext()) {
        auto temp = next_;
        next_ = nullptr;
        return temp;
    }
    return nullptr;
}

void rice::pastry::routing::RoutingTable_alternateRoutesIterator_1::remove()
{
    throw new ::java::lang::RuntimeException(u"Not implemented."_j);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::routing::RoutingTable_alternateRoutesIterator_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::pastry::routing::RoutingTable_alternateRoutesIterator_1::getClass0()
{
    return class_();
}

