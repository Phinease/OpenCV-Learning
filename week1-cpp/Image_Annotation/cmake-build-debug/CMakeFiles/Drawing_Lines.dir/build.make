# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/phinease/Desktop/OpenCV/week1-cpp/Image_Annotation

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/phinease/Desktop/OpenCV/week1-cpp/Image_Annotation/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Drawing_Lines.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Drawing_Lines.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Drawing_Lines.dir/flags.make

CMakeFiles/Drawing_Lines.dir/Drawing_Lines.cpp.o: CMakeFiles/Drawing_Lines.dir/flags.make
CMakeFiles/Drawing_Lines.dir/Drawing_Lines.cpp.o: ../Drawing_Lines.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/phinease/Desktop/OpenCV/week1-cpp/Image_Annotation/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Drawing_Lines.dir/Drawing_Lines.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Drawing_Lines.dir/Drawing_Lines.cpp.o -c /Users/phinease/Desktop/OpenCV/week1-cpp/Image_Annotation/Drawing_Lines.cpp

CMakeFiles/Drawing_Lines.dir/Drawing_Lines.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Drawing_Lines.dir/Drawing_Lines.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/phinease/Desktop/OpenCV/week1-cpp/Image_Annotation/Drawing_Lines.cpp > CMakeFiles/Drawing_Lines.dir/Drawing_Lines.cpp.i

CMakeFiles/Drawing_Lines.dir/Drawing_Lines.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Drawing_Lines.dir/Drawing_Lines.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/phinease/Desktop/OpenCV/week1-cpp/Image_Annotation/Drawing_Lines.cpp -o CMakeFiles/Drawing_Lines.dir/Drawing_Lines.cpp.s

# Object files for target Drawing_Lines
Drawing_Lines_OBJECTS = \
"CMakeFiles/Drawing_Lines.dir/Drawing_Lines.cpp.o"

# External object files for target Drawing_Lines
Drawing_Lines_EXTERNAL_OBJECTS =

Drawing_Lines: CMakeFiles/Drawing_Lines.dir/Drawing_Lines.cpp.o
Drawing_Lines: CMakeFiles/Drawing_Lines.dir/build.make
Drawing_Lines: /usr/local/lib/libopencv_gapi.4.5.0.dylib
Drawing_Lines: /usr/local/lib/libopencv_stitching.4.5.0.dylib
Drawing_Lines: /usr/local/lib/libopencv_aruco.4.5.0.dylib
Drawing_Lines: /usr/local/lib/libopencv_bgsegm.4.5.0.dylib
Drawing_Lines: /usr/local/lib/libopencv_bioinspired.4.5.0.dylib
Drawing_Lines: /usr/local/lib/libopencv_ccalib.4.5.0.dylib
Drawing_Lines: /usr/local/lib/libopencv_cvv.4.5.0.dylib
Drawing_Lines: /usr/local/lib/libopencv_dnn_objdetect.4.5.0.dylib
Drawing_Lines: /usr/local/lib/libopencv_dnn_superres.4.5.0.dylib
Drawing_Lines: /usr/local/lib/libopencv_dpm.4.5.0.dylib
Drawing_Lines: /usr/local/lib/libopencv_face.4.5.0.dylib
Drawing_Lines: /usr/local/lib/libopencv_fuzzy.4.5.0.dylib
Drawing_Lines: /usr/local/lib/libopencv_hfs.4.5.0.dylib
Drawing_Lines: /usr/local/lib/libopencv_img_hash.4.5.0.dylib
Drawing_Lines: /usr/local/lib/libopencv_intensity_transform.4.5.0.dylib
Drawing_Lines: /usr/local/lib/libopencv_line_descriptor.4.5.0.dylib
Drawing_Lines: /usr/local/lib/libopencv_mcc.4.5.0.dylib
Drawing_Lines: /usr/local/lib/libopencv_quality.4.5.0.dylib
Drawing_Lines: /usr/local/lib/libopencv_rapid.4.5.0.dylib
Drawing_Lines: /usr/local/lib/libopencv_reg.4.5.0.dylib
Drawing_Lines: /usr/local/lib/libopencv_rgbd.4.5.0.dylib
Drawing_Lines: /usr/local/lib/libopencv_saliency.4.5.0.dylib
Drawing_Lines: /usr/local/lib/libopencv_stereo.4.5.0.dylib
Drawing_Lines: /usr/local/lib/libopencv_structured_light.4.5.0.dylib
Drawing_Lines: /usr/local/lib/libopencv_superres.4.5.0.dylib
Drawing_Lines: /usr/local/lib/libopencv_surface_matching.4.5.0.dylib
Drawing_Lines: /usr/local/lib/libopencv_tracking.4.5.0.dylib
Drawing_Lines: /usr/local/lib/libopencv_videostab.4.5.0.dylib
Drawing_Lines: /usr/local/lib/libopencv_xfeatures2d.4.5.0.dylib
Drawing_Lines: /usr/local/lib/libopencv_xobjdetect.4.5.0.dylib
Drawing_Lines: /usr/local/lib/libopencv_xphoto.4.5.0.dylib
Drawing_Lines: /usr/local/lib/libopencv_shape.4.5.0.dylib
Drawing_Lines: /usr/local/lib/libopencv_highgui.4.5.0.dylib
Drawing_Lines: /usr/local/lib/libopencv_datasets.4.5.0.dylib
Drawing_Lines: /usr/local/lib/libopencv_plot.4.5.0.dylib
Drawing_Lines: /usr/local/lib/libopencv_text.4.5.0.dylib
Drawing_Lines: /usr/local/lib/libopencv_dnn.4.5.0.dylib
Drawing_Lines: /usr/local/lib/libopencv_ml.4.5.0.dylib
Drawing_Lines: /usr/local/lib/libopencv_phase_unwrapping.4.5.0.dylib
Drawing_Lines: /usr/local/lib/libopencv_optflow.4.5.0.dylib
Drawing_Lines: /usr/local/lib/libopencv_ximgproc.4.5.0.dylib
Drawing_Lines: /usr/local/lib/libopencv_video.4.5.0.dylib
Drawing_Lines: /usr/local/lib/libopencv_videoio.4.5.0.dylib
Drawing_Lines: /usr/local/lib/libopencv_imgcodecs.4.5.0.dylib
Drawing_Lines: /usr/local/lib/libopencv_objdetect.4.5.0.dylib
Drawing_Lines: /usr/local/lib/libopencv_calib3d.4.5.0.dylib
Drawing_Lines: /usr/local/lib/libopencv_features2d.4.5.0.dylib
Drawing_Lines: /usr/local/lib/libopencv_flann.4.5.0.dylib
Drawing_Lines: /usr/local/lib/libopencv_photo.4.5.0.dylib
Drawing_Lines: /usr/local/lib/libopencv_imgproc.4.5.0.dylib
Drawing_Lines: /usr/local/lib/libopencv_core.4.5.0.dylib
Drawing_Lines: CMakeFiles/Drawing_Lines.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/phinease/Desktop/OpenCV/week1-cpp/Image_Annotation/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Drawing_Lines"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Drawing_Lines.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Drawing_Lines.dir/build: Drawing_Lines

.PHONY : CMakeFiles/Drawing_Lines.dir/build

CMakeFiles/Drawing_Lines.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Drawing_Lines.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Drawing_Lines.dir/clean

CMakeFiles/Drawing_Lines.dir/depend:
	cd /Users/phinease/Desktop/OpenCV/week1-cpp/Image_Annotation/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/phinease/Desktop/OpenCV/week1-cpp/Image_Annotation /Users/phinease/Desktop/OpenCV/week1-cpp/Image_Annotation /Users/phinease/Desktop/OpenCV/week1-cpp/Image_Annotation/cmake-build-debug /Users/phinease/Desktop/OpenCV/week1-cpp/Image_Annotation/cmake-build-debug /Users/phinease/Desktop/OpenCV/week1-cpp/Image_Annotation/cmake-build-debug/CMakeFiles/Drawing_Lines.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Drawing_Lines.dir/depend
