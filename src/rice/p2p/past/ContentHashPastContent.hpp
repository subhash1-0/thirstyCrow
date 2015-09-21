// Generated from /pastry-2.1/src/rice/p2p/past/ContentHashPastContent.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/past/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/p2p/past/PastContent.hpp>

struct default_init_tag;

class rice::p2p::past::ContentHashPastContent
    : public virtual ::java::lang::Object
    , public virtual PastContent
{

public:
    typedef ::java::lang::Object super;

private:
    static constexpr int64_t serialVersionUID { int64_t(6375789163758367025LL) };

public: /* protected */
    ::rice::p2p::commonapi::Id* myId {  };
protected:
    void ctor(::rice::p2p::commonapi::Id* myId);

public:
    PastContent* checkInsert(::rice::p2p::commonapi::Id* id, PastContent* existingContent) /* throws(PastException) */ override;
    PastContentHandle* getHandle(Past* local) override;
    ::rice::p2p::commonapi::Id* getId() override;
    bool isMutable() override;

    // Generated
    ContentHashPastContent(::rice::p2p::commonapi::Id* myId);
protected:
    ContentHashPastContent(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
