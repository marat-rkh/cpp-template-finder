#include "class_template_handler.h"

using clang::ast_matchers::DeclarationMatcher;
using clang::ast_matchers::classTemplateDecl;

const DeclarationMatcher ClassTemplateHandler::Matcher =
    classTemplateDecl().bind("class-template");

ClassTemplateCallback ClassTemplateHandler::CreateCallback() {
    return ClassTemplateCallback("class-template");
}
