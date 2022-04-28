/*******************************************************************
*
*  DESCRIPTION: Simulator::registerNewAtomics()
*
*  AUTHOR: Rujun Hu
*
*  STUDENT#: 258902
*
*  EMAIL: rujun_hu@yahoo.ca
*
*  DATE: 16/10/2001
*
*******************************************************************/

#include "modeladm.h" 
#include "mainsimu.h"
#include "scheduler.h"      // class Scheduler
#include "nurse.h"        // class Nurse
#include "equipment.h"        // class Equipment
#include "doctor.h"        // class Doctor
#include "operation.h"        // class Operation


void MainSimulator::registerNewAtomics()
{
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Scheduler>() , "Scheduler" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<DOCTOR>() , "DOCTOR" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Nurse>(), "Nurse" ) ;  
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Equipment>(), "Equipment" ) ;  
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Operation>(), "Operation" ) ;  } 

