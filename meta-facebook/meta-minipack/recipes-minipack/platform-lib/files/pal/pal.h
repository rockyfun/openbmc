/*
 *
 * Copyright 2018-present Facebook. All Rights Reserved.
 *
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#ifndef __PAL_H__
#define __PAL_H__

#include <openbmc/obmc-pal.h>

#ifdef __cplusplus
extern "C" {
#endif

#include <openbmc/kv.h>
#include <openbmc/ipmi.h>
#include <stdbool.h>
#include <math.h>
#include <facebook/bic.h>

#define PLATFORM_NAME "minipack"

#define GPIO_VAL "/sys/class/gpio/gpio%d/value"
#define GPIO_DIR "/sys/class/gpio/gpio%d/direction"
#define SCM_SYSFS "/sys/class/i2c-adapter/i2c-2/2-0035/%s"
#define SMB_SYSFS "/sys/class/i2c-adapter/i2c-12/12-003e/%s"
#define FCM_T_SYSFS "/sys/class/i2c-adapter/i2c-64/64-0033/%s"
#define FCM_B_SYSFS "/sys/class/i2c-adapter/i2c-72/72-0033/%s"
#define SENSORD_FILE_SMB "/tmp/cache_store/smb_sensor%d"
#define SENSORD_FILE_PSU "/tmp/cache_store/psu%d_sensor%d"
#define KV_PATH "/mnt/data/kv_store/%s"

#define MINIPACK_SDR_PATH "/tmp/sdr_%s.bin"

#define COM_PWR_BTN_N "com_pwr_btn_n"
#define SYS_LED_COLOR "sys_led_color"

#define SCM_PRSNT_STATUS "scm_presnt_status"
#define PIM_PRSNT_STATUS "pim_fpga_cpld_%d_prsnt_n_status"
#define FAN_PRSNT_STATUS "fantray%d_present"
#define PSU_L_PRSNT_STATUS "psu_L%d_present_L"
#define PSU_R_PRSNT_STATUS "psu_R%d_present_L"
#define KV_PIM_HEALTH "pim%d_sensor_health"
#define CRASHDUMP_BIN       "/usr/local/bin/autodump.sh"

#define LAST_KEY "last_key"

#define I2C_BUS_1_DIR          "/sys/class/i2c-adapter/i2c-1/"
#define I2C_BUS_3_DIR          "/sys/class/i2c-adapter/i2c-3/"
#define I2C_BUS_13_DIR         "/sys/class/i2c-adapter/i2c-13/"
#define I2C_BUS_16_DIR         "/sys/class/i2c-adapter/i2c-16/"
#define I2C_BUS_17_DIR         "/sys/class/i2c-adapter/i2c-17/"
#define I2C_BUS_30_DIR         "/sys/class/i2c-adapter/i2c-30/"
#define I2C_BUS_48_DIR         "/sys/class/i2c-adapter/i2c-48/"
#define I2C_BUS_49_DIR         "/sys/class/i2c-adapter/i2c-49/"
#define I2C_BUS_51_DIR         "/sys/class/i2c-adapter/i2c-51/"
#define I2C_BUS_52_DIR         "/sys/class/i2c-adapter/i2c-52/"
#define I2C_BUS_56_DIR         "/sys/class/i2c-adapter/i2c-56/"
#define I2C_BUS_57_DIR         "/sys/class/i2c-adapter/i2c-57/"
#define I2C_BUS_59_DIR         "/sys/class/i2c-adapter/i2c-59/"
#define I2C_BUS_60_DIR         "/sys/class/i2c-adapter/i2c-60/"
#define I2C_BUS_64_DIR         "/sys/class/i2c-adapter/i2c-64/"
#define I2C_BUS_66_DIR         "/sys/class/i2c-adapter/i2c-66/"
#define I2C_BUS_67_DIR         "/sys/class/i2c-adapter/i2c-67/"
#define I2C_BUS_72_DIR         "/sys/class/i2c-adapter/i2c-72/"
#define I2C_BUS_74_DIR         "/sys/class/i2c-adapter/i2c-74/"
#define I2C_BUS_75_DIR         "/sys/class/i2c-adapter/i2c-75/"
#define I2C_BUS_82_DIR         "/sys/class/i2c-adapter/i2c-82/"
#define I2C_BUS_83_DIR         "/sys/class/i2c-adapter/i2c-83/"
#define I2C_BUS_84_DIR         "/sys/class/i2c-adapter/i2c-84/"
#define I2C_BUS_86_DIR         "/sys/class/i2c-adapter/i2c-86/"
#define I2C_BUS_90_DIR         "/sys/class/i2c-adapter/i2c-90/"
#define I2C_BUS_91_DIR         "/sys/class/i2c-adapter/i2c-91/"
#define I2C_BUS_92_DIR         "/sys/class/i2c-adapter/i2c-92/"
#define I2C_BUS_94_DIR         "/sys/class/i2c-adapter/i2c-94/"
#define I2C_BUS_98_DIR         "/sys/class/i2c-adapter/i2c-98/"
#define I2C_BUS_99_DIR         "/sys/class/i2c-adapter/i2c-99/"
#define I2C_BUS_100_DIR        "/sys/class/i2c-adapter/i2c-100/"
#define I2C_BUS_102_DIR        "/sys/class/i2c-adapter/i2c-102/"
#define I2C_BUS_106_DIR        "/sys/class/i2c-adapter/i2c-106/"
#define I2C_BUS_107_DIR        "/sys/class/i2c-adapter/i2c-107/"
#define I2C_BUS_108_DIR        "/sys/class/i2c-adapter/i2c-108/"
#define I2C_BUS_110_DIR        "/sys/class/i2c-adapter/i2c-110/"
#define I2C_BUS_114_DIR        "/sys/class/i2c-adapter/i2c-114/"
#define I2C_BUS_115_DIR        "/sys/class/i2c-adapter/i2c-115/"
#define I2C_BUS_116_DIR        "/sys/class/i2c-adapter/i2c-116/"
#define I2C_BUS_118_DIR        "/sys/class/i2c-adapter/i2c-118/"
#define I2C_BUS_122_DIR        "/sys/class/i2c-adapter/i2c-122/"
#define I2C_BUS_123_DIR        "/sys/class/i2c-adapter/i2c-123/"
#define I2C_BUS_124_DIR        "/sys/class/i2c-adapter/i2c-124/"
#define I2C_BUS_126_DIR        "/sys/class/i2c-adapter/i2c-126/"
#define I2C_BUS_130_DIR        "/sys/class/i2c-adapter/i2c-130/"
#define I2C_BUS_131_DIR        "/sys/class/i2c-adapter/i2c-131/"
#define I2C_BUS_132_DIR        "/sys/class/i2c-adapter/i2c-132/"
#define I2C_BUS_134_DIR        "/sys/class/i2c-adapter/i2c-134/"
#define I2C_BUS_138_DIR        "/sys/class/i2c-adapter/i2c-138/"
#define I2C_BUS_139_DIR        "/sys/class/i2c-adapter/i2c-139/"
#define I2C_BUS_140_DIR        "/sys/class/i2c-adapter/i2c-140/"
#define I2C_BUS_142_DIR        "/sys/class/i2c-adapter/i2c-142/"

#define SMB_IR_DEVICE          I2C_BUS_1_DIR"1-0012"
#define SMB_ISL_DEVICE         I2C_BUS_1_DIR"1-0060"
#define SMB_1220_DEVICE        I2C_BUS_1_DIR"1-003a/hwmon/hwmon*"
#define SMB_TEMP1_DEVICE       I2C_BUS_3_DIR"3-0048/hwmon/hwmon*"
#define SMB_TEMP2_DEVICE       I2C_BUS_3_DIR"3-0049/hwmon/hwmon*"
#define SMB_TEMP3_DEVICE       I2C_BUS_3_DIR"3-004a/hwmon/hwmon*"
#define SMB_TEMP4_DEVICE       I2C_BUS_3_DIR"3-004b/hwmon/hwmon*"
#define SMB_IOB_DEVICE         I2C_BUS_13_DIR"13-0035"
#define SCM_HSC_DEVICE         I2C_BUS_16_DIR"16-0010/hwmon/hwmon*"
#define SCM_OUTLET_TEMP_DEVICE I2C_BUS_17_DIR"17-004c/hwmon/hwmon*"
#define SCM_INLET_TEMP_DEVICE  I2C_BUS_17_DIR"17-004d/hwmon/hwmon*"
#define SMB_TH3_TEMP_DEVICE    I2C_BUS_30_DIR"30-004c/hwmon/hwmon*"
#define SMB_PDB_L_TEMP1_DEVICE I2C_BUS_51_DIR"51-0048/hwmon/hwmon*"
#define SMB_PDB_L_TEMP2_DEVICE I2C_BUS_52_DIR"52-0049/hwmon/hwmon*"
#define SMB_PDB_R_TEMP1_DEVICE I2C_BUS_59_DIR"59-0048/hwmon/hwmon*"
#define SMB_PDB_R_TEMP2_DEVICE I2C_BUS_60_DIR"60-0049/hwmon/hwmon*"
#define SMB_FCM_T_TACH_DEVICE  I2C_BUS_64_DIR"64-0033"
#define SMB_FCM_T_TEMP1_DEVICE I2C_BUS_66_DIR"66-0048/hwmon/hwmon*"
#define SMB_FCM_T_TEMP2_DEVICE I2C_BUS_66_DIR"66-0049/hwmon/hwmon*"
#define SMB_FCM_T_HSC_DEVICE   I2C_BUS_67_DIR"67-0010/hwmon/hwmon*"
#define SMB_FCM_B_TACH_DEVICE  I2C_BUS_72_DIR"72-0033"
#define SMB_FCM_B_TEMP1_DEVICE I2C_BUS_74_DIR"74-0048/hwmon/hwmon*"
#define SMB_FCM_B_TEMP2_DEVICE I2C_BUS_74_DIR"74-0049/hwmon/hwmon*"
#define SMB_FCM_B_HSC_DEVICE   I2C_BUS_75_DIR"75-0010/hwmon/hwmon*"
#define PIM1_TEMP1_DEVICE      I2C_BUS_82_DIR"82-0048/hwmon/hwmon*"
#define PIM1_TEMP2_DEVICE      I2C_BUS_83_DIR"83-004b/hwmon/hwmon*"
#define PIM1_HSC_DEVICE        I2C_BUS_84_DIR"84-0010/hwmon/hwmon*"
#define PIM1_34461_DEVICE      I2C_BUS_86_DIR"86-0074/hwmon/hwmon*"
#define PIM2_TEMP1_DEVICE      I2C_BUS_90_DIR"90-0048/hwmon/hwmon*"
#define PIM2_TEMP2_DEVICE      I2C_BUS_91_DIR"91-004b/hwmon/hwmon*"
#define PIM2_HSC_DEVICE        I2C_BUS_92_DIR"92-0010/hwmon/hwmon*"
#define PIM2_34461_DEVICE      I2C_BUS_94_DIR"94-0074/hwmon/hwmon*"
#define PIM3_TEMP1_DEVICE      I2C_BUS_98_DIR"98-0048/hwmon/hwmon*"
#define PIM3_TEMP2_DEVICE      I2C_BUS_99_DIR"99-004b/hwmon/hwmon*"
#define PIM3_HSC_DEVICE        I2C_BUS_100_DIR"100-0010/hwmon/hwmon*"
#define PIM3_34461_DEVICE      I2C_BUS_102_DIR"102-0074/hwmon/hwmon*"
#define PIM4_TEMP1_DEVICE      I2C_BUS_106_DIR"106-0048/hwmon/hwmon*"
#define PIM4_TEMP2_DEVICE      I2C_BUS_107_DIR"107-004b/hwmon/hwmon*"
#define PIM4_HSC_DEVICE        I2C_BUS_108_DIR"108-0010/hwmon/hwmon*"
#define PIM4_34461_DEVICE      I2C_BUS_110_DIR"110-0074/hwmon/hwmon*"
#define PIM5_TEMP1_DEVICE      I2C_BUS_114_DIR"114-0048/hwmon/hwmon*"
#define PIM5_TEMP2_DEVICE      I2C_BUS_115_DIR"115-004b/hwmon/hwmon*"
#define PIM5_HSC_DEVICE        I2C_BUS_116_DIR"116-0010/hwmon/hwmon*"
#define PIM5_34461_DEVICE      I2C_BUS_118_DIR"118-0074/hwmon/hwmon*"
#define PIM6_TEMP1_DEVICE      I2C_BUS_122_DIR"122-0048/hwmon/hwmon*"
#define PIM6_TEMP2_DEVICE      I2C_BUS_123_DIR"123-004b/hwmon/hwmon*"
#define PIM6_HSC_DEVICE        I2C_BUS_124_DIR"124-0010/hwmon/hwmon*"
#define PIM6_34461_DEVICE      I2C_BUS_126_DIR"126-0074/hwmon/hwmon*"
#define PIM7_TEMP1_DEVICE      I2C_BUS_130_DIR"130-0048/hwmon/hwmon*"
#define PIM7_TEMP2_DEVICE      I2C_BUS_131_DIR"131-004b/hwmon/hwmon*"
#define PIM7_HSC_DEVICE        I2C_BUS_132_DIR"132-0010/hwmon/hwmon*"
#define PIM7_34461_DEVICE      I2C_BUS_134_DIR"134-0074/hwmon/hwmon*"
#define PIM8_TEMP1_DEVICE      I2C_BUS_138_DIR"138-0048/hwmon/hwmon*"
#define PIM8_TEMP2_DEVICE      I2C_BUS_139_DIR"139-004b/hwmon/hwmon*"
#define PIM8_HSC_DEVICE        I2C_BUS_140_DIR"140-0010/hwmon/hwmon*"
#define PIM8_34461_DEVICE      I2C_BUS_142_DIR"142-0074/hwmon/hwmon*"
#define PSU1_DEVICE            I2C_BUS_49_DIR"49-0059"
#define PSU2_DEVICE            I2C_BUS_48_DIR"48-0058"
#define PSU3_DEVICE            I2C_BUS_57_DIR"57-0059"
#define PSU4_DEVICE            I2C_BUS_56_DIR"56-0058"

#define TEMP(x)  "temp"#x"_input"
#define VOLT(x)  "in"#x"_input"
#define CURR(x)  "curr"#x"_input"
#define POWER(x) "power"#x"_input"

#define GPIO_MB_REV_ID_0 52
#define GPIO_MB_REV_ID_1 53
#define GPIO_MB_REV_ID_2 54
#define GPIO_POSTCODE_0 56
#define GPIO_POSTCODE_1 57
#define GPIO_POSTCODE_2 58
#define GPIO_POSTCODE_3 59
#define GPIO_POSTCODE_4 60
#define GPIO_POSTCODE_5 61
#define GPIO_POSTCODE_6 62
#define GPIO_POSTCODE_7 63
#define GPIO_SCM_USB_PRSNT  204

#define MAX_READ_RETRY 10
#define DELAY_POWER_OFF 5
#define DELAY_POWER_CYCLE 10

#define LARGEST_DEVICE_NAME 128
#define MINIPACK_MAX_NUM_SLOTS 1

#define UNIT_DIV 1000

#define READING_SKIP 1
#define READING_NA -2

#define SCM_RSENSE 1.16
#define PIM_RSENSE 1.42

#define IPMB_BUS 0

#define BMC_READY_N   28
#define BOARD_REV_EVTA 4
#define BOARD_REV_EVTB 0
#define BIC_SENSOR_READ_NA 0x20
#define THERMAL_CONSTANT   256
#define ERR_NOT_READY   -2
#define MAX_NODES     1
#define MAX_NUM_FRUS    14
#define MAX_SENSOR_NUM  0xFF
#define MAX_SENSOR_THRESHOLD  8
#define MAX_SDR_LEN     64
#define MAX_PIM 8

#define FRU_STATUS_GOOD   1
#define FRU_STATUS_BAD    0

#define I2C_ADDR_SIM_LED 0x20
#define I2C_ADDR_PIM16Q 0x60
#define I2C_ADDR_PIM4DD 0x61

#define FPGA_STS_LED_REG 0x82
#define FPGA_STS_CLR_BLUE 0x01
#define FPGA_STS_CLR_YELLOW 0x05

extern const char pal_fru_list[];

typedef struct _sensor_info_t {
  bool valid;
  sdr_full_t sdr;
} sensor_info_t;

enum {
  BIC_MODE_NORMAL = 0x01,
  BIC_MODE_UPDATE = 0x0F,
};

enum {
  SERVER_POWER_OFF,
  SERVER_POWER_ON,
  SERVER_POWER_CYCLE,
  SERVER_POWER_RESET,
  SERVER_GRACEFUL_SHUTDOWN,
  SERVER_12V_OFF,
  SERVER_12V_ON,
  SERVER_12V_CYCLE,
};

enum {
  FRU_ALL = 0,
  FRU_SCM = 1,
  FRU_SMB = 2,
  FRU_PIM1 = 3,
  FRU_PIM2 = 4,
  FRU_PIM3 = 5,
  FRU_PIM4 = 6,
  FRU_PIM5 = 7,
  FRU_PIM6 = 8,
  FRU_PIM7 = 9,
  FRU_PIM8 = 10,
  FRU_PSU1 = 11,
  FRU_PSU2 = 12,
  FRU_PSU3 = 13,
  FRU_PSU4 = 14,
  FRU_FAN1 = 15,
  FRU_FAN2 = 16,
  FRU_FAN3 = 17,
  FRU_FAN4 = 18,
  FRU_FAN5 = 19,
  FRU_FAN6 = 20,
  FRU_FAN7 = 21,
  FRU_FAN8 = 22,
};

enum {
  HSC_FCM_T = 0,
  HSC_FCM_B = 1
};

/* Sensors on SCM */
enum {
  SCM_SENSOR_OUTLET_LOCAL_TEMP = 0x02,
  SCM_SENSOR_OUTLET_REMOTE_TEMP = 0x03,
  SCM_SENSOR_INLET_LOCAL_TEMP = 0x04,
  SCM_SENSOR_INLET_REMOTE_TEMP = 0x06,
  SCM_SENSOR_HSC_VOLT = 0x0a,
  SCM_SENSOR_HSC_CURR = 0x0b,
  SCM_SENSOR_HSC_POWER = 0x0c,
  /* Sensors on COM-e */
  BIC_SENSOR_MB_OUTLET_TEMP = 0x01,
  BIC_SENSOR_MB_INLET_TEMP = 0x07,
  BIC_SENSOR_PCH_TEMP = 0x08,
  BIC_SENSOR_VCCIN_VR_TEMP = 0x80,
  BIC_SENSOR_1V05MIX_VR_TEMP = 0x81,
  BIC_SENSOR_SOC_TEMP = 0x05,
  BIC_SENSOR_SOC_THERM_MARGIN = 0x09,
  BIC_SENSOR_VDDR_VR_TEMP = 0x82,
  BIC_SENSOR_SOC_DIMMA0_TEMP = 0xB4,
  BIC_SENSOR_SOC_DIMMB0_TEMP = 0xB6,
  BIC_SENSOR_SOC_PACKAGE_PWR = 0x2C,
  BIC_SENSOR_VCCIN_VR_POUT = 0x8B,
  BIC_SENSOR_VDDR_VR_POUT = 0x8D,
  BIC_SENSOR_SOC_TJMAX = 0x30,
  BIC_SENSOR_P3V3_MB = 0xD0,
  BIC_SENSOR_P12V_MB = 0xD2,
  BIC_SENSOR_P1V05_PCH = 0xD3,
  BIC_SENSOR_P3V3_STBY_MB = 0xD5,
  BIC_SENSOR_P5V_STBY_MB = 0xD6,
  BIC_SENSOR_PV_BAT = 0xD7,
  BIC_SENSOR_PVDDR = 0xD8,
  BIC_SENSOR_P1V05_MIX = 0x8E,
  BIC_SENSOR_1V05MIX_VR_CURR = 0x84,
  BIC_SENSOR_VDDR_VR_CURR = 0x85,
  BIC_SENSOR_VCCIN_VR_CURR = 0x83,
  BIC_SENSOR_VCCIN_VR_VOL = 0x88,
  BIC_SENSOR_VDDR_VR_VOL = 0x8A,
  BIC_SENSOR_P1V05MIX_VR_VOL = 0x89,
  BIC_SENSOR_P1V05MIX_VR_POUT = 0x8C,
  BIC_SENSOR_INA230_POWER = 0x29,
  BIC_SENSOR_INA230_VOL = 0x2A,
  BIC_SENSOR_SYSTEM_STATUS = 0x10, //Discrete
  BIC_SENSOR_PROC_FAIL = 0x65, //Discrete
  BIC_SENSOR_SYS_BOOT_STAT = 0x7E, //Discrete
  BIC_SENSOR_VR_HOT = 0xB2, //Discrete
  BIC_SENSOR_CPU_DIMM_HOT = 0xB3, //Discrete
  BIC_SENSOR_SPS_FW_HLTH = 0x17, //Event-only
  BIC_SENSOR_POST_ERR = 0x2B, //Event-only
  BIC_SENSOR_POWER_THRESH_EVENT = 0x3B, //Event-only
  BIC_SENSOR_MACHINE_CHK_ERR = 0x40, //Event-only
  BIC_SENSOR_PCIE_ERR = 0x41, //Event-only
  BIC_SENSOR_OTHER_IIO_ERR = 0x43, //Event-only
  BIC_SENSOR_PROC_HOT_EXT = 0x51, //Event-only
  BIC_SENSOR_POWER_ERR = 0x56, //Event-only
  BIC_SENSOR_MEM_ECC_ERR = 0x63, //Event-only
  BIC_SENSOR_CAT_ERR = 0xEB, //Event-only
};

/* Sensors on SMB */
enum {
  SMB_SENSOR_1220_VMON1 = 0x01,
  SMB_SENSOR_1220_VMON2 = 0x02,
  SMB_SENSOR_1220_VMON3 = 0x03,
  SMB_SENSOR_1220_VMON4 = 0x04,
  SMB_SENSOR_1220_VMON5 = 0x05,
  SMB_SENSOR_1220_VMON6 = 0x06,
  SMB_SENSOR_1220_VMON7 = 0x07,
  SMB_SENSOR_1220_VMON8 = 0x08,
  SMB_SENSOR_1220_VMON9 = 0x09,
  SMB_SENSOR_1220_VMON10 = 0x0a,
  SMB_SENSOR_1220_VMON11 = 0x0b,
  SMB_SENSOR_1220_VMON12 = 0x0c,
  SMB_SENSOR_1220_VCCA = 0x0d,
  SMB_SENSOR_1220_VCCINP = 0x0e,
  SMB_SENSOR_TH3_SERDES_VOLT = 0x0f,
  SMB_SENSOR_TH3_SERDES_CURR = 0x10,
  SMB_SENSOR_TH3_SERDES_TEMP = 0x11,
  SMB_SENSOR_TH3_CORE_VOLT = 0x12,
  SMB_SENSOR_TH3_CORE_CURR = 0x13,
  SMB_SENSOR_TH3_CORE_TEMP = 0x14,
  SMB_SENSOR_TEMP1 = 0x15,
  SMB_SENSOR_TEMP2 = 0x16,
  SMB_SENSOR_TEMP3 = 0x17,
  SMB_SENSOR_TEMP4 = 0x18,
  SMB_SENSOR_TEMP5 = 0x19,
  SMB_SENSOR_TH3_DIE_TEMP1 = 0x1a,
  SMB_SENSOR_TH3_DIE_TEMP2 = 0x1b,
  /* Sensors on PDB */
  SMB_SENSOR_PDB_L_TEMP1 = 0x1c,
  SMB_SENSOR_PDB_L_TEMP2 = 0x1d,
  SMB_SENSOR_PDB_R_TEMP1 = 0x1e,
  SMB_SENSOR_PDB_R_TEMP2 = 0x1f,
  /* Sensors on FCM */
  SMB_SENSOR_FCM_T_TEMP1 = 0x20,
  SMB_SENSOR_FCM_T_TEMP2 = 0x21,
  SMB_SENSOR_FCM_B_TEMP1 = 0x22,
  SMB_SENSOR_FCM_B_TEMP2 = 0x23,
  SMB_SENSOR_FCM_T_HSC_VOLT = 0x24,
  SMB_SENSOR_FCM_T_HSC_CURR = 0x25,
  SMB_SENSOR_FCM_T_HSC_POWER = 0x26,
  SMB_SENSOR_FCM_B_HSC_VOLT = 0x27,
  SMB_SENSOR_FCM_B_HSC_CURR = 0x28,
  SMB_SENSOR_FCM_B_HSC_POWER = 0x29,
  /* Sensors FAN Speed */
  SMB_SENSOR_FAN1_FRONT_TACH = 0x2a,
  SMB_SENSOR_FAN1_REAR_TACH = 0x2b,
  SMB_SENSOR_FAN2_FRONT_TACH = 0x2c,
  SMB_SENSOR_FAN2_REAR_TACH = 0x2d,
  SMB_SENSOR_FAN3_FRONT_TACH = 0x2e,
  SMB_SENSOR_FAN3_REAR_TACH = 0x2f,
  SMB_SENSOR_FAN4_FRONT_TACH = 0x30,
  SMB_SENSOR_FAN4_REAR_TACH = 0x31,
  SMB_SENSOR_FAN5_FRONT_TACH = 0x32,
  SMB_SENSOR_FAN5_REAR_TACH = 0x33,
  SMB_SENSOR_FAN6_FRONT_TACH = 0x34,
  SMB_SENSOR_FAN6_REAR_TACH = 0x35,
  SMB_SENSOR_FAN7_FRONT_TACH = 0x36,
  SMB_SENSOR_FAN7_REAR_TACH = 0x37,
  SMB_SENSOR_FAN8_FRONT_TACH = 0x38,
  SMB_SENSOR_FAN8_REAR_TACH = 0x39,
};

/* Sensors on PIM */
enum {
  /* Sensors on PIM1 */
  PIM1_SENSOR_TEMP1 = 0x01,
  PIM1_SENSOR_TEMP2 = 0x02,
  PIM1_SENSOR_HSC_VOLT = 0x03,
  PIM1_SENSOR_HSC_CURR = 0x04,
  PIM1_SENSOR_HSC_POWER = 0x05,
  PIM1_SENSOR_34461_VOLT1 = 0x06,
  PIM1_SENSOR_34461_VOLT2 = 0x07,
  PIM1_SENSOR_34461_VOLT3 = 0x08,
  PIM1_SENSOR_34461_VOLT4 = 0x09,
  PIM1_SENSOR_34461_VOLT5 = 0x0a,
  PIM1_SENSOR_34461_VOLT6 = 0x0b,
  PIM1_SENSOR_34461_VOLT7 = 0x0c,
  PIM1_SENSOR_34461_VOLT8 = 0x0d,
  PIM1_SENSOR_34461_VOLT9 = 0x0e,
  PIM1_SENSOR_34461_VOLT10 = 0x0f,
  PIM1_SENSOR_34461_VOLT11 = 0x10,
  PIM1_SENSOR_34461_VOLT12 = 0x11,
  PIM1_SENSOR_34461_VOLT13 = 0x12,
  PIM1_SENSOR_34461_VOLT14 = 0x13,
  PIM1_SENSOR_34461_VOLT15 = 0x14,
  PIM1_SENSOR_34461_VOLT16 = 0x15,
  /* Sensors on PIM2 */
  PIM2_SENSOR_TEMP1 = 0x16,
  PIM2_SENSOR_TEMP2 = 0x17,
  PIM2_SENSOR_HSC_VOLT = 0x18,
  PIM2_SENSOR_HSC_CURR = 0x19,
  PIM2_SENSOR_HSC_POWER = 0x1a,
  PIM2_SENSOR_34461_VOLT1 = 0x1b,
  PIM2_SENSOR_34461_VOLT2 = 0x1c,
  PIM2_SENSOR_34461_VOLT3 = 0x1d,
  PIM2_SENSOR_34461_VOLT4 = 0x1e,
  PIM2_SENSOR_34461_VOLT5 = 0x1f,
  PIM2_SENSOR_34461_VOLT6 = 0x20,
  PIM2_SENSOR_34461_VOLT7 = 0x21,
  PIM2_SENSOR_34461_VOLT8 = 0x22,
  PIM2_SENSOR_34461_VOLT9 = 0x23,
  PIM2_SENSOR_34461_VOLT10 = 0x24,
  PIM2_SENSOR_34461_VOLT11 = 0x25,
  PIM2_SENSOR_34461_VOLT12 = 0x26,
  PIM2_SENSOR_34461_VOLT13 = 0x27,
  PIM2_SENSOR_34461_VOLT14 = 0x28,
  PIM2_SENSOR_34461_VOLT15 = 0x29,
  PIM2_SENSOR_34461_VOLT16 = 0x2a,
  /* Sensors on PIM3 */
  PIM3_SENSOR_TEMP1 = 0x2b,
  PIM3_SENSOR_TEMP2 = 0x2c,
  PIM3_SENSOR_HSC_VOLT = 0x2d,
  PIM3_SENSOR_HSC_CURR = 0x2e,
  PIM3_SENSOR_HSC_POWER = 0x2f,
  PIM3_SENSOR_34461_VOLT1 = 0x30,
  PIM3_SENSOR_34461_VOLT2 = 0x31,
  PIM3_SENSOR_34461_VOLT3 = 0x32,
  PIM3_SENSOR_34461_VOLT4 = 0x33,
  PIM3_SENSOR_34461_VOLT5 = 0x34,
  PIM3_SENSOR_34461_VOLT6 = 0x35,
  PIM3_SENSOR_34461_VOLT7 = 0x36,
  PIM3_SENSOR_34461_VOLT8 = 0x37,
  PIM3_SENSOR_34461_VOLT9 = 0x38,
  PIM3_SENSOR_34461_VOLT10 = 0x39,
  PIM3_SENSOR_34461_VOLT11 = 0x3a,
  PIM3_SENSOR_34461_VOLT12 = 0x3b,
  PIM3_SENSOR_34461_VOLT13 = 0x3c,
  PIM3_SENSOR_34461_VOLT14 = 0x3d,
  PIM3_SENSOR_34461_VOLT15 = 0x3e,
  PIM3_SENSOR_34461_VOLT16 = 0x3f,
  /* Sensors on PIM4 */
  PIM4_SENSOR_TEMP1 = 0x40,
  PIM4_SENSOR_TEMP2 = 0x41,
  PIM4_SENSOR_HSC_VOLT = 0x42,
  PIM4_SENSOR_HSC_CURR = 0x43,
  PIM4_SENSOR_HSC_POWER = 0x44,
  PIM4_SENSOR_34461_VOLT1 = 0x45,
  PIM4_SENSOR_34461_VOLT2 = 0x46,
  PIM4_SENSOR_34461_VOLT3 = 0x47,
  PIM4_SENSOR_34461_VOLT4 = 0x48,
  PIM4_SENSOR_34461_VOLT5 = 0x49,
  PIM4_SENSOR_34461_VOLT6 = 0x4a,
  PIM4_SENSOR_34461_VOLT7 = 0x4b,
  PIM4_SENSOR_34461_VOLT8 = 0x4c,
  PIM4_SENSOR_34461_VOLT9 = 0x4d,
  PIM4_SENSOR_34461_VOLT10 = 0x4e,
  PIM4_SENSOR_34461_VOLT11 = 0x4f,
  PIM4_SENSOR_34461_VOLT12 = 0x50,
  PIM4_SENSOR_34461_VOLT13 = 0x51,
  PIM4_SENSOR_34461_VOLT14 = 0x52,
  PIM4_SENSOR_34461_VOLT15 = 0x53,
  PIM4_SENSOR_34461_VOLT16 = 0x54,
  /* Sensors on PIM5 */
  PIM5_SENSOR_TEMP1 = 0x55,
  PIM5_SENSOR_TEMP2 = 0x56,
  PIM5_SENSOR_HSC_VOLT = 0x57,
  PIM5_SENSOR_HSC_CURR = 0x58,
  PIM5_SENSOR_HSC_POWER = 0x59,
  PIM5_SENSOR_34461_VOLT1 = 0x5a,
  PIM5_SENSOR_34461_VOLT2 = 0x5b,
  PIM5_SENSOR_34461_VOLT3 = 0x5c,
  PIM5_SENSOR_34461_VOLT4 = 0x5d,
  PIM5_SENSOR_34461_VOLT5 = 0x5e,
  PIM5_SENSOR_34461_VOLT6 = 0x5f,
  PIM5_SENSOR_34461_VOLT7 = 0x60,
  PIM5_SENSOR_34461_VOLT8 = 0x61,
  PIM5_SENSOR_34461_VOLT9 = 0x62,
  PIM5_SENSOR_34461_VOLT10 = 0x63,
  PIM5_SENSOR_34461_VOLT11 = 0x64,
  PIM5_SENSOR_34461_VOLT12 = 0x65,
  PIM5_SENSOR_34461_VOLT13 = 0x66,
  PIM5_SENSOR_34461_VOLT14 = 0x67,
  PIM5_SENSOR_34461_VOLT15 = 0x68,
  PIM5_SENSOR_34461_VOLT16 = 0x69,
  /* Sensors on PIM6 */
  PIM6_SENSOR_TEMP1 = 0x6a,
  PIM6_SENSOR_TEMP2 = 0x6b,
  PIM6_SENSOR_HSC_VOLT = 0x6c,
  PIM6_SENSOR_HSC_CURR = 0x6d,
  PIM6_SENSOR_HSC_POWER = 0x6e,
  PIM6_SENSOR_34461_VOLT1 = 0x6f,
  PIM6_SENSOR_34461_VOLT2 = 0x70,
  PIM6_SENSOR_34461_VOLT3 = 0x71,
  PIM6_SENSOR_34461_VOLT4 = 0x72,
  PIM6_SENSOR_34461_VOLT5 = 0x73,
  PIM6_SENSOR_34461_VOLT6 = 0x74,
  PIM6_SENSOR_34461_VOLT7 = 0x75,
  PIM6_SENSOR_34461_VOLT8 = 0x76,
  PIM6_SENSOR_34461_VOLT9 = 0x77,
  PIM6_SENSOR_34461_VOLT10 = 0x78,
  PIM6_SENSOR_34461_VOLT11 = 0x79,
  PIM6_SENSOR_34461_VOLT12 = 0x7a,
  PIM6_SENSOR_34461_VOLT13 = 0x7b,
  PIM6_SENSOR_34461_VOLT14 = 0x7c,
  PIM6_SENSOR_34461_VOLT15 = 0x7d,
  PIM6_SENSOR_34461_VOLT16 = 0x7e,
  /* Sensors on PIM7 */
  PIM7_SENSOR_TEMP1 = 0x7f,
  PIM7_SENSOR_TEMP2 = 0x80,
  PIM7_SENSOR_HSC_VOLT = 0x81,
  PIM7_SENSOR_HSC_CURR = 0x82,
  PIM7_SENSOR_HSC_POWER = 0x83,
  PIM7_SENSOR_34461_VOLT1 = 0x84,
  PIM7_SENSOR_34461_VOLT2 = 0x85,
  PIM7_SENSOR_34461_VOLT3 = 0x86,
  PIM7_SENSOR_34461_VOLT4 = 0x87,
  PIM7_SENSOR_34461_VOLT5 = 0x88,
  PIM7_SENSOR_34461_VOLT6 = 0x89,
  PIM7_SENSOR_34461_VOLT7 = 0x8a,
  PIM7_SENSOR_34461_VOLT8 = 0x8b,
  PIM7_SENSOR_34461_VOLT9 = 0x8c,
  PIM7_SENSOR_34461_VOLT10 = 0x8d,
  PIM7_SENSOR_34461_VOLT11 = 0x8e,
  PIM7_SENSOR_34461_VOLT12 = 0x8f,
  PIM7_SENSOR_34461_VOLT13 = 0x90,
  PIM7_SENSOR_34461_VOLT14 = 0x91,
  PIM7_SENSOR_34461_VOLT15 = 0x92,
  PIM7_SENSOR_34461_VOLT16 = 0x93,
  /* Sensors on PIM8 */
  PIM8_SENSOR_TEMP1 = 0x94,
  PIM8_SENSOR_TEMP2 = 0x95,
  PIM8_SENSOR_HSC_VOLT = 0x96,
  PIM8_SENSOR_HSC_CURR = 0x97,
  PIM8_SENSOR_HSC_POWER = 0x98,
  PIM8_SENSOR_34461_VOLT1 = 0x99,
  PIM8_SENSOR_34461_VOLT2 = 0x9a,
  PIM8_SENSOR_34461_VOLT3 = 0x9b,
  PIM8_SENSOR_34461_VOLT4 = 0x9c,
  PIM8_SENSOR_34461_VOLT5 = 0x9d,
  PIM8_SENSOR_34461_VOLT6 = 0x9e,
  PIM8_SENSOR_34461_VOLT7 = 0x9f,
  PIM8_SENSOR_34461_VOLT8 = 0xa0,
  PIM8_SENSOR_34461_VOLT9 = 0xa1,
  PIM8_SENSOR_34461_VOLT10 = 0xa2,
  PIM8_SENSOR_34461_VOLT11 = 0xa3,
  PIM8_SENSOR_34461_VOLT12 = 0xa4,
  PIM8_SENSOR_34461_VOLT13 = 0xa5,
  PIM8_SENSOR_34461_VOLT14 = 0xa6,
  PIM8_SENSOR_34461_VOLT15 = 0xa7,
  PIM8_SENSOR_34461_VOLT16 = 0xa8,
  PIM1_SENSOR_QSFP_TEMP = 0xa9,
  PIM2_SENSOR_QSFP_TEMP = 0xaa,
  PIM3_SENSOR_QSFP_TEMP = 0xab,
  PIM4_SENSOR_QSFP_TEMP = 0xac,
  PIM5_SENSOR_QSFP_TEMP = 0xad,
  PIM6_SENSOR_QSFP_TEMP = 0xae,
  PIM7_SENSOR_QSFP_TEMP = 0xaf,
  PIM8_SENSOR_QSFP_TEMP = 0xb0,
};

/* Sensors on PSU */
enum {
  PSU1_SENSOR_IN_VOLT = 0x01,
  PSU1_SENSOR_12V_VOLT = 0x02,
  PSU1_SENSOR_STBY_VOLT = 0x03,
  PSU1_SENSOR_IN_CURR = 0x04,
  PSU1_SENSOR_12V_CURR = 0x05,
  PSU1_SENSOR_STBY_CURR = 0x06,
  PSU1_SENSOR_IN_POWER = 0x07,
  PSU1_SENSOR_12V_POWER = 0x08,
  PSU1_SENSOR_STBY_POWER = 0x09,
  PSU1_SENSOR_FAN_TACH = 0x0a,
  PSU1_SENSOR_TEMP1 = 0x0b,
  PSU1_SENSOR_TEMP2 = 0x0c,
  PSU1_SENSOR_TEMP3 = 0x0d,
  PSU2_SENSOR_IN_VOLT = 0x0e,
  PSU2_SENSOR_12V_VOLT = 0x0f,
  PSU2_SENSOR_STBY_VOLT = 0x10,
  PSU2_SENSOR_IN_CURR = 0x11,
  PSU2_SENSOR_12V_CURR = 0x12,
  PSU2_SENSOR_STBY_CURR = 0x13,
  PSU2_SENSOR_IN_POWER = 0x14,
  PSU2_SENSOR_12V_POWER = 0x15,
  PSU2_SENSOR_STBY_POWER = 0x16,
  PSU2_SENSOR_FAN_TACH = 0x17,
  PSU2_SENSOR_TEMP1 = 0x18,
  PSU2_SENSOR_TEMP2 = 0x19,
  PSU2_SENSOR_TEMP3 = 0x1a,
  PSU3_SENSOR_IN_VOLT = 0x1b,
  PSU3_SENSOR_12V_VOLT = 0x1c,
  PSU3_SENSOR_STBY_VOLT = 0x1d,
  PSU3_SENSOR_IN_CURR = 0x1e,
  PSU3_SENSOR_12V_CURR = 0x1f,
  PSU3_SENSOR_STBY_CURR = 0x20,
  PSU3_SENSOR_IN_POWER = 0x21,
  PSU3_SENSOR_12V_POWER = 0x22,
  PSU3_SENSOR_STBY_POWER = 0x23,
  PSU3_SENSOR_FAN_TACH = 0x24,
  PSU3_SENSOR_TEMP1 = 0x25,
  PSU3_SENSOR_TEMP2 = 0x26,
  PSU3_SENSOR_TEMP3 = 0x27,
  PSU4_SENSOR_IN_VOLT = 0x28,
  PSU4_SENSOR_12V_VOLT = 0x29,
  PSU4_SENSOR_STBY_VOLT = 0x2a,
  PSU4_SENSOR_IN_CURR = 0x2b,
  PSU4_SENSOR_12V_CURR = 0x2c,
  PSU4_SENSOR_STBY_CURR = 0x2d,
  PSU4_SENSOR_IN_POWER = 0x2e,
  PSU4_SENSOR_12V_POWER = 0x2f,
  PSU4_SENSOR_STBY_POWER = 0x30,
  PSU4_SENSOR_FAN_TACH = 0x31,
  PSU4_SENSOR_TEMP1 = 0x32,
  PSU4_SENSOR_TEMP2 = 0x33,
  PSU4_SENSOR_TEMP3 = 0x34,
};

enum
{
  SLED_CLR_BLUE = 0x3,
  SLED_CLR_YELLOW = 0x4,
  SLED_CLR_RED = 0x6,
  SLED_CLR_OFF = 0x7,
};

enum
{
  SLED_SYS = 1,
  SLED_FAN = 2,
  SLED_PSU = 3,
  SLED_SMB = 4,
};

enum
{
  SCM_LED_BLUE = 0x01,
  SCM_LED_AMBER = 0x05,
};

int pal_handle_oem_1s_intr(uint8_t slot, uint8_t *data);
void pal_inform_bic_mode(uint8_t fru, uint8_t mode);
int pal_get_plat_sku_id(void);
int pal_get_poss_pcie_config(uint8_t slot, uint8_t *req_data, uint8_t req_len, uint8_t *res_data, uint8_t *res_len);
int pal_get_key_value(char *key, char *value);
int pal_set_key_value(char *key, char *value);
int pal_set_sysfw_ver(uint8_t slot, uint8_t *ver);
int pal_get_sysfw_ver(uint8_t slot, uint8_t *ver);
int pal_get_platform_name(char *name);
int pal_is_fru_prsnt(uint8_t fru, uint8_t *status);
int pal_is_fru_ready(uint8_t fru, uint8_t *status);
int pal_get_fru_id(char *str, uint8_t *fru);
int pal_get_fru_name(uint8_t fru, char *name);
int pal_get_fru_list(char *list);
int pal_get_fru_sensor_list(uint8_t fru, uint8_t **sensor_list, int *cnt);
int pal_get_fru_discrete_list(uint8_t fru, uint8_t **sensor_list, int *cnt);
int pal_is_debug_card_prsnt(uint8_t *status);
int pal_post_enable(uint8_t slot);
int pal_post_disable(uint8_t slot);
int pal_post_get_last(uint8_t slot, uint8_t *status);
int pal_post_handle(uint8_t slot, uint8_t status);
int pal_set_last_pwr_state(uint8_t fru, char *state);
int pal_get_last_pwr_state(uint8_t fru, char *state);
int pal_set_com_pwr_btn_n(char *status);
int pal_set_server_power(uint8_t slot_id, uint8_t cmd);
int pal_get_server_power(uint8_t slot_id, uint8_t *status);
int pal_get_fan_speed(uint8_t fan, int *rpm);
int pal_get_board_rev(int *rev);
int pal_sensor_read_raw(uint8_t fru, uint8_t sensor_num, void *value);
bool pal_is_fw_update_ongoing(uint8_t fru);
int pal_get_fw_info(uint8_t fru, unsigned char target, unsigned char* res, unsigned char* res_len);
void pal_update_ts_sled();
int pal_get_sensor_name(uint8_t fru, uint8_t sensor_num, char *name);
int pal_get_sensor_units(uint8_t fru, uint8_t sensor_num, char *units);
int pal_get_sensor_threshold(uint8_t fru, uint8_t sensor_num, uint8_t thresh, void *value);
void pal_sensor_assert_handle(uint8_t fru, uint8_t snr_num, float val, uint8_t thresh);
void pal_sensor_deassert_handle(uint8_t fru, uint8_t snr_num, float val, uint8_t thresh);
int pal_sensor_threshold_flag(uint8_t fru, uint8_t snr_num, uint16_t *flag);
int pal_detect_i2c_device(uint8_t bus_num, uint8_t addr);
int pal_add_i2c_device(uint8_t bus, uint8_t addr, char *device_name);
int pal_del_i2c_device(uint8_t bus, uint8_t addr);
int pal_get_pim_type(uint8_t fru);
void pal_get_chassis_status(uint8_t slot, uint8_t *req_data, uint8_t *res_data, uint8_t *res_len);
uint8_t pal_set_power_restore_policy(uint8_t slot, uint8_t *pwr_policy, uint8_t *res_data);
int pal_sel_handler(uint8_t fru, uint8_t snr_num, uint8_t *event_data);
void *generate_dump(void *arg);
int pal_mon_fw_upgrade(int brd_rev, uint8_t *sys_ug, uint8_t *fan_ug, uint8_t *psu_ug, uint8_t *smb_ug);
void set_sys_led(int brd_rev);
void set_fan_led(int brd_rev);
void set_psu_led(int brd_rev);
void set_smb_led(int brd_rev);
int set_sled(int brd_rev, uint8_t color, int led_name);
void init_led(void);
int pal_light_scm_led(uint8_t led_color);
int pal_get_fru_health(uint8_t fru, uint8_t *value);
void pal_set_pim_sts_led(uint8_t fru);
int pal_set_def_key_value(void);
int pal_init_sensor_check(uint8_t fru, uint8_t snr_num, void *snr);
#ifdef __cplusplus
} // extern "C"
#endif

#endif /* __PAL_H__ */
