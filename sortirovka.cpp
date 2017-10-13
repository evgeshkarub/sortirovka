#include <algorithm>
#include <iostream>
#include <random>
#include <string>
#include <vector>
template<class T>
std::vector<T> generate_random_vector(std::size_t num, T min = -10, T max = 10)
{
    std::random_device rd;
    std::mt19937 e2(rd());
    std::uniform_real_distribution<> dist(min, max);
    auto lambda = [&e2, &dist]() -> T { return dist(e2); };
    std::vector<T> result(num);
    std::generate_n(result.begin(), num, lambda);
    return result;
}
int main()
{
    std::cout << "enter number of symbols:" << std::endl;
    int n = 0;
    std::cin >> n;
    std::vector<int> v1 = generate_random_vector<int>( n , -100, 100);
    for (int j = 0; j < v1.size(); ++j)
    {
        for (int k = 0; k < v1.size(); ++k) 
        {
            if (v1[j]> v1[j + 1])
            {
                int m = v1[j];
                v1[j]=v1[j + 1];
                v1[j+1] = m;
            }
        }
    }
    std::cout << "v1:" << std::endl;
    for (int j = 0; j < v1.size(); ++j)
    {
        std::cout << v1[j] << " ";
    }
    std::vector<int> v2 = generate_random_vector<int>( n , -100, 100);
    for (int j = 0; j < v2.size(); ++j)
    {
        for (int k = 0; k < v1.size(); ++k) 
        {
            if (v2[j]> v2[j + 1])
            {
                int m = v2[j];
                v2[j]=v2[j + 1];
                v2[j+1] = m;
            }
        }
    }
    std::cout << "v2:" << std::endl;
    for (int j = 0; j < v2.size(); ++j)
    {
        std::cout << v2[j] << " ";
    }
    std::cout << std::endl;
}

