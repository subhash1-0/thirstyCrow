// Generated from /pastry-2.1/src/rice/persistence/testing/Test.java
#include <rice/persistence/testing/Test.hpp>

#include <java/io/PrintStream.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/System.hpp>
#include <java/util/Arrays.hpp>
#include <rice/environment/Environment.hpp>
#include <Array.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::persistence::testing::Test::Test(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::persistence::testing::Test::Test(::rice::environment::Environment* env) 
    : Test(*static_cast< ::default_init_tag* >(0))
{
    ctor(env);
}

java::lang::String*& rice::persistence::testing::Test::SUCCESS()
{
    clinit();
    return SUCCESS_;
}
java::lang::String* rice::persistence::testing::Test::SUCCESS_;

java::lang::String*& rice::persistence::testing::Test::FAILURE()
{
    clinit();
    return FAILURE_;
}
java::lang::String* rice::persistence::testing::Test::FAILURE_;

constexpr int32_t rice::persistence::testing::Test::PAD_SIZE;

void rice::persistence::testing::Test::ctor(::rice::environment::Environment* env)
{
    super::ctor();
    environment = env;
}

void rice::persistence::testing::Test::sectionStart(::java::lang::String* name)
{
    npc(::java::lang::System::out())->println(name);
}

void rice::persistence::testing::Test::sectionEnd()
{
    npc(::java::lang::System::out())->println();
}

void rice::persistence::testing::Test::stepStart(::java::lang::String* name)
{
    npc(::java::lang::System::out())->print(pad(::java::lang::StringBuilder().append(u"  "_j)->append(name)->toString()));
}

void rice::persistence::testing::Test::stepDone(::java::lang::String* status)
{
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"["_j)->append(status)
        ->append(u"]"_j)->toString());
    if(npc(status)->equals(static_cast< ::java::lang::Object* >(FAILURE_)))
        ::java::lang::System::exit(0);

}

void rice::persistence::testing::Test::stepDone(::java::lang::String* status, ::java::lang::String* message)
{
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"["_j)->append(status)
        ->append(u"]"_j)->toString());
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"    "_j)->append(message)->toString());
    if(npc(status)->equals(static_cast< ::java::lang::Object* >(FAILURE_)))
        ::java::lang::System::exit(0);

}

void rice::persistence::testing::Test::stepException(::java::lang::Exception* e)
{
    npc(::java::lang::System::out())->println();
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"Exception "_j)->append(static_cast< ::java::lang::Object* >(e))
        ->append(u" occurred during testing."_j)->toString());
    npc(e)->printStackTrace();
    ::java::lang::System::exit(0);
}

java::lang::String* rice::persistence::testing::Test::pad(::java::lang::String* start)
{
    if(npc(start)->length() >= PAD_SIZE) {
        return npc(start)->substring(0, PAD_SIZE);
    } else {
        auto spaceLength = PAD_SIZE - npc(start)->length();
        auto spaces = new ::char16_tArray(spaceLength);
        ::java::util::Arrays::fill(spaces, u'.');
        return npc(start)->concat(new ::java::lang::String(spaces));
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::persistence::testing::Test::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.persistence.testing.Test", 29);
    return c;
}

void rice::persistence::testing::Test::clinit()
{
struct string_init_ {
    string_init_() {
    SUCCESS_ = u"SUCCESS"_j;
    FAILURE_ = u"FAILURE"_j;
    }
};

    static string_init_ string_init_instance;

    super::clinit();
}

java::lang::Class* rice::persistence::testing::Test::getClass0()
{
    return class_();
}

