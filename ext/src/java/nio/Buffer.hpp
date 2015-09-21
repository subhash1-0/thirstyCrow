// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/nio/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct default_init_tag;

class java::nio::Buffer
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    static constexpr int32_t SPLITERATOR_CHARACTERISTICS { int32_t(16464) };
    int64_t address {  };

private:
    int32_t capacity_ {  };
    int32_t limit_ {  };
    int32_t mark_ {  };
    int32_t position_ {  };

protected:
    void ctor(int32_t arg0, int32_t arg1, int32_t arg2, int32_t arg3);

public:
    virtual ::java::lang::Object* array() = 0;
    virtual int32_t arrayOffset() = 0;
    int32_t capacity();

public: /* package */
    static void checkBounds(int32_t arg0, int32_t arg1, int32_t arg2);
    int32_t checkIndex(int32_t arg0);
    int32_t checkIndex(int32_t arg0, int32_t arg1);

public:
    Buffer* clear();

public: /* package */
    void discardMark();

public:
    Buffer* flip();
    virtual bool hasArray_() = 0;
    bool hasRemaining();
    virtual bool isDirect() = 0;
    virtual bool isReadOnly() = 0;
    int32_t limit();
    Buffer* limit(int32_t arg0);
    Buffer* mark();

public: /* package */
    int32_t markValue();
    int32_t nextGetIndex();
    int32_t nextGetIndex(int32_t arg0);
    int32_t nextPutIndex();
    int32_t nextPutIndex(int32_t arg0);

public:
    int32_t position();
    Buffer* position(int32_t arg0);
    int32_t remaining();
    Buffer* reset();
    Buffer* rewind();

public: /* package */
    void truncate();

    // Generated
    Buffer(int32_t arg0, int32_t arg1, int32_t arg2, int32_t arg3);
protected:
    Buffer(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
