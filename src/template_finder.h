#ifndef __TEMPLATE_FINDER_H__
#define __TEMPLATE_FINDER_H__

#include <vector>
#include <string>

#include "clang/Tooling/Tooling.h"

#include "collected_data.h"

CollectedData FindTemplates(
    const std::vector<std::string> &srcPathList,
    const clang::tooling::CompilationDatabase &compilations
);

#endif
