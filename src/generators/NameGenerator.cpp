#include "generators/NameGenerator.h"
#include "utils/ConsoleUtils.h"

namespace NameGen {
namespace Generators {

int NameGenerator::generateMultiple(int count) const {
    if (count <= 0) {
        Utils::ConsoleUtils::printError("生成数量必须大于0");
        return 0;
    }
    
    Utils::ConsoleUtils::printInfo("生成 " + std::to_string(count) + " 个" + getStyleName() + ":");
    Utils::ConsoleUtils::printLine('-');
    
    int successCount = 0;
    for (int i = 0; i < count; ++i) {
        try {
            std::string name = generate();
            Utils::ConsoleUtils::println("  " + std::to_string(i + 1) + ". " + name);
            ++successCount;
        } catch (const std::exception& e) {
            Utils::ConsoleUtils::printError("生成第 " + std::to_string(i + 1) + " 个姓名时出错: " + std::string(e.what()));
        }
    }
    
    Utils::ConsoleUtils::printLine('-');
    return successCount;
}

} // namespace Generators
} // namespace NameGen
