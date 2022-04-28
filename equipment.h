/*******************************************************************
*
*  DESCRIPTION: class Equipment 
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

#ifndef __EQUIPMENT_H
#define __EQUIPMENT_H
#include "atomic.h"  // class Atomic

class Distribution ;

class Equipment: public Atomic
{
public:
	Equipment( const string &name = "Equipment" ) ;	 

	~Equipment();					

	virtual string className() const
		{return "Equipment";}

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
};	// class Equipment


#endif   //__EQUIPMENT_H 
