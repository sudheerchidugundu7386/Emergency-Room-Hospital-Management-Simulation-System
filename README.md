# ER Priority-Based Hospital Emergency Simulation System 🚑

This project is a C++ based **Hospital Emergency Management System** that
simulates real-world emergency triage using a **Priority Queue**.  
Patients are treated based on severity — **Critical → Serious → Normal**.

---

## ⭐ Features
- Add new patients with age, problem, and severity
- Priority-based automatic queue management
- Treats the highest priority patient first
- Search patient by name
- View all waiting patients in a formatted table
- Count the number of patients waiting
- Simple and user-friendly console interface

---

## 🧠 Data Structures Used
- **Priority Queue** (Min-Heap concept)
- Custom comparator for severity ordering

---

## 🔧 How to Run
```bash
g++ emergency.cpp -o emergency
./emergency
