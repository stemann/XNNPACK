// Auto-generated file. Do not edit!
//   Template: src/cs16-fftr/scalar.c.in
//   Generator: tools/xngen
//
// Copyright 2022 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.

#include <assert.h>
#include <stddef.h>
#include <stdint.h>

#include <xnnpack/math.h>
#include <xnnpack/fft.h>


void xnn_cs16_fftr_ukernel__scalar_x4(
    size_t samples,
    int16_t* data,
    const int16_t* twiddle)
{
  assert(samples >= 2);
  assert(samples % 2 == 0);
  assert(data != NULL);
  assert(data != NULL);
  assert(twiddle != NULL);

  int16_t* dl = data;
  int16_t* dr = data + samples * 2;
  int32_t vdcr = (int32_t) dl[0];
  int32_t vdci = (int32_t) dl[1];

  vdcr = math_asr_s32(vdcr * 16383 + 16384, 15);
  vdci = math_asr_s32(vdci * 16383 + 16384, 15);

  dl[0] = vdcr + vdci;
  dl[1] = 0;
  dl += 2;
  dr[0] = vdcr - vdci;
  dr[1] = 0;

  samples >>= 1;

  for (; samples >= 4; samples -= 4) {
    dr -= 4 * 2;
    int32_t vilr0 = dl[0];
    int32_t vili0 = dl[1];
    int32_t vilr1 = dl[2];
    int32_t vili1 = dl[3];
    int32_t vilr2 = dl[4];
    int32_t vili2 = dl[5];
    int32_t vilr3 = dl[6];
    int32_t vili3 = dl[7];
    int32_t virr0 =  (int32_t) dr[6];
    int32_t viri0 = -(int32_t) dr[7];
    int32_t virr1 =  (int32_t) dr[4];
    int32_t viri1 = -(int32_t) dr[5];
    int32_t virr2 =  (int32_t) dr[2];
    int32_t viri2 = -(int32_t) dr[3];
    int32_t virr3 =  (int32_t) dr[0];
    int32_t viri3 = -(int32_t) dr[1];
    const int32_t vtwr0 = twiddle[0];
    const int32_t vtwi0 = twiddle[1];
    const int32_t vtwr1 = twiddle[2];
    const int32_t vtwi1 = twiddle[3];
    const int32_t vtwr2 = twiddle[4];
    const int32_t vtwi2 = twiddle[5];
    const int32_t vtwr3 = twiddle[6];
    const int32_t vtwi3 = twiddle[7];
    twiddle += 4 * 2;

    vilr0 = math_asr_s32(vilr0 * 16383 + 16384, 15);
    virr0 = math_asr_s32(virr0 * 16383 + 16384, 15);
    vilr1 = math_asr_s32(vilr1 * 16383 + 16384, 15);
    virr1 = math_asr_s32(virr1 * 16383 + 16384, 15);
    vilr2 = math_asr_s32(vilr2 * 16383 + 16384, 15);
    virr2 = math_asr_s32(virr2 * 16383 + 16384, 15);
    vilr3 = math_asr_s32(vilr3 * 16383 + 16384, 15);
    virr3 = math_asr_s32(virr3 * 16383 + 16384, 15);
    vili0 = math_asr_s32(vili0 * 16383 + 16384, 15);
    viri0 = math_asr_s32(viri0 * 16383 + 16384, 15);
    vili1 = math_asr_s32(vili1 * 16383 + 16384, 15);
    viri1 = math_asr_s32(viri1 * 16383 + 16384, 15);
    vili2 = math_asr_s32(vili2 * 16383 + 16384, 15);
    viri2 = math_asr_s32(viri2 * 16383 + 16384, 15);
    vili3 = math_asr_s32(vili3 * 16383 + 16384, 15);
    viri3 = math_asr_s32(viri3 * 16383 + 16384, 15);
    const int32_t vacc1r0 = vilr0 + virr0;
    const int32_t vacc2r0 = vilr0 - virr0;
    const int32_t vacc1r1 = vilr1 + virr1;
    const int32_t vacc2r1 = vilr1 - virr1;
    const int32_t vacc1r2 = vilr2 + virr2;
    const int32_t vacc2r2 = vilr2 - virr2;
    const int32_t vacc1r3 = vilr3 + virr3;
    const int32_t vacc2r3 = vilr3 - virr3;
    const int32_t vacc1i0 = vili0 + viri0;
    const int32_t vacc2i0 = vili0 - viri0;
    const int32_t vacc1i1 = vili1 + viri1;
    const int32_t vacc2i1 = vili1 - viri1;
    const int32_t vacc1i2 = vili2 + viri2;
    const int32_t vacc2i2 = vili2 - viri2;
    const int32_t vacc1i3 = vili3 + viri3;
    const int32_t vacc2i3 = vili3 - viri3;

    const int32_t twr0 = math_asr_s32(vacc2r0 * vtwr0 - vacc2i0 * vtwi0 + 16384, 15);
    const int32_t twr1 = math_asr_s32(vacc2r1 * vtwr1 - vacc2i1 * vtwi1 + 16384, 15);
    const int32_t twr2 = math_asr_s32(vacc2r2 * vtwr2 - vacc2i2 * vtwi2 + 16384, 15);
    const int32_t twr3 = math_asr_s32(vacc2r3 * vtwr3 - vacc2i3 * vtwi3 + 16384, 15);
    const int32_t twi0 = math_asr_s32(vacc2r0 * vtwi0 + vacc2i0 * vtwr0 + 16384, 15);
    const int32_t twi1 = math_asr_s32(vacc2r1 * vtwi1 + vacc2i1 * vtwr1 + 16384, 15);
    const int32_t twi2 = math_asr_s32(vacc2r2 * vtwi2 + vacc2i2 * vtwr2 + 16384, 15);
    const int32_t twi3 = math_asr_s32(vacc2r3 * vtwi3 + vacc2i3 * vtwr3 + 16384, 15);

    dl[0] = math_asr_s32(vacc1r0 + twr0, 1);
    dl[1] = math_asr_s32(vacc1i0 + twi0, 1);
    dl[2] = math_asr_s32(vacc1r1 + twr1, 1);
    dl[3] = math_asr_s32(vacc1i1 + twi1, 1);
    dl[4] = math_asr_s32(vacc1r2 + twr2, 1);
    dl[5] = math_asr_s32(vacc1i2 + twi2, 1);
    dl[6] = math_asr_s32(vacc1r3 + twr3, 1);
    dl[7] = math_asr_s32(vacc1i3 + twi3, 1);
    dr[6] = math_asr_s32(vacc1r0 - twr0, 1);
    dr[7] = math_asr_s32(twi0 - vacc1i0, 1);
    dr[4] = math_asr_s32(vacc1r1 - twr1, 1);
    dr[5] = math_asr_s32(twi1 - vacc1i1, 1);
    dr[2] = math_asr_s32(vacc1r2 - twr2, 1);
    dr[3] = math_asr_s32(twi2 - vacc1i2, 1);
    dr[0] = math_asr_s32(vacc1r3 - twr3, 1);
    dr[1] = math_asr_s32(twi3 - vacc1i3, 1);
    dl += 4 * 2;
  }

  if XNN_UNLIKELY(samples != 0) {
    do {
      dr -= 2;
      int32_t vilr = dl[0];
      int32_t vili = dl[1];
      int32_t virr =  (int32_t) dr[0];
      int32_t viri = -(int32_t) dr[1];
      const int32_t vtwr = twiddle[0];
      const int32_t vtwi = twiddle[1];
      twiddle += 2;

      vilr =  math_asr_s32(vilr * 16383 + 16384, 15);
      vili =  math_asr_s32(vili * 16383 + 16384, 15);
      virr = math_asr_s32(virr * 16383 + 16384, 15);
      viri = math_asr_s32(viri * 16383 + 16384, 15);
      const int32_t vacc1r = vilr + virr;
      const int32_t vacc1i = vili + viri;
      const int32_t vacc2r = vilr - virr;
      const int32_t vacc2i = vili - viri;

      const int32_t twr = math_asr_s32(vacc2r * vtwr - vacc2i * vtwi + 16384, 15);
      const int32_t twi = math_asr_s32(vacc2r * vtwi + vacc2i * vtwr + 16384, 15);

      dl[0] = math_asr_s32(vacc1r + twr, 1);
      dl[1] = math_asr_s32(vacc1i + twi, 1);
      dr[0] = math_asr_s32(vacc1r - twr, 1);
      dr[1] = math_asr_s32(twi - vacc1i, 1);
      dl += 2;
    } while (--samples != 0);
  }
}
