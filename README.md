# Drag & Drop Files Gui

A simple drag and drop application in Qt with C++. This has been actually made for someone's need in real life and then turned into a learning curve for me to see how to use Qt with C++. It may be useful for some fellow.

## Build

See [releases](https://github.com/DrShahinstein/qtcopy-files/releases/tag/Stable) if you are interested.

### Linux

Make sure you have [cmake](https://cmake.org/) installed on your machine.

```
$ ./run
```

### Windows
Use [w64devkit](https://github.com/skeeto/w64devkit) terminal

```
$ ./run
```

### Release Build
```
./run --release-build

# check include/working_dir.h to see why that is
```

## Troubleshooting

1. While building in Windows with w64devkit, if you ever get something like this `CMake Error: CMAKE_CXX_COMPILER not set, after EnableLanguage`, open the run script and change the cmake line with this one: `cmake -G "MinGW Makefiles" $cmake_options ..`

## Preview

https://github.com/DrShahinstein/qtcopy-files/assets/81323808/00d37ce1-0754-4e0f-929d-51ecb4a1fe2f

