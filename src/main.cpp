#include "clang/Tooling/CommonOptionsParser.h"
#include "clang/Tooling/Tooling.h"
// Declares llvm::cl::extrahelp.
#include "llvm/Support/CommandLine.h"

#include "clang/ASTMatchers/ASTMatchFinder.h"
// #include "clang/ASTMatchers/ASTMatchers.h"

#include "class_template_handler.h"

using namespace llvm;
using namespace clang::tooling;
using namespace clang::ast_matchers;

// Apply a custom category to all command-line options so that they are the
// only ones displayed.
static cl::OptionCategory tool_category("my-tool options");
// CommonOptionsParser declares HelpMessage with a description of the common
// command-line options related to the compilation database and input files.
// It's nice to have this help message in all tools.
static cl::extrahelp common_help(CommonOptionsParser::HelpMessage);
// A help message for this specific tool can be added afterwards.
static cl::extrahelp more_help("\nMore help text...");

int main(int argc, const char **argv) {
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
        return res;
    }
    llvm::outs() << "found class templates: "
        << class_template_callback.CollectedData().size() << "\n";
}
