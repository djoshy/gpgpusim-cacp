/*********************************************************
 ****  Code for Criticality Aware Warp Scheduler      ****
 ****  Contributed by Ujan Sengupta                   ****
 ****  Also made change to:                           ****
 ****     shader.cc                                   ****
 ****     shader.h                                    ****
 ****  04/20/16                              	      ****
 *********************************************************/
 
#include "shader.h"
 
//***************** class shader.h *********************/
 
void cawa_scheduler::order_warps()
{
    order_by_priority( m_next_cycle_prioritized_warps,
                       m_supervised_warps,
                       m_last_supervised_issued,
                       m_supervised_warps.size(),
                       ORDERED_PRIORITY_FUNC_ONLY,
                       scheduler_unit::sort_warps_by_criticality );
}

bool scheduler_unit::sort_warps_by_criticality(shd_warp_t* lhs, shd_warp_t* rhs)
{
    if (rhs && lhs) 
    {
        if ( lhs->done_exit() || lhs->waiting() ) 
        {
            return false;
        } 
        else if ( rhs->done_exit() || rhs->waiting() ) 
        {
            return true;
        } 
        else 
        {
            if (lhs->tw_get_CPL() == rhs->tw_get_CPL())
            {	
            	return lhs->get_dynamic_warp_id() < rhs->get_dynamic_warp_id();
            }
            else
            {
            	return lhs->tw_get_CPL() > rhs->tw_get_CPL();
            }
        }
    } 
    else 
    {
        return lhs < rhs;
    }
}


scheduler_unit::scheduler_unit()
{
    count = 0;
    flag = 0;
}
