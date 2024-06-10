# Drag & Drop Gui

A simple drag and drop application in Qt with C++. This has been actually made for someone's need in real life and then turned into a learning curve for me to see how to use Qt with C++. It may be useful for some fellow so I gathered the code in this repo.


## Preview

https://github.com/DrShahinstein/qtcopy-files/assets/81323808/bbd6db1e-aaea-4453-820f-f3055de15b69


## Build

See [releases](https://github.com/DrShahinstein/qtcopy-files/releases/tag/Stable) if you are interested.
If you want to build on your own, make sure you have [cmake](https://cmake.org/) and [qt](https://www.qt.io/download-open-source) installed on your machine.

### Linux
```
$ mkdir build
$ cd build/
$ cmake ..

# or

$ ./run
```

### Windows
Using [w64devkit](https://github.com/skeeto/w64devkit) is recommended to avoid the very silly windows problems I've gone through.

```
$ mkdir build
$ cd build/
$ cmake -G "MinGW Makefiles" ..

# or

$ ./run # w64devkit must be used
```

### Release Build
```
$ mkdir build
$ cd build/
$ cmake -DRELEASE_BUILD=ON ..                      # linux
$ cmake -G "MinGW Makefiles" -DRELEASE_BUILD=ON .. # windows

# or

./run --release-build

# see include/working_dir.h
```
