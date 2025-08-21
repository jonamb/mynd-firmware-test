#pragma once
#include "tas5805m.h"

// From 2024-07-26

// TAS5805M Set to left only mode
const tas5805m_cfg_reg_t tas5805m_channel_left_config[] = {
    { 0x00, 0x00 },     // Page 0
    { 0x7f, 0x8C },     // Book 0x8C
    { 0x00, 0x2C },     // Page 0x2A
    { CFG_META_BURST, 5 }, // Left channel to left output
    { 0x1C, 0x00 },
    { 0x80, 0x00 },
    { 0x00, 0x00 },
    { CFG_META_BURST, 5 }, // Right channel to left output
    { 0x20, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
    { CFG_META_DELAY, 5 }, // Left channel to right output
    { 0x24, 0x00 },
    { 0x80, 0x00 },
    { 0x00, 0x00 },
    { CFG_META_BURST, 5 }, // Right channel to right output
    { 0x28, 0x00 },
    { 0x00, 0x00 },
    { 0x00, 0x00 },
};

#define TAS5805M_CHANNEL_LEFT_REGISTERS_SIZE (sizeof(tas5805m_channel_left_config) / sizeof(tas5805m_channel_left_config[0]))
