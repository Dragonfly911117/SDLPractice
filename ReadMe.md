## Environment:

* OS: Windows11/Arch
* IDE: CLion
* Package manager: vcpkg

## Progress

* [Lesson 01 Hello SDL](https://lazyfoo.net/tutorials/SDL/01_hello_SDL/index.php)
* [Lesson 02 Getting an Image on the Screen](https://lazyfoo.net/tutorials/SDL/02_getting_an_image_on_the_screen/index.php)
* [Lesson 03 Event Driven Programming](https://lazyfoo.net/tutorials/SDL/03_event_driven_programming/index.php)
* [Lesson 04 Key Presses](https://lazyfoo.net/tutorials/SDL/04_key_presses/index.php)
* [Lesson 05 Optimized Surface Loading and Soft Stretching](https://lazyfoo.net/tutorials/SDL/05_optimized_surface_loading_and_soft_stretching/index.php)
* [Lesson 06 Extension Libraries and Loading Other Image Formats](https://lazyfoo.net/tutorials/SDL/06_extension_libraries_and_loading_other_image_formats/index.php)
* [Lesson 07 Texture Loading and Rendering](https://lazyfoo.net/tutorials/SDL/07_texture_loading_and_rendering/index.php)x
* [Lesson 08 Geometry Rendering](https://lazyfoo.net/tutorials/SDL/08_geometry_rendering/index.php)
* [Lesson 09 Clip Rendering and Sprite Sheets](https://lazyfoo.net/tutorials/SDL/09_clip_rendering_and_sprite_sheets/index.php)
* [Lesson 10 Color Keying](https://lazyfoo.net/tutorials/SDL/10_color_keying/index.php)
* ![Render text on surface](resource/img.png)

## Caution

* As [here](https://blog.jetbrains.com/clion/2023/01/support-for-vcpkg-in-clion/) mentioned, many toolchains can not be
  used (Basically, Use native toolchains, not something attached from VM or Remote).
* If you are using vcpkg, you should add `set(VCPKG_TARGET_TRIPLET x64-windows)` to your CMakeLists.txt. (x64-windows is
  the default triplet, you can change it to x64-linux or x64-osx)
* Set the working directory to the root of the project so the program can find the resources.
  ![img.png](resource/RunDebugConfing.png)