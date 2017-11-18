# Fanfare Simulator

[![UNIX Build Status](https://travis-ci.org/fanfaresimulator/fanfaresimulator.svg?branch=master)](https://travis-ci.org/fanfaresimulator/fanfaresimulator)
[![Windows Build status](https://ci.appveyor.com/api/projects/status/feq6cgdphiymy52p?svg=true)](https://ci.appveyor.com/project/emersion/fanfaresimulator)

## Setup

Dependencies:
* [CMake](https://cmake.org/)
* [Qt](https://www.qt.io/)
  * Linux: on Debian-based systems, `apt install qtbase5-dev`
  * Windows: https://www.qt.io/download-qt-for-application-development then "Get your open source package"
  * Mac: `brew install qt`
* [Portaudio](http://www.portaudio.com/)
  * Linux: on Debian-based systems, `apt install portaudio19-dev`
  * Windows: ???
  * Mac: `brew install portaudio`

```shell
cd build # If you're not there already
make
./fanfaresimulator
```

## Make clean

```shell
rm -rf build
mkdir build
cd build
cmake ..
```
