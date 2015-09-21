// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/util/zip/fwd-pastry-2.1.hpp>
#include <java/util/zip/InflaterInputStream.hpp>

struct default_init_tag;

class java::util::zip::GZIPInputStream
    : public InflaterInputStream
{

public:
    typedef InflaterInputStream super;

private:
    static constexpr int32_t FCOMMENT { int32_t(16) };
    static constexpr int32_t FEXTRA { int32_t(4) };
    static constexpr int32_t FHCRC { int32_t(2) };
    static constexpr int32_t FNAME { int32_t(8) };
    static constexpr int32_t FTEXT { int32_t(1) };

public:
    static constexpr int32_t GZIP_MAGIC { int32_t(35615) };

private:
    bool closed {  };

public: /* protected */
    CRC32* crc {  };
    bool eos {  };

private:
    ::int8_tArray* tmpbuf {  };

protected:
    void ctor(::java::io::InputStream* arg0);
    void ctor(::java::io::InputStream* arg0, int32_t arg1);

public:
    void close() override;
    /*void ensureOpen(); (private) */
    int32_t read(::int8_tArray* arg0, int32_t arg1, int32_t arg2) override;
    /*int32_t readHeader(::java::io::InputStream* arg0); (private) */
    /*bool readTrailer(); (private) */
    /*int32_t readUByte(::java::io::InputStream* arg0); (private) */
    /*int64_t readUInt(::java::io::InputStream* arg0); (private) */
    /*int32_t readUShort(::java::io::InputStream* arg0); (private) */
    /*void skipBytes(::java::io::InputStream* arg0, int32_t arg1); (private) */

    // Generated
    GZIPInputStream(::java::io::InputStream* arg0);
    GZIPInputStream(::java::io::InputStream* arg0, int32_t arg1);
protected:
    GZIPInputStream(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    int32_t read();
    int32_t read(::int8_tArray* arg0);

private:
    virtual ::java::lang::Class* getClass0();
};
