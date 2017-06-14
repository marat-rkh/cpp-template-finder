#include "class_template_handler.h"

using clang::ast_matchers::MatchFinder;
using clang::ClassTemplateDecl;

void ClassTemplateHandler::run(const MatchFinder::MatchResult &result) {
    auto nodes = result.Nodes;
    auto class_templ_decl = nodes.getNodeAs<ClassTemplateDecl>("class-template");
    if(class_templ_decl) {
        auto ctx = result.Context;
        auto loc_start = ctx->getFullLoc(class_templ_decl->getLocStart());
        auto loc_end = ctx->getFullLoc(class_templ_decl->getTemplatedDecl()->getLocStart());
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
