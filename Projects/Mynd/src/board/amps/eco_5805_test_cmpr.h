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
	{ CFG_META_SWITCH, 5 }
	{ CFG_META_DELAY, 5 }
	{ 0x24, 0x00 }
	{ 0x80, 0x00 }
	{ 0x00, 0x00 }
	{ 0x28, 0x00 }
	{ 0x29, 0x00 }
	{ 0x2a, 0x00 }
	{ 0x2b, 0x00 }
};

#define TAS5805M_CHANNEL_LEFT_REGISTERS_SIZE (sizeof(tas5805m_channel_left_config) / sizeof(tas5805m_channel_left_config[0]))