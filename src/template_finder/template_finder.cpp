#include "template_finder.h"

#include <stdexcept>

#include "clang/Tooling/Tooling.h"
#include "clang/ASTMatchers/ASTMatchFinder.h"

#include "handlers/class_template_handler.h"

using std::vector;
using std::string;
using std::runtime_error;
using clang::tooling::CompilationDatabase;
using clang::tooling::ClangTool;
using clang::tooling::newFrontendActionFactory;
using clang::ast_matchers::MatchFinder;
using template_finder::handlers::ClassTemplateHandler;

namespace template_finder {

CollectedData FindTemplates(
    const vector<string> &src_paths,
    const CompilationDatabase &compilations
) {
    ClangTool tool(compilations, src_paths);
    MatchFinder finder;
    auto class_template_callback = ClassTemplateHandler::CreateCallback(src_paths);
    finder.addMatcher(ClassTemplateHandler::Matcher, &class_template_callback);

    int res = tool.run(newFrontendActionFactory(&finder).get());
    if(res) {
        throw runtime_error("failed to find templates");
    }
    return CollectedData(class_template_callback.CollectedData());
}

}
