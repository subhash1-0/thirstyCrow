// Generated from /pastry-2.1/src/rice/p2p/splitstream/SplitStreamSubscribeContent.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/p2p/splitstream/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/p2p/scribe/rawserialization/RawScribeContent.hpp>

struct default_init_tag;

class rice::p2p::splitstream::SplitStreamSubscribeContent
    : public virtual ::java::lang::Object
    , public virtual ::rice::p2p::scribe::rawserialization::RawScribeContent
{

public:
    typedef ::java::lang::Object super;
    static constexpr int16_t TYPE { int16_t(2) };

private:
    static int32_t STAGE_NON_FINAL_;
    static int32_t STAGE_FINAL_;

public: /* protected */
    int32_t stage {  };
protected:
    void ctor(int32_t stage);

public:
    virtual int32_t getStage();
    int16_t getType() override;
    void serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */ override;
protected:
    void ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf) /* throws(IOException) */;

    // Generated

public:
    SplitStreamSubscribeContent(int32_t stage);
    SplitStreamSubscribeContent(::rice::p2p::commonapi::rawserialization::InputBuffer* buf);
protected:
    SplitStreamSubscribeContent(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    static void clinit();
    static int32_t& STAGE_NON_FINAL();
    static int32_t& STAGE_FINAL();

private:
    virtual ::java::lang::Class* getClass0();
};
