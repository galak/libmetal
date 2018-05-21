/*
 * Copyright (c) 2015, Xilinx Inc. and Contributors. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*
 * @file	log.h
 * @brief	Logging support for libmetal.
 */

#ifndef __METAL_METAL_LOG__H__
#define __METAL_METAL_LOG__H__

#ifdef __cplusplus
extern "C" {
#endif

/** \defgroup logging Library Logging Interfaces
 *  @{ */

/** Log message priority levels for libmetal. */
enum metal_log_level {
	METAL_LOG_EMERGENCY = 1,/**< system is unusable.               */
	METAL_LOG_ALERT,	/**< action must be taken immediately. */
	METAL_LOG_CRITICAL,	/**< critical conditions.              */
	METAL_LOG_ERROR,	/**< error conditions.                 */
	METAL_LOG_WARNING,	/**< warning conditions.               */
	METAL_LOG_NOTICE,	/**< normal but significant condition. */
	METAL_LOG_INFO,		/**< informational messages.           */
	METAL_LOG_DEBUG,	/**< debug-level messages.             */
};

#include <metal/system/@PROJECT_SYSTEM@/log.h>

#if (METAL_LOG_LEVEL > 0)

/**
 * @brief	Default libmetal log handler.  This handler prints libmetal log
 *		mesages to stderr.
 * @param[in]	level	log message level.
 * @param[in]	format	log message format string.
 * @return	0 on success, or -errno on failure.
 */
extern void metal_default_log_handler(enum metal_log_level level,
				      const char *format, ...);

/**
 * Emit a log message if the log level permits.
 *
 * @param	level	Log level.
 * @param	...	Format string and arguments.
 */
#ifndef metal_log_handler
#define metal_log_handler metal_default_log_handler
#endif

#define metal_log(level, ...)						       \
	((level <= METAL_LOG_LEVEL) \
	       ? (void)metal_log_handler(level, __VA_ARGS__)	       \
	       : (void)0)
#else

#define metal_log(level, ...)

#endif

/** @} */
#ifdef __cplusplus
}
#endif

#endif /* __METAL_METAL_LOG__H__ */
