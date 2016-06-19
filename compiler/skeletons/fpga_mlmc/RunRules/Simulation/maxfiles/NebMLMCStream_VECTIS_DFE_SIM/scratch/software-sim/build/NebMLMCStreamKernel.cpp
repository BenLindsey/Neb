#include "stdsimheader.h"
#include "NebMLMCStreamKernel.h"

namespace maxcompilersim {

NebMLMCStreamKernel::NebMLMCStreamKernel(const std::string &instance_name) : 
  ManagerBlockSync(instance_name),
  KernelManagerBlockSync(instance_name, 148, 2, 62, 0, "",1)
, c_hw_fix_1_0_uns_bits((HWOffsetFix<1,0,UNSIGNED>(varint_u<1>(0x1l))))
, c_hw_fix_32_0_uns_bits((HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(0x0000006cl))))
, c_hw_fix_33_0_uns_bits((HWOffsetFix<33,0,UNSIGNED>(varint_u<33>(0x000000000l))))
, c_hw_fix_33_0_uns_bits_1((HWOffsetFix<33,0,UNSIGNED>(varint_u<33>(0x000000001l))))
, c_hw_fix_2_0_uns_bits((HWOffsetFix<2,0,UNSIGNED>(varint_u<2>(0x2l))))
, c_hw_fix_2_0_uns_bits_1((HWOffsetFix<2,0,UNSIGNED>(varint_u<2>(0x0l))))
, c_hw_fix_2_0_uns_bits_2((HWOffsetFix<2,0,UNSIGNED>(varint_u<2>(0x1l))))
, c_hw_fix_1_0_uns_undef((HWOffsetFix<1,0,UNSIGNED>()))
, c_hw_fix_25_0_uns_bits((HWOffsetFix<25,0,UNSIGNED>(varint_u<25>(0x0000000l))))
, c_hw_fix_25_0_uns_bits_1((HWOffsetFix<25,0,UNSIGNED>(varint_u<25>(0x0000001l))))
, c_hw_fix_32_0_uns_bits_1((HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(0x00000001l))))
, c_hw_fix_32_0_uns_undef((HWOffsetFix<32,0,UNSIGNED>()))
, c_hw_fix_32_0_sgn_bits((HWOffsetFix<32,0,TWOSCOMPLEMENT>(varint_u<32>(0x00000000l))))
, c_hw_flt_8_24_bits((HWFloat<8,24>(varint_u<32>(0x3f7383c6l))))
, c_hw_flt_8_24_bits_1((HWFloat<8,24>(varint_u<32>(0x00000000l))))
, c_hw_fix_32_0_uns_bits_2((HWOffsetFix<32,0,UNSIGNED>(varint_u<32>(0x00000000l))))
, c_hw_flt_8_24_undef((HWFloat<8,24>()))
, c_hw_flt_8_24_bits_2((HWFloat<8,24>(varint_u<32>(0x42c80000l))))
, c_hw_flt_8_24_bits_3((HWFloat<8,24>(varint_u<32>(0x3d4ccccdl))))
, c_hw_flt_8_24_bits_4((HWFloat<8,24>(varint_u<32>(0x3f800000l))))
, c_hw_flt_8_24_bits_5((HWFloat<8,24>(varint_u<32>(0x3e99999al))))
, c_hw_fix_1_0_uns_bits_1((HWOffsetFix<1,0,UNSIGNED>(varint_u<1>(0x0l))))
, c_hw_flt_8_24_bits_6((HWFloat<8,24>(varint_u<32>(0x3d3851ecl))))
, c_hw_flt_8_24_bits_7((HWFloat<8,24>(varint_u<32>(0x42a00000l))))
, c_hw_fix_49_0_uns_bits((HWOffsetFix<49,0,UNSIGNED>(varint_u<49>(0x1000000000000l))))
, c_hw_fix_49_0_uns_bits_1((HWOffsetFix<49,0,UNSIGNED>(varint_u<49>(0x0000000000000l))))
, c_hw_fix_49_0_uns_bits_2((HWOffsetFix<49,0,UNSIGNED>(varint_u<49>(0x0000000000001l))))
{
  { // Node ID: 14 (NodeConstantRawBits)
    id14out_value = (c_hw_fix_1_0_uns_bits);
  }
  { // Node ID: 250 (NodeConstantRawBits)
    id250out_value = (c_hw_fix_32_0_uns_bits);
  }
  { // Node ID: 284 (NodeConstantRawBits)
    id284out_value = (c_hw_fix_2_0_uns_bits);
  }
  { // Node ID: 3 (NodeInputMappedReg)
    registerMappedRegister("N", Data(24));
  }
  { // Node ID: 4 (NodeInputMappedReg)
    registerMappedRegister("nc", Data(32));
  }
  { // Node ID: 283 (NodeConstantRawBits)
    id283out_value = (c_hw_fix_32_0_uns_bits_1);
  }
  { // Node ID: 282 (NodeConstantRawBits)
    id282out_value = (c_hw_fix_1_0_uns_bits);
  }
  { // Node ID: 281 (NodeConstantRawBits)
    id281out_value = (c_hw_fix_32_0_uns_bits_1);
  }
  { // Node ID: 150 (NodeInputMappedReg)
    registerMappedRegister("io_diff_force_disabled", Data(1));
  }
  { // Node ID: 2 (NodeInputMappedReg)
    registerMappedRegister("l", Data(32));
  }
  { // Node ID: 280 (NodeConstantRawBits)
    id280out_value = (c_hw_fix_32_0_sgn_bits);
  }
  { // Node ID: 279 (NodeConstantRawBits)
    id279out_value = (c_hw_flt_8_24_bits);
  }
  { // Node ID: 194 (NodeConstantRawBits)
    id194out_value = (c_hw_flt_8_24_bits_1);
  }
  { // Node ID: 278 (NodeConstantRawBits)
    id278out_value = (c_hw_fix_32_0_sgn_bits);
  }
  { // Node ID: 277 (NodeConstantRawBits)
    id277out_value = (c_hw_fix_32_0_uns_bits_2);
  }
  { // Node ID: 276 (NodeConstantRawBits)
    id276out_value = (c_hw_fix_1_0_uns_bits);
  }
  { // Node ID: 180 (NodeRAM)
    for(int i=0;i<16777216;i++)
      (id180sta_ram_store[(i)]) = (c_hw_flt_8_24_undef);
  }
  { // Node ID: 61 (NodeConstantRawBits)
    id61out_value = (c_hw_flt_8_24_bits_2);
  }
  { // Node ID: 275 (NodeConstantRawBits)
    id275out_value = (c_hw_flt_8_24_bits_3);
  }
  { // Node ID: 274 (NodeConstantRawBits)
    id274out_value = (c_hw_flt_8_24_bits_4);
  }
  { // Node ID: 273 (NodeConstantRawBits)
    id273out_value = (c_hw_flt_8_24_bits_5);
  }
  { // Node ID: 272 (NodeConstantRawBits)
    id272out_value = (c_hw_fix_1_0_uns_bits_1);
  }
  { // Node ID: 271 (NodeConstantRawBits)
    id271out_value = (c_hw_fix_32_0_uns_bits_1);
  }
  { // Node ID: 29 (NodeInputMappedReg)
    registerMappedRegister("io_r1_force_disabled", Data(1));
  }
  { // Node ID: 35 (NodeInput)
     m_r1 =  registerInput("r1",0,5);
  }
  { // Node ID: 270 (NodeConstantRawBits)
    id270out_value = (c_hw_flt_8_24_bits_6);
  }
  { // Node ID: 269 (NodeConstantRawBits)
    id269out_value = (c_hw_flt_8_24_bits_3);
  }
  { // Node ID: 268 (NodeConstantRawBits)
    id268out_value = (c_hw_flt_8_24_bits_5);
  }
  { // Node ID: 267 (NodeConstantRawBits)
    id267out_value = (c_hw_fix_1_0_uns_bits_1);
  }
  { // Node ID: 266 (NodeConstantRawBits)
    id266out_value = (c_hw_fix_32_0_uns_bits_1);
  }
  { // Node ID: 45 (NodeInputMappedReg)
    registerMappedRegister("io_r2_force_disabled", Data(1));
  }
  { // Node ID: 51 (NodeInput)
     m_r2 =  registerInput("r2",1,5);
  }
  { // Node ID: 265 (NodeConstantRawBits)
    id265out_value = (c_hw_flt_8_24_bits_6);
  }
  { // Node ID: 264 (NodeConstantRawBits)
    id264out_value = (c_hw_flt_8_24_bits_7);
  }
  { // Node ID: 263 (NodeConstantRawBits)
    id263out_value = (c_hw_flt_8_24_bits);
  }
  { // Node ID: 262 (NodeConstantRawBits)
    id262out_value = (c_hw_fix_32_0_uns_bits_2);
  }
  { // Node ID: 261 (NodeConstantRawBits)
    id261out_value = (c_hw_fix_1_0_uns_bits);
  }
  { // Node ID: 181 (NodeRAM)
    for(int i=0;i<16777216;i++)
      (id181sta_ram_store[(i)]) = (c_hw_flt_8_24_undef);
  }
  { // Node ID: 65 (NodeConstantRawBits)
    id65out_value = (c_hw_flt_8_24_bits_2);
  }
  { // Node ID: 260 (NodeConstantRawBits)
    id260out_value = (c_hw_flt_8_24_bits_3);
  }
  { // Node ID: 259 (NodeConstantRawBits)
    id259out_value = (c_hw_flt_8_24_bits_4);
  }
  { // Node ID: 258 (NodeConstantRawBits)
    id258out_value = (c_hw_flt_8_24_bits_5);
  }
  { // Node ID: 257 (NodeConstantRawBits)
    id257out_value = (c_hw_flt_8_24_bits_6);
  }
  { // Node ID: 256 (NodeConstantRawBits)
    id256out_value = (c_hw_flt_8_24_bits_7);
  }
  { // Node ID: 156 (NodeOutput)
    m_diff = registerOutput("diff",0 );
  }
  { // Node ID: 255 (NodeConstantRawBits)
    id255out_value = (c_hw_fix_32_0_uns_bits_1);
  }
  { // Node ID: 254 (NodeConstantRawBits)
    id254out_value = (c_hw_fix_1_0_uns_bits);
  }
  { // Node ID: 253 (NodeConstantRawBits)
    id253out_value = (c_hw_fix_32_0_uns_bits_1);
  }
  { // Node ID: 173 (NodeInputMappedReg)
    registerMappedRegister("io_fine_force_disabled", Data(1));
  }
  { // Node ID: 179 (NodeOutput)
    m_fine = registerOutput("fine",1 );
  }
  { // Node ID: 186 (NodeConstantRawBits)
    id186out_value = (c_hw_fix_1_0_uns_bits);
  }
  { // Node ID: 252 (NodeConstantRawBits)
    id252out_value = (c_hw_fix_1_0_uns_bits);
  }
  { // Node ID: 183 (NodeConstantRawBits)
    id183out_value = (c_hw_fix_49_0_uns_bits);
  }
  { // Node ID: 187 (NodeOutputMappedReg)
    registerMappedRegister("current_run_cycle_count", Data(48));
  }
  { // Node ID: 251 (NodeConstantRawBits)
    id251out_value = (c_hw_fix_1_0_uns_bits);
  }
  { // Node ID: 189 (NodeConstantRawBits)
    id189out_value = (c_hw_fix_49_0_uns_bits);
  }
  { // Node ID: 192 (NodeInputMappedReg)
    registerMappedRegister("run_cycle_count", Data(48));
  }
}

void NebMLMCStreamKernel::resetComputation() {
  resetComputationAfterFlush();
}

void NebMLMCStreamKernel::resetComputationAfterFlush() {
  { // Node ID: 19 (NodeCounterV1)

    (id19st_count) = (c_hw_fix_33_0_uns_bits);
  }
  { // Node ID: 18 (NodeCounterV1)

    (id18st_count) = (c_hw_fix_2_0_uns_bits_1);
  }
  { // Node ID: 203 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id203out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 3 (NodeInputMappedReg)
    id3out_N = getMappedRegValue<HWOffsetFix<24,0,UNSIGNED> >("N");
  }
  { // Node ID: 16 (NodeCounterV1)
    const HWOffsetFix<24,0,UNSIGNED> &id16in_max = id3out_N;

    (id16st_count) = (c_hw_fix_25_0_uns_bits);
  }
  { // Node ID: 4 (NodeInputMappedReg)
    id4out_nc = getMappedRegValue<HWOffsetFix<32,0,UNSIGNED> >("nc");
  }
  { // Node ID: 15 (NodeCounterV1)
    const HWOffsetFix<32,0,UNSIGNED> &id15in_max = id4out_nc;

    (id15st_count) = (c_hw_fix_33_0_uns_bits);
  }
  { // Node ID: 204 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id204out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 205 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id205out_output[i] = (c_hw_fix_32_0_uns_undef);
    }
  }
  { // Node ID: 206 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id206out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 150 (NodeInputMappedReg)
    id150out_io_diff_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_diff_force_disabled");
  }
  { // Node ID: 239 (NodeFIFO)

    for(int i=0; i<142; i++)
    {
      id239out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 2 (NodeInputMappedReg)
    id2out_l = getMappedRegValue<HWOffsetFix<32,0,TWOSCOMPLEMENT> >("l");
  }
  { // Node ID: 207 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id207out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 209 (NodeFIFO)

    for(int i=0; i<13; i++)
    {
      id209out_output[i] = (c_hw_flt_8_24_undef);
    }
  }
  { // Node ID: 244 (NodeFIFO)

    for(int i=0; i<5; i++)
    {
      id244out_output[i] = (c_hw_flt_8_24_undef);
    }
  }
  { // Node ID: 29 (NodeInputMappedReg)
    id29out_io_r1_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_r1_force_disabled");
  }
  { // Node ID: 35 (NodeInput)

    (id35st_read_next_cycle) = (c_hw_fix_1_0_uns_bits_1);
    (id35st_last_read_value) = (c_hw_flt_8_24_undef);
  }
  { // Node ID: 212 (NodeFIFO)

    for(int i=0; i<9; i++)
    {
      id212out_output[i] = (c_hw_flt_8_24_undef);
    }
  }
  { // Node ID: 214 (NodeFIFO)

    for(int i=0; i<9; i++)
    {
      id214out_output[i] = (c_hw_flt_8_24_undef);
    }
  }
  { // Node ID: 216 (NodeFIFO)

    for(int i=0; i<5; i++)
    {
      id216out_output[i] = (c_hw_flt_8_24_undef);
    }
  }
  { // Node ID: 245 (NodeFIFO)

    for(int i=0; i<13; i++)
    {
      id245out_output[i] = (c_hw_flt_8_24_undef);
    }
  }
  { // Node ID: 45 (NodeInputMappedReg)
    id45out_io_r2_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_r2_force_disabled");
  }
  { // Node ID: 219 (NodeFIFO)

    for(int i=0; i<9; i++)
    {
      id219out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 51 (NodeInput)

    (id51st_read_next_cycle) = (c_hw_fix_1_0_uns_bits_1);
    (id51st_last_read_value) = (c_hw_flt_8_24_undef);
  }
  { // Node ID: 220 (NodeFIFO)

    for(int i=0; i<45; i++)
    {
      id220out_output[i] = (c_hw_flt_8_24_undef);
    }
  }
  { // Node ID: 221 (NodeFIFO)

    for(int i=0; i<9; i++)
    {
      id221out_output[i] = (c_hw_flt_8_24_undef);
    }
  }
  { // Node ID: 246 (NodeFIFO)

    for(int i=0; i<9; i++)
    {
      id246out_output[i] = (c_hw_flt_8_24_undef);
    }
  }
  { // Node ID: 247 (NodeFIFO)

    for(int i=0; i<29; i++)
    {
      id247out_output[i] = (c_hw_flt_8_24_undef);
    }
  }
  { // Node ID: 226 (NodeFIFO)

    for(int i=0; i<3; i++)
    {
      id226out_output[i] = (c_hw_flt_8_24_undef);
    }
  }
  { // Node ID: 228 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id228out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 229 (NodeFIFO)

    for(int i=0; i<13; i++)
    {
      id229out_output[i] = (c_hw_flt_8_24_undef);
    }
  }
  { // Node ID: 248 (NodeFIFO)

    for(int i=0; i<13; i++)
    {
      id248out_output[i] = (c_hw_flt_8_24_undef);
    }
  }
  { // Node ID: 249 (NodeFIFO)

    for(int i=0; i<5; i++)
    {
      id249out_output[i] = (c_hw_flt_8_24_undef);
    }
  }
  { // Node ID: 235 (NodeFIFO)

    for(int i=0; i<9; i++)
    {
      id235out_output[i] = (c_hw_flt_8_24_undef);
    }
  }
  { // Node ID: 234 (NodeFIFO)

    for(int i=0; i<17; i++)
    {
      id234out_output[i] = (c_hw_flt_8_24_undef);
    }
  }
  { // Node ID: 227 (NodeFIFO)

    for(int i=0; i<34; i++)
    {
      id227out_output[i] = (c_hw_flt_8_24_undef);
    }
  }
  { // Node ID: 237 (NodeFIFO)

    for(int i=0; i<3; i++)
    {
      id237out_output[i] = (c_hw_flt_8_24_undef);
    }
  }
  { // Node ID: 238 (NodeFIFO)

    for(int i=0; i<13; i++)
    {
      id238out_output[i] = (c_hw_flt_8_24_undef);
    }
  }
  { // Node ID: 242 (NodeFIFO)

    for(int i=0; i<2; i++)
    {
      id242out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 173 (NodeInputMappedReg)
    id173out_io_fine_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_fine_force_disabled");
  }
  { // Node ID: 243 (NodeFIFO)

    for(int i=0; i<129; i++)
    {
      id243out_output[i] = (c_hw_fix_1_0_uns_undef);
    }
  }
  { // Node ID: 184 (NodeCounterV1)

    (id184st_count) = (c_hw_fix_49_0_uns_bits_1);
  }
  { // Node ID: 190 (NodeCounterV1)

    (id190st_count) = (c_hw_fix_49_0_uns_bits_1);
  }
  { // Node ID: 192 (NodeInputMappedReg)
    id192out_run_cycle_count = getMappedRegValue<HWOffsetFix<48,0,UNSIGNED> >("run_cycle_count");
  }
}

void NebMLMCStreamKernel::updateState() {
  { // Node ID: 3 (NodeInputMappedReg)
    id3out_N = getMappedRegValue<HWOffsetFix<24,0,UNSIGNED> >("N");
  }
  { // Node ID: 4 (NodeInputMappedReg)
    id4out_nc = getMappedRegValue<HWOffsetFix<32,0,UNSIGNED> >("nc");
  }
  { // Node ID: 150 (NodeInputMappedReg)
    id150out_io_diff_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_diff_force_disabled");
  }
  { // Node ID: 2 (NodeInputMappedReg)
    id2out_l = getMappedRegValue<HWOffsetFix<32,0,TWOSCOMPLEMENT> >("l");
  }
  { // Node ID: 29 (NodeInputMappedReg)
    id29out_io_r1_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_r1_force_disabled");
  }
  { // Node ID: 45 (NodeInputMappedReg)
    id45out_io_r2_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_r2_force_disabled");
  }
  { // Node ID: 173 (NodeInputMappedReg)
    id173out_io_fine_force_disabled = getMappedRegValue<HWOffsetFix<1,0,UNSIGNED> >("io_fine_force_disabled");
  }
  { // Node ID: 192 (NodeInputMappedReg)
    id192out_run_cycle_count = getMappedRegValue<HWOffsetFix<48,0,UNSIGNED> >("run_cycle_count");
  }
}

void NebMLMCStreamKernel::preExecute() {
  { // Node ID: 35 (NodeInput)
    if(((needsToReadInput(m_r1))&(((getFlushLevel())<((6l)+(5)))|(!(isFlushingActive()))))) {
      (id35st_last_read_value) = (readInput<HWFloat<8,24> >(m_r1));
    }
    id35out_data = (id35st_last_read_value);
  }
  { // Node ID: 51 (NodeInput)
    if(((needsToReadInput(m_r2))&(((getFlushLevel())<((14l)+(5)))|(!(isFlushingActive()))))) {
      (id51st_last_read_value) = (readInput<HWFloat<8,24> >(m_r2));
    }
    id51out_data = (id51st_last_read_value);
  }
}

void NebMLMCStreamKernel::runComputationCycle() {
  if (m_mappedElementsChanged) {
    m_mappedElementsChanged = false;
    updateState();
    std::cout << "NebMLMCStreamKernel: Mapped Elements Changed: Reloaded" << std::endl;
  }
  preExecute();
  execute0();
}

int NebMLMCStreamKernel::getFlushLevelStart() {
  return ((1l)+(3l));
}

}
