# - Try to find Portaudio
# Once done this will define
#
#  FLUIDSYNTH_FOUND - system has Portaudio
#  FLUIDSYNTH_INCLUDE_DIRS - the Portaudio include directory
#  FLUIDSYNTH_LIBRARIES - Link these to use Portaudio
#  FLUIDSYNTH_DEFINITIONS - Compiler switches required for using Portaudio
#  FLUIDSYNTH_VERSION - Portaudio version
#
#  Copyright (c) 2006 Andreas Schneider <mail@cynapses.org>
#
# Redistribution and use is allowed according to the terms of the New BSD license.
# For details see the accompanying COPYING-CMAKE-SCRIPTS file.
#

if (FLUIDSYNTH_LIBRARIES AND FLUIDSYNTH_INCLUDE_DIRS)
  # in cache already
  set(FLUIDSYNTH_FOUND TRUE)
else (FLUIDSYNTH_LIBRARIES AND FLUIDSYNTH_INCLUDE_DIRS)
  if (NOT WIN32)
   include(FindPkgConfig)
   pkg_check_modules(FLUIDSYNTH fluidsynth)
  endif (NOT WIN32)

  if (NOT FLUIDSYNTH_FOUND)
    find_path(FLUIDSYNTH_INCLUDE_DIR
      NAMES fluidsynth.h
      HINTS ./vendor/include
    )

    find_library(FLUIDSYNTH_LIBRARY
      NAMES fluidsynth_debug fluidsynth
      HINTS ./vendor/lib
    )

    set(FLUIDSYNTH_INCLUDE_DIRS ${FLUIDSYNTH_INCLUDE_DIR})
    set(FLUIDSYNTH_LIBRARIES ${FLUIDSYNTH_LIBRARY})
    set(FLUIDSYNTH_LIBRARY_DIRS ${FLUIDSYNTH_LIBRARY_DIR})

  endif (NOT FLUIDSYNTH_FOUND)

  # show the FLUIDSYNTH_INCLUDE_DIRS and FLUIDSYNTH_LIBRARIES variables only in the advanced view
  mark_as_advanced(FLUIDSYNTH_INCLUDE_DIRS FLUIDSYNTH_LIBRARIES)

endif (FLUIDSYNTH_LIBRARIES AND FLUIDSYNTH_INCLUDE_DIRS)
