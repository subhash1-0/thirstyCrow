// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/table/TableTransprotLayerImpl.java
#include <org/mpisws/p2p/transport/table/TableTransprotLayerImpl_requestValue_1_receiveResult_1_1_receiveResult_1_1_1.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/IllegalStateException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/nio/ByteBuffer.hpp>
#include <org/mpisws/p2p/transport/table/TableStore.hpp>
#include <org/mpisws/p2p/transport/table/TableTransprotLayerImpl_requestValue_1.hpp>
#include <org/mpisws/p2p/transport/table/TableTransprotLayerImpl_requestValue_1_receiveResult_1_1.hpp>
#include <org/mpisws/p2p/transport/table/TableTransprotLayerImpl.hpp>
#include <org/mpisws/p2p/transport/table/UnknownValueException.hpp>
#include <org/mpisws/p2p/transport/util/Serializer.hpp>
#include <rice/Continuation.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/p2p/util/rawserialization/SimpleInputBuffer.hpp>

template<typename T, typename U>
static T java_cast(U* u)
{
    if(!u) return static_cast<T>(nullptr);
    auto t = dynamic_cast<T>(u);
    if(!t) throw new ::java::lang::ClassCastException();
    return t;
}

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::transport::table::TableTransprotLayerImpl_requestValue_1_receiveResult_1_1_receiveResult_1_1_1::TableTransprotLayerImpl_requestValue_1_receiveResult_1_1_receiveResult_1_1_1(TableTransprotLayerImpl_requestValue_1_receiveResult_1_1 *TableTransprotLayerImpl_requestValue_1_receiveResult_1_1_this, ::java::lang::Object* source, ::java::lang::Object* principal, ::rice::Continuation* c)
    : super(*static_cast< ::default_init_tag* >(0))
    , TableTransprotLayerImpl_requestValue_1_receiveResult_1_1_this(TableTransprotLayerImpl_requestValue_1_receiveResult_1_1_this)
    , source(source)
    , principal(principal)
    , c(c)
{
    clinit();
    ctor();
}

void org::mpisws::p2p::transport::table::TableTransprotLayerImpl_requestValue_1_receiveResult_1_1_receiveResult_1_1_1::receiveResult(::java::nio::ByteBuffer* result)
{
    try {
        auto sib = new ::rice::p2p::util::rawserialization::SimpleInputBuffer(result);
        auto response = npc(sib)->readByte();
        {
            ::java::lang::Object* value;
            switch (response) {
            case TableTransprotLayerImpl::RESPONSE_SUCCESS:
                value = java_cast< ::java::lang::Object* >(npc(TableTransprotLayerImpl_requestValue_1_receiveResult_1_1_this->TableTransprotLayerImpl_requestValue_1_this->TableTransprotLayerImpl_this->valueSerializer)->deserialize(sib));
                if(npc(TableTransprotLayerImpl_requestValue_1_receiveResult_1_1_this->TableTransprotLayerImpl_requestValue_1_this->TableTransprotLayerImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINER)
                    npc(TableTransprotLayerImpl_requestValue_1_receiveResult_1_1_this->TableTransprotLayerImpl_requestValue_1_this->TableTransprotLayerImpl_this->logger)->log(::java::lang::StringBuilder().append(u"requestValue("_j)->append(static_cast< ::java::lang::Object* >(source))
                        ->append(u","_j)
                        ->append(static_cast< ::java::lang::Object* >(principal))
                        ->append(u") got value "_j)
                        ->append(static_cast< ::java::lang::Object* >(value))->toString());

                npc(TableTransprotLayerImpl_requestValue_1_receiveResult_1_1_this->TableTransprotLayerImpl_requestValue_1_this->TableTransprotLayerImpl_this->knownValues)->put(principal, value);
                npc(c)->receiveResult(value);
                break;
            case TableTransprotLayerImpl::RESPONSE_FAILED:
                npc(c)->receiveException(new UnknownValueException(source, principal));
                break;
            default:
                npc(c)->receiveException(new ::java::lang::IllegalStateException(::java::lang::StringBuilder().append(u"Unknown response:"_j)->append(response)->toString()));
                break;
            }
        }

    } catch (::java::lang::Exception* ioe) {
        npc(c)->receiveException(ioe);
    }
}

void org::mpisws::p2p::transport::table::TableTransprotLayerImpl_requestValue_1_receiveResult_1_1_receiveResult_1_1_1::receiveResult(::java::lang::Object* result)
{ 
    receiveResult(dynamic_cast< ::java::nio::ByteBuffer* >(result));
}

void org::mpisws::p2p::transport::table::TableTransprotLayerImpl_requestValue_1_receiveResult_1_1_receiveResult_1_1_1::receiveException(::java::lang::Exception* exception)
{
    npc(c)->receiveException(exception);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::table::TableTransprotLayerImpl_requestValue_1_receiveResult_1_1_receiveResult_1_1_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::table::TableTransprotLayerImpl_requestValue_1_receiveResult_1_1_receiveResult_1_1_1::getClass0()
{
    return class_();
}

