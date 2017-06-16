add_library(test-common template_finder/test_common.cpp)

add_executable(find-class-template.test
    template_finder/find_class_template_tests.cpp
)
target_link_libraries(find-class-template.test
    gtest_main
    test-common
    cpp-template-finder-lib
)
