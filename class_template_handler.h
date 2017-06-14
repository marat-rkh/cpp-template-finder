#ifndef __CLASS_TEMPLATE_HANDLER_H__
#define __CLASS_TEMPLATE_HANDLER_H__

#include "clang/ASTMatchers/ASTMatchFinder.h"

class ClassTemplateHandler
    : public clang::ast_matchers::MatchFinder::MatchCallback
{
public:
    void run(const clang::ast_matchers::MatchFinder::MatchResult &result) override;
};

#endif
