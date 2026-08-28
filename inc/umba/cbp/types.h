/*! \file
    \brief Типы для umba::cbp
 */

#pragma once

//--------------------------------------------------------------------------------------------------------------------
#include "umba/filename.h"
#include "umba/filesys.h"

//
#include <ixwebsocket/IXNetSystem.h>
#include <ixwebsocket/IXWebSocket.h>
#include <ixwebsocket/IXHttpClient.h>
//
#include <nlohmann/json.hpp>

//
#include <string>
#include <vector>

//--------------------------------------------------------------------------------------------------------------------



//--------------------------------------------------------------------------------------------------------------------
// #include "umba/cbp/types.h"
// umba::chrome_devtools_protocol::
// umba::cdp::

namespace umba {
namespace chrome_devtools_protocol {

//----------------------------------------------------------------------------
using json = nlohmann::json;

//----------------------------------------------------------------------------


//--------------------------------------------------------------------------------------------------------------------
//enum class BaseConnectResult



//--------------------------------------------------------------------------------------------------------------------
struct Timeouts
{
    int connectTimeout    = 1; // 1 секунда на подключение
    int transferTimeout   = 1; // 1 секунда на получение данных

    Timeouts& setConnectTimeout(int t)
    {
        connectTimeout = t;
        return *this;
    }

    Timeouts& setTransferTimeout(int t)
    {
        transferTimeout = t;
        return *this;
    }

    Timeouts getCopy() const 
    {
        return *this;
    }

}; // struct Timeouts





//--------------------------------------------------------------------------------------------------------------------

} // namespace chrome_devtools_protocol

namespace cdp = chrome_devtools_protocol;

} // namespace umba

// #include "umba/cbp/types.h"
// umba::chrome_devtools_protocol::
// umba::cdp::

//--------------------------------------------------------------------------------------------------------------------



//--------------------------------------------------------------------------------------------------------------------
#include "JsonListResponse.h"
#include "JsonVersionResponse.h"

//--------------------------------------------------------------------------------------------------------------------




