/*! \file
    \brief Различные утилиты для umba::cbp
 */

#pragma once

//--------------------------------------------------------------------------------------------------------------------
#include "umba/filename.h"
#include "umba/filesys.h"

//--------------------------------------------------------------------------------------------------------------------



//--------------------------------------------------------------------------------------------------------------------
// #include "umba/cbp/utils.h"
// umba::chrome_devtools_protocol::utils::
// umba::cdp::utils::

namespace umba {
namespace chrome_devtools_protocol {
namespace utils {

//--------------------------------------------------------------------------------------------------------------------



//--------------------------------------------------------------------------------------------------------------------
inline
std::string generateChromeUserDataFolderForProjectImpl( const std::string &folderRole // profile, cache etc
                                                      , std::string projectPath
                                                      , std::string browserName=std::string()
                                                      , const std::string &projectSubfolder=std::string() // if empty use temp folder
                                                      )
{
    projectPath = umba::filename::makeCanonical(projectPath);

    if (browserName.empty())
        browserName = "chrome";

    if (!projectSubfolder.empty())
    {
        projectPath = umba::filename::appendPath(projectPath, projectSubfolder);
        return umba::filename::makeCanonical(umba::filename::appendPath(projectPath, "." + browserName + "-" + folderRole));
    }

    auto flattenPath = umba::filename::flattenPath(projectPath);

    projectPath = umba::filesys::getTempFolderPath();
    projectPath = umba::filename::appendPath(projectPath, "." + browserName + "-" + folderRole);
    return umba::filename::appendPath(projectPath, flattenPath);
}

//--------------------------------------------------------------------------------------------------------------------
inline
std::string generateChromeUserProfileFolderForProject( std::string projectPath
                                                     , std::string browserName=std::string()
                                                     , const std::string &projectSubfolder=std::string() // if empty use temp folder
                                                     )
{
    return generateChromeUserDataFolderForProjectImpl("profile", projectPath, browserName, projectSubfolder);
}

//--------------------------------------------------------------------------------------------------------------------
inline
std::string generateChromeUserCacheFolderForProject( std::string projectPath
                                                   , std::string browserName=std::string()
                                                   , const std::string &projectSubfolder=std::string() // if empty use temp folder
                                                   )
{
    return generateChromeUserDataFolderForProjectImpl("cache", projectPath, browserName, projectSubfolder);
}

//--------------------------------------------------------------------------------------------------------------------




//--------------------------------------------------------------------------------------------------------------------
/*
    Порт можно потом проверить
    http://localhost:SOME_PORT/json/version

    {
      "Browser": "Chrome/118.0.5993.88",
      "Protocol-Version": "1.3",
      "User-Agent": "...",
      "V8-Version": "...",
      "WebKit-Version": "...",
      "webSocketDebuggerUrl": "...",
      "userDataDir": "/home/user/.config/google-chrome/MyProfile"
    }

    и сравнить с тем, какой предполагается для данного порта. Если отличается - значит, произошла коллизия по порту.

    Тогда рапортуем и выходим
*/

inline
int generatePortNumberForProjectConnection(std::string projectPath, int startPort=9000, int range=1000)
{
    filename::stripLastPathSep(projectPath);

    std::size_t h = std::hash<std::string>{}(projectPath);

    return startPort + int(h%std::size_t(range));
}

//--------------------------------------------------------------------------------------------------------------------



//--------------------------------------------------------------------------------------------------------------------

} // namespace utils
} // namespace chrome_devtools_protocol

namespace cdp = chrome_devtools_protocol;

} // namespace umba

// #include "umba/cbp/utils.h"
// umba::chrome_devtools_protocol::utils::
// umba::cdp::utils::

//--------------------------------------------------------------------------------------------------------------------

