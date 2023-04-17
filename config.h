#pragma once
#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720

#ifdef __linux__
#define FONT_DIR "/usr/share/fonts/WindowsFonts/"
#elif _WIN32
#include <iso646.h> // MSVC consider "not" undeclared identifier
#define FONT_DIR "C:\\Windows\\Fonts\\"
#else

#endif