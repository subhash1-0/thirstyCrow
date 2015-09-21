// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/nio/fwd-pastry-2.1.hpp>
#include <java/util/stream/fwd-pastry-2.1.hpp>
#include <java/io/Reader.hpp>

struct default_init_tag;

class java::io::BufferedReader
    : public Reader
{

public:
    typedef Reader super;

private:
    static constexpr int32_t INVALIDATED { int32_t(-2) };
    static constexpr int32_t UNMARKED { int32_t(-1) };
    ::char16_tArray* cb {  };
    static int32_t defaultCharBufferSize_;
    static int32_t defaultExpectedLineLength_;
    Reader* in {  };
    int32_t markedChar {  };
    bool markedSkipLF {  };
    int32_t nChars {  };
    int32_t nextChar {  };
    int32_t readAheadLimit {  };
    bool skipLF {  };

protected:
    void ctor(Reader* arg0);
    void ctor(Reader* arg0, int32_t arg1);

public:
    void close() override;
    /*void ensureOpen(); (private) */
    /*void fill(); (private) */
    virtual ::java::util::stream::Stream* lines();
    void mark(int32_t arg0) override;
    bool markSupported() override;
    int32_t read() override;
    int32_t read(::char16_tArray* arg0, int32_t arg1, int32_t arg2) override;
    /*int32_t read1(::char16_tArray* arg0, int32_t arg1, int32_t arg2); (private) */
    virtual ::java::lang::String* readLine();

public: /* package */
    virtual ::java::lang::String* readLine(bool arg0);

public:
    bool ready() override;
    void reset() override;
    int64_t skip(int64_t arg0) override;

    // Generated
    BufferedReader(Reader* arg0);
    BufferedReader(Reader* arg0, int32_t arg1);
protected:
    BufferedReader(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    int32_t read(::java::nio::CharBuffer* arg0);
    virtual int32_t read(::char16_tArray* arg0);

private:
    static int32_t& defaultCharBufferSize();
    static int32_t& defaultExpectedLineLength();
    virtual ::java::lang::Class* getClass0();
};
