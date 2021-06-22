#include "Valu.h"
#include <verilated.h>

enum class ALU_OPS {
	NOP,
	ADD,
	SUB,
	MUL,
	DIV,
	SQRT
};

template<typename NumberSystemType>
NumberSystemType ArithmeticLogicUnit(ALU_OPS op, const NumberSystemType& a, const NumberSystemType& b) {
	using namespace sw::universal;
    Valu *tb = new Valu;

	NumberSystemType c;
	switch (op) {
	default:
	case ALU_OPS::NOP:
        tb->aluop=2;
        tb->a=(uint32_t)a;
        tb->b=(uint32_t)b;
        tb->eval();
        c = tb->f;
		break;
	case ALU_OPS::ADD:
        tb->aluop=0;
        tb->a=(uint32_t)a;
        tb->b=(uint32_t)b;
        tb->eval();
        c = tb->f;
		break;
	case ALU_OPS::SUB:
        tb->aluop=1;
        tb->a=(uint32_t)a;
        tb->b=(uint32_t)b;
        tb->eval();
        c = tb->f;
		break;
	}
	return c;
}



