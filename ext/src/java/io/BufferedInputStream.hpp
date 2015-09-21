// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <atomic>
#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/util/concurrent/atomic/fwd-pastry-2.1.hpp>
#include <java/io/FilterInputStream.hpp>

struct default_init_tag;

class java::io::BufferedInputStream
    : public FilterInputStream
{

public:
    typedef FilterInputStream super;

private:
    static int32_t DEFAULT_BUFFER_SIZE_;
    static int32_t MAX_BUFFER_SIZE_;

public: /* protected */
    std::atomic< ::int8_tArray* > buf {  };

private:
    static ::java::util::concurrent::atomic::AtomicReferenceFieldUpdater* bufUpdater_;

public: /* protected */
    int32_t count {  };
    int32_t marklimit {  };
    int32_t markpos {  };
    int32_t pos {  };

protected:
    void ctor(InputStream* arg0);
    void ctor(InputStream* arg0, int32_t arg1);

public:
    int32_t available() override;
    void close() override;
    /*void fill(); (private) */
    /*::int8_tArray* getBufIfOpen(); (private) */
    /*InputStream* getInIfOpen(); (private) */
    void mark(int32_t arg0) override;
    bool markSupported() override;
    int32_t read() override;
    int32_t read(::int8_tArray* arg0, int32_t arg1, int32_t arg2) override;
    /*int32_t read1(::int8_tArray* arg0, int32_t arg1, int32_t arg2); (private) */
    void reset() override;
    int64_t skip(int64_t arg0) override;

    // Generated
    BufferedInputStream(InputStream* arg0);
    BufferedInputStream(InputStream* arg0, int32_t arg1);
protected:
    BufferedInputStream(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    int32_t read(::int8_tArray* arg0);

private:
    static int32_t& DEFAULT_BUFFER_SIZE();
    static int32_t& MAX_BUFFER_SIZE();
    static ::java::util::concurrent::atomic::AtomicReferenceFieldUpdater*& bufUpdater();
    virtual ::java::lang::Class* getClass0();
};
