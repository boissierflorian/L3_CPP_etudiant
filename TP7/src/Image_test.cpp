#include <CppUTest/CommandLineTestRunner.h>
#include <string>

#include "Image.hpp"

TEST_GROUP(GroupImage) { };

TEST(GroupImage, Image_constructeur_1) 
{
  Image image(10, 9);
  CHECK_EQUAL(10, image.getLargeur());
  CHECK_EQUAL(9, image.getHauteur());
}

TEST(GroupImage, Image_accesseurs) 
{
  Image image(10, 9);
  image.setPixel(9, 8, 255);
  image.setPixel(0, 0, 0);
  image.setPixel(0, 1, 127);
  CHECK_EQUAL(255, image.getPixel(9, 8));
  CHECK_EQUAL(0, image.getPixel(0, 0));
  CHECK_EQUAL(127, image.getPixel(0, 1));
}

TEST(GroupImage, Image_exception_1) 
{
  try
  {  
    Image image(-1, 0);
    FAIL("Exception non levée !");
  }
  catch (const std::string& str)
  {
    CHECK_EQUAL(str, "Dimension(s) invalide(s) !");
  }
  
  try
  {  
    Image image(0, -1);
    FAIL("Exception non levée !");
  }
  catch (const std::string& str)
  {
    CHECK_EQUAL(str, "Dimension(s) invalide(s) !");
  }

  try
  {  
    Image image(-99, -99);
    FAIL("Exception non levée !");
  }
  catch (const std::string& str)
  {
    CHECK_EQUAL(str, "Dimension(s) invalide(s) !");
  }
}

TEST(GroupImage, Image_exception_2)
{
  Image image(5, 5);

  try
  {
    image.getPixel(-1, -1);
  }
  catch (const std::string& str)
  {
    CHECK_EQUAL(str, "Coordonnées invalides !");
  }

  try
  {
    image.getPixel(5, 0);
  }
  catch (const std::string& str)
  {
    CHECK_EQUAL(str, "Coordonnées invalides !");
  }
}
