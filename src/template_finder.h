#ifndef __TEMPLATE_FINDER_H__
#define __TEMPLATE_FINDER_H__

#include <vector>
#include <string>

#include "class_template_data.h"

std::vector<ClassTemplateData> FindTemplates(int argc, const char *argv[]);
std::vector<ClassTemplateData> FindTemplates(std::string const &file_path);

#endif
