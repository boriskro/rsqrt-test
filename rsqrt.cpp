#include <cstdio>
#include <new>

static float Q_rsqrt(float number)
{
	long i;
	float x2, y;
	const float threehalfs = 1.5F;

	x2 = number * 0.5F;
	y  = number;
	i  = * ( long * ) &y;                       // evil floating point bit level hacking
	i  = 0x5f3759df - ( i >> 1 );               // what the fuck?
	y  = * ( float * ) &i;
	y  = y * ( threehalfs - ( x2 * y * y ) );   // 1st iteration
//	y  = y * ( threehalfs - ( x2 * y * y ) );   // 2nd iteration, this can be removed

	return y;
}

static void run_test()
{
	char storage[100];
	std::printf("%f\n", Q_rsqrt(0.25));
	auto t = new (storage + 3) float(0.5);
	std::printf("%f\n", Q_rsqrt(*t));
}

int main(int argc, char *argv[])
{
	run_test();
    return 0;
}
