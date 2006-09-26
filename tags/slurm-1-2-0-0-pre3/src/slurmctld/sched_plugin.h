/*****************************************************************************\
 *  sched_plugin.h - Define scheduler plugin functions.
 *****************************************************************************
 *  Copyright (C) 2004-2006 The Regents of the University of California.
 *  Produced at Lawrence Livermore National Laboratory (cf, DISCLAIMER).
 *  Written by Jay Windley <jwindley@lnxi.com>
 *  UCRL-CODE-217948.
 *  
 *  This file is part of SLURM, a resource management program.
 *  For details, see <http://www.llnl.gov/linux/slurm/>.
 *  
 *  SLURM is free software; you can redistribute it and/or modify it under
 *  the terms of the GNU General Public License as published by the Free
 *  Software Foundation; either version 2 of the License, or (at your option)
 *  any later version.
 *
 *  In addition, as a special exception, the copyright holders give permission 
 *  to link the code of portions of this program with the OpenSSL library under 
 *  certain conditions as described in each individual source file, and 
 *  distribute linked combinations including the two. You must obey the GNU 
 *  General Public License in all respects for all of the code used other than 
 *  OpenSSL. If you modify file(s) with this exception, you may extend this 
 *  exception to your version of the file(s), but you are not obligated to do 
 *  so. If you do not wish to do so, delete this exception statement from your
 *  version.  If you delete this exception statement from all source files in 
 *  the program, then also delete it here.
 *  
 *  SLURM is distributed in the hope that it will be useful, but WITHOUT ANY
 *  WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 *  FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
 *  details.
 *  
 *  You should have received a copy of the GNU General Public License along
 *  with SLURM; if not, write to the Free Software Foundation, Inc.,
 *  51 Franklin Street, Fifth Floor, Boston, MA 02110-1301  USA.
\*****************************************************************************/

#ifndef __SLURM_CONTROLLER_SCHED_PLUGIN_API_H__
#define __SLURM_CONTROLLER_SCHED_PLUGIN_API_H__

#include <slurm/slurm.h>

/*
 * Initialize the external scheduler adapter.
 *
 * Returns a SLURM errno.
 */
int slurm_sched_init( void );

/*
 * Terminate external scheduler, free memory.
 * 
 * Returns a SLURM errno.
 */
extern int slurm_sched_fini(void);

/*
 **************************************************************************
 *                          P L U G I N   C A L L S                       *
 **************************************************************************
 */

/*
 * For passive schedulers, invoke a scheduling pass.
 */
int slurm_sched_schedule( void );

/*
 * Supply the initial SLURM priority for a newly-submitted job.
 */
uint32_t slurm_sched_initial_priority( uint32_t max_prio );

/*
 * Note that some job is pending.
 */
void slurm_sched_job_is_pending( void );

/* 
 * Return any plugin-specific error number
 */
int slurm_sched_p_get_errno( void );

/*
 * Return any plugin-specific error description
 */
char *slurm_sched_p_strerror( int errnum );

#endif /*__SLURM_CONTROLLER_SCHED_PLUGIN_API_H__*/
