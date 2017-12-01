/// @file
///
/// Day 1: Inverse Captcha
///

#include <iostream>
#include <string>
#include <vector>

#include "advent/days/01/inverse_captcha.hh"
#include "advent/utils/assert.hh"
#include "advent/utils/tests.hh"

namespace advent {

namespace {
	const std::string one_input = "4947511368953458947325823626295765395991842961953181626646951893"
		"933643725857788685121948639276527881497797486579893186459362218877315427185626432726838626"
		"275373786248436148313374416597412812896387651714525764663813145588216365953949817885886734"
		"437693435978518839556688181657231749398938416549145566813241336674464121385117244242923944"
		"541666236398724251686443362482172138263397412675468237793833433627895274615795658229668593"
		"497779379219336949123695521527727351678327625637196643154569871867135411537814996461782387"
		"626441864843811422499261947437131392625962648784586365958964873626586722243462413586672341"
		"159745286265236483119198865664978372171696739239351433868237572931487193778215173146298128"
		"869124128299244845134938856723439641512524336223411416615238144659915169616845119414715728"
		"954537116249862693423987861758469257839186868564426844898733274976989636588628563366824227"
		"975512514891266619548485722972287654456467452564996794514263588654778444674585339629818522"
		"925133588714833211619735832456987635315983954676755291814969111177698341275164413692612752"
		"442259788936174565243855184931122721697677758612566497282537549646758125345462262955359396"
		"973521412173373467385534956168327837578669281745191453572348345847882538936185494843857332"
		"836271994453696583391756444848593858845749432192679227299675719438437945657369757161747278"
		"523484412544928867943629343438686433378286374542775822769623532463578354933383722198243715"
		"175264742835417148979941278644614336278948312686593362642344368727153747272117641677391693"
		"419995738556277751148482752687391592725186733167536729952978887348443889284398593599924756"
		"374397712692329165423858767796166951294123667351125936697193357835113557738146854918767214"
		"529947143188637165424731872463515486261577751433331614228679244375262538658599699473669728"
		"956749668459932449252187669375434878754856473299952858217393593699989353319861268737267376"
		"721592658275664437945157559398136761947554744772241521399879444194633713864998414152277346"
		"737335552615438713597977965298478617489795275799857579647426674737672692483352298368182974"
		"77665453189662485548925521497365877771665365728224394427883312135322325169141784";

	const std::vector<TestData> part_one_tests {
		{"1122", 3},
		{"1111", 4},
		{"1234", 0},
		{"91212129", 9},
	};

	const std::vector<TestData> part_two_tests {
		{"1212", 6},
		{"1221", 0},
		{"123425", 4},
		{"123123", 12},
		{"12131415", 4},
	};
}

// Override.
void Day01::solve_part_one() {
	std::cout << part_one()
			<< solve_for_input(one_input)
		<< std::endl;
}

void Day01::solve_part_two() {
	std::cout << part_two()
			<< solve_for_input(one_input, one_input.length() >> 1)
		<< std::endl;
}

bool Day01::test_part_one() {
	for (const auto& [input, expected] : part_one_tests) {
		TEST_EQ(input, solve_for_input(input), expected);
	}
	return true;
}

bool Day01::test_part_two() {
	for (const auto& [input, expected] : part_two_tests) {
		auto distance = input.length() >> 1;
		TEST_EQ(input, solve_for_input(input, distance), expected);
	}
	return false;
}

int Day01::solve_for_input(const std::string& input, int distance) {
	if (input.length() <= 1) {
		LOG_MSG("too short input");
		return -1;
	}

	int sum = 0;
	int length = input.length();
	for (int i = 0; i < length; ++i) {
		if (input[i] == input[(i+distance)%length]) {
			sum += (input[i] - '0');
		}
	}

	return sum;
}

}
