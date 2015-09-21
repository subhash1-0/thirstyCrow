// Generated from /pastry-2.1/src/rice/pastry/routing/RouteMessage.java
#include <rice/pastry/routing/RouteMessage.hpp>

#include <java/io/IOException.hpp>
#include <java/lang/Byte.hpp>
#include <java/lang/Class.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/IllegalStateException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/RuntimeException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/Throwable.hpp>
#include <java/util/Map.hpp>
#include <rice/p2p/commonapi/Cancellable.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/commonapi/Message.hpp>
#include <rice/p2p/commonapi/NodeHandle.hpp>
#include <rice/p2p/commonapi/rawserialization/InputBuffer.hpp>
#include <rice/p2p/commonapi/rawserialization/MessageDeserializer.hpp>
#include <rice/p2p/commonapi/rawserialization/OutputBuffer.hpp>
#include <rice/p2p/commonapi/rawserialization/RawMessage.hpp>
#include <rice/p2p/util/rawserialization/SimpleInputBuffer.hpp>
#include <rice/pastry/Id.hpp>
#include <rice/pastry/NodeHandle.hpp>
#include <rice/pastry/PastryNode.hpp>
#include <rice/pastry/commonapi/PastryEndpointMessage.hpp>
#include <rice/pastry/messaging/JavaSerializedDeserializer.hpp>
#include <rice/pastry/messaging/Message.hpp>
#include <rice/pastry/messaging/PJavaSerializedMessage.hpp>
#include <rice/pastry/messaging/PRawMessage.hpp>
#include <rice/pastry/routing/RouteMessage_RMDeserializer.hpp>
#include <rice/pastry/routing/RouteMessageNotification.hpp>
#include <rice/pastry/routing/RouterAddress.hpp>
#include <rice/pastry/routing/SendOptions.hpp>
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

rice::pastry::routing::RouteMessage::RouteMessage(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::routing::RouteMessage::RouteMessage(::rice::pastry::Id* target, ::rice::pastry::messaging::Message* msg, int8_t serializeVersion) 
    : RouteMessage(*static_cast< ::default_init_tag* >(0))
{
    ctor(target,msg,serializeVersion);
}

rice::pastry::routing::RouteMessage::RouteMessage(::rice::pastry::Id* target, ::rice::pastry::messaging::Message* msg, SendOptions* opts, int8_t serializeVersion) 
    : RouteMessage(*static_cast< ::default_init_tag* >(0))
{
    ctor(target,msg,opts,serializeVersion);
}

rice::pastry::routing::RouteMessage::RouteMessage(::rice::pastry::NodeHandle* dest, ::rice::pastry::messaging::Message* msg, SendOptions* opts, int8_t serializeVersion) 
    : RouteMessage(*static_cast< ::default_init_tag* >(0))
{
    ctor(dest,msg,opts,serializeVersion);
}

rice::pastry::routing::RouteMessage::RouteMessage(::rice::pastry::Id* target, ::rice::pastry::messaging::Message* msg, ::rice::pastry::NodeHandle* firstHop, int8_t serializeVersion) 
    : RouteMessage(*static_cast< ::default_init_tag* >(0))
{
    ctor(target,msg,firstHop,serializeVersion);
}

rice::pastry::routing::RouteMessage::RouteMessage(::rice::pastry::Id* target, ::rice::pastry::messaging::PRawMessage* msg, ::rice::pastry::NodeHandle* firstHop, SendOptions* opts, int8_t serializeVersion) 
    : RouteMessage(*static_cast< ::default_init_tag* >(0))
{
    ctor(target,msg,firstHop,opts,serializeVersion);
}

rice::pastry::routing::RouteMessage::RouteMessage(::rice::pastry::Id* target, ::rice::pastry::messaging::Message* msg, ::rice::pastry::NodeHandle* firstHop, SendOptions* opts, int8_t serializeVersion) 
    : RouteMessage(*static_cast< ::default_init_tag* >(0))
{
    ctor(target,msg,firstHop,opts,serializeVersion);
}

rice::pastry::routing::RouteMessage::RouteMessage(::rice::pastry::Id* target, int32_t auxAddress, ::rice::pastry::NodeHandle* prev, ::rice::p2p::commonapi::rawserialization::InputBuffer* buf, int8_t priority, ::rice::pastry::PastryNode* pn, ::rice::pastry::NodeHandle* destinationHandle, int8_t serializeVersion)  /* throws(IOException) */
    : RouteMessage(*static_cast< ::default_init_tag* >(0))
{
    ctor(target,auxAddress,prev,buf,priority,pn,destinationHandle,serializeVersion);
}

void rice::pastry::routing::RouteMessage::init()
{
    rawInternalMsg = nullptr;
    numRetries = int32_t(0);
    endpointDeserializer = new RouteMessage_RMDeserializer(this);
}

constexpr int64_t rice::pastry::routing::RouteMessage::serialVersionUID;

constexpr int16_t rice::pastry::routing::RouteMessage::TYPE;

void rice::pastry::routing::RouteMessage::ctor(::rice::pastry::Id* target, ::rice::pastry::messaging::Message* msg, int8_t serializeVersion)
{
    ctor(target, msg, static_cast< ::rice::pastry::NodeHandle* >(nullptr), static_cast< SendOptions* >(nullptr), serializeVersion);
}

void rice::pastry::routing::RouteMessage::ctor(::rice::pastry::Id* target, ::rice::pastry::messaging::Message* msg, SendOptions* opts, int8_t serializeVersion)
{
    ctor(target, msg, static_cast< ::rice::pastry::NodeHandle* >(nullptr), opts, serializeVersion);
}

void rice::pastry::routing::RouteMessage::ctor(::rice::pastry::NodeHandle* dest, ::rice::pastry::messaging::Message* msg, SendOptions* opts, int8_t serializeVersion)
{
    ctor(npc(dest)->getNodeId(), msg, dest, opts, serializeVersion);
}

void rice::pastry::routing::RouteMessage::ctor(::rice::pastry::Id* target, ::rice::pastry::messaging::Message* msg, ::rice::pastry::NodeHandle* firstHop, int8_t serializeVersion)
{
    ctor(target, msg, firstHop, static_cast< SendOptions* >(nullptr), serializeVersion);
}

rice::pastry::messaging::PRawMessage* rice::pastry::routing::RouteMessage::convert(::rice::pastry::messaging::Message* msg)
{
    clinit();
    if(dynamic_cast< ::rice::pastry::messaging::PRawMessage* >(msg) != nullptr) {
        auto prm = java_cast< ::rice::pastry::messaging::PRawMessage* >(msg);
        if(npc(prm)->getType() == 0)
            if(dynamic_cast< ::rice::pastry::messaging::PJavaSerializedMessage* >(prm) != nullptr)
                throw new ::java::lang::RuntimeException(::java::lang::StringBuilder().append(u"Cannot route a PJavaSerializedMessage, this is used internally in RouteMessage."_j)->append(static_cast< ::java::lang::Object* >(msg))
                    ->append(u" "_j)
                    ->append(npc(npc(msg)->getClass())->getName())->toString());


        return prm;
    }
    return new ::rice::pastry::messaging::PJavaSerializedMessage(msg);
}

void rice::pastry::routing::RouteMessage::ctor(::rice::pastry::Id* target, ::rice::pastry::messaging::PRawMessage* msg, ::rice::pastry::NodeHandle* firstHop, SendOptions* opts, int8_t serializeVersion)
{
    ctor(target, java_cast< ::rice::pastry::messaging::Message* >(msg), firstHop, opts, serializeVersion);
    rawInternalMsg = msg;
    if(msg != nullptr)
        internalType = npc(msg)->getType();

}

void rice::pastry::routing::RouteMessage::ctor(::rice::pastry::Id* target, ::rice::pastry::messaging::Message* msg, ::rice::pastry::NodeHandle* firstHop, SendOptions* opts, int8_t serializeVersion)
{
    super::ctor(RouterAddress::getCode());
    init();
    this->version = serializeVersion;
    this->target = java_cast< ::rice::pastry::Id* >(target);
    internalMsg = msg;
    nextHop = firstHop;
    this->opts = opts;
    if(this->opts == nullptr)
        this->opts = new SendOptions();

    if(msg != nullptr)
        auxAddress = npc(msg)->getDestination();

}

rice::pastry::Id* rice::pastry::routing::RouteMessage::getTarget()
{
    return target;
}

rice::pastry::NodeHandle* rice::pastry::routing::RouteMessage::getPrevNode()
{
    return prevNode;
}

void rice::pastry::routing::RouteMessage::setPrevNode(::rice::pastry::NodeHandle* n)
{
    prevNode = n;
}

rice::pastry::NodeHandle* rice::pastry::routing::RouteMessage::getNextHop()
{
    return nextHop;
}

void rice::pastry::routing::RouteMessage::setNextHop(::rice::pastry::NodeHandle* nh)
{
    nextHop = nh;
}

int32_t rice::pastry::routing::RouteMessage::getPriority()
{
    if(internalMsg != nullptr)
        return npc(internalMsg)->getPriority();

    return internalPriority;
}

rice::pastry::messaging::Message* rice::pastry::routing::RouteMessage::unwrap()
{
    if(internalMsg != nullptr) {
        return internalMsg;
    }
    try {
        npc(endpointDeserializer)->setSubDeserializer(new ::rice::pastry::messaging::JavaSerializedDeserializer(pn));
        return unwrap(endpointDeserializer);
    } catch (::java::io::IOException* ioe) {
        throw new ::java::lang::RuntimeException(static_cast< ::java::lang::Throwable* >(ioe));
    }
}

rice::pastry::routing::SendOptions* rice::pastry::routing::RouteMessage::getOptions()
{
    if(opts == nullptr) {
        opts = new SendOptions();
    }
    return opts;
}

java::lang::String* rice::pastry::routing::RouteMessage::toString()
{
    if(internalMsg == nullptr) {
        return ::java::lang::StringBuilder().append(u"R[serialized{"_j)->append(auxAddress)
            ->append(u","_j)
            ->append(internalType)
            ->append(u"}]"_j)->toString();
    }
    auto str = ::java::lang::StringBuilder().append(u"R["_j)->append(static_cast< ::java::lang::Object* >(internalMsg))
        ->append(u"]"_j)->toString();
    return str;
}

rice::p2p::commonapi::Id* rice::pastry::routing::RouteMessage::getDestinationId()
{
    return getTarget();
}

rice::p2p::commonapi::NodeHandle* rice::pastry::routing::RouteMessage::getNextHopHandle()
{
    return nextHop;
}

rice::p2p::commonapi::Message* rice::pastry::routing::RouteMessage::getMessage()
{
    return npc((java_cast< ::rice::pastry::commonapi::PastryEndpointMessage* >(unwrap())))->getMessage();
}

rice::p2p::commonapi::Message* rice::pastry::routing::RouteMessage::getMessage(::rice::p2p::commonapi::rawserialization::MessageDeserializer* md) /* throws(IOException) */
{
    npc(endpointDeserializer)->setSubDeserializer(md);
    return npc((java_cast< ::rice::pastry::commonapi::PastryEndpointMessage* >(unwrap(endpointDeserializer))))->getMessage();
}

void rice::pastry::routing::RouteMessage::setDestinationId(::rice::p2p::commonapi::Id* id)
{
    target = java_cast< ::rice::pastry::Id* >(id);
}

void rice::pastry::routing::RouteMessage::setNextHopHandle(::rice::p2p::commonapi::NodeHandle* nextHop)
{
    this->nextHop = java_cast< ::rice::pastry::NodeHandle* >(nextHop);
}

void rice::pastry::routing::RouteMessage::setMessage(::rice::p2p::commonapi::Message* message)
{
    npc((java_cast< ::rice::pastry::commonapi::PastryEndpointMessage* >(unwrap())))->setMessage(message);
}

void rice::pastry::routing::RouteMessage::setMessage(::rice::p2p::commonapi::rawserialization::RawMessage* message)
{
    npc((java_cast< ::rice::pastry::commonapi::PastryEndpointMessage* >(unwrap())))->setMessage(message);
}

rice::pastry::routing::RouteMessage* rice::pastry::routing::RouteMessage::build(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, int8_t priority, ::rice::pastry::PastryNode* pn, ::rice::pastry::NodeHandle* prev, int8_t outputVersion) /* throws(IOException) */
{
    clinit();
    auto version = npc(buf)->readByte();
    switch (version) {
    case int32_t(0): {
            auto auxAddress = npc(buf)->readInt();
            auto target = ::rice::pastry::Id::build(buf);
            return new ::rice::pastry::routing::RouteMessage(target, auxAddress, prev, buf, priority, pn, nullptr, outputVersion);
        }
    case int32_t(1): {
            auto auxAddress = npc(buf)->readInt();
            ::rice::pastry::NodeHandle* destHandle = nullptr;
            ::rice::pastry::Id* target = nullptr;
            auto hasDestHandle = npc(buf)->readBoolean();
            if(hasDestHandle) {
                destHandle = npc(pn)->readNodeHandle(buf);
                target = java_cast< ::rice::pastry::Id* >(npc(destHandle)->getId());
            } else {
                target = ::rice::pastry::Id::build(buf);
            }
            return new ::rice::pastry::routing::RouteMessage(target, auxAddress, prev, buf, priority, pn, destHandle, outputVersion);
        }
    default:
        throw new ::java::io::IOException(::java::lang::StringBuilder().append(u"Unknown Version: "_j)->append(version)->toString());
    }

}

void rice::pastry::routing::RouteMessage::ctor(::rice::pastry::Id* target, int32_t auxAddress, ::rice::pastry::NodeHandle* prev, ::rice::p2p::commonapi::rawserialization::InputBuffer* buf, int8_t priority, ::rice::pastry::PastryNode* pn, ::rice::pastry::NodeHandle* destinationHandle, int8_t serializeVersion) /* throws(IOException) */
{
    ctor(target, static_cast< ::rice::pastry::messaging::PRawMessage* >(nullptr), static_cast< ::rice::pastry::NodeHandle* >(nullptr), static_cast< SendOptions* >(nullptr), serializeVersion);
    hasSender = npc(buf)->readBoolean();
    internalPriority = priority;
    internalType = npc(buf)->readShort();
    prevNode = prev;
    serializedMsg = buf;
    this->destinationHandle = destinationHandle;
    this->pn = pn;
    this->auxAddress = auxAddress;
}

void rice::pastry::routing::RouteMessage::serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */
{
    npc(buf)->writeByte(version);
    npc(buf)->writeInt(auxAddress);
    switch (version) {
    case int32_t(0):
        npc(target)->serialize(buf);
        break;
    case int32_t(1):
        npc(buf)->writeBoolean(destinationHandle != nullptr);
        if(destinationHandle != nullptr) {
            npc(destinationHandle)->serialize(buf);
        } else {
            npc(target)->serialize(buf);
        }
    }

    if(serializedMsg != nullptr) {
        npc(buf)->writeBoolean(hasSender);
        npc(buf)->writeShort(internalType);
        auto raw = new ::int8_tArray(npc(serializedMsg)->bytesRemaining());
        npc(serializedMsg)->read(raw);
        npc(buf)->write(raw, 0, npc(raw)->length);
        serializedMsg = new ::rice::p2p::util::rawserialization::SimpleInputBuffer(raw);
    } else {
        if(rawInternalMsg == nullptr) {
            rawInternalMsg = convert(internalMsg);
        }
        auto sender = npc(rawInternalMsg)->getSender();
        auto hasSender = (sender != nullptr);
        if(hasSender) {
            npc(buf)->writeBoolean(true);
        } else {
            npc(buf)->writeBoolean(false);
        }
        auto priority = npc(rawInternalMsg)->getPriority();
        if(priority > ::java::lang::Byte::MAX_VALUE)
            throw new ::java::lang::IllegalStateException(::java::lang::StringBuilder().append(u"Priority must be in the range of "_j)->append(::java::lang::Byte::MIN_VALUE)
                ->append(u" to "_j)
                ->append(::java::lang::Byte::MAX_VALUE)
                ->append(u".  Lower values are higher priority. Priority of "_j)
                ->append(static_cast< ::java::lang::Object* >(rawInternalMsg))
                ->append(u" was "_j)
                ->append(priority)
                ->append(u"."_j)->toString());

        if(priority < ::java::lang::Byte::MIN_VALUE)
            throw new ::java::lang::IllegalStateException(::java::lang::StringBuilder().append(u"Priority must be in the range of "_j)->append(::java::lang::Byte::MIN_VALUE)
                ->append(u" to "_j)
                ->append(::java::lang::Byte::MAX_VALUE)
                ->append(u".  Lower values are higher priority. Priority of "_j)
                ->append(static_cast< ::java::lang::Object* >(rawInternalMsg))
                ->append(u" was "_j)
                ->append(priority)
                ->append(u"."_j)->toString());

        auto type = npc(rawInternalMsg)->getType();
        npc(buf)->writeShort(type);
        if(hasSender) {
            npc(sender)->serialize(buf);
        }
        npc(rawInternalMsg)->serialize(buf);
    }
}

rice::pastry::messaging::Message* rice::pastry::routing::RouteMessage::unwrap(::rice::p2p::commonapi::rawserialization::MessageDeserializer* md) /* throws(IOException) */
{
    if(internalMsg != nullptr) {
        return internalMsg;
    }
    ::rice::pastry::NodeHandle* internalSender = nullptr;
    if(hasSender) {
        internalSender = npc(pn)->readNodeHandle(serializedMsg);
    }
    internalMsg = java_cast< ::rice::pastry::messaging::Message* >(npc(md)->deserialize(serializedMsg, internalType, internalPriority, internalSender));
    serializedMsg = nullptr;
    pn = nullptr;
    return internalMsg;
}

int16_t rice::pastry::routing::RouteMessage::getType()
{
    return TYPE;
}

int32_t rice::pastry::routing::RouteMessage::getAuxAddress()
{
    return auxAddress;
}

int16_t rice::pastry::routing::RouteMessage::getInternalType()
{
    if(rawInternalMsg != nullptr)
        return npc(rawInternalMsg)->getType();

    if(internalMsg != nullptr) {
        if(dynamic_cast< ::rice::p2p::commonapi::rawserialization::RawMessage* >(internalMsg) != nullptr) {
            return npc((java_cast< ::rice::p2p::commonapi::rawserialization::RawMessage* >(internalMsg)))->getType();
        }
        return 0;
    }
    return -int32_t(1);
}

void rice::pastry::routing::RouteMessage::setDestinationHandle(::rice::pastry::NodeHandle* handle)
{
    destinationHandle = handle;
}

rice::pastry::NodeHandle* rice::pastry::routing::RouteMessage::getDestinationHandle()
{
    return destinationHandle;
}

java::util::Map* rice::pastry::routing::RouteMessage::getTLOptions()
{
    return options;
}

void rice::pastry::routing::RouteMessage::setTLOptions(::java::util::Map* options)
{
    this->options = options;
}

void rice::pastry::routing::RouteMessage::setTLCancellable(::rice::p2p::commonapi::Cancellable* c)
{
    tlCancellable = c;
}

bool rice::pastry::routing::RouteMessage::cancel()
{
    return npc(tlCancellable)->cancel();
}

void rice::pastry::routing::RouteMessage::setRouteMessageNotification(RouteMessageNotification* notification)
{
    notifyMe = notification;
}

void rice::pastry::routing::RouteMessage::sendSuccess(::rice::pastry::NodeHandle* nextHop)
{
    if(notifyMe != nullptr)
        npc(notifyMe)->sendSuccess(this, nextHop);

}

bool rice::pastry::routing::RouteMessage::sendFailed(::java::lang::Exception* e)
{
    if(notifyMe != nullptr)
        npc(notifyMe)->sendFailed(this, e);

    return notifyMe != nullptr;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::routing::RouteMessage::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.routing.RouteMessage", 32);
    return c;
}

java::lang::Class* rice::pastry::routing::RouteMessage::getClass0()
{
    return class_();
}

