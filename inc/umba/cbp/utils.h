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

} // namespace utils
} // namespace chrome_devtools_protocol

namespace cdp = chrome_devtools_protocol;

} // namespace umba

// #include "umba/cbp/utils.h"
// umba::chrome_devtools_protocol::utils::
// umba::cdp::utils::

//--------------------------------------------------------------------------------------------------------------------

