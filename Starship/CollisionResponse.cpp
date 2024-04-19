#include "CollisionResponse.h"

CollisionResponse::CollisionResponse()
{
	// Initialize all the variables I created

	J = 0.0f;

	initialShip = glm::vec3(0.0f, 0.0f, 0.0f);
	initialAsteroid = glm::vec3(20000.0f, 10000.0f, 20000.0f);

	asteroidMass = 1.0f;
	restitution = 0.5f;
	shipMass = 100.0f;

	iAsteroid = glm::mat3(0.1f, 0.0f, 0.0f, 0.0f, 0.1f, 0.0f, 0.0f, 0.0f, 0.1f);
	iShip = glm::mat3(20.0f, 0.0f, 0.0f, 0.0f, 40.0f, 0.0f, 0.0f, 0.0f, 20.0f);

	unitNormal = glm::vec3((2.0f / 3.0f), (1.0f / 3.0f), (2.0f / 3.0f));

	shipCenterOfMassPositionAtCollision = glm::vec3(0.0f, 0.0f, 0.0f);
	asteroidCenterOfMassPositionAtCollision = glm::vec3(-10.0f, 2.0f, 0.0f);

	pointOfCollision = glm::vec3(-8.0f, 1.0f, 0.0f);

	rShip = pointOfCollision - shipCenterOfMassPositionAtCollision;
	rAsteroid = pointOfCollision - asteroidCenterOfMassPositionAtCollision;

	std::cout << "Vector of astroid (" << initialAsteroid.x << ", " << initialAsteroid.y << ", " 
		<< initialAsteroid.z << ")" << std::endl;

	std::cout << "Vector of ship (" << initialShip.x << ", " << initialShip.y << ", " << initialShip.z << ")" << std::endl;

	std::cout << "Restitution = " << restitution << std::endl;

	std::cout << "Asteroid mass = " << asteroidMass << std::endl;
	std::cout << "Ship mass = " << shipMass << std::endl << "\n";

	std::cout << "Ship matrix \t" << iShip[0][0] << "\t" << iShip[0][1] << "\t" << iShip[0][2] << "\t" << std::endl;
	std::cout << "\t\t" << iShip[1][0] << "\t" << iShip[1][1] << "\t" << iShip[1][2] << "\t" << std::endl;
	std::cout << "\t\t" << iShip[2][0] << "\t" << iShip[2][1] << "\t" << iShip[2][2] << "\t" << std::endl << "\n";

	std::cout << "Asteroid matrix \t" << iAsteroid[0][0] << "\t" << iAsteroid[0][1] << "\t" << iAsteroid[0][2] << "\t" 
		<< std::endl;
	std::cout << "\t\t\t" << iAsteroid[1][0] << "\t" << iAsteroid[1][1] << "\t" << iAsteroid[1][2] << "\t" << std::endl;
	std::cout << "\t\t\t" << iAsteroid[2][0] << "\t" << iAsteroid[2][1] << "\t" << iAsteroid[2][2] << "\t" << std::endl << "\n";

	std::cout << "Unit normal vector (" << unitNormal.x << ", " << unitNormal.y << ", " << unitNormal.z << ")" << std::endl;

	std::cout << "Ship's centre of mass position at collision (" << shipCenterOfMassPositionAtCollision.x << ", " 
		<< shipCenterOfMassPositionAtCollision.y << ", " << shipCenterOfMassPositionAtCollision.z << ")" << std::endl;

	std::cout << "Asteroid's centre of mass position at collision (" << asteroidCenterOfMassPositionAtCollision.x << ", "
		<< asteroidCenterOfMassPositionAtCollision.y << ", " << asteroidCenterOfMassPositionAtCollision.z << ")" << std::endl;

	std::cout << "Point at collision (" << pointOfCollision.x << ", " << pointOfCollision.y << ", " 
		<< pointOfCollision.z << ")" << std::endl;

	std::cout << "R ship (" << rShip.x << ", " << rShip.y << ", " << rShip.z << ")" << std::endl;
	std::cout << "R asteroid (" << rAsteroid.x << ", " << rAsteroid.y << ", " << rAsteroid.z << ")" << std::endl << "\n";
}

CollisionResponse::~CollisionResponse()
{
	// Nothing to see here
}

void CollisionResponse::InverseMatrixOfShip()
{
	// Determinant |A| = a(ei - fh) - b(di - fg) + c(dh - eg)

	std::cout << "The determinant of the ship is = " << glm::determinant(iShip) << std::endl;

	glm::mat3 transposeShip = glm::transpose(iShip);

	std::cout << "Transpose Ship Matrix \t\t" << transposeShip[0][0] << "\t" << transposeShip[0][1] << "\t"
		<< transposeShip[0][2] << std::endl;
	std::cout << "\t\t\t\t" << transposeShip[1][0] << "\t" << transposeShip[1][1] << "\t"
		<< transposeShip[1][2] << std::endl;
	std::cout << "\t\t\t\t" << transposeShip[2][0] << "\t" << transposeShip[2][1] << "\t"
		<< transposeShip[2][2] << std::endl << "\n";

	glm::mat3 inverseShip = glm::inverse(iShip);

	// Inverse = (1 / determinant) * adjugateMatrix
	std::cout << "Inverse Ship Matrix \t\t" << inverseShip[0][0] << "\t" << inverseShip[0][1] << "\t"
		<< inverseShip[0][2] << std::endl;
	std::cout << "\t\t\t\t" << inverseShip[1][0] << "\t" << inverseShip[1][1] << "\t"
		<< inverseShip[1][2] << std::endl;
	std::cout << "\t\t\t\t" << inverseShip[2][0] << "\t" << inverseShip[2][1] << "\t"
		<< inverseShip[2][2] << std::endl << "\n";
}

void CollisionResponse::InverseMatrixOfAsteroid()
{
	// Determinant |A| = a(ei - fh) - b(di - fg) + c(dh - eg)

	std::cout << "The determinant of the asteroid is = " << glm::determinant(iAsteroid) << std::endl;

	glm::mat3 transposeAsteroid = glm::transpose(iAsteroid);

	std::cout << "Transpose Asteroid Matrix \t" << transposeAsteroid[0][0] << "\t" << transposeAsteroid[0][1] << "\t"
		<< transposeAsteroid[0][2] << std::endl;
	std::cout << "\t\t\t\t" << transposeAsteroid[1][0] << "\t" << transposeAsteroid[1][1] << "\t"
		<< transposeAsteroid[1][2] << std::endl;
	std::cout << "\t\t\t\t" << transposeAsteroid[2][0] << "\t" << transposeAsteroid[2][1] << "\t"
		<< transposeAsteroid[2][2] << std::endl << "\n";

	glm::mat3 inverseAsteroid = glm::inverse(iAsteroid);

	// Inverse = (1 / determinant) * adjugateMatrix
	std::cout << "Inverse Asteroid Matrix \t" << inverseAsteroid[0][0] << "\t" << inverseAsteroid[0][1] << "\t"
		<< inverseAsteroid[0][2] << std::endl;
	std::cout << "\t\t\t\t" << inverseAsteroid[1][0] << "\t" << inverseAsteroid[1][1] << "\t"
		<< inverseAsteroid[1][2] << std::endl;
	std::cout << "\t\t\t\t" << inverseAsteroid[2][0] << "\t" << inverseAsteroid[2][1] << "\t"
		<< inverseAsteroid[2][2] << std::endl << "\n";
}

void CollisionResponse::Jcalculation()
{
	/* vr = n * (v1i - v2i)
	Linear impulse J = -vr (r + 1) /(1 / m1 + 1 / m2 + n * (l1 ^ (-1) (r1 * n) * r1) + n * (l2 ^ (-1) (r2 × n) * r2)) */

	// Finds the difference between the 2 velocities
	glm::vec3 velDifference = initialShip - initialAsteroid;

	// 4 float variables to calculate J
	float a = -glm::dot(unitNormal, velDifference) * (restitution + 1.0f);

	float b = (1.0f / asteroidMass) + (1.0f / shipMass);

	float c = glm::dot(unitNormal * glm::inverse(iShip) * (rShip * unitNormal) * rShip, 
		glm::vec3(0.90448331f, 0.90448331f, 0.90448331f));

	float d = glm::dot(unitNormal * glm::inverse(iAsteroid) * (rAsteroid * unitNormal) * rAsteroid, 
		glm::vec3(2.11764701f, 2.11764701f, 2.11764701f));
	
	J = (a) / (b + c + d); // Find the linear impluse

	std::cout << "J = " << std::setprecision(4) << J << std::endl; // std::setprecision rounds up J to a whole number

}

void CollisionResponse::linearVelOfShip()
{
	// vf_1 = vi_1 + (J * n) / m1

	glm::vec3 linearShipVel = initialShip + (J * unitNormal) / shipMass; // Create a local variable for final velocity of ship

	std::cout << "Final velocity of ship = (" << std::setprecision(3) << linearShipVel.x << ", " << linearShipVel.y << ", "
		<< linearShipVel.z << ")" << std::endl; // Print to the console the final velocity vector of the ship
}

void CollisionResponse::angularVelOfShip()
{
	// wf_1 = wi_1 + I_1 ^(-1) (r_1 * J * n)

	// Include a local variable for the initial angular ship
	glm::vec3 initialAngularShip = glm::vec3(319.2f, 133.11f, -177.0f);

	// Create a local variable for final angular velocity of ship
	glm::vec3 angularShipVel = initialAngularShip + glm::inverse(iShip) * (rShip * J * unitNormal);

	std::cout << "Final angular velocity of ship = (" << std::setprecision(3) << angularShipVel.x << ", " << angularShipVel.y 
		<< ", " << angularShipVel.z << ")" << std::endl; // Print to the console the final angular velocity vector of ship
}