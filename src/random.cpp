#include "random.h"


double RandomNumbers::uniform_double(double lower, double upper) {
    std::uniform_real_distribution<double> distr(lower,upper);
    return distr(rng);
}

void RandomNumbers:: uniform_double(std::vector<double>& tab, double lower, double upper) {
    for(size_t i(0); i < tab.size(); ++i) {
        tab[i] = uniform_double(lower,upper);
    }
}

double RandomNumbers::normal(double mean, double sd) {
    std::normal_distribution<double> distr(mean,sd);
    return distr(rng);
}

void RandomNumbers:: normal(std::vector<double>& tab, double mean, double sd) {
    for(size_t i(0); i < tab.size(); ++i) {
        tab[i] = normal(mean,sd);
    }
}

int RandomNumbers::poisson(double mean) {
    std::poisson_distribution<> poisson(mean);
    return poisson(rng);
}

void RandomNumbers::poisson(std::vector<int>&tab, double mean) {
    for(size_t i(0); i < tab.size(); ++i) {
        tab[i] = poisson(mean);
    }
}

RandomNumbers::RandomNumbers(unsigned long s) {
    if (s==0){
        std::random_device rd;
        seed = rd();
    } else {
        seed = s;
    }
    rng = std::mt19937(seed);
}

