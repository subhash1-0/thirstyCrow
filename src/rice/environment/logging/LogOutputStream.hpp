// Generated from /pastry-2.1/src/rice/environment/logging/LogOutputStream.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/fwd-pastry-2.1.hpp>
#include <java/io/OutputStream.hpp>

struct default_init_tag;

class rice::environment::logging::LogOutputStream
    : public ::java::io::OutputStream
{

public:
    typedef ::java::io::OutputStream super;

public: /* protected */
    Logger* logger {  };
    ::int8_tArray* buffer {  };
    int32_t offset {  };
    int32_t level {  };

public:
    static constexpr int32_t BUFFER_SIZE { int32_t(1024) };
protected:
    void ctor(::rice::environment::Environment* env, int32_t level);
    void ctor(::rice::environment::Environment* env, int32_t level, ::java::lang::String* instance);

public:
    void write(int32_t b) /* throws(IOException) */ override;
    void flush() override;
    void close() override;

    // Generated
    LogOutputStream(::rice::environment::Environment* env, int32_t level);
    LogOutputStream(::rice::environment::Environment* env, int32_t level, ::java::lang::String* instance);
protected:
    LogOutputStream(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    virtual void write(::int8_tArray* arg0);
    virtual void write(::int8_tArray* arg0, int32_t arg1, int32_t arg2);

private:
    virtual ::java::lang::Class* getClass0();
};
