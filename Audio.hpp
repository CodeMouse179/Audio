#ifndef CODEMOUSE_AUDIO_HPP
#define CODEMOUSE_AUDIO_HPP

#include "String.hpp"
#include <Windows.h>
#include <Mmsystem.h>

namespace CodeMouse
{
    struct MCIResult
    {
    public:
        MCIERROR errorCode;
        std::wstring returnString;

    public:
        MCIResult()
        {
            this->errorCode = 0;
            this->returnString = L"";
        }

        MCIResult(MCIERROR errorCode, const std::wstring& returnString)
        {
            this->errorCode = errorCode;
            this->returnString = returnString;
        }

        bool OK()
        {
            return this->errorCode == 0;
        }
    };

    class MCI
    {
    public:
        static MCIResult SendString(const std::wstring& s);

        static MCIResult GetErrorString(MCIERROR errorCode);
    };

    class MCIHelper
    {
    public:
        static MCIResult Open(const std::wstring& path, const std::wstring& alias);

        static MCIResult Close(const std::wstring& shortPathOrAlias);

        static MCIResult Play(const std::wstring& shortPathOrAlias);
    };

    class InternalTool
    {
    public:
        //return empty string if failed.
        static std::wstring ShortPathName(const std::wstring& path);
    };

    class Audio
    {
    public:
    };
}

#endif