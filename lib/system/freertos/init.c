/*
 * Copyright (c) 2016, Xilinx Inc. and Contributors. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*
 * @file	freertos/init.c
 * @brief	FreeRTOS libmetal initialization.
 */

#include <metal/sys.h>
#include <metal/utilities.h>
#include <metal/device.h>
#include <metal/irq.h>

struct metal_state _metal;

int metal_sys_init(const struct metal_init_params *params)
{
	metal_unused(params);
	metal_bus_register(&metal_generic_bus);
	return metal_irq_init();
}

void metal_sys_finish(void)
{
	metal_irq_deinit();
	metal_bus_unregister(&metal_generic_bus);
}
