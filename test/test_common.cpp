#include "test_common.h"

#include<vector>
#include<string>

using std::vector;
using std::string;
using clang::tooling::FixedCompilationDatabase;

const FixedCompilationDatabase TestCommon::TestCompilations =
    FixedCompilationDatabase(".", {"-xc++", "-std=c++11"});
