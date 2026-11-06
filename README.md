# Pazt
Simple and stupid utilities for terminal I made while craving some foods

![Static Badge](https://img.shields.io/badge/version-0.1.0-green?style=for-the-badge&logo=GitHub&logoColor=%23ffffff)
![GitHub License](https://img.shields.io/github/license/nunoguevara/Macaroni?style=for-the-badge)

## Tools
There are currently 2 utils available:
- Macaroni | file(s) creation
- Lasagna | reading text content of a file

## Installation
To install it (though Idk why anyone would install it), you can just build from source especially because it's lightweight
What you need:
- GCC or Clang or any other C compiler
- CMake

Installation steps:
```Shell
git clone --depth 1 https://github.com/nunoguevara/Pazt.git
cd Pazt
```
After that, you can configure your build with (You can customize the configuration to your liking):
```Shell
cmake -S . -B build
```
And then run:
```Shell
cmake --build build
cmake --install build
```
Or if you need to install it system-wide, you can run:
```Shell
cmake --build build
sudo cmake --install build
```
