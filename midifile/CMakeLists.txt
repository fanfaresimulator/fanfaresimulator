set(MIDIFILE_SOURCE_FILES
	Binasc.cpp
	MidiEvent.cpp
	MidiEventList.cpp
	MidiFile.cpp
	MidiMessage.cpp
	Options.cpp
)

add_library(midifile STATIC ${MIDIFILE_SOURCE_FILES})
target_include_directories(midifile PRIVATE ../include/midifile)
