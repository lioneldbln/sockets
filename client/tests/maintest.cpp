#include "gmock/gmock.h"

//#include "sockettest.cpp"

int main(int argc, char** argv) {
   testing::InitGoogleMock(&argc, argv);
   return RUN_ALL_TESTS();
}
