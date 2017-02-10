#include <iostream>
#include <chrono>
#include <cstdio>
#include <Eigen/Dense>

static Eigen::Matrix<float, Eigen::Dynamic, Eigen::Dynamic> m1(5000, 5000);
static Eigen::Matrix<float, Eigen::Dynamic, Eigen::Dynamic> m2(5000, 5000);
static Eigen::Matrix<float, Eigen::Dynamic, Eigen::Dynamic> m3(5000, 5000);

int main(int argc, char *argv[])
{
	freopen("out.txt", "w", stdout);
	//setvbuf(stdout, 0, _IOLBF, 32 * 5000);

	auto start = std::chrono::steady_clock::now();

	for (size_t i = 0; i < 5000; i++) {
		for (size_t j = 0; j < 5000; j++) {
			m1(i, j) = (float)rand();
			m2(i, j) = (float)rand();
		}
	}

	m3.noalias() = (m1 * m2).eval();
	for (size_t i = 0; i < 5000; i++) {
		for (size_t j = 0; j < 5000; j++)
			printf("%f ", m3(i, j));
		puts("\n");
	}

	auto end = std::chrono::steady_clock::now();

	fprintf(stderr, "product time: %llu ms\n",
		std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count());

	return 0;
}
