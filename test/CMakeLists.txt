include(FetchContent)
FetchContent_Declare(
  googletest
  # Specify the commit you depend on and update it regularly.
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(Google_Tests test.cpp ${CMAKE_SOURCE_DIR}/sudoku.h ${CMAKE_SOURCE_DIR}/sudoku.cpp ${CMAKE_SOURCE_DIR}/util.h ${CMAKE_SOURCE_DIR}/util.cpp)
target_link_libraries(Google_Tests gtest)
target_include_directories(Google_Tests PRIVATE ${CMAKE_SOURCE_DIR})

include(GoogleTest)
gtest_discover_tests(Google_Tests)

