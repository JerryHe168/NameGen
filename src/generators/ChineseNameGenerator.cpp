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

const std::vector<std::string> ChineseNameGenerator::m_maleGivenNameChars = {
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

const std::vector<std::string> ChineseNameGenerator::m_femaleGivenNameChars = {
    "芳", "娜", "秀英", "敏", "静", "丽", "秀兰", "霞", "桂英", "艳",
    "娟", "玲", "欣", "怡", "佳", "悦", "妍", "茜", "琳", "璐",
    "瑶", "婷", "雪", "冰", "清", "洁", "安", "宁", "乐", "晨",
    "曦", "睿", "颖", "慧", "云", "岚", "雨", "虹", "霞", "月",
    "星", "辰", "花", "草", "兰", "梅", "菊", "荷", "莲", "蓉",
    "桂", "桃", "杏", "梨", "樱", "枫", "柏", "柳", "杨", "桐",
    "凤", "凰", "燕", "莺", "蝶", "蜂", "雀", "鹅", "鸳鸯", "仙鹤",
    "玉", "珠", "宝", "贝", "金", "银", "钻", "翠", "琼", "瑶",
    "琴", "棋", "书", "画", "诗", "词", "歌", "赋", "韵", "律",
    "梦", "幻", "仙", "灵", "神", "奇", "妙", "美", "好", "甜"
};

const std::vector<std::string> ChineseNameGenerator::m_neutralGivenNameChars = {
    "文", "华", "明", "亮", "光", "辉", "耀", "灿", "烂", "晨",
    "曦", "晓", "阳", "月", "星", "辰", "天", "地", "人", "和",
    "安", "宁", "平", "静", "顺", "畅", "通", "达", "远", "近",
    "高", "低", "上", "下", "中", "正", "直", "公", "平", "公",
    "道", "德", "仁", "义", "礼", "智", "信", "善", "良", "诚",
    "实", "真", "假", "虚", "实", "空", "满", "盈", "亏", "损",
    "益", "增", "减", "多", "少", "大", "小", "长", "短", "宽",
    "窄", "厚", "薄", "深", "浅", "新", "旧", "老", "幼", "生",
    "死", "存", "亡", "兴", "衰", "盛", "败", "成", "败", "得",
    "失", "取", "舍", "进", "退", "升", "降", "出", "入", "来",
    "去", "起", "伏", "动", "静", "开", "关", "启", "闭", "始",
    "终", "结", "束", "开", "始", "结", "束", "源", "流", "根",
    "本", "枝", "叶", "花", "果", "实", "种", "子", "苗", "芽"
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

const std::vector<std::string>& ChineseNameGenerator::getGivenNameChars(Config::Gender gender) const {
    switch (gender) {
        case Config::Gender::Male:
            return m_maleGivenNameChars;
        case Config::Gender::Female:
            return m_femaleGivenNameChars;
        case Config::Gender::Mixed:
        default:
            return m_neutralGivenNameChars;
    }
}

int ChineseNameGenerator::getGivenNameLength(Config::NameLength length) const {
    Utils::Random& random = Utils::Random::instance();
    
    switch (length) {
        case Config::NameLength::Single:
            return 1;
        case Config::NameLength::Double:
            return 2;
        case Config::NameLength::Mixed:
        default:
            return random.nextInt(1, 2);
    }
}

std::string ChineseNameGenerator::generateGivenName(Config::Gender gender, Config::NameLength length) const {
    Utils::Random& random = Utils::Random::instance();
    std::string givenName;
    
    const std::vector<std::string>* chars;
    Config::Gender actualGender = gender;
    
    if (gender == Config::Gender::Mixed) {
        actualGender = random.nextDouble() < 0.5 ? Config::Gender::Male : Config::Gender::Female;
    }
    
    chars = &getGivenNameChars(actualGender);
    int len = getGivenNameLength(length);
    
    for (int i = 0; i < len; ++i) {
        givenName += random.choice(*chars);
    }
    
    return givenName;
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
