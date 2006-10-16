/*******************************************************************************
* Copyright (C) 2004-2006 Intel Corp. All rights reserved.
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are met:
*
*  - Redistributions of source code must retain the above copyright notice,
*    this list of conditions and the following disclaimer.
*
*  - Redistributions in binary form must reproduce the above copyright notice,
*    this list of conditions and the following disclaimer in the documentation
*    and/or other materials provided with the distribution.
*
*  - Neither the name of Intel Corp. nor the names of its
*    contributors may be used to endorse or promote products derived from this
*    software without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ``AS IS''
* AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
* ARE DISCLAIMED. IN NO EVENT SHALL Intel Corp. OR THE CONTRIBUTORS
* BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
* CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
* SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
* INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
* CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
* ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
* POSSIBILITY OF SUCH DAMAGE.
*******************************************************************************/

/**
 * @author Anas Nashif
 */

#ifndef DEBUG_H_
#define DEBUG_H_

#include "wsman_config.h"

#include <stdarg.h>
#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */



typedef enum {
    DEBUG_LEVEL_ALWAYS   = -1,
    DEBUG_LEVEL_NONE     = 0,
    DEBUG_LEVEL_ERROR    = 1,
    DEBUG_LEVEL_CRITICAL = 2,
    DEBUG_LEVEL_WARNING  = 3,
    DEBUG_LEVEL_MESSAGE  = 4,
    DEBUG_LEVEL_INFO     = 5,
    DEBUG_LEVEL_DEBUG    = 6,
} debug_level_e;


typedef void (*debug_fn) (const char *message,
                           debug_level_e level,
                           void* user_data);
    


struct _debug_handler_t {
    debug_fn   	         fn;
    debug_level_e 	level;
    void*     		user_data;
    unsigned int	id;
};
typedef struct _debug_handler_t debug_handler_t;


unsigned int
debug_add_handler (debug_fn fn,
                      debug_level_e level,
                      void* user_data);

void debug_remove_handler (unsigned int id);

const char * debug_helper (const char *format, ...);

void
debug_full (debug_level_e  level,
               const char   *format,
               ...);


const char *
debug_helper (const char *format,
                 ...);

#define debug( format...) \
        debug_full(DEBUG_LEVEL_DEBUG, "[%d] %s:%d(%s) %s", DEBUG_LEVEL_DEBUG, __FILE__, __LINE__,__FUNCTION__, \
                debug_helper (format))
#define error( format...) \
        debug_full(DEBUG_LEVEL_ERROR, "[%d] %s:%d(%s) %s", DEBUG_LEVEL_ERROR, __FILE__, __LINE__,__FUNCTION__, \
                debug_helper (format))
#define message( format...) \
        debug_full(DEBUG_LEVEL_MESSAGE, "[%d] %s:%d(%s) %s", DEBUG_LEVEL_MESSAGE, __FILE__, __LINE__,__FUNCTION__, \
                debug_helper (format))

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /*DEBUG_H_*/