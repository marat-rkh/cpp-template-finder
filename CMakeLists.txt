set(LLVM_LINK_COMPONENTS support)

add_clang_executable(cpp-template-finder
  main.cpp
  class_template_callback.cpp
  class_template_handler.cpp
)

target_link_libraries(cpp-template-finder
  clangTooling
  clangBasic
  clangASTMatchers
)

install(TARGETS cpp-template-finder RUNTIME DESTINATION bin)
