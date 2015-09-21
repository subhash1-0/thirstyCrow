// Generated from /pastry-2.1/src/rice/tutorial/scribe/MyScribeContent.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/tutorial/scribe/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/p2p/scribe/ScribeContent.hpp>

struct default_init_tag;

class rice::tutorial::scribe::MyScribeContent
    : public virtual ::java::lang::Object
    , public virtual ::rice::p2p::scribe::ScribeContent
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    ::rice::p2p::commonapi::NodeHandle* from {  };
    int32_t seq {  };
protected:
    void ctor(::rice::p2p::commonapi::NodeHandle* from, int32_t seq);

public:
    ::java::lang::String* toString() override;

    // Generated
    MyScribeContent(::rice::p2p::commonapi::NodeHandle* from, int32_t seq);
protected:
    MyScribeContent(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
