#include "clang/Tooling/CommonOptionsParser.h"
#include "clang/Tooling/Tooling.h"
// Declares llvm::cl::extrahelp.
#include "llvm/Support/CommandLine.h"

#include "template_finder.h"

using namespace llvm;
using llvm::cl::OptionCategory;
using clang::tooling::CommonOptionsParser;

// Apply a custom category to all command-line options so that they are the
// only ones displayed.
static OptionCategory tool_category("my-tool options");
// CommonOptionsParser declares HelpMessage with a description of the common
// command-line options related to the compilation database and input files.
// It's nice to have this help message in all tools.
static cl::extrahelp common_help(clang::tooling::CommonOptionsParser::HelpMessage);
// A help message for this specific tool can be added afterwards.
static cl::extrahelp more_help("\nMore help text...");

int main(int argc, const char **argv) {
    try {
        CommonOptionsParser options_parser(argc, argv, tool_category);
        auto templates = FindTemplates(
                options_parser.getSourcePathList(),
                options_parser.getCompilations()
        );
        llvm::outs() << "found class templates: " << templates.size() << "\n";
    } catch(std::exception const &e) {
        llvm::outs() << e.what() << "\n";
    }
}
