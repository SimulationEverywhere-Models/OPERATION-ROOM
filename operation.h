/*******************************************************************
*
*  DESCRIPTION: class Operation 
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

#ifndef __OPERATION_H
#define __OPERATION_H
#include "atomic.h"  // class Atomic

class Distribution ;

class Operation: public Atomic
{
public:
	Operation( const string &name = "Operation" ) ;	 

	~Operation();					

	virtual string className() const
		{return "Operation";}

protected:
	Model &initFunction()
		{return *this;}

	Model &externalFunction( const ExternalMessage & );

	Model &internalFunction( const InternalMessage & );

	Model &outputFunction( const InternalMessage & );

private:
	const Port &in ;
	Port &out ;
	Port &done ;
	Distribution *dist ;
	int pid ;

	Distribution &distribution()
			{return *dist;}
};	// class Operation


#endif   //__OPERATION_H 
