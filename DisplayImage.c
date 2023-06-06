#include <stdio.h>
#include <SDL2/SDL.h>

int main() {
    SDL_Window* window = NULL;
    SDL_Surface* surface = NULL;
    SDL_Surface* image = NULL;
    SDL_Event event;

    // 初始化SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    // 创建窗口
    window = SDL_CreateWindow("Image Viewer", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN);
    if (window == NULL) {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    // 加载图片
    image = SDL_LoadBMP("YOUR_IMAGE_PATH");
    if (image == NULL) {
        printf("Unable to load image %s! SDL Error: %s\n", "YOUR_IMAGE_PATH", SDL_GetError());
        return 1;
    }

    // 获取窗口表面
    surface = SDL_GetWindowSurface(window);

    // 将图片绘制到窗口表面
    SDL_BlitSurface(image, NULL, surface, NULL);

    // 更新窗口表面
    SDL_UpdateWindowSurface(window);

    // 等待用户退出
    while (1) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                // 退出循环
                break;
            }
        }
    }

    // 释放资源并退出
    SDL_FreeSurface(image);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
