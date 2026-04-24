#include "generators/ChineseNameGenerator.h"
#include "utils/Random.h"

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

const std::vector<std::string> ChineseNameGenerator::m_givenNameChars = {
    "伟", "芳", "娜", "秀英", "敏", "静", "丽", "强", "磊", "军",
    "洋", "勇", "艳", "杰", "娟", "涛", "明", "超", "秀兰", "霞",
    "平", "刚", "桂英", "文", "华", "玲", "辉", "鑫", "斌", "波",
    "宇", "浩", "凯", "健", "俊", "帅", "晨", "博", "豪", "杰",
    "涵", "默", "思", "远", "航", "天", "然", "安", "宁", "乐",
    "欣", "怡", "佳", "悦", "妍", "茜", "琳", "璐", "瑶", "婷",
    "雪", "冰", "清", "洁", "晨", "曦", "睿", "智", "颖", "慧",
    "云", "岚", "雨", "虹", "霞", "月", "星", "辰", "阳", "光",
    "德", "仁", "义", "礼", "智", "信", "善", "良", "诚", "实",
    "志", "恒", "毅", "坚", "勇", "敢", "正", "直", "公", "平"
};

ChineseNameGenerator::ChineseNameGenerator() {
}

std::string ChineseNameGenerator::generateSurname() const {
    Utils::Random& random = Utils::Random::instance();
    
    if (random.nextDouble() < 0.2) {
        return random.choice(m_compoundSurnames);
    } else {
        return random.choice(m_singleSurnames);
    }
}

std::string ChineseNameGenerator::generateGivenName(int length) const {
    Utils::Random& random = Utils::Random::instance();
    std::string givenName;
    
    for (int i = 0; i < length; ++i) {
        givenName += random.choice(m_givenNameChars);
    }
    
    return givenName;
}

std::string ChineseNameGenerator::generate() const {
    std::string surname = generateSurname();
    
    Utils::Random& random = Utils::Random::instance();
    const int minGivenLength = 1;
    const int maxGivenLength = 2;
    int givenNameLength = random.nextInt(minGivenLength, maxGivenLength);
    
    std::string givenName = generateGivenName(givenNameLength);
    
    return surname + givenName;
}

std::string ChineseNameGenerator::getStyleName() const {
    return "中文名";
}

} // namespace Generators
} // namespace NameGen
