#ifndef __TEST_COMMON_H__
#define __TEST_COMMON_H__

#include "clang/Tooling/CompilationDatabase.h"

class TestCommon {
public:
    static const clang::tooling::FixedCompilationDatabase TestCompilations;
};

#endif
