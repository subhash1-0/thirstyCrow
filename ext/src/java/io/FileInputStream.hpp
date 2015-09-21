// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <atomic>
#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/nio/channels/fwd-pastry-2.1.hpp>
#include <java/io/InputStream.hpp>

struct default_init_tag;

class java::io::FileInputStream
    : public InputStream
{

public:
    typedef InputStream super;

private:
    ::java::nio::channels::FileChannel* channel {  };
    ::java::lang::Object* closeLock {  };
    std::atomic< bool > closed {  };
    FileDescriptor* fd {  };
    ::java::lang::String* path {  };

protected:
    void ctor(::java::lang::String* arg0);
    void ctor(File* arg0);
    void ctor(FileDescriptor* arg0);

public:
    int32_t available() override;
    void close() override;
    /*void close0(); (private) */

public: /* protected */
    void finalize() override;

public:
    virtual ::java::nio::channels::FileChannel* getChannel();
    FileDescriptor* getFD();
    /*static void initIDs(); (private) */
    /*void open(::java::lang::String* arg0); (private) */
    /*void open0(::java::lang::String* arg0); (private) */
    int32_t read() override;
    int32_t read(::int8_tArray* arg0) override;
    int32_t read(::int8_tArray* arg0, int32_t arg1, int32_t arg2) override;
    /*int32_t read0(); (private) */
    /*int32_t readBytes(::int8_tArray* arg0, int32_t arg1, int32_t arg2); (private) */
    int64_t skip(int64_t arg0) override;

    // Generated
    FileInputStream(::java::lang::String* arg0);
    FileInputStream(File* arg0);
    FileInputStream(FileDescriptor* arg0);
protected:
    FileInputStream(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
