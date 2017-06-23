#include "class_template_callback.h"
#include "json_format.h"

using json = nlohmann::json;
using clang::ast_matchers::MatchFinder;
using clang::ClassTemplateDecl;
using clang::NonTypeTemplateParmDecl;
using clang::TemplateTypeParmDecl;
using clang::TemplateTemplateParmDecl;
using clang::TemplateParameterList;
using clang::LangOptions;
using clang::PrintingPolicy;
using clang::ASTContext;

namespace template_finder { namespace handlers {

void ClassTemplateCallback::run(const MatchFinder::MatchResult &result) {
    auto &nodes = result.Nodes;
    auto full_decl = nodes.getNodeAs<ClassTemplateDecl>(bound_name_);
    if(!full_decl) {
        // TODO this should not be here
        llvm::outs() << "warning: encountered class template with no declaration\n";
        return;
    }
    auto ctx = result.Context;
    if(!IsAmongTargetFiles(ctx, full_decl)) {
        return;
    }
    const auto &decl_name = full_decl->getNameAsString();
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
    json j_params = HandleParams(params);
    data_.push_back({
        {"kind", TemplateKind::CLASS_TEMPLATE},
        {"beg", {
            {"line", loc_start.getSpellingLineNumber() - 1},
            {"col", loc_start.getSpellingColumnNumber() - 1},
        }},
        {"end", {
            {"line", loc_end.getSpellingLineNumber() - 1},
            {"col", loc_end.getSpellingColumnNumber()},
        }},
        {"params", j_params}
    });
}

bool ClassTemplateCallback::IsAmongTargetFiles(
    ASTContext *const ctx,
    const ClassTemplateDecl *decl
) const {
    auto file_path = ctx->getSourceManager().getFilename(decl->getLocStart()).str();
    return target_files_.find(file_path) != target_files_.end();
}

json ClassTemplateCallback::HandleParams(TemplateParameterList *params) {
    // TODO handle parameter packs
    json j_params;
    LangOptions lang_opts;
    PrintingPolicy printing_policy(lang_opts);
    printing_policy.adjustForCPlusPlus();
    for(auto p: *params) {
        json j_param;
        if(llvm::isa<NonTypeTemplateParmDecl>(p)) {
            j_param["kind"] = TemplateParameterKind::NON_TYPE;
            auto non_type_p = llvm::cast<NonTypeTemplateParmDecl>(p);
            j_param["type"] = non_type_p->getType().getAsString(printing_policy);
        } else if(llvm::isa<TemplateTypeParmDecl>(p)) {
            j_param["kind"] = TemplateParameterKind::TYPE;
        } else if(llvm::isa<TemplateTemplateParmDecl>(p)) {
            j_param["kind"] = TemplateParameterKind::TEMPLATE;
            // TODO handle
        } else {
            llvm::outs() << "warning: undexpected template parameter type\n";
        }
        j_param["name"] = p->getName();
        j_params.push_back(j_param);
    }
    return j_params;
}

}}
