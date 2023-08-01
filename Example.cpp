#include "Audio.hpp"
int main()
{
    CodeMouse::MCIResult result = CodeMouse::MCI::GetErrorString(0);
    auto x = CodeMouse::MCIHelper::Open(L"C:/Users/16692/Desktop/audios/小松未歩 - 謎.mp3", L"test");
    //auto x = CodeMouse::MCIHelper::Open(L"C:/Users/16692/Desktop/audios/Silent Hill 2 OST - Promise.mp3", L"test");
    auto y = CodeMouse::MCIHelper::Play(L"test");
    getchar();
    auto z = CodeMouse::MCIHelper::Stop(L"test");
    CodeMouse::MCIHelper::Play(L"test");
    system("pause");
    return 0;
}