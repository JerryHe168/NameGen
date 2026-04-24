#include <iostream>
#include <memory>
#include <map>
#include <string>

#include "utils/ConsoleUtils.h"
#include "utils/Random.h"
#include "generators/NameGenerator.h"
#include "generators/ChineseNameGenerator.h"
#include "generators/EnglishNameGenerator.h"
#include "generators/JapaneseNameGenerator.h"

using namespace NameGen;
using namespace NameGen::Utils;
using namespace NameGen::Generators;

enum class MenuOption {
    EXIT = 0,
    CHINESE_NAME = 1,
    ENGLISH_NAME = 2,
    JAPANESE_NAME = 3,
    ALL_STYLES = 4
};

void displayMainMenu() {
    ConsoleUtils::clearScreen();
    ConsoleUtils::printHeader("多风格姓名生成器");
    ConsoleUtils::println("");
    ConsoleUtils::println("请选择姓名风格:");
    ConsoleUtils::printMenuOption(static_cast<int>(MenuOption::CHINESE_NAME), "生成中文名");
    ConsoleUtils::printMenuOption(static_cast<int>(MenuOption::ENGLISH_NAME), "生成英文名");
    ConsoleUtils::printMenuOption(static_cast<int>(MenuOption::JAPANESE_NAME), "生成日文名");
    ConsoleUtils::printMenuOption(static_cast<int>(MenuOption::ALL_STYLES), "生成全部风格");
    ConsoleUtils::println("");
    ConsoleUtils::printMenuOption(static_cast<int>(MenuOption::EXIT), "退出程序");
    ConsoleUtils::printLine('-');
}

std::unique_ptr<NameGenerator> createGenerator(MenuOption option) {
    switch (option) {
        case MenuOption::CHINESE_NAME:
            return std::make_unique<ChineseNameGenerator>();
        case MenuOption::ENGLISH_NAME:
            return std::make_unique<EnglishNameGenerator>();
        case MenuOption::JAPANESE_NAME:
            return std::make_unique<JapaneseNameGenerator>();
        default:
            return nullptr;
    }
}

void generateNames(MenuOption option) {
    ConsoleUtils::clearScreen();
    
    if (option == MenuOption::ALL_STYLES) {
        int count = ConsoleUtils::getIntInput("请输入每种风格要生成的姓名数量 (1-10): ", 1, 10);
        ConsoleUtils::println("");
        
        std::vector<std::unique_ptr<NameGenerator>> generators;
        generators.push_back(std::make_unique<ChineseNameGenerator>());
        generators.push_back(std::make_unique<EnglishNameGenerator>());
        generators.push_back(std::make_unique<JapaneseNameGenerator>());
        
        for (const auto& generator : generators) {
            ConsoleUtils::printLine('=', 50);
            generator->generateMultiple(count);
            ConsoleUtils::println("");
        }
    } else {
        auto generator = createGenerator(option);
        if (!generator) {
            ConsoleUtils::printError("无效的选项");
            ConsoleUtils::pause();
            return;
        }
        
        ConsoleUtils::printHeader("生成" + generator->getStyleName());
        int count = ConsoleUtils::getIntInput("请输入要生成的姓名数量 (1-10): ", 1, 10);
        ConsoleUtils::println("");
        
        generator->generateMultiple(count);
    }
    
    ConsoleUtils::println("");
    ConsoleUtils::pause();
}

int main() {
    ConsoleUtils::init();
    
    Random::instance();
    
    MenuOption choice;
    
    do {
        displayMainMenu();
        int input = ConsoleUtils::getIntInput("请输入选项 (0-4): ", 0, 4);
        choice = static_cast<MenuOption>(input);
        
        switch (choice) {
            case MenuOption::CHINESE_NAME:
            case MenuOption::ENGLISH_NAME:
            case MenuOption::JAPANESE_NAME:
            case MenuOption::ALL_STYLES:
                generateNames(choice);
                break;
            case MenuOption::EXIT:
                ConsoleUtils::printInfo("感谢使用，再见！");
                break;
            default:
                ConsoleUtils::printError("无效选项，请重新选择");
                ConsoleUtils::pause();
                break;
        }
        
    } while (choice != MenuOption::EXIT);
    
    ConsoleUtils::cleanup();
    return 0;
}
