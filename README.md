# Macaroni
A simple and stupid file creation utility for terminal I made while craving some foods

![Static Badge](https://img.shields.io/badge/version-0.1.0-green?style=for-the-badge&logo=GitHub&logoColor=%23ffffff)
![GitHub License](https://img.shields.io/github/license/nunoguevara/Macaroni?style=for-the-badge)

## Features
- Lightweight and minuscule⚡
- Multi-file creation📂

## Installation
To install it (though Idk why anyone would install it), you can just build from source especially because it's lightweight
What you need:
- GCC or Clang or any other C compiler
- CMake

Installation steps:
```Shell
git clone --depth 1 https://github.com/nunoguevara/Macaroni.git
cd Macaroni
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

## Usage
You can use it to create a single file, e.g:
```Shell
macaroni textfile.txt
```

Or even multiple files:

```Shell
macaroni textfile.txt textfile1.txt textfile2.txt
```

And it doesn't overwrite existing files, so don't worry!