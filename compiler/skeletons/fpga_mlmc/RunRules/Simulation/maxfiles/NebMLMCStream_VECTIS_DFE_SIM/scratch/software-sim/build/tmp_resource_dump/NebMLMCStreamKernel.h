#ifndef NEBMLMCSTREAMKERNEL_H_
#define NEBMLMCSTREAMKERNEL_H_

// #include "KernelManagerBlockSync.h"


namespace maxcompilersim {

class NebMLMCStreamKernel : public KernelManagerBlockSync {
public:
  NebMLMCStreamKernel(const std::string &instance_name);

protected:
  virtual void runComputationCycle();
  virtual void resetComputation();
  virtual void resetComputationAfterFlush();
          void updateState();
          void preExecute();
  virtual int  getFlushLevelStart();

private:
  t_port_number m_r1;
  t_port_number m_r2;
  t_port_number m_diff;
  t_port_number m_fine;
  HWOffsetFix<1,0,UNSIGNED> id14out_value;

  HWOffsetFix<32,0,UNSIGNED> id250out_value;

  HWOffsetFix<32,0,UNSIGNED> id19out_count;
  HWOffsetFix<1,0,UNSIGNED> id19out_wrap;

  HWOffsetFix<33,0,UNSIGNED> id19st_count;

  HWOffsetFix<2,0,UNSIGNED> id284out_value;

  HWOffsetFix<1,0,UNSIGNED> id18out_count;
  HWOffsetFix<1,0,UNSIGNED> id18out_wrap;

  HWOffsetFix<2,0,UNSIGNED> id18st_count;

  HWOffsetFix<1,0,UNSIGNED> id203out_output[2];

  HWOffsetFix<24,0,UNSIGNED> id3out_N;

  HWOffsetFix<24,0,UNSIGNED> id16out_count;
  HWOffsetFix<1,0,UNSIGNED> id16out_wrap;

  HWOffsetFix<25,0,UNSIGNED> id16st_count;

  HWOffsetFix<32,0,UNSIGNED> id4out_nc;

  HWOffsetFix<32,0,UNSIGNED> id15out_count;
  HWOffsetFix<1,0,UNSIGNED> id15out_wrap;

  HWOffsetFix<33,0,UNSIGNED> id15st_count;

  HWOffsetFix<32,0,UNSIGNED> id283out_value;

  HWOffsetFix<32,0,UNSIGNED> id135out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id136out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id204out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id282out_value;

  HWOffsetFix<1,0,UNSIGNED> id138out_result[2];

  HWRawBits<1> id139out_result[2];

  HWOffsetFix<32,0,UNSIGNED> id205out_output[2];

  HWOffsetFix<32,0,UNSIGNED> id281out_value;

  HWOffsetFix<32,0,UNSIGNED> id144out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id145out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id206out_output[2];

  HWRawBits<1> id146out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id150out_io_diff_force_disabled;

  HWOffsetFix<1,0,UNSIGNED> id239out_output[142];

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id2out_l;

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id280out_value;

  HWOffsetFix<1,0,UNSIGNED> id131out_result[2];

  HWFloat<8,24> id279out_value;

  HWFloat<8,24> id194out_value;

  HWOffsetFix<32,0,TWOSCOMPLEMENT> id278out_value;

  HWOffsetFix<1,0,UNSIGNED> id82out_result[2];

  HWOffsetFix<32,0,UNSIGNED> id277out_value;

  HWOffsetFix<1,0,UNSIGNED> id60out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id207out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id276out_value;

  HWOffsetFix<1,0,UNSIGNED> id114out_result[2];

  HWFloat<8,24> id180out_doutb[3];

  HWFloat<8,24> id180sta_ram_store[16777216];

  std::string format_string_NebMLMCStreamKernel_1 (const char* _format_arg_format_string);
  HWFloat<8,24> id61out_value;

  HWFloat<8,24> id62out_result[2];

  HWFloat<8,24> id209out_output[13];

  HWFloat<8,24> id244out_output[5];

  HWFloat<8,24> id275out_value;

  HWFloat<8,24> id68out_result[9];

  HWFloat<8,24> id274out_value;

  HWFloat<8,24> id7out_o[7];

  HWFloat<8,24> id9out_result[29];

  HWFloat<8,24> id69out_result[9];

  HWFloat<8,24> id70out_result[13];

  HWFloat<8,24> id273out_value;

  HWFloat<8,24> id72out_result[9];

  HWOffsetFix<1,0,UNSIGNED> id272out_value;

  HWOffsetFix<1,0,UNSIGNED> id21out_result[2];

  HWOffsetFix<32,0,UNSIGNED> id271out_value;

  HWOffsetFix<32,0,UNSIGNED> id23out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id24out_result[2];

  HWRawBits<1> id25out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id29out_io_r1_force_disabled;

  HWFloat<8,24> id35out_data;

  HWOffsetFix<1,0,UNSIGNED> id35st_read_next_cycle;
  HWFloat<8,24> id35st_last_read_value;

  HWFloat<8,24> id52out_result[29];

  HWFloat<8,24> id54out_result[9];

  HWFloat<8,24> id212out_output[9];

  HWFloat<8,24> id73out_result[9];

  HWFloat<8,24> id74out_result[13];

  HWFloat<8,24> id270out_value;

  HWFloat<8,24> id76out_result[9];

  HWFloat<8,24> id214out_output[9];

  HWFloat<8,24> id77out_result[9];

  HWFloat<8,24> id78out_result[13];

  HWFloat<8,24> id79out_result[9];

  HWFloat<8,24> id80out_result[13];

  HWFloat<8,24> id216out_output[5];

  HWFloat<8,24> id245out_output[13];

  HWFloat<8,24> id269out_value;

  HWFloat<8,24> id84out_result[9];

  HWFloat<8,24> id85out_result[9];

  HWFloat<8,24> id86out_result[13];

  HWFloat<8,24> id268out_value;

  HWFloat<8,24> id88out_result[9];

  HWOffsetFix<1,0,UNSIGNED> id267out_value;

  HWOffsetFix<1,0,UNSIGNED> id37out_result[2];

  HWOffsetFix<32,0,UNSIGNED> id266out_value;

  HWOffsetFix<32,0,UNSIGNED> id39out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id40out_result[2];

  HWRawBits<1> id41out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id45out_io_r2_force_disabled;

  HWOffsetFix<1,0,UNSIGNED> id219out_output[9];

  HWFloat<8,24> id51out_data;

  HWOffsetFix<1,0,UNSIGNED> id51st_read_next_cycle;
  HWFloat<8,24> id51st_last_read_value;

  HWFloat<8,24> id55out_result[29];

  HWFloat<8,24> id57out_result[9];

  HWFloat<8,24> id220out_output[45];

  HWFloat<8,24> id89out_result[9];

  HWFloat<8,24> id221out_output[9];

  HWFloat<8,24> id90out_result[13];

  HWFloat<8,24> id265out_value;

  HWFloat<8,24> id246out_output[9];

  HWFloat<8,24> id92out_result[9];

  HWFloat<8,24> id93out_result[9];

  HWFloat<8,24> id94out_result[13];

  HWFloat<8,24> id95out_result[9];

  HWFloat<8,24> id96out_result[13];

  HWFloat<8,24> id247out_output[29];

  HWFloat<8,24> id97out_result[2];

  HWFloat<8,24> id264out_value;

  HWFloat<8,24> id119out_result[13];

  HWOffsetFix<1,0,UNSIGNED> id120out_result[3];

  HWFloat<8,24> id226out_output[3];

  HWFloat<8,24> id121out_result[2];

  HWFloat<8,24> id123out_result[9];

  HWFloat<8,24> id263out_value;

  HWOffsetFix<32,0,UNSIGNED> id262out_value;

  HWOffsetFix<1,0,UNSIGNED> id64out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id228out_output[2];

  HWOffsetFix<1,0,UNSIGNED> id261out_value;

  HWOffsetFix<1,0,UNSIGNED> id117out_result[2];

  HWFloat<8,24> id181out_doutb[3];

  HWFloat<8,24> id181sta_ram_store[16777216];

  std::string format_string_NebMLMCStreamKernel_2 (const char* _format_arg_format_string);
  HWFloat<8,24> id65out_value;

  HWFloat<8,24> id66out_result[2];

  HWFloat<8,24> id229out_output[13];

  HWFloat<8,24> id248out_output[13];

  HWFloat<8,24> id249out_output[5];

  HWFloat<8,24> id260out_value;

  HWFloat<8,24> id99out_result[9];

  HWFloat<8,24> id259out_value;

  HWFloat<8,24> id10out_o[7];

  HWFloat<8,24> id12out_result[29];

  HWFloat<8,24> id100out_result[9];

  HWFloat<8,24> id101out_result[13];

  HWFloat<8,24> id258out_value;

  HWFloat<8,24> id103out_result[9];

  HWFloat<8,24> id58out_result[13];

  HWFloat<8,24> id104out_result[9];

  HWFloat<8,24> id105out_result[13];

  HWFloat<8,24> id235out_output[9];

  HWFloat<8,24> id257out_value;

  HWFloat<8,24> id107out_result[9];

  HWFloat<8,24> id234out_output[17];

  HWFloat<8,24> id108out_result[9];

  HWFloat<8,24> id109out_result[13];

  HWFloat<8,24> id110out_result[9];

  HWFloat<8,24> id111out_result[13];

  HWFloat<8,24> id227out_output[34];

  HWFloat<8,24> id256out_value;

  HWFloat<8,24> id125out_result[13];

  HWOffsetFix<1,0,UNSIGNED> id126out_result[3];

  HWFloat<8,24> id237out_output[3];

  HWFloat<8,24> id127out_result[2];

  HWFloat<8,24> id129out_result[9];

  HWFloat<8,24> id132out_result[13];

  HWFloat<8,24> id238out_output[13];

  HWFloat<8,24> id133out_result[2];

  HWOffsetFix<32,0,UNSIGNED> id255out_value;

  HWOffsetFix<32,0,UNSIGNED> id158out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id159out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id254out_value;

  HWOffsetFix<1,0,UNSIGNED> id161out_result[2];

  HWRawBits<1> id162out_result[2];

  HWOffsetFix<32,0,UNSIGNED> id253out_value;

  HWOffsetFix<32,0,UNSIGNED> id167out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id168out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id242out_output[2];

  HWRawBits<1> id169out_result[2];

  HWOffsetFix<1,0,UNSIGNED> id173out_io_fine_force_disabled;

  HWOffsetFix<1,0,UNSIGNED> id243out_output[129];

  HWOffsetFix<1,0,UNSIGNED> id186out_value;

  HWOffsetFix<1,0,UNSIGNED> id252out_value;

  HWOffsetFix<49,0,UNSIGNED> id183out_value;

  HWOffsetFix<48,0,UNSIGNED> id184out_count;
  HWOffsetFix<1,0,UNSIGNED> id184out_wrap;

  HWOffsetFix<49,0,UNSIGNED> id184st_count;

  HWOffsetFix<1,0,UNSIGNED> id251out_value;

  HWOffsetFix<49,0,UNSIGNED> id189out_value;

  HWOffsetFix<48,0,UNSIGNED> id190out_count;
  HWOffsetFix<1,0,UNSIGNED> id190out_wrap;

  HWOffsetFix<49,0,UNSIGNED> id190st_count;

  HWOffsetFix<48,0,UNSIGNED> id192out_run_cycle_count;

  HWOffsetFix<1,0,UNSIGNED> id193out_result[2];

  const HWOffsetFix<1,0,UNSIGNED> c_hw_fix_1_0_uns_bits;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits;
  const HWOffsetFix<33,0,UNSIGNED> c_hw_fix_33_0_uns_bits;
  const HWOffsetFix<33,0,UNSIGNED> c_hw_fix_33_0_uns_bits_1;
  const HWOffsetFix<2,0,UNSIGNED> c_hw_fix_2_0_uns_bits;
  const HWOffsetFix<2,0,UNSIGNED> c_hw_fix_2_0_uns_bits_1;
  const HWOffsetFix<2,0,UNSIGNED> c_hw_fix_2_0_uns_bits_2;
  const HWOffsetFix<1,0,UNSIGNED> c_hw_fix_1_0_uns_undef;
  const HWOffsetFix<25,0,UNSIGNED> c_hw_fix_25_0_uns_bits;
  const HWOffsetFix<25,0,UNSIGNED> c_hw_fix_25_0_uns_bits_1;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_1;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_undef;
  const HWOffsetFix<32,0,TWOSCOMPLEMENT> c_hw_fix_32_0_sgn_bits;
  const HWFloat<8,24> c_hw_flt_8_24_bits;
  const HWFloat<8,24> c_hw_flt_8_24_bits_1;
  const HWOffsetFix<32,0,UNSIGNED> c_hw_fix_32_0_uns_bits_2;
  const HWFloat<8,24> c_hw_flt_8_24_undef;
  const HWFloat<8,24> c_hw_flt_8_24_bits_2;
  const HWFloat<8,24> c_hw_flt_8_24_bits_3;
  const HWFloat<8,24> c_hw_flt_8_24_bits_4;
  const HWFloat<8,24> c_hw_flt_8_24_bits_5;
  const HWOffsetFix<1,0,UNSIGNED> c_hw_fix_1_0_uns_bits_1;
  const HWFloat<8,24> c_hw_flt_8_24_bits_6;
  const HWFloat<8,24> c_hw_flt_8_24_bits_7;
  const HWOffsetFix<49,0,UNSIGNED> c_hw_fix_49_0_uns_bits;
  const HWOffsetFix<49,0,UNSIGNED> c_hw_fix_49_0_uns_bits_1;
  const HWOffsetFix<49,0,UNSIGNED> c_hw_fix_49_0_uns_bits_2;

  void execute0();
};

}

#endif /* NEBMLMCSTREAMKERNEL_H_ */
