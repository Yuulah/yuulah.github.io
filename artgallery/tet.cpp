double CircleWithQuadHole::Intersect(Vector source, Vector d)
{
	/*===============================================================================*/
	/*== Enter ray/disk-with-quadrilateral-hole intersection calculations here    ==*/
	/*== Delete the line "t = -1.0;" and insert your solution instead              ==*/
	/*== NOTE 1: If there is no intersection point set t = -1.0;                   ==*/
	/*===============================================================================*/
  float t = -1.0;
	float dn = d.Dot(n);
	if (dn == 0)	// plane and ray parallel
		return -1.0;
	t = (A - source).Dot(n) / dn;
	Vector p = source + d.Scale(t,t,t);
	float t1, t2, t3;
	t1 = (p - A).Cross(B - A).Dot(n);
	t2 = (p - B).Cross(C - B).Dot(n);
	t3 = (p - C).Cross(A - C).Dot(n);

	if (t1 < 0 && t2 < 0 && t3 < 0) return -1;
	if (t1 > 0 && t2 > 0 && t3 > 0) return -1;

  t1 = (p - B).Cross(C - B).Dot(n);
	t2 = (p - C).Cross(D - C).Dot(n);
	t3 = (p - D).Cross(B - D).Dot(n);

  if (t1 < 0 && t2 < 0 && t3 < 0) return -1;
  if (t1 > 0 && t2 > 0 && t3 > 0) return -1;

  t1 = (p - A).Cross(B - A).Dot(n);
	t2 = (p - B).Cross(D - B).Dot(n);
	t3 = (p - D).Cross(A - D).Dot(n);
  if (t1 < 0 && t2 < 0 && t3 < 0) return -1;
  if (t1 > 0 && t2 > 0 && t3 > 0) return -1;

  return t;
	// The following variables are define
	// Vector n = normal of the plane of the disk
	// Vector Centre = centre of the disk
	// double radius = radius of the disk
	// Vector A,B,C,D = vertices of the convex quadrilateral hole

    return t;
}
