// Generated from /pastry-2.1/src/rice/pastry/direct/DirectNodeHandle.java
#include <rice/pastry/direct/DirectNodeHandle.hpp>

#include <java/lang/Class.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Integer.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/RuntimeException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/System.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/LogManager.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/p2p/commonapi/rawserialization/OutputBuffer.hpp>
#include <rice/p2p/commonapi/rawserialization/SizeCheckOutputBuffer.hpp>
#include <rice/pastry/Id.hpp>
#include <rice/pastry/NodeHandle.hpp>
#include <rice/pastry/PastryNode.hpp>
#include <rice/pastry/direct/DirectPastryNode.hpp>
#include <rice/pastry/direct/NetworkSimulator.hpp>
#include <rice/pastry/direct/NodeRecord.hpp>

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

rice::pastry::direct::DirectNodeHandle::DirectNodeHandle(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::direct::DirectNodeHandle::DirectNodeHandle(::rice::pastry::PastryNode* ln, NetworkSimulator* sim) 
    : DirectNodeHandle(*static_cast< ::default_init_tag* >(0))
{
    ctor(ln,sim);
}

void rice::pastry::direct::DirectNodeHandle::ctor(::rice::pastry::PastryNode* ln, NetworkSimulator* sim)
{
    super::ctor();
    localnode = ln;
    logger = npc(npc(npc(ln)->getEnvironment())->getLogManager())->getLogger(getClass(), nullptr);
    simulator = sim;
    npc(ln)->addObserver(this);
}

rice::pastry::PastryNode* rice::pastry::direct::DirectNodeHandle::getRemote()
{
    return localnode;
}

rice::pastry::Id* rice::pastry::direct::DirectNodeHandle::getNodeId()
{
    return npc(localnode)->getNodeId();
}

int32_t rice::pastry::direct::DirectNodeHandle::getLiveness()
{
    if(npc(simulator)->isAlive(this)) {
        return LIVENESS_ALIVE;
    }
    return LIVENESS_DEAD;
}

rice::pastry::direct::NetworkSimulator* rice::pastry::direct::DirectNodeHandle::getSimulator()
{
    return simulator;
}

void rice::pastry::direct::DirectNodeHandle::notifyObservers(::java::lang::Object* arg)
{
    setChanged();
    super::notifyObservers(arg);
}

bool rice::pastry::direct::DirectNodeHandle::ping()
{
    return isAlive();
}

void rice::pastry::direct::DirectNodeHandle::assertLocalNode()
{
    if(DirectPastryNode::getCurrentNode() == nullptr) {
        throw new ::java::lang::RuntimeException(::java::lang::StringBuilder().append(u"PANIC: localnode is null in "_j)->append(static_cast< ::java::lang::Object* >(this))
            ->append(u"@"_j)
            ->append(::java::lang::System::identityHashCode(this))->toString());
    }
}

int32_t rice::pastry::direct::DirectNodeHandle::proximity()
{
    assertLocalNode();
    return npc(getLocalNode())->proximity(this);
}

void rice::pastry::direct::DirectNodeHandle::receiveMessage(::rice::pastry::messaging::Message* msg)
{
    npc(DirectPastryNode::getCurrentNode())->send(this, msg, nullptr, nullptr);
}

bool rice::pastry::direct::DirectNodeHandle::equals(::java::lang::Object* obj)
{
    return obj == static_cast< ::java::lang::Object* >(this);
}

int32_t rice::pastry::direct::DirectNodeHandle::hashCode()
{
    return npc(this->getNodeId())->hashCode();
}

java::lang::String* rice::pastry::direct::DirectNodeHandle::toString()
{
    return ::java::lang::StringBuilder().append(u"[DNH "_j)->append(static_cast< ::java::lang::Object* >(getNodeId()))
        ->append(u"]"_j)->toString();
}

void rice::pastry::direct::DirectNodeHandle::update(::java::util::Observable* arg0, ::java::lang::Object* arg1)
{
    if(npc(simulator)->isAlive(this)) {
    } else {
        notifyObservers(static_cast< ::java::lang::Object* >(::rice::pastry::NodeHandle::DECLARED_DEAD()));
    }
}

void rice::pastry::direct::DirectNodeHandle::serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */
{
    if(dynamic_cast< ::rice::p2p::commonapi::rawserialization::SizeCheckOutputBuffer* >(buf) != nullptr) {
        npc((java_cast< ::rice::p2p::commonapi::rawserialization::SizeCheckOutputBuffer* >(buf)))->writeSpecial(this);
    } else {
        throw new ::java::lang::RuntimeException(u"DirectNodeHandle.serialize() Should not be called.  If you are doing this to determine the size, please use a SizeCheckOutputBuffer such as the DirectSizeChecker."_j);
    }
}

rice::pastry::direct::NodeRecord* rice::pastry::direct::DirectNodeHandle::getAddress()
{
    return npc(simulator)->getNodeRecord(this);
}

int64_t rice::pastry::direct::DirectNodeHandle::getEpoch()
{
    return 0;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::direct::DirectNodeHandle::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.direct.DirectNodeHandle", 35);
    return c;
}

void rice::pastry::direct::DirectNodeHandle::update(::java::lang::Object* update)
{
    super::update(update);
}

void rice::pastry::direct::DirectNodeHandle::notifyObservers()
{
    super::notifyObservers();
}

java::lang::Class* rice::pastry::direct::DirectNodeHandle::getClass0()
{
    return class_();
}

