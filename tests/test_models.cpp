#include <iostream>
#include <cmath>
#include "../include/Market.hpp"
#include "../include/Payoff.hpp"
#include "../include/VanillaOption.hpp"
#include "../include/BlackScholes.hpp"
#include "../include/MonteCarlo.hpp"
#include "../include/BinomialTree.hpp"

void run_convergence_tests() {
    Market market(100.0, 0.05, 0.2);
    PayoffCall payoff(100.0);
    VanillaOption option(1.0, payoff);

    double bs_price = blackscholesPrice(option, market);
    
    double mc_price = MonteCarloPrice(option, market, 100000);
    double tree_price = BinomialTreePrice(option, market, 1000); 

    // 计算绝对误差
    double mc_error = std::abs(mc_price - bs_price);
    double bt_error = std::abs(tree_price - bs_price);

    std::cout << "========== Convergence Tests ==========\n";
    std::cout << "Benchmark (BS Price): " << bs_price << "\n\n";

    if (mc_error < 0.1) {
        std::cout << "[PASS] Monte Carlo converges. Error: " << mc_error << "\n";
    } else {
        std::cout << "[FAIL] Monte Carlo error too large: " << mc_error << "\n";
    }

    if (bt_error < 0.05) {
        std::cout << "[PASS] Binomial Tree converges. Error: " << bt_error << "\n";
    } else {
        std::cout << "[FAIL] Binomial Tree error too large: " << bt_error << "\n";
    }
    std::cout << "=======================================\n";
}

int main() {
    std::cout << "Starting pricing engine tests...\n";
    try {
        run_convergence_tests();
    } catch (const std::exception& e) {
        std::cerr << "Test failed with exception: " << e.what() << "\n";
        return 1;
    }
    return 0;
}