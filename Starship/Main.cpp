#include <iostream> // I originally included this inside of Main.cpp but it's redundant since I have the CollisionReponse class
#include "CollisionResponse.h" // Included for creating the class variable and using them

// The only things to include in Main.cpp are my collision response functions to show they work properly in the console
int main()
{
	// Add a pointer to the Collision Reponse class variable to use them in Main.cpp
	CollisionResponse* collider = new CollisionResponse();

	// Include the inverse of both the ship and asteroid matricies
	collider->InverseMatrixOfShip();
	collider->InverseMatrixOfAsteroid();

	// Prints to the console of the J and velocity vector calculations
	collider->Jcalculation();
	collider->linearVelOfShip();
	collider->angularVelOfShip();

	return 0; // Returns 0 but this is redundant
}