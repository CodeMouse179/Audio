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
}