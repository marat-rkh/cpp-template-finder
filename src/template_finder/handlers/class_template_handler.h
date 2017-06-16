#ifndef __CLASS_TEMPLATE_HANDLER_H__
#define __CLASS_TEMPLATE_HANDLER_H__

#include <string>

#include "clang/ASTMatchers/ASTMatchers.h"

#include "class_template_callback.h"

namespace template_finder { namespace handlers {

class ClassTemplateHandler {
public:
    static const clang::ast_matchers::DeclarationMatcher Matcher;
    static ClassTemplateCallback CreateCallback();
};

}}

#endif
