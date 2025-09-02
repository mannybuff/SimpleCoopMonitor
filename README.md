# SimpleCoopMonitor

A simple C++ project to track chickens and their egg production using custom objects and linked lists.

## Overview

This application manages a small chicken coop by tracking animals (currently limited to chickens), their details (name, sex, egg production), and associated expenses. It uses a linked list for animal storage, supports ordered insertion by name, and persists data to a file (`couplist.txt`).

Key features:
- Add, remove, and list chickens.
- Collect and update egg production for female chickens.
- Manage and update expenses (e.g., construction, feed).
- Menu-driven interface for user interaction.

## Requirements

- C++ compiler (e.g., g++).
- Standard library support.

## Building and Running

1. Clone the repository:
    git clone https://github.com/mannybuff/SimpleCoopMonitor.git
    cd SimpleCoopMonitor
2. Build the project (using Makefile if provided, or manually):
    make
    Or: g++ -o main *.cpp
3. Run the executable:
    ./main


Data is loaded from and saved to `couplist.txt`. Sample data is included.

## Structure

- **animal.h/cpp**: Base class for animals.
- **chicken.h/cpp**: Derived class for chickens with egg tracking.
- **linked.h/cpp**: Linked list implementation for managing animals.
- **function.h/cpp**: Utility functions for menus, data loading, and operations.
- **main.cpp**: Entry point; handles file I/O and menu loop.
- **couplist.txt**: Data persistence file.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

