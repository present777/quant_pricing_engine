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

    PayoffCall payoff_call(100.0);
    VanillaOption call_option(1.0, payoff_call);

    double bs_call = blackscholesPrice(call_option, market);
    double mc_call = MonteCarloPrice(call_option, market, 100000);
    double bt_call = BinomialTreePrice(call_option, market, 1000);

    double mc_call_error = std::abs(mc_call - bs_call);
    double bt_call_error = std::abs(bt_call - bs_call);

    std::cout << "========== Call Option Tests ==========\n";
    std::cout << "Benchmark (BS Price): " << bs_call << "\n";
    if (mc_call_error < 0.1) {
        std::cout << "[PASS] Monte Carlo converges. Error: " << mc_call_error << "\n";
    } else {
        std::cout << "[FAIL] Monte Carlo error too large: " << mc_call_error << "\n";
    }
    if (bt_call_error < 0.05) {
        std::cout << "[PASS] Binomial Tree converges. Error: " << bt_call_error << "\n";
    } else {
        std::cout << "[FAIL] Binomial Tree error too large: " << bt_call_error << "\n";
    }
    std::cout << "\n";

    PayoffPut payoff_put(100.0);
    VanillaOption put_option(1.0, payoff_put);

    double bs_put = blackscholesPrice(put_option, market);
    double mc_put = MonteCarloPrice(put_option, market, 100000);
    double bt_put = BinomialTreePrice(put_option, market, 1000);

    double mc_put_error = std::abs(mc_put - bs_put);
    double bt_put_error = std::abs(bt_put - bs_put);

    std::cout << "========== Put Option Tests ==========\n";
    std::cout << "Benchmark (BS Price): " << bs_put << "\n";
    if (mc_put_error < 0.1) {
        std::cout << "[PASS] Monte Carlo converges. Error: " << mc_put_error << "\n";
    } else {
        std::cout << "[FAIL] Monte Carlo error too large: " << mc_put_error << "\n";
    }
    if (bt_put_error < 0.05) {
        std::cout << "[PASS] Binomial Tree converges. Error: " << bt_put_error << "\n";
    } else {
        std::cout << "[FAIL] Binomial Tree error too large: " << bt_put_error << "\n";
    }
    std::cout << "=======================================\n";
}

int main() {
    std::cout << "Starting comprehensive pricing engine tests...\n\n";
    try {
        run_convergence_tests();
    } catch (const std::exception& e) {
        std::cerr << "Test failed with exception: " << e.what() << "\n";
        return 1;
    }
    return 0;
}