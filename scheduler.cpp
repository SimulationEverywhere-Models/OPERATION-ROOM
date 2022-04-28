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

/** include files **/
#include "scheduler.h"  // class Scheduler
#include "message.h"    // class ExternalMessage, InternalMessage
#include "mainsimu.h"   // MainSimulator::Instance().getParameter( ... )

/** public functions **/

/*******************************************************************
* Function Name: Scheduler
********************************************************************/
Scheduler::Scheduler( const string &name )
: Atomic( name )
, in( addInputPort( "in" ) )
, done( addInputPort( "done" ) )
, out( addOutputPort( "out" ) )
, preparationTime( 0, 0, 10, 0 )
{
	string time( MainSimulator::Instance().getParameter( description(), "preparation" ) ) ;

	if( time != "" )
		preparationTime = time ;
}

/*******************************************************************
* Function Name: initFunction
********************************************************************/
Model &Scheduler::initFunction()
{
	elements.erase( elements.begin(), elements.end() ) ;
	return *this ;
}

/*******************************************************************
* Function Name: externalFunction
********************************************************************/
Model &Scheduler::externalFunction( const ExternalMessage &msg )
{
	if( msg.port() == in )
	{
		elements.push_back( msg.value() ) ;
		if( elements.size() == 1 )
			holdIn( active, preparationTime );
	}

	if(( msg.port() == done ) && ( elements.size()>1 ))
	{
		elements.pop_front() ;
		if( !elements.empty() )
			holdIn( active, preparationTime );
	}

	return *this;
}

/*******************************************************************
* Function Name: internalFunction
********************************************************************/
Model &Scheduler::internalFunction( const InternalMessage & )
{
	passivate();
	return *this ;
}

/*******************************************************************
* Function Name: outputFunction
********************************************************************/
Model &Scheduler::outputFunction( const InternalMessage &msg )
{
	sendOutput( msg.time(), out, elements.front() ) ;
	return *this ;
}
