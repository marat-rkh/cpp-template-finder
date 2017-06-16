#include "template_finder.h"

#include <stdexcept>

#include "clang/Tooling/Tooling.h"
#include "clang/ASTMatchers/ASTMatchFinder.h"

#include "class_template_handler.h"

using std::vector;
using std::string;
using std::runtime_error;
using clang::tooling::CompilationDatabase;
using clang::tooling::ClangTool;
using clang::tooling::newFrontendActionFactory;
using clang::ast_matchers::MatchFinder;

CollectedData FindTemplates(
    const vector<string> &srcPathList,
    const CompilationDatabase &compilations
) {
    ClangTool tool(compilations, srcPathList);
    MatchFinder finder;
    auto class_template_callback = ClassTemplateHandler::CreateCallback();
    finder.addMatcher(ClassTemplateHandler::Matcher, &class_template_callback);

    int res = tool.run(newFrontendActionFactory(&finder).get());
    if(res) {
        throw runtime_error("failed to find templates");
    }
    return CollectedData(class_template_callback.CollectedData());
}
