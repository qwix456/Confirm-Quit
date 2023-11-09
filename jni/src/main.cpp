#include "includes.h"
#include "ExitAlert.h"
#include "PlayLayer.hpp"

ExitAlert a;

PlayLayer* playlayer;

void PlayLayerNew::onQuitHooks(PlayLayer* self) {
	playlayer = self;

  FLAlertLayer::create(&a, "Confirm", "Do you really want to quit?", "No", "Yes")->show();
}

void PlayLayerNew::Quit() {
  return PlayLayerNew::onQuit(playlayer);
}

void ApplyHooks() {
    HOOK("_ZN9PlayLayer6onQuitEv", PlayLayerNew::onQuitHooks, PlayLayerNew::onQuit);
}

void loader() {
    ApplyHooks();
}

JNIEXPORT jint JNI_OnLoad(JavaVM *vm, void *reserved)
{
    loader();
    return JNI_VERSION_1_6;
}
