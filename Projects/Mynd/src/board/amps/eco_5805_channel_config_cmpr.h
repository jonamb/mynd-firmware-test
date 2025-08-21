#pragma once
#include "tas5805m.h"

// From 2024-07-26

// TAS5805M Set to left only mode
const tas5805m_cfg_reg_t tas5805m_channel_left_config[] = {
	{ 0x00, 0x00 }
	{ 0x7f, 0x8c }
	{ 0x00, 0x2c }
	{ 0x1c, 0x00 }
	{ 0x1d, 0x80 }
	{ 0x1e, 0x00 }
	{ CFG_META_SWITCH, 7 }
	{ 0x26, 0x00 }
	{ CFG_META_SWITCH, 5 }
};

// TAS5805M Set to right only mode
const tas5805m_cfg_reg_t tas5805m_channel_right_config[] = {
	{ 0x00, 0x00 }
	{ 0x7f, 0x8c }
	{ 0x00, 0x2c }
	{ 0x1c, 0x00 }
	{ 0x1d, 0x80 }
	{ 0x1e, 0x00 }
	{ CFG_META_SWITCH, 7 }
	{ 0x26, 0x00 }
	{ CFG_META_SWITCH, 5 }
};

// TAS5805M Set to normal stereo mode
const tas5805m_cfg_reg_t tas5805m_channel_stereo_config[] = {
	{ 0x00, 0x00 }
	{ 0x7f, 0x8c }
	{ 0x00, 0x2c }
	{ 0x1c, 0x00 }
	{ 0x1d, 0x80 }
	{ 0x1e, 0x00 }
	{ CFG_META_SWITCH, 7 }
	{ 0x26, 0x00 }
	{ CFG_META_SWITCH, 5 }
};

#define TAS5805M_CHANNEL_LEFT_REGISTERS_SIZE (sizeof(tas5805m_channel_left_config) / sizeof(tas5805m_channel_left_config[0]))
#define TAS5805M_CHANNEL_RIGHT_REGISTERS_SIZE (sizeof(tas5805m_channel_right_config) / sizeof(tas5805m_channel_right_config[0]))
#define TAS5805M_CHANNEL_STEREO_REGISTERS_SIZE (sizeof(tas5805m_channel_stereo_config) / sizeof(tas5805m_channel_stereo_config[0]))