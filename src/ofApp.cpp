#include "ofApp.h"

#define NUM 1000 //円の数を表す定数NUMを1000と定義

float loc_x[NUM]; //円のx座標
float loc_y[NUM]; //円のy座標
float speed_x[NUM]; //x軸方向のスピード
float speed_y[NUM]; //y軸方向のスピード
float radius[NUM]; //円の半径
int red[NUM]; //Red成分
int green[NUM]; //Green成分
int blue[NUM]; //Blue成分
bool mouse_pressed; //マウスはクリックされているか?
float gravity;
float friction;
int cnt;

//--------------------------------------------------------------
void ofApp::setup(){
    mySound.load("wafu-goodnight.mp3");
    piano_do.load("piano_do.mp3");
    piano_re.load("piano_re.mp3");
    piano_mi.load("piano_mi.mp3");
    piano_fa.load("piano_fa.mp3");
    piano_so.load("piano_so.mp3");
    piano_ra.load("piano_ra.mp3");
    piano_si.load("piano_si.mp3");
    
    ofSetBackgroundAuto(false);
    ofBackground(0, 0, 0); //背景色の設定
    ofSetFrameRate(60); //フレームレートの設定
    ofSetCircleResolution(64); //円の解像度設定
    ofEnableAlphaBlending(); //アルファチャンネルを有効に
    mouse_pressed = false; //マウス状態を「クリックされていない」に
    gravity = 0.1; //重力
    friction = 0.999;
    
    cnt = 0;
    for(int i = 0; i < NUM; i++){
        speed_x[i]= ofRandom(-10, 10); //x軸方向スピード初期値
        speed_y[i]= ofRandom(-10, 10); //x軸方向スピード初期値
        loc_x[i] = ofRandom(1, ofGetWidth());
        loc_y[i] = ofRandom(1, ofGetHeight());
        red[i] = ofRandom(0, 255); //Red成分を設定
        green[i] = ofRandom(0, 255); //Green成分を設定
        blue[i] = ofRandom(0, 255); //Blue成分を設定
        radius[i] = ofRandom(1, 100);
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    ofBackground(0, 0, 0); //背景色の設定
    for(int i = 0; i < cnt; i++){
        speed_x[i] = speed_x[i] * friction; //x軸方向の摩擦力の影響を計算
        speed_y[i] = speed_y[i] * friction; //y軸方向の摩擦力の影響を計算
        loc_x[i] = loc_x[i] + speed_x[i]; //円のx座標を更新
        loc_y[i] = loc_y[i] + speed_y[i]; //円のy座標を更新
        
        if(loc_x[i] < 0){
            loc_x[i] = 0;
            speed_x[i] = speed_x[i] * -1.0;
        }
        if(loc_x[i] > ofGetWidth()){
            loc_x[i] = ofGetWidth();
            speed_x[i] = speed_x[i] * -1.0;
        }
        if(loc_y[i] < 0){
            loc_y[i] = 0;
            speed_y[i] = speed_y[i] * -1.0;
        }
        if(loc_y[i] > ofGetHeight()){
            loc_y[i] = ofGetHeight();
            speed_y[i] = speed_y[i] * -1.0;
        }
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    for(int i = 0; i < cnt; ++i){
        
        
        ofSetColor(red[i], green[i], blue[i], 127); //描画色の設定
        ofCircle(loc_x[i], loc_y[i], radius[i]);
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch(key){
        
        case'a':
            piano_do.play();
        case's':
            piano_re.play();
        case'd':
            piano_mi.play();
        case'f':
            piano_fa.play();
        case'g':
            piano_so.play();
        case'h':
            piano_ra.play();
        case'j':
            piano_si.play();
        case true:
            cnt++;
        
    }
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
