#include "Vector2D.h"

Vector2D::Vector2D(sf::Vector2f* vector) {
	this->vector = vector;
}

Vector2D::Vector2D(const Vector2D& copy) {
	vector = copy.vector;
}

Vector2D::~Vector2D() {
	//vector pointer will be deleted elsewhere
}

//operator overloading
Vector2D& Vector2D::operator=(const Vector2D &rhs) {
	if (this == &rhs) return *this;

	//copy values
	this->vector = rhs.vector;

	return *this;
}

sf::Vector2f Vector2D::operator+(const Vector2D &b) const {
	//create a new vector storing result
	sf::Vector2f c = *vector + *b.vector;
	return c;
}

sf::Vector2f Vector2D::operator-(const Vector2D &b) const {
	//create a new vector storing result
	sf::Vector2f c = *vector - *b.vector;
	return c;
}

//TODO: double check you're doing the right thing here
//multiplication with scalar
sf::Vector2f Vector2D::operator*(const float &scalar) const {
	sf::Vector2f c = *vector * scalar;
	return c;
}

//TODO: double check you're doing the right thing here
//division by scalar
sf::Vector2f Vector2D::operator/(const float &scalar) const {
	//avoid division by 0
	if (scalar == 0) {
		throw std::domain_error("Division by zero undefined");
	}

	sf::Vector2f c = *vector / scalar;
	return c;
}

std::ostream& operator<< (std::ostream &out, const Vector2D &vec) {
	out << "(" << vec.vector->x << "," << vec.vector->y << ")" << std::endl;
	return out;
}

/*std::istream& operator >> (std::istream &in, Vector2D &vec) {
	//TODO: catch errors
	in >> vec.vector;

	return in;
}*/

bool operator==(const Vector2D &lhs, const Vector2D &rhs) {
	if (lhs.vector->x == rhs.vector->x && lhs.vector->y == rhs.vector->y) {
		return true;
	}
	else return false;
}

bool operator!=(const Vector2D &lhs, const Vector2D &rhs) {
	if (lhs.vector->x != rhs.vector->x && lhs.vector->y != rhs.vector->y) {
		return true;
	}
	else return false;
}

float Vector2D::getMagnitude() const {
	//magnitude of v = SQRT(x^2 + y^2)
	float sum;
	sum = (vector->x*vector->x) + (vector->y*vector->y);
	sum = sqrt(sum);
	return sum;
}

//scalar product
float Vector2D::operator*(const Vector2D &rhs) const {
	return (vector->x * rhs.vector->x) + (vector->y * rhs.vector->y);
}

//vector product
/*sf::Vector2f Vector2D::operator%(const Vector2D &rhs) const {
	//calculate each axes
	float x = (vector->x * rhs.vector->y) - (vector->y * rhs.vector->x);
	float y = (this->z * rhs.x) - (this->x * rhs.z);

	//return result constructed into a vector
	return Vector2D(x, y, z);
}*/

//auxillary function checking for zero vector
bool Vector2D::isZeroVector() const {
	if (vector->x == 0 && vector->y == 0) {
		return true;
	}
	else return false;
}

//unit vector
sf::Vector2f Vector2D::getUnitVector() const {
	//check for a zero vector
	if (this->isZeroVector()) {
		throw std::domain_error("Unit vector of zero vector undefined");
	}

	//to get unit vector you simply divide the vector by its magnitude
	sf::Vector2f c = (*this) / (this->getMagnitude());
	return c;
}

//unit vector orthogonal to two given vectors
/*sf::Vector2f Vector2D::getOrthogonalUnitVector(const Vector2D &b) const {
	//vector product produces vector orthogonal to both
	sf::Vector2f c = (*this) % b;

	//check for a zero vector
	//zero vector orthogonal to every vector, but unit vector undefined
	if (c.isZeroVector()) {
		throw std::domain_error("Unit vector of zero vector undefined");
	}


	//return the unit vector form of result
	return c.getUnitVector();
}*/