/**
 * dx_udp_extension_intf.h
 *
 * @file
 * @copyright Copyright (c) 2015 Elektrobit Automotive GmbH. All rights reserved.
 *
 * @date    $Date:: 2017-05-22 #$
 * @version $Revision:: 10046   $
 * @author  $Author:: zhenemi   $
 */

/**
 * The data exchange via udp. Protocoldefinition.
 */

#include <stdint.h>


#ifndef _ADDITIONAL_UDP_EXTENSION_HEADER_
#define _ADDITIONAL_UDP_EXTENSION_HEADER_



/**
 * \page page_add_udp_extension ADTF Message Bus UDP Extension
 *
 * The ADTF Message Bus Service (adtf_data_exchange.srv) implements the @ref
 * adtf::IMessageBus interface
 * to enlarge the @ref adtf::IDataExchange. It provides the possibility
 * to connect two or more instances of ADTF to each other.
 * There are several transport protocols (UDP, TCP, ...) implemented to
 * communicate with ADTF.
 * This documentation page will explain the communication via UDP Protocol.
 *
 * -# \subpage page_default_udp
 * -# \subpage page_ADTF_udp_network
 * -# \subpage page_ADTF_udp_performance
 * -# \subpage page_ADTF_udp_channel_based_time_synchronization
 */

/** \page page_default_udp ADTF UDP Extension
 *
 * \section sec_default_udp Default UDP definitions
 *
 * \subsection subsec_modes Sending and Receiving Package Modes
 * There are 3 possibilities to send data and receive data which will be
 * understood by the Message Bus Service:
 * \n
 * -# UDP Packages for Sending and Receiving unidentified data in NOID Mode
 * -# UDP Packages for Sending and Receiving data in ASYNC Mode
 * -# UDP Packages for Sending and Receiving data in SYNC Mode (waiting for answer)
 *
 *
 * \par Parameters
 *
 * A UDP channel accepts the following connection dependent parameters
 * -# <b>timeout</b>: a timeout for the connection
 * -# <b>max_package_size</b>: maximal size before transmitted user data is
 * split (in order to limit the udp package size).
 * -# <b>forceclient</b>: If the parameter is set to true, this configuration
 * can also run on the local machine. Warning: Just configure the
 * URL of the configuration and not of the subgraph.
 *
 * \n These arguments can also be configured globally in the settings menu.
 *
 * \par Example Code for understanding
 *
 * This example describes the way an ADTF Message Bus sends data to a far system.
 *
 *
 * \image HTML messagebus_common_connection.png common connection example
 *
 * \code
 *      // Create a channel within the ADTF Data Exchange Service (or Message Bus Service)
 *      // ADTF Data Exchange Service opens up a UDP-Socket to send data to the
 *      // "far_system" in the network.
 *      // These UDP Channels will always be opened bi-directionally!
 *      // In this case the channel will send UDP packets to the far_system:5000
 *      // and will wait for answers of UDP packets on localhost:5001!
 *      // A timeout of 30000000 micro seconds and a maximal package size of
 *      // 50000 bytes is configured here
 *      //
 *      tResult nResult = pDataExchange->CreateChannel
 *      ("mychannel", "udp://far_system:5000{timeout=30000000, max_package_size=50000}");
 *      if (IS_OK(nResult))
 *      {
 *          char   strMyMessageData[100];
 *
 *          // send unmanaged NOID data on the channel
 *          strcpy(strMyMessageData, "my unidentified NOID data area");
 *          pDataExchange->Send("mychannel",
 *                              NULL,
 *                              strMyMessageData,
 *                              100);
 *
 *          // send managed ASYNC data on the channel
 *          strcpy(strMyMessageData, "my ASYNC data area");
 *          pDataExchange->Send("mychannel",
 *                              "my-async-message",
 *                              strMyMessageData,
 *                              100);
 *
 *          // send managed SYNC data on the channel
 *          strcpy(strMyMessageData, "my SYNC data area");
 *          char   strAnswerData[50];
 *          tInt nRealSizeofAnswer = 0;
 *          pDataExchange->Send("mychannel",
 *                              "my-sync-message",
 *                              strMyMessageData,
 *                              100,
 *                              (tVoid*)strAnswerData,
 *                              50, //size of answer buffer
 *                              &nRealSizeofAnswer,
 *                              100000, //timeout);
 *      }
 * \endcode
 *
 * \subsection subsec_modes_NOID Receiving and Sending NOID mode data
 * The UDP package received by the \b far_system is structured with the header package
 * defined in structure @ref tADTFDXUDPHeader to receive data in NOID mode.
 *
 * <b>The package has the following characteristics:</b>
 * \li un-identified NOID Mode means there is no Message ID set.
 * \li The packages can have only a maximum size of
 *     @ref ADTF_DX_UDP_MAX_PACKAGESIZE bytes.
 * \li The packages must start with the structured data header
 *     @ref tADTFDXUDPHeader followed by the data bytes.
 *      -# The package header has to have set the
 *         @ref tADTFDXUDPHeader.ui32StartBytes to @ref ADTF_DX_UDP_STARTBYTES.
 *      -# If the package header has set the
 *         @ref tADTFDXUDPHeader::ui32StartBytes == @ref ADTF_DX_UDP_STARTBYTES_ENDIANESS,
 *          you can be sure the sender platform has a different Endianess and
 *          you need to swap relevant data!
 *      -# The package header have to have set the
 *         @ref tADTFDXUDPHeader::ui8HeaderType to @ref ADTF_DX_UDP_HEADER_TYPE_NOID.
 *      -# The package header have to have set the
 *         @ref tADTFDXUDPHeader::ui32DataSize to the amount of bytes following.
 *
 * \n <b>The UDP Package of the Example Code above looks like: </b>
 * \n
 * <table>
 * <tr>
 *  <th colspan="2">
 *      tADTFDXUDPHeader
 *  </td>
 *  <td>
 *  </td>
 *  <td>
 *      data area
 *  </td>
 * </tr>
 * <tr>
 *  <td>
 *      ui32StartBytes<br>
 *      ui8HeaderType<br>
 *      ui32SenderUID<br>
 *      tmTime<br>
 *      ui32DataSize<br>
 *      _reserved
 *  </td>
 *  <td>
 *      ADTF_DX_UDP_STARTBYTES <br>
 *      ADTF_DX_UDP_HEADER_TYPE_NOID <br>
 *      a identifier given by sender <br>
 *      current time of the sender (microseconds) <br>
 *      100 <br>
 *      11 bytes reserved
 *  </td>
 *  <td>
 *  </td>
 *  <td>
 *      "my NOID data area"\\0 ...<additional 82 bytes>
 *  </td>
 * </tr>
 * </table>
 *
 * \subsection subsec_modes_ASYNC Receiving and Sending ASYNC messages
 *
 * The received UDP package is structured with the header
 * defined in the structure @ref tADTFDXUDPHeaderASync.
 * \li In ASYNC Mode no answer is awaiting. ADTF does not care if the message
 *     will be received on the far_system.
 * \li The UDP packages can only have the maximum length of
 *     @ref ADTF_DX_UDP_MAX_PACKAGESIZE bytes.
 *      -# If the message you want to sent is longer than
 *         ADTF_DX_UDP_MAX_PACKAGESIZE you need to use
 *          more packages and count up the ui8PackageCount within the sender.
 * \li The UDP packages must start with the structured data header
 *     @ref tADTFDXUDPHeaderASync followed by the data bytes of one message part.
 *      -# The package header has to have set the
 *         @ref tADTFDXUDPHeaderASync::ui32StartBytes to @ref ADTF_DX_UDP_STARTBYTES.
 *      -# If the package header has set the
 *         @ref tADTFDXUDPHeaderASync::ui32StartBytes == @ref ADTF_DX_UDP_STARTBYTES_ENDIANESS,
 *          you can be sure the sender platform has a different
 *          Endianess and you need to swap all relevant data!
 *      -# The package header has to have set the
 *         @ref tADTFDXUDPHeaderASync::ui8HeaderType to @ref ADTF_DX_UDP_HEADER_TYPE_ASYNC.
 *      -# The package header has to have set the
 *         @ref tADTFDXUDPHeaderASync::ui32DataSize to the amount of bytes following.
 *      -# The ui32MsgSize within the header is always the size of the whole
 *         message also if it is split into more packages.
 *
 *\n <b>The UDP Package of the Example Code above looks like: </b>
 * \n
 * <table>
 * <tr>
 *  <th colspan="2">
 *      tADTFDXUDPHeaderASync
 *  </td>
 *  <td>
 *  </td>
 *  <td>
 *      data area
 *  </td>
 * </tr>
 * <tr>
 *  <td>
 *      ui32StartBytes<br>
 *      ui8HeaderType<br>
 *      ui32SenderUID<br>
 *      tmTime<br>
 *      ui32DataSize<br>
 *      _reserved<br>
 *      strMsgId<br>
 *      ui32MsgSize<br>
 *      ui8PackageId<br>
 *      ui8PackageCount
 *  </td>
 *  <td>
 *      ADTF_DX_UDP_STARTBYTES <br>
 *      ADTF_DX_UDP_HEADER_TYPE_ASYNC <br>
 *      a identifier given by sender <br>
 *      current time of the sender (microseconds) <br>
 *      100 <br>
 *      11 bytes reserved<br>
 *      "my-async-message"\\0 ...<additional 112 bytes><br>
 *      100<br>
 *      0<br>
 *      1
 *  </td>
 *  <td>
 *  </td>
 *  <td>
 *      "my async data area"\\0 ...<additional 82 bytes>
 *  </td>
 * </tr>
 * </table>
 *
 * \subsection subsec_modes_SYNC Receiving and Sending SYNC messages via UDP Port
 *
 * The received UDP Package is structured with the header
 * defined in the structure @ref tADTFDXUDPHeaderSync to communicate with ADTF in SYNC Mode.
 *
 * Very important is that a SYNC Message that is received needs to be responded
 * with an ASYNC Message.
 * Otherwise it can be possible, that the sender will wait on the answer forever
 * if no timeout is implemented.
 * The message for the answer has to have set the @ref tADTFDXUDPHeaderSync::strMsgIdReply
 * as MessageId within the ASYNC Message responding.
 * \li The UDP packages can only be @ref ADTF_DX_UDP_MAX_PACKAGESIZE bytes long.
 * \li The UDP packages must start with the structured data header @ref
 *     tADTFDXUDPHeaderSync followed by the data bytes of one message part.
 *      -# The package header has to have set the @ref
 *         tADTFDXUDPHeaderSync::ui32StartBytes to @ref ADTF_DX_UDP_STARTBYTES.
 *      -# The package header has to have set the
 *         @ref tADTFDXUDPHeaderSync::ui8HeaderType to @ref ADTF_DX_UDP_HEADER_TYPE_SYNC.
 *      -# The package header has to have set the
 *         @ref tADTFDXUDPHeaderSync::ui32DataSize to the amount of bytes following.
 *
 *\n <b>The SYNC UDP Package of the Example Code above looks like: </b>
 * \n
 * <table>
 * <tr>
 *  <th colspan="2">
 *      tADTFDXUDPHeaderSync
 *  </td>
 *  <td>
 *  </td>
 *  <td>
 *      data area
 *  </td>
 * </tr>
 * <tr>
 *  <td>
 *      ui32StartBytes<br>
 *      ui8HeaderType<br>
 *      ui32SenderUID<br>
 *      tmTime<br>
 *      ui32DataSize<br>
 *      _reserved<br>
 *      strMsgId<br>
 *      ui32MsgSize<br>
 *      ui8PackageId<br>
 *      ui8PackageCount<br>
 *      strMsgIdReply
 *  </td>
 *  <td>
 *      ADTF_DX_UDP_STARTBYTES <br>
 *      ADTF_DX_UDP_HEADER_TYPE_SYNC <br>
 *      a identifier given by sender <br>
 *      current time of the sender (microseconds) <br>
 *      100 <br>
 *      11 bytes reserved<br>
 *      "my-sync-message"\\0 ...<additional 114 bytes><br>
 *      100<br>
 *      0<br>
 *      1<br>
 *      "my-sync-message_reply"\\0 ...<additional 108 bytes>
 *  </td>
 *  <td>
 *  </td>
 *  <td>
 *      "my sync data area"\\0 ...<additional 83 bytes>
 *  </td>
 * </tr>
 * </table>
 *
 * \par Example
 *  For a concrete example how to implement a
 *  connection within a non-ADTF system have a look at \ref page_example_dataexchange_raw.
 *
 */

/**
 * \page page_ADTF_udp_network ADTF UDP Network
 *
 * \section sec_simple_prot Simple ADTF UDP Control Protocol
 *
 * The UDP Packages described in @ref page_default_udp are used to communicate
 * within the ADTF UDP Network.
 * The ADTF UDP Network is one possibility to establish connections between
 * ADTF and non-ADTF systems.
 * An ADTF UDP Network is organized through a simple \b channel-based \b
 * Server-Client Configuration.
 *
 * There are 4 roles an ADTF UDP Network participant can have:
 *
 * -# Simple ADTF UDP Sender
 * -# Simple ADTF UDP Receiver
 * -# ADTF UDP Channel Client
 * -# ADTF UDP Channel Server
 *
 * To configure connections between an ADTF system, which contains an ADTF
 * Filtergraph Manager, to a non-ADTF system you have to use the
 * \b Untyped \b Communication. See the description on @ref page_add_filter_dx_communication.
 *
 * \subsection subsec_sender The communication as an ADTF UDP Sender
 *
 * \li ADTF UDP Sender will only \b send data to another participant within the
 *     network
 * \li The connection can only be a direct \b point-2-point
 * \li The used UDP packages can be the @ref tADTFDXUDPHeader, @ref
 *     tADTFDXUDPHeaderASync
 *
 * \par Use case: Sending data as ADTF UDP Sender to an ADTF UDP Channel Server
 *
 * The illustration shows:
 * \li the sender sends messages with no message identifier to the port 5000
 *     of an ADTF UDP Channel Server
 * \li the sender sends messages with the message identifier \e "msg_raw" to
 *     the port 5000 of an ADTF UDP Channel Server
 *
 * \n \image HTML messagebus_udp_network_sender.png Principal of UDP Sender
 *
 * If you use the ADTF Filtergraph Manager on the ADTF System you should only use
 * ASYNC UDP Packages (@ref tADTFDXUDPHeaderASync).
 *
 * \subsection subsec_receiver The communication as an ADTF UDP Receiver
 *
 * \li ADTF UDP Receiver will only \b receive data from another participant
 *     within the network
 * \li The connection can only be a direct \b point-2-point
 * \li The used UDP packages can be the @ref tADTFDXUDPHeader or @ref
 *     tADTFDXUDPHeaderASync
 * \li The network partner can be an ADTF UDP Sender or an ADTF UDP Channel Client
 *
 * \par Use case: Receiving data as ADTF UDP Receiver
 *
 * The illustration shows:
 * \li the receiver gets messages with no message identifier on the port 5000
 * \li the receiver gets messages with the message identifier \e "msg_raw" on
 *     the port 5000
 *
 * \n \image HTML messagebus_udp_network_receiver.png Principal of UDP Receiver
 *
 * If you use the ADTF Filtergraph Manager on the ADTF System you will only get
 * ASYNC UDP Packages (@ref tADTFDXUDPHeaderASync).
 *
 * \subsection subsec_client The communication as an ADTF UDP Client
 * \li ADTF UDP Channel Client will \b receive data and \b send data
 * \li The used UDP packages can be the @ref tADTFDXUDPHeader,
 *     @ref tADTFDXUDPHeaderASync and also @ref tADTFDXUDPHeaderSync
 *
 * \par Use case: Establish a connection as ADTF UDP Channel Client
 *
 * The illustration shows:
 * \li the ADTF UDP Channel Server listens to the port 5000
 * \li the ADTF UDP Channel Server expects the client listening to 5001
 * \li the port number pair can also configured to a different port number
 *     set (i.e. 6666 and 6667)
 * \li the client starts a connection by sending an ASYNC message with no data
 *     area (ui32MsgSize == 0) and the message identifier \e "subscribe"
 * \li the client will get an ASYNC message \e "subscribed" from the server as answer
 * \li the client sends ASYNC \e "subscribe" as long as it did not receive the
 *     ASYNC \e "subscribed"
 * \li the client sends messages with the message identifier \e "msg_raw" to
 *     the port 5000 of the server
 * \li the client can receive ASYNC messages (i.e. in this case the ASYNC \e "msg2_raw")
 *     on port 5001
 *
 * \n \image HTML messagebus_udp_network_client_1.png Principal of UDP Client - ASYNC
 *
 * \par Use case: SYNC connection as ADTF UDP Channel Client
 *
 * The illustration shows:
 * \li the port number pair can also be configured to a different port number
 *     set (i.e. 6666 and 6667)
 * \li the client sends a SYNC message \e "msg_raw" where the requested message
 *     for the answer is \e "msg_raw_reply"
 * \li the server will send an ASYNC \e "msg_raw_reply" as answer to the SYNC message
 * \li the client wants to stop connection and sends ASYNC \e "unsubscribe"
 * \li the server responds \e "unsubscribed"
 *
 * \n \image HTML messagebus_udp_network_client_2.png Principal of UDP Client - SYNC
 *
 * \subsection subsec_server Additional Task as an ADTF UDP Channel Server
 * \li ADTF UDP Channel Server will \b receive data, \b send data and \b
 *     share data to all subscribed ADTF UDP Channel Clients
 * \li The used UDP packages can be the @ref tADTFDXUDPHeader, @ref
 *     tADTFDXUDPHeaderASync and also @ref tADTFDXUDPHeaderSync
 *
 * \par Use case: Share Messages coming from an ADTF UDP Channel Client
 *
 * The illustration shows:
 * \li the ADTF UDP Channel Server listens to the port 5000
 * \li the ADTF UDP Channel Server expects all clients listening to 5001
 * \li the port number pair can also be configured to a different port number
 *     set (i.e. 6666 and 6667)
 * \li one client will send an ASYNC \e "msg_raw" to the server
 * \li the server will provide this data to the \e "msg_raw" pin of the remote subgraph
 * \li the server will share this ASYNC \e "msg_raw" to all other subscribed clients
 *
 * \n \image HTML messagebus_udp_network_server_1.png Principal of
 * ADTF UDP Channel Server - Sharing messages
 *
 * \par Use case: Share Message which will be send on the Channel
 *
 * The illustration shows:
 * \li the ADTF Filtergraph Manager will send a \e "msg_raw" on the channel
 * \li the server will share this ASYNC \e "msg_raw" to all other subscribed clients
 *
 * \n \image HTML messagebus_udp_network_server_2.png Principal of
 *     ADTF UDP Channel Server - Sharing messages
 */

/**
 * \page page_ADTF_udp_channel_based_time_synchronization ADTF UDP channel based time synchronization
 *
 * This time synchronization is a point to point synchronization protocol with
 * master-slave architecture. This protocol defines a timing master (TM) and
 * one timing slave. The timing channel is established according to the
 * related UDP data channel with a port offset of 123. For example, if the UDP
 * data channel port is 5000, the UDP timing channel port results in 5123.<br>
 *
 * \par Configuration
 * The following global properties are valid for this synchronization type:
 * <table>
 * <tr>
 *  <th>Name</th>
 *  <th>Type</th>
 *  <th>Default</th>
 *  <th>Description</th>
 * </tr>
 * <tr>
 *  <td>synchronizing_cycletime</td>
 *  <td>Integer</td>
 *  <td>@ref ADTF_DX_TIMESYNC_CYCLE_TIME (with the value 1000000)</td>
 *  <td>@copydoc ADTF_DX_TIMESYNC_CYCLE_TIME</td>
 * </tr>
 * <tr>
 *  <td>synchronizing_timeout</td>
 *  <td>Integer</td>
 *  <td>@ref ADTF_DX_TIMEOUT (with the value 2500000)</td>
 *  <td>@copydoc ADTF_DX_TIMEOUT</td>
 * </tr>
 * </table>
 *
 * \par Who will be the timing master?
 * The timing master will be the first ADTF that performs the
 * ucom::IRuntime::CRLF_PreIncrementLevel during the state change to
 * ucom::IRuntime::RL_Running
 *
 * \par When will the time be synchronized?
 * The first time synchronization will be performed after an ADTF is set as
 * timing slave. This happens before changing to ucom::IRuntime::RL_Running.
 * Afterwards the timing master periodically sends the time to the timing slave.
 * The time period is set by property \b synchronizing_cycletime .
 *
 * \par How does the time synchronization work?
 * To calculate the time offset the most simple technique is used
 * (called PING-PONG). In the very beginning a message (PING) will be generated
 * and sent to another system via network. During generation a timestamp is
 * being generated, too. The addressed system will answer that message
 * immediately with another message (PONG). The network offset will be the half
 * the time between generation of PING and receiving of PONG.
 * @remarks To synchronize the network a reference time has to be defined. This
 * time will be sent to all other systems (called slaves).
 * @note To calculate a useful time offset the sending route should be the same
 * as the receiving route.
 *
 * Following the time measurement, the time will be transmitted
 * using the timing channel. On timing slaves the reference clock will be
 * adjusted by using a special algorithm. To have a meaningful time base, both
 * master and slave should be running some seconds before they are used.
 *
 * \par Short description of time sync protocol commands
 * The communication to synchronize the time between master and slaves uses
 * special messages. If a time sync communication is used without ADTF,
 * the following messages must be used:
 * <table>
 *  <tr>
 *   <th>Name</th>
 *   <th>Description</th>
 *  </tr>
 *  <tr>
 *   <td>@ref ADTF_DX_SET_TIMEMASTER</td>
 *   <td>@copydoc ADTF_DX_SET_TIMEMASTER</td>
 *  </tr>
 *  <tr>
 *   <td>@ref ADTF_DX_TIMEMASTER_REP</td>
 *   <td>@copydoc ADTF_DX_TIMEMASTER_REP</td>
 *  </tr>
 *  <tr>
 *   <td>@ref ADTF_DX_TIMEMASTER_REQ</td>
 *   <td>@copydoc ADTF_DX_TIMEMASTER_REQ</td>
 *  </tr>
 *  <tr>
 *   <td>@ref ADTF_DX_MEASURE_DELAY</td>
 *   <td>@copydoc ADTF_DX_MEASURE_DELAY</td>
 *  </tr>
 *  <tr>
 *   <td>@ref ADTF_DX_MEASURE_DELAY_REP</td>
 *   <td>@copydoc ADTF_DX_MEASURE_DELAY_REP</td>
 *  </tr>
 *  <tr>
 *   <td>@ref ADTF_DX_SYNCHRONIZE_FAR</td>
 *   <td>@copydoc ADTF_DX_SYNCHRONIZE_FAR</td>
 *  </tr>
 *  <tr>
 *   <td>@ref ADTF_DX_SYNCHRONIZE_FAR_REQ</td>
 *   <td>@copydoc ADTF_DX_SYNCHRONIZE_FAR_REQ</td>
 *  </tr>
 *  <tr>
 *   <td>@ref ADTF_DX_SYNCHRONIZE_FAR_REP</td>
 *   <td>@copydoc ADTF_DX_SYNCHRONIZE_FAR_REP</td>
 *  </tr>
 * </table>
 *
 * @remarks If the timing slave needs too much time during startup, the
 *          following hints may be helpful:
 *          \li reduce the synchronizing_timeout
 *          \li reduce the dx_channel_timeout
 * @remarks Both steps must be performed during one configuration step.
 */

/**
 * \page page_ADTF_udp_performance UDP Channel Performance
 *
 * Measuring and Performance Analysis for UDP-Messagebus-Channel can be done
 * using the Demo_MessageBus_NetIO_Filter delivered in ADTF examples.
 *
 * \par Setting up Performance Test using Demo_MessageBus_NetIO_Filter
 *
 * To setup performance test, 2 ADTF instances running Demo_MessageBus_NetIO_Filter
 * are necessary.
 *
 * <i>Setting up Server</i>
 *
 * -# Create configuration with Demo_MessageBus_NetIO_Filter
 * -# Set <b>Server Mode</b> property to <b>True</b>
 * -# Set <b>Server URL</b> to current PC ip address with port
 * and make sure port is not closed (e.g. udp://192.168.1.10:5555).
 * All other properties are for filter in server mode irrelevant.
 * In server mode, filter only receives messages and sends it back to the client.
 * -# Run Server Configuration
 *
 * <i>Setting up Client</i>
 * -# Create configuration with Demo_MessageBus_NetIO_Filter
 * -# Set <b>Client First Message Size</b> property. Message size is in KBytes and
 * will be increased by 2 each test period. Default is 1
 * -# Set <b>Client Generate Rate</b> property. Samples per second. If set to 0
 * samples will be send as fast as possible.
 * -# Set <b>Client Period Time</b> property. Duration of current test period
 * in seconds.
 * -# Set <b>Client Test Periods</b> property. How many periods should be done
 * during whole test phase. Each period increases message size by 2.
 * -# Set <b>Server Mode</b> property to <b>False</b>
 * -# Set <b>Server URL</b> to server PC ip address with port
 * and make sure port is not closed (e.g. udp://192.168.1.10:5555). <b>Note:</b>
 * Executing test on a single machine, additional forceclient flag must be set on
 * client side (e.g. udp://localhost:5555{forceclient=true}).
 * -# Run Client Configuration
 *
 * Make sure Server is always running before client.
 *
 * In Console View of ADTF client instance, measurement results are shown at the
 * end each test period.
 *
 * Example configuration can be found under
 * $ADTF_INSTALL_DIR/src/examples/src/filters/demo_messagebus_netio/configuration.
 *
 *
 * \par Tuning Possibilities
 *
 * - common Network
 *
 *   Generally recommended on 1 GBit-Ethernet, but mandatory on 10 GBit, is the
 *   usage of JumboFrames !\n
 *   --> this must be supported by Ethernet-Hardware/Driver (and by a switch, if connected)
 *
 * - Windowx XP
 *
 *   create a DWORD key: \n
 *   HKLM\\SYSTEM\\CurrentControlSet\\Services\\AFD\\Parameters\\FastSendDatagramThreshold \n
 *   --> recommended value on 1 GBit Ethernet: 16000 decimal
 *
 *   ==> this tuning had no effect during the performance-tests with Messagebus-Netio-Demo,
 *       but advantages are possible in certain applications.
 *
 * - Linux
 *
 *   the problem: setsockopt(SO_SNDBUF/SO_RCVBUF) is limited to an Operating-System maximum, \n
 *   on current distributions: 262144 byte.
 *
 *   --> increase the OS-maximum:
 *
 *       sysctl -w net.core.rmem_max=524288     # Maximum socket receive buffer size \n
 *       sysctl -w net.core.wmem_max=524288     # Maximum socket send buffer size
 *
 *       To make the change permanent, add the following lines to the /etc/sysctl.conf file,
 *       which is used during the boot process: \n
 *       net.core.rmem_max=262144 \n
 *       net.core.wmem_max=262144
 *
 *   ==> this tuning had no effect during the performance-tests with Messagebus-Netio-Demo,
 *       but advantages are possible in certain applications.
 *
 *
 * \par Limits and data drops
 *
 * Sending large sized data, like high resolution video, or sending data from
 * two or more different  sources to one destination on the same port, can
 * create following warning message.
 *
 * \code
 * 'Data dropped for channel message "<pin_name>"! Splitted message was not
 * completed! (<int number>)'
 * \endcode
 *
 * In video transmission case some frames will get lost and display can freeze
 * until next complete set of packets will be successfully received.
 *
 * To o avoid data drops make sure:
 * - There is only one sender on the same address:port
 * - Network is not heavily loaded
 * - Computer performance is appropriate
 *
 * On WindowsXP there is an additionally fact: the socket-implementation. A sendto()
 * with same packet size takes sometimes 3-5x longer as on Linux.
 *
 * Currently the only possibility to increase the data throughput:
 * use scaling your test environment, use more than one ADTF Messagebus
 * (means: use multiple independent threads for data transfer),
 * multi-core CPU's required.
 */

/*! Sets whether the message bus is enabled during startup. Defaults to tFalse*/
#define ADTF_DX_DEFAULT_VALUE_ENABLED tFalse
/*! Sets the time synchronization cycle in [us]. Only needed by the timemaster */
#define ADTF_DX_TIMEOUT 2500000
/*! Sets the timeout for network transfers in [us] */
#define ADTF_DX_TIMESYNC_CYCLE_TIME 1000000

/*! Sets the time master on the current channel. */
#define ADTF_DX_SET_TIMEMASTER "adtf.core.dx.settimemaster"
/*! Acknowledgement message of @ref ADTF_DX_SET_TIMEMASTER. */
#define ADTF_DX_TIMEMASTER_REP "adtf.core.dx.timemaster.reply"
/*! A time synchronize request to the timing master. */
#define ADTF_DX_TIMEMASTER_REQ "adtf.core.dx.timemaster.request"
/*!
 * Sends a message to another system. This message has to be answered as fast
 * as possible to get better time results.
 */
#define ADTF_DX_MEASURE_DELAY "adtf.core.dx.measure.delay"
/*! Acknowledgement message of @ref ADTF_DX_MEASURE_DELAY. */
#define ADTF_DX_MEASURE_DELAY_REP "adtf.core.dx.measure.delay.reply"
/*!
 * Sends the local stream time to another system. The related data is @ref
 * tMessageBusTime
 */
#define ADTF_DX_SYNCHRONIZE_FAR "adtf.core.dx.synchronize.far"
/*!
 * Time synchronize request to another system. Acknowledgement message will be
 * a @ref ADTF_DX_SYNCHRONIZE_FAR_REP.
 */
#define ADTF_DX_SYNCHRONIZE_FAR_REQ "adtf.core.dx.synchronize.far.request"
/*!
 * Acknowledgment message of @ref ADTF_DX_SYNCHRONIZE_FAR_REQ. The related data
 * is @ref tMessageBusTime
 */
#define ADTF_DX_SYNCHRONIZE_FAR_REP "adtf.core.dx.synchronize.far.reply"

/**
 * Time synchronization message.
 */
#define ADTF_DX_TIMESYNC_MSG "adtf.dx.timesync"
/**
 * Time synchronization message request.
 */
#define ADTF_DX_TIMESYNC_MSG_REQ "adtf.dx.timesync.req"
/**
 * Time synchronization master message.
 */
#define ADTF_DX_TIMEMASTER_MSG "adtf.dx.timemaster"
/**
 * Time synchronization master message request.
 */
#define ADTF_DX_TIMEMASTER_MSG_REQ "adtf.dx.timemaster.req"

/* these definitions are used to talk to ADTF Data Exchange via UDP */

/** ADTF UDP Packages Start Bytes */
#define  ADTF_DX_UDP_STARTBYTES           0xAD0FAD0F

/**
 *  ADTF UDP Packages Start Bytes when Endianess of sender is different!
 *  Always use ADTF_DX_UDP_STARTBYTES when sending the package.
 *  When sending Endianess dependent data and you need to know that, please put
 *  an Endianess identification in your data by yourself. I.e. you can
 *  use @ref PLATFORM_BYTEORDER.
 */
#define  ADTF_DX_UDP_STARTBYTES_ENDIANESS 0x0FAD0FAD


/**
 *  Use this identification number when using @ref tADTFDXUDPHeader.
 *  @remark renamed for better understanding.
 */
#define  ADTF_DX_UDP_HEADER_TYPE_NOID      0
/**
 *  Use this identification number when using @ref tADTFDXUDPHeader.
 */
#define  ADTF_DX_UDP_HEADER_TYPE_RAW      ADTF_DX_UDP_HEADER_TYPE_NOID

/**
 *  Use this identification number when using @ref tADTFDXUDPHeaderASync.
 */
#define  ADTF_DX_UDP_HEADER_TYPE_ASYNC    1

/**
 *  Use this identification number when using @ref tADTFDXUDPHeaderSync.
 */
#define  ADTF_DX_UDP_HEADER_TYPE_SYNC     2

/** ADTF UDP Packages maximal message size (65000)*/
#define  ADTF_DX_UDP_MAX_PACKAGESIZE      65000
/** ADTF UDP Protocol default port */
#define  ADTF_DX_UDP_DEFAULT_PORT         5000
/** ADTF UDP Receiver Default timeout in ms */
#define  ADTF_DX_UDP_RECEIVE_TIMEOUT      300000
/** ADTF UDP Protocol Receive Queue Size in message count */
#define  ADTF_DX_UDP_RECEIVE_QUEUESIZE    50

/**
 *  This Macro defines the maximal byte length (with trailing NULL)
 *  of a message id can be send through the UDP packages.
 */
#define  ADTF_DX_UDP_MAX_MESSAGEID_LENGTH    128


#ifdef WIN32
    #pragma pack(push)
    #pragma pack(1)
#else
    #pragma pack(push)
    #pragma pack(1)
#endif


/**
 * ADTF UDP Package defines for receiving ADTF UDP default protocol packages.
 * The header is followed by the data area:
 * This header is used to receive and send unmanaged NOID data.
 * \n
 * \n <b>UDP Data have the following structure:</b>
 * \n
 * <table>
 * <tr>
 *      <td> tADTFDXUDPHeader </td>
 *      <td> data bytes ... </td>
 * </tr>
 * <tr>
 *      <td> sizeof(tADTFDXUDPHeader) </td>
 *      <td> amount of bytes specified in ui32DataSize </td>
 * </tr>
 * </table>
 *
 * @see subsec_modes_NOID
 */
typedef struct tag_tADTFDXUDPHeader
{
    /** ADTF UDP Packages Start bytes: @ref ADTF_DX_UDP_STARTBYTES. */
    uint32_t    ui32StartBytes;
    /** ADTF Header Type
      * @see ADTF_DX_UDP_HEADER_TYPE_NOID macro.
      */
    uint8_t    ui8HeaderType;
    /** UDP Packages Sender ID. */
    uint32_t    ui32SenderUID;
    /** Sender Time (packages of the same message MUST have the same time). */
    int64_t tmTime;
    /** Size if data area in this package. */
    uint32_t    ui32DataSize;
    /** reserved for further use */
    uint8_t     _reserved1[11];
} tADTFDXUDPHeader;

/**
 * ADTF UDP Package defines for receiving ADTF UDP default protocol packages.
 * The header is followed by the data area:
 * This header is used to receive and send managed SYNC data by package counter
 * and message id.
 * \n
 * <table>
 * <tr>
 *      <td> tADTFDXUDPHeaderASync </td>
 *      <td> data bytes ... </td>
 * </tr>
 * <tr>
 *      <td> sizeof(tADTFDXUDPHeaderASync) </td>
 *      <td> amount of bytes specified in ui32DataSize </td>
 * </tr>
 * </table>
 *
 * @see subsec_modes_ASYNC
 */
typedef struct tag_tADTFDXUDPHeaderASync
{
    /** ADTF UDP Packages Start bytes: see ADTF_DX_UDP_STARTBYTES. */
    uint32_t    ui32StartBytes;
    /** ADTF Header Type */
    /** see ADTF_DX_UDP_HEADER_TYPE_ASYNC macro. */
    uint8_t    ui8HeaderType;
    /** UDP Packages Sender ID. */
    uint32_t    ui32SenderUID;
    /** Sender Time (packages of the same message MUST have the same time). */
    int64_t tmTime;
    /** Size if data area in this package. */
    uint32_t    ui32DataSize;
    /** reserved for further use */
    uint8_t     _reserved1[11];

    /** ADTF Message Id (must be NULL terminated). */
    char      strMsgId[ADTF_DX_UDP_MAX_MESSAGEID_LENGTH+2];
    /** Whole message size (only data area). */
    uint32_t    ui32MsgSize;
    /** If the message is longer than one UDP package then the packages are
       identified to encounter the order. Must be 0 or >0 and <ui8PackageCount. */
    uint8_t     ui8PackageId;
    /** If the message is longer than one UDP package this value gives the whole
      package count. Must be 1 or >1. */
    uint8_t     ui8PackageCount;
} tADTFDXUDPHeaderASync;

/**
 * ADTF UDP Package defines for receiving ADTF UDP default protocol packages.
 * The header is followed by the data area:
 * This header is used to receive and send managed SYNC data packages by package
 * counter and message id.
 * It also contains the message identifier to reply the data.
 * \n
 * <table>
 * <tr>
 *      <td> tADTFDXUDPHeaderSync </td>
 *      <td> data bytes ... </td>
 * </tr>
 * <tr>
 *      <td> sizeof(tADTFDXUDPHeaderSync) </td>
 *      <td> amount of bytes specified in ui32DataSize </td>
 * </tr>
 * </table>
 *
 * @see subsec_modes_SYNC
 */
typedef struct tag_tADTFDXUDPHeaderSync
{
    /** ADTF UDP Packages Start bytes: @ref ADTF_DX_UDP_STARTBYTES. */
    uint32_t    ui32StartBytes;
    /** ADTF Header Type
       @see ADTF_DX_UDP_HEADER_TYPE_SYNC macro. */
    uint8_t    ui8HeaderType;
    /** UDP Packages Sender ID. */
    uint32_t    ui32SenderUID;
    /** Sender Time (packages of the same message MUST have the same time). */
    int64_t tmTime;
    /** Size if data area in this package. */
    uint32_t    ui32DataSize;
    /** reserved for further use */
    uint8_t     _reserved1[11];

    /** ADTF Message Id (must be NULL terminated). */
    char      strMsgId[ADTF_DX_UDP_MAX_MESSAGEID_LENGTH+2];
    /** Whole message size (only data area). */
    uint32_t    ui32MsgSize;
    /** When the message is longer then than one UDP package. Then the packages
      are identified to encounter the order. Must be 0 or >0 and <ui8PackageCount. */
    uint8_t     ui8PackageId;
    /** When the message is longer then than one UDP package it gives the whole
     package count. Must be 1 ore >1. */
    uint8_t     ui8PackageCount;

    /** ADTF Message Id for answer (must be NULL terminated). */
    char      strMsgIdReply[ADTF_DX_UDP_MAX_MESSAGEID_LENGTH];
} tADTFDXUDPHeaderSync;

#pragma pack(pop)

#endif /* _ADDITIONAL_UDP_EXTENSION_HEADER_ */

