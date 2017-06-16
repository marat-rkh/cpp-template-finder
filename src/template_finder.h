#ifndef __TEMPLATE_FINDER_H__
#define __TEMPLATE_FINDER_H__

#include <vector>
#include <string>

#include "clang/Tooling/Tooling.h"

#include "class_template_data.h"

std::vector<ClassTemplateData> FindTemplates(
    const std::vector<std::string> &srcPathList,
    const clang::tooling::CompilationDatabase &compilations
);

#endif
