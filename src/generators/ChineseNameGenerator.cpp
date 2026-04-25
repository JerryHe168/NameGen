#include "generators/ChineseNameGenerator.h"
#include "utils/Random.h"
#include "utils/ConsoleUtils.h"

namespace NameGen {
namespace Generators {

const std::vector<std::string> ChineseNameGenerator::m_singleSurnames = {
    "王", "李", "张", "刘", "陈", "杨", "赵", "黄", "周", "吴",
    "徐", "孙", "胡", "朱", "高", "林", "何", "郭", "马", "罗",
    "梁", "宋", "郑", "谢", "韩", "唐", "冯", "于", "董", "萧",
    "程", "曹", "袁", "邓", "许", "傅", "沈", "曾", "彭", "吕",
    "苏", "卢", "蒋", "蔡", "贾", "丁", "魏", "薛", "叶", "阎",
    "余", "潘", "杜", "戴", "夏", "钟", "汪", "田", "任", "姜",
    "范", "方", "石", "姚", "谭", "廖", "邹", "熊", "金", "陆",
    "郝", "孔", "白", "崔", "康", "毛", "邱", "秦", "江", "史",
    "顾", "侯", "邵", "孟", "龙", "万", "段", "雷", "钱", "汤",
    "尹", "黎", "易", "常", "武", "乔", "贺", "赖", "龚", "文"
};

const std::vector<std::string> ChineseNameGenerator::m_compoundSurnames = {
    "欧阳", "太史", "端木", "上官", "司马", "东方", "独孤", "南宫",
    "万俟", "闻人", "夏侯", "诸葛", "尉迟", "公羊", "赫连", "澹台",
    "皇甫", "宗政", "濮阳", "公冶", "太叔", "申屠", "公孙", "仲孙",
    "轩辕", "令狐", "钟离", "宇文", "长孙", "慕容", "鲜于", "闾丘",
    "司徒", "司空", "亓官", "司寇", "仉督", "子车", "颛孙", "端木",
    "巫马", "公西", "漆雕", "乐正", "壤驷", "公良", "拓跋", "夹谷",
    "宰父", "谷梁", "晋楚", "闫法", "汝鄢", "涂钦", "段干", "百里",
    "东郭", "南门", "呼延", "归海", "羊舌", "微生", "岳帅", "缑亢",
    "况后", "有琴", "梁丘", "左丘", "东门", "西门", "商牟", "佘佴",
    "伯赏", "南宫", "墨哈", "谯笪", "年爱", "阳佟", "第五", "言福"
};

const std::vector<std::string> ChineseNameGenerator::m_maleSingleChars = {
    "伟", "强", "磊", "军", "洋", "勇", "杰", "涛", "明", "超",
    "平", "刚", "文", "华", "辉", "鑫", "斌", "波", "宇", "浩",
    "凯", "健", "俊", "帅", "晨", "博", "豪", "杰", "涵", "默",
    "思", "远", "航", "天", "然", "安", "宁", "乐", "晨", "曦",
    "睿", "智", "云", "岚", "雨", "虹", "月", "星", "辰", "阳",
    "光", "德", "仁", "义", "礼", "智", "信", "善", "良", "诚",
    "实", "志", "恒", "毅", "坚", "勇", "敢", "正", "直", "公",
    "平", "峰", "山", "河", "海", "川", "林", "木", "森", "石",
    "铁", "钢", "铜", "金", "银", "玉", "瑞", "祥", "福", "禄",
    "寿", "喜", "财", "运", "龙", "虎", "豹", "狮", "鹏", "鹰"
};

const std::vector<std::string> ChineseNameGenerator::m_maleDoubleNames = {
    "伟强", "志刚", "建国", "建军", "建华", "建平", "小明", "大明",
    "文华", "志强", "志明", "志远", "志豪", "志文", "志武", "志勇",
    "俊杰", "俊豪", "俊凯", "俊伟", "俊明", "俊峰", "俊龙", "俊鹏",
    "浩然", "浩宇", "浩轩", "浩文", "浩明", "浩瀚", "浩洋", "浩泽",
    "天宇", "天翔", "天浩", "天杰", "天磊", "天阳", "天明", "天睿",
    "文博", "文浩", "文轩", "文杰", "文磊", "文涛", "文强", "文军",
    "梓轩", "梓浩", "梓杰", "梓豪", "梓睿", "梓阳", "梓明", "梓涛",
    "子轩", "子浩", "子杰", "子豪", "子睿", "子阳", "子明", "子涛",
    "宇航", "宇轩", "宇杰", "宇豪", "宇睿", "宇阳", "宇明", "宇涛",
    "浩杰", "浩豪", "浩睿", "浩阳", "伟明", "伟杰", "伟涛", "伟军"
};

const std::vector<std::string> ChineseNameGenerator::m_femaleSingleChars = {
    "芳", "娜", "秀", "英", "敏", "静", "丽", "兰", "霞", "桂",
    "艳", "娟", "玲", "欣", "怡", "佳", "悦", "妍", "茜", "琳",
    "璐", "瑶", "婷", "雪", "冰", "清", "洁", "安", "宁", "乐",
    "晨", "曦", "睿", "颖", "慧", "云", "岚", "雨", "虹", "月",
    "星", "辰", "花", "草", "梅", "菊", "荷", "莲", "蓉", "桃",
    "杏", "梨", "樱", "枫", "柏", "柳", "杨", "桐", "凤", "凰",
    "燕", "莺", "蝶", "蜂", "雀", "鹅", "鸳", "鸯", "仙", "鹤",
    "玉", "珠", "宝", "贝", "金", "银", "翠", "琼", "琴", "棋",
    "书", "画", "诗", "词", "歌", "赋", "韵", "律", "梦", "幻",
    "灵", "神", "奇", "妙", "美", "好", "甜", "香", "纯", "柔"
};

const std::vector<std::string> ChineseNameGenerator::m_femaleDoubleNames = {
    "秀英", "秀兰", "桂英", "小芳", "小红", "小丽", "小美", "小花",
    "美丽", "美玲", "美凤", "美兰", "美华", "美娟", "美娜", "美婷",
    "秀丽", "秀娟", "秀娜", "秀婷", "秀芳", "秀华", "秀玲", "秀敏",
    "桂兰", "桂华", "桂娟", "桂娜", "桂婷", "桂芳", "桂玲", "桂敏",
    "梦琪", "梦萱", "梦洁", "梦瑶", "梦婷", "梦娜", "梦娟", "梦华",
    "思琪", "思萱", "思洁", "思瑶", "思婷", "思娜", "思娟", "思华",
    "雨琪", "雨萱", "雨洁", "雨瑶", "雨婷", "雨娜", "雨娟", "雨华",
    "雪琪", "雪萱", "雪洁", "雪瑶", "雪婷", "雪娜", "雪娟", "雪华",
    "欣怡", "欣然", "欣悦", "欣妍", "欣琳", "欣瑶", "欣婷", "欣娜",
    "雅琪", "雅萱", "雅洁", "雅瑶", "雅婷", "雅娜", "雅娟", "雅华"
};

const std::vector<std::string> ChineseNameGenerator::m_neutralSingleChars = {
    "文", "华", "明", "亮", "光", "辉", "耀", "灿", "烂", "晨",
    "曦", "晓", "阳", "月", "星", "辰", "天", "地", "人", "和",
    "安", "宁", "平", "静", "顺", "畅", "通", "达", "远", "近",
    "高", "低", "上", "下", "中", "正", "直", "公", "平", "公",
    "道", "德", "仁", "义", "礼", "智", "信", "善", "良", "诚",
    "实", "真", "假", "虚", "实", "空", "满", "盈", "亏", "损",
    "益", "增", "减", "多", "少", "大", "小", "长", "短", "宽",
    "窄", "厚", "薄", "深", "浅", "新", "旧", "老", "幼", "生",
    "死", "存", "亡", "兴", "衰", "盛", "败", "成", "败", "得",
    "失", "取", "舍", "进", "退", "升", "降", "出", "入", "来"
};

const std::vector<std::string> ChineseNameGenerator::m_neutralDoubleNames = {
    "文华", "文辉", "文明", "文亮", "文光", "文灿", "文晨", "文晓",
    "华文", "辉文", "明文", "亮文", "光文", "灿文", "晨文", "晓文",
    "光华", "光辉", "光明", "光亮", "光灿", "光晨", "光晓", "光阳",
    "辉华", "辉光", "辉明", "辉亮", "辉灿", "辉晨", "辉晓", "辉阳",
    "明华", "明光", "明辉", "明亮", "明灿", "明晨", "明晓", "明阳",
    "亮华", "亮光", "亮辉", "亮明", "亮灿", "亮晨", "亮晓", "亮阳",
    "晨华", "晨光", "晨辉", "晨明", "晨亮", "晨灿", "晨阳", "晨月",
    "晓华", "晓光", "晓辉", "晓明", "晓亮", "晓灿", "晓阳", "晓月",
    "安华", "安光", "安辉", "安明", "安亮", "安晨", "安晓", "安阳",
    "宁华", "宁光", "宁辉", "宁明", "宁亮", "宁晨", "宁晓", "宁阳"
};

ChineseNameGenerator::ChineseNameGenerator() {
}

ChineseNameGenerator::ChineseNameGenerator(const Config::ChineseNameConfig& config)
    : m_config(config) {
}

std::string ChineseNameGenerator::generateSurname(Config::SurnameType type) const {
    Utils::Random& random = Utils::Random::instance();
    
    switch (type) {
        case Config::SurnameType::Single:
            return random.choice(m_singleSurnames);
        case Config::SurnameType::Compound:
            return random.choice(m_compoundSurnames);
        case Config::SurnameType::Mixed:
        default:
            if (random.nextDouble() < 0.2) {
                return random.choice(m_compoundSurnames);
            } else {
                return random.choice(m_singleSurnames);
            }
    }
}

const std::vector<std::string>& ChineseNameGenerator::getSingleChars(Config::Gender gender) const {
    switch (gender) {
        case Config::Gender::Male:
            return m_maleSingleChars;
        case Config::Gender::Female:
            return m_femaleSingleChars;
        case Config::Gender::Mixed:
        default:
            return m_neutralSingleChars;
    }
}

const std::vector<std::string>& ChineseNameGenerator::getDoubleNames(Config::Gender gender) const {
    switch (gender) {
        case Config::Gender::Male:
            return m_maleDoubleNames;
        case Config::Gender::Female:
            return m_femaleDoubleNames;
        case Config::Gender::Mixed:
        default:
            return m_neutralDoubleNames;
    }
}

std::string ChineseNameGenerator::generateSingleCharName(Config::Gender gender) const {
    Utils::Random& random = Utils::Random::instance();
    
    Config::Gender actualGender = gender;
    if (gender == Config::Gender::Mixed) {
        actualGender = random.nextDouble() < 0.5 ? Config::Gender::Male : Config::Gender::Female;
    }
    
    const std::vector<std::string>& singleChars = getSingleChars(actualGender);
    return random.choice(singleChars);
}

std::string ChineseNameGenerator::generateDoubleCharName(Config::Gender gender) const {
    Utils::Random& random = Utils::Random::instance();
    
    Config::Gender actualGender = gender;
    if (gender == Config::Gender::Mixed) {
        actualGender = random.nextDouble() < 0.5 ? Config::Gender::Male : Config::Gender::Female;
    }
    
    const std::vector<std::string>& singleChars = getSingleChars(actualGender);
    const std::vector<std::string>& doubleNames = getDoubleNames(actualGender);
    
    if (random.nextDouble() < 0.5 && !doubleNames.empty()) {
        return random.choice(doubleNames);
    } else {
        std::string name;
        name += random.choice(singleChars);
        name += random.choice(singleChars);
        return name;
    }
}

std::string ChineseNameGenerator::generateGivenName(Config::Gender gender, Config::NameLength length) const {
    Utils::Random& random = Utils::Random::instance();
    
    Config::NameLength actualLength = length;
    if (length == Config::NameLength::Mixed) {
        actualLength = random.nextDouble() < 0.5 ? Config::NameLength::Single : Config::NameLength::Double;
    }
    
    switch (actualLength) {
        case Config::NameLength::Single:
            return generateSingleCharName(gender);
        case Config::NameLength::Double:
        case Config::NameLength::Mixed:
        default:
            return generateDoubleCharName(gender);
    }
}

std::string ChineseNameGenerator::generateWithConfig(const Config::ChineseNameConfig& config) const {
    std::string surname = generateSurname(config.surnameType);
    std::string givenName = generateGivenName(config.gender, config.nameLength);
    return surname + givenName;
}

int ChineseNameGenerator::generateMultipleWithConfig(const Config::ChineseNameConfig& config) const {
    if (config.count <= 0) {
        Utils::ConsoleUtils::printError("生成数量必须大于0");
        return 0;
    }
    
    Utils::ConsoleUtils::printInfo("生成 " + std::to_string(config.count) + " 个" + config.getDescription() + ":");
    Utils::ConsoleUtils::printLine('-');
    
    int successCount = 0;
    for (int i = 0; i < config.count; ++i) {
        try {
            std::string name = generateWithConfig(config);
            Utils::ConsoleUtils::println("  " + std::to_string(i + 1) + ". " + name);
            ++successCount;
        } catch (const std::exception& e) {
            Utils::ConsoleUtils::printError("生成第 " + std::to_string(i + 1) + " 个姓名时出错: " + std::string(e.what()));
        }
    }
    
    Utils::ConsoleUtils::printLine('-');
    return successCount;
}

std::string ChineseNameGenerator::generate() const {
    return generateWithConfig(m_config);
}

std::string ChineseNameGenerator::getStyleName() const {
    return "中文名";
}

void ChineseNameGenerator::setConfig(const Config::ChineseNameConfig& config) {
    m_config = config;
}

Config::ChineseNameConfig ChineseNameGenerator::getConfig() const {
    return m_config;
}

} // namespace Generators
} // namespace NameGen
