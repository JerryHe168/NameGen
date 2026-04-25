#include <iostream>
#include <memory>
#include <map>
#include <string>
#include <vector>

#include "utils/ConsoleUtils.h"
#include "utils/Random.h"
#include "config/NameGenConfig.h"
#include "generators/NameGenerator.h"
#include "generators/ChineseNameGenerator.h"
#include "generators/EnglishNameGenerator.h"
#include "generators/JapaneseNameGenerator.h"

using namespace NameGen;
using namespace NameGen::Utils;
using namespace NameGen::Generators;
using namespace NameGen::Config;

enum class MenuLevel {
    Main,
    SurnameType,
    Gender,
    NameLength,
    Count
};

enum class MainMenuOption {
    EXIT = 0,
    CHINESE_SINGLE = 1,
    CHINESE_COMPOUND = 2,
    ENGLISH_NAME = 3,
    JAPANESE_NAME = 4,
    ALL_STYLES = 5
};

enum class SurnameMenuOption {
    BACK = 0,
    CONTINUE = 1
};

enum class GenderMenuOption {
    BACK = 0,
    MALE = 1,
    FEMALE = 2,
    MIXED = 3
};

enum class LengthMenuOption {
    BACK = 0,
    SINGLE = 1,
    DOUBLE = 2,
    MIXED = 3
};

void displayMainMenu() {
    ConsoleUtils::clearScreen();
    ConsoleUtils::printHeader("多风格姓名生成器");
    ConsoleUtils::println("");
    ConsoleUtils::println("请选择姓名风格:");
    ConsoleUtils::printMenuOption(static_cast<int>(MainMenuOption::CHINESE_SINGLE), "生成中文名（单姓）");
    ConsoleUtils::printMenuOption(static_cast<int>(MainMenuOption::CHINESE_COMPOUND), "生成中文名（复姓）");
    ConsoleUtils::printMenuOption(static_cast<int>(MainMenuOption::ENGLISH_NAME), "生成英文名");
    ConsoleUtils::printMenuOption(static_cast<int>(MainMenuOption::JAPANESE_NAME), "生成日文名");
    ConsoleUtils::printMenuOption(static_cast<int>(MainMenuOption::ALL_STYLES), "生成全部风格");
    ConsoleUtils::println("");
    ConsoleUtils::printMenuOption(static_cast<int>(MainMenuOption::EXIT), "退出程序");
    ConsoleUtils::printLine('-');
}

void displayGenderMenu(const std::string& surnameType) {
    ConsoleUtils::clearScreen();
    ConsoleUtils::printHeader("选择性别 - " + surnameType);
    ConsoleUtils::println("");
    ConsoleUtils::println("请选择性别:");
    ConsoleUtils::printMenuOption(static_cast<int>(GenderMenuOption::MALE), "男性");
    ConsoleUtils::printMenuOption(static_cast<int>(GenderMenuOption::FEMALE), "女性");
    ConsoleUtils::printMenuOption(static_cast<int>(GenderMenuOption::MIXED), "混合（随机）");
    ConsoleUtils::println("");
    ConsoleUtils::printMenuOption(static_cast<int>(GenderMenuOption::BACK), "返回上一级");
    ConsoleUtils::printLine('-');
}

void displayLengthMenu(const std::string& surnameType, const std::string& gender) {
    ConsoleUtils::clearScreen();
    ConsoleUtils::printHeader("选择名字长度 - " + surnameType + " - " + gender);
    ConsoleUtils::println("");
    ConsoleUtils::println("请选择名字长度:");
    ConsoleUtils::printMenuOption(static_cast<int>(LengthMenuOption::SINGLE), "单字名");
    ConsoleUtils::printMenuOption(static_cast<int>(LengthMenuOption::DOUBLE), "双字名");
    ConsoleUtils::printMenuOption(static_cast<int>(LengthMenuOption::MIXED), "混合（随机）");
    ConsoleUtils::println("");
    ConsoleUtils::printMenuOption(static_cast<int>(LengthMenuOption::BACK), "返回上一级");
    ConsoleUtils::printLine('-');
}

void displayCountMenu(const std::string& description) {
    ConsoleUtils::clearScreen();
    ConsoleUtils::printHeader("设置生成数量 - " + description);
    ConsoleUtils::println("");
    ConsoleUtils::printLine('-');
}

void generateNonChineseNames(MainMenuOption option) {
    ConsoleUtils::clearScreen();
    
    std::unique_ptr<NameGenerator> generator;
    std::string styleName;
    
    switch (option) {
        case MainMenuOption::ENGLISH_NAME:
            generator = std::make_unique<EnglishNameGenerator>();
            styleName = "英文名";
            break;
        case MainMenuOption::JAPANESE_NAME:
            generator = std::make_unique<JapaneseNameGenerator>();
            styleName = "日文名";
            break;
        default:
            ConsoleUtils::printError("无效的选项");
            ConsoleUtils::pause();
            return;
    }
    
    ConsoleUtils::printHeader("生成" + styleName);
    int count = ConsoleUtils::getIntInput("请输入要生成的姓名数量 (1-10): ", 1, 10);
    ConsoleUtils::println("");
    
    generator->generateMultiple(count);
    
    ConsoleUtils::println("");
    ConsoleUtils::pause();
}

void generateAllStyles() {
    ConsoleUtils::clearScreen();
    
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
    
    ConsoleUtils::println("");
    ConsoleUtils::pause();
}

std::string getSurnameTypeString(SurnameType type) {
    switch (type) {
        case SurnameType::Single:
            return "单姓";
        case SurnameType::Compound:
            return "复姓";
        default:
            return "混合";
    }
}

std::string getGenderString(Gender gender) {
    switch (gender) {
        case Gender::Male:
            return "男性";
        case Gender::Female:
            return "女性";
        default:
            return "混合";
    }
}

std::string getNameLengthString(NameLength length) {
    switch (length) {
        case NameLength::Single:
            return "单字名";
        case NameLength::Double:
            return "双字名";
        default:
            return "混合";
    }
}

void runChineseNameFlow(SurnameType surnameType) {
    ChineseNameGenerator generator;
    ChineseNameConfig config;
    config.surnameType = surnameType;
    
    std::string surnameTypeStr = getSurnameTypeString(surnameType);
    
    MenuLevel currentLevel = MenuLevel::Gender;
    
    while (currentLevel != MenuLevel::Main) {
        switch (currentLevel) {
            case MenuLevel::Gender: {
                displayGenderMenu(surnameTypeStr);
                int input = ConsoleUtils::getIntInput("请输入选项 (0-3): ", 0, 3);
                GenderMenuOption genderOption = static_cast<GenderMenuOption>(input);
                
                if (genderOption == GenderMenuOption::BACK) {
                    currentLevel = MenuLevel::Main;
                } else {
                    switch (genderOption) {
                        case GenderMenuOption::MALE:
                            config.gender = Gender::Male;
                            break;
                        case GenderMenuOption::FEMALE:
                            config.gender = Gender::Female;
                            break;
                        case GenderMenuOption::MIXED:
                            config.gender = Gender::Mixed;
                            break;
                        default:
                            break;
                    }
                    currentLevel = MenuLevel::NameLength;
                }
                break;
            }
            
            case MenuLevel::NameLength: {
                displayLengthMenu(surnameTypeStr, getGenderString(config.gender));
                int input = ConsoleUtils::getIntInput("请输入选项 (0-3): ", 0, 3);
                LengthMenuOption lengthOption = static_cast<LengthMenuOption>(input);
                
                if (lengthOption == LengthMenuOption::BACK) {
                    currentLevel = MenuLevel::Gender;
                } else {
                    switch (lengthOption) {
                        case LengthMenuOption::SINGLE:
                            config.nameLength = NameLength::Single;
                            break;
                        case LengthMenuOption::DOUBLE:
                            config.nameLength = NameLength::Double;
                            break;
                        case LengthMenuOption::MIXED:
                            config.nameLength = NameLength::Mixed;
                            break;
                        default:
                            break;
                    }
                    currentLevel = MenuLevel::Count;
                }
                break;
            }
            
            case MenuLevel::Count: {
                std::string desc = surnameTypeStr + " - " + getGenderString(config.gender) + " - " + getNameLengthString(config.nameLength);
                displayCountMenu(desc);
                int count = ConsoleUtils::getIntInput("请输入要生成的姓名数量 (1-10): ", 1, 10);
                config.count = count;
                
                ConsoleUtils::println("");
                generator.generateMultipleWithConfig(config);
                ConsoleUtils::println("");
                ConsoleUtils::pause();
                
                currentLevel = MenuLevel::NameLength;
                break;
            }
            
            default:
                currentLevel = MenuLevel::Main;
                break;
        }
    }
}

int main() {
    ConsoleUtils::init();
    
    Random::instance();
    
    MainMenuOption mainChoice;
    
    do {
        displayMainMenu();
        int input = ConsoleUtils::getIntInput("请输入选项 (0-5): ", 0, 5);
        mainChoice = static_cast<MainMenuOption>(input);
        
        switch (mainChoice) {
            case MainMenuOption::CHINESE_SINGLE:
                runChineseNameFlow(SurnameType::Single);
                break;
                
            case MainMenuOption::CHINESE_COMPOUND:
                runChineseNameFlow(SurnameType::Compound);
                break;
                
            case MainMenuOption::ENGLISH_NAME:
            case MainMenuOption::JAPANESE_NAME:
                generateNonChineseNames(mainChoice);
                break;
                
            case MainMenuOption::ALL_STYLES:
                generateAllStyles();
                break;
                
            case MainMenuOption::EXIT:
                ConsoleUtils::printInfo("感谢使用，再见！");
                break;
                
            default:
                ConsoleUtils::printError("无效选项，请重新选择");
                ConsoleUtils::pause();
                break;
        }
        
    } while (mainChoice != MainMenuOption::EXIT);
    
    ConsoleUtils::cleanup();
    return 0;
}
