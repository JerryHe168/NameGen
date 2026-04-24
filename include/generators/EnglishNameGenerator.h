#ifndef ENGLISHNAMEGENERATOR_H
#define ENGLISHNAMEGENERATOR_H

#include "NameGenerator.h"
#include <vector>

namespace NameGen {
namespace Generators {

class EnglishNameGenerator : public NameGenerator {
public:
    EnglishNameGenerator();
    
    std::string generate() const override;
    std::string getStyleName() const override;

private:
    static const std::vector<std::string> m_maleFirstNames;
    static const std::vector<std::string> m_femaleFirstNames;
    static const std::vector<std::string> m_lastNames;
    
    std::string generateFirstName() const;
    std::string generateLastName() const;
};

} // namespace Generators
} // namespace NameGen

#endif // ENGLISHNAMEGENERATOR_H
