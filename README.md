# C-DisplayImage
C语言显示路径图片的程序
#include <stdio.h>: 这是包含标准输入输出的头文件。
#include <SDL2/SDL.h>: 这是包含SDL库的头文件。
int main() { ... }: 这是程序的入口函数。
SDL_Window* window = NULL;: 这是一个指向SDL窗口的指针。
SDL_Surface* surface = NULL;: 这是一个指向SDL表面的指针，用于绘制图像。
SDL_Surface* image = NULL;: 这是一个指向SDL图像表面的指针，用于存储加载的图片。
if (SDL_Init(SDL_INIT_VIDEO) < 0) { ... }: 这是初始化SDL库，如果失败，则打印错误消息并退出程序。
window = SDL_CreateWindow("Image Viewer", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN);: 这是创建一个窗口，标题为"Image Viewer"，尺寸为800x600。
if (window == NULL) { ... }: 如果窗口创建失败，则打印错误消息并退出程序。
image = SDL_LoadBMP("YOUR_IMAGE_PATH");: 这是加载位图图片文件到image表面中，您需要替换"YOUR_IMAGE_PATH"为实际的图片文件路径。
if (image == NULL) { ... }: 如果图片加载失败，则打印错误消息并退出程序。
surface = SDL_GetWindowSurface(window);: 这是获取窗口的表面，用于绘制图片。
SDL_BlitSurface(image, NULL, surface, NULL);: 这是将图片表面绘制到窗口表面上。
SDL_UpdateWindowSurface(window);: 这是更新窗口表面，将绘制的内容显示在窗口上。
while (1) { ... }: 这是一个无限循环，用于等待用户退出程序。
while (SDL_PollEvent(&event)) { ... }: 这是一个事件循环，用于处理用户输入事件。
if (event.type == SDL_QUIT) { ... }: 如果用户点击了关闭窗口按钮，退出循环。
SDL_FreeSurface(image);: 释放图片表面的内存。
SDL_DestroyWindow(window);: 销毁窗口。
SDL_Quit();: 退出SDL库。
return 0;: 返回0，表示程序成功执行完毕。
