/*******************************************************************
*
*  DESCRIPTION: Atomic Model Nurse (use a distribution)
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

/** include files **/
#include <math.h>          // fabs( ... )
#include "nurse.h"         // base header
#include "message.h"       // InternalMessage ....
#include "distri.h"        // class Distribution
#include "mainsimu.h"      // class MainSimulator
#include "strutil.h"       // str2float( ... )

/*******************************************************************
* Function Name: Nurse
* Description: constructor
********************************************************************/
Nurse::Nurse( const string &name )
: Atomic( name )
, in( addInputPort( "in" ) )
, out( addOutputPort( "out" ) )
{
	try
	{
		dist = Distribution::create( MainSimulator::Instance().getParameter( description(), "distribution" ) );

		MASSERT( dist );

		for ( register int i = 0 ; i < dist->varCount() ; i++ )
		{
			string parameter( MainSimulator::Instance().getParameter( description(), dist->getVar(i) ) ) ;
			dist->setVar( i, str2float( parameter ) ) ;
		}
	} catch( InvalidDistribution &e )
	{
		e.addText( "The model " + description() + " has distribution problems!" ) ;
		e.print(cerr);
		MTHROW( e ) ;
	} catch( MException &e )
	{
		MTHROW( e ) ;
	}
}

/*******************************************************************
* Function Name: externalFunction
* Description: the Nurse receives one job
********************************************************************/
Model &Nurse::externalFunction( const ExternalMessage &msg )
{
	pid = (int)msg.value();
	holdIn( active, Time( static_cast<float>( fabs( distribution().get() ) ) ) ) ;
	return *this ;
}

/*******************************************************************
* Function Name: internalFunction
********************************************************************/
Model &Nurse::internalFunction( const InternalMessage & )
{
	passivate();
	return *this;
}

/*******************************************************************
* Function Name: outputFunction
********************************************************************/
Model &Nurse::outputFunction( const InternalMessage &msg )
{
	sendOutput( msg.time(), out, pid );
	return *this;
}

Nurse::~Nurse()
{
	delete dist;
}
