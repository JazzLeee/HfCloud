#include "HfCloud.h"
#include "SceneStart.h"
//This is always the first scene

struct{
    Sprite *bak, *frot;
}data;
void SceneStart::start_scene(){
    data.bak = new Sprite("t2.png");  //Ĭ�� x = y = z = 0
    data.frot = new Sprite("t1.png", 100, 100, 30); // (x, y, z), z = 30����������ɫ������ǰ
   // data.frot = new Sprite("t1.png", 100, 100, -20); // (x, y, z), z = -20, ��������ɫ����

    main_module->manage(data.bak);
    main_module->manage(data.frot);
}
void SceneStart::end_scene(){

}
void SceneStart::update(){
    Scene::update();
    if(Input::key_is_triggled(SDLK_ESCAPE))SceneManager::exit();
}
