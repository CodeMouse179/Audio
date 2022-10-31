#include "Audio.hpp"
#pragma comment(lib, "Winmm.lib")

namespace CodeMouse
{
    MCIResult MCI::SendString(const std::wstring& s)
    {
        wchar_t returnString[128];
        MCIERROR errorCode = mciSendString(s.c_str(), returnString, 128, NULL);
        return MCIResult(errorCode, returnString);
    }

    MCIResult MCI::GetErrorString(MCIERROR errorCode)
    {
        wchar_t errorText[128];
        BOOL ret = mciGetErrorString(errorCode, errorText, 128);
        if (ret) return MCIResult(0, errorText);
        else return MCIResult(1, L"");
    }

    std::wstring InternalTool::ShortPathName(const std::wstring& path)
    {
        wchar_t buffer[MAX_PATH];
        bool success = GetShortPathName(path.c_str(), buffer, MAX_PATH);
        if (success) return std::wstring(buffer);
        else return std::wstring();
    }
}