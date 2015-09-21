// Generated from /pastry-2.1/src/rice/environment/logging/AbstractLogManager.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <rice/environment/logging/fwd-pastry-2.1.hpp>
#include <java/io/OutputStream.hpp>

struct default_init_tag;

class rice::environment::logging::AbstractLogManager_NullOutputStream
    : public ::java::io::OutputStream
{

public:
    typedef ::java::io::OutputStream super;
    void write(int32_t arg0) /* throws(IOException) */ override;
    void write(::int8_tArray* buf) /* throws(IOException) */ override;
    void write(::int8_tArray* buf, int32_t a, int32_t b) /* throws(IOException) */ override;
    void close() override;

    // Generated
    AbstractLogManager_NullOutputStream();
protected:
    AbstractLogManager_NullOutputStream(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
    friend class AbstractLogManager;
    friend class AbstractLogManager_AbstractLogManager_1;
};
