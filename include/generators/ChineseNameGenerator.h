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
    
    static const std::vector<std::string> m_maleSingleChars;
    static const std::vector<std::string> m_maleDoubleNames;
    static const std::vector<std::string> m_femaleSingleChars;
    static const std::vector<std::string> m_femaleDoubleNames;
    static const std::vector<std::string> m_neutralSingleChars;
    static const std::vector<std::string> m_neutralDoubleNames;
    
    Config::ChineseNameConfig m_config;
    
    std::string generateSurname(Config::SurnameType type) const;
    std::string generateGivenName(Config::Gender gender, Config::NameLength length) const;
    
    const std::vector<std::string>& getSingleChars(Config::Gender gender) const;
    const std::vector<std::string>& getDoubleNames(Config::Gender gender) const;
    
    std::string generateSingleCharName(Config::Gender gender) const;
    std::string generateDoubleCharName(Config::Gender gender) const;
};

} // namespace Generators
} // namespace NameGen

#endif // CHINESENAMEGENERATOR_H
