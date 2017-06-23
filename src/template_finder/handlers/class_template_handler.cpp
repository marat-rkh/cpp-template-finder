#include "class_template_handler.h"

using std::vector;
using std::string;

using clang::ast_matchers::DeclarationMatcher;
using clang::ast_matchers::classTemplateDecl;

namespace template_finder { namespace handlers {

const DeclarationMatcher ClassTemplateHandler::Matcher =
    classTemplateDecl().bind("class-template");

ClassTemplateCallback ClassTemplateHandler::CreateCallback(const vector<string> &target_files) {
    return ClassTemplateCallback(target_files, "class-template");
}

}}
