#include "gtest/gtest.h"
#include "test_common.h"

#include <vector>
#include <utility>

#include "template_finder.h"

using std::vector;
using std::make_pair;

TEST(find_class_template, should_handle_simple_template) {
    auto res = FindTemplates({"data/simple_class_template.h"}, TestCommon::TestCompilations);
    ASSERT_EQ(res.size(), 1u);
    ASSERT_EQ(res[0].template_start, make_pair(3, 1));
    ASSERT_EQ(res[0].param_list_end, make_pair(10, 1));
}

TEST(find_class_template, should_handle_multiple_templates) {
    auto res = FindTemplates({"data/multiple_class_templates.h"}, TestCommon::TestCompilations);
    ASSERT_EQ(res.size(), 3u);
    ASSERT_EQ(res[0].template_start, make_pair(1, 1));
    ASSERT_EQ(res[0].param_list_end, make_pair(1, 17));
    ASSERT_EQ(res[1].template_start, make_pair(4, 1));
    ASSERT_EQ(res[1].param_list_end, make_pair(4, 17));
    ASSERT_EQ(res[2].template_start, make_pair(7, 1));
    ASSERT_EQ(res[2].param_list_end, make_pair(7, 25));
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
