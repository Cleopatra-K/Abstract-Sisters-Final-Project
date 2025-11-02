# Pretoria Blooms Co. - Plant Nursery Management System


**Team Name:** Abstract Sisters Final Project  
**Course:** COS214 – Design Patterns Project  
**Institution:** University of Pretoria    

**Pretoria Blooms Co.** is a C++ based **e-commerce system** that simulates a functional plant nursery.  
Users can browse, customize, and purchase a variety of **flowers and trees**, manage their shopping cart, and create bundles or arrangements.  
The system is designed to showcase **software design principles** and the practical application of multiple **design patterns**.


---

## Project Overview

**Pretoria Blooms Co.** is a featured plant nursery management system that handles:  
- **Plant inventory management** with complete life cycle tracking  
- **Customer purchasing workflows** with shopping cart and bundle functionality  
- **Staff coordination** between greenhouse and sales operations  
- **Plant customization options** such as decorative pots and arrangements  
- **Dynamic discount system** and real-time stock tracking  

The system models the daily operations of a nursery, providing extensibility for future additions such as new plant types, staff roles, and customer features.

---

## System Architecture

This system integrates **13 Gang of Four (GoF) design patterns** to achieve modularity, maintainability, and scalability.

| Pattern Type | Pattern | Description |
|---------------|----------|--------------|
| **Behavioral** | **State** | Manages plant life cycle transitions from seedling to withering. |
|  | **Strategy** | Calculates customer discounts dynamically (bulk, seasonal, withering). |
|  | **Mediator** | Coordinates communication between greenhouse staff and sales staff. |
|  | **Template Method** | Defines plant care routines with flexible steps. |
|  | **Command** | Encapsulates user actions such as purchasing, removing, or watering plants. |
|  | **Chain of Responsibility** | Routes customer and staff requests to the appropriate handlers. |
| **Creational** | **Abstract Factory** | Creates plant families (flowers, trees) for consistent production. |
|  | **Prototype** | Clones existing plants for quick stock replenishment. |
| **Structural** | **Composite** | Groups plants into bundles and bouquets for customer customization. |
|  | **Decorator** | Adds decorative elements such as pots, gift wrapping, or cards. |
|  | **Bridge** | Separates plant color representation from plant type. |
|  | **Iterator** | Enables traversal through bundled or grouped plants. |
|  | **Facade** | Provides a simplified, unified menu interface for customers. |

**Technology Stack:** C++11, Makefile build system  

---

## Project Structure

All files are located in the **root directory**, with a dedicated **`/docs`** folder containing the final report and UML diagrams.

```
/ (root)
│
├── README.md                # Project documentation
├── Makefile                 # Build and run configuration
├── TestingMain.cpp          # Main entry point
├── *.cpp / *.h              # All source and header files
│
└── /docs                    # Documentation and report files
    ├── COS214_Final_Report.pdf
    └──TransparentLogo.png
```

## Compilation and Execution

### Prerequisites
- **C++ compiler** with C++11 support (g++ recommended)
- **WSL/Ubuntu environment** (required for Makefile compatibility)
- **Valgrind** (optional, for memory leak analysis)

### Installation & Setup
1. Ensure WSL/Ubuntu is installed and configured
2. Clone or download the project repository to your local machine
3. Navigate to the project's root directory

### Building the System
```bash
make
```

### Running the Application
```bash
./nursery
```

### Maintenance Commands
```bash 
make clean      
make valgrind  
``` 

### System Features
1. Interactive Menu System: Simple facade-driven interface for customers and staff.
2. Real-Time Inventory: Tracks stock levels and updates automatically.
3. Plant Life Cycle Simulation: Manages transitions through seedling, blooming, mature, and withering states.
4. Customer Management: Handles shopping carts, purchases, and bundle creation.
5. Staff Operations: Divides tasks between greenhouse and sales staff, using the Mediator pattern.
6. Discount System: Applies multiple discount strategies such as seasonal and bulk discounts.
7. Bundle Creation: Uses the Composite pattern to create bouquets and arrangements dynamically.

#### Development Team
Abstract Sisters – COS214 2025
Department of Computer Science, University of Pretoria

<p align="center">
  <img src="docs/TransparentLogo.png" alt="Pretoria Blooms Co. Logo" width="200" style="margin-bottom: 20px;">
</p>
