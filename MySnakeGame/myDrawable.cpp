#include "myDrawable.hpp"

Vector2f myDrawable::getLocation()
{
    return m_location;
}

void myDrawable::setLocation(const Vector2f& konum)
{
    m_location = konum;
    
}
