#include "clang/Tooling/CommonOptionsParser.h"
#include "clang/Tooling/Tooling.h"
// Declares llvm::cl::extrahelp.
#include "llvm/Support/CommandLine.h"

#include "template_finder.h"

using namespace llvm;
// CommonOptionsParser declares HelpMessage with a description of the common
// command-line options related to the compilation database and input files.
// It's nice to have this help message in all tools.
static cl::extrahelp common_help(clang::tooling::CommonOptionsParser::HelpMessage);
// A help message for this specific tool can be added afterwards.
static cl::extrahelp more_help("\nMore help text...");

int main(int argc, const char **argv) {
    try {
        auto templates = FindTemplates(argc, argv);
        llvm::outs() << "found class templates: " << templates.size() << "\n";
    } catch(std::exception const &e) {
        llvm::outs() << e.what() << "\n";
    }
}
