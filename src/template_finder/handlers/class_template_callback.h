#ifndef __CLASS_TEMPLATE_CALLBACK_H__
#define __CLASS_TEMPLATE_CALLBACK_H__

#include <string>
#include <vector>

#include "3rd_party/json.hpp"

#include "clang/ASTMatchers/ASTMatchFinder.h"

namespace template_finder { namespace handlers {

class ClassTemplateCallback: public clang::ast_matchers::MatchFinder::MatchCallback {
public:
    explicit ClassTemplateCallback(const std::string &bound_name)
        : bound_name_(bound_name)
    {}

    void run(const clang::ast_matchers::MatchFinder::MatchResult &result) override;
    const std::vector<nlohmann::json> &CollectedData() const { return data_; }
private:
    nlohmann::json HandleParams(clang::TemplateParameterList *params);

    const std::string bound_name_;
    std::vector<nlohmann::json> data_;
};

}}

#endif
