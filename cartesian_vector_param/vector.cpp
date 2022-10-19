#include "vector.hh"

Vector::Vector()
{
    x = 0;
    y = 0;
    z = 0;
}

Vector::Vector(std::initializer_list<int> list)
{
    x = data(list)[0];
    y = data(list)[1];
    z = data(list)[2];
}

int Vector::operator*(const Vector &argum)
{

    if (NDIM == 2)
    {
        return x * argum.x + y * argum.y + 0;
    }
    return x * argum.x + y * argum.y + z * argum.z;
}
int &Vector::operator[](size_t index)
{
    if (index >= NDIM)
        throw std::invalid_argument("Invalide Dimension");
    switch (index)
    {
    case 0:
        return x;
    case 1:
        return y;
    default:
        return z;
    }
}

Vector &Vector::operator+=(const int &argum)
{
    x += argum;
    y += argum;

    if (NDIM == 3)
        z += argum;

    return *this;
}

Vector &Vector::operator+=(const Vector &argum)
{
    x += argum.x;
    y += argum.y;

    if (NDIM == 3)
        z += argum.z;

    return *this;
}

Vector &Vector::operator*=(const int &argum)
{
    y *= argum;
    x *= argum;

    if (NDIM == 3)
        z *= argum;

    return *this;
}

Vector &Vector::operator-=(const Vector &argum)
{
    x -= argum.x;
    y -= argum.y;

    if (NDIM == 3)
        z -= argum.z;

    return *this;
}

Vector Vector::operator+(const Vector &argum)
{

    if (NDIM == 3)
        return Vector({this->x + argum.x, this->y + argum.y, this->z + argum.z});
    else
        return Vector({this->x + argum.x, this->y + argum.y});
}

Vector Vector::operator*(const int &argum)
{
    if (NDIM == 3)
    {
        return Vector({this->x * argum, this->y * argum, this->z * argum});
    }
    return Vector({this->x * argum, this->y * argum});
}

int Vector::get_x()
{
    return x;
}

int Vector::get_y()
{
    return y;
}

int Vector::get_z()
{
    return z;
}
