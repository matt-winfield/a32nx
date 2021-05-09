#include "AutopilotLaws.h"
#include "AutopilotLaws_private.h"
#include "look1_binlxpw.h"
#include "rt_modd.h"

const uint8_T AutopilotLaws_IN_any = 1U;
const uint8_T AutopilotLaws_IN_left = 2U;
const uint8_T AutopilotLaws_IN_right = 3U;
const uint8_T AutopilotLaws_IN_any_g = 1U;
const uint8_T AutopilotLaws_IN_left_m = 2U;
const uint8_T AutopilotLaws_IN_right_o = 3U;
const uint8_T AutopilotLaws_IN_InAir = 1U;
const uint8_T AutopilotLaws_IN_OnGround = 2U;
void AutopilotLawsModelClass::AutopilotLaws_Chart(real_T rtu_right, real_T rtu_left, boolean_T rtu_use_short_path,
  real_T *rty_out, rtDW_Chart_AutopilotLaws_T *localDW)
{
  real_T tmp;
  real_T tmp_0;
  boolean_T tmp_1;
  if (localDW->is_active_c3_sUPy3BXaP8VT23gJSge3dZD_ap_library == 0U) {
    localDW->is_active_c3_sUPy3BXaP8VT23gJSge3dZD_ap_library = 1U;
    localDW->is_c3_sUPy3BXaP8VT23gJSge3dZD_ap_library = AutopilotLaws_IN_any;
    if (std::abs(rtu_left) < std::abs(rtu_right)) {
      *rty_out = rtu_left;
    } else {
      *rty_out = rtu_right;
    }
  } else {
    switch (localDW->is_c3_sUPy3BXaP8VT23gJSge3dZD_ap_library) {
     case AutopilotLaws_IN_any:
      tmp = std::abs(rtu_right);
      tmp_0 = std::abs(rtu_left);
      tmp_1 = !rtu_use_short_path;
      if (tmp_1 && (tmp < tmp_0) && (tmp >= 10.0) && (tmp <= 20.0)) {
        localDW->is_c3_sUPy3BXaP8VT23gJSge3dZD_ap_library = AutopilotLaws_IN_right;
        *rty_out = rtu_right;
      } else if (tmp_1 && (tmp_0 < tmp) && (tmp_0 >= 10.0) && (tmp_0 <= 20.0)) {
        localDW->is_c3_sUPy3BXaP8VT23gJSge3dZD_ap_library = AutopilotLaws_IN_left;
        *rty_out = rtu_left;
      } else if (tmp_0 < tmp) {
        *rty_out = rtu_left;
      } else {
        *rty_out = rtu_right;
      }
      break;

     case AutopilotLaws_IN_left:
      tmp = std::abs(rtu_left);
      tmp_0 = std::abs(rtu_right);
      if (rtu_use_short_path || (tmp_0 < 10.0) || (tmp < 10.0)) {
        localDW->is_c3_sUPy3BXaP8VT23gJSge3dZD_ap_library = AutopilotLaws_IN_any;
        if (tmp < tmp_0) {
          *rty_out = rtu_left;
        } else {
          *rty_out = rtu_right;
        }
      } else {
        *rty_out = rtu_left;
      }
      break;

     default:
      tmp = std::abs(rtu_left);
      tmp_0 = std::abs(rtu_right);
      if (rtu_use_short_path || (tmp_0 < 10.0) || (tmp < 10.0)) {
        localDW->is_c3_sUPy3BXaP8VT23gJSge3dZD_ap_library = AutopilotLaws_IN_any;
        if (tmp < tmp_0) {
          *rty_out = rtu_left;
        } else {
          *rty_out = rtu_right;
        }
      } else {
        *rty_out = rtu_right;
      }
      break;
    }
  }
}

void AutopilotLawsModelClass::AutopilotLaws_LagFilter(real_T rtu_U, real_T rtu_C1, real_T rtu_dt, real_T *rty_Y,
  rtDW_LagFilter_AutopilotLaws_T *localDW)
{
  real_T ca;
  real_T denom_tmp;
  if ((!localDW->pY_not_empty) || (!localDW->pU_not_empty)) {
    localDW->pU = rtu_U;
    localDW->pU_not_empty = true;
    localDW->pY = rtu_U;
    localDW->pY_not_empty = true;
  }

  denom_tmp = rtu_dt * rtu_C1;
  ca = denom_tmp / (denom_tmp + 2.0);
  *rty_Y = (2.0 - denom_tmp) / (denom_tmp + 2.0) * localDW->pY + (rtu_U * ca + localDW->pU * ca);
  localDW->pY = *rty_Y;
  localDW->pU = rtu_U;
}

void AutopilotLawsModelClass::AutopilotLaws_Chart_j(real_T rtu_right, real_T rtu_left, real_T rtu_use_short_path, real_T
  *rty_out, rtDW_Chart_AutopilotLaws_c_T *localDW)
{
  real_T tmp;
  real_T tmp_0;
  if (localDW->is_active_c3_sQHqjOt6dG4nwhom4nTqEME_ap_library == 0U) {
    localDW->is_active_c3_sQHqjOt6dG4nwhom4nTqEME_ap_library = 1U;
    localDW->is_c3_sQHqjOt6dG4nwhom4nTqEME_ap_library = AutopilotLaws_IN_any_g;
    if (std::abs(rtu_left) < std::abs(rtu_right)) {
      *rty_out = rtu_left;
    } else {
      *rty_out = rtu_right;
    }
  } else {
    switch (localDW->is_c3_sQHqjOt6dG4nwhom4nTqEME_ap_library) {
     case AutopilotLaws_IN_any_g:
      tmp = std::abs(rtu_right);
      tmp_0 = std::abs(rtu_left);
      if ((rtu_use_short_path == 0.0) && (tmp < tmp_0) && (tmp >= 10.0) && (tmp <= 20.0)) {
        localDW->is_c3_sQHqjOt6dG4nwhom4nTqEME_ap_library = AutopilotLaws_IN_right_o;
        *rty_out = rtu_right;
      } else if ((rtu_use_short_path == 0.0) && (tmp_0 < tmp) && (tmp_0 >= 10.0) && (tmp_0 <= 20.0)) {
        localDW->is_c3_sQHqjOt6dG4nwhom4nTqEME_ap_library = AutopilotLaws_IN_left_m;
        *rty_out = rtu_left;
      } else if (tmp_0 < tmp) {
        *rty_out = rtu_left;
      } else {
        *rty_out = rtu_right;
      }
      break;

     case AutopilotLaws_IN_left_m:
      tmp = std::abs(rtu_left);
      tmp_0 = std::abs(rtu_right);
      if ((rtu_use_short_path != 0.0) || (tmp_0 < 10.0) || (tmp < 10.0)) {
        localDW->is_c3_sQHqjOt6dG4nwhom4nTqEME_ap_library = AutopilotLaws_IN_any_g;
        if (tmp < tmp_0) {
          *rty_out = rtu_left;
        } else {
          *rty_out = rtu_right;
        }
      } else {
        *rty_out = rtu_left;
      }
      break;

     default:
      tmp = std::abs(rtu_left);
      tmp_0 = std::abs(rtu_right);
      if ((rtu_use_short_path != 0.0) || (tmp_0 < 10.0) || (tmp < 10.0)) {
        localDW->is_c3_sQHqjOt6dG4nwhom4nTqEME_ap_library = AutopilotLaws_IN_any_g;
        if (tmp < tmp_0) {
          *rty_out = rtu_left;
        } else {
          *rty_out = rtu_right;
        }
      } else {
        *rty_out = rtu_right;
      }
      break;
    }
  }
}

void AutopilotLawsModelClass::AutopilotLaws_storevalue(boolean_T rtu_active, real_T rtu_u, real_T *rty_y,
  rtDW_storevalue_AutopilotLaws_T *localDW)
{
  if ((!rtu_active) || (!localDW->storage_not_empty)) {
    localDW->storage = rtu_u;
    localDW->storage_not_empty = true;
  }

  *rty_y = localDW->storage;
}

void AutopilotLawsModelClass::AutopilotLaws_RateLimiter(real_T rtu_u, real_T rtu_up, real_T rtu_lo, real_T rtu_Ts,
  real_T rtu_init, real_T *rty_Y, rtDW_RateLimiter_AutopilotLaws_T *localDW)
{
  real_T u0;
  real_T u1;
  if (!localDW->pY_not_empty) {
    localDW->pY = rtu_init;
    localDW->pY_not_empty = true;
  }

  u0 = rtu_u - localDW->pY;
  u1 = rtu_up * rtu_Ts;
  if (u0 < u1) {
    u1 = u0;
  }

  u0 = rtu_lo * rtu_Ts;
  if (u1 > u0) {
    u0 = u1;
  }

  localDW->pY += u0;
  *rty_Y = localDW->pY;
}

void AutopilotLawsModelClass::AutopilotLaws_WashoutFilter(real_T rtu_U, real_T rtu_C1, real_T rtu_dt, real_T *rty_Y,
  rtDW_WashoutFilter_AutopilotLaws_T *localDW)
{
  real_T ca;
  real_T denom_tmp;
  if ((!localDW->pY_not_empty) || (!localDW->pU_not_empty)) {
    localDW->pU = rtu_U;
    localDW->pU_not_empty = true;
    localDW->pY = rtu_U;
    localDW->pY_not_empty = true;
  }

  denom_tmp = rtu_dt * rtu_C1;
  ca = 2.0 / (denom_tmp + 2.0);
  *rty_Y = (2.0 - denom_tmp) / (denom_tmp + 2.0) * localDW->pY + (rtu_U * ca - localDW->pU * ca);
  localDW->pY = *rty_Y;
  localDW->pU = rtu_U;
}

void AutopilotLawsModelClass::AutopilotLaws_Voter1(real_T rtu_u1, real_T rtu_u2, real_T rtu_u3, real_T *rty_Y)
{
  real_T x[3];
  int32_T rtu_u1_0;
  x[0] = rtu_u1;
  x[1] = rtu_u2;
  x[2] = rtu_u3;
  if (rtu_u1 < rtu_u2) {
    if (rtu_u2 < rtu_u3) {
      rtu_u1_0 = 1;
    } else if (rtu_u1 < rtu_u3) {
      rtu_u1_0 = 2;
    } else {
      rtu_u1_0 = 0;
    }
  } else if (rtu_u1 < rtu_u3) {
    rtu_u1_0 = 0;
  } else if (rtu_u2 < rtu_u3) {
    rtu_u1_0 = 2;
  } else {
    rtu_u1_0 = 1;
  }

  *rty_Y = x[rtu_u1_0];
}

void AutopilotLawsModelClass::step()
{
  real_T result_tmp[9];
  real_T result[3];
  real_T result_0[3];
  real_T rtb_Gain4;
  real_T rtb_Gain5;
  real_T rtb_GainTheta;
  real_T rtb_GainTheta1;
  real_T rtb_Gain_a4z;
  real_T rtb_Gain_hf;
  real_T rtb_Gain_jf;
  real_T rtb_Gain_m;
  real_T rtb_Gain_mc;
  real_T rtb_Gain_ny;
  real_T rtb_Gain_p;
  real_T rtb_ManualSwitch;
  real_T rtb_Mod2;
  real_T rtb_Mod2_f;
  real_T rtb_Mod2_k;
  real_T rtb_Saturation;
  real_T rtb_Saturation1;
  real_T rtb_Sum2_d;
  real_T rtb_Sum2_j;
  real_T rtb_Sum_am;
  real_T rtb_Sum_ib_tmp;
  real_T rtb_Sum_k;
  real_T rtb_Vz;
  real_T rtb_Y_m;
  real_T rtb_Y_p;
  real_T rtb_out_c;
  int32_T i;
  int32_T rtb_BusAssignment_output_ap_on;
  int32_T rtb_on_ground;
  boolean_T rtb_Compare;
  boolean_T rtb_Delay_hu;
  boolean_T rtb_Delay_n;
  rtb_GainTheta = AutopilotLaws_P.GainTheta_Gain * AutopilotLaws_U.in.data.Theta_deg;
  rtb_GainTheta1 = AutopilotLaws_P.GainTheta1_Gain * AutopilotLaws_U.in.data.Phi_deg;
  rtb_Saturation = 0.017453292519943295 * rtb_GainTheta;
  rtb_Saturation1 = 0.017453292519943295 * rtb_GainTheta1;
  rtb_ManualSwitch = std::tan(rtb_Saturation);
  rtb_Mod2 = std::sin(rtb_Saturation1);
  rtb_Mod2_k = std::cos(rtb_Saturation1);
  result_tmp[0] = 1.0;
  result_tmp[3] = rtb_Mod2 * rtb_ManualSwitch;
  result_tmp[6] = rtb_Mod2_k * rtb_ManualSwitch;
  result_tmp[1] = 0.0;
  result_tmp[4] = rtb_Mod2_k;
  result_tmp[7] = -rtb_Mod2;
  result_tmp[2] = 0.0;
  rtb_Gain_mc = 1.0 / std::cos(rtb_Saturation);
  result_tmp[5] = rtb_Gain_mc * rtb_Mod2;
  result_tmp[8] = rtb_Gain_mc * rtb_Mod2_k;
  rtb_Mod2 = AutopilotLaws_P.Gain_Gain_de * AutopilotLaws_U.in.data.p_rad_s * AutopilotLaws_P.Gainpk_Gain;
  rtb_Mod2_k = AutopilotLaws_P.Gain_Gain_d * AutopilotLaws_U.in.data.q_rad_s * AutopilotLaws_P.Gainqk_Gain;
  rtb_ManualSwitch = AutopilotLaws_P.Gain_Gain_m * AutopilotLaws_U.in.data.r_rad_s;
  for (rtb_on_ground = 0; rtb_on_ground < 3; rtb_on_ground++) {
    result[rtb_on_ground] = result_tmp[rtb_on_ground + 6] * rtb_ManualSwitch + (result_tmp[rtb_on_ground + 3] *
      rtb_Mod2_k + result_tmp[rtb_on_ground] * rtb_Mod2);
  }

  rtb_ManualSwitch = std::cos(rtb_Saturation);
  rtb_Mod2 = std::sin(rtb_Saturation);
  rtb_Mod2_k = std::sin(rtb_Saturation1);
  rtb_Saturation = std::cos(rtb_Saturation1);
  result_tmp[0] = rtb_ManualSwitch;
  result_tmp[3] = 0.0;
  result_tmp[6] = -rtb_Mod2;
  result_tmp[1] = rtb_Mod2_k * rtb_Mod2;
  result_tmp[4] = rtb_Saturation;
  result_tmp[7] = rtb_ManualSwitch * rtb_Mod2_k;
  result_tmp[2] = rtb_Saturation * rtb_Mod2;
  result_tmp[5] = 0.0 - rtb_Mod2_k;
  result_tmp[8] = rtb_Saturation * rtb_ManualSwitch;
  for (rtb_on_ground = 0; rtb_on_ground < 3; rtb_on_ground++) {
    result_0[rtb_on_ground] = result_tmp[rtb_on_ground + 6] * AutopilotLaws_U.in.data.bz_m_s2 +
      (result_tmp[rtb_on_ground + 3] * AutopilotLaws_U.in.data.by_m_s2 + result_tmp[rtb_on_ground] *
       AutopilotLaws_U.in.data.bx_m_s2);
  }

  rtb_Saturation = AutopilotLaws_P.Gain_Gain_nz * AutopilotLaws_U.in.data.gear_strut_compression_1 -
    AutopilotLaws_P.Constant1_Value_b;
  if (rtb_Saturation > AutopilotLaws_P.Saturation_UpperSat_p) {
    rtb_Saturation = AutopilotLaws_P.Saturation_UpperSat_p;
  } else {
    if (rtb_Saturation < AutopilotLaws_P.Saturation_LowerSat_g) {
      rtb_Saturation = AutopilotLaws_P.Saturation_LowerSat_g;
    }
  }

  rtb_Saturation1 = AutopilotLaws_P.Gain1_Gain_ll * AutopilotLaws_U.in.data.gear_strut_compression_2 -
    AutopilotLaws_P.Constant1_Value_b;
  if (rtb_Saturation1 > AutopilotLaws_P.Saturation1_UpperSat_j) {
    rtb_Saturation1 = AutopilotLaws_P.Saturation1_UpperSat_j;
  } else {
    if (rtb_Saturation1 < AutopilotLaws_P.Saturation1_LowerSat_d) {
      rtb_Saturation1 = AutopilotLaws_P.Saturation1_LowerSat_d;
    }
  }

  if (AutopilotLaws_DWork.is_active_c5_AutopilotLaws == 0U) {
    AutopilotLaws_DWork.is_active_c5_AutopilotLaws = 1U;
    AutopilotLaws_DWork.is_c5_AutopilotLaws = AutopilotLaws_IN_OnGround;
    rtb_on_ground = 1;
  } else if (AutopilotLaws_DWork.is_c5_AutopilotLaws == 1) {
    if ((rtb_Saturation > 0.05) || (rtb_Saturation1 > 0.05)) {
      AutopilotLaws_DWork.is_c5_AutopilotLaws = AutopilotLaws_IN_OnGround;
      rtb_on_ground = 1;
    } else {
      rtb_on_ground = 0;
    }
  } else {
    if ((rtb_Saturation == 0.0) && (rtb_Saturation1 == 0.0)) {
      AutopilotLaws_DWork.is_c5_AutopilotLaws = AutopilotLaws_IN_InAir;
      rtb_on_ground = 0;
    } else {
      rtb_on_ground = 1;
    }
  }

  rtb_BusAssignment_output_ap_on = ((AutopilotLaws_U.in.input.enabled_AP1 != 0.0) ||
    (AutopilotLaws_U.in.input.enabled_AP2 != 0.0));
  rtb_Saturation = AutopilotLaws_P.Gain3_Gain_a * AutopilotLaws_U.in.data.nav_gs_deg;
  rtb_Saturation1 = rt_modd((AutopilotLaws_U.in.data.Psi_magnetic_deg - (AutopilotLaws_U.in.data.nav_loc_deg +
    AutopilotLaws_P.Constant3_Value_e)) + AutopilotLaws_P.Constant3_Value_e, AutopilotLaws_P.Constant3_Value_e);
  rtb_Mod2 = rt_modd(AutopilotLaws_P.Constant3_Value_e - rtb_Saturation1, AutopilotLaws_P.Constant3_Value_e);
  if (AutopilotLaws_P.ManualSwitch_CurrentSetting == 1) {
    rtb_ManualSwitch = AutopilotLaws_P.Constant_Value;
  } else {
    rtb_ManualSwitch = AutopilotLaws_U.in.input.lateral_law;
  }

  rtb_Compare = (rtb_ManualSwitch == AutopilotLaws_P.CompareToConstant2_const);
  if (rtb_Saturation1 < rtb_Mod2) {
    rtb_Saturation1 *= AutopilotLaws_P.Gain1_Gain;
  } else {
    rtb_Saturation1 = AutopilotLaws_P.Gain_Gain * rtb_Mod2;
  }

  rtb_Saturation1 = std::abs(rtb_Saturation1);
  if (!AutopilotLaws_DWork.limit_not_empty) {
    AutopilotLaws_DWork.limit = rtb_Saturation1;
    AutopilotLaws_DWork.limit_not_empty = true;
  }

  if (!rtb_Compare) {
    if (rtb_Saturation1 > 15.0) {
      AutopilotLaws_DWork.limit = rtb_Saturation1;
    } else {
      AutopilotLaws_DWork.limit = 15.0;
    }

    if (AutopilotLaws_DWork.limit >= 115.0) {
      AutopilotLaws_DWork.limit = 115.0;
    }
  }

  if (rtb_Compare && (rtb_Saturation1 < 15.0)) {
    AutopilotLaws_DWork.limit = 15.0;
  }

  if (AutopilotLaws_U.in.data.nav_dme_nmi > AutopilotLaws_P.Saturation_UpperSat_c) {
    rtb_Gain_mc = AutopilotLaws_P.Saturation_UpperSat_c;
  } else if (AutopilotLaws_U.in.data.nav_dme_nmi < AutopilotLaws_P.Saturation_LowerSat_d) {
    rtb_Gain_mc = AutopilotLaws_P.Saturation_LowerSat_d;
  } else {
    rtb_Gain_mc = AutopilotLaws_U.in.data.nav_dme_nmi;
  }

  rtb_Mod2_k = std::sin(AutopilotLaws_P.Gain1_Gain_g * AutopilotLaws_U.in.data.nav_loc_error_deg) * rtb_Gain_mc;
  rtb_Saturation1 = rtb_Mod2_k * look1_binlxpw(AutopilotLaws_U.in.data.nav_dme_nmi,
    AutopilotLaws_P.ScheduledGain_BreakpointsForDimension1, AutopilotLaws_P.ScheduledGain_Table, 4U);
  rtb_Mod2_k = look1_binlxpw(rtb_Mod2_k, AutopilotLaws_P.ScheduledGain3_BreakpointsForDimension1,
    AutopilotLaws_P.ScheduledGain3_Table, 3U);
  rtb_Saturation1 *= rtb_Mod2_k;
  rtb_Mod2 = rt_modd((AutopilotLaws_U.in.data.Psi_magnetic_track_deg - (rt_modd(rt_modd
    (AutopilotLaws_U.in.data.nav_loc_error_deg + AutopilotLaws_U.in.data.nav_loc_deg, AutopilotLaws_P.Constant3_Value_m)
    + AutopilotLaws_P.Constant3_Value_m, AutopilotLaws_P.Constant3_Value_m) + AutopilotLaws_P.Constant3_Value_a)) +
                     AutopilotLaws_P.Constant3_Value_a, AutopilotLaws_P.Constant3_Value_a);
  rtb_Mod2_k = rt_modd(AutopilotLaws_P.Constant3_Value_a - rtb_Mod2, AutopilotLaws_P.Constant3_Value_a);
  if (rtb_Saturation1 > AutopilotLaws_DWork.limit) {
    rtb_Saturation1 = AutopilotLaws_DWork.limit;
  } else {
    if (rtb_Saturation1 < -AutopilotLaws_DWork.limit) {
      rtb_Saturation1 = -AutopilotLaws_DWork.limit;
    }
  }

  if (rtb_Mod2 < rtb_Mod2_k) {
    rtb_Mod2 *= AutopilotLaws_P.Gain1_Gain_p;
  } else {
    rtb_Mod2 = AutopilotLaws_P.Gain_Gain_p * rtb_Mod2_k;
  }

  rtb_Saturation1 = (rtb_Saturation1 + rtb_Mod2) * look1_binlxpw(AutopilotLaws_U.in.data.V_gnd_kn,
    AutopilotLaws_P.ScheduledGain1_BreakpointsForDimension1, AutopilotLaws_P.ScheduledGain1_Table, 3U) * look1_binlxpw
    (AutopilotLaws_U.in.data.V_tas_kn, AutopilotLaws_P.ScheduledGain2_BreakpointsForDimension1,
     AutopilotLaws_P.ScheduledGain2_Table, 5U);
  rtb_Mod2 = rt_modd((AutopilotLaws_U.in.data.nav_loc_deg - (AutopilotLaws_U.in.data.Psi_magnetic_deg +
    AutopilotLaws_P.Constant3_Value_j)) + AutopilotLaws_P.Constant3_Value_j, AutopilotLaws_P.Constant3_Value_j);
  AutopilotLaws_Chart_j(rtb_Mod2, AutopilotLaws_P.Gain_Gain_nj * rt_modd(AutopilotLaws_P.Constant3_Value_j - rtb_Mod2,
    AutopilotLaws_P.Constant3_Value_j), AutopilotLaws_P.Constant2_Value, &rtb_out_c, &AutopilotLaws_DWork.sf_Chart_j);
  if (AutopilotLaws_U.in.data.nav_dme_nmi > AutopilotLaws_P.Saturation_UpperSat_o) {
    rtb_Gain_mc = AutopilotLaws_P.Saturation_UpperSat_o;
  } else if (AutopilotLaws_U.in.data.nav_dme_nmi < AutopilotLaws_P.Saturation_LowerSat_o) {
    rtb_Gain_mc = AutopilotLaws_P.Saturation_LowerSat_o;
  } else {
    rtb_Gain_mc = AutopilotLaws_U.in.data.nav_dme_nmi;
  }

  rtb_Mod2_k = std::sin(AutopilotLaws_P.Gain1_Gain_h5 * AutopilotLaws_U.in.data.nav_loc_error_deg) * rtb_Gain_mc *
    AutopilotLaws_P.Gain2_Gain_g;
  if (rtb_Mod2_k > AutopilotLaws_P.Saturation1_UpperSat_g) {
    rtb_Mod2_k = AutopilotLaws_P.Saturation1_UpperSat_g;
  } else {
    if (rtb_Mod2_k < AutopilotLaws_P.Saturation1_LowerSat_k) {
      rtb_Mod2_k = AutopilotLaws_P.Saturation1_LowerSat_k;
    }
  }

  rtb_Compare = (rtb_ManualSwitch == AutopilotLaws_P.CompareToConstant_const);
  if (!rtb_Compare) {
    AutopilotLaws_DWork.Delay_DSTATE = AutopilotLaws_P.DiscreteTimeIntegratorVariableTs_InitialCondition;
  }

  AutopilotLaws_DWork.Delay_DSTATE += AutopilotLaws_P.Gain6_Gain * rtb_Mod2_k *
    AutopilotLaws_P.DiscreteTimeIntegratorVariableTs_Gain * AutopilotLaws_U.in.time.dt;
  if (AutopilotLaws_DWork.Delay_DSTATE > AutopilotLaws_P.DiscreteTimeIntegratorVariableTs_UpperLimit) {
    AutopilotLaws_DWork.Delay_DSTATE = AutopilotLaws_P.DiscreteTimeIntegratorVariableTs_UpperLimit;
  } else {
    if (AutopilotLaws_DWork.Delay_DSTATE < AutopilotLaws_P.DiscreteTimeIntegratorVariableTs_LowerLimit) {
      AutopilotLaws_DWork.Delay_DSTATE = AutopilotLaws_P.DiscreteTimeIntegratorVariableTs_LowerLimit;
    }
  }

  AutopilotLaws_storevalue(rtb_Compare, AutopilotLaws_U.in.data.nav_loc_deg, &rtb_Y_p,
    &AutopilotLaws_DWork.sf_storevalue);
  rtb_Mod2 = rt_modd((AutopilotLaws_U.in.data.Psi_magnetic_deg - (rt_modd(rt_modd
    (AutopilotLaws_U.in.data.nav_loc_error_deg + rtb_Y_p, AutopilotLaws_P.Constant3_Value_m0) +
    AutopilotLaws_P.Constant3_Value_m0, AutopilotLaws_P.Constant3_Value_m0) + AutopilotLaws_P.Constant3_Value_eg)) +
                     AutopilotLaws_P.Constant3_Value_eg, AutopilotLaws_P.Constant3_Value_eg);
  rtb_Mod2_f = rt_modd(AutopilotLaws_P.Constant3_Value_eg - rtb_Mod2, AutopilotLaws_P.Constant3_Value_eg);
  if (rtb_Mod2 < rtb_Mod2_f) {
    rtb_Mod2 *= AutopilotLaws_P.Gain1_Gain_ni;
  } else {
    rtb_Mod2 = AutopilotLaws_P.Gain_Gain_k * rtb_Mod2_f;
  }

  rtb_Mod2 = rt_modd((rt_modd(rt_modd(((rtb_Mod2_k * look1_binlxpw(AutopilotLaws_U.in.data.V_gnd_kn,
    AutopilotLaws_P.ScheduledGain_BreakpointsForDimension1_j, AutopilotLaws_P.ScheduledGain_Table_p, 2U) +
    AutopilotLaws_DWork.Delay_DSTATE) + AutopilotLaws_P.Gain1_Gain_f * rtb_Mod2) +
    AutopilotLaws_U.in.data.Psi_magnetic_deg, AutopilotLaws_P.Constant3_Value_c) + AutopilotLaws_P.Constant3_Value_c,
    AutopilotLaws_P.Constant3_Value_c) - (AutopilotLaws_U.in.data.Psi_magnetic_deg + AutopilotLaws_P.Constant3_Value_h))
                     + AutopilotLaws_P.Constant3_Value_h, AutopilotLaws_P.Constant3_Value_h);
  AutopilotLaws_Chart_j(rtb_Mod2, AutopilotLaws_P.Gain_Gain_py * rt_modd(AutopilotLaws_P.Constant3_Value_h - rtb_Mod2,
    AutopilotLaws_P.Constant3_Value_h), AutopilotLaws_P.Constant1_Value_e, &rtb_Mod2_f, &AutopilotLaws_DWork.sf_Chart_o);
  rtb_Mod2 = rt_modd((AutopilotLaws_U.in.input.Psi_c_deg - (AutopilotLaws_U.in.data.Psi_magnetic_deg +
    AutopilotLaws_P.Constant3_Value_d)) + AutopilotLaws_P.Constant3_Value_d, AutopilotLaws_P.Constant3_Value_d);
  rtb_Compare = ((rtb_ManualSwitch == AutopilotLaws_P.CompareToConstant5_const) ==
                 AutopilotLaws_P.CompareToConstant_const_h);
  rtb_Mod2_k = AutopilotLaws_P.Subsystem_Value / AutopilotLaws_U.in.time.dt;
  if (!rtb_Compare) {
    for (i = 0; i < 100; i++) {
      AutopilotLaws_DWork.Delay_DSTATE_l[i] = AutopilotLaws_P.Delay_InitialCondition;
    }
  }

  if (rtb_Mod2_k < 1.0) {
    rtb_Delay_hu = rtb_Compare;
  } else {
    if (rtb_Mod2_k > 100.0) {
      i = 100;
    } else {
      i = static_cast<int32_T>(static_cast<uint32_T>(std::fmod(std::floor(rtb_Mod2_k), 4.294967296E+9)));
    }

    rtb_Delay_hu = AutopilotLaws_DWork.Delay_DSTATE_l[100U - i];
  }

  AutopilotLaws_Chart(rtb_Mod2, AutopilotLaws_P.Gain_Gain_ac * rt_modd(AutopilotLaws_P.Constant3_Value_d - rtb_Mod2,
    AutopilotLaws_P.Constant3_Value_d), rtb_Compare != rtb_Delay_hu, &rtb_Mod2_k, &AutopilotLaws_DWork.sf_Chart);
  rtb_Mod2 = rt_modd((AutopilotLaws_U.in.input.Psi_c_deg - (AutopilotLaws_U.in.data.Psi_magnetic_track_deg +
    AutopilotLaws_P.Constant3_Value_n)) + AutopilotLaws_P.Constant3_Value_n, AutopilotLaws_P.Constant3_Value_n);
  rtb_Delay_hu = ((rtb_ManualSwitch == AutopilotLaws_P.CompareToConstant4_const) ==
                  AutopilotLaws_P.CompareToConstant_const_e);
  rtb_Y_p = AutopilotLaws_P.Subsystem_Value_n / AutopilotLaws_U.in.time.dt;
  if (!rtb_Delay_hu) {
    for (i = 0; i < 100; i++) {
      AutopilotLaws_DWork.Delay_DSTATE_h5[i] = AutopilotLaws_P.Delay_InitialCondition_b;
    }
  }

  if (rtb_Y_p < 1.0) {
    rtb_Delay_n = rtb_Delay_hu;
  } else {
    if (rtb_Y_p > 100.0) {
      i = 100;
    } else {
      i = static_cast<int32_T>(static_cast<uint32_T>(std::fmod(std::floor(rtb_Y_p), 4.294967296E+9)));
    }

    rtb_Delay_n = AutopilotLaws_DWork.Delay_DSTATE_h5[100U - i];
  }

  AutopilotLaws_Chart(rtb_Mod2, AutopilotLaws_P.Gain_Gain_e * rt_modd(AutopilotLaws_P.Constant3_Value_n - rtb_Mod2,
    AutopilotLaws_P.Constant3_Value_n), rtb_Delay_hu != rtb_Delay_n, &rtb_Y_p, &AutopilotLaws_DWork.sf_Chart_b);
  rtb_Mod2 = AutopilotLaws_P.DiscreteDerivativeVariableTs_Gain * AutopilotLaws_U.in.data.nav_loc_error_deg;
  AutopilotLaws_LagFilter(AutopilotLaws_U.in.data.nav_loc_error_deg + AutopilotLaws_P.Gain3_Gain_i * ((rtb_Mod2 -
    AutopilotLaws_DWork.Delay_DSTATE_i) / AutopilotLaws_U.in.time.dt), AutopilotLaws_P.LagFilter_C1,
    AutopilotLaws_U.in.time.dt, &rtb_Y_m, &AutopilotLaws_DWork.sf_LagFilter);
  switch (static_cast<int32_T>(rtb_ManualSwitch)) {
   case 0:
    rtb_Mod2_k = rtb_GainTheta1;
    break;

   case 1:
    rtb_Mod2_k *= look1_binlxpw(AutopilotLaws_U.in.data.V_tas_kn,
      AutopilotLaws_P.ScheduledGain_BreakpointsForDimension1_a, AutopilotLaws_P.ScheduledGain_Table_i, 5U);
    break;

   case 2:
    rtb_Mod2_k = rtb_Y_p * look1_binlxpw(AutopilotLaws_U.in.data.V_tas_kn,
      AutopilotLaws_P.ScheduledGain_BreakpointsForDimension1_d, AutopilotLaws_P.ScheduledGain_Table_h, 5U);
    break;

   case 3:
    rtb_Gain_ny = AutopilotLaws_P.Gain_Gain_n * AutopilotLaws_U.in.data.flight_guidance_xtk_nmi;
    if (rtb_Gain_ny > AutopilotLaws_P.Saturation_UpperSat) {
      rtb_Gain_ny = AutopilotLaws_P.Saturation_UpperSat;
    } else {
      if (rtb_Gain_ny < AutopilotLaws_P.Saturation_LowerSat) {
        rtb_Gain_ny = AutopilotLaws_P.Saturation_LowerSat;
      }
    }

    rtb_Mod2_k = (AutopilotLaws_P.Gain2_Gain * AutopilotLaws_U.in.data.flight_guidance_tae_deg + rtb_Gain_ny) *
      AutopilotLaws_P.Gain1_Gain_n * look1_binlxpw(AutopilotLaws_U.in.data.V_tas_kn,
      AutopilotLaws_P.ScheduledGain2_BreakpointsForDimension1_k, AutopilotLaws_P.ScheduledGain2_Table_g, 5U) +
      AutopilotLaws_U.in.data.flight_guidance_phi_deg;
    break;

   case 4:
    rtb_Mod2_k = rtb_Saturation1;
    break;

   case 5:
    rtb_Mod2_k = rtb_Y_m * look1_binlxpw(AutopilotLaws_U.in.data.H_radio_ft,
      AutopilotLaws_P.ScheduledGain_BreakpointsForDimension1_e, AutopilotLaws_P.ScheduledGain_Table_pf, 4U) *
      look1_binlxpw(AutopilotLaws_U.in.data.V_tas_kn, AutopilotLaws_P.ScheduledGain2_BreakpointsForDimension1_j,
                    AutopilotLaws_P.ScheduledGain2_Table_h, 5U);
    break;

   default:
    rtb_Mod2_k = AutopilotLaws_P.Constant3_Value;
    break;
  }

  rtb_Y_p = look1_binlxpw(AutopilotLaws_U.in.data.V_tas_kn, AutopilotLaws_P.ROLLLIM1_bp01Data,
    AutopilotLaws_P.ROLLLIM1_tableData, 4U);
  if (rtb_Mod2_k > rtb_Y_p) {
    rtb_Mod2_k = rtb_Y_p;
  } else {
    rtb_Y_p *= AutopilotLaws_P.Gain1_Gain_l;
    if (rtb_Mod2_k < rtb_Y_p) {
      rtb_Mod2_k = rtb_Y_p;
    }
  }

  if ((AutopilotLaws_U.in.input.enabled_AP1 == 0.0) && (AutopilotLaws_U.in.input.enabled_AP2 == 0.0)) {
    AutopilotLaws_DWork.icLoad = 1U;
  }

  if (AutopilotLaws_DWork.icLoad != 0) {
    AutopilotLaws_DWork.Delay_DSTATE_h = rtb_GainTheta1;
  }

  rtb_Gain_ny = rtb_Mod2_k - AutopilotLaws_DWork.Delay_DSTATE_h;
  rtb_Vz = AutopilotLaws_P.Constant2_Value_h * AutopilotLaws_U.in.time.dt;
  if (rtb_Gain_ny < rtb_Vz) {
    rtb_Vz = rtb_Gain_ny;
  }

  rtb_Y_p = AutopilotLaws_P.Gain1_Gain_k * AutopilotLaws_P.Constant2_Value_h * AutopilotLaws_U.in.time.dt;
  if (rtb_Vz > rtb_Y_p) {
    rtb_Y_p = rtb_Vz;
  }

  AutopilotLaws_DWork.Delay_DSTATE_h += rtb_Y_p;
  AutopilotLaws_LagFilter(AutopilotLaws_DWork.Delay_DSTATE_h, AutopilotLaws_P.LagFilter_C1_l, AutopilotLaws_U.in.time.dt,
    &rtb_Y_m, &AutopilotLaws_DWork.sf_LagFilter_d);
  AutopilotLaws_RateLimiter(static_cast<real_T>((AutopilotLaws_U.in.input.enabled_AP1 != 0.0) ||
    (AutopilotLaws_U.in.input.enabled_AP2 != 0.0)), AutopilotLaws_P.RateLimiterVariableTs_up,
    AutopilotLaws_P.RateLimiterVariableTs_lo, AutopilotLaws_U.in.time.dt,
    AutopilotLaws_P.RateLimiterVariableTs_InitialCondition, &rtb_Y_p, &AutopilotLaws_DWork.sf_RateLimiter);
  if (rtb_Y_p > AutopilotLaws_P.Saturation_UpperSat_j) {
    rtb_Vz = AutopilotLaws_P.Saturation_UpperSat_j;
  } else if (rtb_Y_p < AutopilotLaws_P.Saturation_LowerSat_p) {
    rtb_Vz = AutopilotLaws_P.Saturation_LowerSat_p;
  } else {
    rtb_Vz = rtb_Y_p;
  }

  rtb_Y_p = rtb_Y_m * rtb_Vz;
  rtb_Vz = AutopilotLaws_P.Constant_Value_n - rtb_Vz;
  rtb_Vz *= rtb_GainTheta1;
  AutopilotLaws_Y.out.output.autopilot.Phi_c_deg = rtb_Y_p + rtb_Vz;
  if (AutopilotLaws_U.in.data.H_radio_ft <= AutopilotLaws_P.CompareToConstant_const_d) {
    rtb_Gain_mc = AutopilotLaws_P.Gain_Gain_a * rtb_out_c;
  } else {
    rtb_Gain_mc = AutopilotLaws_P.Constant1_Value;
  }

  AutopilotLaws_LagFilter(rtb_Gain_mc, AutopilotLaws_P.LagFilter1_C1, AutopilotLaws_U.in.time.dt, &rtb_Y_p,
    &AutopilotLaws_DWork.sf_LagFilter_j);
  switch (static_cast<int32_T>(rtb_ManualSwitch)) {
   case 0:
    rtb_Y_p = AutopilotLaws_P.beta_Value;
    break;

   case 1:
    rtb_Y_p = AutopilotLaws_P.beta_Value_e;
    break;

   case 2:
    rtb_Y_p = AutopilotLaws_P.beta_Value_b;
    break;

   case 3:
    rtb_Y_p = AutopilotLaws_P.beta_Value_m;
    break;

   case 4:
    rtb_Y_p = AutopilotLaws_P.beta_Value_d;
    break;

   case 5:
    break;

   default:
    rtb_Y_p = AutopilotLaws_P.Gain5_Gain * rtb_Mod2_f + AutopilotLaws_P.Gain_Gain_b * result[2];
    break;
  }

  AutopilotLaws_Y.out.output.flight_director.Beta_c_deg = rtb_Y_p;
  AutopilotLaws_Y.out.output.autopilot.Beta_c_deg = rtb_Y_p;
  AutopilotLaws_Y.out.output.flight_director.Phi_c_deg = rtb_Mod2_k;
  if (AutopilotLaws_U.in.input.ALT_soft_mode_active) {
    rtb_Mod2_k = (AutopilotLaws_U.in.input.V_c_kn - AutopilotLaws_U.in.data.V_ias_kn) * AutopilotLaws_P.Gain1_Gain_b;
    if (rtb_Mod2_k > AutopilotLaws_P.Saturation1_UpperSat) {
      rtb_Mod2_k = AutopilotLaws_P.Saturation1_UpperSat;
    } else {
      if (rtb_Mod2_k < AutopilotLaws_P.Saturation1_LowerSat) {
        rtb_Mod2_k = AutopilotLaws_P.Saturation1_LowerSat;
      }
    }
  } else {
    rtb_Mod2_k = AutopilotLaws_P.Constant1_Value_h;
  }

  if (AutopilotLaws_P.ManualSwitch_CurrentSetting_b == 1) {
    rtb_out_c = AutopilotLaws_P.Constant_Value_m;
  } else {
    rtb_out_c = AutopilotLaws_U.in.input.vertical_law;
  }

  if (rtb_out_c != AutopilotLaws_P.CompareToConstant5_const_e) {
    AutopilotLaws_B.u = (AutopilotLaws_U.in.input.H_c_ft + AutopilotLaws_U.in.data.H_ft) -
      AutopilotLaws_U.in.data.H_ind_ft;
  }

  AutopilotLaws_LagFilter(AutopilotLaws_B.u - AutopilotLaws_U.in.data.H_ft, AutopilotLaws_P.LagFilter_C1_a,
    AutopilotLaws_U.in.time.dt, &rtb_ManualSwitch, &AutopilotLaws_DWork.sf_LagFilter_k);
  rtb_Mod2_k += AutopilotLaws_P.Gain_Gain_f * rtb_ManualSwitch;
  if (rtb_Mod2_k > AutopilotLaws_P.Saturation_UpperSat_n) {
    rtb_Mod2_k = AutopilotLaws_P.Saturation_UpperSat_n;
  } else {
    if (rtb_Mod2_k < AutopilotLaws_P.Saturation_LowerSat_d4) {
      rtb_Mod2_k = AutopilotLaws_P.Saturation_LowerSat_d4;
    }
  }

  rtb_Mod2_k -= AutopilotLaws_U.in.data.H_dot_ft_min;
  rtb_Gain_ny = AutopilotLaws_P.kntoms_Gain * AutopilotLaws_U.in.data.V_tas_kn;
  if (rtb_Gain_ny > AutopilotLaws_P.Saturation_UpperSat_n3) {
    rtb_Gain_ny = AutopilotLaws_P.Saturation_UpperSat_n3;
  } else {
    if (rtb_Gain_ny < AutopilotLaws_P.Saturation_LowerSat_m) {
      rtb_Gain_ny = AutopilotLaws_P.Saturation_LowerSat_m;
    }
  }

  rtb_Gain_ny = AutopilotLaws_P.ftmintoms_Gain * rtb_Mod2_k / rtb_Gain_ny;
  if (rtb_Gain_ny > 1.0) {
    rtb_Gain_ny = 1.0;
  } else {
    if (rtb_Gain_ny < -1.0) {
      rtb_Gain_ny = -1.0;
    }
  }

  rtb_Mod2_f = AutopilotLaws_P.Gain_Gain_kr * std::asin(rtb_Gain_ny);
  AutopilotLaws_WashoutFilter(result_0[2], AutopilotLaws_P.WashoutFilter_C1, AutopilotLaws_U.in.time.dt, &rtb_Mod2_k,
    &AutopilotLaws_DWork.sf_WashoutFilter_c);
  AutopilotLaws_LagFilter(AutopilotLaws_U.in.data.nav_gs_error_deg, AutopilotLaws_P.LagFilter1_C1_a,
    AutopilotLaws_U.in.time.dt, &rtb_Y_p, &AutopilotLaws_DWork.sf_LagFilter_h);
  rtb_ManualSwitch = AutopilotLaws_P.DiscreteDerivativeVariableTs_Gain_l * rtb_Y_p;
  AutopilotLaws_LagFilter(rtb_Y_p + AutopilotLaws_P.Gain3_Gain_o * ((rtb_ManualSwitch -
    AutopilotLaws_DWork.Delay_DSTATE_g) / AutopilotLaws_U.in.time.dt), AutopilotLaws_P.LagFilter_C1_n,
    AutopilotLaws_U.in.time.dt, &rtb_Y_m, &AutopilotLaws_DWork.sf_LagFilter_d2);
  AutopilotLaws_storevalue(rtb_out_c == AutopilotLaws_P.CompareToConstant6_const, rtb_Saturation, &rtb_Y_p,
    &AutopilotLaws_DWork.sf_storevalue_m);
  if (rtb_Y_p > AutopilotLaws_P.Saturation_UpperSat_f) {
    rtb_Y_p = AutopilotLaws_P.Saturation_UpperSat_f;
  } else {
    if (rtb_Y_p < AutopilotLaws_P.Saturation_LowerSat_om) {
      rtb_Y_p = AutopilotLaws_P.Saturation_LowerSat_om;
    }
  }

  rtb_Gain_ny = AutopilotLaws_P.kntoms_Gain_i * AutopilotLaws_U.in.data.V_gnd_kn;
  if (rtb_Gain_ny > AutopilotLaws_P.Saturation_UpperSat_g) {
    rtb_Gain_ny = AutopilotLaws_P.Saturation_UpperSat_g;
  } else {
    if (rtb_Gain_ny < AutopilotLaws_P.Saturation_LowerSat_c) {
      rtb_Gain_ny = AutopilotLaws_P.Saturation_LowerSat_c;
    }
  }

  rtb_Gain_ny = std::atan(AutopilotLaws_P.fpmtoms_Gain * AutopilotLaws_U.in.data.H_dot_ft_min / rtb_Gain_ny) *
    AutopilotLaws_P.Gain_Gain_nu;
  if ((AutopilotLaws_U.in.data.H_radio_ft > AutopilotLaws_P.CompareToConstant_const_n) &&
      AutopilotLaws_U.in.data.nav_gs_valid) {
    rtb_Gain_mc = AutopilotLaws_P.Gain_Gain_h * rtb_Mod2_k + rtb_Y_m * look1_binlxpw(AutopilotLaws_U.in.data.H_radio_ft,
      AutopilotLaws_P.ScheduledGain_BreakpointsForDimension1_h, AutopilotLaws_P.ScheduledGain_Table_ir, 5U);
  } else {
    rtb_Gain_mc = (rtb_Y_p - rtb_Gain_ny) * AutopilotLaws_P.Gain2_Gain_j;
  }

  AutopilotLaws_Voter1(rtb_Gain_mc, AutopilotLaws_P.Gain1_Gain_nq * ((rtb_Y_p + AutopilotLaws_P.Bias_Bias) - rtb_Gain_ny),
                       AutopilotLaws_P.Gain_Gain_p2 * ((rtb_Y_p + AutopilotLaws_P.Bias1_Bias) - rtb_Gain_ny), &rtb_Y_m);
  rtb_Sum_ib_tmp = AutopilotLaws_U.in.input.H_c_ft - AutopilotLaws_U.in.data.H_ind_ft;
  rtb_Gain_ny = AutopilotLaws_P.kntoms_Gain_e * AutopilotLaws_U.in.data.V_tas_kn;
  if (rtb_Sum_ib_tmp < 0.0) {
    rtb_Mod2_k = -1.0;
  } else if (rtb_Sum_ib_tmp > 0.0) {
    rtb_Mod2_k = 1.0;
  } else {
    rtb_Mod2_k = rtb_Sum_ib_tmp;
  }

  if (rtb_Gain_ny > AutopilotLaws_P.Saturation_UpperSat_d) {
    rtb_Gain_ny = AutopilotLaws_P.Saturation_UpperSat_d;
  } else {
    if (rtb_Gain_ny < AutopilotLaws_P.Saturation_LowerSat_b) {
      rtb_Gain_ny = AutopilotLaws_P.Saturation_LowerSat_b;
    }
  }

  rtb_Gain_ny = ((AutopilotLaws_P.Constant_Value_b * rtb_Mod2_k + rtb_Sum_ib_tmp) * AutopilotLaws_P.Gain_Gain_el -
                 AutopilotLaws_U.in.data.H_dot_ft_min) * AutopilotLaws_P.ftmintoms_Gain_g / rtb_Gain_ny;
  if (rtb_Gain_ny > 1.0) {
    rtb_Gain_ny = 1.0;
  } else {
    if (rtb_Gain_ny < -1.0) {
      rtb_Gain_ny = -1.0;
    }
  }

  rtb_Gain_p = AutopilotLaws_P.Gain_Gain_da * std::asin(rtb_Gain_ny);
  rtb_Mod2_k = AutopilotLaws_P.Gain1_Gain_kw * AutopilotLaws_U.in.data.alpha_deg;
  rtb_Vz = result_0[2] * std::sin(rtb_Mod2_k);
  rtb_Mod2_k = std::cos(rtb_Mod2_k);
  rtb_Mod2_k *= result_0[0];
  rtb_Sum2_j = AutopilotLaws_U.in.data.V_ias_kn - AutopilotLaws_U.in.input.V_c_kn;
  rtb_Gain_ny = rtb_Sum2_j * AutopilotLaws_P.Gain1_Gain_hn;
  if (rtb_Gain_ny > AutopilotLaws_P.Saturation_UpperSat_j4) {
    rtb_Gain_ny = AutopilotLaws_P.Saturation_UpperSat_j4;
  } else {
    if (rtb_Gain_ny < AutopilotLaws_P.Saturation_LowerSat_bb) {
      rtb_Gain_ny = AutopilotLaws_P.Saturation_LowerSat_bb;
    }
  }

  rtb_Sum2_d = (rtb_Vz + rtb_Mod2_k) * AutopilotLaws_P.Gain_Gain_bi * AutopilotLaws_P.Gain_Gain_ei + rtb_Gain_ny;
  rtb_Gain_ny = AutopilotLaws_P.kntoms_Gain_iw * AutopilotLaws_U.in.data.V_tas_kn;
  if (rtb_Gain_ny > AutopilotLaws_P.Saturation_UpperSat_k) {
    rtb_Gain_ny = AutopilotLaws_P.Saturation_UpperSat_k;
  } else {
    if (rtb_Gain_ny < AutopilotLaws_P.Saturation_LowerSat_ce) {
      rtb_Gain_ny = AutopilotLaws_P.Saturation_LowerSat_ce;
    }
  }

  rtb_Gain_ny = (AutopilotLaws_P.Constant_Value_k - AutopilotLaws_U.in.data.H_dot_ft_min) *
    AutopilotLaws_P.ftmintoms_Gain_p / rtb_Gain_ny;
  if (rtb_Gain_ny > 1.0) {
    rtb_Gain_ny = 1.0;
  } else {
    if (rtb_Gain_ny < -1.0) {
      rtb_Gain_ny = -1.0;
    }
  }

  rtb_Gain_hf = AutopilotLaws_P.Gain_Gain_md * std::asin(rtb_Gain_ny);
  rtb_Gain_ny = AutopilotLaws_P.kntoms_Gain_a * AutopilotLaws_U.in.data.V_tas_kn;
  if (rtb_Gain_ny > AutopilotLaws_P.Saturation_UpperSat_db) {
    rtb_Gain_ny = AutopilotLaws_P.Saturation_UpperSat_db;
  } else {
    if (rtb_Gain_ny < AutopilotLaws_P.Saturation_LowerSat_bt) {
      rtb_Gain_ny = AutopilotLaws_P.Saturation_LowerSat_bt;
    }
  }

  rtb_Gain_ny = (AutopilotLaws_U.in.input.H_dot_c_fpm - AutopilotLaws_U.in.data.H_dot_ft_min) *
    AutopilotLaws_P.ftmintoms_Gain_h / rtb_Gain_ny;
  if (rtb_Gain_ny > 1.0) {
    rtb_Gain_ny = 1.0;
  } else {
    if (rtb_Gain_ny < -1.0) {
      rtb_Gain_ny = -1.0;
    }
  }

  rtb_Gain_a4z = AutopilotLaws_P.Gain_Gain_df * std::asin(rtb_Gain_ny);
  rtb_Gain_ny = AutopilotLaws_P.kntoms_Gain_p * AutopilotLaws_U.in.data.V_gnd_kn;
  if (rtb_Gain_ny > AutopilotLaws_P.Saturation_UpperSat_kp) {
    rtb_Gain_ny = AutopilotLaws_P.Saturation_UpperSat_kp;
  } else {
    if (rtb_Gain_ny < AutopilotLaws_P.Saturation_LowerSat_l) {
      rtb_Gain_ny = AutopilotLaws_P.Saturation_LowerSat_l;
    }
  }

  rtb_Sum_k = AutopilotLaws_U.in.input.FPA_c_deg - std::atan(AutopilotLaws_P.fpmtoms_Gain_d *
    AutopilotLaws_U.in.data.H_dot_ft_min / rtb_Gain_ny) * AutopilotLaws_P.Gain_Gain_l;
  rtb_Mod2_k = rtb_GainTheta - AutopilotLaws_P.Constant2_Value_f;
  rtb_Gain4 = AutopilotLaws_P.Gain4_Gain * rtb_Mod2_k;
  rtb_Gain5 = AutopilotLaws_P.Gain5_Gain_c * AutopilotLaws_U.in.data.bz_m_s2;
  AutopilotLaws_WashoutFilter(AutopilotLaws_U.in.data.bx_m_s2, AutopilotLaws_P.WashoutFilter_C1_m,
    AutopilotLaws_U.in.time.dt, &rtb_Y_p, &AutopilotLaws_DWork.sf_WashoutFilter_l);
  AutopilotLaws_WashoutFilter(AutopilotLaws_U.in.data.H_ind_ft, AutopilotLaws_P.WashoutFilter_C1_h,
    AutopilotLaws_U.in.time.dt, &rtb_Mod2_k, &AutopilotLaws_DWork.sf_WashoutFilter);
  if (AutopilotLaws_U.in.data.H_radio_ft > AutopilotLaws_P.Saturation_UpperSat_e) {
    rtb_Gain_mc = AutopilotLaws_P.Saturation_UpperSat_e;
  } else if (AutopilotLaws_U.in.data.H_radio_ft < AutopilotLaws_P.Saturation_LowerSat_mg) {
    rtb_Gain_mc = AutopilotLaws_P.Saturation_LowerSat_mg;
  } else {
    rtb_Gain_mc = AutopilotLaws_U.in.data.H_radio_ft;
  }

  AutopilotLaws_LagFilter(rtb_Gain_mc, AutopilotLaws_P.LagFilter_C1_h, AutopilotLaws_U.in.time.dt, &rtb_Gain_ny,
    &AutopilotLaws_DWork.sf_LagFilter_g);
  rtb_Gain_mc = (rtb_Mod2_k + rtb_Gain_ny) * AutopilotLaws_P.DiscreteDerivativeVariableTs2_Gain;
  rtb_Mod2_k = (rtb_Gain_mc - AutopilotLaws_DWork.Delay_DSTATE_k) / AutopilotLaws_U.in.time.dt;
  AutopilotLaws_LagFilter(AutopilotLaws_P.Gain2_Gain_c * rtb_Mod2_k, AutopilotLaws_P.LagFilter3_C1,
    AutopilotLaws_U.in.time.dt, &rtb_Gain_ny, &AutopilotLaws_DWork.sf_LagFilter_e);
  AutopilotLaws_WashoutFilter(AutopilotLaws_U.in.data.H_dot_ft_min, AutopilotLaws_P.WashoutFilter1_C1,
    AutopilotLaws_U.in.time.dt, &rtb_Mod2_k, &AutopilotLaws_DWork.sf_WashoutFilter_h);
  rtb_Mod2_k += rtb_Gain_ny;
  rtb_Delay_n = (rtb_out_c == AutopilotLaws_P.CompareToConstant7_const);
  if (!AutopilotLaws_DWork.wasActive_not_empty) {
    AutopilotLaws_DWork.wasActive = rtb_Delay_n;
    AutopilotLaws_DWork.wasActive_not_empty = true;
  }

  if ((!AutopilotLaws_DWork.wasActive) && rtb_Delay_n) {
    rtb_Gain_ny = std::abs(rtb_Mod2_k) / 60.0;
    AutopilotLaws_DWork.Tau = AutopilotLaws_U.in.data.H_radio_ft / (rtb_Gain_ny - 1.6666666666666667);
    AutopilotLaws_DWork.H_bias = AutopilotLaws_DWork.Tau * rtb_Gain_ny - AutopilotLaws_U.in.data.H_radio_ft;
  }

  if (rtb_Delay_n) {
    rtb_Vz = -1.0 / AutopilotLaws_DWork.Tau * (AutopilotLaws_U.in.data.H_radio_ft + AutopilotLaws_DWork.H_bias) * 60.0;
  } else {
    rtb_Vz = rtb_Mod2_k;
  }

  AutopilotLaws_DWork.wasActive = rtb_Delay_n;
  rtb_Gain_ny = AutopilotLaws_P.kntoms_Gain_av * AutopilotLaws_U.in.data.V_gnd_kn;
  if (rtb_Gain_ny > AutopilotLaws_P.Saturation_UpperSat_m) {
    rtb_Gain_ny = AutopilotLaws_P.Saturation_UpperSat_m;
  } else {
    if (rtb_Gain_ny < AutopilotLaws_P.Saturation_LowerSat_d1) {
      rtb_Gain_ny = AutopilotLaws_P.Saturation_LowerSat_d1;
    }
  }

  rtb_Gain_ny = (rtb_Vz - rtb_Mod2_k) * AutopilotLaws_P.ftmintoms_Gain_i / rtb_Gain_ny;
  if (rtb_Gain_ny > 1.0) {
    rtb_Gain_ny = 1.0;
  } else {
    if (rtb_Gain_ny < -1.0) {
      rtb_Gain_ny = -1.0;
    }
  }

  rtb_Gain_jf = AutopilotLaws_P.Gain_Gain_fz * std::asin(rtb_Gain_ny);
  rtb_Sum_am = AutopilotLaws_P.Constant1_Value_d - rtb_GainTheta;
  rtb_Mod2_k = AutopilotLaws_P.Gain1_Gain_fy * AutopilotLaws_U.in.data.alpha_deg;
  rtb_Vz = result_0[2] * std::sin(rtb_Mod2_k);
  rtb_Mod2_k = std::cos(rtb_Mod2_k);
  rtb_Mod2_k *= result_0[0];
  rtb_Gain_ny = rtb_Sum2_j * AutopilotLaws_P.Gain1_Gain_fr;
  if (rtb_Gain_ny > AutopilotLaws_P.Saturation_UpperSat_e3) {
    rtb_Gain_ny = AutopilotLaws_P.Saturation_UpperSat_e3;
  } else {
    if (rtb_Gain_ny < AutopilotLaws_P.Saturation_LowerSat_py) {
      rtb_Gain_ny = AutopilotLaws_P.Saturation_LowerSat_py;
    }
  }

  rtb_Sum2_j = (rtb_Vz + rtb_Mod2_k) * AutopilotLaws_P.Gain_Gain_nub * AutopilotLaws_P.Gain_Gain_ao + rtb_Gain_ny;
  rtb_Gain_ny = AutopilotLaws_P.kntoms_Gain_f * AutopilotLaws_U.in.data.V_tas_kn;
  if (rtb_Gain_ny > AutopilotLaws_P.Saturation_UpperSat_b) {
    rtb_Gain_ny = AutopilotLaws_P.Saturation_UpperSat_b;
  } else {
    if (rtb_Gain_ny < AutopilotLaws_P.Saturation_LowerSat_ow) {
      rtb_Gain_ny = AutopilotLaws_P.Saturation_LowerSat_ow;
    }
  }

  rtb_Gain_ny = (AutopilotLaws_P.Constant_Value_i - AutopilotLaws_U.in.data.H_dot_ft_min) *
    AutopilotLaws_P.ftmintoms_Gain_j / rtb_Gain_ny;
  if (rtb_Gain_ny > 1.0) {
    rtb_Gain_ny = 1.0;
  } else {
    if (rtb_Gain_ny < -1.0) {
      rtb_Gain_ny = -1.0;
    }
  }

  rtb_Gain_m = AutopilotLaws_P.Gain_Gain_bd * std::asin(rtb_Gain_ny);
  AutopilotLaws_Voter1(rtb_Sum_am, AutopilotLaws_P.Gain_Gain_b2 * rtb_Sum2_j, AutopilotLaws_P.VS_Gain_c * rtb_Gain_m,
                       &rtb_Mod2_k);
  switch (static_cast<int32_T>(rtb_out_c)) {
   case 0:
    rtb_Mod2_k = rtb_GainTheta;
    break;

   case 1:
    rtb_Mod2_k = AutopilotLaws_P.VS_Gain * rtb_Mod2_f;
    break;

   case 2:
    rtb_Mod2_k = AutopilotLaws_P.VS_Gain_a * rtb_Gain_p;
    break;

   case 3:
    if (rtb_Sum_ib_tmp > AutopilotLaws_P.Switch_Threshold_n) {
      rtb_Gain_ny = AutopilotLaws_P.Gain_Gain_kg * rtb_Sum2_d;
      rtb_Mod2_k = AutopilotLaws_P.VS_Gain_j * rtb_Gain_hf;
      if (rtb_Gain_ny > rtb_Mod2_k) {
        rtb_Mod2_k = rtb_Gain_ny;
      }
    } else {
      rtb_Gain_ny = AutopilotLaws_P.Gain_Gain_kg * rtb_Sum2_d;
      rtb_Mod2_k = AutopilotLaws_P.VS_Gain_j * rtb_Gain_hf;
      if (rtb_Gain_ny < rtb_Mod2_k) {
        rtb_Mod2_k = rtb_Gain_ny;
      }
    }
    break;

   case 4:
    rtb_Mod2_k = AutopilotLaws_P.VS_Gain_h * rtb_Gain_a4z;
    break;

   case 5:
    rtb_Mod2_k = AutopilotLaws_P.Gain_Gain_c * rtb_Sum_k;
    break;

   case 6:
    rtb_Mod2_k = rtb_Y_m;
    break;

   case 7:
    if (rtb_on_ground > AutopilotLaws_P.Switch_Threshold_c) {
      rtb_Mod2_k = rtb_Gain4;
    } else {
      rtb_Mod2_k = (AutopilotLaws_P.Gain3_Gain * rtb_Y_p + rtb_Gain5) + AutopilotLaws_P.VS_Gain_e * rtb_Gain_jf;
    }
    break;
  }

  rtb_Mod2_k += rtb_GainTheta;
  if (rtb_Mod2_k > AutopilotLaws_P.Constant1_Value_i) {
    rtb_Mod2_k = AutopilotLaws_P.Constant1_Value_i;
  } else {
    rtb_Gain_ny = AutopilotLaws_P.Gain1_Gain_m * AutopilotLaws_P.Constant1_Value_i;
    if (rtb_Mod2_k < rtb_Gain_ny) {
      rtb_Mod2_k = rtb_Gain_ny;
    }
  }

  if (rtb_BusAssignment_output_ap_on == 0) {
    AutopilotLaws_DWork.icLoad_f = 1U;
  }

  if (AutopilotLaws_DWork.icLoad_f != 0) {
    AutopilotLaws_DWork.Delay_DSTATE_h2 = rtb_GainTheta;
  }

  rtb_Mod2_k -= AutopilotLaws_DWork.Delay_DSTATE_h2;
  rtb_Vz = AutopilotLaws_P.Constant2_Value_h1 * AutopilotLaws_U.in.time.dt;
  if (rtb_Mod2_k >= rtb_Vz) {
    rtb_Mod2_k = rtb_Vz;
  }

  rtb_Vz = AutopilotLaws_P.Gain1_Gain_i0 * AutopilotLaws_P.Constant2_Value_h1 * AutopilotLaws_U.in.time.dt;
  if (rtb_Mod2_k > rtb_Vz) {
    rtb_Vz = rtb_Mod2_k;
  }

  AutopilotLaws_DWork.Delay_DSTATE_h2 += rtb_Vz;
  AutopilotLaws_LagFilter(AutopilotLaws_DWork.Delay_DSTATE_h2, AutopilotLaws_P.LagFilter_C1_i,
    AutopilotLaws_U.in.time.dt, &rtb_Gain_ny, &AutopilotLaws_DWork.sf_LagFilter_n);
  AutopilotLaws_RateLimiter(static_cast<real_T>(rtb_BusAssignment_output_ap_on),
    AutopilotLaws_P.RateLimiterVariableTs_up_i, AutopilotLaws_P.RateLimiterVariableTs_lo_o, AutopilotLaws_U.in.time.dt,
    AutopilotLaws_P.RateLimiterVariableTs_InitialCondition_p, &rtb_Mod2_k, &AutopilotLaws_DWork.sf_RateLimiter_g);
  if (rtb_Mod2_k > AutopilotLaws_P.Saturation_UpperSat_ju) {
    rtb_Mod2_k = AutopilotLaws_P.Saturation_UpperSat_ju;
  } else {
    if (rtb_Mod2_k < AutopilotLaws_P.Saturation_LowerSat_n) {
      rtb_Mod2_k = AutopilotLaws_P.Saturation_LowerSat_n;
    }
  }

  rtb_Gain_ny *= rtb_Mod2_k;
  rtb_Mod2_k = AutopilotLaws_P.Constant_Value_f - rtb_Mod2_k;
  rtb_Mod2_k *= rtb_GainTheta;
  AutopilotLaws_Y.out.output.autopilot.Theta_c_deg = rtb_Gain_ny + rtb_Mod2_k;
  AutopilotLaws_Voter1(rtb_Sum_am, rtb_Sum2_j, rtb_Gain_m, &rtb_Vz);
  switch (static_cast<int32_T>(rtb_out_c)) {
   case 0:
    rtb_Vz = rtb_GainTheta;
    break;

   case 1:
    rtb_Vz = rtb_Mod2_f;
    break;

   case 2:
    rtb_Vz = rtb_Gain_p;
    break;

   case 3:
    if (rtb_Sum_ib_tmp > AutopilotLaws_P.Switch_Threshold) {
      if (rtb_Sum2_d > rtb_Gain_hf) {
        rtb_Vz = rtb_Sum2_d;
      } else {
        rtb_Vz = rtb_Gain_hf;
      }
    } else if (rtb_Sum2_d < rtb_Gain_hf) {
      rtb_Vz = rtb_Sum2_d;
    } else {
      rtb_Vz = rtb_Gain_hf;
    }
    break;

   case 4:
    rtb_Vz = rtb_Gain_a4z;
    break;

   case 5:
    rtb_Vz = rtb_Sum_k;
    break;

   case 6:
    rtb_Vz = AutopilotLaws_P.Gain1_Gain_h * rtb_Y_m;
    break;

   case 7:
    if (rtb_on_ground > AutopilotLaws_P.Switch1_Threshold) {
      rtb_Vz = AutopilotLaws_P.Gain2_Gain_h * rtb_Gain4;
    } else {
      rtb_Vz = (AutopilotLaws_P.Gain1_Gain_i * rtb_Y_p + rtb_Gain5) + rtb_Gain_jf;
    }
    break;
  }

  rtb_Mod2_k = rtb_Vz + rtb_GainTheta;
  if (rtb_Mod2_k > AutopilotLaws_P.Constant1_Value_i) {
    AutopilotLaws_Y.out.output.flight_director.Theta_c_deg = AutopilotLaws_P.Constant1_Value_i;
  } else {
    rtb_out_c = AutopilotLaws_P.Gain1_Gain_nu * AutopilotLaws_P.Constant1_Value_i;
    if (rtb_Mod2_k < rtb_out_c) {
      AutopilotLaws_Y.out.output.flight_director.Theta_c_deg = rtb_out_c;
    } else {
      AutopilotLaws_Y.out.output.flight_director.Theta_c_deg = rtb_Mod2_k;
    }
  }

  AutopilotLaws_Y.out.time = AutopilotLaws_U.in.time;
  AutopilotLaws_Y.out.data.Theta_deg = rtb_GainTheta;
  AutopilotLaws_Y.out.data.Phi_deg = rtb_GainTheta1;
  AutopilotLaws_Y.out.data.qk_deg_s = result[1];
  AutopilotLaws_Y.out.data.rk_deg_s = result[2];
  AutopilotLaws_Y.out.data.pk_deg_s = result[0];
  AutopilotLaws_Y.out.data.V_ias_kn = AutopilotLaws_U.in.data.V_ias_kn;
  AutopilotLaws_Y.out.data.V_tas_kn = AutopilotLaws_U.in.data.V_tas_kn;
  AutopilotLaws_Y.out.data.V_mach = AutopilotLaws_U.in.data.V_mach;
  AutopilotLaws_Y.out.data.V_gnd_kn = AutopilotLaws_U.in.data.V_gnd_kn;
  AutopilotLaws_Y.out.data.alpha_deg = AutopilotLaws_U.in.data.alpha_deg;
  AutopilotLaws_Y.out.data.H_ft = AutopilotLaws_U.in.data.H_ft;
  AutopilotLaws_Y.out.data.H_ind_ft = AutopilotLaws_U.in.data.H_ind_ft;
  AutopilotLaws_Y.out.data.H_radio_ft = AutopilotLaws_U.in.data.H_radio_ft;
  AutopilotLaws_Y.out.data.H_dot_ft_min = AutopilotLaws_U.in.data.H_dot_ft_min;
  AutopilotLaws_Y.out.data.Psi_magnetic_deg = AutopilotLaws_U.in.data.Psi_magnetic_deg;
  AutopilotLaws_Y.out.data.Psi_magnetic_track_deg = AutopilotLaws_U.in.data.Psi_magnetic_track_deg;
  AutopilotLaws_Y.out.data.Psi_true_deg = AutopilotLaws_U.in.data.Psi_true_deg;
  AutopilotLaws_Y.out.data.ax_m_s2 = result_0[0];
  AutopilotLaws_Y.out.data.ay_m_s2 = result_0[1];
  AutopilotLaws_Y.out.data.az_m_s2 = result_0[2];
  AutopilotLaws_Y.out.data.bx_m_s2 = AutopilotLaws_U.in.data.bx_m_s2;
  AutopilotLaws_Y.out.data.by_m_s2 = AutopilotLaws_U.in.data.by_m_s2;
  AutopilotLaws_Y.out.data.bz_m_s2 = AutopilotLaws_U.in.data.bz_m_s2;
  AutopilotLaws_Y.out.data.nav_valid = AutopilotLaws_U.in.data.nav_valid;
  AutopilotLaws_Y.out.data.nav_loc_deg = AutopilotLaws_U.in.data.nav_loc_deg;
  AutopilotLaws_Y.out.data.nav_gs_deg = rtb_Saturation;
  AutopilotLaws_Y.out.data.nav_dme_valid = AutopilotLaws_U.in.data.nav_dme_valid;
  AutopilotLaws_Y.out.data.nav_dme_nmi = AutopilotLaws_U.in.data.nav_dme_nmi;
  AutopilotLaws_Y.out.data.nav_loc_valid = AutopilotLaws_U.in.data.nav_loc_valid;
  AutopilotLaws_Y.out.data.nav_loc_error_deg = AutopilotLaws_U.in.data.nav_loc_error_deg;
  AutopilotLaws_Y.out.data.nav_gs_valid = AutopilotLaws_U.in.data.nav_gs_valid;
  AutopilotLaws_Y.out.data.nav_gs_error_deg = AutopilotLaws_U.in.data.nav_gs_error_deg;
  AutopilotLaws_Y.out.data.flight_guidance_xtk_nmi = AutopilotLaws_U.in.data.flight_guidance_xtk_nmi;
  AutopilotLaws_Y.out.data.flight_guidance_tae_deg = AutopilotLaws_U.in.data.flight_guidance_tae_deg;
  AutopilotLaws_Y.out.data.flight_guidance_phi_deg = AutopilotLaws_U.in.data.flight_guidance_phi_deg;
  AutopilotLaws_Y.out.data.flight_phase = AutopilotLaws_U.in.data.flight_phase;
  AutopilotLaws_Y.out.data.V2_kn = AutopilotLaws_U.in.data.V2_kn;
  AutopilotLaws_Y.out.data.VAPP_kn = AutopilotLaws_U.in.data.VAPP_kn;
  AutopilotLaws_Y.out.data.VLS_kn = AutopilotLaws_U.in.data.VLS_kn;
  AutopilotLaws_Y.out.data.VMAX_kn = AutopilotLaws_U.in.data.VMAX_kn;
  AutopilotLaws_Y.out.data.is_flight_plan_available = AutopilotLaws_U.in.data.is_flight_plan_available;
  AutopilotLaws_Y.out.data.altitude_constraint_ft = AutopilotLaws_U.in.data.altitude_constraint_ft;
  AutopilotLaws_Y.out.data.thrust_reduction_altitude = AutopilotLaws_U.in.data.thrust_reduction_altitude;
  AutopilotLaws_Y.out.data.thrust_reduction_altitude_go_around =
    AutopilotLaws_U.in.data.thrust_reduction_altitude_go_around;
  AutopilotLaws_Y.out.data.acceleration_altitude = AutopilotLaws_U.in.data.acceleration_altitude;
  AutopilotLaws_Y.out.data.acceleration_altitude_engine_out = AutopilotLaws_U.in.data.acceleration_altitude_engine_out;
  AutopilotLaws_Y.out.data.acceleration_altitude_go_around = AutopilotLaws_U.in.data.acceleration_altitude_go_around;
  AutopilotLaws_Y.out.data.acceleration_altitude_go_around_engine_out =
    AutopilotLaws_U.in.data.acceleration_altitude_go_around_engine_out;
  AutopilotLaws_Y.out.data.cruise_altitude = AutopilotLaws_U.in.data.cruise_altitude;
  AutopilotLaws_Y.out.data.on_ground = rtb_on_ground;
  AutopilotLaws_Y.out.data.zeta_deg = AutopilotLaws_P.Gain2_Gain_b * AutopilotLaws_U.in.data.zeta_pos;
  AutopilotLaws_Y.out.data.throttle_lever_1_pos = AutopilotLaws_U.in.data.throttle_lever_1_pos;
  AutopilotLaws_Y.out.data.throttle_lever_2_pos = AutopilotLaws_U.in.data.throttle_lever_2_pos;
  AutopilotLaws_Y.out.data.flaps_handle_index = AutopilotLaws_U.in.data.flaps_handle_index;
  AutopilotLaws_Y.out.data.is_engine_operative_1 = AutopilotLaws_U.in.data.is_engine_operative_1;
  AutopilotLaws_Y.out.data.is_engine_operative_2 = AutopilotLaws_U.in.data.is_engine_operative_2;
  AutopilotLaws_Y.out.input = AutopilotLaws_U.in.input;
  AutopilotLaws_Y.out.output.ap_on = rtb_BusAssignment_output_ap_on;
  AutopilotLaws_Y.out.output.Phi_loc_c = rtb_Saturation1;
  for (rtb_on_ground = 0; rtb_on_ground < 99; rtb_on_ground++) {
    AutopilotLaws_DWork.Delay_DSTATE_l[rtb_on_ground] = AutopilotLaws_DWork.Delay_DSTATE_l[rtb_on_ground + 1];
    AutopilotLaws_DWork.Delay_DSTATE_h5[rtb_on_ground] = AutopilotLaws_DWork.Delay_DSTATE_h5[rtb_on_ground + 1];
  }

  AutopilotLaws_DWork.Delay_DSTATE_l[99] = rtb_Compare;
  AutopilotLaws_DWork.Delay_DSTATE_h5[99] = rtb_Delay_hu;
  AutopilotLaws_DWork.Delay_DSTATE_i = rtb_Mod2;
  AutopilotLaws_DWork.icLoad = 0U;
  AutopilotLaws_DWork.Delay_DSTATE_g = rtb_ManualSwitch;
  AutopilotLaws_DWork.Delay_DSTATE_k = rtb_Gain_mc;
  AutopilotLaws_DWork.icLoad_f = 0U;
}

void AutopilotLawsModelClass::initialize()
{
  {
    int32_T i;
    AutopilotLaws_DWork.Delay_DSTATE = AutopilotLaws_P.DiscreteTimeIntegratorVariableTs_InitialCondition;
    for (i = 0; i < 100; i++) {
      AutopilotLaws_DWork.Delay_DSTATE_l[i] = AutopilotLaws_P.Delay_InitialCondition;
      AutopilotLaws_DWork.Delay_DSTATE_h5[i] = AutopilotLaws_P.Delay_InitialCondition_b;
    }

    AutopilotLaws_DWork.Delay_DSTATE_i = AutopilotLaws_P.DiscreteDerivativeVariableTs_InitialCondition;
    AutopilotLaws_DWork.icLoad = 1U;
    AutopilotLaws_DWork.Delay_DSTATE_g = AutopilotLaws_P.DiscreteDerivativeVariableTs_InitialCondition_h;
    AutopilotLaws_DWork.Delay_DSTATE_k = AutopilotLaws_P.DiscreteDerivativeVariableTs2_InitialCondition;
    AutopilotLaws_DWork.icLoad_f = 1U;
    AutopilotLaws_B.u = AutopilotLaws_P.Y_Y0;
  }
}

void AutopilotLawsModelClass::terminate()
{
}

AutopilotLawsModelClass::AutopilotLawsModelClass() :
  AutopilotLaws_B(),
  AutopilotLaws_DWork(),
  AutopilotLaws_U(),
  AutopilotLaws_Y()
{
}

AutopilotLawsModelClass::~AutopilotLawsModelClass()
{
}
