# Fanfare Simulator

[![UNIX Build Status](https://travis-ci.org/fanfaresimulator/fanfaresimulator.svg?branch=master)](https://travis-ci.org/fanfaresimulator/fanfaresimulator)
[![Windows Build status](https://ci.appveyor.com/api/projects/status/feq6cgdphiymy52p?svg=true)](https://ci.appveyor.com/project/emersion/fanfaresimulator)

## Setup

Dependencies:
* [CMake](https://cmake.org/)
* [Qt](https://www.qt.io/)
  * Linux: on Debian-based systems, `apt install qtbase5-dev`
  * Windows: http://doc.qt.io/qt-5/gettingstarted.html
  * Mac: `brew install qt`

```
cd build # If youŕe not there already
make
./fanfaresimulator
```

## Make clean
```
rm -rf build/
mkdir build/
cd build/
cmake ../
```
