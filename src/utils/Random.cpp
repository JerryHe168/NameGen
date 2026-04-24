#include "utils/Random.h"
#include <stdexcept>

namespace NameGen {
namespace Utils {

Random::Random() {
    auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    m_generator.seed(static_cast<unsigned int>(seed));
}

Random::Random(unsigned int seed) {
    m_generator.seed(seed);
}

int Random::nextInt(int min, int max) {
    if (min > max) {
        std::swap(min, max);
    }
    std::uniform_int_distribution<int> dist(min, max);
    return dist(m_generator);
}

int Random::nextInt(int max) {
    if (max < 0) {
        throw std::invalid_argument("max cannot be negative");
    }
    if (max == 0) {
        return 0;
    }
    return nextInt(0, max - 1);
}

double Random::nextDouble() {
    std::uniform_real_distribution<double> dist(0.0, 1.0);
    return dist(m_generator);
}

double Random::nextDouble(double min, double max) {
    if (min > max) {
        std::swap(min, max);
    }
    std::uniform_real_distribution<double> dist(min, max);
    return dist(m_generator);
}

Random& Random::instance() {
    static Random instance;
    return instance;
}

} // namespace Utils
} // namespace NameGen
