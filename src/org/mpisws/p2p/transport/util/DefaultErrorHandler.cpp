// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/util/DefaultErrorHandler.java
#include <org/mpisws/p2p/transport/util/DefaultErrorHandler.hpp>

#include <java/lang/IllegalArgumentException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <Array.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::transport::util::DefaultErrorHandler::DefaultErrorHandler(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::transport::util::DefaultErrorHandler::DefaultErrorHandler(::rice::environment::logging::Logger* logger) 
    : DefaultErrorHandler(*static_cast< ::default_init_tag* >(0))
{
    ctor(logger);
}

org::mpisws::p2p::transport::util::DefaultErrorHandler::DefaultErrorHandler(::rice::environment::logging::Logger* logger, int32_t printlevel) 
    : DefaultErrorHandler(*static_cast< ::default_init_tag* >(0))
{
    ctor(logger,printlevel);
}

void org::mpisws::p2p::transport::util::DefaultErrorHandler::init()
{
    NUM_BYTES_TO_PRINT = int32_t(8);
}

void org::mpisws::p2p::transport::util::DefaultErrorHandler::ctor(::rice::environment::logging::Logger* logger)
{
    ctor(logger, ::rice::environment::logging::Logger::INFO);
}

void org::mpisws::p2p::transport::util::DefaultErrorHandler::ctor(::rice::environment::logging::Logger* logger, int32_t printlevel)
{
    super::ctor();
    init();
    if(logger == nullptr)
        throw new ::java::lang::IllegalArgumentException(u"logger is null"_j);

    this->logger = logger;
    this->printlevel = printlevel;
}

void org::mpisws::p2p::transport::util::DefaultErrorHandler::receivedUnexpectedData(::java::lang::Object* id, ::int8_tArray* bytes, int32_t pos, ::java::util::Map* options)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO) {
        auto s = u""_j;
        auto numBytes = NUM_BYTES_TO_PRINT;
        if(npc(bytes)->length < numBytes)
            numBytes = npc(bytes)->length;

        for (auto i = int32_t(0); i < numBytes; i++) {
            s = ::java::lang::StringBuilder(s).append(::java::lang::StringBuilder().append((*bytes)[i])->append(u","_j)->toString())->toString();
        }
        npc(logger)->log(::java::lang::StringBuilder().append(u"Unexpected data from "_j)->append(static_cast< ::java::lang::Object* >(id))
            ->append(u" "_j)
            ->append(s)->toString());
    }
}

void org::mpisws::p2p::transport::util::DefaultErrorHandler::receivedException(::java::lang::Object* i, ::java::lang::Throwable* error)
{
    if(npc(logger)->level <= printlevel) {
        npc(logger)->logException(i == nullptr ? static_cast< ::java::lang::String* >(nullptr) : npc(i)->toString(), error);
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::util::DefaultErrorHandler::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.util.DefaultErrorHandler", 49);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::util::DefaultErrorHandler::getClass0()
{
    return class_();
}

