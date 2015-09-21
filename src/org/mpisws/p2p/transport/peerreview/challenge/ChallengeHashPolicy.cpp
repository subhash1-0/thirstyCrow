// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/challenge/ChallengeHashPolicy.java
#include <org/mpisws/p2p/transport/peerreview/challenge/ChallengeHashPolicy.hpp>

#include <java/io/IOException.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/util/Serializer.hpp>
#include <rice/p2p/util/rawserialization/SimpleInputBuffer.hpp>

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

org::mpisws::p2p::transport::peerreview::challenge::ChallengeHashPolicy::ChallengeHashPolicy(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::transport::peerreview::challenge::ChallengeHashPolicy::ChallengeHashPolicy(int8_t flags, ::java::lang::Object* originator, ::org::mpisws::p2p::transport::util::Serializer* idSerializer) 
    : ChallengeHashPolicy(*static_cast< ::default_init_tag* >(0))
{
    ctor(flags,originator,idSerializer);
}

void org::mpisws::p2p::transport::peerreview::challenge::ChallengeHashPolicy::ctor(int8_t flags, ::java::lang::Object* originator, ::org::mpisws::p2p::transport::util::Serializer* idSerializer)
{
    super::ctor();
    this->includeNextCheckpoint = ((flags & FLAG_INCLUDE_CHECKPOINT) == FLAG_INCLUDE_CHECKPOINT);
    this->flags = flags;
    this->idSerializer = idSerializer;
    if((flags & FLAG_FULL_MESSAGES_SENDER) == FLAG_FULL_MESSAGES_SENDER) {
        /* assert((originator != nullptr)) */ ;
        this->originator = originator;
    } else {
        this->originator = nullptr;
    }
}

bool org::mpisws::p2p::transport::peerreview::challenge::ChallengeHashPolicy::hashEntry(int16_t type, ::int8_tArray* content)
{
    switch (type) {
    case EVT_CHECKPOINT:
        if(includeNextCheckpoint) {
            includeNextCheckpoint = false;
            return false;
        }
        return true;
    case EVT_SEND:
        if((flags & FLAG_FULL_MESSAGES_ALL) == FLAG_FULL_MESSAGES_ALL)
            return false;

        if(java_cast< ::java::lang::Object* >(originator) != nullptr) {
            try {
                auto otherOriginator = java_cast< ::java::lang::Object* >(npc(idSerializer)->deserialize(new ::rice::p2p::util::rawserialization::SimpleInputBuffer(content)));
                if(npc(otherOriginator)->equals(java_cast< ::java::lang::Object* >(originator))) {
                    includeNextSendSign = true;
                }
            } catch (::java::io::IOException* ioe) {
                npc(ioe)->printStackTrace();
            }
            return false;
        }
        return true;
    case EVT_SENDSIGN:
        if((flags & FLAG_FULL_MESSAGES_ALL) == FLAG_FULL_MESSAGES_ALL)
            return false;

        if(includeNextSendSign) {
            includeNextSendSign = false;
            return false;
        }
        return true;
    default:
        break;
    }

    return false;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::peerreview::challenge::ChallengeHashPolicy::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.peerreview.challenge.ChallengeHashPolicy", 65);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::peerreview::challenge::ChallengeHashPolicy::getClass0()
{
    return class_();
}

