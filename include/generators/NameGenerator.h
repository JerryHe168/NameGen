#ifndef NAMEGENERATOR_H
#define NAMEGENERATOR_H

#include <string>

namespace NameGen {
namespace Generators {

class NameGenerator {
public:
    virtual ~NameGenerator() = default;
    
    virtual std::string generate() const = 0;
    virtual std::string getStyleName() const = 0;
    
    virtual int generateMultiple(int count) const;
};

} // namespace Generators
} // namespace NameGen

#endif // NAMEGENERATOR_H
