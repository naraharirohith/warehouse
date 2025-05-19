# Warehouse Management System

![C++](https://img.shields.io/badge/C++-17-blue.svg)
![Platform](https://img.shields.io/badge/Platform-Linux%20%7C%20Windows-lightgrey.svg)

A terminal-based warehouse management system implementing core inventory features using Object-Oriented Programming (OOP) concepts.

## Table of Contents
- [Features](#features)
- [Prerequisites](#prerequisites)
- [Installation](#installation)
- [Building](#building)
- [Usage](#usage)
- [Database Configuration](#database-configuration)
- [Troubleshooting](#troubleshooting)
- [Contributing](#contributing)
- [License](#license)

## Features
- Inventory management (Add/Remove/Update items)
- Low stock alerts
- JSON data persistence
- Cross-platform support
- Terminal-based interface

## Prerequisites

### Linux
```bash
# Debian/Ubuntu
sudo apt update && sudo apt install -y \
    git \
    libjson-dev

## Installation

Clone the repository:

```bash
git clone https://github.com/yourusername/warehouse-system.git
cd warehouse-system

## Building

### Linux

To build the project on a Linux system, use the following commands:

```bash
make clean    # Clean previous builds
make          # Compile the project
