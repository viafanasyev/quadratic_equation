/**
 * @file
 */
#include "testlib.h"
#include "../src/solver.h"
#include <fstream>
#include <sstream>

/**
 * Gets the next value from stringstream and converts it to double.
 * If the value can't be converted to double, fails an assertion.
 * @param[in, out] iss stringstream to read value from
 * @return converted double
 */
double getDouble(std::istringstream& iss) {
    double value = NAN;
    iss >> value;
    assert(!iss.fail());
    return value;
}

/**
 * Gets the next value from stringstream and converts it to int.
 * If the value can't be converted to int, fails an assertion.
 * @param[in, out] iss stringstream to read value from
 * @return converted int
 */
int getInt(std::istringstream& iss) {
    int value = 0;
    iss >> value;
    assert(!iss.fail());
    return value;
}

/**
 * Creates Test objects from the given file.
 * @note Tests should be written line-by-line in the next format:
 * "a_coefficient b_coefficient c_coefficient roots_number [root_1] [root_2]".
 * @param fileName name of the file with tests
 */
void setUpTestsFromFile(const char* fileName) {
    std::ifstream file(fileName, std::ios_base::in);

    TestRunner *runner = TestRunner::getInstance();
    runner->clear();

    int testsNumber = 0;
    double a = NAN, b = NAN, c = NAN;
    int actualRootsNumber = 0;
    double actualX1 = NAN, actualX2 = NAN;
    std::string line;
    while (getline(file, line)) {
        std::istringstream iss(line);

        a = getDouble(iss);
        b = getDouble(iss);
        c = getDouble(iss);

        actualRootsNumber = getInt(iss);
        if (actualRootsNumber == 2) {
            actualX1 = getDouble(iss);
            actualX2 = getDouble(iss);
            if (actualX1 > actualX2) std::swap(actualX1, actualX2);
        } else if (actualRootsNumber == 1) {
            actualX1 = getDouble(iss);
        }

        auto TEST_NAME(fileTests, ) = [a, b, c, actualRootsNumber, actualX1, actualX2]() {
            double x1 = 0, x2 = 0;
            int rootsNumber = solveQuadratic(a, b, c, x1, x2);

            ASSERT_EQUALS(rootsNumber, actualRootsNumber);
            if (rootsNumber == 2) {
                ASSERT_DOUBLE_EQUALS(x1, actualX1);
                ASSERT_DOUBLE_EQUALS(x2, actualX2);
            } else if (rootsNumber == 1) {
                ASSERT_DOUBLE_EQUALS(x1, actualX1);
            }
        };

        runner->addTest(TEST_NAME(fileTests, ), fileName, ++testsNumber);
    }

    file.close();
}

int main(int argc, char *argv[]) {
    if (argc > 1) {
        setUpTestsFromFile(argv[1]);
    }
    return TestRunner::getInstance()->runAllTests() ? 0 : -1;
}
