#include "template_finder.h"

#include <stdexcept>

#include "clang/Tooling/CommonOptionsParser.h"
#include "clang/Tooling/Tooling.h"
#include "clang/ASTMatchers/ASTMatchFinder.h"

#include "class_template_handler.h"

using std::vector;
using std::string;
using std::runtime_error;
using llvm::cl::OptionCategory;
using clang::tooling::CommonOptionsParser;
using clang::tooling::ClangTool;
using clang::tooling::newFrontendActionFactory;
using clang::ast_matchers::MatchFinder;

// Apply a custom category to all command-line options so that they are the
// only ones displayed.
static OptionCategory tool_category("my-tool options");

vector<ClassTemplateData> FindTemplates(int argc, const char *argv[]) {
    CommonOptionsParser options_parser(argc, argv, tool_category);
    ClangTool tool(
        options_parser.getCompilations(),
        options_parser.getSourcePathList()
    );

    MatchFinder finder;
    auto class_template_callback = ClassTemplateHandler::CreateCallback();
    finder.addMatcher(ClassTemplateHandler::Matcher, &class_template_callback);

    int res = tool.run(newFrontendActionFactory(&finder).get());
    if(res) {
        throw runtime_error("failed to find templates");
    }
    return class_template_callback.CollectedData();
}


vector<ClassTemplateData> FindTemplates(string const &file_path) {
    const int argc = 5;
    const char *argv[] = {"", file_path.c_str(), "--", "-xc++", "-std=c++11"};
    return FindTemplates(argc, argv);
}
