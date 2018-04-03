/*
 * Copyright (c) 2016, Xilinx Inc. and Contributors. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*
 * @file	linux/irq.h
 * @brief	Linux libmetal irq definitions.
 */

#ifndef __METAL_IRQ__H__
#error "Include metal/irq.h instead of metal/linux/irq.h"
#endif

#ifndef __METAL_LINUX_IRQ__H__
#define __METAL_LINUX_IRQ__H__

#ifdef HAS_METAL_IRQ_HANDLER
extern int metal_linux_irq_init(void);
extern void metal_linux_irq_shutdown(void);
#else
static inline int metal_linux_irq_init(void)
{
	return 0;
}

static inline void metal_linux_irq_shutdown(void)
{

}
#endif

#endif /* __METAL_LINUX_IRQ__H__ */
