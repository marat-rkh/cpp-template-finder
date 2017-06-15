#ifndef __CLASS_TEMPLATE_HANDLER_H__
#define __CLASS_TEMPLATE_HANDLER_H__

#include <vector>

#include "clang/ASTMatchers/ASTMatchFinder.h"

#include "class_template_data.h"

class ClassTemplateHandler
    : public clang::ast_matchers::MatchFinder::MatchCallback
{
public:
    void run(const clang::ast_matchers::MatchFinder::MatchResult &result) override;
    const std::vector<ClassTemplateData> &CollectedData() const { return data_; }
private:
    std::vector<ClassTemplateData> data_;
};

#endif
