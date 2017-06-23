#ifndef __CLASS_TEMPLATE_CALLBACK_H__
#define __CLASS_TEMPLATE_CALLBACK_H__

#include <string>
#include <vector>
#include <set>

#include "3rd_party/json.hpp"

#include "clang/ASTMatchers/ASTMatchFinder.h"

namespace template_finder { namespace handlers {

class ClassTemplateCallback: public clang::ast_matchers::MatchFinder::MatchCallback {
public:
    explicit ClassTemplateCallback(
        const std::vector<std::string> &target_files,
        const std::string &bound_name
    )
        : target_files_(target_files.begin(), target_files.end())
        , bound_name_(bound_name)
    {}

    void run(const clang::ast_matchers::MatchFinder::MatchResult &result) override;
    const std::vector<nlohmann::json> &CollectedData() const { return data_; }
private:
    bool IsAmongTargetFiles(
        clang::ASTContext *const ctx,
        const clang::ClassTemplateDecl *decl
    ) const;
    nlohmann::json HandleParams(clang::TemplateParameterList *params);

    const std::set<std::string> target_files_;
    const std::string bound_name_;
    std::vector<nlohmann::json> data_;
};

}}

#endif
