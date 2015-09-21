// Generated from /pastry-2.1/src/rice/p2p/splitstream/SplitStreamSubscribeContent.java
#include <rice/p2p/splitstream/SplitStreamSubscribeContent.hpp>

#include <java/io/IOException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/p2p/commonapi/rawserialization/InputBuffer.hpp>
#include <rice/p2p/commonapi/rawserialization/OutputBuffer.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::splitstream::SplitStreamSubscribeContent::SplitStreamSubscribeContent(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::splitstream::SplitStreamSubscribeContent::SplitStreamSubscribeContent(int32_t stage) 
    : SplitStreamSubscribeContent(*static_cast< ::default_init_tag* >(0))
{
    ctor(stage);
}

rice::p2p::splitstream::SplitStreamSubscribeContent::SplitStreamSubscribeContent(::rice::p2p::commonapi::rawserialization::InputBuffer* buf)  /* throws(IOException) */
    : SplitStreamSubscribeContent(*static_cast< ::default_init_tag* >(0))
{
    ctor(buf);
}

constexpr int16_t rice::p2p::splitstream::SplitStreamSubscribeContent::TYPE;

int32_t& rice::p2p::splitstream::SplitStreamSubscribeContent::STAGE_NON_FINAL()
{
    clinit();
    return STAGE_NON_FINAL_;
}
int32_t rice::p2p::splitstream::SplitStreamSubscribeContent::STAGE_NON_FINAL_;

int32_t& rice::p2p::splitstream::SplitStreamSubscribeContent::STAGE_FINAL()
{
    clinit();
    return STAGE_FINAL_;
}
int32_t rice::p2p::splitstream::SplitStreamSubscribeContent::STAGE_FINAL_;

void rice::p2p::splitstream::SplitStreamSubscribeContent::ctor(int32_t stage)
{
    super::ctor();
    this->stage = stage;
}

int32_t rice::p2p::splitstream::SplitStreamSubscribeContent::getStage()
{
    return stage;
}

int16_t rice::p2p::splitstream::SplitStreamSubscribeContent::getType()
{
    return TYPE;
}

void rice::p2p::splitstream::SplitStreamSubscribeContent::serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */
{
    npc(buf)->writeByte(static_cast< int8_t >(int32_t(0)));
    npc(buf)->writeInt(stage);
}

void rice::p2p::splitstream::SplitStreamSubscribeContent::ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf) /* throws(IOException) */
{
    super::ctor();
    auto version = npc(buf)->readByte();
    switch (version) {
    case int32_t(0):
        stage = npc(buf)->readInt();
        break;
    default:
        throw new ::java::io::IOException(::java::lang::StringBuilder().append(u"Unknown Version: "_j)->append(version)->toString());
    }

}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::splitstream::SplitStreamSubscribeContent::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.splitstream.SplitStreamSubscribeContent", 48);
    return c;
}

void rice::p2p::splitstream::SplitStreamSubscribeContent::clinit()
{
    super::clinit();
    static bool in_cl_init = false;
struct clinit_ {
    clinit_() {
        in_cl_init = true;
        STAGE_NON_FINAL_ = -int32_t(10);
        STAGE_FINAL_ = -int32_t(9);
    }
};

    if(!in_cl_init) {
        static clinit_ clinit_instance;
    }
}

java::lang::Class* rice::p2p::splitstream::SplitStreamSubscribeContent::getClass0()
{
    return class_();
}

