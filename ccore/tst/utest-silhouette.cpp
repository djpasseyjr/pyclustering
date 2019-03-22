/**
*
* @authors Andrei Novikov (pyclustering@yandex.ru)
* @date 2014-2019
* @copyright GNU Public License
*
* GNU_PUBLIC_LICENSE
*   pyclustering is free software: you can redistribute it and/or modify
*   it under the terms of the GNU General Public License as published by
*   the Free Software Foundation, either version 3 of the License, or
*   (at your option) any later version.
*
*   pyclustering is distributed in the hope that it will be useful,
*   but WITHOUT ANY WARRANTY; without even the implied warranty of
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*   GNU General Public License for more details.
*
*   You should have received a copy of the GNU General Public License
*   along with this program.  If not, see <http://www.gnu.org/licenses/>.
*
*/


#include "gtest/gtest.h"

#include "answer.hpp"
#include "answer_reader.hpp"
#include "samples.hpp"

#include "cluster/silhouette.hpp"


using namespace ccore::clst;


static void template_correct_scores(const dataset_ptr & p_data, const answer & p_answer) {
    silhouette_data result;
    silhouette().process(*p_data, p_answer.clusters(), result);

    ASSERT_EQ(p_data->size(), result.get_score().size());
    for (const auto score : result.get_score()) {
        ASSERT_LE(-1.0, score);
        ASSERT_GE(1.0, score);
    }
}


TEST(utest_silhouette, correct_score_simple01) {
    template_correct_scores(simple_sample_factory::create_sample(SAMPLE_SIMPLE::SAMPLE_SIMPLE_01), answer_reader::read(SAMPLE_SIMPLE::SAMPLE_SIMPLE_01));
}

TEST(utest_silhouette, correct_score_simple02) {
    template_correct_scores(simple_sample_factory::create_sample(SAMPLE_SIMPLE::SAMPLE_SIMPLE_02), answer_reader::read(SAMPLE_SIMPLE::SAMPLE_SIMPLE_02));
}

TEST(utest_silhouette, correct_score_simple03) {
    template_correct_scores(simple_sample_factory::create_sample(SAMPLE_SIMPLE::SAMPLE_SIMPLE_03), answer_reader::read(SAMPLE_SIMPLE::SAMPLE_SIMPLE_03));
}

TEST(utest_silhouette, correct_score_simple04) {
    template_correct_scores(simple_sample_factory::create_sample(SAMPLE_SIMPLE::SAMPLE_SIMPLE_04), answer_reader::read(SAMPLE_SIMPLE::SAMPLE_SIMPLE_04));
}

TEST(utest_silhouette, correct_score_simple05) {
    template_correct_scores(simple_sample_factory::create_sample(SAMPLE_SIMPLE::SAMPLE_SIMPLE_05), answer_reader::read(SAMPLE_SIMPLE::SAMPLE_SIMPLE_05));
}

TEST(utest_silhouette, correct_score_simple06) {
    template_correct_scores(simple_sample_factory::create_sample(SAMPLE_SIMPLE::SAMPLE_SIMPLE_06), answer_reader::read(SAMPLE_SIMPLE::SAMPLE_SIMPLE_06));
}

TEST(utest_silhouette, correct_score_simple07) {
    template_correct_scores(simple_sample_factory::create_sample(SAMPLE_SIMPLE::SAMPLE_SIMPLE_07), answer_reader::read(SAMPLE_SIMPLE::SAMPLE_SIMPLE_07));
}

TEST(utest_silhouette, correct_score_simple08) {
    template_correct_scores(simple_sample_factory::create_sample(SAMPLE_SIMPLE::SAMPLE_SIMPLE_08), answer_reader::read(SAMPLE_SIMPLE::SAMPLE_SIMPLE_08));
}
