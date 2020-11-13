//using binaryGCD algorithm
#include<stdio.h>
int gcditterative(int a,int b);
int gcdrecursion(int a,int b);
int main()
{
	int a,b;
	printf("Enter two numbers\n");
	scanf("%d %d",&a,&b);
	printf("GCD of given two numbers using itterative method is :");
	int gcd,gd;
	
	if(a<0)
		a = -a;
	if (b<0)
		b = -b;
		
	gcd = gcditterative(a,b);

	printf("%d\n",gcd);
	
	gd = gcdrecursion(a,b);
	printf("GCD of given two numbers using recursive method is :");
	printf("%d\n",gd);
	return 0;
}

int gcditterative(int a,int b)
{
	 unsigned int shift = 0;

    /* GCD(0,v) == v; GCD(u,0) == u, GCD(0,0) == 0 */
    if (a == 0) return b;
    if (b == 0) return a;
 
    /* Let shift := lg K, where K is the greatest power of 2
        dividing both u and v. */
    while (((a | b) & 1) == 0) {
        shift++;
        a >>= 1;
        b >>= 1;
    }
 
    while ((a & 1) == 0)
        a >>= 1;
 
    /* From here on, u is always odd. */
    do {
        /* remove all factors of 2 in v -- they are not common */
        /*   note: v is not zero, so while will terminate */
        while ((b & 1) == 0)
            b >>= 1;

        /* Now u and v are both odd. Swap if necessary so u <= v,
            then set v = v - u (which is even). For bignums, the
             swapping is just pointer movement, and the subtraction
              can be done in-place. */
        if (a > b) {
            unsigned int t = b; b = a; a = t; // Swap u and v.
        }
       
        b -= a; // Here v >= u.
    } while (b != 0);

    /* restore common factors of 2 */
    return a << shift;
}


int gcdrecursion(int a,int b)
{
	// simple cases (termination)
    if (a == b)
        return a;

    if (a == 0)
        return b;

    if (b == 0)
        return a;

    // look for factors of 2
    if (~a & 1) // u is even
        if (b & 1) // v is odd
            return gcdrecursion(a >> 1, b);
        else // both u and v are even
            return gcdrecursion(a >> 1, b >> 1) << 1;

    if (~b & 1) // u is odd, v is even
        return gcdrecursion(a, b >> 1);

    // reduce larger argument
    if (a > b)
        return gcdrecursion((a - b) >> 1, b);

    return gcdrecursion((b - a) >> 1, a);
}
	
