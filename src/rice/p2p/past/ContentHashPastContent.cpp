// Generated from /pastry-2.1/src/rice/p2p/past/ContentHashPastContent.java
#include <rice/p2p/past/ContentHashPastContent.hpp>

#include <java/lang/NullPointerException.hpp>
#include <java/lang/String.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/past/ContentHashPastContentHandle.hpp>
#include <rice/p2p/past/Past.hpp>
#include <rice/p2p/past/PastContent.hpp>
#include <rice/p2p/past/PastException.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::past::ContentHashPastContent::ContentHashPastContent(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::past::ContentHashPastContent::ContentHashPastContent(::rice::p2p::commonapi::Id* myId) 
    : ContentHashPastContent(*static_cast< ::default_init_tag* >(0))
{
    ctor(myId);
}

constexpr int64_t rice::p2p::past::ContentHashPastContent::serialVersionUID;

void rice::p2p::past::ContentHashPastContent::ctor(::rice::p2p::commonapi::Id* myId)
{
    super::ctor();
    this->myId = myId;
}

rice::p2p::past::PastContent* rice::p2p::past::ContentHashPastContent::checkInsert(::rice::p2p::commonapi::Id* id, PastContent* existingContent) /* throws(PastException) */
{
    if(existingContent != nullptr) {
        throw new PastException(u"ContentHashPastContent: can't insert, object already exists"_j);
    }
    if(!npc(id)->equals(getId())) {
        throw new PastException(u"ContentHashPastContent: can't insert, content hash incorrect"_j);
    }
    return this;
}

rice::p2p::past::PastContentHandle* rice::p2p::past::ContentHashPastContent::getHandle(Past* local)
{
    return new ContentHashPastContentHandle(npc(local)->getLocalNodeHandle(), getId());
}

rice::p2p::commonapi::Id* rice::p2p::past::ContentHashPastContent::getId()
{
    return myId;
}

bool rice::p2p::past::ContentHashPastContent::isMutable()
{
    return false;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::past::ContentHashPastContent::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.past.ContentHashPastContent", 36);
    return c;
}

java::lang::Class* rice::p2p::past::ContentHashPastContent::getClass0()
{
    return class_();
}

