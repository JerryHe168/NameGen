#ifndef RANDOM_H
#define RANDOM_H

#include <random>
#include <chrono>
#include <stdexcept>
#include <vector>

namespace NameGen {
namespace Utils {

class Random {
public:
    Random();
    explicit Random(unsigned int seed);
    
    int nextInt(int min, int max);
    int nextInt(int max);
    
    double nextDouble();
    double nextDouble(double min, double max);
    
    template<typename T>
    const T& choice(const std::vector<T>& items);
    
    static Random& instance();
    
private:
    std::mt19937 m_generator;
};

template<typename T>
const T& Random::choice(const std::vector<T>& items) {
    if (items.empty()) {
        throw std::runtime_error("Cannot choose from empty vector");
    }
    int index = nextInt(static_cast<int>(items.size()) - 1);
    return items[index];
}

} // namespace Utils
} // namespace NameGen

#endif // RANDOM_H
