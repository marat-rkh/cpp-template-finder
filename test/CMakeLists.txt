set(TEST_SRC find_class_template_tests.cpp)
add_executable(find-class-template.test ${TEST_SRC})
target_link_libraries(find-class-template.test gtest_main cpp-template-finder-lib)
