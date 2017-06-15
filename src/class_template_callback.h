#ifndef __CLASS_TEMPLATE_CALLBACK_H__
#define __CLASS_TEMPLATE_CALLBACK_H__

#include <string>
#include <vector>

#include "clang/ASTMatchers/ASTMatchFinder.h"

#include "class_template_data.h"

class ClassTemplateCallback: public clang::ast_matchers::MatchFinder::MatchCallback {
public:
    explicit ClassTemplateCallback(const std::string &bound_name)
        : bound_name_(bound_name)
    {}

    void run(const clang::ast_matchers::MatchFinder::MatchResult &result) override;
    const std::vector<ClassTemplateData> &CollectedData() const { return data_; }
private:
    const std::string bound_name_;
    std::vector<ClassTemplateData> data_;
};

#endif
