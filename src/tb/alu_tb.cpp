#include <stdlib.h>
#include <iostream>
#include <string>
#include <universal/number/integer/integer.hpp>
#include "alu.hpp"
#include "Valu.h"
#include <verilated.h>

#include <universal/verification/test_status.hpp> // ReportTestResult

int main(int argc, char** argv)
try {
	using namespace std;
	using namespace sw::universal;

	if (argc != 4) {
		std::cerr << "Usage: hw_int [add | sub | mul | div | sqrt] a b\n";
		std::cerr << "Example: hw_int add 1.5 -1.5\n";
		return EXIT_SUCCESS;  // needed for regression test success
	}
	string op = argv[1];
	float fa = atof(argv[2]);
	float fb = atof(argv[3]);
	cout << op << " " << fa << " and " << fb << '\n';

	integer<8> a, b, c;
	a = fa;
	b = fb;

	// decode the operation
	ALU_OPS alu_op;
	if (op == "add") {
		alu_op = ALU_OPS::ADD;
		c = ArithmeticLogicUnit(alu_op, a, b);
		cout << a << " + " << b << " = " << c << '\n';
		cout << to_binary(a, true) << " + " << to_binary(b, true) << " = " << to_binary(c, true) << '\n';
	}
	else if (op == "sub") {
		alu_op = ALU_OPS::SUB;
		c = ArithmeticLogicUnit(alu_op, a, b);
		cout << a << " - " << b << " = " << c << '\n';
		cout << to_binary(a, true) << " - " << to_binary(b, true) << " = " << to_binary(c, true) << '\n';
	}
	return EXIT_SUCCESS;
}
catch (char const* msg) {
	std::cerr << msg << std::endl;
	return EXIT_FAILURE;
}
catch (...) {
	std::cerr << "Caught unknown exception" << std::endl;
	return EXIT_FAILURE;
}
