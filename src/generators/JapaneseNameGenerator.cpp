#include "generators/JapaneseNameGenerator.h"
#include "utils/Random.h"

namespace NameGen {
namespace Generators {

const std::vector<std::string> JapaneseNameGenerator::m_surnames = {
    "佐藤", "铃木", "高桥", "田中", "渡边", "伊藤", "山本", "中村",
    "小林", "加藤", "吉田", "山田", "佐佐木", "山口", "松本", "井上",
    "木村", "林", "清水", "山下", "石川", "中岛", "池上", "桥本",
    "小川", "山下", "石井", "长谷川", "原田", "藤田", "近藤", "大野",
    "村上", "太田", "小田", "河野", "平野", "金子", "前田", "冈田",
    "中村", "小野", "田村", "横山", "藤原", "西田", "古川", "本多",
    "森田", "内田", "秋元", "大塚", "高木", "安藤", "谷口", "大岛",
    "池田", "市川", "吉村", "杉山", "小池", "菅原", "北村", "五十岚",
    "福岛", "安田", "中川", "西野", "宫本", "内藤", "岛田", "岩崎",
    "工藤", "神谷", "椎名", "阿部", "岩田", "黑泽", "浅野", "北野",
    "坂本", "织田", "丰臣", "德川", "毛利", "武田", "上杉", "伊达",
    "真田", "石田", "竹中", "黑田", "加藤", "福岛", "片仓", "直江",
    "宇喜多", "小早川", "锅岛", "立花", "大友", "岛津", "龙造寺", "有马",
    "大久保", "小山", "酒井", "本多", "榊原", "井伊", "平岩", "鸟居",
    "大谷", "增田", "长束", "前田", "浅野", "小早川", "藤堂", "户川"
};

const std::vector<std::string> JapaneseNameGenerator::m_maleGivenNames = {
    "翔", "拓也", "健太", "大和", "悠太", "阳斗", "苍空", "悠翔",
    "莲", "陆", "斗真", "阳太", "飒太", "朝阳", "大翔", "太一",
    "悠", "拓真", "健斗", "和真", "瑛太", "海斗", "悠人", "大地",
    "大河", "太阳", "隼人", "龙太", "虎太郎", "健太郎", "勇太", "匠",
    "海", "陆斗", "阳翔", "苍太", "空", "歩梦", "勇斗", "树",
    "慎吾", "健吾", "勇吾", "悟", "哲也", "博之", "明", "亮",
    "正树", "浩树", "大树", "直树", "和树", "春树", "秋人", "冬马",
    "拓海", "航平", "海翔", "洋平", "泰平", "昌平", "隆平", "浩平",
    "健一", "浩一", "太一", "阳一", "诚一", "真一", "正一", "纯一",
    "明彦", "邦彦", "义彦", "康彦", "隆彦", "敏彦", "和彦", "春彦",
    "俊介", "祐介", "亮介", "阳介", "大介", "介", "敦", "笃",
    "毅", "刚", "武", "勇", "猛", "威", "雄", "豪"
};

const std::vector<std::string> JapaneseNameGenerator::m_femaleGivenNames = {
    "美咲", "莉子", "凛", "杏", "结菜", "葵", "七海", "彩花",
    "爱莉", "花音", "优奈", "美羽", "桜", "奈绪", "结衣", "阳菜",
    "美月", "凛花", "心", "咲良", "爱菜", "菜々", "枫", "美桜",
    "花", "琴音", "优花", "梨花", "沙耶", "彩乃", "理子", "裕子",
    "智子", "恵子", "方子", "雅子", "京子", "明子", "镜子", "久子",
    "幸子", "佳子", "文子", "尚子", "房子", "容子", "多恵子", "淑子",
    "千代子", "万纪子", "登志子", "常子", "世津子", "雪子", "春子", "秋子",
    "夏子", "冬子", "叶子", "兰子", "菊子", "梅子", "桃子", "樱子",
    "奈津子", "真由子", "裕子", "容子", "圣子", "玲子", "令子", "丽子",
    "智子", "知子", "慧子", "明子", "亮子", "晶子", "光子", "阳子",
    "美子", "良子", "芳子", "贵子", "恵子", "庆子", "敬子", "佳子",
    "由美", "裕美", "友美", "智美", "博美", "久美", "真美", "亚美",
    "爱美", "志保", "静香", "文香", "美香", "由香", "裕香", "友香",
    "麻美", "真美", "真美", "绫乃", "彩乃", "理乃", "真乃", "梦乃"
};

JapaneseNameGenerator::JapaneseNameGenerator() {
}

std::string JapaneseNameGenerator::generateSurname() const {
    Utils::Random& random = Utils::Random::instance();
    return random.choice(m_surnames);
}

std::string JapaneseNameGenerator::generateGivenName() const {
    Utils::Random& random = Utils::Random::instance();
    
    if (random.nextDouble() < 0.5) {
        return random.choice(m_maleGivenNames);
    } else {
        return random.choice(m_femaleGivenNames);
    }
}

std::string JapaneseNameGenerator::generate() const {
    std::string surname = generateSurname();
    std::string givenName = generateGivenName();
    return surname + givenName;
}

std::string JapaneseNameGenerator::getStyleName() const {
    return "日文名";
}

} // namespace Generators
} // namespace NameGen
