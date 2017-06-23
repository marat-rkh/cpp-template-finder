#include "gtest/gtest.h"
#include "test_common.h"

#include <vector>
#include <utility>

#include "3rd_party/json.hpp"

#include "template_finder.h"
#include "json_format.h"

using std::vector;
using std::make_pair;
using json = nlohmann::json;
using template_finder::FindTemplates;
using template_finder::TemplateKind;
using template_finder::TemplateParameterKind;

void assertHasEntries(const vector<json> &actual, const vector<json> &expected) {
    ASSERT_EQ(actual.size(), expected.size());
    for(decltype(actual.size()) i = 0; i < actual.size(); ++i) {
        if(expected[i].find("kind") != expected[i].end()) {
            ASSERT_TRUE(actual[i]["kind"] == expected[i]["kind"]);
        }
        if(expected[i].find("beg") != expected[i].end()) {
            ASSERT_TRUE(actual[i]["beg"] == expected[i]["beg"]);
        }
        if(expected[i].find("end") != expected[i].end()) {
            ASSERT_TRUE(actual[i]["end"] == expected[i]["end"]);
        }
        if(expected[i].find("params") != expected[i].end()) {
            ASSERT_TRUE(actual[i]["params"] == expected[i]["params"]);
        }
    }
}

TEST(find_class_template, should_handle_simple_template) {
    auto data = FindTemplates({"data/simple_class_template.h"}, TestCommon::TestCompilations);
    vector<json> expected = {
        {
            {"kind", TemplateKind::CLASS_TEMPLATE},
            {"beg", { {"line", 2}, {"col", 0} }},
            {"end", { {"line", 9}, {"col", 1} }},
            {"params", json::array({
                { {"kind", TemplateParameterKind::TYPE}, {"name", "A"} },
                { {"kind", TemplateParameterKind::TYPE}, {"name", "B"} },
                { {"kind", TemplateParameterKind::NON_TYPE}, {"type", "int"}, {"name", "N"} },
                { {"kind", TemplateParameterKind::TEMPLATE}, {"name", "TT"} },
                { {"kind", TemplateParameterKind::TYPE}, {"name", "C"} },
                { {"kind", TemplateParameterKind::TYPE}, {"name", ""} }
            })}
        }
    };
    assertHasEntries(data.class_templates, expected);
}

TEST(find_class_template, should_handle_multiple_templates) {
    auto data = FindTemplates({"data/multiple_class_templates.h"}, TestCommon::TestCompilations);
    vector<json> expected = {
        {
            {"kind", TemplateKind::CLASS_TEMPLATE},
            {"beg", { {"line", 0}, {"col", 0} }},
            {"end", { {"line", 0}, {"col", 17} }},
            {"params", json::array({
                { {"kind", TemplateParameterKind::TYPE}, {"name", "T"} }
            })}
        }, {
            {"kind", TemplateKind::CLASS_TEMPLATE},
            {"beg", { {"line", 3}, {"col", 0} }},
            {"end", { {"line", 3}, {"col", 17} }},
            {"params", json::array({
                { {"kind", TemplateParameterKind::TYPE}, {"name", "T"} }
            })}
        }, {
            {"kind", TemplateKind::CLASS_TEMPLATE},
            {"beg", { {"line", 6}, {"col", 0} }},
            {"end", { {"line", 6}, {"col", 25} }},
            {"params", json::array({
                { {"kind", TemplateParameterKind::TYPE}, {"name", "T"} },
                { {"kind", TemplateParameterKind::NON_TYPE}, {"type", "bool"}, {"name", "B"} }
            })}
        }
    };
    assertHasEntries(data.class_templates, expected);
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
