#include "utils/ConsoleUtils.h"
#include <limits>

#ifdef _WIN32
#define NOMINMAX
#include <windows.h>
#else
#include <termios.h>
#include <unistd.h>
#include <cstdio>
#endif

namespace NameGen {
namespace Utils {

bool ConsoleUtils::m_initialized = false;
#ifdef _WIN32
unsigned int ConsoleUtils::m_oldOutputCP = 0;
unsigned int ConsoleUtils::m_oldInputCP = 0;
#endif

void ConsoleUtils::init() {
    if (m_initialized) return;
    
#ifdef _WIN32
    m_oldOutputCP = GetConsoleOutputCP();
    m_oldInputCP = GetConsoleCP();
    
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
#else
    setlocale(LC_ALL, "");
#endif
    
    m_initialized = true;
}

void ConsoleUtils::cleanup() {
    if (!m_initialized) return;
    
#ifdef _WIN32
    SetConsoleOutputCP(m_oldOutputCP);
    SetConsoleCP(m_oldInputCP);
#endif
    
    m_initialized = false;
}

void ConsoleUtils::print(const std::string& message) {
    std::cout << message;
    std::cout.flush();
}

void ConsoleUtils::println(const std::string& message) {
    std::cout << message << std::endl;
}

void ConsoleUtils::printLine(char character, int length) {
    std::string line(length, character);
    println(line);
}

void ConsoleUtils::printHeader(const std::string& title) {
    const int totalWidth = 50;
    int padding = (totalWidth - static_cast<int>(title.length())) / 2;
    
    printLine('=', totalWidth);
    println(std::string(padding, ' ') + title);
    printLine('=', totalWidth);
}

void ConsoleUtils::printMenuOption(int index, const std::string& option) {
    println("  [" + std::to_string(index) + "] " + option);
}

void ConsoleUtils::printSuccess(const std::string& message) {
#ifdef _WIN32
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD savedAttributes;
    
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    savedAttributes = consoleInfo.wAttributes;
    
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    println("[SUCCESS] " + message);
    
    SetConsoleTextAttribute(hConsole, savedAttributes);
#else
    println("\033[1;32m[SUCCESS]\033[0m " + message);
#endif
}

void ConsoleUtils::printError(const std::string& message) {
#ifdef _WIN32
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD savedAttributes;
    
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    savedAttributes = consoleInfo.wAttributes;
    
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
    println("[ERROR] " + message);
    
    SetConsoleTextAttribute(hConsole, savedAttributes);
#else
    println("\033[1;31m[ERROR]\033[0m " + message);
#endif
}

void ConsoleUtils::printInfo(const std::string& message) {
#ifdef _WIN32
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD savedAttributes;
    
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    savedAttributes = consoleInfo.wAttributes;
    
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    println("[INFO] " + message);
    
    SetConsoleTextAttribute(hConsole, savedAttributes);
#else
    println("\033[1;34m[INFO]\033[0m " + message);
#endif
}

void ConsoleUtils::clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void ConsoleUtils::pause() {
    println("按任意键继续...");
#ifdef _WIN32
    system("pause > nul");
#else
    struct termios oldt, newt;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
#endif
}

int ConsoleUtils::getIntInput(const std::string& prompt, int min, int max) {
    int input;
    while (true) {
        print(prompt);
        if (std::cin >> input) {
            if (input >= min && input <= max) {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                return input;
            } else {
                printError("请输入介于 " + std::to_string(min) + " 和 " + std::to_string(max) + " 之间的数字");
            }
        } else {
            printError("无效输入，请输入一个数字");
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

std::string ConsoleUtils::getStringInput(const std::string& prompt) {
    std::string input;
    print(prompt);
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, input);
    return input;
}

char ConsoleUtils::getCharInput(const std::string& prompt) {
    char input;
    print(prompt);
    std::cin >> input;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return input;
}

} // namespace Utils
} // namespace NameGen
