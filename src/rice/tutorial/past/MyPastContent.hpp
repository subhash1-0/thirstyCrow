// Generated from /pastry-2.1/src/rice/tutorial/past/MyPastContent.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/tutorial/past/fwd-pastry-2.1.hpp>
#include <rice/p2p/past/ContentHashPastContent.hpp>

struct default_init_tag;

class rice::tutorial::past::MyPastContent
    : public ::rice::p2p::past::ContentHashPastContent
{

public:
    typedef ::rice::p2p::past::ContentHashPastContent super;

public: /* package */
    ::java::lang::String* content {  };
protected:
    void ctor(::rice::p2p::commonapi::Id* id, ::java::lang::String* content);

public:
    ::java::lang::String* toString() override;

    // Generated
    MyPastContent(::rice::p2p::commonapi::Id* id, ::java::lang::String* content);
protected:
    MyPastContent(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
