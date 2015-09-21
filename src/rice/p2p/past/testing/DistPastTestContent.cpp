// Generated from /pastry-2.1/src/rice/p2p/past/testing/DistPastTestContent.java
#include <rice/p2p/past/testing/DistPastTestContent.hpp>

#include <java/lang/NullPointerException.hpp>
#include <java/lang/String.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/time/TimeSource.hpp>
#include <rice/p2p/commonapi/IdFactory.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::past::testing::DistPastTestContent::DistPastTestContent(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::past::testing::DistPastTestContent::DistPastTestContent(::rice::environment::Environment* env, ::rice::p2p::commonapi::IdFactory* idf, ::java::lang::String* content) 
    : DistPastTestContent(*static_cast< ::default_init_tag* >(0))
{
    ctor(env,idf,content);
}

void rice::p2p::past::testing::DistPastTestContent::ctor(::rice::environment::Environment* env, ::rice::p2p::commonapi::IdFactory* idf, ::java::lang::String* content)
{
    super::ctor(npc(idf)->buildId(content));
    this->content = content;
    this->timestamp = npc(npc(env)->getTimeSource())->currentTimeMillis();
}

java::lang::String* rice::p2p::past::testing::DistPastTestContent::getContent()
{
    return content;
}

int64_t rice::p2p::past::testing::DistPastTestContent::getTimestamp()
{
    return timestamp;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::past::testing::DistPastTestContent::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.past.testing.DistPastTestContent", 41);
    return c;
}

java::lang::Class* rice::p2p::past::testing::DistPastTestContent::getClass0()
{
    return class_();
}

