// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct java::io::ObjectStreamConstants
    : public virtual ::java::lang::Object
{
    static constexpr int32_t PROTOCOL_VERSION_1 { int32_t(1) };
    static constexpr int32_t PROTOCOL_VERSION_2 { int32_t(2) };
    static constexpr int8_t SC_BLOCK_DATA { int8_t(8) };
    static constexpr int8_t SC_ENUM { int8_t(16) };
    static constexpr int8_t SC_EXTERNALIZABLE { int8_t(4) };
    static constexpr int8_t SC_SERIALIZABLE { int8_t(2) };
    static constexpr int8_t SC_WRITE_METHOD { int8_t(1) };
    static constexpr int16_t STREAM_MAGIC { int16_t(-21267) };
    static constexpr int16_t STREAM_VERSION { int16_t(5) };

private:
    static SerializablePermission* SUBCLASS_IMPLEMENTATION_PERMISSION_;
    static SerializablePermission* SUBSTITUTION_PERMISSION_;

public:
    static constexpr int8_t TC_ARRAY { int8_t(117) };
    static constexpr int8_t TC_BASE { int8_t(112) };
    static constexpr int8_t TC_BLOCKDATA { int8_t(119) };
    static constexpr int8_t TC_BLOCKDATALONG { int8_t(122) };
    static constexpr int8_t TC_CLASS { int8_t(118) };
    static constexpr int8_t TC_CLASSDESC { int8_t(114) };
    static constexpr int8_t TC_ENDBLOCKDATA { int8_t(120) };
    static constexpr int8_t TC_ENUM { int8_t(126) };
    static constexpr int8_t TC_EXCEPTION { int8_t(123) };
    static constexpr int8_t TC_LONGSTRING { int8_t(124) };
    static constexpr int8_t TC_MAX { int8_t(126) };
    static constexpr int8_t TC_NULL { int8_t(112) };
    static constexpr int8_t TC_OBJECT { int8_t(115) };
    static constexpr int8_t TC_PROXYCLASSDESC { int8_t(125) };
    static constexpr int8_t TC_REFERENCE { int8_t(113) };
    static constexpr int8_t TC_RESET { int8_t(121) };
    static constexpr int8_t TC_STRING { int8_t(116) };
    static constexpr int32_t baseWireHandle { int32_t(8257536) };


    // Generated
    static ::java::lang::Class *class_();
    static SerializablePermission*& SUBCLASS_IMPLEMENTATION_PERMISSION();
    static SerializablePermission*& SUBSTITUTION_PERMISSION();
};
