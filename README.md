# C++ Quant Pricing Engine

A modular, object-oriented derivatives pricing library implemented in C++.

## Core Features
*   **OOP Architecture**: Decoupled financial products from pricing algorithms via a polymorphic `Payoff` base class.
*   **Market Environment**: Designed an immutable `Market` data center for thread-safe market state management.
*   **Pricing Models**: Supports Black-Scholes analytical solutions, Monte Carlo simulations, and Binomial Tree models.
*   **Greeks**: Computes core Greeks (Delta, Gamma, Vega) utilizing Finite Difference Methods and dynamic scenario generation (Bumping).

## Quick Start
1. Clone the repository:
   `git clone https://github.com/present777/quant_pricing_engine.git`
2. Compile and run:
   `g++ src/main.cpp -o PricingEngine`
   `./PricingEngine`

## Future Work
- [ ] Implement multi-threading for Monte Carlo simulations.
- [ ] Add support for exotic options (eg: Asian options, Barrier options).
- [ ] Build a Volatility Surface constructor.

---

## 中文说明

本项目是一个基于 C++ 开发的面向对象（OOP）期权定价引擎。

### 核心亮点
*   **面向对象**：利用 C++ 多态机制构建 `Payoff` 抽象基类，将金融产品（看涨/看跌期权）与底层数学定价算法解耦，符合开闭原则（OCP）。
*   **不可变市场环境**：设计了独立的 `Market` 数据中心类，管理标的价格、利率和波动率。通过只读访问（Const Correctness），保障了数据安全。
*   **多模型定价引擎**：支持 Black-Scholes 解析解、蒙特卡洛（Monte Carlo）路径模拟以及二叉树（Binomial Tree）模型。同时利用了期权平价公式（Put-Call Parity），减少了冗余代码。
*   **Greeks 计算**：基于有限差分法，通过动态生成平行市场状态（Bumping），计算期权的 Delta, Gamma, 和 Vega。