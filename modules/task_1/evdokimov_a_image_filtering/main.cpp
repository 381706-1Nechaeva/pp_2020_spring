// Copyright 2019 Evdokimov Artem
#include <gtest/gtest.h>
#include <vector>
#include "./image_filtering.h"

TEST(Filtering_Image, Image_Filtering_Correct_Work) {
  // Arrange
  int columns = 2;
  int rows = 2;
  // Act
  std::vector<int> result = imageFiltering(
      getTempImage({1, 2, 3, 4}, rows, columns), cernel(), rows, columns);
  // Result
  std::vector<int> expectedResult = {-8, -1, 6, 13};
  // Assert
  ASSERT_EQ(result, expectedResult);
}

TEST(Filtering_Image, Exception_In_Generate_Image_With_Not_Equals_Attributes) {
  // Arrange
  int columns = 0;
  int rows = -1;
  // Assert
  ASSERT_ANY_THROW(generateImage(rows, columns));
}

TEST(Filtering_Image, Exception_In_Temp_Image_With_Not_Equals_Attributes) {
  // Arrange
  int columns = 0;
  int rows = -1;
  // Assert
  ASSERT_ANY_THROW(getTempImage({1, 2, 3, 4}, rows, columns));
}

TEST(Filtering_Image, Exception_In_Filtering_With_Not_Equals_Attributes) {
  // Arrange
  int columns = 0;
  int rows = -1;
  // Assert
  ASSERT_ANY_THROW(imageFiltering({1, 2, 3, 4}, cernel(), rows, columns));
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
