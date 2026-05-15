cmake_minimum_required(VERSION 3.10) # Set the minimum required version of CMake

project(Skuf.VS.Furry)

set(CMAKE_CXX_STANDARD 20) # Use C++20 standard
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SFML_DIR ${SFML_DIR}) # Adjust this path to where SFML is installed on your system

# Find the SFML package and specify the required components
find_package(SFML 3.0 REQUIRED COMPONENTS
    Graphics
    Window
    System
    Audio
    Network
    Main
)

file(GLOB_RECURSE SOURCES "src/*.cpp") # Collect all .cpp files in the src directory and its subdirectories

# add_executable(Skuf.VS.Furry WIN32 ${SOURCES}) # Create an executable target named DazedRE using the collected source files, with WIN32 flag to specify a Windows application (no console)
add_executable(Skuf.VS.Furry ${SOURCES}) # Create an executable target named DazedRE using the collected source files (without WIN32 flag, which will create a console application)

target_include_directories(Skuf.VS.Furry PRIVATE include) # Add the include directory to the target's include path

# Link the SFML libraries to the Skuf.VS.Furry target
target_link_libraries(Skuf.VS.Furry PRIVATE
    SFML::Graphics 
    SFML::Window 
    SFML::System 
    SFML::Audio 
    SFML::Network
    SFML::Main
)

# Set the working directory for the debugger to the source directory of the project
set_property(TARGET Skuf.VS.Furry PROPERTY
    VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}"
)

# After building the Skuf.VS.Furry target, copy the assets directory to the output directory of the executable
add_custom_command(TARGET Skuf.VS.Furry POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    "${CMAKE_SOURCE_DIR}/assets"
    "$<TARGET_FILE_DIR:Skuf.VS.Furry>/assets"
)