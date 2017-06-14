#include "class_template_handler.h"

using clang::ast_matchers::MatchFinder;
using clang::FullSourceLoc;

void ClassTemplateHandler::run(const MatchFinder::MatchResult &result) {
    auto classTemplDecl =
        result.Nodes.getNodeAs<clang::ClassTemplateDecl>("class-template");
    if(classTemplDecl) {
        FullSourceLoc loc_start =
            result.Context->getFullLoc(classTemplDecl->getLocStart());
        FullSourceLoc loc_end =
            result.Context->getFullLoc(classTemplDecl->getTemplatedDecl()->getLocStart());
        llvm::outs() << "Found class template\n";
        if (loc_start.isValid()) {
            llvm::outs() << "start - "
                << loc_start.getSpellingLineNumber() << ":"
                << loc_start.getSpellingColumnNumber() << "\n";
        }
        if (loc_end.isValid()) {
            llvm::outs() << "end - "
                << loc_end.getSpellingLineNumber() << ":"
                << loc_end.getSpellingColumnNumber() << "\n";
        }
    }
}
