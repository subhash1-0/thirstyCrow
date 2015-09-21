// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/util/zip/fwd-pastry-2.1.hpp>
#include <java/util/zip/DeflaterOutputStream.hpp>

struct default_init_tag;

class java::util::zip::GZIPOutputStream
    : public DeflaterOutputStream
{

public:
    typedef DeflaterOutputStream super;

private:
    static constexpr int32_t GZIP_MAGIC { int32_t(35615) };
    static constexpr int32_t TRAILER_SIZE { int32_t(8) };

public: /* protected */
    CRC32* crc {  };

protected:
    void ctor(::java::io::OutputStream* arg0);
    void ctor(::java::io::OutputStream* arg0, int32_t arg1);
    void ctor(::java::io::OutputStream* arg0, bool arg1);
    void ctor(::java::io::OutputStream* arg0, int32_t arg1, bool arg2);

public:
    void finish() override;
    void write(::int8_tArray* arg0, int32_t arg1, int32_t arg2) override;
    /*void writeHeader(); (private) */
    /*void writeInt(int32_t arg0, ::int8_tArray* arg1, int32_t arg2); (private) */
    /*void writeShort(int32_t arg0, ::int8_tArray* arg1, int32_t arg2); (private) */
    /*void writeTrailer(::int8_tArray* arg0, int32_t arg1); (private) */

    // Generated
    GZIPOutputStream(::java::io::OutputStream* arg0);
    GZIPOutputStream(::java::io::OutputStream* arg0, int32_t arg1);
    GZIPOutputStream(::java::io::OutputStream* arg0, bool arg1);
    GZIPOutputStream(::java::io::OutputStream* arg0, int32_t arg1, bool arg2);
protected:
    GZIPOutputStream(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    void write(int32_t arg0);
    void write(::int8_tArray* arg0);

private:
    virtual ::java::lang::Class* getClass0();
};
