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

//this is where all your hooks should be
void ApplyHooks() {
    HOOK("_ZN9PlayLayer6onQuitEv", PlayLayerNew::onQuitHooks, PlayLayerNew::onQuit);
}

//this is where your starting patches should be
void ApplyPatches() {
    PatchManager tmp;

    tmp.addPatch("libcocos2dcpp.so", 0x20CDD8, "00 BF");

    //make sure to apply the patches
    tmp.Modify();
}

//this function will run when the app starts
void loader() {
    ApplyHooks();
    ApplyPatches();
}

//starter
JNIEXPORT jint JNI_OnLoad(JavaVM *vm, void *reserved)
{
    loader();
    return JNI_VERSION_1_6;
}
