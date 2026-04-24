#ifndef CONSOLEUTILS_H
#define CONSOLEUTILS_H

#include <string>
#include <iostream>

namespace NameGen {
namespace Utils {

class ConsoleUtils {
public:
    static void init();
    static void cleanup();
    
    static void print(const std::string& message);
    static void println(const std::string& message);
    static void printLine(char character = '-', int length = 40);
    
    static void printHeader(const std::string& title);
    static void printMenuOption(int index, const std::string& option);
    static void printSuccess(const std::string& message);
    static void printError(const std::string& message);
    static void printInfo(const std::string& message);
    
    static void clearScreen();
    static void pause();
    
    static int getIntInput(const std::string& prompt, int min = 0, int max = 100);
    static std::string getStringInput(const std::string& prompt);
    static char getCharInput(const std::string& prompt);
    
private:
    static bool m_initialized;
#ifdef _WIN32
    static unsigned int m_oldOutputCP;
    static unsigned int m_oldInputCP;
#endif
};

} // namespace Utils
} // namespace NameGen

#endif // CONSOLEUTILS_H
