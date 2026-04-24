#ifndef JAPANESENAMEGENERATOR_H
#define JAPANESENAMEGENERATOR_H

#include "NameGenerator.h"
#include <vector>

namespace NameGen {
namespace Generators {

class JapaneseNameGenerator : public NameGenerator {
public:
    JapaneseNameGenerator();
    
    std::string generate() const override;
    std::string getStyleName() const override;
    
    int generateMultiple(int count) const override;

private:
    static const std::vector<std::string> m_surnames;
    static const std::vector<std::string> m_maleGivenNames;
    static const std::vector<std::string> m_femaleGivenNames;
    
    std::string generateSurname() const;
    std::string generateGivenName() const;
};

} // namespace Generators
} // namespace NameGen

#endif // JAPANESENAMEGENERATOR_H
