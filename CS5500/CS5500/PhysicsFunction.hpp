/*
Initial Author: Austin Finlinson
Creation Date: 1/20/2015
Last Edit: 1/20/2015
Contents: The PhysicsFunction abstract strategy that actually performs a physics operation
*/

#ifndef PHYSICSFUNCTION
#define PHYSICSFUNCTION

//Assumes that all physics functions are evaluated based on region data and coordinates
  //perhaps that should only be a specialization of a more general simulation function that can run
  //on presumably any or no data.
class PhysicsFunction 
{
    //Changes are applied to NextWorld, data gotten from CurrentWorld?
	// = 0 makes it Pure Virtual, meaning it has to be implemented
	//Possibly make it so the changes array is returned instead of using a reference for result.
  //virtual void ApplyTo(World current, World& result, Coordinate start_pos, Coordinate end_pos) = 0;
  
  //Function Name/ID.  So you can find out what this is.  Maybe an Enum?
};

#endif