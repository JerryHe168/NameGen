#ifndef CHINESENAMEGENERATOR_H
#define CHINESENAMEGENERATOR_H

#include "NameGenerator.h"
#include <vector>

namespace NameGen {
namespace Generators {

class ChineseNameGenerator : public NameGenerator {
public:
    ChineseNameGenerator();
    
    std::string generate() const override;
    std::string getStyleName() const override;

private:
    static const std::vector<std::string> m_singleSurnames;
    static const std::vector<std::string> m_compoundSurnames;
    static const std::vector<std::string> m_givenNameChars;
    
    std::string generateSurname() const;
    std::string generateGivenName(int length) const;
};

} // namespace Generators
} // namespace NameGen

#endif // CHINESENAMEGENERATOR_H
