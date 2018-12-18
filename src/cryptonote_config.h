// Copyright (c) 2017-2018, The NERVA Project
// Copyright (c) 2017-2018, The Masari Project
// Copyright (c) 2014-2018, The Monero Project
// 
// All rights reserved.
// 
// Redistribution and use in source and binary forms, with or without modification, are
// permitted provided that the following conditions are met:
// 
// 1. Redistributions of source code must retain the above copyright notice, this list of
//    conditions and the following disclaimer.
// 
// 2. Redistributions in binary form must reproduce the above copyright notice, this list
//    of conditions and the following disclaimer in the documentation and/or other
//    materials provided with the distribution.
// 
// 3. Neither the name of the copyright holder nor the names of its contributors may be
//    used to endorse or promote products derived from this software without specific
//    prior written permission.
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY
// EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
// MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL
// THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
// PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
// STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF
// THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
// 
// Parts of this file are originally copyright (c) 2012-2013 The Cryptonote developers

#pragma once

#include <string>
#include <set>
#include <boost/uuid/uuid.hpp>

#define CRYPTONOTE_DNS_TIMEOUT_MS                       20000

#define CRYPTONOTE_MAX_BLOCK_NUMBER                     500000000
#define CRYPTONOTE_MAX_BLOCK_SIZE                       500000000  // block header blob limit, never used!
#define CRYPTONOTE_MAX_TX_SIZE                          1000000000
#define CRYPTONOTE_PUBLIC_ADDRESS_TEXTBLOB_VER          0
#define CRYPTONOTE_MINED_MONEY_UNLOCK_WINDOW            30
#define CRYPTONOTE_MINED_MONEY_UNLOCK_WINDOW_V6         30
#define CURRENT_TRANSACTION_VERSION                     1
#define CURRENT_BLOCK_MAJOR_VERSION                     1
#define CURRENT_BLOCK_MINOR_VERSION                     1
#define CRYPTONOTE_BLOCK_FUTURE_TIME_LIMIT              60*60*2
#define CRYPTONOTE_DEFAULT_TX_SPENDABLE_AGE             10

#define BLOCKCHAIN_TIMESTAMP_CHECK_WINDOW               60

#define CRYPTONOTE_BLOCK_FUTURE_TIME_LIMIT_V2           60*24
#define BLOCKCHAIN_TIMESTAMP_CHECK_WINDOW_V2            12

#define CRYPTONOTE_BLOCK_FUTURE_TIME_LIMIT_V6           60*5

// MONEY_SUPPLY - total number coins to be generated
#define MONEY_SUPPLY                                    ((uint64_t)177777776000000000)
#define EMISSION_SPEED_FACTOR_PER_MINUTE                (19) 
#define FINAL_SUBSIDY_PER_MINUTE                        ((uint64_t)8000000000) // 8 * pow(10, 9)

#define CRYPTONOTE_REWARD_BLOCKS_WINDOW                 30
#define CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_V1    245760
#define CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_V2    245760 // 2 * 240 Kb
#define CRYPTONOTE_COINBASE_BLOB_RESERVED_SIZE          600
#define CRYPTONOTE_DISPLAY_DECIMAL_POINT                12
// COIN - number of smallest units in one coin
#define COIN                                            ((uint64_t)1000000000) // pow(10, 9)

#define DEFAULT_MIXIN                                   4
#define DEFAULT_RINGSIZE                                DEFAULT_MIXIN + 1
#define DYNAMIC_FEE_PER_KB_BASE_FEE                     ((uint64_t)400000000) // 4 * pow(10,8)))
#define DYNAMIC_FEE_PER_KB_BASE_BLOCK_REWARD            ((uint64_t)10000000000000) // 10 * pow(10,12)

#define DIFFICULTY_TARGET                               120  // seconds
#define DIFFICULTY_WINDOW                               360 // blocks old / 2 for increasing difficulty_target
#define DIFFICULTY_LAG                                  15  // !!! ???
#define DIFFICULTY_CUT                                  60  // timestamps to cut after sorting
#define DIFFICULTY_BLOCKS_COUNT                         DIFFICULTY_WINDOW + DIFFICULTY_LAG

#define DIFFICULTY_BLOCKS_ESTIMATE_TIMESPAN             DIFFICULTY_TARGET //just alias; used by tests
#define DIFFICULTY_WINDOW_V2                            34 //(reduced i guess to 17 due to high rate of emission doubling it)
#define DIFFICULTY_CUT_V2                               12 // (increasing this too short)
#define DIFFICULTY_BLOCKS_COUNT_V2                      DIFFICULTY_WINDOW_V2 + DIFFICULTY_CUT_V2*2

#define DIFFICULTY_WINDOW_V3                            120
#define DIFFICULTY_BLOCKS_COUNT_V3                      DIFFICULTY_WINDOW_V3

#define DIFFICULTY_WINDOW_V6                            120
#define DIFFICULTY_BLOCKS_COUNT_V6                      DIFFICULTY_WINDOW_V6 + 1

#define CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_SECONDS_V1   DIFFICULTY_TARGET * CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_BLOCKS
#define CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_BLOCKS       1

#define BLOCKS_IDS_SYNCHRONIZING_DEFAULT_COUNT          10000  //by default, blocks ids count in synchronizing
#define BLOCKS_SYNCHRONIZING_DEFAULT_COUNT              20     //by default, blocks count in blocks downloading

#define CRYPTONOTE_MEMPOOL_TX_LIVETIME                    (86400) //seconds, three days // reducing to one day to counter tx spam attacks
#define CRYPTONOTE_MEMPOOL_TX_FROM_ALT_BLOCK_LIVETIME     151200 //seconds, one week// divided by 4 for the same reason as above

#define COMMAND_RPC_GET_BLOCKS_FAST_MAX_COUNT           1000

#define P2P_LOCAL_WHITE_PEERLIST_LIMIT                  1000
#define P2P_LOCAL_GRAY_PEERLIST_LIMIT                   5000

#define P2P_DEFAULT_CONNECTIONS_COUNT                   8
#define P2P_DEFAULT_HANDSHAKE_INTERVAL                  60           //secondes
#define P2P_DEFAULT_PACKET_MAX_SIZE                     50000000     //50000000 bytes maximum packet size
#define P2P_DEFAULT_PEERS_IN_HANDSHAKE                  250
#define P2P_DEFAULT_CONNECTION_TIMEOUT                  5000       //5 seconds
#define P2P_DEFAULT_PING_CONNECTION_TIMEOUT             2000       //2 seconds
#define P2P_DEFAULT_INVOKE_TIMEOUT                      60*2*1000  //2 minutes
#define P2P_DEFAULT_HANDSHAKE_INVOKE_TIMEOUT            5000       //5 seconds
#define P2P_DEFAULT_WHITELIST_CONNECTIONS_PERCENT       70
#define P2P_DEFAULT_ANCHOR_CONNECTIONS_COUNT            4  // excpecting too many nodes due to pow increasing anchor connections for local node stability // 

#define HF_SUPPORTED_MIN_VERSION                        version_string_to_integer("1.0.5.0")
#define SUPPORTED_MIN_VERSION                           version_string_to_integer("1.0.4.1")

#define P2P_FAILED_ADDR_FORGET_SECONDS                  (1)          //1 second LMAO
#define P2P_IP_BLOCKTIME_MAINNET                        (1)          //1 second LMAO
#define P2P_IP_BLOCKTIME_TESTNET                        (60*5)       //5 minutes
#define P2P_IP_FAILS_BEFORE_BLOCK                       100000000000 // LMAOOO
#define P2P_IDLE_CONNECTION_KILL_INTERVAL               (5*60)       //5 minutes

#define P2P_SUPPORT_FLAG_FLUFFY_BLOCKS                  0x01
#define P2P_SUPPORT_FLAGS                               P2P_SUPPORT_FLAG_FLUFFY_BLOCKS

#define ALLOW_DEBUG_COMMANDS

#define CRYPTONOTE_NAME                         "Turd" // The mighty Turd
#define CRYPTONOTE_POOLDATA_FILENAME            "poolstate.bin"
#define CRYPTONOTE_BLOCKCHAINDATA_FILENAME      "hyc.mdb" // The bold violin player work of art
#define CRYPTONOTE_BLOCKCHAINDATA_LOCK_FILENAME "lock.mdb"
#define P2P_NET_DATA_FILENAME                   "turdnodeslist.bin" // :)
#define MINER_CONFIG_FILE_NAME                  "miner_conf.json"

#define THREAD_STACK_SIZE                       5 * 1024 * 1024

#define PER_KB_FEE_QUANTIZATION_DECIMALS        8

#define HASH_OF_HASHES_STEP                     256

#define DEFAULT_TXPOOL_MAX_SIZE                 648000000ull // 3 days at 300000, in bytes

// New constants are intended to go here
namespace config
{
  uint64_t const DEFAULT_DUST_THRESHOLD = 0; // deprecated
  std::string const P2P_REMOTE_DEBUG_TRUSTED_PUB_KEY = "0000000000000000000000000000000000000000000000000000000000000000";


  uint64_t const CRYPTONOTE_PUBLIC_ADDRESS_BASE58_PREFIX = 0x197220; // Turd
  uint64_t const CRYPTONOTE_PUBLIC_INTEGRATED_ADDRESS_BASE58_PREFIX = 0x1bf220; // Turi
  uint64_t const CRYPTONOTE_PUBLIC_SUBADDRESS_BASE58_PREFIX = 0x187220; // Turb
  uint16_t const P2P_DEFAULT_PORT = 12210;
  uint16_t const RPC_DEFAULT_PORT = 12211;
  uint16_t const ZMQ_RPC_DEFAULT_PORT = 12213;
  boost::uuids::uuid const NETWORK_ID = { {
      0xcd, 0xac, 0x50, 0x2e, 0xb3, 0x74, 0x8f, 0xf2, 0x0f, 0xb7, 0x72, 0x18, 0x0f, 0x73, 0x24, 0x13
    } }; // Turd's nightmare
  std::string const GENESIS_TX = "013c01ff0001ffffffffffff03029b2e4c0281c0b02e7c53291a94d1d0cbff8883f8024f5142ee494ffbbd08807121017767aafcde9be00dcfd098715ebcf7f410daebc582fda69d24a28e9d0bc890d1"; // Deleted Genesis Hash we'll add upon mainnet launch along with fork hashes and new fork blocks (since we keep nerva's fork changes and not merging them cause we are too lazy and too scammy)
  uint32_t const GENESIS_NONCE = 9876;
  std::set<std::string> const seed_nodes = {
     "82.37.88.209:12210",
     "51.68.46.120:12210",
     "185.229.236.165:12210"};

  namespace testnet
  {
    uint64_t const CRYPTONOTE_PUBLIC_ADDRESS_BASE58_PREFIX = 0x3beca0; // TuTd
    uint64_t const CRYPTONOTE_PUBLIC_INTEGRATED_ADDRESS_BASE58_PREFIX = 0x3eaca0; // TuTi
    uint64_t const CRYPTONOTE_PUBLIC_SUBADDRESS_BASE58_PREFIX = 0x3aeca0; // TuTb
    uint16_t const P2P_DEFAULT_PORT = 22210;
    uint16_t const RPC_DEFAULT_PORT = 22211;
    uint16_t const ZMQ_RPC_DEFAULT_PORT = 22212;
    boost::uuids::uuid const NETWORK_ID = { {
        0x12 ,0x30, 0xF1, 0x71 , 0x61, 0x04 , 0x41, 0x61, 0x17, 0x31, 0x00, 0x82, 0x16, 0xA1, 0xA1, 0x11
      } }; // Bender's daydream
    // leaving the genesis hash unaltered we are too romanian too have a testnet we dont need it 
    std::string const GENESIS_TX = "013c01ff0001ffffffffffff03029b2e4c0281c0b02e7c53291a94d1d0cbff8883f8024f5142ee494ffbbd08807121017767aafcde9be00dcfd098715ebcf7f410daebc582fda69d24a28e9d0bc890d1";
    uint32_t const GENESIS_NONCE = 10001;
    std::set<std::string> const seed_nodes = {
      "82.37.88.209:22210",
      "51.68.46.120:22210",
      "185.229.236.165:22210"};
  }

  namespace stagenet
  {

    uint64_t const CRYPTONOTE_PUBLIC_ADDRESS_BASE58_PREFIX = 0x1eaca0; // TuSd
    uint64_t const CRYPTONOTE_PUBLIC_INTEGRATED_ADDRESS_BASE58_PREFIX = 0x216ca0; // TuSi
    uint64_t const CRYPTONOTE_PUBLIC_SUBADDRESS_BASE58_PREFIX = 0x1daca0; // TuSb
    uint16_t const P2P_DEFAULT_PORT = 32210;
    uint16_t const RPC_DEFAULT_PORT = 32211;
    uint16_t const ZMQ_RPC_DEFAULT_PORT = 32212;
    boost::uuids::uuid const NETWORK_ID = { {
        0x12 ,0x30, 0xF1, 0x71 , 0x61, 0x04 , 0x41, 0x61, 0x17, 0x31, 0x00, 0x82, 0x16, 0xA1, 0xA1, 0x12
      } }; // Bender's daydream
    std::string const GENESIS_TX = "013c01ff0001ffffffffffff0302df5d56da0c7d643ddd1ce61901c7bdc5fb1738bfe39fbe69c28a3a7032729c0f2101168d0c4ca86fb55a4cf6a36d31431be1c53a3bd7411bb24e8832410289fa6f3b";
    uint32_t const GENESIS_NONCE = 10002;
    std::set<std::string> const seed_nodes = {
      "82.37.88.209:32210",
      "51.68.46.120:32210",
      "185.229.236.165:32210"};
  }
}

#ifndef VERSION_TO_INT
#define VERSION_TO_INT

inline uint32_t version_string_to_integer(std::string data)
{
  const char* v = data.c_str();

  unsigned int byte3;
  unsigned int byte2;
  unsigned int byte1;
  unsigned int byte0;
  char dummyString[2];

  if (sscanf (v, "%u.%u.%u.%u%1s", &byte3, &byte2, &byte1, &byte0, dummyString) == 4)
  {
    if ((byte3 < 256) && (byte2 < 256) && (byte1 < 256) && (byte0 < 256))
      return (byte3 << 24) + (byte2 << 16) + (byte1 << 8) +  byte0;
  }

  return 0;
}

#endif

namespace cryptonote
{
  enum network_type : uint8_t
  {
    MAINNET = 0,
    TESTNET,
    STAGENET,
    FAKECHAIN,
    UNDEFINED = 255
  };
}
