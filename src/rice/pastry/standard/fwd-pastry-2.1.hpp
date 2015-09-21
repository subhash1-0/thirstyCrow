// Forward declarations for rice.pastry.standard
#pragma once


namespace rice
{
    namespace pastry
    {
        namespace standard
        {
            class CertifiedNodeIdFactory;
            class ConsistentJoinMsg;
            class ConsistentJoinProtocol;
            class ConsistentJoinProtocol_CJPDeserializer;
            class ConsistentJoinProtocol_ConsistentJoinProtocol_1;
            class ConsistentJoinProtocol_FailedTime;
            class ConsistentJoinProtocol_RequestFromEveryoneMsg;
            class IPNodeIdFactory;
            class InitiatePingNeighbor;
            class PartitionHandler;
            class PartitionHandler_GoneSetEntry;
            class PartitionHandler_run_1;
            class PeriodicLeafSetProtocol;
            class PeriodicLeafSetProtocol_PLSPMessageDeserializer;
            class PeriodicLeafSetProtocol_removeFromLeafsetIfPossible_1;
            struct ProximityNeighborSelector;
            class RandomNodeIdFactory;
            class RapidRerouter;
            class RapidRerouter_RouterNotification;
            class RapidRerouter_rerouteMe_1;
            class StandardAddress;
            class StandardJoinProtocol;
            class StandardJoinProtocol_SJPDeserializer;
            class StandardJoinProtocol_handleInitiateJoin_1;
            class StandardJoinProtocol_handleIntermediateHop_2;
            class StandardJoinProtocol_respondToJoiner_3;
            class StandardLeafSetProtocol;
            class StandardRouteSetProtocol;
            class StandardRouteSetProtocol_SRSPDeserializer;
            class StandardRouter;
            class StandardRouter_AliveRouterStrategy;
            class StandardRouter_StandardRouter_1;
            class StandardRouter_getBestRoutingCandidates_4;
            class StandardRouter_route_2;
            class StandardRouter_sendTheMessage_3;
            class TooManyRouteAttempts;
        } // standard
    } // pastry
} // rice
