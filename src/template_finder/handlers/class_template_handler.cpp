#include "class_template_handler.h"

using clang::ast_matchers::DeclarationMatcher;
using clang::ast_matchers::classTemplateDecl;

namespace template_finder { namespace handlers {

const DeclarationMatcher ClassTemplateHandler::Matcher =
    classTemplateDecl().bind("class-template");

ClassTemplateCallback ClassTemplateHandler::CreateCallback() {
    return ClassTemplateCallback("class-template");
}

}}
