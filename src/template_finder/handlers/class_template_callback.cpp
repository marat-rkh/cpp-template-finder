#include "class_template_callback.h"

using clang::ast_matchers::MatchFinder;
using clang::ClassTemplateDecl;
using clang::NonTypeTemplateParmDecl;
using clang::TemplateTypeParmDecl;
using clang::TemplateTemplateParmDecl;

namespace template_finder { namespace handlers {

void ClassTemplateCallback::run(const MatchFinder::MatchResult &result) {
    auto nodes = result.Nodes;
    auto full_decl = nodes.getNodeAs<ClassTemplateDecl>(bound_name_);
    if(!full_decl) {
        llvm::outs() << "warning: encountered class template with no declaration\n";
        return;
    }
    const auto &decl_name = full_decl->getNameAsString();
    auto ctx = result.Context;
    auto loc_start = ctx->getFullLoc(full_decl->getLocStart());
    if(!loc_start.isValid()) {
        llvm::outs() << "warning: failed to get start location for class template "
            << decl_name << "\n";
        return;
    }
    auto params = full_decl->getTemplateParameters();
    if(!params) {
        llvm::outs() << "warning: failed to get params for class template " << decl_name << "\n";
        return;
    }
    auto loc_end = ctx->getFullLoc(params->getRAngleLoc());
    if(!loc_end.isValid()) {
        llvm::outs() << "warning: failed to get end location for class template "
            << decl_name << "\n";
        return;
    }
    // for(auto p: *params) {
    //     if(llvm::isa<NonTypeTemplateParmDecl>(p)) {
    //         auto non_type_p = llvm::cast<NonTypeTemplateParmDecl>(p);
    //         llvm::outs() << non_type_p->getType().getAsString();
    //     } else if(llvm::isa<TemplateTypeParmDecl>(p)) {
    //         llvm::outs() << "typename";
    //     } else if(llvm::isa<TemplateTemplateParmDecl>(p)) {
    //         // TODO handle
    //     } else {
    //         llvm::outs() << "warning: undexpected template parameter type\n";
    //     }
    //     llvm::outs() << " " << p->getName() << "\n";
    // }
    data_.push_back({
        { loc_start.getSpellingLineNumber(), loc_start.getSpellingColumnNumber() },
        { loc_end.getSpellingLineNumber(), loc_end.getSpellingColumnNumber() }
    });
}

}}
