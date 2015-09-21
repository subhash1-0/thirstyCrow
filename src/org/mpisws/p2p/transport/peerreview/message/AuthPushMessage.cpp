// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/message/AuthPushMessage.java
#include <org/mpisws/p2p/transport/peerreview/message/AuthPushMessage.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/util/ArrayList.hpp>
#include <java/util/HashMap.hpp>
#include <java/util/Iterator.hpp>
#include <java/util/List.hpp>
#include <java/util/Map_Entry.hpp>
#include <java/util/Map.hpp>
#include <java/util/Set.hpp>
#include <org/mpisws/p2p/transport/peerreview/commitment/Authenticator.hpp>
#include <org/mpisws/p2p/transport/peerreview/commitment/AuthenticatorSerializer.hpp>
#include <org/mpisws/p2p/transport/util/Serializer.hpp>
#include <rice/p2p/commonapi/rawserialization/InputBuffer.hpp>
#include <rice/p2p/commonapi/rawserialization/OutputBuffer.hpp>
#include <rice/p2p/commonapi/rawserialization/RawSerializable.hpp>

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

org::mpisws::p2p::transport::peerreview::message::AuthPushMessage::AuthPushMessage(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::transport::peerreview::message::AuthPushMessage::AuthPushMessage(::java::util::Map* authenticators) 
    : AuthPushMessage(*static_cast< ::default_init_tag* >(0))
{
    ctor(authenticators);
}

void org::mpisws::p2p::transport::peerreview::message::AuthPushMessage::ctor(::java::util::Map* authenticators)
{
    super::ctor();
    this->authenticators = authenticators;
}

int16_t org::mpisws::p2p::transport::peerreview::message::AuthPushMessage::getType()
{
    return MSG_AUTHPUSH;
}

/* <I extends RawSerializable> */org::mpisws::p2p::transport::peerreview::message::AuthPushMessage* org::mpisws::p2p::transport::peerreview::message::AuthPushMessage::build(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::org::mpisws::p2p::transport::util::Serializer* idSerializer, ::org::mpisws::p2p::transport::peerreview::commitment::AuthenticatorSerializer* authSerializer) /* throws(IOException) */
{
    clinit();
    ::java::util::Map* authenticators = new ::java::util::HashMap();
    int32_t numIds = npc(buf)->readShort();
    for (auto i = int32_t(0); i < numIds; i++) {
        auto id = java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(idSerializer)->deserialize(buf));
        int32_t numAuths = npc(buf)->readShort();
        ::java::util::List* l = new ::java::util::ArrayList();
        npc(authenticators)->put(id, l);
        for (auto a = int32_t(0); a < numAuths; a++) {
            npc(l)->add(static_cast< ::java::lang::Object* >(npc(authSerializer)->deserialize(buf)));
        }
    }
    return new AuthPushMessage(authenticators);
}

void org::mpisws::p2p::transport::peerreview::message::AuthPushMessage::serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */
{
    npc(buf)->writeShort(static_cast< int16_t >(npc(authenticators)->size()));
    for (auto _i = npc(npc(authenticators)->entrySet())->iterator(); _i->hasNext(); ) {
        ::java::util::Map_Entry* e = java_cast< ::java::util::Map_Entry* >(_i->next());
        {
            npc(java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(e)->getKey()))->serialize(buf);
            npc(buf)->writeShort(static_cast< int16_t >(npc(java_cast< ::java::util::List* >(npc(e)->getValue()))->size()));
            for (auto _i = npc(java_cast< ::java::util::List* >(npc(e)->getValue()))->iterator(); _i->hasNext(); ) {
                ::org::mpisws::p2p::transport::peerreview::commitment::Authenticator* a = java_cast< ::org::mpisws::p2p::transport::peerreview::commitment::Authenticator* >(_i->next());
                {
                    npc(a)->serialize(buf);
                }
            }
        }
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::peerreview::message::AuthPushMessage::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.peerreview.message.AuthPushMessage", 59);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::peerreview::message::AuthPushMessage::getClass0()
{
    return class_();
}

