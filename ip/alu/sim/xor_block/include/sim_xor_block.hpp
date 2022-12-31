#pragma once

#include <verilated.h>
#include <verilated_vcd_c.h>

#include "tb_xor_block.h"

class SimXorBlock {

public:
  SimXorBlock();
  ~SimXorBlock();
  vluint64_t get_fail_count();
  void IoTest(vluint32_t a, vluint32_t b);
  void InvertIoTest(vluint32_t a, vluint32_t b);

private:
  tb_xor_block   mDut;
  VerilatedVcdC mTrace;
  
  vluint64_t mSimTime   = 0;
  vluint64_t mTestCount = 0;
  vluint64_t mFailCount = 0;

  void tick();
};