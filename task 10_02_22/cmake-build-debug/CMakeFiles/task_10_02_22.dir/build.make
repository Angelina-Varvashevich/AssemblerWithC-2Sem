# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.20

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.2.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.2.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "D:\clion\2 sem\task 10_02_22"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:\clion\2 sem\task 10_02_22\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles\task_10_02_22.dir\depend.make
# Include the progress variables for this target.
include CMakeFiles\task_10_02_22.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\task_10_02_22.dir\flags.make

CMakeFiles\task_10_02_22.dir\main.cpp.obj: CMakeFiles\task_10_02_22.dir\flags.make
CMakeFiles\task_10_02_22.dir\main.cpp.obj: ..\main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\clion\2 sem\task 10_02_22\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/task_10_02_22.dir/main.cpp.obj"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\task_10_02_22.dir\main.cpp.obj /FdCMakeFiles\task_10_02_22.dir\ /FS -c "D:\clion\2 sem\task 10_02_22\main.cpp"
<<

CMakeFiles\task_10_02_22.dir\main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/task_10_02_22.dir/main.cpp.i"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\cl.exe > CMakeFiles\task_10_02_22.dir\main.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\clion\2 sem\task 10_02_22\main.cpp"
<<

CMakeFiles\task_10_02_22.dir\main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/task_10_02_22.dir/main.cpp.s"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\task_10_02_22.dir\main.cpp.s /c "D:\clion\2 sem\task 10_02_22\main.cpp"
<<

CMakeFiles\task_10_02_22.dir\Flowerbed.cpp.obj: CMakeFiles\task_10_02_22.dir\flags.make
CMakeFiles\task_10_02_22.dir\Flowerbed.cpp.obj: ..\Flowerbed.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\clion\2 sem\task 10_02_22\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/task_10_02_22.dir/Flowerbed.cpp.obj"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\task_10_02_22.dir\Flowerbed.cpp.obj /FdCMakeFiles\task_10_02_22.dir\ /FS -c "D:\clion\2 sem\task 10_02_22\Flowerbed.cpp"
<<

CMakeFiles\task_10_02_22.dir\Flowerbed.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/task_10_02_22.dir/Flowerbed.cpp.i"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\cl.exe > CMakeFiles\task_10_02_22.dir\Flowerbed.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\clion\2 sem\task 10_02_22\Flowerbed.cpp"
<<

CMakeFiles\task_10_02_22.dir\Flowerbed.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/task_10_02_22.dir/Flowerbed.cpp.s"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\task_10_02_22.dir\Flowerbed.cpp.s /c "D:\clion\2 sem\task 10_02_22\Flowerbed.cpp"
<<

CMakeFiles\task_10_02_22.dir\FileReader.cpp.obj: CMakeFiles\task_10_02_22.dir\flags.make
CMakeFiles\task_10_02_22.dir\FileReader.cpp.obj: ..\FileReader.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\clion\2 sem\task 10_02_22\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/task_10_02_22.dir/FileReader.cpp.obj"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\task_10_02_22.dir\FileReader.cpp.obj /FdCMakeFiles\task_10_02_22.dir\ /FS -c "D:\clion\2 sem\task 10_02_22\FileReader.cpp"
<<

CMakeFiles\task_10_02_22.dir\FileReader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/task_10_02_22.dir/FileReader.cpp.i"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\cl.exe > CMakeFiles\task_10_02_22.dir\FileReader.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\clion\2 sem\task 10_02_22\FileReader.cpp"
<<

CMakeFiles\task_10_02_22.dir\FileReader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/task_10_02_22.dir/FileReader.cpp.s"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\task_10_02_22.dir\FileReader.cpp.s /c "D:\clion\2 sem\task 10_02_22\FileReader.cpp"
<<

CMakeFiles\task_10_02_22.dir\FlowerbedConversion.cpp.obj: CMakeFiles\task_10_02_22.dir\flags.make
CMakeFiles\task_10_02_22.dir\FlowerbedConversion.cpp.obj: ..\FlowerbedConversion.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\clion\2 sem\task 10_02_22\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/task_10_02_22.dir/FlowerbedConversion.cpp.obj"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\task_10_02_22.dir\FlowerbedConversion.cpp.obj /FdCMakeFiles\task_10_02_22.dir\ /FS -c "D:\clion\2 sem\task 10_02_22\FlowerbedConversion.cpp"
<<

CMakeFiles\task_10_02_22.dir\FlowerbedConversion.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/task_10_02_22.dir/FlowerbedConversion.cpp.i"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\cl.exe > CMakeFiles\task_10_02_22.dir\FlowerbedConversion.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\clion\2 sem\task 10_02_22\FlowerbedConversion.cpp"
<<

CMakeFiles\task_10_02_22.dir\FlowerbedConversion.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/task_10_02_22.dir/FlowerbedConversion.cpp.s"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\task_10_02_22.dir\FlowerbedConversion.cpp.s /c "D:\clion\2 sem\task 10_02_22\FlowerbedConversion.cpp"
<<

# Object files for target task_10_02_22
task_10_02_22_OBJECTS = \
"CMakeFiles\task_10_02_22.dir\main.cpp.obj" \
"CMakeFiles\task_10_02_22.dir\Flowerbed.cpp.obj" \
"CMakeFiles\task_10_02_22.dir\FileReader.cpp.obj" \
"CMakeFiles\task_10_02_22.dir\FlowerbedConversion.cpp.obj"

# External object files for target task_10_02_22
task_10_02_22_EXTERNAL_OBJECTS =

task_10_02_22.exe: CMakeFiles\task_10_02_22.dir\main.cpp.obj
task_10_02_22.exe: CMakeFiles\task_10_02_22.dir\Flowerbed.cpp.obj
task_10_02_22.exe: CMakeFiles\task_10_02_22.dir\FileReader.cpp.obj
task_10_02_22.exe: CMakeFiles\task_10_02_22.dir\FlowerbedConversion.cpp.obj
task_10_02_22.exe: CMakeFiles\task_10_02_22.dir\build.make
task_10_02_22.exe: CMakeFiles\task_10_02_22.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="D:\clion\2 sem\task 10_02_22\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable task_10_02_22.exe"
	"C:\Program Files\JetBrains\CLion 2021.2.2\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\task_10_02_22.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\100190~1.0\x86\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\100190~1.0\x86\mt.exe --manifests -- C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\link.exe /nologo @CMakeFiles\task_10_02_22.dir\objects1.rsp @<<
 /out:task_10_02_22.exe /implib:task_10_02_22.lib /pdb:"D:\clion\2 sem\task 10_02_22\cmake-build-debug\task_10_02_22.pdb" /version:0.0 /machine:X86 /debug /INCREMENTAL /subsystem:console  kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\task_10_02_22.dir\build: task_10_02_22.exe
.PHONY : CMakeFiles\task_10_02_22.dir\build

CMakeFiles\task_10_02_22.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\task_10_02_22.dir\cmake_clean.cmake
.PHONY : CMakeFiles\task_10_02_22.dir\clean

CMakeFiles\task_10_02_22.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" "D:\clion\2 sem\task 10_02_22" "D:\clion\2 sem\task 10_02_22" "D:\clion\2 sem\task 10_02_22\cmake-build-debug" "D:\clion\2 sem\task 10_02_22\cmake-build-debug" "D:\clion\2 sem\task 10_02_22\cmake-build-debug\CMakeFiles\task_10_02_22.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles\task_10_02_22.dir\depend

