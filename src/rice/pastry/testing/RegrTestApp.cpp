// Generated from /pastry-2.1/src/rice/pastry/testing/RegrTestApp.java
#include <rice/pastry/testing/RegrTestApp.hpp>

#include <java/io/IOException.hpp>
#include <java/io/PrintStream.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/RuntimeException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/System.hpp>
#include <java/util/SortedMap.hpp>
#include <java/util/Vector.hpp>
#include <rice/p2p/commonapi/Id_Distance.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/pastry/Id_Distance.hpp>
#include <rice/pastry/Id.hpp>
#include <rice/pastry/NodeHandle.hpp>
#include <rice/pastry/PastryNode.hpp>
#include <rice/pastry/leafset/LeafSet.hpp>
#include <rice/pastry/messaging/Message.hpp>
#include <rice/pastry/routing/RouteMessage.hpp>
#include <rice/pastry/routing/RoutingTable.hpp>
#include <rice/pastry/routing/SendOptions.hpp>
#include <rice/pastry/testing/PastryRegrTest.hpp>
#include <rice/pastry/testing/RegrTestApp_RTAddress.hpp>
#include <rice/pastry/testing/RTMessage.hpp>

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

rice::pastry::testing::RegrTestApp::RegrTestApp(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::testing::RegrTestApp::RegrTestApp(::rice::pastry::PastryNode* pn, PastryRegrTest* prg) 
    : RegrTestApp(*static_cast< ::default_init_tag* >(0))
{
    ctor(pn,prg);
}

int32_t& rice::pastry::testing::RegrTestApp::addr()
{
    clinit();
    return addr_;
}
int32_t rice::pastry::testing::RegrTestApp::addr_;

void rice::pastry::testing::RegrTestApp::ctor(::rice::pastry::PastryNode* pn, PastryRegrTest* prg)
{
    super::ctor(pn);
    this->prg = prg;
}

int32_t rice::pastry::testing::RegrTestApp::getAddress()
{
    return addr_;
}

void rice::pastry::testing::RegrTestApp::sendMsg(::rice::pastry::Id* nid)
{
    routeMsg(nid, new RTMessage(addr_, getNodeHandle(), nid), new ::rice::pastry::routing::SendOptions());
}

void rice::pastry::testing::RegrTestApp::sendTrace(::rice::pastry::Id* nid)
{
    routeMsg(nid, new RTMessage(addr_, getNodeHandle(), nid), new ::rice::pastry::routing::SendOptions());
}

void rice::pastry::testing::RegrTestApp::deliver(::rice::pastry::Id* key, ::rice::pastry::messaging::Message* msg)
{
    auto rmsg = java_cast< RTMessage* >(msg);
    auto localId = getNodeId();
    if(localId != key) {
        int32_t inBetween;
        if(npc(localId)->compareTo(static_cast< ::rice::p2p::commonapi::Id* >(key)) < 0) {
            auto i1 = npc(npc(npc(prg)->pastryNodesSortedReady)->subMap(localId, key))->size();
            auto i2 = npc(npc(npc(prg)->pastryNodesSortedReady)->tailMap(key))->size() + npc(npc(npc(prg)->pastryNodesSortedReady)->headMap(localId))->size();
            inBetween = (i1 < i2) ? i1 : i2;
        } else {
            auto i1 = npc(npc(npc(prg)->pastryNodesSortedReady)->subMap(key, localId))->size();
            auto i2 = npc(npc(npc(prg)->pastryNodesSortedReady)->tailMap(localId))->size() + npc(npc(npc(prg)->pastryNodesSortedReady)->headMap(key))->size();
            inBetween = (i1 < i2) ? i1 : i2;
        }
        if(inBetween > 1) {
            npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"messageForAppl failure, inBetween="_j)->append(inBetween)->toString());
            npc(::java::lang::System::out())->print(static_cast< ::java::lang::Object* >(msg));
            npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u" received at "_j)->append(static_cast< ::java::lang::Object* >(getNodeId()))->toString());
            npc(::java::lang::System::out())->println(static_cast< ::java::lang::Object* >(getLeafSet()));
        }
    }
}

void rice::pastry::testing::RegrTestApp::forward(::rice::pastry::routing::RouteMessage* rm)
{
    ::rice::pastry::messaging::Message* msg;
    try {
        msg = npc(rm)->unwrap(deserializer);
    } catch (::java::io::IOException* ioe) {
        throw new ::java::lang::RuntimeException(::java::lang::StringBuilder().append(u"Error deserializing message "_j)->append(static_cast< ::java::lang::Object* >(rm))->toString(), ioe);
    }
    auto key = npc(rm)->getTarget();
    auto nextHop = npc(npc(rm)->getNextHop())->getNodeId();
    auto localId = getNodeId();
    auto dist = npc(localId)->distance(key);
    int32_t base = npc(getRoutingTable())->baseBitLength();
    if(npc(prg)->lastMsg == msg) {
        auto localIndex = npc(localId)->indexOfMSDD(key, base);
        auto lastIndex = npc(npc(prg)->lastNode)->indexOfMSDD(key, base);
        if((localIndex > lastIndex && nextHop != localId) || (localIndex == lastIndex && npc(dist)->compareTo(static_cast< ::rice::p2p::commonapi::Id_Distance* >(npc(prg)->lastDist)) > 0))
            npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"at... "_j)->append(static_cast< ::java::lang::Object* >(getNodeId()))
                ->append(u" enrouteMessage failure with "_j)
                ->append(static_cast< ::java::lang::Object* >(msg))
                ->append(u" lastNode="_j)
                ->append(static_cast< ::java::lang::Object* >(npc(prg)->lastNode))
                ->append(u" lastDist="_j)
                ->append(static_cast< ::java::lang::Object* >(npc(prg)->lastDist))
                ->append(u" dist="_j)
                ->append(static_cast< ::java::lang::Object* >(dist))
                ->append(u" nextHop="_j)
                ->append(static_cast< ::java::lang::Object* >(nextHop))
                ->append(u" loci="_j)
                ->append(localIndex)
                ->append(u" lasti="_j)
                ->append(lastIndex)->toString());

        npc(prg)->lastDist = dist;
    }
    npc(prg)->lastMsg = msg;
    npc(prg)->lastDist = dist;
    npc(prg)->lastNode = localId;
}

void rice::pastry::testing::RegrTestApp::update(::rice::pastry::NodeHandle* nh, bool wasAdded)
{
    auto const nid = npc(nh)->getNodeId();
    if(!npc(npc(prg)->pastryNodesSorted)->containsKey(nid) && npc(nh)->isAlive())
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"at... "_j)->append(static_cast< ::java::lang::Object* >(getNodeId()))
            ->append(u"leafSetChange failure 1 with "_j)
            ->append(static_cast< ::java::lang::Object* >(nid))->toString());

    auto localId = npc(thePastryNode)->getNodeId();
    if(localId == nid)
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"at... "_j)->append(static_cast< ::java::lang::Object* >(getNodeId()))
            ->append(u"leafSetChange failure 2 with "_j)
            ->append(static_cast< ::java::lang::Object* >(nid))->toString());

    int32_t inBetween;
    if(npc(localId)->compareTo(static_cast< ::rice::p2p::commonapi::Id* >(nid)) < 0) {
        auto i1 = npc(npc(npc(prg)->pastryNodesSorted)->subMap(localId, nid))->size();
        auto i2 = npc(npc(npc(prg)->pastryNodesSorted)->tailMap(nid))->size() + npc(npc(npc(prg)->pastryNodesSorted)->headMap(localId))->size();
        inBetween = (i1 < i2) ? i1 : i2;
    } else {
        auto i1 = npc(npc(npc(prg)->pastryNodesSorted)->subMap(nid, localId))->size();
        auto i2 = npc(npc(npc(prg)->pastryNodesSorted)->tailMap(localId))->size() + npc(npc(npc(prg)->pastryNodesSorted)->headMap(nid))->size();
        inBetween = (i1 < i2) ? i1 : i2;
    }
    auto lsSize = npc(getLeafSet())->maxSize() / int32_t(2);
    if((inBetween > lsSize && wasAdded && !npc(npc(prg)->pastryNodesLastAdded)->contains(static_cast< ::java::lang::Object* >(thePastryNode)) && !npc(prg)->inConcJoin) || (inBetween <= lsSize && !wasAdded && !npc(getLeafSet())->member(nh)) && npc(npc(prg)->pastryNodesSorted)->containsKey(npc(nh)->getNodeId())) {
    }
}

void rice::pastry::testing::RegrTestApp::routeSetChange(::rice::pastry::NodeHandle* nh, bool wasAdded)
{
    auto nid = npc(nh)->getNodeId();
    if(!npc(npc(prg)->pastryNodesSorted)->containsKey(nid)) {
        if(npc(nh)->isAlive() || wasAdded)
            npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"at... "_j)->append(static_cast< ::java::lang::Object* >(getNodeId()))
                ->append(u"routeSetChange failure 1 with "_j)
                ->append(static_cast< ::java::lang::Object* >(nid))
                ->append(u" wasAdded="_j)
                ->append(wasAdded)->toString());

    }
}

void rice::pastry::testing::RegrTestApp::notifyReady()
{
}

rice::pastry::PastryNode* rice::pastry::testing::RegrTestApp::getPastryNode()
{
    return thePastryNode;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::testing::RegrTestApp::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.testing.RegrTestApp", 31);
    return c;
}

void rice::pastry::testing::RegrTestApp::clinit()
{
    super::clinit();
    static bool in_cl_init = false;
struct clinit_ {
    clinit_() {
        in_cl_init = true;
        addr_ = RegrTestApp_RTAddress::getCode();
    }
};

    if(!in_cl_init) {
        static clinit_ clinit_instance;
    }
}

java::lang::Class* rice::pastry::testing::RegrTestApp::getClass0()
{
    return class_();
}

