#include "glm/glm.hpp" // Need this for creating physics vectors
#include <iostream> // Need this to print to the console
#include <glm/gtx/string_cast.hpp> // I used this to convert a matrix into a string (with glm::to_string) just in case
#include <iomanip> // Need this to round to a number of decimal places (with std::setprecision(int))

class CollisionResponse
{
public:
	CollisionResponse(); // Initialize all the variables I created
	~CollisionResponse(); // Destructor with no code inside it

	void InverseMatrixOfShip(); // Finds the inverse matrix of the ship as a float array
	void InverseMatrixOfAsteroid(); // Finds the inverse matrix of the asteroid as a float array

	void Jcalculation(); // Calculates the linear impluse
	void linearVelOfShip(); // Calculates the final velocity vector of the ship
	void angularVelOfShip(); // Calculates the final angular velocity of the ship

private:
	// Float variables needed for the calculations
	float asteroidMass, restitution, shipMass, J;

	// R variable for both ship and asteroid
	glm::vec3 rShip, rAsteroid;

	// Stores the matricies of the ship and asteroid
	glm::mat3 iShip, iAsteroid;

	// Vec3 variables to initialize ship and asteroid vectors and to use them in calculations
	glm::vec3 initialShip, initialAsteroid;

	// Vec3 variables needed for intialization and calculation
	glm::vec3 unitNormal, shipCenterOfMassPositionAtCollision, asteroidCenterOfMassPositionAtCollision, pointOfCollision;
};

