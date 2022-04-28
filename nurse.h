/*******************************************************************
*
*  DESCRIPTION: class Nurse 
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

#ifndef __NURSE_H
#define __NURSE_H
#include "atomic.h"  // class Atomic

class Distribution ;

class Nurse: public Atomic
{
public:
	Nurse( const string &name = "Nurse" ) ;	 

	~Nurse();				

	virtual string className() const
		{return "Nurse";}

protected:
	Model &initFunction()
		{return *this;}

	Model &externalFunction( const ExternalMessage & );

	Model &internalFunction( const InternalMessage & );

	Model &outputFunction( const InternalMessage & );

private:
	const Port &in ;
	Port &out ;
	Distribution *dist ;
	int pid ;

	Distribution &distribution()
			{return *dist;}
};	// class Nurse


#endif   //__NURSE_H 
