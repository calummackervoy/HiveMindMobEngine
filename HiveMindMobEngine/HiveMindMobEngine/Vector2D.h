#pragma once
#include "RendererConfig.h"

//Author: Calum Mackervoy
//Purpose: Wrapper class for methods to use SFML vectors

//TODO: necessary to update other classes to use this?

class Vector2D {
public:
	Vector2D(sf::Vector2f* vector);
	Vector2D(const Vector2D& copy);
	~Vector2D();

	sf::Vector2f* getVector() { return vector; };

	//functions
	float getMagnitude() const;

	//overloading operators..
	//arithmetic
	sf::Vector2f operator+(const Vector2D &b) const;
	sf::Vector2f operator-(const Vector2D &b) const;

	//multiplication/division with scalar
	sf::Vector2f operator*(const float &scalar) const;
	sf::Vector2f operator/(const float &scalar) const;

	//scalar product
	float operator*(const Vector2D &rhs) const;
	//vector product
	//sf::Vector2f operator%(const Vector2D &rhs) const;

	//auxillary for checking for zero vector
	bool isZeroVector() const;

	Vector2D& operator=(const Vector2D &rhs);
	friend bool operator==(const Vector2D &lhs, const Vector2D &rhs);
	friend bool operator!=(const Vector2D &lhs, const Vector2D &rhs);

	friend std::ostream& operator<< (std::ostream &out, const Vector2D &vec);
	//friend std::istream& operator >> (std::istream &in, Vector2D &vec);

	sf::Vector2f getUnitVector() const;
	//sf::Vector2f getOrthogonalUnitVector(const Vector2D &b) const;

protected:
	sf::Vector2f* vector;
};