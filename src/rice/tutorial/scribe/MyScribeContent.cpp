// Generated from /pastry-2.1/src/rice/tutorial/scribe/MyScribeContent.java
#include <rice/tutorial/scribe/MyScribeContent.hpp>

#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/p2p/commonapi/NodeHandle.hpp>

rice::tutorial::scribe::MyScribeContent::MyScribeContent(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::tutorial::scribe::MyScribeContent::MyScribeContent(::rice::p2p::commonapi::NodeHandle* from, int32_t seq) 
    : MyScribeContent(*static_cast< ::default_init_tag* >(0))
{
    ctor(from,seq);
}

void rice::tutorial::scribe::MyScribeContent::ctor(::rice::p2p::commonapi::NodeHandle* from, int32_t seq)
{
    super::ctor();
    this->from = from;
    this->seq = seq;
}

java::lang::String* rice::tutorial::scribe::MyScribeContent::toString()
{
    return ::java::lang::StringBuilder().append(u"MyScribeContent #"_j)->append(seq)
        ->append(u" from "_j)
        ->append(static_cast< ::java::lang::Object* >(from))->toString();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::tutorial::scribe::MyScribeContent::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.tutorial.scribe.MyScribeContent", 36);
    return c;
}

java::lang::Class* rice::tutorial::scribe::MyScribeContent::getClass0()
{
    return class_();
}

