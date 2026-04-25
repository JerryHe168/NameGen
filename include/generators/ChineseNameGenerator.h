#ifndef CHINESENAMEGENERATOR_H
#define CHINESENAMEGENERATOR_H

#include "NameGenerator.h"
#include "config/NameGenConfig.h"
#include <vector>
#include <string>

namespace NameGen {
namespace Generators {

class ChineseNameGenerator : public NameGenerator {
public:
    ChineseNameGenerator();
    explicit ChineseNameGenerator(const Config::ChineseNameConfig& config);
    
    std::string generate() const override;
    std::string getStyleName() const override;
    
    std::string generateWithConfig(const Config::ChineseNameConfig& config) const;
    int generateMultipleWithConfig(const Config::ChineseNameConfig& config) const;
    
    void setConfig(const Config::ChineseNameConfig& config);
    Config::ChineseNameConfig getConfig() const;

private:
    static const std::vector<std::string> m_singleSurnames;
    static const std::vector<std::string> m_compoundSurnames;
    static const std::vector<std::string> m_maleGivenNameChars;
    static const std::vector<std::string> m_femaleGivenNameChars;
    static const std::vector<std::string> m_neutralGivenNameChars;
    
    Config::ChineseNameConfig m_config;
    
    std::string generateSurname(Config::SurnameType type) const;
    std::string generateGivenName(Config::Gender gender, Config::NameLength length) const;
    const std::vector<std::string>& getGivenNameChars(Config::Gender gender) const;
    int getGivenNameLength(Config::NameLength length) const;
};

} // namespace Generators
} // namespace NameGen

#endif // CHINESENAMEGENERATOR_H
