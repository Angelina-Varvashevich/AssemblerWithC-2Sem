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
CMAKE_SOURCE_DIR = "D:\clion\2 sem\ts"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:\clion\2 sem\ts\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles\ts.dir\depend.make
# Include the progress variables for this target.
include CMakeFiles\ts.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\ts.dir\flags.make

CMakeFiles\ts.dir\main.cpp.obj: CMakeFiles\ts.dir\flags.make
CMakeFiles\ts.dir\main.cpp.obj: ..\main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\clion\2 sem\ts\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ts.dir/main.cpp.obj"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\ts.dir\main.cpp.obj /FdCMakeFiles\ts.dir\ /FS -c "D:\clion\2 sem\ts\main.cpp"
<<

CMakeFiles\ts.dir\main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ts.dir/main.cpp.i"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\cl.exe > CMakeFiles\ts.dir\main.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\clion\2 sem\ts\main.cpp"
<<

CMakeFiles\ts.dir\main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ts.dir/main.cpp.s"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\ts.dir\main.cpp.s /c "D:\clion\2 sem\ts\main.cpp"
<<

CMakeFiles\ts.dir\DynamicArray.cpp.obj: CMakeFiles\ts.dir\flags.make
CMakeFiles\ts.dir\DynamicArray.cpp.obj: ..\DynamicArray.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\clion\2 sem\ts\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/ts.dir/DynamicArray.cpp.obj"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\ts.dir\DynamicArray.cpp.obj /FdCMakeFiles\ts.dir\ /FS -c "D:\clion\2 sem\ts\DynamicArray.cpp"
<<

CMakeFiles\ts.dir\DynamicArray.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ts.dir/DynamicArray.cpp.i"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\cl.exe > CMakeFiles\ts.dir\DynamicArray.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\clion\2 sem\ts\DynamicArray.cpp"
<<

CMakeFiles\ts.dir\DynamicArray.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ts.dir/DynamicArray.cpp.s"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\ts.dir\DynamicArray.cpp.s /c "D:\clion\2 sem\ts\DynamicArray.cpp"
<<

# Object files for target ts
ts_OBJECTS = \
"CMakeFiles\ts.dir\main.cpp.obj" \
"CMakeFiles\ts.dir\DynamicArray.cpp.obj"

# External object files for target ts
ts_EXTERNAL_OBJECTS =

ts.exe: CMakeFiles\ts.dir\main.cpp.obj
ts.exe: CMakeFiles\ts.dir\DynamicArray.cpp.obj
ts.exe: CMakeFiles\ts.dir\build.make
ts.exe: CMakeFiles\ts.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="D:\clion\2 sem\ts\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable ts.exe"
	"C:\Program Files\JetBrains\CLion 2021.2.2\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\ts.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\100190~1.0\x86\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\100190~1.0\x86\mt.exe --manifests -- C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\link.exe /nologo @CMakeFiles\ts.dir\objects1.rsp @<<
 /out:ts.exe /implib:ts.lib /pdb:"D:\clion\2 sem\ts\cmake-build-debug\ts.pdb" /version:0.0 /machine:X86 /debug /INCREMENTAL /subsystem:console  kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\ts.dir\build: ts.exe
.PHONY : CMakeFiles\ts.dir\build

CMakeFiles\ts.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\ts.dir\cmake_clean.cmake
.PHONY : CMakeFiles\ts.dir\clean

CMakeFiles\ts.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" "D:\clion\2 sem\ts" "D:\clion\2 sem\ts" "D:\clion\2 sem\ts\cmake-build-debug" "D:\clion\2 sem\ts\cmake-build-debug" "D:\clion\2 sem\ts\cmake-build-debug\CMakeFiles\ts.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles\ts.dir\depend
