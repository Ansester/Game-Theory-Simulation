# Iterated Prisoner's Dilemma Simulation

A C++ command-line application for simulating multi-round Iterated Prisoner's Dilemma (IPD) games across configurable decision strategies.

---

## Context & Provenance

* **Project Context**: Coursework project for Computer Science / Game Theory (NYU Abu Dhabi).
* **Author**: Ashmit Mukherjee.

---

## Technical Details & Payoff Matrix

* **Payoff Rules**:
  * Both Cooperate: +3 points each
  * Both Defect: +1 point each
  * One Cooperates / One Defects: Defector +5 points, Cooperator 0 points
* **Supported Strategies**:
  * `Always Defect` (`e`): Defects on every turn.
  * `Always Cooperate` (`g`): Cooperates on every turn.
  * `Tit-for-Tat` (`t`): Mimics the opponent's previous move (with configurable initial move).
  * `Random` (`r`): Randomly chooses cooperation or defection.

---

## Running Locally

```bash
# Compile
g++ -std=c++17 main.cpp -o ipd_sim

# Run simulation
./ipd_sim
```

---

## License

This repository's source code is licensed under the [MIT License](LICENSE).
