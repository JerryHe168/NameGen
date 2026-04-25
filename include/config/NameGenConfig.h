#ifndef NAMEGEN_CONFIG_H
#define NAMEGEN_CONFIG_H

#include <string>

namespace NameGen {
namespace Config {

enum class SurnameType {
    Single,
    Compound,
    Mixed
};

enum class Gender {
    Male,
    Female,
    Mixed
};

enum class NameLength {
    Single,
    Double,
    Mixed
};

struct ChineseNameConfig {
    SurnameType surnameType;
    Gender gender;
    NameLength nameLength;
    int count;
    
    ChineseNameConfig()
        : surnameType(SurnameType::Mixed)
        , gender(Gender::Mixed)
        , nameLength(NameLength::Mixed)
        , count(1) {
    }
    
    ChineseNameConfig(SurnameType s, Gender g, NameLength l, int c = 1)
        : surnameType(s)
        , gender(g)
        , nameLength(l)
        , count(c) {
    }
    
    std::string getDescription() const {
        std::string desc;
        
        switch (surnameType) {
            case SurnameType::Single:
                desc += "单姓";
                break;
            case SurnameType::Compound:
                desc += "复姓";
                break;
            case SurnameType::Mixed:
                desc += "混合姓氏";
                break;
        }
        
        desc += " - ";
        
        switch (gender) {
            case Gender::Male:
                desc += "男性";
                break;
            case Gender::Female:
                desc += "女性";
                break;
            case Gender::Mixed:
                desc += "混合性别";
                break;
        }
        
        desc += " - ";
        
        switch (nameLength) {
            case NameLength::Single:
                desc += "单字名";
                break;
            case NameLength::Double:
                desc += "双字名";
                break;
            case NameLength::Mixed:
                desc += "混合长度";
                break;
        }
        
        return desc;
    }
};

} // namespace Config
} // namespace NameGen

#endif // NAMEGEN_CONFIG_H
