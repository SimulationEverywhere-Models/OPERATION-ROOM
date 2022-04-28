/*******************************************************************
*
*  DESCRIPTION: class DOCTOR
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

#ifndef __DOCTOR_H
#define __DOCTOR_H
#include "atomic.h"  

class Distribution ;

class DOCTOR: public Atomic
{
public:
	DOCTOR( const string &name = "DOCTOR" ) ;	

	~DOCTOR();					

	virtual string className() const
		{return "DOCTOR";}

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
};	// class DOCTOR


#endif   //__DOCTOR_H 
