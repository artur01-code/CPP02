#include "Fixed.hpp"
#include "Point.hpp"

typedef struct s_vec
{
    Fixed    x;
    Fixed    y;
}    t_vec;

Fixed    ft_dot(t_vec a, t_vec b)
{
    Fixed    out;

    out = (a.x * b.x) + (a.y * b.y);
    return (out);
}

bool bsp( const Point &a, const Point &b, const Point& c, const Point& point)
{
	t_vec    v0;
	t_vec    v1;
	t_vec    v2;
	// Compute vectors   

	v0.x = c.getX() - a.getX();
	v0.y = c.getY() - a.getY();

	v1.x = b.getX() - a.getX();
	v1.y = b.getY() - a.getY();

	v2.x = point.getX() - a.getX();
	v2.y = point.getY() - a.getY();


	// Compute dot products
	Fixed dot00 = ft_dot(v0, v0);
	Fixed dot01 = ft_dot(v0, v1);
	Fixed dot02 = ft_dot(v0, v2);
	Fixed dot11 = ft_dot(v1, v1);
	Fixed dot12 = ft_dot(v1, v2);

	// Compute barycentric coordinates
	Fixed    invDenom((Fixed) 1 / (dot00 * dot11 - dot01 * dot01));
	Fixed    u = (dot11 * dot02 - dot01 * dot12) * invDenom;
	Fixed    v = (dot00 * dot12 - dot01 * dot02) * invDenom;

	// Check if point is in triangle
	return (u >= 0) && (v >= 0) && (u + v < 1);
}