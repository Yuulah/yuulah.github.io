// The code below computes the intersection with a triangle
// you need to change it so that you compute the intersection
// with a plane with  triangular hole
double PlaneWithTriangleHole::Intersect(Vector source, Vector d)
{
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
	return t;
}


///ORIGINAL question
// The code below computes the intersection with a triangle
// you need to change it so that you compute the intersection
// with a plane with  triangular hole
double PlaneWithTriangleHole::Intersect(Vector source, Vector d)
{
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

	if (t1 < 0 && t2 < 0 && t3 < 0) return t;
	if (t1 > 0 && t2 > 0 && t3 > 0) return t;
	return -1.0;
}
