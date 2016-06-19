#include "stdsimheader.h"
//#define BOOST_NO_STD_LOCALE
//#include <boost/format.hpp>

//#include "NebMLMCStreamKernel.h"

namespace maxcompilersim {

void NebMLMCStreamKernel::execute0() {
  { // Node ID: 14 (NodeConstantRawBits)
  }
  { // Node ID: 250 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (3l)))
  { // Node ID: 19 (NodeCounterV1)
    const HWOffsetFix<1,0,UNSIGNED> &id19in_enable = id14out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id19in_max = id250out_value;

    HWOffsetFix<33,0,UNSIGNED> id19x_1;
    HWOffsetFix<1,0,UNSIGNED> id19x_2;
    HWOffsetFix<1,0,UNSIGNED> id19x_3;
    HWOffsetFix<33,0,UNSIGNED> id19x_4t_1e_1;

    id19out_count = (cast_fixed2fixed<32,0,UNSIGNED,TRUNCATE>((id19st_count)));
    (id19x_1) = (add_fixed<33,0,UNSIGNED,TRUNCATE>((id19st_count),(c_hw_fix_33_0_uns_bits_1)));
    (id19x_2) = (gte_fixed((id19x_1),(cast_fixed2fixed<33,0,UNSIGNED,TRUNCATE>(id19in_max))));
    (id19x_3) = (and_fixed((id19x_2),id19in_enable));
    id19out_wrap = (id19x_3);
    if((id19in_enable.getValueAsBool())) {
      if(((id19x_3).getValueAsBool())) {
        (id19st_count) = (c_hw_fix_33_0_uns_bits);
      }
      else {
        (id19x_4t_1e_1) = (id19x_1);
        (id19st_count) = (id19x_4t_1e_1);
      }
    }
    else {
    }
  }
  { // Node ID: 284 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (3l)))
  { // Node ID: 18 (NodeCounterV1)
    const HWOffsetFix<1,0,UNSIGNED> &id18in_enable = id19out_wrap;
    const HWOffsetFix<2,0,UNSIGNED> &id18in_max = id284out_value;

    HWOffsetFix<2,0,UNSIGNED> id18x_1;
    HWOffsetFix<1,0,UNSIGNED> id18x_2;
    HWOffsetFix<1,0,UNSIGNED> id18x_3;
    HWOffsetFix<2,0,UNSIGNED> id18x_4t_1e_1;

    id18out_count = (cast_fixed2fixed<1,0,UNSIGNED,TRUNCATE>((id18st_count)));
    (id18x_1) = (add_fixed<2,0,UNSIGNED,TRUNCATE>((id18st_count),(c_hw_fix_2_0_uns_bits_2)));
    (id18x_2) = (gte_fixed((id18x_1),id18in_max));
    (id18x_3) = (and_fixed((id18x_2),id18in_enable));
    id18out_wrap = (id18x_3);
    if((id18in_enable.getValueAsBool())) {
      if(((id18x_3).getValueAsBool())) {
        (id18st_count) = (c_hw_fix_2_0_uns_bits_1);
      }
      else {
        (id18x_4t_1e_1) = (id18x_1);
        (id18st_count) = (id18x_4t_1e_1);
      }
    }
    else {
    }
  }
  { // Node ID: 203 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id203in_input = id18out_wrap;

    id203out_output[(getCycle()+1)%2] = id203in_input;
  }
  { // Node ID: 3 (NodeInputMappedReg)
  }
  if ( (getFillLevel() >= (4l)))
  { // Node ID: 16 (NodeCounterV1)
    const HWOffsetFix<1,0,UNSIGNED> &id16in_enable = id203out_output[getCycle()%2];
    const HWOffsetFix<24,0,UNSIGNED> &id16in_max = id3out_N;

    HWOffsetFix<25,0,UNSIGNED> id16x_1;
    HWOffsetFix<1,0,UNSIGNED> id16x_2;
    HWOffsetFix<1,0,UNSIGNED> id16x_3;
    HWOffsetFix<25,0,UNSIGNED> id16x_4t_1e_1;

    id16out_count = (cast_fixed2fixed<24,0,UNSIGNED,TRUNCATE>((id16st_count)));
    (id16x_1) = (add_fixed<25,0,UNSIGNED,TRUNCATE>((id16st_count),(c_hw_fix_25_0_uns_bits_1)));
    (id16x_2) = (gte_fixed((id16x_1),(cast_fixed2fixed<25,0,UNSIGNED,TRUNCATE>(id16in_max))));
    (id16x_3) = (and_fixed((id16x_2),id16in_enable));
    id16out_wrap = (id16x_3);
    if((id16in_enable.getValueAsBool())) {
      if(((id16x_3).getValueAsBool())) {
        (id16st_count) = (c_hw_fix_25_0_uns_bits);
      }
      else {
        (id16x_4t_1e_1) = (id16x_1);
        (id16st_count) = (id16x_4t_1e_1);
      }
    }
    else {
    }
  }
  { // Node ID: 4 (NodeInputMappedReg)
  }
  if ( (getFillLevel() >= (4l)))
  { // Node ID: 15 (NodeCounterV1)
    const HWOffsetFix<1,0,UNSIGNED> &id15in_enable = id16out_wrap;
    const HWOffsetFix<32,0,UNSIGNED> &id15in_max = id4out_nc;

    HWOffsetFix<33,0,UNSIGNED> id15x_1;
    HWOffsetFix<1,0,UNSIGNED> id15x_2;
    HWOffsetFix<1,0,UNSIGNED> id15x_3;
    HWOffsetFix<33,0,UNSIGNED> id15x_4t_1e_1;

    id15out_count = (cast_fixed2fixed<32,0,UNSIGNED,TRUNCATE>((id15st_count)));
    (id15x_1) = (add_fixed<33,0,UNSIGNED,TRUNCATE>((id15st_count),(c_hw_fix_33_0_uns_bits_1)));
    (id15x_2) = (gte_fixed((id15x_1),(cast_fixed2fixed<33,0,UNSIGNED,TRUNCATE>(id15in_max))));
    (id15x_3) = (and_fixed((id15x_2),id15in_enable));
    id15out_wrap = (id15x_3);
    if((id15in_enable.getValueAsBool())) {
      if(((id15x_3).getValueAsBool())) {
        (id15st_count) = (c_hw_fix_33_0_uns_bits);
      }
      else {
        (id15x_4t_1e_1) = (id15x_1);
        (id15st_count) = (id15x_4t_1e_1);
      }
    }
    else {
    }
  }
  { // Node ID: 283 (NodeConstantRawBits)
  }
  { // Node ID: 135 (NodeSub)
    const HWOffsetFix<32,0,UNSIGNED> &id135in_a = id4out_nc;
    const HWOffsetFix<32,0,UNSIGNED> &id135in_b = id283out_value;

    id135out_result[(getCycle()+1)%2] = (sub_fixed<32,0,UNSIGNED,TONEAR>(id135in_a,id135in_b));
  }
  { // Node ID: 136 (NodeEq)
    const HWOffsetFix<32,0,UNSIGNED> &id136in_a = id15out_count;
    const HWOffsetFix<32,0,UNSIGNED> &id136in_b = id135out_result[getCycle()%2];

    id136out_result[(getCycle()+1)%2] = (eq_fixed(id136in_a,id136in_b));
  }
  HWRawBits<1> id140out_output;

  { // Node ID: 140 (NodeReinterpret)
    const HWOffsetFix<1,0,UNSIGNED> &id140in_input = id136out_result[getCycle()%2];

    id140out_output = (cast_fixed2bits(id140in_input));
  }
  { // Node ID: 204 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id204in_input = id18out_count;

    id204out_output[(getCycle()+1)%2] = id204in_input;
  }
  { // Node ID: 282 (NodeConstantRawBits)
  }
  { // Node ID: 138 (NodeEq)
    const HWOffsetFix<1,0,UNSIGNED> &id138in_a = id204out_output[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id138in_b = id282out_value;

    id138out_result[(getCycle()+1)%2] = (eq_fixed(id138in_a,id138in_b));
  }
  HWRawBits<1> id141out_output;

  { // Node ID: 141 (NodeReinterpret)
    const HWOffsetFix<1,0,UNSIGNED> &id141in_input = id138out_result[getCycle()%2];

    id141out_output = (cast_fixed2bits(id141in_input));
  }
  { // Node ID: 139 (NodeAnd)
    const HWRawBits<1> &id139in_a = id140out_output;
    const HWRawBits<1> &id139in_b = id141out_output;

    HWRawBits<1> id139x_1;

    (id139x_1) = (and_bits(id139in_a,id139in_b));
    id139out_result[(getCycle()+1)%2] = (id139x_1);
  }
  HWOffsetFix<1,0,UNSIGNED> id142out_output;

  { // Node ID: 142 (NodeReinterpret)
    const HWRawBits<1> &id142in_input = id139out_result[getCycle()%2];

    id142out_output = (cast_bits2fixed<1,0,UNSIGNED>(id142in_input));
  }
  HWRawBits<1> id147out_output;

  { // Node ID: 147 (NodeReinterpret)
    const HWOffsetFix<1,0,UNSIGNED> &id147in_input = id142out_output;

    id147out_output = (cast_fixed2bits(id147in_input));
  }
  { // Node ID: 205 (NodeFIFO)
    const HWOffsetFix<32,0,UNSIGNED> &id205in_input = id19out_count;

    id205out_output[(getCycle()+1)%2] = id205in_input;
  }
  { // Node ID: 281 (NodeConstantRawBits)
  }
  { // Node ID: 144 (NodeSub)
    const HWOffsetFix<32,0,UNSIGNED> &id144in_a = id250out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id144in_b = id281out_value;

    id144out_result[(getCycle()+1)%2] = (sub_fixed<32,0,UNSIGNED,TONEAR>(id144in_a,id144in_b));
  }
  { // Node ID: 145 (NodeEq)
    const HWOffsetFix<32,0,UNSIGNED> &id145in_a = id205out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id145in_b = id144out_result[getCycle()%2];

    id145out_result[(getCycle()+1)%2] = (eq_fixed(id145in_a,id145in_b));
  }
  { // Node ID: 206 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id206in_input = id145out_result[getCycle()%2];

    id206out_output[(getCycle()+1)%2] = id206in_input;
  }
  HWRawBits<1> id148out_output;

  { // Node ID: 148 (NodeReinterpret)
    const HWOffsetFix<1,0,UNSIGNED> &id148in_input = id206out_output[getCycle()%2];

    id148out_output = (cast_fixed2bits(id148in_input));
  }
  { // Node ID: 146 (NodeAnd)
    const HWRawBits<1> &id146in_a = id147out_output;
    const HWRawBits<1> &id146in_b = id148out_output;

    HWRawBits<1> id146x_1;

    (id146x_1) = (and_bits(id146in_a,id146in_b));
    id146out_result[(getCycle()+1)%2] = (id146x_1);
  }
  HWOffsetFix<1,0,UNSIGNED> id149out_output;

  { // Node ID: 149 (NodeReinterpret)
    const HWRawBits<1> &id149in_input = id146out_result[getCycle()%2];

    id149out_output = (cast_bits2fixed<1,0,UNSIGNED>(id149in_input));
  }
  HWRawBits<1> id153out_output;

  { // Node ID: 153 (NodeReinterpret)
    const HWOffsetFix<1,0,UNSIGNED> &id153in_input = id149out_output;

    id153out_output = (cast_fixed2bits(id153in_input));
  }
  { // Node ID: 150 (NodeInputMappedReg)
  }
  HWOffsetFix<1,0,UNSIGNED> id151out_result;

  { // Node ID: 151 (NodeNot)
    const HWOffsetFix<1,0,UNSIGNED> &id151in_a = id150out_io_diff_force_disabled;

    id151out_result = (not_fixed(id151in_a));
  }
  HWRawBits<1> id154out_output;

  { // Node ID: 154 (NodeReinterpret)
    const HWOffsetFix<1,0,UNSIGNED> &id154in_input = id151out_result;

    id154out_output = (cast_fixed2bits(id154in_input));
  }
  HWRawBits<1> id152out_result;

  { // Node ID: 152 (NodeAnd)
    const HWRawBits<1> &id152in_a = id153out_output;
    const HWRawBits<1> &id152in_b = id154out_output;

    HWRawBits<1> id152x_1;

    (id152x_1) = (and_bits(id152in_a,id152in_b));
    id152out_result = (id152x_1);
  }
  HWOffsetFix<1,0,UNSIGNED> id155out_output;

  { // Node ID: 155 (NodeReinterpret)
    const HWRawBits<1> &id155in_input = id152out_result;

    id155out_output = (cast_bits2fixed<1,0,UNSIGNED>(id155in_input));
  }
  { // Node ID: 239 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id239in_input = id155out_output;

    id239out_output[(getCycle()+141)%142] = id239in_input;
  }
  { // Node ID: 2 (NodeInputMappedReg)
  }
  { // Node ID: 280 (NodeConstantRawBits)
  }
  { // Node ID: 131 (NodeEq)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id131in_a = id2out_l;
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id131in_b = id280out_value;

    id131out_result[(getCycle()+1)%2] = (eq_fixed(id131in_a,id131in_b));
  }
  { // Node ID: 279 (NodeConstantRawBits)
  }
  { // Node ID: 194 (NodeConstantRawBits)
  }
  { // Node ID: 278 (NodeConstantRawBits)
  }
  { // Node ID: 82 (NodeEq)
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id82in_a = id2out_l;
    const HWOffsetFix<32,0,TWOSCOMPLEMENT> &id82in_b = id278out_value;

    id82out_result[(getCycle()+1)%2] = (eq_fixed(id82in_a,id82in_b));
  }
  { // Node ID: 277 (NodeConstantRawBits)
  }
  { // Node ID: 60 (NodeEq)
    const HWOffsetFix<32,0,UNSIGNED> &id60in_a = id15out_count;
    const HWOffsetFix<32,0,UNSIGNED> &id60in_b = id277out_value;

    id60out_result[(getCycle()+1)%2] = (eq_fixed(id60in_a,id60in_b));
  }
  { // Node ID: 207 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id207in_input = id60out_result[getCycle()%2];

    id207out_output[(getCycle()+1)%2] = id207in_input;
  }
  HWFloat<8,24> id201out_output;

  { // Node ID: 201 (NodeStreamOffset)
    const HWFloat<8,24> &id201in_input = id97out_result[getCycle()%2];

    id201out_output = id201in_input;
  }
  { // Node ID: 276 (NodeConstantRawBits)
  }
  { // Node ID: 114 (NodeEq)
    const HWOffsetFix<1,0,UNSIGNED> &id114in_a = id18out_count;
    const HWOffsetFix<1,0,UNSIGNED> &id114in_b = id276out_value;

    id114out_result[(getCycle()+1)%2] = (eq_fixed(id114in_a,id114in_b));
  }
  if ( (getFillLevel() >= (4l)))
  { // Node ID: 180 (NodeRAM)
    const bool id180_inputvalid = !(isFlushingActive() && getFlushLevel() >= (4l));
    const HWOffsetFix<24,0,UNSIGNED> &id180in_addrA = id16out_count;
    const HWFloat<8,24> &id180in_dina = id201out_output;
    const HWOffsetFix<1,0,UNSIGNED> &id180in_wea = id114out_result[getCycle()%2];
    const HWOffsetFix<24,0,UNSIGNED> &id180in_addrB = id16out_count;

    long id180x_1;
    long id180x_2;
    HWFloat<8,24> id180x_3;

    (id180x_1) = (id180in_addrA.getValueAsLong());
    (id180x_2) = (id180in_addrB.getValueAsLong());
    switch(((long)((id180x_2)<(16777216l)))) {
      case 0l:
        id180x_3 = (c_hw_flt_8_24_undef);
        break;
      case 1l:
        id180x_3 = (id180sta_ram_store[(id180x_2)]);
        break;
      default:
        id180x_3 = (c_hw_flt_8_24_undef);
        break;
    }
    id180out_doutb[(getCycle()+2)%3] = (id180x_3);
    if(((id180in_wea.getValueAsBool())&id180_inputvalid)) {
      if(((id180x_1)<(16777216l))) {
        (id180sta_ram_store[(id180x_1)]) = id180in_dina;
      }
      else {
        throw std::runtime_error((format_string_NebMLMCStreamKernel_1("Run-time exception during simulation: Out of bounds write to NodeRAM (ID: 180) on port A, ram depth is 16777216.")));
      }
    }
  }
  { // Node ID: 61 (NodeConstantRawBits)
  }
  { // Node ID: 62 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id62in_sel = id207out_output[getCycle()%2];
    const HWFloat<8,24> &id62in_option0 = id180out_doutb[getCycle()%3];
    const HWFloat<8,24> &id62in_option1 = id61out_value;

    HWFloat<8,24> id62x_1;

    switch((id62in_sel.getValueAsLong())) {
      case 0l:
        id62x_1 = id62in_option0;
        break;
      case 1l:
        id62x_1 = id62in_option1;
        break;
      default:
        id62x_1 = (c_hw_flt_8_24_undef);
        break;
    }
    id62out_result[(getCycle()+1)%2] = (id62x_1);
  }
  { // Node ID: 209 (NodeFIFO)
    const HWFloat<8,24> &id209in_input = id62out_result[getCycle()%2];

    id209out_output[(getCycle()+12)%13] = id209in_input;
  }
  { // Node ID: 244 (NodeFIFO)
    const HWFloat<8,24> &id244in_input = id209out_output[getCycle()%13];

    id244out_output[(getCycle()+4)%5] = id244in_input;
  }
  { // Node ID: 275 (NodeConstantRawBits)
  }
  { // Node ID: 68 (NodeMul)
    const HWFloat<8,24> &id68in_a = id275out_value;
    const HWFloat<8,24> &id68in_b = id62out_result[getCycle()%2];

    id68out_result[(getCycle()+8)%9] = (mul_float(id68in_a,id68in_b));
  }
  { // Node ID: 274 (NodeConstantRawBits)
  }
  HWOffsetFix<32,1,UNSIGNED> id195out_output;

  { // Node ID: 195 (NodeReinterpret)
    const HWOffsetFix<32,0,UNSIGNED> &id195in_input = id4out_nc;

    id195out_output = (cast_bits2fixed<32,1,UNSIGNED>((cast_fixed2bits(id195in_input))));
  }
  HWOffsetFix<32,0,UNSIGNED> id196out_o;

  { // Node ID: 196 (NodeCast)
    const HWOffsetFix<32,1,UNSIGNED> &id196in_i = id195out_output;

    id196out_o = (cast_fixed2fixed<32,0,UNSIGNED,TONEAR>(id196in_i));
  }
  { // Node ID: 7 (NodeCast)
    const HWOffsetFix<32,0,UNSIGNED> &id7in_i = id196out_o;

    id7out_o[(getCycle()+6)%7] = (cast_fixed2float<8,24>(id7in_i));
  }
  { // Node ID: 9 (NodeDiv)
    const HWFloat<8,24> &id9in_a = id274out_value;
    const HWFloat<8,24> &id9in_b = id7out_o[getCycle()%7];

    id9out_result[(getCycle()+28)%29] = (div_float(id9in_a,id9in_b));
  }
  { // Node ID: 69 (NodeMul)
    const HWFloat<8,24> &id69in_a = id68out_result[getCycle()%9];
    const HWFloat<8,24> &id69in_b = id9out_result[getCycle()%29];

    id69out_result[(getCycle()+8)%9] = (mul_float(id69in_a,id69in_b));
  }
  { // Node ID: 70 (NodeAdd)
    const HWFloat<8,24> &id70in_a = id244out_output[getCycle()%5];
    const HWFloat<8,24> &id70in_b = id69out_result[getCycle()%9];

    id70out_result[(getCycle()+12)%13] = (add_float(id70in_a,id70in_b));
  }
  { // Node ID: 273 (NodeConstantRawBits)
  }
  { // Node ID: 72 (NodeMul)
    const HWFloat<8,24> &id72in_a = id273out_value;
    const HWFloat<8,24> &id72in_b = id209out_output[getCycle()%13];

    id72out_result[(getCycle()+8)%9] = (mul_float(id72in_a,id72in_b));
  }
  { // Node ID: 272 (NodeConstantRawBits)
  }
  { // Node ID: 21 (NodeEq)
    const HWOffsetFix<1,0,UNSIGNED> &id21in_a = id204out_output[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id21in_b = id272out_value;

    id21out_result[(getCycle()+1)%2] = (eq_fixed(id21in_a,id21in_b));
  }
  HWRawBits<1> id26out_output;

  { // Node ID: 26 (NodeReinterpret)
    const HWOffsetFix<1,0,UNSIGNED> &id26in_input = id21out_result[getCycle()%2];

    id26out_output = (cast_fixed2bits(id26in_input));
  }
  { // Node ID: 271 (NodeConstantRawBits)
  }
  { // Node ID: 23 (NodeSub)
    const HWOffsetFix<32,0,UNSIGNED> &id23in_a = id250out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id23in_b = id271out_value;

    id23out_result[(getCycle()+1)%2] = (sub_fixed<32,0,UNSIGNED,TONEAR>(id23in_a,id23in_b));
  }
  { // Node ID: 24 (NodeEq)
    const HWOffsetFix<32,0,UNSIGNED> &id24in_a = id205out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id24in_b = id23out_result[getCycle()%2];

    id24out_result[(getCycle()+1)%2] = (eq_fixed(id24in_a,id24in_b));
  }
  HWRawBits<1> id27out_output;

  { // Node ID: 27 (NodeReinterpret)
    const HWOffsetFix<1,0,UNSIGNED> &id27in_input = id24out_result[getCycle()%2];

    id27out_output = (cast_fixed2bits(id27in_input));
  }
  { // Node ID: 25 (NodeAnd)
    const HWRawBits<1> &id25in_a = id26out_output;
    const HWRawBits<1> &id25in_b = id27out_output;

    HWRawBits<1> id25x_1;

    (id25x_1) = (and_bits(id25in_a,id25in_b));
    id25out_result[(getCycle()+1)%2] = (id25x_1);
  }
  HWOffsetFix<1,0,UNSIGNED> id28out_output;

  { // Node ID: 28 (NodeReinterpret)
    const HWRawBits<1> &id28in_input = id25out_result[getCycle()%2];

    id28out_output = (cast_bits2fixed<1,0,UNSIGNED>(id28in_input));
  }
  HWRawBits<1> id32out_output;

  { // Node ID: 32 (NodeReinterpret)
    const HWOffsetFix<1,0,UNSIGNED> &id32in_input = id28out_output;

    id32out_output = (cast_fixed2bits(id32in_input));
  }
  { // Node ID: 29 (NodeInputMappedReg)
  }
  HWOffsetFix<1,0,UNSIGNED> id30out_result;

  { // Node ID: 30 (NodeNot)
    const HWOffsetFix<1,0,UNSIGNED> &id30in_a = id29out_io_r1_force_disabled;

    id30out_result = (not_fixed(id30in_a));
  }
  HWRawBits<1> id33out_output;

  { // Node ID: 33 (NodeReinterpret)
    const HWOffsetFix<1,0,UNSIGNED> &id33in_input = id30out_result;

    id33out_output = (cast_fixed2bits(id33in_input));
  }
  HWRawBits<1> id31out_result;

  { // Node ID: 31 (NodeAnd)
    const HWRawBits<1> &id31in_a = id32out_output;
    const HWRawBits<1> &id31in_b = id33out_output;

    HWRawBits<1> id31x_1;

    (id31x_1) = (and_bits(id31in_a,id31in_b));
    id31out_result = (id31x_1);
  }
  HWOffsetFix<1,0,UNSIGNED> id34out_output;

  { // Node ID: 34 (NodeReinterpret)
    const HWRawBits<1> &id34in_input = id31out_result;

    id34out_output = (cast_bits2fixed<1,0,UNSIGNED>(id34in_input));
  }
  if ( (getFillLevel() >= (6l)))
  { // Node ID: 35 (NodeInput)
    const HWOffsetFix<1,0,UNSIGNED> &id35in_enable = id34out_output;

    (id35st_read_next_cycle) = ((id35in_enable.getValueAsBool())&(!(((getFlushLevel())>=(6l))&(isFlushingActive()))));
    queueReadRequest(m_r1, id35st_read_next_cycle.getValueAsBool());
  }
  { // Node ID: 52 (NodeSqrt)
    const HWFloat<8,24> &id52in_a = id9out_result[getCycle()%29];

    id52out_result[(getCycle()+28)%29] = (sqrt_float(id52in_a));
  }
  { // Node ID: 54 (NodeMul)
    const HWFloat<8,24> &id54in_a = id35out_data;
    const HWFloat<8,24> &id54in_b = id52out_result[getCycle()%29];

    id54out_result[(getCycle()+8)%9] = (mul_float(id54in_a,id54in_b));
  }
  { // Node ID: 212 (NodeFIFO)
    const HWFloat<8,24> &id212in_input = id54out_result[getCycle()%9];

    id212out_output[(getCycle()+8)%9] = id212in_input;
  }
  { // Node ID: 73 (NodeMul)
    const HWFloat<8,24> &id73in_a = id72out_result[getCycle()%9];
    const HWFloat<8,24> &id73in_b = id212out_output[getCycle()%9];

    id73out_result[(getCycle()+8)%9] = (mul_float(id73in_a,id73in_b));
  }
  { // Node ID: 74 (NodeAdd)
    const HWFloat<8,24> &id74in_a = id70out_result[getCycle()%13];
    const HWFloat<8,24> &id74in_b = id73out_result[getCycle()%9];

    id74out_result[(getCycle()+12)%13] = (add_float(id74in_a,id74in_b));
  }
  { // Node ID: 270 (NodeConstantRawBits)
  }
  { // Node ID: 76 (NodeMul)
    const HWFloat<8,24> &id76in_a = id270out_value;
    const HWFloat<8,24> &id76in_b = id244out_output[getCycle()%5];

    id76out_result[(getCycle()+8)%9] = (mul_float(id76in_a,id76in_b));
  }
  { // Node ID: 214 (NodeFIFO)
    const HWFloat<8,24> &id214in_input = id76out_result[getCycle()%9];

    id214out_output[(getCycle()+8)%9] = id214in_input;
  }
  { // Node ID: 77 (NodeMul)
    const HWFloat<8,24> &id77in_a = id54out_result[getCycle()%9];
    const HWFloat<8,24> &id77in_b = id54out_result[getCycle()%9];

    id77out_result[(getCycle()+8)%9] = (mul_float(id77in_a,id77in_b));
  }
  { // Node ID: 78 (NodeSub)
    const HWFloat<8,24> &id78in_a = id77out_result[getCycle()%9];
    const HWFloat<8,24> &id78in_b = id9out_result[getCycle()%29];

    id78out_result[(getCycle()+12)%13] = (sub_float(id78in_a,id78in_b));
  }
  { // Node ID: 79 (NodeMul)
    const HWFloat<8,24> &id79in_a = id214out_output[getCycle()%9];
    const HWFloat<8,24> &id79in_b = id78out_result[getCycle()%13];

    id79out_result[(getCycle()+8)%9] = (mul_float(id79in_a,id79in_b));
  }
  { // Node ID: 80 (NodeAdd)
    const HWFloat<8,24> &id80in_a = id74out_result[getCycle()%13];
    const HWFloat<8,24> &id80in_b = id79out_result[getCycle()%9];

    id80out_result[(getCycle()+12)%13] = (add_float(id80in_a,id80in_b));
  }
  { // Node ID: 216 (NodeFIFO)
    const HWFloat<8,24> &id216in_input = id80out_result[getCycle()%13];

    id216out_output[(getCycle()+4)%5] = id216in_input;
  }
  { // Node ID: 245 (NodeFIFO)
    const HWFloat<8,24> &id245in_input = id216out_output[getCycle()%5];

    id245out_output[(getCycle()+12)%13] = id245in_input;
  }
  { // Node ID: 269 (NodeConstantRawBits)
  }
  { // Node ID: 84 (NodeMul)
    const HWFloat<8,24> &id84in_a = id269out_value;
    const HWFloat<8,24> &id84in_b = id80out_result[getCycle()%13];

    id84out_result[(getCycle()+8)%9] = (mul_float(id84in_a,id84in_b));
  }
  { // Node ID: 85 (NodeMul)
    const HWFloat<8,24> &id85in_a = id84out_result[getCycle()%9];
    const HWFloat<8,24> &id85in_b = id9out_result[getCycle()%29];

    id85out_result[(getCycle()+8)%9] = (mul_float(id85in_a,id85in_b));
  }
  { // Node ID: 86 (NodeAdd)
    const HWFloat<8,24> &id86in_a = id245out_output[getCycle()%13];
    const HWFloat<8,24> &id86in_b = id85out_result[getCycle()%9];

    id86out_result[(getCycle()+12)%13] = (add_float(id86in_a,id86in_b));
  }
  { // Node ID: 268 (NodeConstantRawBits)
  }
  { // Node ID: 88 (NodeMul)
    const HWFloat<8,24> &id88in_a = id268out_value;
    const HWFloat<8,24> &id88in_b = id216out_output[getCycle()%5];

    id88out_result[(getCycle()+8)%9] = (mul_float(id88in_a,id88in_b));
  }
  { // Node ID: 267 (NodeConstantRawBits)
  }
  { // Node ID: 37 (NodeEq)
    const HWOffsetFix<1,0,UNSIGNED> &id37in_a = id204out_output[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id37in_b = id267out_value;

    id37out_result[(getCycle()+1)%2] = (eq_fixed(id37in_a,id37in_b));
  }
  HWRawBits<1> id42out_output;

  { // Node ID: 42 (NodeReinterpret)
    const HWOffsetFix<1,0,UNSIGNED> &id42in_input = id37out_result[getCycle()%2];

    id42out_output = (cast_fixed2bits(id42in_input));
  }
  { // Node ID: 266 (NodeConstantRawBits)
  }
  { // Node ID: 39 (NodeSub)
    const HWOffsetFix<32,0,UNSIGNED> &id39in_a = id250out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id39in_b = id266out_value;

    id39out_result[(getCycle()+1)%2] = (sub_fixed<32,0,UNSIGNED,TONEAR>(id39in_a,id39in_b));
  }
  { // Node ID: 40 (NodeEq)
    const HWOffsetFix<32,0,UNSIGNED> &id40in_a = id205out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id40in_b = id39out_result[getCycle()%2];

    id40out_result[(getCycle()+1)%2] = (eq_fixed(id40in_a,id40in_b));
  }
  HWRawBits<1> id43out_output;

  { // Node ID: 43 (NodeReinterpret)
    const HWOffsetFix<1,0,UNSIGNED> &id43in_input = id40out_result[getCycle()%2];

    id43out_output = (cast_fixed2bits(id43in_input));
  }
  { // Node ID: 41 (NodeAnd)
    const HWRawBits<1> &id41in_a = id42out_output;
    const HWRawBits<1> &id41in_b = id43out_output;

    HWRawBits<1> id41x_1;

    (id41x_1) = (and_bits(id41in_a,id41in_b));
    id41out_result[(getCycle()+1)%2] = (id41x_1);
  }
  HWOffsetFix<1,0,UNSIGNED> id44out_output;

  { // Node ID: 44 (NodeReinterpret)
    const HWRawBits<1> &id44in_input = id41out_result[getCycle()%2];

    id44out_output = (cast_bits2fixed<1,0,UNSIGNED>(id44in_input));
  }
  HWRawBits<1> id48out_output;

  { // Node ID: 48 (NodeReinterpret)
    const HWOffsetFix<1,0,UNSIGNED> &id48in_input = id44out_output;

    id48out_output = (cast_fixed2bits(id48in_input));
  }
  { // Node ID: 45 (NodeInputMappedReg)
  }
  HWOffsetFix<1,0,UNSIGNED> id46out_result;

  { // Node ID: 46 (NodeNot)
    const HWOffsetFix<1,0,UNSIGNED> &id46in_a = id45out_io_r2_force_disabled;

    id46out_result = (not_fixed(id46in_a));
  }
  HWRawBits<1> id49out_output;

  { // Node ID: 49 (NodeReinterpret)
    const HWOffsetFix<1,0,UNSIGNED> &id49in_input = id46out_result;

    id49out_output = (cast_fixed2bits(id49in_input));
  }
  HWRawBits<1> id47out_result;

  { // Node ID: 47 (NodeAnd)
    const HWRawBits<1> &id47in_a = id48out_output;
    const HWRawBits<1> &id47in_b = id49out_output;

    HWRawBits<1> id47x_1;

    (id47x_1) = (and_bits(id47in_a,id47in_b));
    id47out_result = (id47x_1);
  }
  HWOffsetFix<1,0,UNSIGNED> id50out_output;

  { // Node ID: 50 (NodeReinterpret)
    const HWRawBits<1> &id50in_input = id47out_result;

    id50out_output = (cast_bits2fixed<1,0,UNSIGNED>(id50in_input));
  }
  { // Node ID: 219 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id219in_input = id50out_output;

    id219out_output[(getCycle()+8)%9] = id219in_input;
  }
  if ( (getFillLevel() >= (14l)))
  { // Node ID: 51 (NodeInput)
    const HWOffsetFix<1,0,UNSIGNED> &id51in_enable = id219out_output[getCycle()%9];

    (id51st_read_next_cycle) = ((id51in_enable.getValueAsBool())&(!(((getFlushLevel())>=(14l))&(isFlushingActive()))));
    queueReadRequest(m_r2, id51st_read_next_cycle.getValueAsBool());
  }
  { // Node ID: 55 (NodeSqrt)
    const HWFloat<8,24> &id55in_a = id9out_result[getCycle()%29];

    id55out_result[(getCycle()+28)%29] = (sqrt_float(id55in_a));
  }
  { // Node ID: 57 (NodeMul)
    const HWFloat<8,24> &id57in_a = id51out_data;
    const HWFloat<8,24> &id57in_b = id55out_result[getCycle()%29];

    id57out_result[(getCycle()+8)%9] = (mul_float(id57in_a,id57in_b));
  }
  { // Node ID: 220 (NodeFIFO)
    const HWFloat<8,24> &id220in_input = id57out_result[getCycle()%9];

    id220out_output[(getCycle()+44)%45] = id220in_input;
  }
  { // Node ID: 89 (NodeMul)
    const HWFloat<8,24> &id89in_a = id88out_result[getCycle()%9];
    const HWFloat<8,24> &id89in_b = id220out_output[getCycle()%45];

    id89out_result[(getCycle()+8)%9] = (mul_float(id89in_a,id89in_b));
  }
  { // Node ID: 221 (NodeFIFO)
    const HWFloat<8,24> &id221in_input = id89out_result[getCycle()%9];

    id221out_output[(getCycle()+8)%9] = id221in_input;
  }
  { // Node ID: 90 (NodeAdd)
    const HWFloat<8,24> &id90in_a = id86out_result[getCycle()%13];
    const HWFloat<8,24> &id90in_b = id221out_output[getCycle()%9];

    id90out_result[(getCycle()+12)%13] = (add_float(id90in_a,id90in_b));
  }
  { // Node ID: 265 (NodeConstantRawBits)
  }
  { // Node ID: 246 (NodeFIFO)
    const HWFloat<8,24> &id246in_input = id245out_output[getCycle()%13];

    id246out_output[(getCycle()+8)%9] = id246in_input;
  }
  { // Node ID: 92 (NodeMul)
    const HWFloat<8,24> &id92in_a = id265out_value;
    const HWFloat<8,24> &id92in_b = id246out_output[getCycle()%9];

    id92out_result[(getCycle()+8)%9] = (mul_float(id92in_a,id92in_b));
  }
  { // Node ID: 93 (NodeMul)
    const HWFloat<8,24> &id93in_a = id220out_output[getCycle()%45];
    const HWFloat<8,24> &id93in_b = id220out_output[getCycle()%45];

    id93out_result[(getCycle()+8)%9] = (mul_float(id93in_a,id93in_b));
  }
  { // Node ID: 94 (NodeSub)
    const HWFloat<8,24> &id94in_a = id93out_result[getCycle()%9];
    const HWFloat<8,24> &id94in_b = id9out_result[getCycle()%29];

    id94out_result[(getCycle()+12)%13] = (sub_float(id94in_a,id94in_b));
  }
  { // Node ID: 95 (NodeMul)
    const HWFloat<8,24> &id95in_a = id92out_result[getCycle()%9];
    const HWFloat<8,24> &id95in_b = id94out_result[getCycle()%13];

    id95out_result[(getCycle()+8)%9] = (mul_float(id95in_a,id95in_b));
  }
  { // Node ID: 96 (NodeAdd)
    const HWFloat<8,24> &id96in_a = id90out_result[getCycle()%13];
    const HWFloat<8,24> &id96in_b = id95out_result[getCycle()%9];

    id96out_result[(getCycle()+12)%13] = (add_float(id96in_a,id96in_b));
  }
  { // Node ID: 247 (NodeFIFO)
    const HWFloat<8,24> &id247in_input = id246out_output[getCycle()%9];

    id247out_output[(getCycle()+28)%29] = id247in_input;
  }
  { // Node ID: 97 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id97in_sel = id82out_result[getCycle()%2];
    const HWFloat<8,24> &id97in_option0 = id96out_result[getCycle()%13];
    const HWFloat<8,24> &id97in_option1 = id247out_output[getCycle()%29];

    HWFloat<8,24> id97x_1;

    switch((id97in_sel.getValueAsLong())) {
      case 0l:
        id97x_1 = id97in_option0;
        break;
      case 1l:
        id97x_1 = id97in_option1;
        break;
      default:
        id97x_1 = (c_hw_flt_8_24_undef);
        break;
    }
    id97out_result[(getCycle()+1)%2] = (id97x_1);
  }
  { // Node ID: 264 (NodeConstantRawBits)
  }
  { // Node ID: 119 (NodeSub)
    const HWFloat<8,24> &id119in_a = id97out_result[getCycle()%2];
    const HWFloat<8,24> &id119in_b = id264out_value;

    id119out_result[(getCycle()+12)%13] = (sub_float(id119in_a,id119in_b));
  }
  { // Node ID: 120 (NodeGt)
    const HWFloat<8,24> &id120in_a = id194out_value;
    const HWFloat<8,24> &id120in_b = id119out_result[getCycle()%13];

    id120out_result[(getCycle()+2)%3] = (gt_float(id120in_a,id120in_b));
  }
  { // Node ID: 226 (NodeFIFO)
    const HWFloat<8,24> &id226in_input = id119out_result[getCycle()%13];

    id226out_output[(getCycle()+2)%3] = id226in_input;
  }
  { // Node ID: 121 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id121in_sel = id120out_result[getCycle()%3];
    const HWFloat<8,24> &id121in_option0 = id226out_output[getCycle()%3];
    const HWFloat<8,24> &id121in_option1 = id194out_value;

    HWFloat<8,24> id121x_1;

    switch((id121in_sel.getValueAsLong())) {
      case 0l:
        id121x_1 = id121in_option0;
        break;
      case 1l:
        id121x_1 = id121in_option1;
        break;
      default:
        id121x_1 = (c_hw_flt_8_24_undef);
        break;
    }
    id121out_result[(getCycle()+1)%2] = (id121x_1);
  }
  { // Node ID: 123 (NodeMul)
    const HWFloat<8,24> &id123in_a = id279out_value;
    const HWFloat<8,24> &id123in_b = id121out_result[getCycle()%2];

    id123out_result[(getCycle()+8)%9] = (mul_float(id123in_a,id123in_b));
  }
  { // Node ID: 263 (NodeConstantRawBits)
  }
  { // Node ID: 262 (NodeConstantRawBits)
  }
  { // Node ID: 64 (NodeEq)
    const HWOffsetFix<32,0,UNSIGNED> &id64in_a = id15out_count;
    const HWOffsetFix<32,0,UNSIGNED> &id64in_b = id262out_value;

    id64out_result[(getCycle()+1)%2] = (eq_fixed(id64in_a,id64in_b));
  }
  { // Node ID: 228 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id228in_input = id64out_result[getCycle()%2];

    id228out_output[(getCycle()+1)%2] = id228in_input;
  }
  HWFloat<8,24> id202out_output;

  { // Node ID: 202 (NodeStreamOffset)
    const HWFloat<8,24> &id202in_input = id227out_output[getCycle()%34];

    id202out_output = id202in_input;
  }
  { // Node ID: 261 (NodeConstantRawBits)
  }
  { // Node ID: 117 (NodeEq)
    const HWOffsetFix<1,0,UNSIGNED> &id117in_a = id18out_count;
    const HWOffsetFix<1,0,UNSIGNED> &id117in_b = id261out_value;

    id117out_result[(getCycle()+1)%2] = (eq_fixed(id117in_a,id117in_b));
  }
  if ( (getFillLevel() >= (4l)))
  { // Node ID: 181 (NodeRAM)
    const bool id181_inputvalid = !(isFlushingActive() && getFlushLevel() >= (4l));
    const HWOffsetFix<24,0,UNSIGNED> &id181in_addrA = id16out_count;
    const HWFloat<8,24> &id181in_dina = id202out_output;
    const HWOffsetFix<1,0,UNSIGNED> &id181in_wea = id117out_result[getCycle()%2];
    const HWOffsetFix<24,0,UNSIGNED> &id181in_addrB = id16out_count;

    long id181x_1;
    long id181x_2;
    HWFloat<8,24> id181x_3;

    (id181x_1) = (id181in_addrA.getValueAsLong());
    (id181x_2) = (id181in_addrB.getValueAsLong());
    switch(((long)((id181x_2)<(16777216l)))) {
      case 0l:
        id181x_3 = (c_hw_flt_8_24_undef);
        break;
      case 1l:
        id181x_3 = (id181sta_ram_store[(id181x_2)]);
        break;
      default:
        id181x_3 = (c_hw_flt_8_24_undef);
        break;
    }
    id181out_doutb[(getCycle()+2)%3] = (id181x_3);
    if(((id181in_wea.getValueAsBool())&id181_inputvalid)) {
      if(((id181x_1)<(16777216l))) {
        (id181sta_ram_store[(id181x_1)]) = id181in_dina;
      }
      else {
        throw std::runtime_error((format_string_NebMLMCStreamKernel_2("Run-time exception during simulation: Out of bounds write to NodeRAM (ID: 181) on port A, ram depth is 16777216.")));
      }
    }
  }
  { // Node ID: 65 (NodeConstantRawBits)
  }
  { // Node ID: 66 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id66in_sel = id228out_output[getCycle()%2];
    const HWFloat<8,24> &id66in_option0 = id181out_doutb[getCycle()%3];
    const HWFloat<8,24> &id66in_option1 = id65out_value;

    HWFloat<8,24> id66x_1;

    switch((id66in_sel.getValueAsLong())) {
      case 0l:
        id66x_1 = id66in_option0;
        break;
      case 1l:
        id66x_1 = id66in_option1;
        break;
      default:
        id66x_1 = (c_hw_flt_8_24_undef);
        break;
    }
    id66out_result[(getCycle()+1)%2] = (id66x_1);
  }
  { // Node ID: 229 (NodeFIFO)
    const HWFloat<8,24> &id229in_input = id66out_result[getCycle()%2];

    id229out_output[(getCycle()+12)%13] = id229in_input;
  }
  { // Node ID: 248 (NodeFIFO)
    const HWFloat<8,24> &id248in_input = id229out_output[getCycle()%13];

    id248out_output[(getCycle()+12)%13] = id248in_input;
  }
  { // Node ID: 249 (NodeFIFO)
    const HWFloat<8,24> &id249in_input = id248out_output[getCycle()%13];

    id249out_output[(getCycle()+4)%5] = id249in_input;
  }
  { // Node ID: 260 (NodeConstantRawBits)
  }
  { // Node ID: 99 (NodeMul)
    const HWFloat<8,24> &id99in_a = id260out_value;
    const HWFloat<8,24> &id99in_b = id229out_output[getCycle()%13];

    id99out_result[(getCycle()+8)%9] = (mul_float(id99in_a,id99in_b));
  }
  { // Node ID: 259 (NodeConstantRawBits)
  }
  { // Node ID: 10 (NodeCast)
    const HWOffsetFix<32,0,UNSIGNED> &id10in_i = id4out_nc;

    id10out_o[(getCycle()+6)%7] = (cast_fixed2float<8,24>(id10in_i));
  }
  { // Node ID: 12 (NodeDiv)
    const HWFloat<8,24> &id12in_a = id259out_value;
    const HWFloat<8,24> &id12in_b = id10out_o[getCycle()%7];

    id12out_result[(getCycle()+28)%29] = (div_float(id12in_a,id12in_b));
  }
  { // Node ID: 100 (NodeMul)
    const HWFloat<8,24> &id100in_a = id99out_result[getCycle()%9];
    const HWFloat<8,24> &id100in_b = id12out_result[getCycle()%29];

    id100out_result[(getCycle()+8)%9] = (mul_float(id100in_a,id100in_b));
  }
  { // Node ID: 101 (NodeAdd)
    const HWFloat<8,24> &id101in_a = id249out_output[getCycle()%5];
    const HWFloat<8,24> &id101in_b = id100out_result[getCycle()%9];

    id101out_result[(getCycle()+12)%13] = (add_float(id101in_a,id101in_b));
  }
  { // Node ID: 258 (NodeConstantRawBits)
  }
  { // Node ID: 103 (NodeMul)
    const HWFloat<8,24> &id103in_a = id258out_value;
    const HWFloat<8,24> &id103in_b = id248out_output[getCycle()%13];

    id103out_result[(getCycle()+8)%9] = (mul_float(id103in_a,id103in_b));
  }
  { // Node ID: 58 (NodeAdd)
    const HWFloat<8,24> &id58in_a = id212out_output[getCycle()%9];
    const HWFloat<8,24> &id58in_b = id57out_result[getCycle()%9];

    id58out_result[(getCycle()+12)%13] = (add_float(id58in_a,id58in_b));
  }
  { // Node ID: 104 (NodeMul)
    const HWFloat<8,24> &id104in_a = id103out_result[getCycle()%9];
    const HWFloat<8,24> &id104in_b = id58out_result[getCycle()%13];

    id104out_result[(getCycle()+8)%9] = (mul_float(id104in_a,id104in_b));
  }
  { // Node ID: 105 (NodeAdd)
    const HWFloat<8,24> &id105in_a = id101out_result[getCycle()%13];
    const HWFloat<8,24> &id105in_b = id104out_result[getCycle()%9];

    id105out_result[(getCycle()+12)%13] = (add_float(id105in_a,id105in_b));
  }
  { // Node ID: 235 (NodeFIFO)
    const HWFloat<8,24> &id235in_input = id105out_result[getCycle()%13];

    id235out_output[(getCycle()+8)%9] = id235in_input;
  }
  { // Node ID: 257 (NodeConstantRawBits)
  }
  { // Node ID: 107 (NodeMul)
    const HWFloat<8,24> &id107in_a = id257out_value;
    const HWFloat<8,24> &id107in_b = id249out_output[getCycle()%5];

    id107out_result[(getCycle()+8)%9] = (mul_float(id107in_a,id107in_b));
  }
  { // Node ID: 234 (NodeFIFO)
    const HWFloat<8,24> &id234in_input = id107out_result[getCycle()%9];

    id234out_output[(getCycle()+16)%17] = id234in_input;
  }
  { // Node ID: 108 (NodeMul)
    const HWFloat<8,24> &id108in_a = id58out_result[getCycle()%13];
    const HWFloat<8,24> &id108in_b = id58out_result[getCycle()%13];

    id108out_result[(getCycle()+8)%9] = (mul_float(id108in_a,id108in_b));
  }
  { // Node ID: 109 (NodeSub)
    const HWFloat<8,24> &id109in_a = id108out_result[getCycle()%9];
    const HWFloat<8,24> &id109in_b = id12out_result[getCycle()%29];

    id109out_result[(getCycle()+12)%13] = (sub_float(id109in_a,id109in_b));
  }
  { // Node ID: 110 (NodeMul)
    const HWFloat<8,24> &id110in_a = id234out_output[getCycle()%17];
    const HWFloat<8,24> &id110in_b = id109out_result[getCycle()%13];

    id110out_result[(getCycle()+8)%9] = (mul_float(id110in_a,id110in_b));
  }
  { // Node ID: 111 (NodeAdd)
    const HWFloat<8,24> &id111in_a = id235out_output[getCycle()%9];
    const HWFloat<8,24> &id111in_b = id110out_result[getCycle()%9];

    id111out_result[(getCycle()+12)%13] = (add_float(id111in_a,id111in_b));
  }
  { // Node ID: 227 (NodeFIFO)
    const HWFloat<8,24> &id227in_input = id111out_result[getCycle()%13];

    id227out_output[(getCycle()+33)%34] = id227in_input;
  }
  { // Node ID: 256 (NodeConstantRawBits)
  }
  { // Node ID: 125 (NodeSub)
    const HWFloat<8,24> &id125in_a = id227out_output[getCycle()%34];
    const HWFloat<8,24> &id125in_b = id256out_value;

    id125out_result[(getCycle()+12)%13] = (sub_float(id125in_a,id125in_b));
  }
  { // Node ID: 126 (NodeGt)
    const HWFloat<8,24> &id126in_a = id194out_value;
    const HWFloat<8,24> &id126in_b = id125out_result[getCycle()%13];

    id126out_result[(getCycle()+2)%3] = (gt_float(id126in_a,id126in_b));
  }
  { // Node ID: 237 (NodeFIFO)
    const HWFloat<8,24> &id237in_input = id125out_result[getCycle()%13];

    id237out_output[(getCycle()+2)%3] = id237in_input;
  }
  { // Node ID: 127 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id127in_sel = id126out_result[getCycle()%3];
    const HWFloat<8,24> &id127in_option0 = id237out_output[getCycle()%3];
    const HWFloat<8,24> &id127in_option1 = id194out_value;

    HWFloat<8,24> id127x_1;

    switch((id127in_sel.getValueAsLong())) {
      case 0l:
        id127x_1 = id127in_option0;
        break;
      case 1l:
        id127x_1 = id127in_option1;
        break;
      default:
        id127x_1 = (c_hw_flt_8_24_undef);
        break;
    }
    id127out_result[(getCycle()+1)%2] = (id127x_1);
  }
  { // Node ID: 129 (NodeMul)
    const HWFloat<8,24> &id129in_a = id263out_value;
    const HWFloat<8,24> &id129in_b = id127out_result[getCycle()%2];

    id129out_result[(getCycle()+8)%9] = (mul_float(id129in_a,id129in_b));
  }
  { // Node ID: 132 (NodeSub)
    const HWFloat<8,24> &id132in_a = id123out_result[getCycle()%9];
    const HWFloat<8,24> &id132in_b = id129out_result[getCycle()%9];

    id132out_result[(getCycle()+12)%13] = (sub_float(id132in_a,id132in_b));
  }
  { // Node ID: 238 (NodeFIFO)
    const HWFloat<8,24> &id238in_input = id123out_result[getCycle()%9];

    id238out_output[(getCycle()+12)%13] = id238in_input;
  }
  { // Node ID: 133 (NodeMux)
    const HWOffsetFix<1,0,UNSIGNED> &id133in_sel = id131out_result[getCycle()%2];
    const HWFloat<8,24> &id133in_option0 = id132out_result[getCycle()%13];
    const HWFloat<8,24> &id133in_option1 = id238out_output[getCycle()%13];

    HWFloat<8,24> id133x_1;

    switch((id133in_sel.getValueAsLong())) {
      case 0l:
        id133x_1 = id133in_option0;
        break;
      case 1l:
        id133x_1 = id133in_option1;
        break;
      default:
        id133x_1 = (c_hw_flt_8_24_undef);
        break;
    }
    id133out_result[(getCycle()+1)%2] = (id133x_1);
  }
  if ( (getFillLevel() >= (148l)) && (getFlushLevel() < (148l)|| !isFlushingActive() ))
  { // Node ID: 156 (NodeOutput)
    const HWOffsetFix<1,0,UNSIGNED> &id156in_output_control = id239out_output[getCycle()%142];
    const HWFloat<8,24> &id156in_data = id133out_result[getCycle()%2];

    bool id156x_1;

    (id156x_1) = ((id156in_output_control.getValueAsBool())&(!(((getFlushLevel())>=(148l))&(isFlushingActive()))));
    if((id156x_1)) {
      writeOutput(m_diff, id156in_data);
    }
  }
  { // Node ID: 255 (NodeConstantRawBits)
  }
  { // Node ID: 158 (NodeSub)
    const HWOffsetFix<32,0,UNSIGNED> &id158in_a = id4out_nc;
    const HWOffsetFix<32,0,UNSIGNED> &id158in_b = id255out_value;

    id158out_result[(getCycle()+1)%2] = (sub_fixed<32,0,UNSIGNED,TONEAR>(id158in_a,id158in_b));
  }
  { // Node ID: 159 (NodeEq)
    const HWOffsetFix<32,0,UNSIGNED> &id159in_a = id15out_count;
    const HWOffsetFix<32,0,UNSIGNED> &id159in_b = id158out_result[getCycle()%2];

    id159out_result[(getCycle()+1)%2] = (eq_fixed(id159in_a,id159in_b));
  }
  HWRawBits<1> id163out_output;

  { // Node ID: 163 (NodeReinterpret)
    const HWOffsetFix<1,0,UNSIGNED> &id163in_input = id159out_result[getCycle()%2];

    id163out_output = (cast_fixed2bits(id163in_input));
  }
  { // Node ID: 254 (NodeConstantRawBits)
  }
  { // Node ID: 161 (NodeEq)
    const HWOffsetFix<1,0,UNSIGNED> &id161in_a = id204out_output[getCycle()%2];
    const HWOffsetFix<1,0,UNSIGNED> &id161in_b = id254out_value;

    id161out_result[(getCycle()+1)%2] = (eq_fixed(id161in_a,id161in_b));
  }
  HWRawBits<1> id164out_output;

  { // Node ID: 164 (NodeReinterpret)
    const HWOffsetFix<1,0,UNSIGNED> &id164in_input = id161out_result[getCycle()%2];

    id164out_output = (cast_fixed2bits(id164in_input));
  }
  { // Node ID: 162 (NodeAnd)
    const HWRawBits<1> &id162in_a = id163out_output;
    const HWRawBits<1> &id162in_b = id164out_output;

    HWRawBits<1> id162x_1;

    (id162x_1) = (and_bits(id162in_a,id162in_b));
    id162out_result[(getCycle()+1)%2] = (id162x_1);
  }
  HWOffsetFix<1,0,UNSIGNED> id165out_output;

  { // Node ID: 165 (NodeReinterpret)
    const HWRawBits<1> &id165in_input = id162out_result[getCycle()%2];

    id165out_output = (cast_bits2fixed<1,0,UNSIGNED>(id165in_input));
  }
  HWRawBits<1> id170out_output;

  { // Node ID: 170 (NodeReinterpret)
    const HWOffsetFix<1,0,UNSIGNED> &id170in_input = id165out_output;

    id170out_output = (cast_fixed2bits(id170in_input));
  }
  { // Node ID: 253 (NodeConstantRawBits)
  }
  { // Node ID: 167 (NodeSub)
    const HWOffsetFix<32,0,UNSIGNED> &id167in_a = id250out_value;
    const HWOffsetFix<32,0,UNSIGNED> &id167in_b = id253out_value;

    id167out_result[(getCycle()+1)%2] = (sub_fixed<32,0,UNSIGNED,TONEAR>(id167in_a,id167in_b));
  }
  { // Node ID: 168 (NodeEq)
    const HWOffsetFix<32,0,UNSIGNED> &id168in_a = id205out_output[getCycle()%2];
    const HWOffsetFix<32,0,UNSIGNED> &id168in_b = id167out_result[getCycle()%2];

    id168out_result[(getCycle()+1)%2] = (eq_fixed(id168in_a,id168in_b));
  }
  { // Node ID: 242 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id242in_input = id168out_result[getCycle()%2];

    id242out_output[(getCycle()+1)%2] = id242in_input;
  }
  HWRawBits<1> id171out_output;

  { // Node ID: 171 (NodeReinterpret)
    const HWOffsetFix<1,0,UNSIGNED> &id171in_input = id242out_output[getCycle()%2];

    id171out_output = (cast_fixed2bits(id171in_input));
  }
  { // Node ID: 169 (NodeAnd)
    const HWRawBits<1> &id169in_a = id170out_output;
    const HWRawBits<1> &id169in_b = id171out_output;

    HWRawBits<1> id169x_1;

    (id169x_1) = (and_bits(id169in_a,id169in_b));
    id169out_result[(getCycle()+1)%2] = (id169x_1);
  }
  HWOffsetFix<1,0,UNSIGNED> id172out_output;

  { // Node ID: 172 (NodeReinterpret)
    const HWRawBits<1> &id172in_input = id169out_result[getCycle()%2];

    id172out_output = (cast_bits2fixed<1,0,UNSIGNED>(id172in_input));
  }
  HWRawBits<1> id176out_output;

  { // Node ID: 176 (NodeReinterpret)
    const HWOffsetFix<1,0,UNSIGNED> &id176in_input = id172out_output;

    id176out_output = (cast_fixed2bits(id176in_input));
  }
  { // Node ID: 173 (NodeInputMappedReg)
  }
  HWOffsetFix<1,0,UNSIGNED> id174out_result;

  { // Node ID: 174 (NodeNot)
    const HWOffsetFix<1,0,UNSIGNED> &id174in_a = id173out_io_fine_force_disabled;

    id174out_result = (not_fixed(id174in_a));
  }
  HWRawBits<1> id177out_output;

  { // Node ID: 177 (NodeReinterpret)
    const HWOffsetFix<1,0,UNSIGNED> &id177in_input = id174out_result;

    id177out_output = (cast_fixed2bits(id177in_input));
  }
  HWRawBits<1> id175out_result;

  { // Node ID: 175 (NodeAnd)
    const HWRawBits<1> &id175in_a = id176out_output;
    const HWRawBits<1> &id175in_b = id177out_output;

    HWRawBits<1> id175x_1;

    (id175x_1) = (and_bits(id175in_a,id175in_b));
    id175out_result = (id175x_1);
  }
  HWOffsetFix<1,0,UNSIGNED> id178out_output;

  { // Node ID: 178 (NodeReinterpret)
    const HWRawBits<1> &id178in_input = id175out_result;

    id178out_output = (cast_bits2fixed<1,0,UNSIGNED>(id178in_input));
  }
  { // Node ID: 243 (NodeFIFO)
    const HWOffsetFix<1,0,UNSIGNED> &id243in_input = id178out_output;

    id243out_output[(getCycle()+128)%129] = id243in_input;
  }
  if ( (getFillLevel() >= (135l)) && (getFlushLevel() < (135l)|| !isFlushingActive() ))
  { // Node ID: 179 (NodeOutput)
    const HWOffsetFix<1,0,UNSIGNED> &id179in_output_control = id243out_output[getCycle()%129];
    const HWFloat<8,24> &id179in_data = id123out_result[getCycle()%9];

    bool id179x_1;

    (id179x_1) = ((id179in_output_control.getValueAsBool())&(!(((getFlushLevel())>=(135l))&(isFlushingActive()))));
    if((id179x_1)) {
      writeOutput(m_fine, id179in_data);
    }
  }
  { // Node ID: 186 (NodeConstantRawBits)
  }
  { // Node ID: 252 (NodeConstantRawBits)
  }
  { // Node ID: 183 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (147l)))
  { // Node ID: 184 (NodeCounterV1)
    const HWOffsetFix<1,0,UNSIGNED> &id184in_enable = id252out_value;
    const HWOffsetFix<49,0,UNSIGNED> &id184in_max = id183out_value;

    HWOffsetFix<49,0,UNSIGNED> id184x_1;
    HWOffsetFix<1,0,UNSIGNED> id184x_2;
    HWOffsetFix<1,0,UNSIGNED> id184x_3;
    HWOffsetFix<49,0,UNSIGNED> id184x_4t_1e_1;

    id184out_count = (cast_fixed2fixed<48,0,UNSIGNED,TRUNCATE>((id184st_count)));
    (id184x_1) = (add_fixed<49,0,UNSIGNED,TRUNCATE>((id184st_count),(c_hw_fix_49_0_uns_bits_2)));
    (id184x_2) = (gte_fixed((id184x_1),id184in_max));
    (id184x_3) = (and_fixed((id184x_2),id184in_enable));
    id184out_wrap = (id184x_3);
    if((id184in_enable.getValueAsBool())) {
      if(((id184x_3).getValueAsBool())) {
        (id184st_count) = (c_hw_fix_49_0_uns_bits_1);
      }
      else {
        (id184x_4t_1e_1) = (id184x_1);
        (id184st_count) = (id184x_4t_1e_1);
      }
    }
    else {
    }
  }
  HWOffsetFix<48,0,UNSIGNED> id185out_output;

  { // Node ID: 185 (NodeStreamOffset)
    const HWOffsetFix<48,0,UNSIGNED> &id185in_input = id184out_count;

    id185out_output = id185in_input;
  }
  if ( (getFillLevel() >= (148l)) && (getFlushLevel() < (148l)|| !isFlushingActive() ))
  { // Node ID: 187 (NodeOutputMappedReg)
    const HWOffsetFix<1,0,UNSIGNED> &id187in_load = id186out_value;
    const HWOffsetFix<48,0,UNSIGNED> &id187in_data = id185out_output;

    bool id187x_1;

    (id187x_1) = ((id187in_load.getValueAsBool())&(!(((getFlushLevel())>=(148l))&(isFlushingActive()))));
    if((id187x_1)) {
      setMappedRegValue("current_run_cycle_count", id187in_data);
    }
  }
  { // Node ID: 251 (NodeConstantRawBits)
  }
  { // Node ID: 189 (NodeConstantRawBits)
  }
  if ( (getFillLevel() >= (0l)))
  { // Node ID: 190 (NodeCounterV1)
    const HWOffsetFix<1,0,UNSIGNED> &id190in_enable = id251out_value;
    const HWOffsetFix<49,0,UNSIGNED> &id190in_max = id189out_value;

    HWOffsetFix<49,0,UNSIGNED> id190x_1;
    HWOffsetFix<1,0,UNSIGNED> id190x_2;
    HWOffsetFix<1,0,UNSIGNED> id190x_3;
    HWOffsetFix<49,0,UNSIGNED> id190x_4t_1e_1;

    id190out_count = (cast_fixed2fixed<48,0,UNSIGNED,TRUNCATE>((id190st_count)));
    (id190x_1) = (add_fixed<49,0,UNSIGNED,TRUNCATE>((id190st_count),(c_hw_fix_49_0_uns_bits_2)));
    (id190x_2) = (gte_fixed((id190x_1),id190in_max));
    (id190x_3) = (and_fixed((id190x_2),id190in_enable));
    id190out_wrap = (id190x_3);
    if((id190in_enable.getValueAsBool())) {
      if(((id190x_3).getValueAsBool())) {
        (id190st_count) = (c_hw_fix_49_0_uns_bits_1);
      }
      else {
        (id190x_4t_1e_1) = (id190x_1);
        (id190st_count) = (id190x_4t_1e_1);
      }
    }
    else {
    }
  }
  { // Node ID: 192 (NodeInputMappedReg)
  }
  { // Node ID: 193 (NodeEq)
    const HWOffsetFix<48,0,UNSIGNED> &id193in_a = id190out_count;
    const HWOffsetFix<48,0,UNSIGNED> &id193in_b = id192out_run_cycle_count;

    id193out_result[(getCycle()+1)%2] = (eq_fixed(id193in_a,id193in_b));
  }
  if ( (getFillLevel() >= (1l)))
  { // Node ID: 191 (NodeFlush)
    const HWOffsetFix<1,0,UNSIGNED> &id191in_start = id193out_result[getCycle()%2];

    if((id191in_start.getValueAsBool())) {
      startFlushing();
    }
  }
};

};
