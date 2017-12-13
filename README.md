# Fanfare Simulator

[![UNIX Build Status](https://travis-ci.org/fanfaresimulator/fanfaresimulator.svg?branch=master)](https://travis-ci.org/fanfaresimulator/fanfaresimulator)
[![Windows Build status](https://ci.appveyor.com/api/projects/status/feq6cgdphiymy52p?svg=true)](https://ci.appveyor.com/project/emersion/fanfaresimulator)

## Setup

Dependencies:
* [CMake](https://cmake.org/)
* [Qt](https://www.qt.io/)
* [FluidSynth](http://www.fluidsynth.org/)

### Linux

On Debian-based systems:

```shell
sudo apt install qtbase5-dev libfluidsynth-dev
```

In the project directory:

```shell
mkdir build
cd build
cmake ..
```

### macOS

```shell
brew install qt fluidsynth
```

In the project directory:

```shell
mkdir build
cd build
cmake ..
```

### Windows

* If you don't have Visual Studio, install Visual C++ Build Tools
  * Download http://landinghub.visualstudio.com/visual-cpp-build-tools
  * Launch setup, install
  * Add `C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\bin\amd64` to your `PATH`
  * Add `C:\Program Files (x86)\Windows Kits\10\bin\x64\ucrt` to your `PATH`
* Install Qt
  * Go to https://www.qt.io/download-qt-for-application-development then "Get your open source package"
  * Launch setup
  * In "Select Components", check "Qt > Qt 5.9.2 > msvc2015 64-bit"
  * Install
  * Add `C:\Qt\5.9.2\msvc2015_64\bin` to your `PATH`
* Install pre-built Fluidsynth
  * Download https://github.com/fanfaresimulator/fanfaresimulator/files/1505797/vendor.zip
  * Move it in the project directory
  * Right click > Extract All
  * Add the `vendor\lib` directory to your `PATH`
* Install CMake
  * Go to https://cmake.org/download/ then "Latest Release > Binary Distributions > Windows win64-x64 Installer"
  * Launch setup, install
* Run CMake
  * If you have Visual Studio
    * Launch CMake (cmake-gui)
    * Select source directory
    * Create a new directory "build" and select it as build directory
    * Configure
    * Select "Visual Studio 14 2015 Win64"
    * Generate
    * Open project (or open `fanfaresimulator.sln` with Visual Studio)
    * Build
  * If you don't have Visual Studio, from the CLI:
    ```shell
    mkdir build
    cd build
    cmake .. -G "Visual Studio 14 2015 Win64" -DCMAKE_PREFIX_PATH=C:\Qt\5.9.2\msvc2015_64
    msbuild fanfaresimulator.sln
    ```

And you're done!

## Build

```shell
cd build # If you're not there already
make
```

## Usage

Start the server and some clients:

```shell
./fanfaresimulator-server
./fanfaresimulator
```

If you want to select a custom MIDI file:

```shell
./fanfaresimulator-server <midi-file>
```

If you want to change the number of players (put 0 to just play the partition):

```shell
./fanfaresimulator-server --players-nbr=4
```

### Cleanup build directory

```shell
rm -rf build
mkdir build
cd build
cmake ..
```
