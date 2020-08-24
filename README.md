# Filter-Images

Filtering an image is taking the pixels of some original image, and modifying each pixel in such a way that a particular effect is apparent in the resulting image.

The simplest way to represent an image is with a grid of pixels (i.e., dots), each of which can be of a different color. For black-and-white images, we thus need 1 bit per pixel, as 0 could represent black and 1 could represent white.

In this sense, then, is an image just a bitmap (i.e., a map of bits). For more colorful images, you simply need more bits per pixel.

RGB Values: 
A 24-bit BMP uses 8 bits to signify the amount of red in a pixel’s color, 8 bits to signify the amount of green in a pixel’s color, and 8 bits to signify the amount of blue in a pixel’s color.

# Grayscale
“Grayscale” filter is where we take an image and convert it to black-and-white.

We know that if red, green, and blue values(RGB) are all set to 0x00 (hexadecimal for 0), then the pixel is black. And if all values are set to 0xff (hexadecimal for 255), then the pixel is white. So long as the red, green, and blue values are all equal, the result will be varying shades of gray along the black-white spectrum, with higher values meaning lighter shades (closer to white) and lower values meaning darker shades (closer to black).
If the original red, green, and blue values were all pretty high, then the new value should also be pretty high. And if the original values were all low, then the new value should also be low.

To ensure each pixel of the new image still has the same general brightness or darkness as the old image, we can take the average of the red, green, and blue values to determine what shade of grey to make the new pixel.

        New Value = (Red + Green + Blue)/3

# Sepia
“Sepia” filter gives images an old-timey feel by making the whole image look a bit reddish-brown.

An image can be converted to sepia by taking each pixel, and computing new red, green, and blue values based on the original values of the three.

There are a number of algorithms for converting an image to sepia, but for this problem, we used the following algorithm. For each pixel, the sepia color values should be calculated based on the original color values per the below.

      sepiaRed = .393 * originalRed + .769 * originalGreen + .189 * originalBlue
      sepiaGreen = .349 * originalRed + .686 * originalGreen + .168 * originalBlue
      sepiaBlue = .272 * originalRed + .534 * originalGreen + .131 * originalBlue
      
If the result of each of these formulas may not be an integer, but each value could be rounded to the nearest integer. It’s also possible that the result of the formula is a number greater than 255, the maximum value for an 8-bit color value. In that case, we capped the red, green, and blue values at 255. As a result, the resulting red, green, and blue values will be whole numbers between 0 and 255, inclusive.

# Reflection
Some filters might also move pixels around. Reflecting an image, is a filter where the resulting image is what you would get by placing the original image in front of a mirror. So any pixels on the left side of the image should end up on the right, and vice versa.

Note that all of the original pixels of the original image will still be present in the reflected image, it’s just that those pixels may have rearranged to be in a different place in the image.

# Blur
There are a number of ways to create the effect of blurring or softening an image. We used the “box blur,” which works by taking each pixel and, for each color value, giving it a new value by averaging the color values of neighboring pixels.


