#include "generators/EnglishNameGenerator.h"
#include "utils/Random.h"

namespace NameGen {
namespace Generators {

const std::vector<std::string> EnglishNameGenerator::m_maleFirstNames = {
    "James", "John", "Robert", "Michael", "William", "David", "Richard", "Joseph",
    "Thomas", "Christopher", "Daniel", "Paul", "Mark", "Donald", "George", "Kenneth",
    "Steven", "Edward", "Brian", "Ronald", "Anthony", "Kevin", "Jason", "Matthew",
    "Gary", "Timothy", "Jose", "Larry", "Jeffrey", "Frank", "Scott", "Eric",
    "Stephen", "Andrew", "Raymond", "Gregory", "Joshua", "Jerry", "Dennis", "Walter",
    "Patrick", "Peter", "Harold", "Douglas", "Carl", "Arthur", "Ryan", "Roger",
    "Joe", "Juan", "Jack", "Albert", "Jonathan", "Justin", "Terry", "Gerald",
    "Keith", "Samuel", "Willie", "Ralph", "Lawrence", "Nicholas", "Roy", "Benjamin",
    "Bruce", "Brandon", "Adam", "Harry", "Fred", "Wayne", "Billy", "Steve",
    "Louis", "Jeremy", "Aaron", "Randy", "Howard", "Eugene", "Carlos", "Russell",
    "Bobby", "Victor", "Martin", "Ernest", "Phillip", "Todd", "Jesse", "Craig",
    "Alan", "Shawn", "Clarence", "Sean", "Philip", "Chris", "Johnny", "Earl",
    "Jimmy", "Antonio", "Danny", "Bryan", "Tony", "Luis", "Mike", "Stanley"
};

const std::vector<std::string> EnglishNameGenerator::m_femaleFirstNames = {
    "Mary", "Patricia", "Jennifer", "Linda", "Barbara", "Elizabeth", "Susan", "Jessica",
    "Sarah", "Karen", "Nancy", "Lisa", "Margaret", "Betty", "Dorothy", "Sandra",
    "Ashley", "Kimberly", "Donna", "Emily", "Michelle", "Carol", "Amanda", "Melissa",
    "Deborah", "Stephanie", "Rebecca", "Sharon", "Laura", "Cynthia", "Kathleen", "Amy",
    "Angela", "Shirley", "Brenda", "Pamela", "Nicole", "Emma", "Samantha", "Katherine",
    "Christine", "Helen", "Debra", "Rachel", "Carolyn", "Janet", "Catherine", "Heather",
    "Diane", "Julie", "Joyce", "Virginia", "Victoria", "Kelly", "Christina", "Lauren",
    "Joan", "Evelyn", "Judith", "Megan", "Cheryl", "Andrea", "Hannah", "Jacqueline",
    "Martha", "Gloria", "Teresa", "Ann", "Sara", "Madison", "Frances", "Kathryn",
    "Janice", "Julia", "Grace", "Monica", "Judy", "Abigail", "Sophia", "Rose",
    "Beverly", "Denise", "Theresa", "Tammy", "Irene", "Jane", "Lori", "Rachelle",
    "Marilyn", "Amber", "Danielle", "Brittany", "Diana", "Abby", "Fiona", "Ella",
    "Natalie", "Olivia", "Ava", "Sophie", "Chloe", "Isabella", "Mia", "Zoe"
};

const std::vector<std::string> EnglishNameGenerator::m_lastNames = {
    "Smith", "Johnson", "Williams", "Brown", "Jones", "Garcia", "Miller", "Davis",
    "Rodriguez", "Martinez", "Hernandez", "Lopez", "Gonzalez", "Wilson", "Anderson",
    "Thomas", "Taylor", "Moore", "Jackson", "Martin", "Lee", "Perez", "Thompson",
    "White", "Harris", "Sanchez", "Clark", "Ramirez", "Lewis", "Robinson", "Walker",
    "Young", "Allen", "King", "Wright", "Scott", "Torres", "Nguyen", "Hill", "Flores",
    "Green", "Adams", "Nelson", "Baker", "Hall", "Rivera", "Campbell", "Mitchell",
    "Carter", "Roberts", "Gomez", "Phillips", "Evans", "Turner", "Diaz", "Parker",
    "Cruz", "Edwards", "Collins", "Reyes", "Stewart", "Morris", "Morales", "Murphy",
    "Cook", "Rogers", "Gutierrez", "Ortiz", "Morgan", "Cooper", "Peterson", "Bailey",
    "Reed", "Kelly", "Howard", "Ramos", "Kim", "Cox", "Ward", "Richardson", "Watson",
    "Brooks", "Chavez", "Wood", "James", "Bennett", "Gray", "Mendoza", "Ruiz",
    "Hughes", "Price", "Alvarez", "Castillo", "Sanders", "Patel", "Myers", "Long",
    "Ross", "Foster", "Jimenez", "Powell", "Jenkins", "Perry", "Russell", "Sullivan"
};

EnglishNameGenerator::EnglishNameGenerator() {
}

std::string EnglishNameGenerator::generateFirstName() const {
    Utils::Random& random = Utils::Random::instance();
    
    if (random.nextDouble() < 0.5) {
        return random.choice(m_maleFirstNames);
    } else {
        return random.choice(m_femaleFirstNames);
    }
}

std::string EnglishNameGenerator::generateLastName() const {
    Utils::Random& random = Utils::Random::instance();
    return random.choice(m_lastNames);
}

std::string EnglishNameGenerator::generate() const {
    std::string firstName = generateFirstName();
    std::string lastName = generateLastName();
    return firstName + " " + lastName;
}

std::string EnglishNameGenerator::getStyleName() const {
    return "英文名";
}

int EnglishNameGenerator::generateMultiple(int count) const {
    return NameGenerator::generateMultiple(count);
}

} // namespace Generators
} // namespace NameGen
