#include "HfCloud.h"
#include "SceneStart.h"

using namespace HfCloud;
//This is always the first scene

#include "windows.h"
struct{
    Bitmap *bmp;
    Sprite *sprite;
    int cnt;
    long long last;
    long long now;
    long long freq;
    char buf[233];
    SDL_Texture *tex;
}data;
void SceneStart::start_scene(){
    data.bmp = new Bitmap(100, 100);
    data.bmp->fill_rect(0, 0, 100, 100, RGBA(255, 255, 0, 255));
    data.sprite = new Sprite(data.bmp);
    //main_module->manage(data.sprite);

    QueryPerformanceFrequency((LARGE_INTEGER*)&data.freq);
    QueryPerformanceCounter((LARGE_INTEGER*)&data.last);

    data.tex = SDL_CreateTexture(Graphics::render, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, 200, 200);
                                                                                        //����һ��200x200��texture
}
void SceneStart::end_scene(){

}
void SceneStart::update(){
    Scene::update();

    Hf_Rect rts = (Hf_Rect){0, 0, 100, 100}; //Ҫ���Ƶľ���x,y,w,h
    Hf_Rect rtd = (Hf_Rect){0, 0, 100, 100}; //Ŀ��λ��
    SDL_SetRenderTarget(Graphics::render, data.tex);
    SDL_SetRenderDrawColor(Graphics::render, 255, 255, 0, 255);
    SDL_RenderFillRect(Graphics::render, &rts);
    SDL_SetRenderTarget(Graphics::render, NULL);  //�ָ�������texture
    SDL_RenderCopy(Graphics::render, data.tex, &rts, &rtd);


    if(Input::key_is_triggled(SDLK_ESCAPE))SceneManager::exit(); //press esc to quit
    if(++data.cnt == 60){
        data.cnt = 0;
        QueryPerformanceCounter((LARGE_INTEGER*)&data.now);
        double c = 1.0*(data.now-data.last)/data.freq;
        sprintf(data.buf, "HfCloud  -FPS : %.2lf", 60/c);
        Graphics::set_title(data.buf);
        QueryPerformanceCounter((LARGE_INTEGER*)&data.last);
    }
}
