#pragma once
#include "tas5825p.h"

// Set input crossbar to only left channel
const tas5825p_cfg_reg_t tas5825p_channel_left_config[] = {
	{ 0x00, 0x00 },
	{ 0x7f, 0x8c },
	{ 0x00, 0x0b },
	{ 0x14, 0x00 },
	{ 0x15, 0x80 },
	{ 0x16, 0x00 },
	{ CFG_META_SWITCH, 5 },
};

// Set input crossbar to only right channel
const tas5825p_cfg_reg_t tas5825p_channel_right_config[] = {
	{ 0x00, 0x00 },
	{ 0x7f, 0x8c },
	{ 0x00, 0x0b },
	{ 0x14, 0x00 },
	{ CFG_META_SWITCH, 5 },
	{ 0x1a, 0x00 },
	{ 0x1b, 0x00 },
};

// Set input crossbar to sum both channels *_0.5
const tas5825p_cfg_reg_t tas5825p_channel_stereo_config[] = {
	{ 0x00, 0x00 },
	{ 0x7f, 0x8c },
	{ 0x00, 0x0b },
	{ CFG_META_BURST, 9 },
	{ 0x14, 0x00 },
	{ 0x40, 0x00 },
	{ 0x00, 0x00 },
	{ 0x40, 0x00 },
	{ 0x00, 0x00 },
};

#define TAS5825P_CHANNEL_LEFT_REGISTERS_SIZE (sizeof(tas5825p_channel_left_config) / sizeof(tas5825p_channel_left_config[0]))
#define TAS5825P_CHANNEL_RIGHT_REGISTERS_SIZE (sizeof(tas5825p_channel_right_config) / sizeof(tas5825p_channel_right_config[0]))
#define TAS5825P_CHANNEL_STEREO_REGISTERS_SIZE (sizeof(tas5825p_channel_stereo_config) / sizeof(tas5825p_channel_stereo_config[0]))