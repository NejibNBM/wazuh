/*   $OSSEC, os_regex.c, v0.4, 2006/01/02, Daniel B. Cid$   */

/* Copyright (C) 2009 Trend Micro Inc.
 * All right reserved.
 *
 * This program is a free software; you can redistribute it
 * and/or modify it under the terms of the GNU General Public
 * License (version 3) as published by the FSF - Free Software
 * Foundation
 */


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "os_regex.h"


/** int OS_Regex(char *pattern, char *str) v0.4
 *
 *  This function is a wrapper around the compile/execute
 *  functions. It should only be used when the pattern is
 *  only going to be used once.
 *  Returns 1 on success or 0 on failure.
 */
int OS_Regex(char *pattern, char *str)
{
    int r_code = 0;
    OSRegex reg;

    /* If the compilation failed, we don't need to free anything */
    if(OSRegex_Compile(pattern, &reg, 0))
    {
        if(OSRegex_Execute(str, &reg))
        {
            r_code = 1;
        }

        OSRegex_FreePattern(&reg);
    }
    
    return(r_code);
}


/* EOF */
