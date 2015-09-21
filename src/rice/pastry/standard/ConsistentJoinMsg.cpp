// Generated from /pastry-2.1/src/rice/pastry/standard/ConsistentJoinMsg.java
#include <rice/pastry/standard/ConsistentJoinMsg.hpp>

#include <java/io/IOException.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/util/HashSet.hpp>
#include <java/util/Iterator.hpp>
#include <rice/p2p/commonapi/rawserialization/InputBuffer.hpp>
#include <rice/p2p/commonapi/rawserialization/OutputBuffer.hpp>
#include <rice/pastry/NodeHandle.hpp>
#include <rice/pastry/NodeHandleFactory.hpp>
#include <rice/pastry/join/JoinAddress.hpp>
#include <rice/pastry/leafset/LeafSet.hpp>

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

rice::pastry::standard::ConsistentJoinMsg::ConsistentJoinMsg(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::standard::ConsistentJoinMsg::ConsistentJoinMsg(::rice::pastry::leafset::LeafSet* ls, ::java::util::HashSet* failed, bool request) 
    : ConsistentJoinMsg(*static_cast< ::default_init_tag* >(0))
{
    ctor(ls,failed,request);
}

rice::pastry::standard::ConsistentJoinMsg::ConsistentJoinMsg(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::pastry::NodeHandleFactory* nhf, ::rice::pastry::NodeHandle* sender)  /* throws(IOException) */
    : ConsistentJoinMsg(*static_cast< ::default_init_tag* >(0))
{
    ctor(buf,nhf,sender);
}

constexpr int64_t rice::pastry::standard::ConsistentJoinMsg::serialVersionUID;

constexpr int16_t rice::pastry::standard::ConsistentJoinMsg::TYPE;

void rice::pastry::standard::ConsistentJoinMsg::ctor(::rice::pastry::leafset::LeafSet* ls, ::java::util::HashSet* failed, bool request)
{
    super::ctor(::rice::pastry::join::JoinAddress::getCode());
    this->ls = ls;
    this->request = request;
    this->failed = failed;
}

java::lang::String* rice::pastry::standard::ConsistentJoinMsg::toString()
{
    return ::java::lang::StringBuilder().append(u"ConsistentJoinMsg "_j)->append(static_cast< ::java::lang::Object* >(ls))
        ->append(u" request:"_j)
        ->append(request)->toString();
}

int16_t rice::pastry::standard::ConsistentJoinMsg::getType()
{
    return TYPE;
}

void rice::pastry::standard::ConsistentJoinMsg::serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */
{
    npc(buf)->writeByte(static_cast< int8_t >(int32_t(0)));
    npc(ls)->serialize(buf);
    npc(buf)->writeBoolean(request);
    npc(buf)->writeInt(npc(failed)->size());
    auto i = npc(failed)->iterator();
    while (npc(i)->hasNext()) {
        auto h = java_cast< ::rice::pastry::NodeHandle* >(java_cast< ::rice::pastry::NodeHandle* >(npc(i)->next()));
        npc(h)->serialize(buf);
    }
}

void rice::pastry::standard::ConsistentJoinMsg::ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::pastry::NodeHandleFactory* nhf, ::rice::pastry::NodeHandle* sender) /* throws(IOException) */
{
    super::ctor(::rice::pastry::join::JoinAddress::getCode());
    auto version = npc(buf)->readByte();
    {
        int32_t numInSet;
        switch (version) {
        case int32_t(0):
            setSender(sender);
            ls = ::rice::pastry::leafset::LeafSet::build(buf, nhf);
            request = npc(buf)->readBoolean();
            failed = new ::java::util::HashSet();
            numInSet = npc(buf)->readInt();
            for (auto i = int32_t(0); i < numInSet; i++) {
                npc(failed)->add(static_cast< ::java::lang::Object* >(java_cast< ::rice::pastry::NodeHandle* >(npc(nhf)->readNodeHandle(buf))));
            }
            break;
        default:
            throw new ::java::io::IOException(::java::lang::StringBuilder().append(u"Unknown Version: "_j)->append(version)->toString());
        }
    }

}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::standard::ConsistentJoinMsg::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.standard.ConsistentJoinMsg", 38);
    return c;
}

java::lang::Class* rice::pastry::standard::ConsistentJoinMsg::getClass0()
{
    return class_();
}

