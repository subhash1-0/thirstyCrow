// Generated from /pastry-2.1/src/rice/tutorial/past/MyPastContent.java
#include <rice/tutorial/past/MyPastContent.hpp>

#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>

rice::tutorial::past::MyPastContent::MyPastContent(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::tutorial::past::MyPastContent::MyPastContent(::rice::p2p::commonapi::Id* id, ::java::lang::String* content) 
    : MyPastContent(*static_cast< ::default_init_tag* >(0))
{
    ctor(id,content);
}

void rice::tutorial::past::MyPastContent::ctor(::rice::p2p::commonapi::Id* id, ::java::lang::String* content)
{
    super::ctor(id);
    this->content = content;
}

java::lang::String* rice::tutorial::past::MyPastContent::toString()
{
    return ::java::lang::StringBuilder().append(u"MyPastContent ["_j)->append(content)
        ->append(u"]"_j)->toString();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::tutorial::past::MyPastContent::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.tutorial.past.MyPastContent", 32);
    return c;
}

java::lang::Class* rice::tutorial::past::MyPastContent::getClass0()
{
    return class_();
}

