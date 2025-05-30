/* 
 *  pslash - a lightweight framebuffer splashscreen for embedded devices. 
 *
 *  Copyright (c) 2006 Matthew Allum <mallum@o-hand.com>
 *
 *  SPDX-License-Identifier: GPL-2.0-or-later
 *
 */

#ifndef _HAVE_PSPLASH_H
#define _HAVE_PSPLASH_H

#define _GNU_SOURCE 1
#include <assert.h>
#include <errno.h>
#include <fcntl.h>
#include <limits.h>
#include <linux/fb.h>
#include <linux/kd.h>
#include <linux/vt.h>
#include <signal.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#if defined(__i386__) || defined(__alpha__)
#include <sys/io.h>
#endif
#include <sys/ioctl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/types.h>
#include <termios.h>
#include <unistd.h>

typedef uint8_t  uint8;
typedef uint16_t uint16;

#if defined __STDC__ && defined __STDC_VERSION__ && __STDC_VERSION__ <= 201710L
typedef int            bool;
#endif

#ifndef FALSE
#define FALSE 0
#endif

#ifndef TRUE
#define TRUE 1
#endif

#define PSPLASH_FIFO "psplash_fifo"

#define CLAMP(x, low, high) \
   (((x) > (high)) ? (high) : (((x) < (low)) ? (low) : (x)))

#define DEBUG 0

#if DEBUG
#define DBG(x, a...) \
   { printf ( __FILE__ ":%d,%s() " x "\n", __LINE__, __func__, ##a); }
#else
#define DBG(x, a...) do {} while (0)
#endif

#ifdef __GNUC__
#  define UNUSED(x) UNUSED_ ## x __attribute__((__unused__))
#else
#  define UNUSED(x) UNUSED_ ## x
#endif

typedef struct PSplashFont
{
    char *name;				/* Font name. */
    int   height;			/* Height in pixels. */
    int   index_mask;			/* ((1 << N) - 1). */
    int  *offset;			/* (1 << N) offsets into index. */
    int  *index;
    u_int32_t *content;
}
PSplashFont;


#include "psplash-fb.h"
#include "psplash-console.h"

#endif
