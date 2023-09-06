#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

struct TestCase {
    int a;
    int b;
    int c;
};

std::vector<TestCase> generate_test_cases(int num_test_cases) {
    std::vector<TestCase> test_cases;
    srand(static_cast<unsigned>(time(0)));

    for (int i = 0; i < num_test_cases; ++i) {
        TestCase test_case;
        test_case.a = rand() % 1000001; // Generates random number between 0 and 1000
        // test_case.b = rand() % 1001;
        // test_case.c = rand() % 1001;
        test_cases.push_back(test_case);
    }
    return test_cases;
}

int main() {
    int num_test_cases = 10;
    std::vector<TestCase> test_cases = generate_test_cases(num_test_cases);

    // Printing the test cases
    for (const auto& test_case : test_cases) {
        if(test_case.a>=2){
        std::cout << test_case.a <<std::endl;
        }
    }

    return 0;
}

