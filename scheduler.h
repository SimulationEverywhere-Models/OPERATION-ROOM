/*******************************************************************
*
*  DESCRIPTION: Atomic Model Scheduler
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

#ifndef __SCHEDULER_H
#define __SCHEDULER_H

#include <list>
#include "atomic.h"     // class Atomic

class Scheduler : public Atomic
{
public:
	Scheduler( const string &name = "Scheduler" );	//Default constructor

	virtual string className() const ;
protected:
	Model &initFunction();
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );

private:
	const Port &in;
	const Port &done;
	Port &out;
	Time preparationTime;
	typedef list<Value> ElementList ;
	ElementList elements ;

	Time timeLeft;

};	// class Scheduler

// ** inline ** // 
inline
string Scheduler::className() const
{
	return "Scheduler" ;
}

#endif   //__SCHEDULER_H
